//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_RealTimeCoordinateTransform : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Create RealTimeCoordinateTransform object.
/// </summary>
+ (easyar_RealTimeCoordinateTransform *) create;
/// <summary>
/// Set buffer size，the unit of capacity is seconds. The data within capacity seconds from now will be saved.
/// BufferSize represents the capacity of the buffer. If there is more than capacity seconds of data in the buffer, the latest data will be input to the buffer and the oldest frame of data will be released.
/// </summary>
- (void)setBufferSize:(int)capacity;
/// <summary>
/// Get buffer capacity. The default is 15 seconds. The data within 15 seconds from now will be saved.
/// </summary>
- (int)getBufferSize;
/// <summary>
/// Input data to the cache, the data includes localTwc and mapTcw at the time timestamp. localTwc means camera pose at local coordinates, mapTcw means the camera pose at the localized map coordinates.
/// </summary>
- (bool)insertData:(double)timestamp localTwc:(easyar_Matrix44F *)localTwc mapTcw:(easyar_Matrix44F *)mapTcw;
/// <summary>
/// Returns the camera pose in the localized map after insert motionTracking status and localTwc at the time timestamp. localTwc means camera pose at local coordinates.
/// </summary>
- (easyar_Matrix44F *)getPoseInMap:(double)timestamp status:(easyar_MotionTrackingStatus)status localTwc:(easyar_Matrix44F *)localTwc;

@end
