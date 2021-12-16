#include "ImageTracking/ImageTracker.h"

#include "Engine/Texture2DDynamic.h"
#include "Rendering/Texture2DResource.h"

UImageTrackers::UImageTrackers()
{
	_imageTracker = std::unique_ptr<ImageTrackerWrapper>(new ImageTrackerWrapper());
	Width = 672;
	Height = 1280;
	
	_imageTracker->cameraWidth = Width;
	_imageTracker->cameraHeight = Height;

	CameraUpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);

	CameraBackground = UTexture2D::CreateTransient(Width, Height, PF_UYVY);
	
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
}

void UImageTrackers::Stop()
{
	_imageTracker->stop();
	delete CameraUpdateTextureRegion;
}

void UImageTrackers::CallEveryFrame()
{
	// check(IsInGameThread());
	_imageTracker->perFrame();
	// UE_LOG(LogTemp, Warning, TEXT("%d"), _imageTracker->cameraImage->format());
	// GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Green, FString::Printf(TEXT("%d"), _imageTracker->cameraImage->format()));
	UpdateTextureRegions(
		CameraBackground, 0, 1,
		CameraUpdateTextureRegion, 4 * Width, 4,
		(uint8*)_imageTracker->cameraImage->buffer()->data(), false);
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
	uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData)
{
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
		RegionData->SrcData = SrcData;

		ENQUEUE_RENDER_COMMAND(UpdateTextureRegionData)
		([RegionData, bFreeData](FRHICommandListImmediate& RHICmdList)
		{
			for (uint32 RegionIndex = 0; RegionIndex < RegionData->NumRegions; ++RegionIndex)
			{
				int32 CurrentFirstMip = RegionData->Texture2DResource->GetCurrentFirstMip();
				if (RegionData->MipIndex >= CurrentFirstMip)
				{
					RHICmdList.UpdateTexture2D(
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
	}
}