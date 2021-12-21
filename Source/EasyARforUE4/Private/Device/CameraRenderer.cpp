#include "Device/CameraRenderer.h"

class FCameraBackgroundVS;
class FCameraBackgroundPS;

FCameraRenderer::FCameraRenderer(int Width, int Height, UTextureRenderTarget2D* InRenderTarget)
{
	CameraRT = InRenderTarget;
	CurrentImageSize.X = Width;
	CurrentImageSize.Y = Height;
}

FCameraRenderer::~FCameraRenderer()
{
	CameraRT = nullptr;
}

void FCameraRenderer::Upload(int Width, int Height, void* BufferData)
{
	RenderEveryFrameLock.Lock();
	RetrieveFrame(Width, Height, BufferData);
	RenderEveryFrameLock.Unlock();
}

void FCameraRenderer::RetrieveFrame(int Width, int Height, void* BufferData)
{
	check(IsInRenderingThread())
	InitRHI();
	
	FUpdateTextureRegion2D UpdateTextureRegion2D = FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);
	RHIUpdateTexture2D(BackTexture->GetTexture2D(), 0, UpdateTextureRegion2D, 4 * Width, (uint8*)BufferData);

	UpdateTextureRegion2D.Width = CurrentImageSize.X / 2;
	UpdateTextureRegion2D.Height = CurrentImageSize.Y / 2;
	
	auto data = (uint8*)BufferData + Width * Height;
	RHIUpdateTexture2D(BackTextureUV->GetTexture2D(), 0, UpdateTextureRegion2D, 4 * Width, data);
}

void FCameraRenderer::Render(FMatrix ImageProjection, void* BufferData)
{
	RenderEveryFrameLock.Lock();
	ENQUEUE_RENDER_COMMAND(CameraBackgroundRendering)
	([this, BufferData, ImageProjection](FRHICommandListImmediate& RHICmdList)
	{
		CameraBackground_RenderThread(
			RHICmdList, ImageProjection,
			BufferData
			);
	});
	RenderEveryFrameLock.Unlock();
}

void FCameraRenderer::InitRHI()
{
	// FRHIResourceCreateInfo CreateInfo;
	// BackTexture = RHICreateTexture2D(
	// 	CurrentImageSize.X, CurrentImageSize.Y,
	// 	PF_R8G8B8A8_UINT, 1, 1, TexCreate_ShaderResource | TexCreate_UAV,
	// 	CreateInfo);
 //    BackTexture_UAV = RHICreateUnorderedAccessView(BackTexture);
 //    BackTexture_SRV = RHICreateShaderResourceView(BackTexture, 0);
 //    
 //    BackTextureUV = RHICreateTexture2D(
 //    	CurrentImageSize.X / 2, CurrentImageSize.Y / 2,
 //    	PF_R8G8B8A8_UINT, 1, 1, TexCreate_ShaderResource | TexCreate_UAV,
 //    	CreateInfo);
 //    BackTextureUV_UAV = RHICreateUnorderedAccessView(BackTextureUV);
 //    BackTextureUV_SRV = RHICreateShaderResourceView(BackTextureUV, 0);
	
}

void FCameraRenderer::CameraBackground_RenderThread(
		FRHICommandListImmediate& RHICmdList,
		FMatrix ImageProjection,
		// FShaderResourceViewRHIRef BackTextures_SRV,
		// FShaderResourceViewRHIRef BackTexturesUV_SRV,
		void* BufferData)
{
	check(IsInRenderingThread())
	SCOPED_DRAW_EVENT(RHICmdList, CameraBack);
    
	FRHIRenderPassInfo RenderPassInfo(
    	CameraRT->GetRenderTargetResource()->GetRenderTargetTexture(),
    	ERenderTargetActions::Clear_Store);

	RHICmdList.BeginRenderPass(RenderPassInfo, TEXT("CameraBackgroundRendering"));
	{
		auto ShaderMap = GetGlobalShaderMap(ERHIFeatureLevel::ES3_1);
		TShaderMapRef<FCameraBackgroundVS> VertexShader(ShaderMap);
		TShaderMapRef<FCameraBackgroundPS> PixelShader(ShaderMap);

		// Set the graphic pipeline state.
		FGraphicsPipelineStateInitializer GraphicsPSOInit;
		RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
		GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
		GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
		GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
		GraphicsPSOInit.PrimitiveType = PT_TriangleStrip;
		SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);

		FCameraBackgroundPS::FParameters PassParameters;
		PassParameters.Projection = ImageProjection;
		PassParameters.BackTexture = BackTexture_SRV;
		PassParameters.BackTextureUV = BackTextureUV_SRV;
		PassParameters.BaseSampler = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
		PassParameters.BaseSamplerUV = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
		
		SetShaderParameters(RHICmdList, PixelShader, PixelShader.GetPixelShader(), PassParameters);

		RHICmdList.SetStreamSource(0, GCameraBackgroundVB.VertexBufferRHI, 0);
		RHICmdList.DrawPrimitive(0, 2, 1);

		RHICmdList.CopyToResolveTarget(
			CameraRT->GetRenderTargetResource()->GetRenderTargetTexture(),
			CameraRT->GetRenderTargetResource()->TextureRHI, FResolveParams()
		);
	}
	RHICmdList.EndRenderPass();
}
		

void FCameraRenderer::Finalize()
{
	
}


