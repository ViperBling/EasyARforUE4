#include "Device/CameraRenderer.h"
#include "MediaShaders.h"

class FCameraBackgroundVS;
class FCameraBackgroundPS;

FCameraRenderer::FCameraRenderer(int Width, int Height, UTextureRenderTarget2D* InRenderTarget)
{
	CameraRT = InRenderTarget;
	CurrentImageSize.X = Width;
	CurrentImageSize.Y = Height;
	bInitialize = false;
}

FCameraRenderer::~FCameraRenderer()
{
	CameraRT = nullptr;
}

void FCameraRenderer::RetrieveFrame(int Width, int Height, void* BufferData)
{
	check(IsInRenderingThread())
	const auto BackTexSrcBpp = GPixelFormats[BackTexture->GetFormat()].BlockBytes;
	FUpdateTextureRegion2D UpdateTextureRegion2D = FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height * 1.5);
	RHIUpdateTexture2D(BackTexture, 0, UpdateTextureRegion2D, BackTexSrcBpp * Width, (uint8*)BufferData);
}

void FCameraRenderer::Render(FMatrix ImageProjection, void* BufferData)
{
	FTextureRenderTargetResource* RenderTargetResource = CameraRT->GameThread_GetRenderTargetResource();
	ENQUEUE_RENDER_COMMAND(CameraBackgroundRendering)
	([this, RenderTargetResource, BufferData, ImageProjection](FRHICommandListImmediate& RHICmdList)
	{
		if (!bInitialize)
		{
			InitRHI();
			bInitialize = true;
		}
		RetrieveFrame(CurrentImageSize.X, CurrentImageSize.Y, BufferData);
		// CameraBackground_RenderThread(
		// 	RHICmdList, ImageProjection, RenderTargetResource);
		CustomCameraBackground_RenderThread(
        	RHICmdList, RenderTargetResource);
	});
}

void FCameraRenderer::InitRHI()
{
	check(IsInRenderingThread())
	FRHIResourceCreateInfo CreateInfo;
	BackTexture = RHICreateTexture2D(
		CurrentImageSize.X, CurrentImageSize.Y * 1.5,
		PF_G8, 1, 1, TexCreate_ShaderResource | TexCreate_UAV,
		CreateInfo);
    BackTexture_UAV = RHICreateUnorderedAccessView(BackTexture);
    BackTexture_SRV = RHICreateShaderResourceView(BackTexture, 0);
}

void FCameraRenderer::CameraBackground_RenderThread(
		FRHICommandListImmediate& RHICmdList,
		FMatrix ImageProjection,
		FTextureRenderTargetResource* RenderTargetResource
		)
{
	check(IsInRenderingThread())
	SCOPED_DRAW_EVENT(RHICmdList, CameraBack);
	
	FGraphicsPipelineStateInitializer GraphicsPSOInit;
	FRHITexture* RenderTarget = RenderTargetResource->TextureRHI.GetReference();
	RHICmdList.Transition(FRHITransitionInfo(RenderTarget, ERHIAccess::Unknown, ERHIAccess::RTV));

	FIntPoint OutputDim(RenderTarget->GetSizeXYZ().X, RenderTarget->GetSizeXYZ().Y);
	
	FRHIRenderPassInfo RenderPassInfo(RenderTarget,ERenderTargetActions::DontLoad_Store);
	RHICmdList.BeginRenderPass(RenderPassInfo, TEXT("CameraBackgroundRendering"));
	{
		RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
		RHICmdList.SetViewport(0, 0, 0.0f, OutputDim.X, OutputDim.Y, 1.0f);
		
		auto ShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
		TShaderMapRef<FMediaShadersVS> VertexShader(ShaderMap);
		TShaderMapRef<FNV12ConvertAsBytesPS> PixelShader(ShaderMap);
		
		GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
		GraphicsPSOInit.BlendState = TStaticBlendStateWriteMask<CW_RGBA, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE>::GetRHI();
		GraphicsPSOInit.PrimitiveType = PT_TriangleStrip;
		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GMediaVertexDeclaration.VertexDeclarationRHI;
		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
		GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
		SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);

		FVector YUVOffset(MediaShaders::YUVOffset8bits);
		
		const FMatrix YuvToSrgbJpeg = FMatrix(
		FPlane(1.000000f,  0.000000f,  1.402000f, 0.000000f),
		FPlane(1.000000f, -0.344140f, -0.714140f, 0.000000f),
		FPlane(1.000000f,  1.772000f,  0.000000f, 0.000000f),
		FPlane(0.000000f,  0.000000f,  0.000000f, 0.000000f));

		static const FMatrix NV21Convert(
			FPlane(1.000000f, 0.000000f, 1.139830f, 0.000000f),
			FPlane(1.000000f, -0.394650f, -0.58060f, 0.000000f),
			FPlane(1.000000f, 2.032110f, 0.000000f, 0.000000f),
			FPlane(0.000000f, 0.000000f, 0.000000f, 0.000000f));
		
		PixelShader->SetParameters(RHICmdList, BackTexture, OutputDim, NV21Convert, YUVOffset, true);
		RHICmdList.SetViewport(0, 0, 0.0f, OutputDim.X, OutputDim.Y, 1.0f);
		RHICmdList.SetStreamSource(0, CreateTempMediaVertexBuffer(), 0);
		RHICmdList.DrawPrimitive(0, 2, 1);
	}
	RHICmdList.EndRenderPass();
	RHICmdList.Transition(FRHITransitionInfo(RenderTarget, ERHIAccess::RTV, ERHIAccess::SRVGraphics));
}

void FCameraRenderer::CustomCameraBackground_RenderThread(
    FRHICommandListImmediate& RHICmdList,
    FTextureRenderTargetResource* RenderTargetResource)
{
	check(IsInRenderingThread())
	SCOPED_DRAW_EVENT(RHICmdList, CameraBack);
	
	FGraphicsPipelineStateInitializer GraphicsPSOInit;
	FRHITexture* RenderTarget = RenderTargetResource->TextureRHI.GetReference();
	RHICmdList.Transition(FRHITransitionInfo(RenderTarget, ERHIAccess::Unknown, ERHIAccess::RTV));
	
	FIntPoint OutputDim(RenderTarget->GetSizeXYZ().X, RenderTarget->GetSizeXYZ().Y);
	
	FRHIRenderPassInfo RenderPassInfo(RenderTarget,ERenderTargetActions::DontLoad_Store);
	RHICmdList.BeginRenderPass(RenderPassInfo, TEXT("CameraBackgroundRendering"));
	{
		RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
		RHICmdList.SetViewport(0, 0, 0.0f, OutputDim.X, OutputDim.Y, 1.0f);
		auto ShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
		TShaderMapRef<FCameraBackgroundVS> VertexShader(ShaderMap);
		TShaderMapRef<FCameraBackgroundPS> PixelShader(ShaderMap);
		
		GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
		GraphicsPSOInit.BlendState = TStaticBlendStateWriteMask<CW_RGBA, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE>::GetRHI();
		GraphicsPSOInit.PrimitiveType = PT_TriangleStrip;
		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
		GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
		SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);

		FCameraBackgroundPS::FParameters PassParameters;
		PassParameters.BackTexture = BackTexture_SRV;
		PassParameters.UVScale = FVector2D((float)OutputDim.X / (float)BackTexture->GetSizeX(), (float)OutputDim.Y / (float)BackTexture->GetSizeY());
		PassParameters.OutWidth = OutputDim.X;
		PassParameters.SRGBToLinear = true;
		PassParameters.BaseSampler = TStaticSamplerState<SF_Bilinear>::GetRHI();
		PassParameters.BaseSamplerUV = TStaticSamplerState<SF_Point>::GetRHI();

		SetShaderParameters(RHICmdList, PixelShader, PixelShader.GetPixelShader(), PassParameters);
		
		RHICmdList.SetStreamSource(0, GCameraBackgroundVB.VertexBufferRHI, 0);
		RHICmdList.DrawPrimitive(0, 2, 1);
	}
	RHICmdList.EndRenderPass();
	RHICmdList.Transition(FRHITransitionInfo(RenderTarget, ERHIAccess::RTV, ERHIAccess::SRVGraphics));
}