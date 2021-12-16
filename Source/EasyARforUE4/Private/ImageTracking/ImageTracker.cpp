#include "ImageTracking/ImageTracker.h"

#include "Engine/Texture2DDynamic.h"
#include "Rendering/Texture2DResource.h"

static int YUVtoRGB(int y, int u, int v);

UImageTrackers::UImageTrackers()
{
	_imageTracker = std::unique_ptr<ImageTrackerWrapper>(new ImageTrackerWrapper());
	Width = 1280;
	Height = 1280;
	
	_imageTracker->cameraWidth = Width;
	_imageTracker->cameraHeight = Height;

	CameraUpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);

	CameraBackground = UTexture2D::CreateTransient(Width, Height, PF_B8G8R8A8);
	
	CameraBackground->UpdateResource();
}

UImageTrackers::~UImageTrackers()
{
	_imageTracker = nullptr;
}

void UImageTrackers::Initialize()
{
	
	_imageTracker->initialize();
	
	for (auto n : ImageCollection)
	{
		_imageTracker->loadFromImage(TCHAR_TO_UTF8(*GetImagePath(n)), TCHAR_TO_UTF8(*n));
	}
}

void UImageTrackers::Start()
{
	_imageTracker->start();
	bFirstFrame = true;
}

void UImageTrackers::Stop()
{
	_imageTracker->stop();
	delete CameraUpdateTextureRegion;
}

void UImageTrackers::CallEveryFrame(float DeltaTime)
{
	// Timer += DeltaTime;
	// if (Timer >= (1. / FrameRate))
	// {
	// 	Timer = 0;
	// 	check(IsInGameThread());
	// 	_imageTracker->perFrame();
	// 	void* CameraFrameData = nullptr;
	// 	if (bFirstFrame)
	// 	{
	// 		CameraFrameData = _imageTracker->cameraImage->buffer()->data();
	// 	}
	// 	if (CameraFrameData != nullptr)
	// 	{
	// 		// UE_LOG(LogTemp, Warning, TEXT("%d"), _imageTracker->cameraImage->format());
	// 		// GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Green, FString::Printf(TEXT("%d"), _imageTracker->cameraImage->format()));
	// 		UpdateTextureRegions(
	// 			CameraBackground, 0, 1,
	// 			CameraUpdateTextureRegion, 4 * Width, 4,
	// 			CameraFrameData, false);
	// 		bFirstFrame = false;
	// 	}
	// }

	_imageTracker->perFrame();
	void* CameraFrameData = nullptr;
	CameraFrameData = _imageTracker->cameraImage->buffer()->data();
	UpdateTextureRegions(
		CameraBackground, 0, 1,
		CameraUpdateTextureRegion, 4 * Width, 4,
		CameraFrameData, false);
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

void UImageTrackers::UpdateTextureRegions(
	UTexture2D* Texture, int32 MipIndex, uint32 NumRegions,
	FUpdateTextureRegion2D* Region2D,
	uint32 SrcPitch, uint32 SrcBpp, void* SrcData, bool bFreeData)
{
	// check(IsInRenderingThread());
	if (Texture && Texture->Resource)
	{
		struct FUpdateTextureRegionsData
		{
			FTexture2DResource* Texture2DResource;
			int32 MipIndex;
			uint32 NumRegions;
			FUpdateTextureRegion2D* Regions;
			uint32 SrcPitch;
			uint32 SrcBpp;
			uint8* SrcData;
		};

		FUpdateTextureRegionsData* RegionData = new FUpdateTextureRegionsData;

		RegionData->Texture2DResource = (FTexture2DResource*)Texture->Resource;
		RegionData->MipIndex = MipIndex;
		RegionData->NumRegions = NumRegions;
		RegionData->Regions = Region2D;
		RegionData->SrcPitch = SrcPitch;
		RegionData->SrcBpp = SrcBpp;

		char* yuv420sp = (char*)SrcData;
		int* rgb = new int[Width * Height];
		
		int size = Width * Height;
		int offset = size;
		
		int u, v, y1, y2, y3, y4;
		
		for (int i = 0, k = 0; i < size; i += 2, k += 2) {
			y1 = yuv420sp[i] & 0xff;
			y2 = yuv420sp[i + 1] & 0xff;
			y3 = yuv420sp[Width + i] & 0xff;
			y4 = yuv420sp[Width + i + 1] & 0xff;
		
			u = yuv420sp[offset + k] & 0xff;
			v = yuv420sp[offset + k + 1] & 0xff;
			u = u - 128;
			v = v - 128;
		
			rgb[i] = YUVtoRGB(y1, u, v);
			rgb[i + 1] = YUVtoRGB(y2, u, v);
			rgb[Width + i] = YUVtoRGB(y3, u, v);
			rgb[Width + i + 1] = YUVtoRGB(y4, u, v);
		
			if (i != 0 && (i + 2) % Width == 0)
				i += Width;
		}
		
		RegionData->SrcData = (uint8*)rgb;
		// RegionData->SrcData = (uint8*)SrcData;
		
		ENQUEUE_RENDER_COMMAND(UpdateTextureRegionData)
		([RegionData, bFreeData](FRHICommandListImmediate& RHICmdList)
		{
			for (uint32 RegionIndex = 0; RegionIndex < RegionData->NumRegions; ++RegionIndex)
			{
				int32 CurrentFirstMip = RegionData->Texture2DResource->GetCurrentFirstMip();
				if (RegionData->MipIndex >= CurrentFirstMip)
				{
					RHIUpdateTexture2D(
					RegionData->Texture2DResource->GetTexture2DRHI(),
					RegionData->MipIndex - CurrentFirstMip,
					RegionData->Regions[RegionIndex],
					RegionData->SrcPitch,
					RegionData->SrcData
					+ RegionData->Regions[RegionIndex].SrcY * RegionData->SrcPitch
					+ RegionData->Regions[RegionIndex].SrcX * RegionData->SrcBpp
					);
				}
			}
			if (bFreeData)
			{
				FMemory::Free(RegionData->Regions);
				FMemory::Free(RegionData->SrcData);
			}
			delete RegionData;
		});
		delete[] rgb;
	}
}

static int YUVtoRGB(int y, int u, int v)
{
	int r, g, b;
	r = y + (int)1.402f*v;
	g = y - (int)(0.344f*u + 0.714f*v);
	b = y + (int)1.772f*u;
	r = r>255 ? 255 : r<0 ? 0 : r;
	g = g>255 ? 255 : g<0 ? 0 : g;
	b = b>255 ? 255 : b<0 ? 0 : b;
	return 0xff000000 | (b << 16) | (g << 8) | r;
}
