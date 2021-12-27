#include "ImageTracking/ImageTracker.h"

static FMatrix MatrixConverter(easyar::Matrix44F MatEasyAR);

UImageTrackers::UImageTrackers()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_PostPhysics;
	_imageTracker = std::make_unique<ImageTrackerWrapper>();
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
	auto CurrentFrame = _imageTracker->cameraFrame;
	auto Buffer = CurrentFrame->inputFrame()->image()->buffer();
	// UE_LOG(LogTemp, Warning, TEXT("%d"), Buffer->size());
	
	auto ImageProjection = CurrentFrame->inputFrame()->cameraParameters()->imageProjection((float)Width / (float)Height, 90, true, false);
	FMatrix ProjectionMatUE = MatrixConverter(ImageProjection);
	CameraRenderer->Render(ProjectionMatUE, Buffer->data());

	if (_imageTracker->TrackTargets.size() != 0)
	{
		for (auto target : _imageTracker->TrackTargets)
		{
			if (ImageTargets.Contains(FString(target.second->name().c_str())))
			{
				GEngine->AddOnScreenDebugMessage(
					0, 1.0f, FColor::Green,
					FString::Printf(TEXT("Found Target (%s): %d\n"), *FString(target.second->name().c_str()), target.second->runtimeID()));
			}
		}
	}
}

void UImageTrackers::Initialize()
{
	_imageTracker->cameraWidth = Width;
	_imageTracker->cameraHeight = Height;
	CameraRenderer = new FCameraRenderer(Width, Height, OutRT);
	
	_imageTracker->initialize();
	
	//for (auto n : ImageCollection)
	//{
	//	_imageTracker->loadFromImage(TCHAR_TO_UTF8(*GetImagePath(n)), TCHAR_TO_UTF8(*n));
	//}

	for (auto target : ImageTargets) 
	{
		_imageTracker->loadFromImage(TCHAR_TO_UTF8(*GetImagePath(target.Key)), TCHAR_TO_UTF8(*target.Key));
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

void UImageTrackers::CallEveryFrame(float DeltaTime)
{
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
