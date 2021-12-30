﻿#pragma once

#include "CoreMinimal.h"
#include "ImageTrackerWrapper.h"
#include "Device/CameraRenderer.h"
#include "ImageTracker.generated.h"

UCLASS()
class UEasyARMesh : public USceneComponent
{
	GENERATED_BODY()
public:
	UPROPERTY()
	UStaticMesh* Mesh;
	
	UPROPERTY()
	FTransform MeshTransform;

	UEasyARMesh() : Mesh(nullptr), MeshTransform(FTransform()){}
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

	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void CallEveryFrame(float DeltaTime);

public:
	
	// UPROPERTY(BlueprintReadWrite)
	// TMap<FString, UEasyARMesh*> ImageTargets;

	UPROPERTY(BlueprintReadWrite)
	TMap<FString, UStaticMesh*> ImageTargets;
	
	UPROPERTY(BlueprintReadWrite)
	UTextureRenderTarget2D* OutRT;
	
	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(BlueprintReadWrite)
	int Width = 1280;

	UPROPERTY(BlueprintReadWrite)
	int Height = 960;

private:
	FString GetImagePath(FString& ImageName);

private:
	std::unique_ptr<ImageTrackerWrapper> _imageTracker;
	FCameraRenderer* CameraRenderer;
	float Timer = 0;
	const float FrameRate = 30.f;
};

