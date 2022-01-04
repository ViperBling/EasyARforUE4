//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_ACCELEROMETER_H__
#define __EASYAR_ACCELEROMETER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_Accelerometer__ctor(/* OUT */ easyar_Accelerometer * * Return);
/// <summary>
/// Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
/// </summary>
bool easyar_Accelerometer_isAvailable(easyar_Accelerometer * This);
/// <summary>
/// Opens the device. Sampling period is defined by implementation. If failed, it will return false.
/// </summary>
bool easyar_Accelerometer_open(easyar_Accelerometer * This);
/// <summary>
/// Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
/// </summary>
bool easyar_Accelerometer_openWithSamplingPeriod(easyar_Accelerometer * This, int samplingPeriodMilliseconds);
/// <summary>
/// Closes. It shall not be used after calling close.
/// </summary>
void easyar_Accelerometer_close(easyar_Accelerometer * This);
/// <summary>
/// Gets the most recent result. If there is no result, it returns empty.
/// </summary>
easyar_OptionalOfAccelerometerResult easyar_Accelerometer_getCurrentResult(easyar_Accelerometer * This);
void easyar_Accelerometer__dtor(easyar_Accelerometer * This);
void easyar_Accelerometer__retain(const easyar_Accelerometer * This, /* OUT */ easyar_Accelerometer * * Return);
const char * easyar_Accelerometer__typeName(const easyar_Accelerometer * This);

#ifdef __cplusplus
}
#endif

#endif
