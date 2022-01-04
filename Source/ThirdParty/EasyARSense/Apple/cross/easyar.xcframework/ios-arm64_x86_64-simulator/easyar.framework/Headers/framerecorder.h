//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_FRAMERECORDER_H__
#define __EASYAR_FRAMERECORDER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Input port.
/// </summary>
void easyar_InputFrameRecorder_input(easyar_InputFrameRecorder * This, /* OUT */ easyar_InputFrameSink * * Return);
/// <summary>
/// Camera buffers occupied in this component.
/// </summary>
int easyar_InputFrameRecorder_bufferRequirement(easyar_InputFrameRecorder * This);
/// <summary>
/// Output port.
/// </summary>
void easyar_InputFrameRecorder_output(easyar_InputFrameRecorder * This, /* OUT */ easyar_InputFrameSource * * Return);
/// <summary>
/// Creates an instance.
/// </summary>
void easyar_InputFrameRecorder_create(/* OUT */ easyar_InputFrameRecorder * * Return);
/// <summary>
/// Starts frame recording. initialScreenRotation is the initial screen rotation when recording data, and it will be used in rendering for playback. The definition of screen rotation is the same as in `CameraParameters`_ .
/// </summary>
bool easyar_InputFrameRecorder_start(easyar_InputFrameRecorder * This, easyar_String * filePath, int initialScreenRotation);
/// <summary>
/// Stops frame recording. It will only stop recording and will not affect connection.
/// </summary>
void easyar_InputFrameRecorder_stop(easyar_InputFrameRecorder * This);
void easyar_InputFrameRecorder__dtor(easyar_InputFrameRecorder * This);
void easyar_InputFrameRecorder__retain(const easyar_InputFrameRecorder * This, /* OUT */ easyar_InputFrameRecorder * * Return);
const char * easyar_InputFrameRecorder__typeName(const easyar_InputFrameRecorder * This);

/// <summary>
/// Output port.
/// </summary>
void easyar_InputFramePlayer_output(easyar_InputFramePlayer * This, /* OUT */ easyar_InputFrameSource * * Return);
/// <summary>
/// Creates an instance.
/// </summary>
void easyar_InputFramePlayer_create(/* OUT */ easyar_InputFramePlayer * * Return);
/// <summary>
/// Starts frame play.
/// </summary>
bool easyar_InputFramePlayer_start(easyar_InputFramePlayer * This, easyar_String * filePath);
/// <summary>
/// Stops frame play.
/// </summary>
void easyar_InputFramePlayer_stop(easyar_InputFramePlayer * This);
/// <summary>
/// Pauses frame play.
/// </summary>
void easyar_InputFramePlayer_pause(easyar_InputFramePlayer * This);
/// <summary>
/// Resumes frame play.
/// </summary>
bool easyar_InputFramePlayer_resume(easyar_InputFramePlayer * This);
/// <summary>
/// Total expected playback time span. The unit is second.
/// </summary>
double easyar_InputFramePlayer_totalTime(easyar_InputFramePlayer * This);
/// <summary>
/// Current playback time point. The unit is second. The initial value is 0.
/// </summary>
double easyar_InputFramePlayer_currentTime(easyar_InputFramePlayer * This);
/// <summary>
/// The initial screen rotation when recording data.
/// </summary>
int easyar_InputFramePlayer_initalScreenRotation(easyar_InputFramePlayer * This);
/// <summary>
/// Whether the playback is completed.
/// </summary>
bool easyar_InputFramePlayer_isCompleted(easyar_InputFramePlayer * This);
void easyar_InputFramePlayer__dtor(easyar_InputFramePlayer * This);
void easyar_InputFramePlayer__retain(const easyar_InputFramePlayer * This, /* OUT */ easyar_InputFramePlayer * * Return);
const char * easyar_InputFramePlayer__typeName(const easyar_InputFramePlayer * This);

#ifdef __cplusplus
}
#endif

#endif
