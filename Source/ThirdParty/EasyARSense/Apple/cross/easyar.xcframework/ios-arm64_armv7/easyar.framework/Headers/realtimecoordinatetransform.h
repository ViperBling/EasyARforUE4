//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_REALTIMECOORDINATETRANSFORM_H__
#define __EASYAR_REALTIMECOORDINATETRANSFORM_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Create RealTimeCoordinateTransform object.
/// </summary>
void easyar_RealTimeCoordinateTransform__ctor(/* OUT */ easyar_RealTimeCoordinateTransform * * Return);
/// <summary>
/// Set buffer size，the unit of capacity is seconds. The data within capacity seconds from now will be saved.
/// BufferSize represents the capacity of the buffer. If there is more than capacity seconds of data in the buffer, the latest data will be input to the buffer and the oldest frame of data will be released.
/// </summary>
void easyar_RealTimeCoordinateTransform_setBufferSize(easyar_RealTimeCoordinateTransform * This, int capacity);
/// <summary>
/// Get buffer capacity. The default is 15 seconds. The data within 15 seconds from now will be saved.
/// </summary>
int easyar_RealTimeCoordinateTransform_getBufferSize(const easyar_RealTimeCoordinateTransform * This);
/// <summary>
/// Input data to the cache, the data includes localTwc and mapTcw at the time timestamp. localTwc means camera pose at local coordinates, mapTcw means the camera pose at the localized map coordinates.
/// </summary>
bool easyar_RealTimeCoordinateTransform_insertData(easyar_RealTimeCoordinateTransform * This, double timestamp, easyar_Matrix44F localTwc, easyar_Matrix44F mapTcw);
/// <summary>
/// Returns the camera pose in the localized map after insert motionTracking status and localTwc at the time timestamp. localTwc means camera pose at local coordinates.
/// </summary>
easyar_Matrix44F easyar_RealTimeCoordinateTransform_getPoseInMap(easyar_RealTimeCoordinateTransform * This, double timestamp, easyar_MotionTrackingStatus status, easyar_Matrix44F localTwc);
void easyar_RealTimeCoordinateTransform__dtor(easyar_RealTimeCoordinateTransform * This);
void easyar_RealTimeCoordinateTransform__retain(const easyar_RealTimeCoordinateTransform * This, /* OUT */ easyar_RealTimeCoordinateTransform * * Return);
const char * easyar_RealTimeCoordinateTransform__typeName(const easyar_RealTimeCoordinateTransform * This);

#ifdef __cplusplus
}
#endif

#endif
