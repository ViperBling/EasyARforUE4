//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CALIBRATION_H__
#define __EASYAR_CALIBRATION_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_CalibrationDownloader__ctor(/* OUT */ easyar_CalibrationDownloader * * Return);
void easyar_CalibrationDownloader_download(easyar_CalibrationDownloader * This, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString onCompleted);
void easyar_CalibrationDownloader__dtor(easyar_CalibrationDownloader * This);
void easyar_CalibrationDownloader__retain(const easyar_CalibrationDownloader * This, /* OUT */ easyar_CalibrationDownloader * * Return);
const char * easyar_CalibrationDownloader__typeName(const easyar_CalibrationDownloader * This);

#ifdef __cplusplus
}
#endif

#endif
