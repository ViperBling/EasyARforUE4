//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_STORAGE_HXX__
#define __EASYAR_STORAGE_HXX__

#include "easyar/types.hxx"

namespace easyar {

class Storage
{
public:
    /// <summary>
    /// Sets asset root path.
    /// </summary>
    static void setAssetDirPath(String * path);
};

}

#endif

#ifndef __IMPLEMENTATION_EASYAR_STORAGE_HXX__
#define __IMPLEMENTATION_EASYAR_STORAGE_HXX__

#include "easyar/storage.h"

namespace easyar {

inline void Storage::setAssetDirPath(String * arg0)
{
    easyar_Storage_setAssetDirPath(arg0->get_cdata());
}

}

#endif
