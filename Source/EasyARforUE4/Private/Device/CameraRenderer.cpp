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

void FCameraRenderer::Upload(int Width, int Height, void* BufferData)
{
	// RenderEveryFrameLock.Lock();
	// RetrieveFrame(Width, Height, BufferData);
	// RenderEveryFrameLock.Unlock();
}

void FCameraRenderer::RetrieveFrame(int Width, int Height, void* BufferData)
{
	check(IsInRenderingThread())
	FUpdateTextureRegion2D UpdateTextureRegion2D = FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);
	RHIUpdateTexture2D(BackTexture, 0, UpdateTextureRegion2D, 4 * Width, (uint8*)BufferData);

	UpdateTextureRegion2D.Width = CurrentImageSize.X / 2;
	// UpdateTextureRegion2D.Height = CurrentImageSize.Y / 2;
	
	auto data = (uint8*)BufferData + Width * Height;
	RHIUpdateTexture2D(BackTextureUV, 0, UpdateTextureRegion2D, 4 * Width, data);
}

void FCameraRenderer::Render(FMatrix ImageProjection, void* BufferData)
{
	// RenderEveryFrameLock.Lock();
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
		CameraBackground_RenderThread(
			RHICmdList, ImageProjection, RenderTargetResource);
	});
	// RenderEveryFrameLock.Unlock();
}

void FCameraRenderer::InitRHI()
{
	check(IsInRenderingThread())
	FRHIResourceCreateInfo CreateInfo;
	BackTexture = RHICreateTexture2D(
		CurrentImageSize.X, CurrentImageSize.Y,
		PF_G8, 1, 1, TexCreate_ShaderResource | TexCreate_UAV,
		CreateInfo);
    BackTexture_UAV = RHICreateUnorderedAccessView(BackTexture);
    BackTexture_SRV = RHICreateShaderResourceView(BackTexture, 0);
    
    BackTextureUV = RHICreateTexture2D(
    	CurrentImageSize.X / 2, CurrentImageSize.Y,
    	PF_R8G8, 1, 1, TexCreate_ShaderResource | TexCreate_UAV,
    	CreateInfo);
    BackTextureUV_UAV = RHICreateUnorderedAccessView(BackTextureUV);
    BackTextureUV_SRV = RHICreateShaderResourceView(BackTextureUV, 0);
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
	
	FRHIRenderPassInfo RenderPassInfo(RenderTarget,ERenderTargetActions::DontLoad_Store);
	RHICmdList.BeginRenderPass(RenderPassInfo, TEXT("CameraBackgroundRendering"));
	{
		RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
		RHICmdList.SetViewport(0, 0, 0.0f, CurrentImageSize.X, CurrentImageSize.Y, 1.0f);
		
		GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
		GraphicsPSOInit.BlendState = TStaticBlendStateWriteMask<CW_RGBA, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE>::GetRHI();
		GraphicsPSOInit.PrimitiveType = PT_TriangleStrip;
		
		auto ShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
		// TShaderMapRef<FMediaShadersVS> VertexShader(ShaderMap);
		// TShaderMapRef<FYCbCrConvertPS> PixelShader(ShaderMap);
		TShaderMapRef<FCameraBackgroundVS> VertexShader(ShaderMap);
		TShaderMapRef<FCameraBackgroundPS> PixelShader(ShaderMap);
		
		// GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GMediaVertexDeclaration.VertexDeclarationRHI;
		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();

		FVector YUVOffset(MediaShaders::YUVOffset10bits);

		GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
		SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
		
		static const FMatrix DefaultMatrix(
			FPlane(1.164383f, 0.000000f, 1.596027f, 0.000000f),
			FPlane(1.164383f, -0.391762f, -0.812968f, 0.000000f),
			FPlane(1.164383f, 2.017232f, 0.000000f, 0.000000f),
			FPlane(0.000000f, 0.000000f, 0.000000f, 0.000000f)
		);
		const FMatrix YuvToRgbRec709 = FMatrix(
		FPlane(1.000000f, 0.000000f, 1.280330f, 0.000000f),
		FPlane(1.000000f, -0.214820f, -0.380590f, 0.000000f),
		FPlane(1.000000f, 2.127980f, 0.000000f, 0.000000f),
		FPlane(0.000000f, 0.000000f, 0.000000f, 0.000000f)
	);

		FCameraBackgroundPS::FParameters PassParameters;
		PassParameters.BackTexture = BackTexture_SRV;
		PassParameters.BackTextureUV = BackTextureUV_SRV;
		PassParameters.BaseSampler = TStaticSamplerState<SF_Bilinear>::GetRHI();
		PassParameters.BaseSamplerUV = TStaticSamplerState<SF_Point>::GetRHI();
		
		// PixelShader->SetParameters(RHICmdList, BackTexture, FIntPoint(CurrentImageSize.X, CurrentImageSize.Y), DefaultMatrix, YUVOffset, false);
		// PixelShader->SetParameters(RHICmdList, BackTexture, BackTextureUV, YuvToRgbRec709, YUVOffset, false);
		SetShaderParameters(RHICmdList, PixelShader, PixelShader.GetPixelShader(), PassParameters);

		// RHICmdList.SetStreamSource(0, CreateTempMediaVertexBuffer(), 0);
		RHICmdList.SetStreamSource(0, GCameraBackgroundVB.VertexBufferRHI, 0);
		
		RHICmdList.SetViewport(0, 0, 0, CurrentImageSize.X, CurrentImageSize.Y, 1.f);
		RHICmdList.DrawPrimitive(0, 2, 1);
	}
	RHICmdList.EndRenderPass();
	RHICmdList.Transition(FRHITransitionInfo(RenderTarget, ERHIAccess::RTV, ERHIAccess::SRVGraphics));
	// RHICmdList.CopyToResolveTarget(
	// 	CameraRT->GetRenderTargetResource()->GetRenderTargetTexture(),
	// 	CameraRT->GetRenderTargetResource()->TextureRHI, FResolveParams()
	// );
}
		

void FCameraRenderer::Finalize()
{
	
}


