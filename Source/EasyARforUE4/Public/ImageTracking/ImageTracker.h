﻿#pragma once

#include "CoreMinimal.h"
#include "ImageTrackerWrapper.h"
#include "Device/CameraRenderer.h"
#include "ImageTracker.generated.h"

UCLASS(ClassGroup = (EasyAR), meta = (BlueprintSpawnableComponent))
class EASYARFORUE4_API UImageTrackers : public UActorComponent
{
	GENERATED_BODY()
public:
	
	UImageTrackers();
	virtual ~UImageTrackers() override;

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
	TArray<FString> ImageCollection;

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* CameraBackground;

	UPROPERTY(BlueprintReadWrite)
	UTextureRenderTarget2D* OutRT;

	UPROPERTY(BlueprintReadWrite)
	int Width = 1024;

	UPROPERTY(BlueprintReadWrite)
	int Height = 1024;
	
	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void Initialize();

	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void Start();

	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void Stop();

	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void CallEveryFrame(float DeltaTime);

	FCameraRenderer CameraRenderer;

private:
	FString GetImagePath(FString& ImageName);
	
	void UpdateTextureRegions(
		UTexture2D* Texture, int32 MipIndex,
		uint32 NumRegions, FUpdateTextureRegion2D* Region2D,
		uint32 SrcPitch, uint32 SrcBpp, void* SrcData, bool bFreeData);
	
	FUpdateTextureRegion2D* CameraUpdateTextureRegion;
	std::unique_ptr<ImageTrackerWrapper> _imageTracker;
	float Timer = 0;
	const float FrameRate = 60.f;
	bool bFirstFrame;
};