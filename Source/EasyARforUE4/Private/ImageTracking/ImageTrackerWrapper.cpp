#include "ImageTracking/ImageTrackerWrapper.h"

ImageTrackerWrapper::ImageTrackerWrapper()
{
}

ImageTrackerWrapper::~ImageTrackerWrapper()
{
}

void ImageTrackerWrapper::initialize()
{
	Scheduler = std::make_shared<easyar::DelayedCallbackScheduler>();
	Throttler = easyar::InputFrameThrottler::create();
	I2FrameAdapter = easyar::InputFrameToFeedbackFrameAdapter::create();
	OutputFrameFork = easyar::OutputFrameFork::create(2);
	OutputFrameBuffer = easyar::OutputFrameBuffer::create();
	
	// ObjectSensing模式Camera Size固定为1280x960，导致画面和SceneCapture的对应不上，会漂移，设置为1280x720
	Camera = easyar::CameraDeviceSelector::createCameraDevice(easyar::CameraDevicePreference::PreferSurfaceTracking);
	
	if (!Camera->openWithPreferredType(easyar::CameraDeviceType::Back))
	{
		UE_LOG(LogTemp, Warning, TEXT("Camera Open Failed"));
		// return;
	}
	Camera->setFocusMode(easyar::CameraDeviceFocusMode::Continousauto);
	Camera->setSize(easyar::Vec2I{{1280, 720}});
	Tracker = easyar::ImageTracker::create();
	
	Camera->inputFrameSource()->connect(Throttler->input());
	Throttler->output()->connect(I2FrameAdapter->input());
	I2FrameAdapter->output()->connect(Tracker->feedbackFrameSink());
	Tracker->outputFrameSource()->connect(OutputFrameFork->input());
	OutputFrameFork->output(0)->connect(OutputFrameBuffer->input());
	
	OutputFrameBuffer->signalOutput()->connect(Throttler->signalInput());
	OutputFrameFork->output(1)->connect(I2FrameAdapter->sideInput());

	Camera->setBufferCapacity(
		Throttler->bufferRequirement() +
		I2FrameAdapter->bufferRequirement() +
		OutputFrameBuffer->bufferRequirement() +
		Tracker->bufferRequirement() + 2);
	// Camera->setBufferCapacity(20);
}

bool ImageTrackerWrapper::start()
{
	bool Status = true;
	Status &= Camera->start();
	Status &= Tracker->start();
	return Status;
}

void ImageTrackerWrapper::stop()
{
	Tracker->stop();
	Camera->stop();
	
	TrackTargets.clear();
	Tracker = nullptr;
	Camera = nullptr;
	Throttler = nullptr;
	OutputFrameBuffer = nullptr;
	OutputFrameFork = nullptr;
	I2FrameAdapter = nullptr;
	Scheduler = nullptr;
}

void ImageTrackerWrapper::perFrame()
{
	while (Scheduler->runOne()) {}

	std::optional<std::shared_ptr<easyar::OutputFrame>> oFrame = OutputFrameBuffer->peek();
	if (!oFrame.has_value()) { return; }
	cameraFrame = oFrame.value();
	
	if (!cameraFrame->inputFrame()->hasCameraParameters())
	{
		UE_LOG(LogTemp, Warning, TEXT("Don't have camera parameters"));
		return;
	}
	
	std::unordered_map<int, std::shared_ptr<easyar::ImageTarget>> lostCandidates = TrackTargets;
	for (auto && result : cameraFrame->results())
	{
		if (!result.has_value()) { return; }
		auto imageTrackerResult = std::static_pointer_cast<easyar::ImageTrackerResult>(result.value());

		if (imageTrackerResult != nullptr)
		{
			for (auto && targetInstance : imageTrackerResult->targetInstances())
			{
				auto status = targetInstance->status();
				auto target = targetInstance->target();
				if (!target.has_value()) { continue; }
				auto imageTarget = std::static_pointer_cast<easyar::ImageTarget>(target.value());
				if (imageTarget == nullptr) { continue; }
				if (status == easyar::TargetStatus::Tracked)
				{
					if (TrackTargets.count(imageTarget->runtimeID()) == 0)
					{
						TrackTargets[imageTarget->runtimeID()] = imageTarget;
					}
					lostCandidates.erase(imageTarget->runtimeID());
					targetPose = targetInstance->pose();
				}
			}
		}
	}

	for (auto p : lostCandidates)
	{
		auto imageTarget = std::get<1>(p);
		if (TrackTargets.count(imageTarget->runtimeID()) > 0)
		{
			TrackTargets.erase(imageTarget->runtimeID());
		}
	}
}

void ImageTrackerWrapper::loadFromImage(const std::string& filename, const std::string& name, const float scale)
{
	// Scale是图片宽度和米的比例，也就是多少米，UE的单位是厘米
	std::optional<std::shared_ptr<easyar::ImageTarget>> ImageTarget =
		easyar::ImageTarget::createFromImageFile(filename, easyar::StorageType::Assets, name, "", "", scale);
	if (ImageTarget.has_value())
	{
		Tracker->loadTarget(ImageTarget.value(), Scheduler, [](std::shared_ptr<easyar::Target> target, bool status)
		{
			GEngine->AddOnScreenDebugMessage(
				0, 1.0f, FColor::Red,
				FString::Printf(TEXT("Load Target (%d): %s %d\n"), status, *FString(target->name().c_str()), target->runtimeID()));
			UE_LOG(LogTemp, Warning, TEXT("Load Target (%d): %s %d\n"), status, *FString(target->name().c_str()), target->runtimeID());
		});
	}
}

// =======================================================================================================
MotionTrakerWrapper::MotionTrakerWrapper()
{
}

MotionTrakerWrapper::~MotionTrakerWrapper()
{
}

void MotionTrakerWrapper::initialize()
{
	Scheduler = std::make_shared<easyar::DelayedCallbackScheduler>();
	I2FrameAdapter = easyar::InputFrameToOutputFrameAdapter::create();
	OutputFrameBuffer = easyar::OutputFrameBuffer::create();
	
	MotionTrackerCamera = std::make_shared<easyar::MotionTrackerCameraDevice>();
	MotionTrackerCamera->setTrackingMode(easyar::MotionTrackerCameraDeviceTrackingMode::VIO);
	MotionTrackerCamera->inputFrameSource()->connect(I2FrameAdapter->input());
	I2FrameAdapter->output()->connect(OutputFrameBuffer->input());

	MotionTrackerCamera->setFrameRateType(easyar::MotionTrackerCameraDeviceFPS::Camera_FPS_30);
	MotionTrackerCamera->setFocusMode(easyar::MotionTrackerCameraDeviceFocusMode::Continousauto);
	MotionTrackerCamera->setFrameResolutionType(easyar::MotionTrackerCameraDeviceResolution::Resolution_1280);
	
	MotionTrackerCamera->setBufferCapacity(OutputFrameBuffer->bufferRequirement() + 8);
}

bool MotionTrakerWrapper::start()
{
	bool Status = true;
	Status &= MotionTrackerCamera->start();
	return Status;
}

void MotionTrakerWrapper::stop()
{
	if (MotionTrackerCamera != nullptr)
	{
		MotionTrackerCamera->stop();
	}
	MotionTrackerCamera->close();
}

void MotionTrakerWrapper::render()
{
	while (Scheduler->runOne()) {}
	
	std::optional<std::shared_ptr<easyar::OutputFrame>> oFrame = OutputFrameBuffer->peek();
	if (!oFrame.has_value()) { return; }
	cameraFrame = oFrame.value();
	auto iFrame = cameraFrame->inputFrame();
	
	GEngine->AddOnScreenDebugMessage(
		1, 1.0f, FColor::Green,
		*FString::Printf(TEXT("%s\n"), *FString(FVector(iFrame->cameraParameters()->size().data[0], iFrame->cameraParameters()->size().data[1], 0).ToString())));
		
	if (!iFrame->hasCameraParameters())
	{
		UE_LOG(LogTemp, Warning, TEXT("Don't have camera parameters"));
		return;
	}

	if (iFrame->trackingStatus() != easyar::MotionTrackingStatus::NotTracking)
	{
		cameraTransform = iFrame->cameraTransform();
	}
}


// ============================================================================================================
ImageTrackerMotionFusionWrapper::ImageTrackerMotionFusionWrapper()
{
}

ImageTrackerMotionFusionWrapper::~ImageTrackerMotionFusionWrapper()
{
}

void ImageTrackerMotionFusionWrapper::initialize()
{
	Scheduler = std::make_shared<easyar::DelayedCallbackScheduler>();
	Throttler = easyar::InputFrameThrottler::create();
	I2FrameAdapter = easyar::InputFrameToFeedbackFrameAdapter::create();
	OutputFrameFork = easyar::OutputFrameFork::create(2);
	OutputFrameBuffer = easyar::OutputFrameBuffer::create();
	RealTimeWorldTransform = std::make_shared<easyar::RealTimeCoordinateTransform>();
	RealTimeWorldTransform->setBufferSize(15);
	
	
	MotionTrackerCamera = std::make_shared<easyar::MotionTrackerCameraDevice>();
	MotionTrackerCamera->setFrameRateType(easyar::MotionTrackerCameraDeviceFPS::Camera_FPS_60);
	MotionTrackerCamera->setFocusMode(easyar::MotionTrackerCameraDeviceFocusMode::Continousauto);
	//MotionTrackerCamera->setFrameResolutionType(easyar::MotionTrackerCameraDeviceResolution::Resolution_1280);
	MotionTrackerCamera->setTrackingMode(easyar::MotionTrackerCameraDeviceTrackingMode::Anchor);
	
	Tracker = easyar::ImageTracker::create();
	
	MotionTrackerCamera->inputFrameSource()->connect(Throttler->input());
	Throttler->output()->connect(I2FrameAdapter->input());
	I2FrameAdapter->output()->connect(Tracker->feedbackFrameSink());
	Tracker->outputFrameSource()->connect(OutputFrameFork->input());
	OutputFrameFork->output(0)->connect(OutputFrameBuffer->input());
	
	OutputFrameBuffer->signalOutput()->connect(Throttler->signalInput());
	OutputFrameFork->output(1)->connect(I2FrameAdapter->sideInput());

	MotionTrackerCamera->setBufferCapacity(
		Throttler->bufferRequirement() +
		I2FrameAdapter->bufferRequirement() +
		OutputFrameBuffer->bufferRequirement() +
		Tracker->bufferRequirement() + 2);
}

bool ImageTrackerMotionFusionWrapper::start()
{
	bool Status = true;
	Status &= MotionTrackerCamera->start();
	Status &= Tracker->start();
	return Status;
}

void ImageTrackerMotionFusionWrapper::stop()
{
	Tracker->stop();
	MotionTrackerCamera->stop();
	
	TrackTargets.clear();
	Tracker = nullptr;
	MotionTrackerCamera = nullptr;
	Throttler = nullptr;
	OutputFrameBuffer = nullptr;
	OutputFrameFork = nullptr;
	I2FrameAdapter = nullptr;
	Scheduler = nullptr;
}

void ImageTrackerMotionFusionWrapper::render()
{
	while (Scheduler->runOne()) {}

	std::optional<std::shared_ptr<easyar::OutputFrame>> oFrame = OutputFrameBuffer->peek();
	if (!oFrame.has_value()) { return; }
	cameraFrame = oFrame.value();
	auto iFrame = cameraFrame->inputFrame();
	
	if (!iFrame->hasCameraParameters())
	{
		UE_LOG(LogTemp, Warning, TEXT("Don't have camera parameters"));
		return;
	}
	cameraLocalTransform = iFrame->cameraTransform();
	std::unordered_map<int, std::shared_ptr<easyar::ImageTarget>> lostCandidates = TrackTargets;
	for (auto && result : cameraFrame->results())
	{
		if (!result.has_value()) { return; }
		auto imageTrackerResult = std::static_pointer_cast<easyar::ImageTrackerResult>(result.value());

		if (imageTrackerResult != nullptr)
		{
			for (auto && targetInstance : imageTrackerResult->targetInstances())
			{
				auto status = targetInstance->status();
				auto target = targetInstance->target();
				if (!target.has_value()) { continue; }
				auto imageTarget = std::static_pointer_cast<easyar::ImageTarget>(target.value());
				if (imageTarget == nullptr) { continue; }
				if (status == easyar::TargetStatus::Tracked && iFrame->trackingStatus() != easyar::MotionTrackingStatus::NotTracking)
				{
					if (TrackTargets.count(imageTarget->runtimeID()) == 0)
					{
						TrackTargets[imageTarget->runtimeID()] = imageTarget;
					}
					lostCandidates.erase(imageTarget->runtimeID());
					targetPose = targetInstance->pose();
					
					cameraWorldTransform = RealTimeWorldTransform->getPoseInMap(iFrame->timestamp(), iFrame->trackingStatus(), cameraLocalTransform);
					RealTimeWorldTransform->insertData(iFrame->timestamp(), cameraLocalTransform, cameraWorldTransform);
				}
			}
		}
	}

	for (auto p : lostCandidates)
	{
		auto imageTarget = std::get<1>(p);
		if (TrackTargets.count(imageTarget->runtimeID()) > 0)
		{
			TrackTargets.erase(imageTarget->runtimeID());
		}
	}
}

void ImageTrackerMotionFusionWrapper::loadFromImage(const std::string& filename, const std::string& name, const float scale)
{
	// Scale是图片宽度和米的比例，也就是多少米，UE的单位是厘米
	std::optional<std::shared_ptr<easyar::ImageTarget>> ImageTarget =
		easyar::ImageTarget::createFromImageFile(filename, easyar::StorageType::Assets, name, "", "", scale);
	if (ImageTarget.has_value())
	{
		Tracker->loadTarget(ImageTarget.value(), Scheduler, [](std::shared_ptr<easyar::Target> target, bool status)
		{
			GEngine->AddOnScreenDebugMessage(
				0, 1.0f, FColor::Red,
				FString::Printf(TEXT("Load Target (%d): %s %d\n"), status, *FString(target->name().c_str()), target->runtimeID()));
		});
	}
}