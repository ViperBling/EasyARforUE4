//=============================================================================================================================
//
// EasyAR Sense 4.3.0.8981-4ecf7d1ec
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_ACCELEROMETER_HXX__
#define __EASYAR_ACCELEROMETER_HXX__

#include "easyar/types.hxx"

namespace easyar {

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
struct AccelerometerResult
{
    float x;
    float y;
    float z;
    double timestamp;

    AccelerometerResult();
    AccelerometerResult(float x, float y, float z, double timestamp);
    easyar_AccelerometerResult get_cdata();
};

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_ACCELEROMETER_HXX__
#define __IMPLEMENTATION_EASYAR_ACCELEROMETER_HXX__

namespace easyar {

inline AccelerometerResult::AccelerometerResult()
{
    this->x = float();
    this->y = float();
    this->z = float();
    this->timestamp = double();
}
inline AccelerometerResult::AccelerometerResult(float x, float y, float z, double timestamp)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->timestamp = timestamp;
}
inline easyar_AccelerometerResult AccelerometerResult::get_cdata()
{
    easyar_AccelerometerResult _return_value_ = {x, y, z, timestamp};
    return _return_value_;
}
}

#endif
