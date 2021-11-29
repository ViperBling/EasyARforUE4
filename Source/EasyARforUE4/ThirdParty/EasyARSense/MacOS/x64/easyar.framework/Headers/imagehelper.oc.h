﻿//=============================================================================================================================
//
// EasyAR Sense 4.3.0.8981-4ecf7d1ec
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

/// <summary>
/// Image helper class.
/// </summary>
@interface easyar_ImageHelper : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Decodes a JPEG or PNG file.
/// </summary>
+ (easyar_Image *)decode:(easyar_Buffer *)buffer;

@end
