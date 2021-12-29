#include "ImageTracking/ImageTracker.h"

static FMatrix MatrixConverter(easyar::Matrix44F MatEasyAR);

static FTransform GetTransformFromMat44F(easyar::Matrix44F& MatEasyAR, float Scale);

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
	Timer += DeltaTime;
	if (Timer >= 1. / FrameRate)
	{
		Timer -= 1. / FrameRate;
		_imageTracker->perFrame();
		auto CurrentFrame = _imageTracker->cameraFrame;
		auto Buffer = CurrentFrame->inputFrame()->image()->buffer();
	
		auto Projection = CurrentFrame->inputFrame()->cameraParameters()->projection(0.01, 1000., (float)Width / (float)Height, 0, true, false);
		FMatrix ProjectionMatUE = MatrixConverter(Projection);
		// if (*ProjectionMatUE.ToString())
		// {
		// 	UE_LOG(LogTemp, Warning, TEXT("%s"), *ProjectionMatUE.ToString());
		// }
		CameraRenderer->Render(Buffer->data());

		if (_imageTracker->TrackTargets.size() != 0)
		{
			for (auto target : _imageTracker->TrackTargets)
			{
				FTransform TmpMeshTransform = FTransform(GetTransformFromMat44F(_imageTracker->targetPose, 1));
				if (ImageTargets.Contains(FString(target.second->name().c_str())))
				{
					// GEngine->AddOnScreenDebugMessage(
					// 	0, 1.0f, FColor::Green,
					// 	FString::Printf(TEXT("Found Target (%s): %d\n"), *FString(target.second->name().c_str()), target.second->runtimeID()));
					// GEngine->AddOnScreenDebugMessage(
					// 	0, 1.0f, FColor::Green,
					// 	FString::Printf(TEXT("Target: %s (%d)\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n\n"),
					// 	*FString(target.second->name().c_str()), target.second->runtimeID(),
					// 	_imageTracker->targetPose.data[0], _imageTracker->targetPose.data[1], _imageTracker->targetPose.data[2], _imageTracker->targetPose.data[3],
					// 	_imageTracker->targetPose.data[4], _imageTracker->targetPose.data[5], _imageTracker->targetPose.data[6], _imageTracker->targetPose.data[7],
					// 	_imageTracker->targetPose.data[8], _imageTracker->targetPose.data[9], _imageTracker->targetPose.data[10], _imageTracker->targetPose.data[11],
					// 	_imageTracker->targetPose.data[12], _imageTracker->targetPose.data[13], _imageTracker->targetPose.data[14], _imageTracker->targetPose.data[15])
					// 	);
					
					StaticMeshComponent->SetStaticMesh(ImageTargets[FString(target.second->name().c_str())]);
					// GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Green, FString::Printf(TEXT("%s"), *ImageTargets[FString(target.second->name().c_str())]->GetName()));
					
					FTransform Test = FTransform(FQuat(0, 0, 0, 0), FVector(300., 0, 0));
					GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Green, FString::Printf(TEXT("%s"), *TmpMeshTransform.ToString()));
					StaticMeshComponent->SetRelativeTransform(TmpMeshTransform);
				}
				if (StaticMeshComponent->GetStaticMesh() != nullptr)
					StaticMeshComponent->SetRelativeTransform(TmpMeshTransform);
			}
		}
	}
}

void UImageTrackers::Initialize()
{
	_imageTracker->cameraWidth = Width;
	_imageTracker->cameraHeight = Height;
	CameraRenderer = new FCameraRenderer(Width, Height, OutRT);
	// StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	// StaticMeshComponent->SetupAttachment(this);
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

static FTransform GetTransformFromMat44F(easyar::Matrix44F& MatEasyAR, float Scale)
{
	FMatrix Sz = FMatrix::Identity;
	Sz.M[2][2] = -1;
	FMatrix Rotation = FMatrix(
		FPlane(MatEasyAR.data[2],  MatEasyAR.data[0], MatEasyAR.data[1],  0),
		FPlane(MatEasyAR.data[6],  MatEasyAR.data[4], MatEasyAR.data[5],  0),
		FPlane(MatEasyAR.data[10], MatEasyAR.data[8], MatEasyAR.data[9],  0),
		FPlane(0, 0, 0, 1));
	
	// FMatrix Rotation = FMatrix(
	// 	FPlane(MatEasyAR.data[8],MatEasyAR.data[9], MatEasyAR.data[10], 0),
	// 	FPlane(MatEasyAR.data[0],MatEasyAR.data[1], MatEasyAR.data[2],  0),
	// 	FPlane(MatEasyAR.data[4],MatEasyAR.data[5], MatEasyAR.data[6],  0),
	// 	FPlane(0, 0, 0, 1));
	
	FVector Translation = FVector(MatEasyAR.data[3], MatEasyAR.data[7], MatEasyAR.data[11]);
	
	Rotation = Sz * Rotation * Sz;
	Translation = Sz.TransformVector(Translation);
	Translation *= 100.;
	Translation = FVector(Translation[2], Translation[0], Translation[1]);
	
	// Rotation = FMatrix(Rotation., Rotation.GetColumn(0), Rotation.GetColumn(1), Rotation.GetColumn(3));
	// GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Green, FString::Printf(TEXT("%s"), *Translation.ToString()));
	FRotator Rotator = FQuat(Rotation).Rotator();

	// Rotator.Pitch = -Rotator.Pitch;
	// Rotator.Yaw = -Rotator.Yaw;
	// Rotator.Roll += 180;
	FTransform Result = FTransform(Rotator, Translation, FVector(0.5));
	return Result;
}