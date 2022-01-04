//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CLOUDLOCALIZE_H__
#define __EASYAR_CLOUDLOCALIZE_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Returns localization status.
/// </summary>
easyar_CloudLocalizeStatus easyar_CloudLocalizeResult_getLocalizeStatus(const easyar_CloudLocalizeResult * This);
/// <summary>
/// Returns ID of the best correspond localized map.
/// </summary>
void easyar_CloudLocalizeResult_getLocalizedMapID(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// Returns the name of the best correspond localized map.
/// </summary>
void easyar_CloudLocalizeResult_getLocalizedMapName(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// Returns the camera pose at the best correspond localized map coordinates.
/// </summary>
easyar_Matrix44F easyar_CloudLocalizeResult_getPose(const easyar_CloudLocalizeResult * This);
/// <summary>
/// Returns the transform from local coordinates (if exists) to the best correspond map coordinates.
/// </summary>
easyar_OptionalOfMatrix44F easyar_CloudLocalizeResult_getDeltaT(const easyar_CloudLocalizeResult * This);
/// <summary>
/// Returns ID of all localized maps.
/// </summary>
void easyar_CloudLocalizeResult_getAllLocalizedMapID(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_ListOfString * * Return);
/// <summary>
/// Returns the camera pose at all localized map coordinates.
/// </summary>
void easyar_CloudLocalizeResult_getAllPose(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_ListOfMatrix44F * * Return);
/// <summary>
/// Returns the transform from local coordinates (if exists) to all map coordinates.
/// </summary>
void easyar_CloudLocalizeResult_getAllDeltaT(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_ListOfMatrix44F * * Return);
/// <summary>
/// Returns extra informations of the localization.
/// </summary>
void easyar_CloudLocalizeResult_getExtraInfo(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// Returns detailed exception message.
/// </summary>
void easyar_CloudLocalizeResult_getExceptionInfo(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// Returns the block id of the best correspond localized map.
/// </summary>
void easyar_CloudLocalizeResult_getLocalizedBlockId(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// Returns the block timestamp of the best correspond localized map.
/// </summary>
void easyar_CloudLocalizeResult_getLocalizedBlockTimestamp(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// Returns the block location of the best correspond localized map.
/// </summary>
easyar_OptionalOfVec3D easyar_CloudLocalizeResult_getLocalizedBlockLocation(const easyar_CloudLocalizeResult * This);
/// <summary>
/// Returns the cluster id of the best correspond localized map.
/// </summary>
void easyar_CloudLocalizeResult_getLocalizedClusterId(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// Returns the cluster location of the best correspond localized map.
/// </summary>
easyar_OptionalOfVec3D easyar_CloudLocalizeResult_getLocalizedClusterLocation(const easyar_CloudLocalizeResult * This);
/// <summary>
/// Returns the camera pose in the cluster which the best correspond localized map belongs to.
/// </summary>
easyar_Matrix44F easyar_CloudLocalizeResult_getPoseInCluster(const easyar_CloudLocalizeResult * This);
/// <summary>
/// Returns the transform from local coordinates (if exists) to the best correspond map coordinates.
/// </summary>
easyar_OptionalOfMatrix44F easyar_CloudLocalizeResult_getDeltaTForCluster(const easyar_CloudLocalizeResult * This);
/// <summary>
/// Returns the location of device.
/// </summary>
easyar_OptionalOfVec3D easyar_CloudLocalizeResult_getDeviceLocation(const easyar_CloudLocalizeResult * This);
void easyar_CloudLocalizeResult__dtor(easyar_CloudLocalizeResult * This);
void easyar_CloudLocalizeResult__retain(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_CloudLocalizeResult * * Return);
const char * easyar_CloudLocalizeResult__typeName(const easyar_CloudLocalizeResult * This);
void easyar_castCloudLocalizeResultToFrameFilterResult(const easyar_CloudLocalizeResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
void easyar_tryCastFrameFilterResultToCloudLocalizeResult(const easyar_FrameFilterResult * This, /* OUT */ easyar_CloudLocalizeResult * * Return);

/// <summary>
/// Returns true.
/// </summary>
bool easyar_CloudLocalizer_isAvailable(void);
/// <summary>
/// Creates an instance and connects to the server.
/// </summary>
void easyar_CloudLocalizer_create(easyar_String * server, easyar_String * apiKey, easyar_String * apiSecret, easyar_String * appId, /* OUT */ easyar_CloudLocalizer * * Return);
/// <summary>
/// Send localization request.
/// Send `InputFrame`_ to resolve a cloud localization. `InputFrame`_ should have at least image data and camera parameters.
/// message input is a json string.
/// acceleration is optional which is the readings from device accelerometer.
/// location is optional which is the readings from device location manager.
/// </summary>
void easyar_CloudLocalizer_resolve(easyar_CloudLocalizer * This, easyar_InputFrame * inputFrame, easyar_String * message, easyar_OptionalOfVec3F acceleration, easyar_OptionalOfVec3D location, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromCloudLocalizeResult callback);
/// <summary>
/// Stops the localization and closes connection. The component shall not be used after calling close.
/// </summary>
void easyar_CloudLocalizer_close(easyar_CloudLocalizer * This);
void easyar_CloudLocalizer__dtor(easyar_CloudLocalizer * This);
void easyar_CloudLocalizer__retain(const easyar_CloudLocalizer * This, /* OUT */ easyar_CloudLocalizer * * Return);
const char * easyar_CloudLocalizer__typeName(const easyar_CloudLocalizer * This);

void easyar_ListOfString__ctor(easyar_String * const * begin, easyar_String * const * end, /* OUT */ easyar_ListOfString * * Return);
void easyar_ListOfString__dtor(easyar_ListOfString * This);
void easyar_ListOfString_copy(const easyar_ListOfString * This, /* OUT */ easyar_ListOfString * * Return);
int easyar_ListOfString_size(const easyar_ListOfString * This);
easyar_String * easyar_ListOfString_at(const easyar_ListOfString * This, int index);

void easyar_ListOfMatrix44F__ctor(easyar_Matrix44F const * begin, easyar_Matrix44F const * end, /* OUT */ easyar_ListOfMatrix44F * * Return);
void easyar_ListOfMatrix44F__dtor(easyar_ListOfMatrix44F * This);
void easyar_ListOfMatrix44F_copy(const easyar_ListOfMatrix44F * This, /* OUT */ easyar_ListOfMatrix44F * * Return);
int easyar_ListOfMatrix44F_size(const easyar_ListOfMatrix44F * This);
easyar_Matrix44F easyar_ListOfMatrix44F_at(const easyar_ListOfMatrix44F * This, int index);

#ifdef __cplusplus
}
#endif

#endif
