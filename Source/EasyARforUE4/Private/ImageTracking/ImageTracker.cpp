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

	Timer += DeltaTime;
	if (Timer >= (1. / FrameRate))
	{
		Timer -= 1. / FrameRate;
		_imageTracker->perFrame();
		auto CurrentFrame = _imageTracker->cameraFrame;
		// if (CurrentFrame->inputFrame()->index() != FrameIndex)
		// {
			auto Buffer = CurrentFrame->inputFrame()->image()->buffer();
			auto ImageProjection = CurrentFrame->inputFrame()->cameraParameters()->imageProjection((float)Width / (float)Height, 90, true, false);
			FMatrix ProjectionMatUE = MatrixConverter(ImageProjection);
			// CameraRenderer->Upload(Width, Height, CameraFrameData);
			CameraRenderer->Render(ProjectionMatUE, Buffer->data());
			// FrameIndex = CurrentFrame->inputFrame()->index();
		// }
	}
}

void UImageTrackers::Initialize()
{
	_imageTracker->cameraWidth = Width;
	_imageTracker->cameraHeight = Height;
	CameraRenderer = new FCameraRenderer(Width, Height, OutRT);
	
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
	}
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
