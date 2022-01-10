#pragma once

#include "CoreMinimal.h"
#include "ImageTrackerWrapper.h"
#include "Device/CameraRenderer.h"
#include "ImageTracker.generated.h"

USTRUCT(BlueprintType)
struct FEasyARMesh
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform MeshTransform;
};

UCLASS(ClassGroup = (EasyAR), meta = (BlueprintSpawnableComponent))
class EASYARFORUE4_API UImageTrackers : public USceneComponent
{
	GENERATED_BODY()
public:
	
	UImageTrackers();
	virtual ~UImageTrackers() override;

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void Initialize();

	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void Start();

	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void Stop();

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, FEasyARMesh> ImageTargetsCollection;

	// UPROPERTY(BlueprintReadWrite)
	// TMap<FString, UStaticMesh*> ImageTargets;
	
	UPROPERTY(BlueprintReadWrite)
	UTextureRenderTarget2D* OutRT;
	
	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(BlueprintReadWrite)
	USceneCaptureComponent2D* SceneCaptureA;

	UPROPERTY(BlueprintReadWrite)
	USceneCaptureComponent2D* SceneCaptureB;

	UPROPERTY(BlueprintReadWrite)
	int Width = 1280;

	UPROPERTY(BlueprintReadWrite)
	int Height = 960;

private:
	FString GetImagePath(FString& ImageName);

private:
	// std::unique_ptr<ImageTrackerWrapper> _imageTracker;
	// std::unique_ptr<MotionTrakerWrapper> _motionTracker;
	std::unique_ptr<ImageTrackerMotionFusionWrapper> _motionFusionTracker;
	FTransform TargetTransform;
	FCameraRenderer* CameraRenderer;
	float Timer = 0;
	const float FrameRate = 30.f;
};

