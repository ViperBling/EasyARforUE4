#include "ImageTracking/ImageTracker.h"

UImageTrackers::UImageTrackers()
{
	_imageTracker = std::unique_ptr<ImageTrackerWrapper>(new ImageTrackerWrapper());
}

UImageTrackers::~UImageTrackers()
{
	_imageTracker = nullptr;
}

void UImageTrackers::Initialize()
{
	
	_imageTracker->initialize();
	// for (auto n : ImageCollection)
	// {
	// 	_imageTracker->loadFromImage(TCHAR_TO_UTF8(*GetImagePath(n)));
	// }
	for (int32 i = 0; i != ImageCollection.Num(); ++i)
	{
		_imageTracker->loadFromImage(TCHAR_TO_UTF8(*GetImagePath(ImageCollection[i])));
	}
}

void UImageTrackers::Start()
{
	_imageTracker->start();
}

void UImageTrackers::Stop()
{
	_imageTracker->stop();
}

void UImageTrackers::CallEveryFrame()
{
	_imageTracker->perFrame();
}

FString UImageTrackers::GetImagePath(FString& ImageName)
{
	FString AssetsPath = FPaths::Combine(FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()), TEXT("NonAssets"));
	// FString AssetsPath = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("EasyARforUE4/Resources/Assets"));
	FString ImagePath = FPaths::Combine(AssetsPath, ImageName);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *ImagePath);
	return ImagePath;
}


