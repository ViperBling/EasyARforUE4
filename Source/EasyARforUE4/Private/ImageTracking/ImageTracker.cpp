#include "ImageTracking/ImageTracker.h"

#include "MediaShaders.h"

#include "Engine/Texture2DDynamic.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Rendering/Texture2DResource.h"

static int YUVtoRGB(int y, int u, int v);
static void NV21toRGB(unsigned char* rgb, char* yuv, int width, int height);
static FMatrix MatrixConverter(easyar::Matrix44F MatEasyAR);

void NV21toRGB_RenderThread(
	FRHICommandListImmediate& RHICmdList,
	FTextureRenderTargetResource* OutRTResource,
	FTextureResource* CameraTextureResource,
	FIntPoint Size
);

UImageTrackers::UImageTrackers()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_PostPhysics;
	
	_imageTracker = std::make_unique<ImageTrackerWrapper>();
	
	bFirstFrame = true;
}

UImageTrackers::~UImageTrackers()
{
	_imageTracker.release();
	delete CameraRenderer;
}

void UImageTrackers::BeginPlay()
{
	Super::BeginPlay();
}

void UImageTrackers::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	Stop();
}

void UImageTrackers::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	_imageTracker->perFrame();
	void* CameraFrameData = _imageTracker->cameraImage->buffer()->data();
	if (CameraFrameData != nullptr)
	{
		auto ImageProjection = _imageTracker->cameraParameters->imageProjection((float)Width / (float)Height, 0, true, false);
		FMatrix ProjectionMatUE = MatrixConverter(ImageProjection);
		// CameraRenderer->Upload(Width, Height, CameraFrameData);
		CameraRenderer->Render(ProjectionMatUE, CameraFrameData);
	}
}

void UImageTrackers::Initialize()
{
	_imageTracker->cameraWidth = Width;
	_imageTracker->cameraHeight = Height;
	CameraRenderer = new FCameraRenderer(Width, Height, OutRT);
	
	// CameraUpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);
	//
	// CameraBackground = UTexture2D::CreateTransient(Width, Height, PF_R8G8B8A8);
	// CameraBackground->UpdateResource();
	
	_imageTracker->initialize();
	
	for (auto n : ImageCollection)
	{
		_imageTracker->loadFromImage(TCHAR_TO_UTF8(*GetImagePath(n)), TCHAR_TO_UTF8(*n));
	}
}

void UImageTrackers::Start()
{
	_imageTracker->start();
}

void UImageTrackers::Stop()
{
	_imageTracker->stop();
	// delete CameraUpdateTextureRegion;
}

void UImageTrackers::CallEveryFrame(float DeltaTime)
{
	Timer += DeltaTime;
	const auto SrcBpp = GPixelFormats[CameraBackground->GetPixelFormat()].BlockBytes;
	if (Timer >= (1. / FrameRate))
	{
		Timer -= 1. / FrameRate;
		// check(IsInGameThread());
		// _imageTracker->perFrame();
		// void* CameraFrameData = _imageTracker->cameraImage->buffer()->data();
		// if (CameraFrameData != nullptr)
		// {
		// 	auto ImageProjection = _imageTracker->cameraParameters->imageProjection((float)Width / (float)Height, 0, true, false);
		// 	FMatrix ProjectionMatUE = MatrixConverter(ImageProjection);
		// 	CameraRenderer.Upload(Width, Height, CameraFrameData);
		// 	CameraRenderer.Render(ProjectionMatUE);
		// 	// GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Green, FString::Printf(TEXT("%d"), _imageTracker->cameraImage->format()));
		// 	// UpdateTextureRegions(
		// 	// 	CameraBackground, 0, 1,
		// 	// 	CameraUpdateTextureRegion, SrcBpp * Height, SrcBpp,
		// 	// 	CameraFrameData, false);
		// 	// bFirstFrame = false;
		// }
	}
	// _imageTracker->perFrame();
	// void* CameraFrameData = nullptr;
	// CameraFrameData = _imageTracker->cameraImage->buffer()->data();
	// // GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Green, FString::Printf(TEXT("%d"), _imageTracker->cameraImage->format()));
	// UpdateTextureRegions(
	// 	CameraBackground, 0, 1,
	// 	CameraUpdateTextureRegion, SrcBpp * Width, SrcBpp,
	// 	CameraFrameData, false);

	// FTexture2DMipMap& mip = CameraBackground->PlatformData->Mips[0];
	// void* data = mip.BulkData.Lock(LOCK_READ_WRITE);
	// FMemory::Memcpy(data, CameraFrameData, Width * Height * 4 * SrcBpp);
	// mip.BulkData.Unlock();
	// CameraBackground->UpdateResource();
}

FString UImageTrackers::GetImagePath(FString& ImageName)
{
	// FString AssetsPath = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("NonAssets"));
	FString AssetsPath = "";
	// FString AssetsPath = FPaths::Combine(FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()), TEXT("NonAssets"));
	// FString AssetsPath = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("EasyARforUE4/Resources/Assets"));
	FString ImagePath = FPaths::Combine(AssetsPath, ImageName);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *ImagePath);
	return ImagePath;
}

// void UImageTrackers::UpdateTextureRegions(
// 	UTexture2D* Texture, int32 MipIndex, uint32 NumRegions,
// 	FUpdateTextureRegion2D* Region2D,
// 	uint32 SrcPitch, uint32 SrcBpp, void* SrcData, bool bFreeData)
// {
// 	// check(IsInGameThread());
// 	if (Texture && Texture->Resource)
// 	{
// 		struct FUpdateTextureRegionsData
// 		{
// 			FTexture2DResource* Texture2DResource;
// 			int32 MipIndex;
// 			uint32 NumRegions;
// 			FUpdateTextureRegion2D* Regions;
// 			uint32 SrcPitch;
// 			uint32 SrcBpp;
// 			uint8* SrcData;
// 		};
//
// 		FUpdateTextureRegionsData* RegionData = new FUpdateTextureRegionsData;
//
// 		RegionData->Texture2DResource = (FTexture2DResource*)Texture->Resource;
// 		RegionData->MipIndex = MipIndex;
// 		RegionData->NumRegions = NumRegions;
// 		RegionData->Regions = Region2D;
// 		RegionData->SrcPitch = SrcPitch;
// 		RegionData->SrcBpp = SrcBpp;
// 		
// 		char* yuv420sp = (char*)(SrcData);
// 		//
// 		int size = Width * Height;
// 		int offset = size;
// 		int* rgb = new int[Width * Height];
// 		
// 		// unsigned char* rgb = new unsigned char[size];
// 		// NV21toRGB(rgb, yuv420sp, Width, Height);
//
// 		int u, v, y1, y2, y3, y4;
// 		
// 		for (int i = 0, k = 0; i < size; i += 2, k += 2) {
// 			y1 = yuv420sp[i] & 0xff;
// 			y2 = yuv420sp[i + 1] & 0xff;
// 			y3 = yuv420sp[Width + i] & 0xff;
// 			y4 = yuv420sp[Width + i + 1] & 0xff;
// 		
// 			u = yuv420sp[offset + k] & 0xff;
// 			v = yuv420sp[offset + k + 1] & 0xff;
// 			u = u - 128;
// 			v = v - 128;
// 		
// 			rgb[i] = YUVtoRGB(y1, u, v);
// 			rgb[i + 1] = YUVtoRGB(y2, u, v);
// 			rgb[Width + i] = YUVtoRGB(y3, u, v);
// 			rgb[Width + i + 1] = YUVtoRGB(y4, u, v);
// 		
// 			if (i != 0 && (i + 2) % Width == 0)
// 				i += Width;
// 		}
// 		
// 		RegionData->SrcData = (uint8*)(rgb);
// 		// RegionData->SrcData = (uint8*)SrcData;
// 		
// 		// FTextureRenderTargetResource* OutRTResource = OutRT->GameThread_GetRenderTargetResource();
// 		
// 		// UE_LOG(LogTemp, Warning, TEXT("s") FString::FromInt(rgb[0]));
// 		ENQUEUE_RENDER_COMMAND(UpdateTextureRegionData)
// 		([RegionData, bFreeData, this](FRHICommandListImmediate& RHICmdList)
// 		{
// 			for (uint32 RegionIndex = 0; RegionIndex < RegionData->NumRegions; ++RegionIndex)
// 			{
// 				int32 CurrentFirstMip = RegionData->Texture2DResource->GetCurrentFirstMip();
// 				if (RegionData->MipIndex >= CurrentFirstMip)
// 				{
// 					RHICmdList.UpdateTexture2D(
// 					RegionData->Texture2DResource->GetTexture2DRHI(),
// 					RegionData->MipIndex - CurrentFirstMip,
// 					RegionData->Regions[RegionIndex],
// 					RegionData->SrcPitch,
// 					RegionData->SrcData
// 					+ RegionData->Regions[RegionIndex].SrcY * RegionData->SrcPitch
// 					+ RegionData->Regions[RegionIndex].SrcX * RegionData->SrcBpp
// 					);
// 				}
// 			}
//
// 			// FTextureResource* CameraTextureResource = CameraBackground->Resource;
//
// 			// NV21toRGB_RenderThread(RHICmdList, OutRTResource, CameraTextureResource, FIntPoint(Width, Height));
// 			
// 			if (bFreeData)
// 			{
// 				FMemory::Free(RegionData->Regions);
// 				FMemory::Free(RegionData->SrcData);
// 			}
// 			delete RegionData;
// 		});
// 		delete[] rgb;
// 	}
// }
//
// void NV21toRGB_RenderThread(
// 	FRHICommandListImmediate& RHICmdList,
// 	FTextureRenderTargetResource* OutRTResource,
// 	FTextureResource* CameraTextureResource,
// 	FIntPoint Size
// )
// {
// 	check(IsInRenderingThread())
//
// 	// RHICmdList.TransitionResource(ERHIAccess::EReadable, CameraTextureResource->TextureRHI);
// 	// RHICmdList.TransitionResource(ERHIAccess::EWritable, OutRTResource->TextureRHI);
//
// 	FRHIRenderPassInfo RenderPassInfo(OutRTResource->GetRenderTargetTexture(), ERenderTargetActions::DontLoad_Store);
// 	RHICmdList.BeginRenderPass(RenderPassInfo, TEXT("Convert"));
// 	{
// 		FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(ERHIFeatureLevel::ES3_1);
// 		TShaderMapRef<FMediaShadersVS> VertexShader(GlobalShaderMap);
// 		TShaderMapRef<FNV21ConvertPS> PixelShader(GlobalShaderMap);
//
// 		// Set the graphic pipeline state.
// 		FGraphicsPipelineStateInitializer GraphicsPSOInit;
// 		RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
// 		GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
// 		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
// 		GraphicsPSOInit.BlendState = TStaticBlendStateWriteMask<CW_RGBA, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE, CW_NONE>::GetRHI();
// 		GraphicsPSOInit.PrimitiveType = PT_TriangleStrip;
// 		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GetVertexDeclarationFVector4();
// 		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
// 		GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
// 		SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
//
// 		static const FMatrix DefaultMatrix(
// 			FPlane(1.164383f, 0.000000f, 1.596027f, 0.000000f),
// 			FPlane(1.164383f, -0.391762f, -0.812968f, 0.000000f),
// 			FPlane(1.164383f, 2.017232f, 0.000000f, 0.000000f),
// 			FPlane(0.000000f, 0.000000f, 0.000000f, 0.000000f)
// 		);
//
// 		RHICmdList.SetViewport(0, 0, 0.f, Size.X, Size.Y, 1.);
// 		PixelShader->SetParameters(RHICmdList, CameraTextureResource->GetTexture2DRHI(), Size, DefaultMatrix, MediaShaders::YUVOffset10bits, false);
//
// 		uint32 PrimitiveCount = 1 * 1 * 2;
// 		RHICmdList.DrawPrimitive(0, PrimitiveCount, 1);
// 	}
// 	RHICmdList.EndRenderPass();
// 	// RHICmdList.TransitionResource(ERHIAccess::EReadable, OutRTResource->TextureRHI);
// 	RHICmdList.CopyToResolveTarget(
// 		OutRTResource->GetRenderTargetTexture(),
// 		OutRTResource->TextureRHI, FResolveParams());
// }
//
// static int YUVtoRGB(int y, int u, int v)
// {
// 	int r, g, b;
// 	r = y + (int)1.402f*v;
// 	g = y - (int)(0.344f*u + 0.714f*v);
// 	b = y + (int)1.772f*u;
// 	r = r > 255 ? 255 : r < 0 ? 0 : r;
// 	g = g > 255 ? 255 : g < 0 ? 0 : g;
// 	b = b > 255 ? 255 : b < 0 ? 0 : b;
// 	return 0xff000000 | (b << 16) | (g << 8) | r;
// }
//
// static void NV21toRGB(unsigned char* rgb, char* yuv, int width, int height)
// {
// 	int total = width * height;
// 	char Y = {};
// 	char U = {};
// 	char V = {};
// 	unsigned char R, G, B;
// 	int index = 0;
//
// 	for (int h = 0; h < height; h++) {
// 		for (int w = 0; w < width; w++) {
//
// 			Y = yuv[h * width + w];
// 			if ((w & 1) == 0)
// 				V = yuv[total + (h >> 1) * width + w];
// 			if ((w & 1) == 1)
// 				U = yuv[total + (h >> 1) * width + w - 1];
//
// 			// OpenCV YCrCb --> RGB
// 			//B = Y + 1.773*(U-128);
// 			//G = Y - 0.714*(V-128) - 0.344*(U-128);
// 			//R = Y + 1.403*(V-128);
//
// 			// YUV-->RGB for HDTV(BT.601)
// 			B = Y + 2.03211*(U-128);
// 			G = Y - 0.39465*(U-128) - 0.5806*(V-128);
// 			R = Y + 1.13983*(V-128);
//
// 			// YUV-->RGB for HDTV(BT.709)
// 			//B = Y + 2.12798*(U-128);
// 			//G = Y - 0.21482*(U-128) - 0.38059*(V-128);
// 			//R = Y + 1.28033*(V-128);
//
// 			// YCbCr-->RGB
// 			// B = 1.164*(Y-16) + 2.018*(U-128);
// 			// G = 1.164*(Y-16) - 0.813*(U-128) - 0.391*(V-128);
// 			// R = 1.164*(Y-16) + 1.596*(V-128);
//
// 			R = R > 255 ? 255 : R < 0 ? 0 : R;
// 			G = G > 255 ? 255 : G < 0 ? 0 : G;
// 			B = B > 255 ? 255 : B < 0 ? 0 : B;
//
// 			rgb[index++] = B;
// 			rgb[index++] = G;
// 			rgb[index++] = R;
// 		}
// 	}
// }


FMatrix MatrixConverter(easyar::Matrix44F MatEasyAR)
{
	FMatrix Result;
	std::array<float, 16> data = MatEasyAR.data;
	FPlane X, Y, Z, W;
	X = FPlane(data[0], data[1], data[2], data[3]);
	Y = FPlane(data[4], data[5], data[6], data[7]);
	Z = FPlane(data[8], data[9], data[10], data[11]);
	W = FPlane(data[12], data[13], data[14], data[15]);
	Result = FMatrix(X, Y, Z, W);
	return Result;
}
