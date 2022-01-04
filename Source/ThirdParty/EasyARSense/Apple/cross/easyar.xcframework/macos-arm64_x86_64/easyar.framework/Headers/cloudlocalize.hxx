//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CLOUDLOCALIZE_HXX__
#define __EASYAR_CLOUDLOCALIZE_HXX__

#include "easyar/types.hxx"
#include "easyar/frame.hxx"

namespace easyar {

class CloudLocalizeResult : public FrameFilterResult
{
protected:
    easyar_CloudLocalizeResult * cdata_ ;
    void init_cdata(easyar_CloudLocalizeResult * cdata);
    virtual CloudLocalizeResult & operator=(const CloudLocalizeResult & data) { return *this; } //deleted
public:
    CloudLocalizeResult(easyar_CloudLocalizeResult * cdata);
    virtual ~CloudLocalizeResult();

    CloudLocalizeResult(const CloudLocalizeResult & data);
    const easyar_CloudLocalizeResult * get_cdata() const;
    easyar_CloudLocalizeResult * get_cdata();

    /// <summary>
    /// Returns localization status.
    /// </summary>
    CloudLocalizeStatus getLocalizeStatus();
    /// <summary>
    /// Returns ID of the best correspond localized map.
    /// </summary>
    void getLocalizedMapID(/* OUT */ String * * Return);
    /// <summary>
    /// Returns the name of the best correspond localized map.
    /// </summary>
    void getLocalizedMapName(/* OUT */ String * * Return);
    /// <summary>
    /// Returns the camera pose at the best correspond localized map coordinates.
    /// </summary>
    Matrix44F getPose();
    /// <summary>
    /// Returns the transform from local coordinates (if exists) to the best correspond map coordinates.
    /// </summary>
    OptionalOfMatrix44F getDeltaT();
    /// <summary>
    /// Returns ID of all localized maps.
    /// </summary>
    void getAllLocalizedMapID(/* OUT */ ListOfString * * Return);
    /// <summary>
    /// Returns the camera pose at all localized map coordinates.
    /// </summary>
    void getAllPose(/* OUT */ ListOfMatrix44F * * Return);
    /// <summary>
    /// Returns the transform from local coordinates (if exists) to all map coordinates.
    /// </summary>
    void getAllDeltaT(/* OUT */ ListOfMatrix44F * * Return);
    /// <summary>
    /// Returns extra informations of the localization.
    /// </summary>
    void getExtraInfo(/* OUT */ String * * Return);
    /// <summary>
    /// Returns detailed exception message.
    /// </summary>
    void getExceptionInfo(/* OUT */ String * * Return);
    /// <summary>
    /// Returns the block id of the best correspond localized map.
    /// </summary>
    void getLocalizedBlockId(/* OUT */ String * * Return);
    /// <summary>
    /// Returns the block timestamp of the best correspond localized map.
    /// </summary>
    void getLocalizedBlockTimestamp(/* OUT */ String * * Return);
    /// <summary>
    /// Returns the block location of the best correspond localized map.
    /// </summary>
    OptionalOfVec3D getLocalizedBlockLocation();
    /// <summary>
    /// Returns the cluster id of the best correspond localized map.
    /// </summary>
    void getLocalizedClusterId(/* OUT */ String * * Return);
    /// <summary>
    /// Returns the cluster location of the best correspond localized map.
    /// </summary>
    OptionalOfVec3D getLocalizedClusterLocation();
    /// <summary>
    /// Returns the camera pose in the cluster which the best correspond localized map belongs to.
    /// </summary>
    Matrix44F getPoseInCluster();
    /// <summary>
    /// Returns the transform from local coordinates (if exists) to the best correspond map coordinates.
    /// </summary>
    OptionalOfMatrix44F getDeltaTForCluster();
    /// <summary>
    /// Returns the location of device.
    /// </summary>
    OptionalOfVec3D getDeviceLocation();
    static void tryCastFromFrameFilterResult(FrameFilterResult * v, /* OUT */ CloudLocalizeResult * * Return);
};

/// <summary>
/// CloudLocalizer implements cloud based localization.
/// </summary>
class CloudLocalizer
{
protected:
    easyar_CloudLocalizer * cdata_ ;
    void init_cdata(easyar_CloudLocalizer * cdata);
    virtual CloudLocalizer & operator=(const CloudLocalizer & data) { return *this; } //deleted
public:
    CloudLocalizer(easyar_CloudLocalizer * cdata);
    virtual ~CloudLocalizer();

    CloudLocalizer(const CloudLocalizer & data);
    const easyar_CloudLocalizer * get_cdata() const;
    easyar_CloudLocalizer * get_cdata();

    /// <summary>
    /// Returns true.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Creates an instance and connects to the server.
    /// </summary>
    static void create(String * server, String * apiKey, String * apiSecret, String * appId, /* OUT */ CloudLocalizer * * Return);
    /// <summary>
    /// Send localization request.
    /// Send `InputFrame`_ to resolve a cloud localization. `InputFrame`_ should have at least image data and camera parameters.
    /// message input is a json string.
    /// acceleration is optional which is the readings from device accelerometer.
    /// location is optional which is the readings from device location manager.
    /// </summary>
    void resolve(InputFrame * inputFrame, String * message, OptionalOfVec3F acceleration, OptionalOfVec3D location, CallbackScheduler * callbackScheduler, FunctorOfVoidFromCloudLocalizeResult callback);
    /// <summary>
    /// Stops the localization and closes connection. The component shall not be used after calling close.
    /// </summary>
    void close();
};

#ifndef __EASYAR_OPTIONALOFMATRIX__F__
#define __EASYAR_OPTIONALOFMATRIX__F__
struct OptionalOfMatrix44F
{
    bool has_value;
    Matrix44F value;
};
static inline easyar_OptionalOfMatrix44F OptionalOfMatrix44F_to_c(OptionalOfMatrix44F o);
#endif

#ifndef __EASYAR_LISTOFSTRING__
#define __EASYAR_LISTOFSTRING__
class ListOfString
{
private:
    easyar_ListOfString * cdata_;
    virtual ListOfString & operator=(const ListOfString & data) { return *this; } //deleted
public:
    ListOfString(easyar_ListOfString * cdata);
    virtual ~ListOfString();

    ListOfString(const ListOfString & data);
    const easyar_ListOfString * get_cdata() const;
    easyar_ListOfString * get_cdata();

    ListOfString(easyar_String * * begin, easyar_String * * end);
    int size() const;
    String * at(int index) const;
};
#endif

#ifndef __EASYAR_LISTOFMATRIX__F__
#define __EASYAR_LISTOFMATRIX__F__
class ListOfMatrix44F
{
private:
    easyar_ListOfMatrix44F * cdata_;
    virtual ListOfMatrix44F & operator=(const ListOfMatrix44F & data) { return *this; } //deleted
public:
    ListOfMatrix44F(easyar_ListOfMatrix44F * cdata);
    virtual ~ListOfMatrix44F();

    ListOfMatrix44F(const ListOfMatrix44F & data);
    const easyar_ListOfMatrix44F * get_cdata() const;
    easyar_ListOfMatrix44F * get_cdata();

    ListOfMatrix44F(easyar_Matrix44F * begin, easyar_Matrix44F * end);
    int size() const;
    Matrix44F at(int index) const;
};
#endif

#ifndef __EASYAR_OPTIONALOFVEC_D__
#define __EASYAR_OPTIONALOFVEC_D__
struct OptionalOfVec3D
{
    bool has_value;
    Vec3D value;
};
static inline easyar_OptionalOfVec3D OptionalOfVec3D_to_c(OptionalOfVec3D o);
#endif

#ifndef __EASYAR_OPTIONALOFVEC_F__
#define __EASYAR_OPTIONALOFVEC_F__
struct OptionalOfVec3F
{
    bool has_value;
    Vec3F value;
};
static inline easyar_OptionalOfVec3F OptionalOfVec3F_to_c(OptionalOfVec3F o);
#endif

#ifndef __EASYAR_FUNCTOROFVOIDFROMCLOUDLOCALIZERESULT__
#define __EASYAR_FUNCTOROFVOIDFROMCLOUDLOCALIZERESULT__
struct FunctorOfVoidFromCloudLocalizeResult
{
    void * _state;
    void (* func)(void * _state, CloudLocalizeResult *);
    void (* destroy)(void * _state);
    FunctorOfVoidFromCloudLocalizeResult(void * _state, void (* func)(void * _state, CloudLocalizeResult *), void (* destroy)(void * _state));
};

static void FunctorOfVoidFromCloudLocalizeResult_func(void * _state, easyar_CloudLocalizeResult *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromCloudLocalizeResult_destroy(void * _state);
static inline easyar_FunctorOfVoidFromCloudLocalizeResult FunctorOfVoidFromCloudLocalizeResult_to_c(FunctorOfVoidFromCloudLocalizeResult f);
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_CLOUDLOCALIZE_HXX__
#define __IMPLEMENTATION_EASYAR_CLOUDLOCALIZE_HXX__

#include "easyar/cloudlocalize.h"
#include "easyar/frame.hxx"
#include "easyar/matrix.hxx"
#include "easyar/vector.hxx"
#include "easyar/image.hxx"
#include "easyar/buffer.hxx"
#include "easyar/cameraparameters.hxx"
#include "easyar/callbackscheduler.hxx"

namespace easyar {

inline CloudLocalizeResult::CloudLocalizeResult(easyar_CloudLocalizeResult * cdata)
    :
    FrameFilterResult(static_cast<easyar_FrameFilterResult *>(NULL)),
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline CloudLocalizeResult::~CloudLocalizeResult()
{
    if (cdata_) {
        easyar_CloudLocalizeResult__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline CloudLocalizeResult::CloudLocalizeResult(const CloudLocalizeResult & data)
    :
    FrameFilterResult(static_cast<easyar_FrameFilterResult *>(NULL)),
    cdata_(NULL)
{
    easyar_CloudLocalizeResult * cdata = NULL;
    easyar_CloudLocalizeResult__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_CloudLocalizeResult * CloudLocalizeResult::get_cdata() const
{
    return cdata_;
}
inline easyar_CloudLocalizeResult * CloudLocalizeResult::get_cdata()
{
    return cdata_;
}
inline void CloudLocalizeResult::init_cdata(easyar_CloudLocalizeResult * cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * cdata_inner = NULL;
        easyar_castCloudLocalizeResultToFrameFilterResult(cdata, &cdata_inner);
        FrameFilterResult::init_cdata(cdata_inner);
    }
}
inline CloudLocalizeStatus CloudLocalizeResult::getLocalizeStatus()
{
    if (cdata_ == NULL) {
        return CloudLocalizeStatus();
    }
    easyar_CloudLocalizeStatus _return_value_ = easyar_CloudLocalizeResult_getLocalizeStatus(cdata_);
    return static_cast<CloudLocalizeStatus>(_return_value_);
}
inline void CloudLocalizeResult::getLocalizedMapID(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_CloudLocalizeResult_getLocalizedMapID(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void CloudLocalizeResult::getLocalizedMapName(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_CloudLocalizeResult_getLocalizedMapName(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline Matrix44F CloudLocalizeResult::getPose()
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_CloudLocalizeResult_getPose(cdata_);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}
inline OptionalOfMatrix44F CloudLocalizeResult::getDeltaT()
{
    if (cdata_ == NULL) {
        return {false, Matrix44F()};
    }
    easyar_OptionalOfMatrix44F _return_value_ = easyar_CloudLocalizeResult_getDeltaT(cdata_);
    return (_return_value_.has_value ? OptionalOfMatrix44F{true, Matrix44F(_return_value_.value.data[0], _return_value_.value.data[1], _return_value_.value.data[2], _return_value_.value.data[3], _return_value_.value.data[4], _return_value_.value.data[5], _return_value_.value.data[6], _return_value_.value.data[7], _return_value_.value.data[8], _return_value_.value.data[9], _return_value_.value.data[10], _return_value_.value.data[11], _return_value_.value.data[12], _return_value_.value.data[13], _return_value_.value.data[14], _return_value_.value.data[15])} : OptionalOfMatrix44F{false, {}});
}
inline void CloudLocalizeResult::getAllLocalizedMapID(/* OUT */ ListOfString * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfString * _return_value_ = NULL;
    easyar_CloudLocalizeResult_getAllLocalizedMapID(cdata_, &_return_value_);
    *Return = new ListOfString(_return_value_);
}
inline void CloudLocalizeResult::getAllPose(/* OUT */ ListOfMatrix44F * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfMatrix44F * _return_value_ = NULL;
    easyar_CloudLocalizeResult_getAllPose(cdata_, &_return_value_);
    *Return = new ListOfMatrix44F(_return_value_);
}
inline void CloudLocalizeResult::getAllDeltaT(/* OUT */ ListOfMatrix44F * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_ListOfMatrix44F * _return_value_ = NULL;
    easyar_CloudLocalizeResult_getAllDeltaT(cdata_, &_return_value_);
    *Return = new ListOfMatrix44F(_return_value_);
}
inline void CloudLocalizeResult::getExtraInfo(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_CloudLocalizeResult_getExtraInfo(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void CloudLocalizeResult::getExceptionInfo(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_CloudLocalizeResult_getExceptionInfo(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void CloudLocalizeResult::getLocalizedBlockId(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_CloudLocalizeResult_getLocalizedBlockId(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline void CloudLocalizeResult::getLocalizedBlockTimestamp(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_CloudLocalizeResult_getLocalizedBlockTimestamp(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline OptionalOfVec3D CloudLocalizeResult::getLocalizedBlockLocation()
{
    if (cdata_ == NULL) {
        return {false, Vec3D()};
    }
    easyar_OptionalOfVec3D _return_value_ = easyar_CloudLocalizeResult_getLocalizedBlockLocation(cdata_);
    return (_return_value_.has_value ? OptionalOfVec3D{true, Vec3D(_return_value_.value.data[0], _return_value_.value.data[1], _return_value_.value.data[2])} : OptionalOfVec3D{false, {}});
}
inline void CloudLocalizeResult::getLocalizedClusterId(/* OUT */ String * * Return)
{
    if (cdata_ == NULL) {
        *Return = NULL;
        return;
    }
    easyar_String * _return_value_ = NULL;
    easyar_CloudLocalizeResult_getLocalizedClusterId(cdata_, &_return_value_);
    *Return = new String(_return_value_);
}
inline OptionalOfVec3D CloudLocalizeResult::getLocalizedClusterLocation()
{
    if (cdata_ == NULL) {
        return {false, Vec3D()};
    }
    easyar_OptionalOfVec3D _return_value_ = easyar_CloudLocalizeResult_getLocalizedClusterLocation(cdata_);
    return (_return_value_.has_value ? OptionalOfVec3D{true, Vec3D(_return_value_.value.data[0], _return_value_.value.data[1], _return_value_.value.data[2])} : OptionalOfVec3D{false, {}});
}
inline Matrix44F CloudLocalizeResult::getPoseInCluster()
{
    if (cdata_ == NULL) {
        return Matrix44F();
    }
    easyar_Matrix44F _return_value_ = easyar_CloudLocalizeResult_getPoseInCluster(cdata_);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}
inline OptionalOfMatrix44F CloudLocalizeResult::getDeltaTForCluster()
{
    if (cdata_ == NULL) {
        return {false, Matrix44F()};
    }
    easyar_OptionalOfMatrix44F _return_value_ = easyar_CloudLocalizeResult_getDeltaTForCluster(cdata_);
    return (_return_value_.has_value ? OptionalOfMatrix44F{true, Matrix44F(_return_value_.value.data[0], _return_value_.value.data[1], _return_value_.value.data[2], _return_value_.value.data[3], _return_value_.value.data[4], _return_value_.value.data[5], _return_value_.value.data[6], _return_value_.value.data[7], _return_value_.value.data[8], _return_value_.value.data[9], _return_value_.value.data[10], _return_value_.value.data[11], _return_value_.value.data[12], _return_value_.value.data[13], _return_value_.value.data[14], _return_value_.value.data[15])} : OptionalOfMatrix44F{false, {}});
}
inline OptionalOfVec3D CloudLocalizeResult::getDeviceLocation()
{
    if (cdata_ == NULL) {
        return {false, Vec3D()};
    }
    easyar_OptionalOfVec3D _return_value_ = easyar_CloudLocalizeResult_getDeviceLocation(cdata_);
    return (_return_value_.has_value ? OptionalOfVec3D{true, Vec3D(_return_value_.value.data[0], _return_value_.value.data[1], _return_value_.value.data[2])} : OptionalOfVec3D{false, {}});
}
inline void CloudLocalizeResult::tryCastFromFrameFilterResult(FrameFilterResult * v, /* OUT */ CloudLocalizeResult * * Return)
{
    if (v == NULL) {
        *Return = NULL;
        return;
    }
    easyar_CloudLocalizeResult * cdata = NULL;
    easyar_tryCastFrameFilterResultToCloudLocalizeResult(v->get_cdata(), &cdata);
    if (cdata == NULL) {
        *Return = NULL;
        return;
    }
    *Return = new CloudLocalizeResult(cdata);
}

inline CloudLocalizer::CloudLocalizer(easyar_CloudLocalizer * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline CloudLocalizer::~CloudLocalizer()
{
    if (cdata_) {
        easyar_CloudLocalizer__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline CloudLocalizer::CloudLocalizer(const CloudLocalizer & data)
    :
    cdata_(NULL)
{
    easyar_CloudLocalizer * cdata = NULL;
    easyar_CloudLocalizer__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_CloudLocalizer * CloudLocalizer::get_cdata() const
{
    return cdata_;
}
inline easyar_CloudLocalizer * CloudLocalizer::get_cdata()
{
    return cdata_;
}
inline void CloudLocalizer::init_cdata(easyar_CloudLocalizer * cdata)
{
    cdata_ = cdata;
}
inline bool CloudLocalizer::isAvailable()
{
    bool _return_value_ = easyar_CloudLocalizer_isAvailable();
    return _return_value_;
}
inline void CloudLocalizer::create(String * arg0, String * arg1, String * arg2, String * arg3, /* OUT */ CloudLocalizer * * Return)
{
    easyar_CloudLocalizer * _return_value_ = NULL;
    easyar_CloudLocalizer_create(arg0->get_cdata(), arg1->get_cdata(), arg2->get_cdata(), arg3->get_cdata(), &_return_value_);
    *Return = new CloudLocalizer(_return_value_);
}
inline void CloudLocalizer::resolve(InputFrame * arg0, String * arg1, OptionalOfVec3F arg2, OptionalOfVec3D arg3, CallbackScheduler * arg4, FunctorOfVoidFromCloudLocalizeResult arg5)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CloudLocalizer_resolve(cdata_, arg0->get_cdata(), arg1->get_cdata(), OptionalOfVec3F_to_c(arg2), OptionalOfVec3D_to_c(arg3), arg4->get_cdata(), FunctorOfVoidFromCloudLocalizeResult_to_c(arg5));
}
inline void CloudLocalizer::close()
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CloudLocalizer_close(cdata_);
}

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFMATRIX__F__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFMATRIX__F__
static inline easyar_OptionalOfMatrix44F OptionalOfMatrix44F_to_c(OptionalOfMatrix44F o)
{
    if (o.has_value) {
        easyar_OptionalOfMatrix44F _return_value_ = {true, o.value.get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfMatrix44F _return_value_ = {false, easyar_Matrix44F()};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_LISTOFSTRING__
#define __IMPLEMENTATION_EASYAR_LISTOFSTRING__
inline ListOfString::ListOfString(easyar_ListOfString * cdata)
    : cdata_(cdata)
{
}
inline ListOfString::~ListOfString()
{
    if (cdata_) {
        easyar_ListOfString__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfString::ListOfString(const ListOfString & data)
    : cdata_(static_cast<easyar_ListOfString *>(NULL))
{
    easyar_ListOfString_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfString * ListOfString::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfString * ListOfString::get_cdata()
{
    return cdata_;
}

inline ListOfString::ListOfString(easyar_String * * begin, easyar_String * * end)
    : cdata_(static_cast<easyar_ListOfString *>(NULL))
{
    easyar_ListOfString__ctor(begin, end, &cdata_);
}
inline int ListOfString::size() const
{
    return easyar_ListOfString_size(cdata_);
}
inline String * ListOfString::at(int index) const
{
    easyar_String * _return_value_ = easyar_ListOfString_at(cdata_, index);
    easyar_String_copy(_return_value_, &_return_value_);
    return new String(_return_value_);
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_LISTOFMATRIX__F__
#define __IMPLEMENTATION_EASYAR_LISTOFMATRIX__F__
inline ListOfMatrix44F::ListOfMatrix44F(easyar_ListOfMatrix44F * cdata)
    : cdata_(cdata)
{
}
inline ListOfMatrix44F::~ListOfMatrix44F()
{
    if (cdata_) {
        easyar_ListOfMatrix44F__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline ListOfMatrix44F::ListOfMatrix44F(const ListOfMatrix44F & data)
    : cdata_(static_cast<easyar_ListOfMatrix44F *>(NULL))
{
    easyar_ListOfMatrix44F_copy(data.cdata_, &cdata_);
}
inline const easyar_ListOfMatrix44F * ListOfMatrix44F::get_cdata() const
{
    return cdata_;
}
inline easyar_ListOfMatrix44F * ListOfMatrix44F::get_cdata()
{
    return cdata_;
}

inline ListOfMatrix44F::ListOfMatrix44F(easyar_Matrix44F * begin, easyar_Matrix44F * end)
    : cdata_(static_cast<easyar_ListOfMatrix44F *>(NULL))
{
    easyar_ListOfMatrix44F__ctor(begin, end, &cdata_);
}
inline int ListOfMatrix44F::size() const
{
    return easyar_ListOfMatrix44F_size(cdata_);
}
inline Matrix44F ListOfMatrix44F::at(int index) const
{
    easyar_Matrix44F _return_value_ = easyar_ListOfMatrix44F_at(cdata_, index);
    return Matrix44F(_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]);
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFVEC_D__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFVEC_D__
static inline easyar_OptionalOfVec3D OptionalOfVec3D_to_c(OptionalOfVec3D o)
{
    if (o.has_value) {
        easyar_OptionalOfVec3D _return_value_ = {true, o.value.get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfVec3D _return_value_ = {false, easyar_Vec3D()};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFVEC_F__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFVEC_F__
static inline easyar_OptionalOfVec3F OptionalOfVec3F_to_c(OptionalOfVec3F o)
{
    if (o.has_value) {
        easyar_OptionalOfVec3F _return_value_ = {true, o.value.get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfVec3F _return_value_ = {false, easyar_Vec3F()};
        return _return_value_;
    }
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMCLOUDLOCALIZERESULT__
#define __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMCLOUDLOCALIZERESULT__
inline FunctorOfVoidFromCloudLocalizeResult::FunctorOfVoidFromCloudLocalizeResult(void * _state, void (* func)(void * _state, CloudLocalizeResult *), void (* destroy)(void * _state))
{
    this->_state = _state;
    this->func = func;
    this->destroy = destroy;
}
static void FunctorOfVoidFromCloudLocalizeResult_func(void * _state, easyar_CloudLocalizeResult * arg0, /* OUT */ easyar_String * * _exception)
{
    *_exception = NULL;
    try {
        easyar_CloudLocalizeResult__retain(arg0, &arg0);
        CloudLocalizeResult * cpparg0 = new CloudLocalizeResult(arg0);
        FunctorOfVoidFromCloudLocalizeResult * f = reinterpret_cast<FunctorOfVoidFromCloudLocalizeResult *>(_state);
        f->func(f->_state, cpparg0);
        delete cpparg0;
    } catch (std::exception & ex) {
        easyar_String_from_utf8_begin(ex.what(), _exception);
    }
}
static void FunctorOfVoidFromCloudLocalizeResult_destroy(void * _state)
{
    FunctorOfVoidFromCloudLocalizeResult * f = reinterpret_cast<FunctorOfVoidFromCloudLocalizeResult *>(_state);
    if (f->destroy) {
        f->destroy(f->_state);
    }
    delete f;
}
static inline easyar_FunctorOfVoidFromCloudLocalizeResult FunctorOfVoidFromCloudLocalizeResult_to_c(FunctorOfVoidFromCloudLocalizeResult f)
{
    easyar_FunctorOfVoidFromCloudLocalizeResult _return_value_ = {NULL, NULL, NULL};
    _return_value_._state = new FunctorOfVoidFromCloudLocalizeResult(f._state, f.func, f.destroy);
    _return_value_.func = FunctorOfVoidFromCloudLocalizeResult_func;
    _return_value_.destroy = FunctorOfVoidFromCloudLocalizeResult_destroy;
    return _return_value_;
}
#endif

}

#endif
