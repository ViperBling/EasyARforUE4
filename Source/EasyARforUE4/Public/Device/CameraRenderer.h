#pragma once

#include "CoreMinimal.h"
#include "RenderResource.h"
#include "Engine/TextureRenderTarget2D.h"
#include "CommonRenderResources.h"
#include "ShaderParameterUtils.h"
#include "RHIStaticStates.h"

#include "CameraShader.h"

#include "easyar/types.hpp"
// #include "CameraRenderer.generated.h"

static unsigned char YUVBlock[24]{
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    127, 127,
    127, 127,
    127, 127,
    127, 127,
};

class FCameraRenderer
{
public:
	FCameraRenderer(int Width, int Height, UTextureRenderTarget2D* InRenderTarget);
	FCameraRenderer(){ CameraRT = nullptr; bInitialize = false; };
	virtual ~FCameraRenderer();

	void Upload(int Width, int Height, void* BufferData);
	void Render(FMatrix ImageProjection, void* BufferData);
	
	UTextureRenderTarget2D* CameraRT;

private:
	void RetrieveFrame(int Width, int Height, void* BufferData);
	void InitRHI();
	void CameraBackground_RenderThread(
		FRHICommandListImmediate& RHICmdList,
		FMatrix ImageProjection,
		FTextureRenderTargetResource* RenderTargetResource
		);
		
	void Finalize();
	
	enum class RetrieveStatus
	{
		Unset,
		Upload,
		Clear,
	};

	FVector2D CurrentImageSize;
	FCriticalSection RenderEveryFrameLock;
	
	FTexture2DRHIRef BackTexture;
	FUnorderedAccessViewRHIRef BackTexture_UAV;
	FShaderResourceViewRHIRef BackTexture_SRV;
	
	FTexture2DRHIRef BackTextureUV;
	FUnorderedAccessViewRHIRef BackTextureUV_UAV;
	FShaderResourceViewRHIRef BackTextureUV_SRV;
	
	bool bInitialize;
};