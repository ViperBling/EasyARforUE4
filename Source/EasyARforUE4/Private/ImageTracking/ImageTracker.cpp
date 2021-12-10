#include "ImageTracking/ImageTracker.h"

UImageTrackers::UImageTrackers()
{
	_imageTracker = std::unique_ptr<ImageTrackerWrapper>(new ImageTrackerWrapper());
	UpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, 0, 0);
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
	delete CameraBackground;
	delete UpdateTextureRegion;
}

void UImageTrackers::CallEveryFrame()
{
	_imageTracker->perFrame();
	CameraBackground = UTexture2D::CreateTransient(_imageTracker->cameraImage->width(), _imageTracker->cameraImage->height());
	// FUpdateTextureRegion2D* Regions = new FUpdateTextureRegion2D(0, 0, 0, 0, _imageTracker->cameraImage->width(), _imageTracker->cameraImage->height());
	UpdateTextureRegion->Width = _imageTracker->cameraImage->width();
	UpdateTextureRegion->Height = _imageTracker->cameraImage->height();
	CameraBackground->UpdateTextureRegions(
		0, 1, UpdateTextureRegion, UpdateTextureRegion->Width * 32, 32,
		(uint8*)_imageTracker->cameraImage->buffer()->data()
	);
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


