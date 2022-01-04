//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"
#import "easyar/frame.oc.h"

@interface easyar_CloudLocalizeResult : easyar_FrameFilterResult

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Returns localization status.
/// </summary>
- (easyar_CloudLocalizeStatus)getLocalizeStatus;
/// <summary>
/// Returns ID of the best correspond localized map.
/// </summary>
- (NSString *)getLocalizedMapID;
/// <summary>
/// Returns the name of the best correspond localized map.
/// </summary>
- (NSString *)getLocalizedMapName;
/// <summary>
/// Returns the camera pose at the best correspond localized map coordinates.
/// </summary>
- (easyar_Matrix44F *)getPose;
/// <summary>
/// Returns the transform from local coordinates (if exists) to the best correspond map coordinates.
/// </summary>
- (easyar_Matrix44F *)getDeltaT;
/// <summary>
/// Returns ID of all localized maps.
/// </summary>
- (NSArray<NSString *> *)getAllLocalizedMapID;
/// <summary>
/// Returns the camera pose at all localized map coordinates.
/// </summary>
- (NSArray<easyar_Matrix44F *> *)getAllPose;
/// <summary>
/// Returns the transform from local coordinates (if exists) to all map coordinates.
/// </summary>
- (NSArray<easyar_Matrix44F *> *)getAllDeltaT;
/// <summary>
/// Returns extra informations of the localization.
/// </summary>
- (NSString *)getExtraInfo;
/// <summary>
/// Returns detailed exception message.
/// </summary>
- (NSString *)getExceptionInfo;
/// <summary>
/// Returns the block id of the best correspond localized map.
/// </summary>
- (NSString *)getLocalizedBlockId;
/// <summary>
/// Returns the block timestamp of the best correspond localized map.
/// </summary>
- (NSString *)getLocalizedBlockTimestamp;
/// <summary>
/// Returns the block location of the best correspond localized map.
/// </summary>
- (easyar_Vec3D *)getLocalizedBlockLocation;
/// <summary>
/// Returns the cluster id of the best correspond localized map.
/// </summary>
- (NSString *)getLocalizedClusterId;
/// <summary>
/// Returns the cluster location of the best correspond localized map.
/// </summary>
- (easyar_Vec3D *)getLocalizedClusterLocation;
/// <summary>
/// Returns the camera pose in the cluster which the best correspond localized map belongs to.
/// </summary>
- (easyar_Matrix44F *)getPoseInCluster;
/// <summary>
/// Returns the transform from local coordinates (if exists) to the best correspond map coordinates.
/// </summary>
- (easyar_Matrix44F *)getDeltaTForCluster;
/// <summary>
/// Returns the location of device.
/// </summary>
- (easyar_Vec3D *)getDeviceLocation;

@end

/// <summary>
/// CloudLocalizer implements cloud based localization.
/// </summary>
@interface easyar_CloudLocalizer : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Returns true.
/// </summary>
+ (bool)isAvailable;
/// <summary>
/// Creates an instance and connects to the server.
/// </summary>
+ (easyar_CloudLocalizer *)create:(NSString *)server apiKey:(NSString *)apiKey apiSecret:(NSString *)apiSecret appId:(NSString *)appId;
/// <summary>
/// Send localization request.
/// Send `InputFrame`_ to resolve a cloud localization. `InputFrame`_ should have at least image data and camera parameters.
/// message input is a json string.
/// acceleration is optional which is the readings from device accelerometer.
/// location is optional which is the readings from device location manager.
/// </summary>
- (void)resolve:(easyar_InputFrame *)inputFrame message:(NSString *)message acceleration:(easyar_Vec3F *)acceleration location:(easyar_Vec3D *)location callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler callback:(void (^)(easyar_CloudLocalizeResult * result))callback;
/// <summary>
/// Stops the localization and closes connection. The component shall not be used after calling close.
/// </summary>
- (void)close;

@end
