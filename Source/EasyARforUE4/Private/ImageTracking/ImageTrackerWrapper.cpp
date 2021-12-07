#include "ImageTracking/ImageTrackerWrapper.h"

void ImageTrackerWrapper::loadFromImage(const std::string& filename)
{
	std::optional<std::shared_ptr<easyar::ImageTarget>> ImageTarget =
		easyar::ImageTarget::createFromImageFile(filename, easyar::StorageType::Assets, "", "", "", 1.0f);
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

ImageTrackerWrapper::ImageTrackerWrapper()
{
	
}

ImageTrackerWrapper::~ImageTrackerWrapper()
{
}

void ImageTrackerWrapper::initialize()
{
	auto result = easyar::Engine::initialize("Oqem9z60vusm0v4VRd5EgDt1WoJciQWu7naOjAqVkNw+hZbBCoiBjEXEhMcKlZrAGJKUwU3WxJ4/jpraEoecwlGFmsNdytfDHpWByw2tkNc2gteUTsrXwhaFkMAMg4aMRb2OjB2Tm8oTg7zKDMTP9SLK19gelJzPEZKGjEW9180Qi5jbEY+B11272YwPipTaGYmHwwzEz/VdkZzAG4mC3V3K18MehdfzU8SYwRuTmcsMxM/1XZWQwAyD2+cSh5LLK5SUzRSPm8ldytfdGoiGy1GlmcEKgqfLHImSwBaSnMERxNmMDIOb3RrIp8sciYfKFoiSjFPEhssRlZCAMISfyxySodwehZ7HEYHXgl2VkMAMg9v9CpSTzxyDodwehZ7HEYHXgl2VkMAMg9v9D4eH3Rq1hc8Lj5TCMoeFjFPEhssRlZCAMomBxxCIodwehZ7HEYHXgl2VkMAMg9vqGoiGyyyWlNoWh5njHpbXgl2VkMAMg9vtPqKh3B6FnscRgdfzU8SQ1g+Ph8srj5jLLJKUww/Ez8AKipmCXY+G4hCFlMJd3JPPE5WQ01Od18wKiJHCGq+R3V3crowLg4baXbvZjAmHh8ceiIHdXdyujByJmMMKiJzaBsSogl2Wmc8LgJrcEpXXlCTElMAblJrHG8Sogl2LmsoKipDdXdyujAyDm90ayLzDHoGQ+g2HlsUWiJKMU8SGyxGVkIA8iprbG7SQzRCBm8cLj5rAXcrX3RqIhstRtJDNEJSRxxGB14JdlZDADIPb4R2MkM0LsofPHI2cwBjE2YwMg5vdGsim2w2AlM0asofPHI2cwBjE2YwMg5vdGsim3h6UhssslpTaFoeZ4x6W14JdlZDADIPb4xCSnMERsofPHI2cwBjE2YwMg5vdGsixyxGVkP0Ph4HHHoq4zw/E2YwMg5vdGsi27zuyh88cjZzAGMSogl2Djd4WlJD6FouQ/QuHmN5d3JvbE4rZjBaVucEch5mMRYCUwgyDiIIExJfbEYKZyzaChoxFvdfaGpWBjCLK19gelJzPEZKGjEW9180Qi5jbEY+B11272YwPipTaGYmHwwzEz/Vdj5rdXbvZjBKJkdsTg4aMRb3X3RqIhstRr5jPGIOh3B6FnscRgdeCXZWQwAyD2+0TiYDKLYOWwRiInNoWiZuMU8SGyxGVkIAtg5bBDYKcwBjE2YwMg5vdGsi6zBWDltorlJTNFI+byV3K190aiIbLUbWA3BmHlssrlJTNFI+byV3K190aiIbLUbWFzw2VkP0Ph4HHHoq4zw/E2YwMg5vdGsi4wQuPmsArlJTNFI+byV3K190aiIbLUaKQwAyDpt4ekpzPE6uU3l3K190aiIbLUaW06iuUlM0Uj5vJXbvZjBqehccNg6HHEoOm2h6LhYxFiIDCE8rXxwyqms0eiteUGYeZ3RqbqNPkifL/A3jDrfjSEL+JCC0s+s+cqzonumZjSno2BizcGuh/EXad/+GH6xUX1n078anaclBHyP0z+MYP3G5vpUk0qW9PThrhh21jE+ZTgr5B9thxmlTTmYpolurMFK9sSxojQxcsa8SI/ax7E8K9cNlPTD7qnQRrVubR7Yn96sT+J/OFB1SErTvcDs54NYTvehzIGxYKgGKQRnYTr7YkmMNSI4heI1ELPylm5blYjq5YtxAfIgQF8ZoUyLTf1PS2/jaocdZZy07iBLd9EilvdSaYycexTzvp6SI2sGKdpBCmnosIs3nIV2AfaTKhx1OM9R3NfmVS0vDZICgZa59/5vWu");
	if (!result) {
		UE_LOG(LogTemp, Warning, TEXT("Initialization failed.\n"));
	}
	if (!easyar::CameraDevice::isAvailable()) {
		UE_LOG(LogTemp, Warning, TEXT("CameraDevice not available.\n"));
	}
	if (!easyar::ImageTracker::isAvailable()) {
		UE_LOG(LogTemp, Warning, TEXT("ImageTracker not available.\n"));
	}

	Scheduler = std::make_shared<easyar::DelayedCallbackScheduler>();
	Throttler = easyar::InputFrameThrottler::create();
	I2FrameAdapter = easyar::InputFrameToFeedbackFrameAdapter::create();
	OutputFrameFork = easyar::OutputFrameFork::create(2);
	OutputFrameBuffer = easyar::OutputFrameBuffer::create();
	
	Camera = easyar::CameraDeviceSelector::createCameraDevice(easyar::CameraDevicePreference::PreferObjectSensing);
	if (!Camera->openWithPreferredType(easyar::CameraDeviceType::Back))
	{
		return;
	}
	Camera->setFocusMode(easyar::CameraDeviceFocusMode::Continousauto);
	Camera->setSize(easyar::Vec2I{{1280, 960}});
	Camera->setBufferCapacity(10);
	Camera->setStateChangedCallback(Scheduler, [](easyar::CameraState s)
	{
		if (s == easyar::CameraState::Disconnected)
		{
			GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Red, TEXT("Camera Disconnected"));
		}
		else if (s == easyar::CameraState::Preempted)
		{
			GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Red, TEXT("Camera preempted"));
		}
	});
	
	Tracker = easyar::ImageTracker::create();
	
	Camera->inputFrameSource()->connect(Throttler->input());
	Throttler->output()->connect(I2FrameAdapter->input());
	I2FrameAdapter->output()->connect(Tracker->feedbackFrameSink());
	Tracker->outputFrameSource()->connect(OutputFrameFork->input());
	OutputFrameFork->output(0)->connect(OutputFrameBuffer->input());
	
	OutputFrameBuffer->signalOutput()->connect(Throttler->signalInput());
	OutputFrameFork->output(1)->connect(I2FrameAdapter->sideInput());
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
	std::shared_ptr<easyar::OutputFrame> frame = oFrame.value();
	std::unordered_map<int, std::shared_ptr<easyar::ImageTarget>> lostCandidates = TrackTargets;
	for (auto && result : frame->results())
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


