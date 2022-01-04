//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_REALTIMECOORDINATETRANSFORM_HXX__
#define __EASYAR_REALTIMECOORDINATETRANSFORM_HXX__

#include "easyar/types.hxx"

namespace easyar {

class RealTimeCoordinateTransform
{
protected:
    easyar_RealTimeCoordinateTransform * cdata_ ;
    void init_cdata(easyar_RealTimeCoordinateTransform * cdata);
    virtual RealTimeCoordinateTransform & operator=(const RealTimeCoordinateTransform & data) { return *this; } //deleted
public:
    RealTimeCoordinateTransform(easyar_RealTimeCoordinateTransform * cdata);
    virtual ~RealTimeCoordinateTransform();

    RealTimeCoordinateTransform(const RealTimeCoordinateTransform & data);
    const easyar_RealTimeCoordinateTransform * get_cdata() const;
    easyar_RealTimeCoordinateTransform * get_cdata();

    /// <summary>
    /// Create RealTimeCoordinateTransform object.
    /// </summary>
    RealTimeCoordinateTransform();
    /// <summary>
    /// Set buffer size，the unit of capacity is seconds. The data within capacity seconds from now will be saved.
    /// BufferSize represents the capacity of the buffer. If there is more than capacity seconds of data in the buffer, the latest data will be input to the buffer and the oldest frame of data will be released.
    /// </summary>
    void setBufferSize(int capacity);
    /// <summary>
    /// Get buffer capacity. The default is 15 seconds. The data within 15 seconds from now will be saved.
    /// </summary>
    int getBufferSize();
    /// <summary>
    /// Input data to the cache, the data includes localTwc and mapTcw at the time timestamp. localTwc means camera pose at local coordinates, mapTcw means the camera pose at the localized map coordinates.
    /// </summary>
    bool insertData(double timestamp, Matrix44F localTwc, Matrix44F mapTcw);
    /// <summary>
    /// Returns the camera pose in the localized map after insert motionTracking status and localTwc at the time timestamp. localTwc means camera pose at local coordinates.
    /// </summary>
    Matrix44F getPoseInMap(double timestamp, MotionTrackingStatus status, Matrix44F localTwc);
};

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_REALTIMECOORDINATETRANSFORM_HXX__
#define __IMPLEMENTATION_EASYAR_REALTIMECOORDINATETRANSFORM_HXX__

#include "easyar/realtimecoordinatetransform.h"
#include "easyar/matrix.hxx"

namespace easyar {

inline RealTimeCoordinateTransform::RealTimeCoordinateTransform(easyar_RealTimeCoordinateTransform * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline RealTimeCoordinateTransform::~RealTimeCoordinateTransform()
{
    if (cdata_) {
        easyar_RealTimeCoordinateTransform__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline RealTimeCoordinateTransform::RealTimeCoordinateTransform(const RealTimeCoordinateTransform & data)
    :
    cdata_(NULL)
{
    easyar_RealTimeCoordinateTransform * cdata = NULL;
    easyar_RealTimeCoordinateTransform__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_RealTimeCoordinateTransform * RealTimeCoordinateTransform::get_cdata() const
{
    return cdata_;
}
inline easyar_RealTimeCoordinateTransform * RealTimeCoordinateTransform::get_cdata()
{
    return cdata_;
}
inline void RealTimeCoordinateTransform::init_cdata(easyar_RealTimeCoordinateTransform * cdata)
{
    cdata_ = cdata;
}
inline RealTimeCoordinateTransform::RealTimeCoordinateTransform()
    :
    cdata_(NULL)
{
    easyar_RealTimeCoordinateTransform * _return_value_ = NULL;
    easyar_RealTimeCoordinateTransform__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline void RealTimeCoordinateTransform::setBufferSize(int arg0)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_RealTimeCoordinateTransform_setBufferSize(cdata_, arg0);
}
inline int RealTimeCoordinateTransform::getBufferSize()
{
    if (cdata_ == NULL) {
        return int();
    }
    int _return_value_ = easyar_RealTimeCoordinateTransform_getBufferSize(cdata_);
    return _return_value_;
}
inline bool RealTimeCoordinateTransform::insertData(double arg0, Matrix44F arg1, Matrix44F arg2)
{
    if (cdata_ == NULL) {
        return bool();
    }
    bool _return_value_ = easyar_RealTimeCoordinateTransform_insertData(cdata_, arg0, arg1.get_cdata(), arg2.get_cdata());
    return _return_value_;
}
inline Matrix44F RealTimeCoordinateTransform::getPoseInMap(double arg0, MotionTrackingStatus arg1, Matrix44F arg2)
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_RealTimeCoordinateTransform_getPoseInMap(cdata_, arg0, static_cast<easyar_MotionTrackingStatus>(arg1), arg2.get_cdata());
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}

}

#endif
