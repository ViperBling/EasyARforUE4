#pragma once

#include "CoreMinimal.h"
#include "ImageTrackerWrapper.h"
#include "ImageTracker.generated.h"

UCLASS(Blueprintable, BlueprintType)
class EASYARFORUE4_API UImageTrackers : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> ImageCollection;

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* CameraBackground;

	UPROPERTY(BlueprintReadOnly)
	int Width = 672;

	UPROPERTY(BlueprintReadOnly)
	int Height = 1280;
	
	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void Initialize();

	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void Start();

	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void Stop();

	UFUNCTION(BlueprintCallable, Category = EasyAR)
	void CallEveryFrame();

	UFUNCTION(BlueprintCallable, Category = Actions)
	FString GetImagePath(FString& ImageName);

	UImageTrackers();
	virtual ~UImageTrackers();
	
private:
	FUpdateTextureRegion2D* CameraUpdateTextureRegion;
	std::unique_ptr<ImageTrackerWrapper> _imageTracker;

	void UpdateTextureRegions(
		UTexture2D* Texture, int32 MipIndex,
		uint32 NumRegions, FUpdateTextureRegion2D* Region2D,
		uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData);
};