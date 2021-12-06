#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "easyar/types.hpp"
#include <unordered_map>
#include "ImageTracking.generated.h"

UCLASS()
class EASYARFORUE4_API AImageTracker : public AActor
{
	GENERATED_BODY()
	AImageTracker();
	
	virtual ~AImageTracker() override
	{
		// Free the dll handle
		FPlatformProcess::FreeDllHandle(EasyARSenseDll);
		EasyARSenseDll = nullptr;
	}
	
public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	// virtual void BeginDestroy() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EasyARImageFiles")
	TArray<FString> ImageFiles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EasyARStreamingAssets")
	FString AssetsPath = FPaths::Combine(FPaths::ProjectPluginsDir(), FString("EasyARforUE4/Resources/Assets"));

protected:
	void LoadFromImage(const std::string& FileName);
	void Initialize();
	bool Start();
	void Finalize();
	void Stop();
	void NextFrame();

	std::shared_ptr<easyar::DelayedCallbackScheduler> Scheduler;
	std::shared_ptr<easyar::CameraDevice> Camera;
	std::shared_ptr<easyar::ImageTracker> Tracker;
	std::shared_ptr<easyar::InputFrameThrottler> Throttler;
	std::shared_ptr<easyar::OutputFrameFork> OutputFrameFork;
	std::shared_ptr<easyar::OutputFrameBuffer> OutputFrameBuffer;
	std::shared_ptr<easyar::InputFrameToFeedbackFrameAdapter> I2FrameAdapter;
	std::unordered_map<int, std::shared_ptr<easyar::ImageTarget>> TrackTargets;
	
	bool IsQuited;
	void* EasyARSenseDll;
};
