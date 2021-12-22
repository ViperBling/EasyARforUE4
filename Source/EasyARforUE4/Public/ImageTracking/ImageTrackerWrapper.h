#pragma once

#include "easyar/types.hpp"
#include <unordered_map>

class ImageTrackerWrapper
{
public:
	ImageTrackerWrapper();
	virtual ~ImageTrackerWrapper();
	
	void initialize();
	bool start();
	void stop();
	void perFrame();
	void loadFromImage(const std::string& filename, const std::string& name);

	std::shared_ptr<easyar::OutputFrame> cameraFrame;

	int cameraWidth;
	int cameraHeight;

private:
	std::shared_ptr<easyar::DelayedCallbackScheduler> Scheduler;
	std::shared_ptr<easyar::CameraDevice> Camera;
	std::shared_ptr<easyar::CameraParameters> CameraParameters;
	std::shared_ptr<easyar::ImageTracker> Tracker;
	std::shared_ptr<easyar::InputFrameThrottler> Throttler;
	std::shared_ptr<easyar::OutputFrameFork> OutputFrameFork;
	std::shared_ptr<easyar::OutputFrameBuffer> OutputFrameBuffer;
	std::shared_ptr<easyar::InputFrameToFeedbackFrameAdapter> I2FrameAdapter;
	std::unordered_map<int, std::shared_ptr<easyar::ImageTarget>> TrackTargets;
};
