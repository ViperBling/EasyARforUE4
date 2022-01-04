//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CALIBRATION_HXX__
#define __EASYAR_CALIBRATION_HXX__

#include "easyar/types.hxx"

namespace easyar {

/// <summary>
/// CalibrationDownloader is used for download and update of calibration data in MotionTracker. The calibration data will only take effect after reallocation of MotionTracker.
/// </summary>
class CalibrationDownloader
{
protected:
    easyar_CalibrationDownloader * cdata_ ;
    void init_cdata(easyar_CalibrationDownloader * cdata);
    virtual CalibrationDownloader & operator=(const CalibrationDownloader & data) { return *this; } //deleted
public:
    CalibrationDownloader(easyar_CalibrationDownloader * cdata);
    virtual ~CalibrationDownloader();

    CalibrationDownloader(const CalibrationDownloader & data);
    const easyar_CalibrationDownloader * get_cdata() const;
    easyar_CalibrationDownloader * get_cdata();

    CalibrationDownloader();
    void download(CallbackScheduler * callbackScheduler, FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString onCompleted);
};

#ifndef __EASYAR_OPTIONALOFSTRING__
#define __EASYAR_OPTIONALOFSTRING__
struct OptionalOfString
{
    bool has_value;
    String * value;
};
static inline easyar_OptionalOfString OptionalOfString_to_c(String * o);
#endif

#ifndef __EASYAR_FUNCTOROFVOIDFROMCALIBRATIONDOWNLOADSTATUSANDOPTIONALOFSTRING__
#define __EASYAR_FUNCTOROFVOIDFROMCALIBRATIONDOWNLOADSTATUSANDOPTIONALOFSTRING__
struct FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString
{
    void * _state;
    void (* func)(void * _state, CalibrationDownloadStatus, String *);
    void (* destroy)(void * _state);
    FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString(void * _state, void (* func)(void * _state, CalibrationDownloadStatus, String *), void (* destroy)(void * _state));
};

static void FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_func(void * _state, easyar_CalibrationDownloadStatus, easyar_OptionalOfString, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_to_c(FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString f);
#endif

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_CALIBRATION_HXX__
#define __IMPLEMENTATION_EASYAR_CALIBRATION_HXX__

#include "easyar/calibration.h"
#include "easyar/callbackscheduler.hxx"

namespace easyar {

inline CalibrationDownloader::CalibrationDownloader(easyar_CalibrationDownloader * cdata)
    :
    cdata_(NULL)
{
    init_cdata(cdata);
}
inline CalibrationDownloader::~CalibrationDownloader()
{
    if (cdata_) {
        easyar_CalibrationDownloader__dtor(cdata_);
        cdata_ = NULL;
    }
}

inline CalibrationDownloader::CalibrationDownloader(const CalibrationDownloader & data)
    :
    cdata_(NULL)
{
    easyar_CalibrationDownloader * cdata = NULL;
    easyar_CalibrationDownloader__retain(data.cdata_, &cdata);
    init_cdata(cdata);
}
inline const easyar_CalibrationDownloader * CalibrationDownloader::get_cdata() const
{
    return cdata_;
}
inline easyar_CalibrationDownloader * CalibrationDownloader::get_cdata()
{
    return cdata_;
}
inline void CalibrationDownloader::init_cdata(easyar_CalibrationDownloader * cdata)
{
    cdata_ = cdata;
}
inline CalibrationDownloader::CalibrationDownloader()
    :
    cdata_(NULL)
{
    easyar_CalibrationDownloader * _return_value_ = NULL;
    easyar_CalibrationDownloader__ctor(&_return_value_);
    init_cdata(_return_value_);
}
inline void CalibrationDownloader::download(CallbackScheduler * arg0, FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString arg1)
{
    if (cdata_ == NULL) {
        return;
    }
    easyar_CalibrationDownloader_download(cdata_, arg0->get_cdata(), FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_to_c(arg1));
}

#ifndef __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMCALIBRATIONDOWNLOADSTATUSANDOPTIONALOFSTRING__
#define __IMPLEMENTATION_EASYAR_FUNCTOROFVOIDFROMCALIBRATIONDOWNLOADSTATUSANDOPTIONALOFSTRING__
inline FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString::FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString(void * _state, void (* func)(void * _state, CalibrationDownloadStatus, String *), void (* destroy)(void * _state))
{
    this->_state = _state;
    this->func = func;
    this->destroy = destroy;
}
static void FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_func(void * _state, easyar_CalibrationDownloadStatus arg0, easyar_OptionalOfString arg1, /* OUT */ easyar_String * * _exception)
{
    *_exception = NULL;
    try {
        CalibrationDownloadStatus cpparg0 = static_cast<CalibrationDownloadStatus>(arg0);
        if (arg1.has_value) { easyar_String_copy(arg1.value, &arg1.value); }
        String * cpparg1 = (arg1.has_value ? new String(arg1.value) : NULL);
        FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString * f = reinterpret_cast<FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString *>(_state);
        f->func(f->_state, cpparg0, cpparg1);
        delete cpparg1;
    } catch (std::exception & ex) {
        easyar_String_from_utf8_begin(ex.what(), _exception);
    }
}
static void FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_destroy(void * _state)
{
    FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString * f = reinterpret_cast<FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString *>(_state);
    if (f->destroy) {
        f->destroy(f->_state);
    }
    delete f;
}
static inline easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_to_c(FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString f)
{
    easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString _return_value_ = {NULL, NULL, NULL};
    _return_value_._state = new FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString(f._state, f.func, f.destroy);
    _return_value_.func = FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_func;
    _return_value_.destroy = FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_destroy;
    return _return_value_;
}
#endif

#ifndef __IMPLEMENTATION_EASYAR_OPTIONALOFSTRING__
#define __IMPLEMENTATION_EASYAR_OPTIONALOFSTRING__
static inline easyar_OptionalOfString OptionalOfString_to_c(String * o)
{
    if (o != NULL) {
        easyar_OptionalOfString _return_value_ = {true, o->get_cdata()};
        return _return_value_;
    } else {
        easyar_OptionalOfString _return_value_ = {false, NULL};
        return _return_value_;
    }
}
#endif

}

#endif
