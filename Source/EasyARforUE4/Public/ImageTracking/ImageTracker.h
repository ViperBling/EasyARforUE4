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
	
	UFUNCTION(BlueprintCallable, Category = Init)
	void Initialize();

	UFUNCTION(BlueprintCallable, Category = Actions)
	void Start();

	UFUNCTION(BlueprintCallable, Category = Actions)
	void Stop();

	UFUNCTION(BlueprintCallable, Category = Actions)
	void CallEveryFrame();

	UFUNCTION(BlueprintCallable, Category = Actions)
	FString GetImagePath(FString& ImageName);

	UImageTrackers();
	virtual ~UImageTrackers();
	
private:
	std::unique_ptr<ImageTrackerWrapper> _imageTracker;
};