#include "ImageTracking/ImageTracker.h"

#include "Components/SceneCaptureComponent2D.h"

static FMatrix MatrixConverter(easyar::Matrix44F& MatEasyAR);
static FTransform GetTransformFromMat44F(easyar::Matrix44F& MatEasyAR, FVector Scale);

UImageTrackers::UImageTrackers()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_PostPhysics;
	_imageTracker = std::make_unique<ImageTrackerWrapper>();
	_motionTracker = std::make_unique<MotionTrakerWrapper>();
}

UImageTrackers::~UImageTrackers()
{
	_imageTracker.release();
	_motionTracker.release();
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
		_motionTracker->render();
		auto CurrentFrame = _motionTracker->cameraFrame;
		auto Buffer = CurrentFrame->inputFrame()->image()->buffer();
		CameraRenderer->Render(Buffer->data());
		
		auto easyarProjection = CurrentFrame->inputFrame()->cameraParameters()->projection(0.01, 1000., (float)OutRT->SizeX / (float)OutRT->SizeY, 0, true, false);
		FReversedZPerspectiveMatrix PerspectiveMatrix = FReversedZPerspectiveMatrix(45, (float)OutRT->SizeX, (float)OutRT->SizeY, 0.01);
	
		PerspectiveMatrix.M[0][0] = easyarProjection.data[1];
		PerspectiveMatrix.M[1][1] = -easyarProjection.data[4];
		PerspectiveMatrix.M[3][2] = -easyarProjection.data[11];
		
		SceneCaptureA->CustomProjectionMatrix = PerspectiveMatrix;
		SceneCaptureB->CustomProjectionMatrix = PerspectiveMatrix;
		
		auto easyarCamTrans = _motionTracker->cameraTransform;
		FMatrix CameraTransform = MatrixConverter(easyarCamTrans).Inverse();

		StaticMeshComponent->SetStaticMesh(ImageTargetsCollection[FString("namecard.jpg")].Mesh);
		StaticMeshComponent->SetWorldTransform(FTransform::Identity);

		FTransform TmpMeshTransform = FTransform(GetTransformFromMat44F(
			easyarCamTrans,
			ImageTargetsCollection[FString("namecard.jpg")].MeshTransform.GetScale3D()));
		SceneCaptureA->SetWorldTransform(TmpMeshTransform.Inverse());
		SceneCaptureB->SetWorldTransform(TmpMeshTransform.Inverse());

		GEngine->AddOnScreenDebugMessage(
			0, 1.0f, FColor::Green,
			FString::Printf(TEXT("%s\n"), *FString(TmpMeshTransform.Inverse().ToString())));
	}
	
	// if (Timer >= 1. / FrameRate)
	// {
	// 	Timer -= 1. / FrameRate;
	// 	_imageTracker->perFrame();
	// 	auto CurrentFrame = _imageTracker->cameraFrame;
	// 	auto Buffer = CurrentFrame->inputFrame()->image()->buffer();
	//
	// 	auto easyarProjection = CurrentFrame->inputFrame()->cameraParameters()->projection(0.01, 1000., (float)OutRT->SizeX / (float)OutRT->SizeY, 0, true, false);
	// 	FReversedZPerspectiveMatrix PerspectiveMatrix = FReversedZPerspectiveMatrix(45, (float)OutRT->SizeX, (float)OutRT->SizeY, 0.01);
	//
	// 	PerspectiveMatrix.M[0][0] = easyarProjection.data[1];
	// 	PerspectiveMatrix.M[1][1] = -easyarProjection.data[4];
	// 	PerspectiveMatrix.M[3][2] = -easyarProjection.data[11];
	// 	
	// 	SceneCaptureA->CustomProjectionMatrix = PerspectiveMatrix;
	// 	SceneCaptureB->CustomProjectionMatrix = PerspectiveMatrix;
	// 	
	// 	// GEngine->AddOnScreenDebugMessage(
	// 	// 	1, 1.0f, FColor::Green,
	// 	// 	FString::Printf(TEXT("%s\n"), *FString(PerspectiveMatrix.ToString())));
	// 	
	// 	CameraRenderer->Render(Buffer->data());
	//
	// 	if (_imageTracker->TrackTargets.size() != 0)
	// 	{
	// 		for (auto target : _imageTracker->TrackTargets)
	// 		{
	// 			
	// 			if (ImageTargetsCollection.Contains(FString(target.second->name().c_str())))
	// 			{
	// 				// GEngine->AddOnScreenDebugMessage(
	// 				// 	0, 1.0f, FColor::Green,
	// 				// 	FString::Printf(TEXT("Found Target (%s): %d\n"), *FString(target.second->name().c_str()), target.second->runtimeID()));
	// 				// GEngine->AddOnScreenDebugMessage(
	// 				// 	0, 1.0f, FColor::Green,
	// 				// 	FString::Printf(TEXT("Target: %s (%d)\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n\n"),
	// 				// 	*FString(target.second->name().c_str()), target.second->runtimeID(),
	// 				// 	_imageTracker->targetPose.data[0], _imageTracker->targetPose.data[1], _imageTracker->targetPose.data[2], _imageTracker->targetPose.data[3],
	// 				// 	_imageTracker->targetPose.data[4], _imageTracker->targetPose.data[5], _imageTracker->targetPose.data[6], _imageTracker->targetPose.data[7],
	// 				// 	_imageTracker->targetPose.data[8], _imageTracker->targetPose.data[9], _imageTracker->targetPose.data[10], _imageTracker->targetPose.data[11],
	// 				// 	_imageTracker->targetPose.data[12], _imageTracker->targetPose.data[13], _imageTracker->targetPose.data[14], _imageTracker->targetPose.data[15])
	// 				// 	);
	// 				
	// 				FTransform TmpMeshTransform = FTransform(GetTransformFromMat44F(
	// 					_imageTracker->targetPose,
	// 					ImageTargetsCollection[FString(target.second->name().c_str())].MeshTransform.GetScale3D()));
	// 				
	// 				StaticMeshComponent->SetStaticMesh(ImageTargetsCollection[FString(target.second->name().c_str())].Mesh);
	// 				// StaticMeshComponent->SetRelativeTransform(FTransform::Identity);
	// 				// ViewInfo.Location = TmpMeshTransform.GetTranslation();
	// 				// ViewInfo.Rotation = TmpMeshTransform.Rotator();
	// 				// SceneCaptureA->SetCameraView(ViewInfo);
	// 				// SceneCaptureB->SetCameraView(ViewInfo);
	//
	// 				// GEngine->AddOnScreenDebugMessage(
	// 				// 	0, 1.0f, FColor::Green,
	// 				// 	FString::Printf(TEXT("%s\n"), *FString(TmpMeshTransform.Rotator().ToString())));
	// 				
	// 				StaticMeshComponent->SetRelativeTransform(TmpMeshTransform);
	// 				StaticMeshComponent->AddLocalRotation(FRotator(90, 0, 0));
	// 				// StaticMeshComponent->AddLocalTransform(ImageTargetsCollection[FString(target.second->name().c_str())].MeshTransform);
	// 			}
	// 			// if (StaticMeshComponent->GetStaticMesh() != nullptr)
	// 			// 	StaticMeshComponent->SetStaticMesh(nullptr);
	// 		}
	// 	}
	// }
}

void UImageTrackers::Initialize()
{
	SceneCaptureA->bUseCustomProjectionMatrix = true;
	SceneCaptureB->bUseCustomProjectionMatrix = true;
	
	CameraRenderer = new FCameraRenderer(Width, Height, OutRT);
	
	_imageTracker->initialize();
	_motionTracker->initialize();

	for (auto target : ImageTargetsCollection) 
	{
		_imageTracker->loadFromImage(TCHAR_TO_UTF8(*GetImagePath(target.Key)), TCHAR_TO_UTF8(*target.Key));
	}
}

void UImageTrackers::Start()
{
	_imageTracker->start();
	_motionTracker->start();
}

void UImageTrackers::Stop()
{
	_imageTracker->stop();
	_motionTracker->stop();
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

FMatrix MatrixConverter(easyar::Matrix44F& MatEasyAR)
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

static FTransform GetTransformFromMat44F(easyar::Matrix44F& MatEasyAR, FVector Scale)
{
	FMatrix Sz = FMatrix::Identity;
	Sz.M[2][2] = -1;

	FMatrix Rotation = FMatrix(
		FVector(MatEasyAR.data[0], MatEasyAR.data[1], MatEasyAR.data[2]),
		FVector(MatEasyAR.data[4], MatEasyAR.data[5], MatEasyAR.data[6]),
		FVector(MatEasyAR.data[8], MatEasyAR.data[9], MatEasyAR.data[10]),
		FVector(0, 0, 0));
	
	FVector Translation = FVector(MatEasyAR.data[3], MatEasyAR.data[7], MatEasyAR.data[11]);
	
	Rotation = Sz * Rotation * Sz;
	// Rotation.M[2][2] *= -1;
	Translation = Sz.TransformPosition(Translation);
	
	Translation *= 100.;
	Translation = FVector(Translation[2], Translation[0], Translation[1]);

	FRotator Rotator = FQuat(Rotation).Rotator();
	
	float Pitch = Rotator.Roll;				// X->Y
	float Yaw = Rotator.Pitch;				// Y->Z
	float Roll = Rotator.Yaw;				// Z->X
	Rotator = FRotator(Pitch, Yaw, Roll);
	Rotator.Pitch *= -1.;
	
	FTransform Result = FTransform(Rotator, Translation, Scale);
	return Result;
}