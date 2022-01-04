//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

/// <summary>
/// record
/// Accelerometer reading.
///
/// The positive direction of x-axis is from the device center to its right side of the screen.
/// The positive direction of y-axis is from the device center to its top side of the screen.
/// The positive direction of z-axis is from the device center perpendicular to the screen outward.
///
/// The unit of x, y, z is m/s^2.
/// The unit of timestamp is second.
/// </summary>
@interface easyar_AccelerometerResult : NSObject

@property (nonatomic) float x;
@property (nonatomic) float y;
@property (nonatomic) float z;
@property (nonatomic) double timestamp;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)create:(float)x y:(float)y z:(float)z timestamp:(double)timestamp;

@end

/// <summary>
/// Accelerometer calls the accelerometer provided by the operating system, and outputs `AccelerometerResult`_ .
/// When it is not needed anymore, call close function to close it. It shall not be used after calling close.
/// It is not recommended to open the accelerometer multiple times simultaneously, which may cause failure on open or cause precision downgrade.
/// </summary>
@interface easyar_Accelerometer : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_Accelerometer *) create;
/// <summary>
/// Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
/// </summary>
- (bool)isAvailable;
/// <summary>
/// Opens the device. Sampling period is defined by implementation. If failed, it will return false.
/// </summary>
- (bool)open;
/// <summary>
/// Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
/// </summary>
- (bool)openWithSamplingPeriod:(int)samplingPeriodMilliseconds;
/// <summary>
/// Closes. It shall not be used after calling close.
/// </summary>
- (void)close;
/// <summary>
/// Gets the most recent result. If there is no result, it returns empty.
/// </summary>
- (easyar_AccelerometerResult *)getCurrentResult;

@end
