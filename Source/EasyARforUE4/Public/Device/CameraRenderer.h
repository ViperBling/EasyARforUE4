#pragma once

#include "CoreMinimal.h"
#include "RenderResource.h"
#include "Engine/TextureRenderTarget2D.h"
#include "CommonRenderResources.h"
#include "ShaderParameterUtils.h"
#include "RHIStaticStates.h"
#include "CameraShader.h"
#include "easyar/types.hpp"

class FCameraRenderer
{
public:
	FCameraRenderer(int Width, int Height, UTextureRenderTarget2D* InRenderTarget);
	FCameraRenderer(){ CameraRT = nullptr; bInitialize = false; };
	virtual ~FCameraRenderer();

	void Render(void* BufferData);
	
	UTextureRenderTarget2D* CameraRT;

private:
	void RetrieveFrame(int Width, int Height, void* BufferData);
	void InitRHI();
	void CameraBackground_RenderThread(
		FRHICommandListImmediate& RHICmdList,
		FMatrix ImageProjection,
		FTextureRenderTargetResource* RenderTargetResource
	);
	
	void CustomCameraBackground_RenderThread(
    	FRHICommandListImmediate& RHICmdList,
    	FTextureRenderTargetResource* RenderTargetResource
    );
	
	FVector2D CurrentImageSize;
	
	FTexture2DRHIRef BackTexture;
	FUnorderedAccessViewRHIRef BackTexture_UAV;
	FShaderResourceViewRHIRef BackTexture_SRV;
	
	bool bInitialize;
};