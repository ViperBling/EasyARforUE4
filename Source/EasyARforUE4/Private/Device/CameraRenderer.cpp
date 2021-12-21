#include "Device/CameraRenderer.h"

class FCameraBackgroundVS;
class FCameraBackgroundPS;

FCameraRenderer::FCameraRenderer(UTextureRenderTarget2D* InRenderTarget)
{
	CameraRT = InRenderTarget;
}

FCameraRenderer::~FCameraRenderer()
{
	CameraRT = nullptr;
}

void FCameraRenderer::Upload(int Width, int Height, void* BufferData)
{
	RetrieveFrame(Width, Height, BufferData);
}

void FCameraRenderer::RetrieveFrame(int Width, int Height, void* BufferData)
{
	InitRHI();
	FUpdateTextureRegion2D UpdateTextureRegion2D = FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);
	RHIUpdateTexture2D(BackTexture->GetTexture2D(), 0, UpdateTextureRegion2D, 4 * Width, (uint8*)BufferData);
	
	auto data = (uint8*)BufferData + (int)CurrentImageSize.X * (int)CurrentImageSize.Y;
	RHIUpdateTexture2D(BackTextureUV->GetTexture2D(), 0, UpdateTextureRegion2D, 4 * CurrentImageSize.X, data);
}

void FCameraRenderer::Render(FMatrix ImageProjection)
{
	
	ENQUEUE_RENDER_COMMAND(CameraBackgroundRendering)
	([this, ImageProjection](FRHICommandListImmediate& RHICmdList)
	{
		CameraBackground_RenderThread(
			RHICmdList, ImageProjection,
			BackTexture_SRV, BackTextureUV_SRV
			);
	});
}

void FCameraRenderer::InitRHI()
{
	FRHIResourceCreateInfo CreateInfo;
	BackTexture = RHICreateTexture2D(
		CurrentImageSize.X, CurrentImageSize.Y,
		PF_L8, 1, 1, TexCreate_Dynamic | TexCreate_ShaderResource | TexCreate_UAV,
		CreateInfo
	);
	BackTexture_UAV = RHICreateUnorderedAccessView(BackTexture);
	BackTexture_SRV = RHICreateShaderResourceView(BackTexture, 0);

	BackTextureUV = RHICreateTexture2D(
		CurrentImageSize.X, CurrentImageSize.Y,
		PF_L8, 1, 1, TexCreate_Dynamic | TexCreate_ShaderResource | TexCreate_UAV,
		CreateInfo
	);
	BackTextureUV_UAV = RHICreateUnorderedAccessView(BackTextureUV);
	BackTextureUV_SRV = RHICreateShaderResourceView(BackTextureUV, 0);
}

void FCameraRenderer::CameraBackground_RenderThread(
		FRHICommandListImmediate& RHICmdList,
		FMatrix ImageProjection,
		FShaderResourceViewRHIRef BackTextures_SRV,
		FShaderResourceViewRHIRef BackTexturesUV_SRV)
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
		PassParameters.BackTexture = BackTextures_SRV;
		PassParameters.BackTextureUV = BackTexturesUV_SRV;
		PassParameters.Sampler = TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();

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


