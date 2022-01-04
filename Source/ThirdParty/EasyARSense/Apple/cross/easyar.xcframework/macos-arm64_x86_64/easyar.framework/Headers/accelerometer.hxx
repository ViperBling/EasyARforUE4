//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
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

/// <summary>
/// Accelerometer calls the accelerometer provided by the operating system, and outputs `AccelerometerResult`_ .
/// When it is not needed anymore, call close function to close it. It shall not be used after calling close.
/// It is not recommended to open the accelerometer multiple times simultaneously, which may cause failure on open or cause precision downgrade.
/// </summary>
class Accelerometer
{
protected:
    easyar_Accelerometer * cdata_ ;
    void init_cdata(easyar_Accelerometer * cdata);
    virtual Accelerometer & operator=(const Accelerometer & data) { return *this; } //deleted
public:
    Accelerometer(easyar_Accelerometer * cdata);
    virtual ~Accelerometer();

    Accelerometer(const Accelerometer & data);
    const easyar_Accelerometer * get_cdata() const;
    easyar_Accelerometer * get_cdata();

    Accelerometer();
    /// <summary>
    /// Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
    /// </summary>
    bool isAvailable();
    /// <summary>
    /// Opens the device. Sampling period is defined by implementation. If failed, it will return false.
    /// </summary>
    bool open();
    /// <summary>
    /// Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
    /// </summary>
    bool openWithSamplingPeriod(int samplingPeriodMilliseconds);
    /// <summary>
    /// Closes. It shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Gets the most recent result. If there is no result, it returns empty.
    /// </summary>
    OptionalOfAccelerometerResult getCurrentResult();
};

#ifndef __EASYAR_OPTIONALOFACCELEROMETERRESULT__
#define __EASYAR_OPTIONALOFACCELEROMETERRESULT__
struct OptionalOfAccelerometerResult
{
    bool has_value;
    AccelerometerResult value;
};
static inline easyar_OptionalOfAccelerometerResult OptionalOfAccelerometerResult_to_c(OptionalOfAccelerometerResult o);
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_ACCELEROMETER_HXX__
#define __IMPLEMENTATION_EASYAR_ACCELEROMETER_HXX__

#include "easyar/accelerometer.h"

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
inline Accelerometer::Accelerometer(easyar_Accelerometer * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline Accelerometer::~Accelerometer()
{
    if (cdata_) {
        easyar_Accelerometer__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline Accelerometer::Accelerometer(const Accelerometer & data)
    :
    cdata_(NULL)
{
    easyar_Accelerometer * cdata = NULL;
    easyar_Accelerometer__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_Accelerometer * Accelerometer::get_cdata() const
{
    return cdata_;
}
inline easyar_Accelerometer * Accelerometer::get_cdata()
{
    return cdata_;
}
inline void Accelerometer::init_cdata(easyar_Accelerometer * cdata)
{
    cdata_ = cdata;
}
inline Accelerometer::Accelerometer()
    :
    cdata_(NULL)
{
    easyar_Accelerometer * _return_value_ = NULL;
    easyar_Accelerometer__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline bool Accelerometer::isAvailable()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_Accelerometer_isAvailable(cdata_);
    return _return_value_;
}
inline bool Accelerometer::open()
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_Accelerometer_open(cdata_);
    return _return_value_;
}
inline bool Accelerometer::openWithSamplingPeriod(int arg0)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_Accelerometer_openWithSamplingPeriod(cdata_, arg0);
    return _return_value_;
}
inline void Accelerometer::close()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_Accelerometer_close(cdata_);
}
inline OptionalOfAccelerometerResult Accelerometer::getCurrentResult()
{
    if (cdata_ == NULL) {
        return {false, AccelerometerResult()};
    }
    easyar_OptionalOfAccelerometerResult _return_value_ = easyar_Accelerometer_getCurrentResult(cdata_);
    return (_return_value_.has_value ? OptionalOfAccelerometerResult{true, AccelerometerResult(_return_value_.value.x, _return_value_.value.y, _return_value_.value.z, _return_value_.value.timestamp)} : OptionalOfAccelerometerResult{false, {}});
}

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFACCELEROMETERRESULT__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFACCELEROMETERRESULT__
static inline easyar_OptionalOfAccelerometerResult OptionalOfAccelerometerResult_to_c(OptionalOfAccelerometerResult o)
{
    if (o.has_value) {
        easyar_OptionalOfAccelerometerResult _return_value_ = {true, o.value.get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfAccelerometerResult _return_value_ = {false, easyar_AccelerometerResult()};
        return _return_value_;
    }
}
#endif

}

#endif
