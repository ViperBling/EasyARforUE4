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
	void loadFromImage(const std::string& filename, const std::string& name, const float scale);
	//void loadTarget(std::optional<std::shared_ptr<easyar::ImageTarget>> Target, const std::string& filename, const std::string& name);

	std::shared_ptr<easyar::OutputFrame> cameraFrame;
	std::unordered_map<int, std::shared_ptr<easyar::ImageTarget>> TrackTargets;
	easyar::Matrix44F targetPose;

private:
	std::shared_ptr<easyar::DelayedCallbackScheduler> Scheduler;
	std::shared_ptr<easyar::CameraDevice> Camera;
	std::shared_ptr<easyar::RealTimeCoordinateTransform> RealTimeCoordinateTransform;
	// std::shared_ptr<easyar::CameraParameters> CameraParameters;
	std::shared_ptr<easyar::ImageTracker> Tracker;
	std::shared_ptr<easyar::InputFrameThrottler> Throttler;
	std::shared_ptr<easyar::OutputFrameFork> OutputFrameFork;
	std::shared_ptr<easyar::OutputFrameBuffer> OutputFrameBuffer;
	std::shared_ptr<easyar::InputFrameToFeedbackFrameAdapter> I2FrameAdapter;
};

class MotionTrakerWrapper
{
public:
	MotionTrakerWrapper();
	virtual ~MotionTrakerWrapper();

	void initialize();
	bool start();
	void stop();
	void render();

	std::shared_ptr<easyar::OutputFrame> cameraFrame;
	easyar::Matrix44F cameraTransform;
	
private:
	std::shared_ptr<easyar::DelayedCallbackScheduler> Scheduler;
	std::shared_ptr<easyar::MotionTrackerCameraDevice> MotionTrackerCamera;
	std::shared_ptr<easyar::OutputFrameBuffer> OutputFrameBuffer;
	std::shared_ptr<easyar::InputFrameToOutputFrameAdapter> I2FrameAdapter;
};

class ImageTrackerMotionFusionWrapper
{
public:
	ImageTrackerMotionFusionWrapper();
	virtual ~ImageTrackerMotionFusionWrapper();

	void initialize();
	bool start();
	void stop();
	void render();
	void loadFromImage(const std::string& filename, const std::string& name, const float scale);

	std::shared_ptr<easyar::OutputFrame> cameraFrame;
	std::unordered_map<int, std::shared_ptr<easyar::ImageTarget>> TrackTargets;
	easyar::Matrix44F targetPose;
	easyar::Matrix44F cameraLocalTransform;
	easyar::Matrix44F cameraWorldTransform;

private:
	std::shared_ptr<easyar::DelayedCallbackScheduler> Scheduler;
	std::shared_ptr<easyar::MotionTrackerCameraDevice> MotionTrackerCamera;
	std::shared_ptr<easyar::ImageTracker> Tracker;
	std::shared_ptr<easyar::RealTimeCoordinateTransform> RealTimeWorldTransform;
	std::shared_ptr<easyar::InputFrameThrottler> Throttler;
	std::shared_ptr<easyar::OutputFrameFork> OutputFrameFork;
	std::shared_ptr<easyar::OutputFrameBuffer> OutputFrameBuffer;
	std::shared_ptr<easyar::InputFrameToFeedbackFrameAdapter> I2FrameAdapter;
};