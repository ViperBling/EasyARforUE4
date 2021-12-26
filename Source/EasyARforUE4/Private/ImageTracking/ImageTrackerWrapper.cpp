#include "ImageTracking/ImageTrackerWrapper.h"

ImageTrackerWrapper::ImageTrackerWrapper()
{
	cameraWidth = 672;
	cameraHeight = 1280;
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
	Camera = easyar::CameraDeviceSelector::createCameraDevice(easyar::CameraDevicePreference::PreferObjectSensing);
	// Camera->setAndroidCameraApiType(easyar::AndroidCameraApiType::Camera1);

	// Camera->setCameraParameters(CameraParameters);
	
	if (!Camera->openWithPreferredType(easyar::CameraDeviceType::Back))
	{

		UE_LOG(LogTemp, Warning, TEXT("Camera Open Failed"));
		// return;
	}

	Camera->setFocusMode(easyar::CameraDeviceFocusMode::Continousauto);
	Camera->setSize(easyar::Vec2I{{1280, 960}});
	// Camera->cameraParameters()->imageHorizontalFlip(false);
	Camera->cameraParameters()->imageOrientation(90);
	
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
						GEngine->AddOnScreenDebugMessage(
							0, 1.0f, FColor::Green,
							FString::Printf(TEXT("Found Target (%s): %d\n"), *FString(imageTarget->name().c_str()), imageTarget->runtimeID()));
					}

					lostCandidates.erase(imageTarget->runtimeID());

					auto pose = targetInstance->pose();
					GEngine->AddOnScreenDebugMessage(
							0, 1.0f, FColor::Green,
							FString::Printf(TEXT("Target: %s (%d)\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n\n"),
							*FString(imageTarget->name().c_str()), imageTarget->runtimeID(),
							pose.data[0], pose.data[1], pose.data[2], pose.data[3],
							pose.data[4], pose.data[5], pose.data[6], pose.data[7],
							pose.data[8], pose.data[9], pose.data[10], pose.data[11],
							pose.data[12], pose.data[13], pose.data[14], pose.data[15])
							);
					UE_LOG(LogTemp, Warning, TEXT("Target: %s (%d)\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n %f %f %f %f\n\n"),
						*FString(imageTarget->name().c_str()), imageTarget->runtimeID(),
						pose.data[0], pose.data[1], pose.data[2], pose.data[3],
						pose.data[4], pose.data[5], pose.data[6], pose.data[7],
						pose.data[8], pose.data[9], pose.data[10], pose.data[11],
						pose.data[12], pose.data[13], pose.data[14], pose.data[15])
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
			UE_LOG(LogTemp, Warning, TEXT("Lost Target: %s (%d)\n\n"),
						*FString(imageTarget->name().c_str()), imageTarget->runtimeID());
		}
	}
}

void ImageTrackerWrapper::loadFromImage(const std::string& filename, const std::string& name)
{
	std::optional<std::shared_ptr<easyar::ImageTarget>> ImageTarget =
		easyar::ImageTarget::createFromImageFile(filename, easyar::StorageType::Assets, name, "", "", 1.0f);
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
