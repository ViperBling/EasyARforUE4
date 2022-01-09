#include "ImageTracking/ImageTracker.h"
#include "Components/SceneCaptureComponent2D.h"

static FMatrix MatrixConverter(easyar::Matrix44F& MatEasyAR);
static FTransform GetTransformFromMat44F(easyar::Matrix44F& MatEasyAR, FVector Scale);

UImageTrackers::UImageTrackers()
{
	PrimaryComponentTick.bCanEverTick = true;
	// PrimaryComponentTick.TickGroup = TG_PostPhysics;
	_imageTracker = std::make_unique<ImageTrackerWrapper>();
	// _motionTracker = std::make_unique<MotionTrakerWrapper>();
}

UImageTrackers::~UImageTrackers()
{
	_imageTracker.release();
	// _motionTracker.release();
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

	// if (Timer >= 1. / FrameRate)
	// {
	// 	Timer -= 1. / FrameRate;
	// 	_motionTracker->render();
	// 	auto CurrentFrame = _motionTracker->cameraFrame;
	// 	auto Buffer = CurrentFrame->inputFrame()->image()->buffer();
	// 	CameraRenderer->Render(Buffer->data());
	// 	
	// 	auto easyarProjection = CurrentFrame->inputFrame()->cameraParameters()->projection(0.01, 1000., (float)OutRT->SizeX / (float)OutRT->SizeY, 0, true, false);
	// 	FReversedZPerspectiveMatrix PerspectiveMatrix = FReversedZPerspectiveMatrix(45, (float)OutRT->SizeX, (float)OutRT->SizeY, 0.01);
	//
	// 	PerspectiveMatrix.M[0][0] = easyarProjection.data[1];
	// 	PerspectiveMatrix.M[1][1] = -easyarProjection.data[4];
	// 	PerspectiveMatrix.M[3][2] = -easyarProjection.data[11];
	// 	
	// 	// SceneCaptureA->CustomProjectionMatrix = PerspectiveMatrix;
	// 	// SceneCaptureB->CustomProjectionMatrix = PerspectiveMatrix;
	// 	
	// 	auto easyarCamTrans = _motionTracker->cameraTransform;
	//
	// 	StaticMeshComponent->SetStaticMesh(ImageTargetsCollection[FString("namecard.jpg")].Mesh);
	//
	// 	FTransform TmpMeshTransform = FTransform(GetTransformFromMat44F(
	// 		easyarCamTrans,
	// 		FVector(1)));
	// 	StaticMeshComponent->SetWorldTransform(FTransform(FRotator(0, 0, 0), FVector(30, 0, -20), FVector(2)));
	// 	
	// 	SceneCaptureA->SetWorldTransform(TmpMeshTransform);
	// 	SceneCaptureB->SetWorldTransform(TmpMeshTransform);
	// }
	
	if (Timer >= 1. / FrameRate)
	{
		Timer -= 1. / FrameRate;
		_imageTracker->perFrame();
		auto CurrentFrame = _imageTracker->cameraFrame;
		auto Buffer = CurrentFrame->inputFrame()->image()->buffer();
	
		// float FOVX = FMath::DegreesToRadians(45.0f);
		// float FOVY = FMath::DegreesToRadians(30.0f);
		// auto easyarProjection = CurrentFrame->inputFrame()->cameraParameters()->projection(0.01, 1000., 1280 / 720., 0, true, false);
		// auto easyarImageProjection = CurrentFrame->inputFrame()->cameraParameters()->imageProjection(1280 / 720., 0, true, false);
		// FReversedZPerspectiveMatrix PerspectiveMatrix = FReversedZPerspectiveMatrix(FOVX, FOVY,
		// 	easyarProjection.data[1] * FMath::Tan(FOVX),
		// 	-easyarProjection.data[4] * FMath::Tan(FOVY),
		// 	0.01, 10000);
	
		// PerspectiveMatrix.M[0][0] = easyarProjection.data[1];
		// PerspectiveMatrix.M[0][1] = easyarProjection.data[0];
		// PerspectiveMatrix.M[1][0] = easyarProjection.data[5];
		// PerspectiveMatrix.M[1][1] = -easyarProjection.data[4];
		// PerspectiveMatrix.M[3][2] = -easyarProjection.data[11];
	
		
		// SceneCaptureA->CustomProjectionMatrix = PerspectiveMatrix;
		// SceneCaptureB->CustomProjectionMatrix = PerspectiveMatrix;
		//
		// GEngine->AddOnScreenDebugMessage(
		// 	0, 1.0f, FColor::Green,
		// 	FString::Printf(TEXT("%s\n"), *FString(MatrixConverter(easyarImageProjection).ToString())));
		//
		//
		
		CameraRenderer->Render(Buffer->data());
	
		if (_imageTracker->TrackTargets.size() != 0)
		{
			for (auto target : _imageTracker->TrackTargets)
			{
				
				if (ImageTargetsCollection.Contains(FString(target.second->name().c_str())))
				{
					// GEngine->AddOnScreenDebugMessage(
					// 	0, 1.0f, FColor::Green,
					// 	FString::Printf(TEXT("Found Target (%s): %d\n"), *FString(target.second->name().c_str()), target.second->runtimeID()));
					StaticMeshComponent->SetStaticMesh(ImageTargetsCollection[FString(target.second->name().c_str())].Mesh);
					float ImageTargetSize = target.second->scale() * 100.;
					float targetScale = ImageTargetSize / StaticMeshComponent->GetStaticMesh()->GetBoundingBox().GetSize().GetMax();
					
					FTransform TmpMeshTransform = FTransform(GetTransformFromMat44F(
						_imageTracker->targetPose,
						FVector(targetScale)
						// ImageTargetsCollection[FString(target.second->name().c_str())].MeshTransform.GetScale3D()
						));
	
					GEngine->AddOnScreenDebugMessage(
						0, 1.0f, FColor::Green,
						FString::Printf(TEXT("%s\n"),
							*FString(FVector(_imageTracker->targetPose.data[3] * 100, _imageTracker->targetPose.data[7] * 100, _imageTracker->targetPose.data[11] * 100).ToString())));
					// GEngine->AddOnScreenDebugMessage(
					// 	1, 1.0f, FColor::Green,
					// 	FString::Printf(TEXT("%s\n"), *FString(TmpMeshTransform.ToString())));
	
					StaticMeshComponent->SetWorldTransform(TmpMeshTransform);
					StaticMeshComponent->AddLocalRotation(FRotator(90, 0, 0));
					// SceneCaptureA->SetWorldTransform(TmpMeshTransform.Inverse());
					// SceneCaptureB->SetWorldTransform(TmpMeshTransform.Inverse());
				}
			}
		}
		else 
		{
			StaticMeshComponent->SetStaticMesh(nullptr);
		}
	}
}

void UImageTrackers::Initialize()
{
	SceneCaptureA->bUseCustomProjectionMatrix = false;
	SceneCaptureB->bUseCustomProjectionMatrix = false;
	
	CameraRenderer = new FCameraRenderer(Width, Height, OutRT);
	
	_imageTracker->initialize();
	// _motionTracker->initialize();

	for (auto target : ImageTargetsCollection) 
	{
		_imageTracker->loadFromImage(TCHAR_TO_UTF8(*GetImagePath(target.Key)), TCHAR_TO_UTF8(*target.Key));
	}
}

void UImageTrackers::Start()
{
	_imageTracker->start();
	// _motionTracker->start();
}

void UImageTrackers::Stop()
{
	_imageTracker->stop();
	// _motionTracker->stop();
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
	float rad = 0.0174532925199444; // FQuat needs Radians. So degree * Pi/180 | Pi/180 = 0.0174532...
	FMatrix Sz = FMatrix::Identity;
	Sz.M[2][2] = -1;

	FMatrix Rotation = FMatrix(
		FVector(MatEasyAR.data[0], MatEasyAR.data[1], MatEasyAR.data[2]),
		FVector(MatEasyAR.data[4], MatEasyAR.data[5], MatEasyAR.data[6]),
		FVector(MatEasyAR.data[8], MatEasyAR.data[9], MatEasyAR.data[10]),
		FVector(0, 0, 0));
	
	FVector Translation = FVector(MatEasyAR.data[3], MatEasyAR.data[7], MatEasyAR.data[11]);
	
	// Rotation = Sz * Rotation * Sz;		// 通过四元数转换，不需要这一步
	Translation = Sz.TransformPosition(Translation);
	
	Translation *= 100.;
	Translation = FVector(Translation[2], Translation[0], Translation[1]);

	FRotator Rotator = Rotation.Rotator();
	
	FQuat qx(FVector(1, 0, 0), -Rotator.Yaw * rad);
	FQuat qz(FVector(0, 0, 1), -Rotator.Pitch * rad);
	FQuat qy(FVector(0, 1, 0), -Rotator.Roll * rad);
	
	FQuat Quat = qy * qz * qx;
	
	FTransform Result = FTransform(FRotator(Quat), Translation, Scale);
	return Result;
}