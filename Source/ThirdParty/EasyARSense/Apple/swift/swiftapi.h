//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __cplusplus
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct easyar_Opaque easyar_Opaque;

typedef struct easyar_String easyar_String;
void easyar_String_from_utf8(const char * _Nullable begin, const char * _Nullable end, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_String_from_utf8_begin(const char * _Nonnull begin, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
const char * _Nullable easyar_String_begin(const easyar_String * _Nonnull This);
const char * _Nullable easyar_String_end(const easyar_String * _Nonnull This);
void easyar_String_copy(const easyar_String * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_String__dtor(easyar_String * _Nonnull This);

typedef struct easyar_ObjectTargetParameters easyar_ObjectTargetParameters;

typedef struct easyar_ObjectTarget easyar_ObjectTarget;

typedef struct easyar_ObjectTrackerResult easyar_ObjectTrackerResult;

typedef struct easyar_ObjectTracker easyar_ObjectTracker;

typedef struct easyar_CalibrationDownloader easyar_CalibrationDownloader;

typedef struct easyar_CloudLocalizeResult easyar_CloudLocalizeResult;

typedef struct easyar_CloudLocalizer easyar_CloudLocalizer;

typedef struct easyar_CloudRecognizationResult easyar_CloudRecognizationResult;

typedef struct easyar_CloudRecognizer easyar_CloudRecognizer;

typedef struct easyar_Buffer easyar_Buffer;

typedef struct easyar_BufferDictionary easyar_BufferDictionary;

typedef struct easyar_BufferPool easyar_BufferPool;

typedef struct easyar_CameraParameters easyar_CameraParameters;

typedef struct easyar_Image easyar_Image;

typedef struct
{
    float data[16];
} easyar_Matrix44F;

typedef struct
{
    float data[9];
} easyar_Matrix33F;

typedef struct
{
    double data[3];
} easyar_Vec3D;

typedef struct
{
    float data[4];
} easyar_Vec4F;

typedef struct
{
    float data[3];
} easyar_Vec3F;

typedef struct
{
    float data[2];
} easyar_Vec2F;

typedef struct
{
    int data[4];
} easyar_Vec4I;

typedef struct
{
    int data[2];
} easyar_Vec2I;

typedef struct easyar_DenseSpatialMap easyar_DenseSpatialMap;

typedef struct
{
    int x;
    int y;
    int z;
    int numOfVertex;
    int startPointOfVertex;
    int numOfIndex;
    int startPointOfIndex;
    int version;
} easyar_BlockInfo;

typedef struct easyar_SceneMesh easyar_SceneMesh;

typedef struct
{
    float x;
    float y;
    float z;
    double timestamp;
} easyar_AccelerometerResult;

typedef struct easyar_Accelerometer easyar_Accelerometer;

typedef struct easyar_ARCoreCameraDevice easyar_ARCoreCameraDevice;

typedef struct easyar_ARKitCameraDevice easyar_ARKitCameraDevice;

typedef struct easyar_CameraDevice easyar_CameraDevice;

typedef struct easyar_CameraDeviceSelector easyar_CameraDeviceSelector;

typedef struct
{
    float x;
    float y;
    float z;
    double timestamp;
} easyar_MagnetometerResult;

typedef struct easyar_SurfaceTrackerResult easyar_SurfaceTrackerResult;

typedef struct easyar_SurfaceTracker easyar_SurfaceTracker;

typedef struct easyar_MotionTrackerCameraDevice easyar_MotionTrackerCameraDevice;

typedef struct easyar_InputFrameRecorder easyar_InputFrameRecorder;

typedef struct easyar_InputFramePlayer easyar_InputFramePlayer;

typedef struct easyar_CallbackScheduler easyar_CallbackScheduler;

typedef struct easyar_DelayedCallbackScheduler easyar_DelayedCallbackScheduler;

typedef struct easyar_ImmediateCallbackScheduler easyar_ImmediateCallbackScheduler;

typedef struct easyar_JniUtility easyar_JniUtility;

typedef struct easyar_Log easyar_Log;

typedef struct easyar_Storage easyar_Storage;

typedef struct easyar_ImageTargetParameters easyar_ImageTargetParameters;

typedef struct easyar_ImageTarget easyar_ImageTarget;

typedef struct easyar_ImageTrackerResult easyar_ImageTrackerResult;

typedef struct easyar_ImageTracker easyar_ImageTracker;

typedef struct easyar_RealTimeCoordinateTransform easyar_RealTimeCoordinateTransform;

typedef struct easyar_Recorder easyar_Recorder;

typedef struct easyar_RecorderConfiguration easyar_RecorderConfiguration;

typedef struct easyar_SparseSpatialMapResult easyar_SparseSpatialMapResult;

typedef struct easyar_PlaneData easyar_PlaneData;

typedef struct easyar_SparseSpatialMapConfig easyar_SparseSpatialMapConfig;

typedef struct easyar_SparseSpatialMap easyar_SparseSpatialMap;

typedef struct easyar_SparseSpatialMapManager easyar_SparseSpatialMapManager;

typedef struct easyar_Engine easyar_Engine;

typedef struct easyar_VideoPlayer easyar_VideoPlayer;

typedef struct easyar_ImageHelper easyar_ImageHelper;

typedef struct easyar_SignalSink easyar_SignalSink;

typedef struct easyar_SignalSource easyar_SignalSource;

typedef struct easyar_InputFrameSink easyar_InputFrameSink;

typedef struct easyar_InputFrameSource easyar_InputFrameSource;

typedef struct easyar_OutputFrameSink easyar_OutputFrameSink;

typedef struct easyar_OutputFrameSource easyar_OutputFrameSource;

typedef struct easyar_FeedbackFrameSink easyar_FeedbackFrameSink;

typedef struct easyar_FeedbackFrameSource easyar_FeedbackFrameSource;

typedef struct easyar_InputFrameFork easyar_InputFrameFork;

typedef struct easyar_OutputFrameFork easyar_OutputFrameFork;

typedef struct easyar_OutputFrameJoin easyar_OutputFrameJoin;

typedef struct easyar_FeedbackFrameFork easyar_FeedbackFrameFork;

typedef struct easyar_InputFrameThrottler easyar_InputFrameThrottler;

typedef struct easyar_OutputFrameBuffer easyar_OutputFrameBuffer;

typedef struct easyar_InputFrameToOutputFrameAdapter easyar_InputFrameToOutputFrameAdapter;

typedef struct easyar_InputFrameToFeedbackFrameAdapter easyar_InputFrameToFeedbackFrameAdapter;

typedef struct easyar_InputFrame easyar_InputFrame;

typedef struct easyar_FrameFilterResult easyar_FrameFilterResult;

typedef struct easyar_OutputFrame easyar_OutputFrame;

typedef struct easyar_FeedbackFrame easyar_FeedbackFrame;

typedef struct easyar_Target easyar_Target;

typedef struct easyar_TargetInstance easyar_TargetInstance;

typedef struct easyar_TargetTrackerResult easyar_TargetTrackerResult;

typedef struct easyar_TextureId easyar_TextureId;

typedef struct { bool has_value; easyar_Buffer * _Nullable value; } easyar_OptionalOfBuffer;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoid;

typedef struct { bool has_value; easyar_ObjectTarget * _Nullable value; } easyar_OptionalOfObjectTarget;

typedef struct easyar_ListOfVec3F easyar_ListOfVec3F;

typedef struct easyar_ListOfTargetInstance easyar_ListOfTargetInstance;

typedef struct { bool has_value; easyar_Target * _Nullable value; } easyar_OptionalOfTarget;

typedef struct { bool has_value; easyar_OutputFrame * _Nullable value; } easyar_OptionalOfOutputFrame;

typedef struct { bool has_value; easyar_FrameFilterResult * _Nullable value; } easyar_OptionalOfFrameFilterResult;

typedef struct easyar_ListOfOptionalOfFrameFilterResult easyar_ListOfOptionalOfFrameFilterResult;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, easyar_OutputFrame * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromOutputFrame;

typedef struct { bool has_value; easyar_FunctorOfVoidFromOutputFrame value; } easyar_OptionalOfFunctorOfVoidFromOutputFrame;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, easyar_Target * _Nonnull, bool, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromTargetAndBool;

typedef struct easyar_ListOfTarget easyar_ListOfTarget;

typedef struct { bool has_value; easyar_String * _Nullable value; } easyar_OptionalOfString;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, int, easyar_OptionalOfString, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString;

typedef struct { bool has_value; easyar_Matrix44F value; } easyar_OptionalOfMatrix44F;

typedef struct easyar_ListOfString easyar_ListOfString;

typedef struct easyar_ListOfMatrix44F easyar_ListOfMatrix44F;

typedef struct { bool has_value; easyar_Vec3D value; } easyar_OptionalOfVec3D;

typedef struct { bool has_value; easyar_Vec3F value; } easyar_OptionalOfVec3F;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, easyar_CloudLocalizeResult * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromCloudLocalizeResult;

typedef struct { bool has_value; easyar_ImageTarget * _Nullable value; } easyar_OptionalOfImageTarget;

typedef struct easyar_ListOfImage easyar_ListOfImage;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, easyar_CloudRecognizationResult * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromCloudRecognizationResult;

typedef struct easyar_ListOfBlockInfo easyar_ListOfBlockInfo;

typedef struct { bool has_value; easyar_AccelerometerResult value; } easyar_OptionalOfAccelerometerResult;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, easyar_InputFrame * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromInputFrame;

typedef struct { bool has_value; easyar_FunctorOfVoidFromInputFrame value; } easyar_OptionalOfFunctorOfVoidFromInputFrame;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, int, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromCameraState;

typedef struct { bool has_value; easyar_FunctorOfVoidFromCameraState value; } easyar_OptionalOfFunctorOfVoidFromCameraState;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, int, easyar_String * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromPermissionStatusAndString;

typedef struct { bool has_value; easyar_FunctorOfVoidFromPermissionStatusAndString value; } easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, int, easyar_String * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromLogLevelAndString;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, int, easyar_String * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromRecordStatusAndString;

typedef struct { bool has_value; easyar_FunctorOfVoidFromRecordStatusAndString value; } easyar_OptionalOfFunctorOfVoidFromRecordStatusAndString;

typedef struct easyar_ListOfPlaneData easyar_ListOfPlaneData;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, bool, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromBool;

typedef struct { bool has_value; easyar_FunctorOfVoidFromBool value; } easyar_OptionalOfFunctorOfVoidFromBool;

typedef struct { bool has_value; easyar_Image * _Nullable value; } easyar_OptionalOfImage;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, bool, easyar_String * _Nonnull, easyar_String * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromBoolAndStringAndString;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, bool, easyar_String * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromBoolAndString;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, int, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromVideoStatus;

typedef struct { bool has_value; easyar_FunctorOfVoidFromVideoStatus value; } easyar_OptionalOfFunctorOfVoidFromVideoStatus;

typedef struct { bool has_value; easyar_FunctorOfVoid value; } easyar_OptionalOfFunctorOfVoid;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, easyar_FeedbackFrame * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfVoidFromFeedbackFrame;

typedef struct { bool has_value; easyar_FunctorOfVoidFromFeedbackFrame value; } easyar_OptionalOfFunctorOfVoidFromFeedbackFrame;

typedef struct easyar_ListOfOutputFrame easyar_ListOfOutputFrame;

typedef struct
{
    easyar_Opaque * _Nonnull _state;
    void (* _Nonnull _func)(easyar_Opaque * _Nonnull _state, easyar_ListOfOutputFrame * _Nonnull, /* OUT */ easyar_OutputFrame * _Nonnull * _Nonnull, /* OUT */ easyar_String * _Nullable * _Nonnull _exception);
    void (* _Nonnull _destroy)(easyar_Opaque * _Nonnull _state);
} easyar_FunctorOfOutputFrameFromListOfOutputFrame;

void easyar_ObjectTargetParameters__ctor(/* OUT */ easyar_ObjectTargetParameters * _Nonnull * _Nonnull Return);
void easyar_ObjectTargetParameters_bufferDictionary(easyar_ObjectTargetParameters * _Nonnull This, /* OUT */ easyar_BufferDictionary * _Nonnull * _Nonnull Return);
void easyar_ObjectTargetParameters_setBufferDictionary(easyar_ObjectTargetParameters * _Nonnull This, easyar_BufferDictionary * _Nonnull bufferDictionary);
void easyar_ObjectTargetParameters_objPath(easyar_ObjectTargetParameters * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ObjectTargetParameters_setObjPath(easyar_ObjectTargetParameters * _Nonnull This, easyar_String * _Nonnull objPath);
void easyar_ObjectTargetParameters_name(easyar_ObjectTargetParameters * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ObjectTargetParameters_setName(easyar_ObjectTargetParameters * _Nonnull This, easyar_String * _Nonnull name);
void easyar_ObjectTargetParameters_uid(easyar_ObjectTargetParameters * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ObjectTargetParameters_setUid(easyar_ObjectTargetParameters * _Nonnull This, easyar_String * _Nonnull uid);
void easyar_ObjectTargetParameters_meta(easyar_ObjectTargetParameters * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ObjectTargetParameters_setMeta(easyar_ObjectTargetParameters * _Nonnull This, easyar_String * _Nonnull meta);
float easyar_ObjectTargetParameters_scale(easyar_ObjectTargetParameters * _Nonnull This);
void easyar_ObjectTargetParameters_setScale(easyar_ObjectTargetParameters * _Nonnull This, float size);
void easyar_ObjectTargetParameters__dtor(easyar_ObjectTargetParameters * _Nonnull This);
void easyar_ObjectTargetParameters__retain(const easyar_ObjectTargetParameters * _Nonnull This, /* OUT */ easyar_ObjectTargetParameters * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ObjectTargetParameters__typeName(const easyar_ObjectTargetParameters * _Nonnull This);

void easyar_ObjectTarget__ctor(/* OUT */ easyar_ObjectTarget * _Nonnull * _Nonnull Return);
void easyar_ObjectTarget_createFromParameters(easyar_ObjectTargetParameters * _Nonnull parameters, /* OUT */ easyar_OptionalOfObjectTarget * _Nonnull Return);
void easyar_ObjectTarget_createFromObjectFile(easyar_String * _Nonnull path, int storageType, easyar_String * _Nonnull name, easyar_String * _Nonnull uid, easyar_String * _Nonnull meta, float scale, /* OUT */ easyar_OptionalOfObjectTarget * _Nonnull Return);
float easyar_ObjectTarget_scale(const easyar_ObjectTarget * _Nonnull This);
void easyar_ObjectTarget_boundingBox(easyar_ObjectTarget * _Nonnull This, /* OUT */ easyar_ListOfVec3F * _Nonnull * _Nonnull Return);
bool easyar_ObjectTarget_setScale(easyar_ObjectTarget * _Nonnull This, float scale);
int easyar_ObjectTarget_runtimeID(const easyar_ObjectTarget * _Nonnull This);
void easyar_ObjectTarget_uid(const easyar_ObjectTarget * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ObjectTarget_name(const easyar_ObjectTarget * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ObjectTarget_setName(easyar_ObjectTarget * _Nonnull This, easyar_String * _Nonnull name);
void easyar_ObjectTarget_meta(const easyar_ObjectTarget * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ObjectTarget_setMeta(easyar_ObjectTarget * _Nonnull This, easyar_String * _Nonnull data);
void easyar_ObjectTarget__dtor(easyar_ObjectTarget * _Nonnull This);
void easyar_ObjectTarget__retain(const easyar_ObjectTarget * _Nonnull This, /* OUT */ easyar_ObjectTarget * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ObjectTarget__typeName(const easyar_ObjectTarget * _Nonnull This);
void easyar_castObjectTargetToTarget(const easyar_ObjectTarget * _Nonnull This, /* OUT */ easyar_Target * _Nonnull * _Nonnull Return);
void easyar_tryCastTargetToObjectTarget(const easyar_Target * _Nonnull This, /* OUT */ easyar_ObjectTarget * _Nonnull * _Nonnull Return);

void easyar_ObjectTrackerResult_targetInstances(const easyar_ObjectTrackerResult * _Nonnull This, /* OUT */ easyar_ListOfTargetInstance * _Nonnull * _Nonnull Return);
void easyar_ObjectTrackerResult_setTargetInstances(easyar_ObjectTrackerResult * _Nonnull This, easyar_ListOfTargetInstance * _Nonnull instances);
void easyar_ObjectTrackerResult__dtor(easyar_ObjectTrackerResult * _Nonnull This);
void easyar_ObjectTrackerResult__retain(const easyar_ObjectTrackerResult * _Nonnull This, /* OUT */ easyar_ObjectTrackerResult * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ObjectTrackerResult__typeName(const easyar_ObjectTrackerResult * _Nonnull This);
void easyar_castObjectTrackerResultToFrameFilterResult(const easyar_ObjectTrackerResult * _Nonnull This, /* OUT */ easyar_FrameFilterResult * _Nonnull * _Nonnull Return);
void easyar_tryCastFrameFilterResultToObjectTrackerResult(const easyar_FrameFilterResult * _Nonnull This, /* OUT */ easyar_ObjectTrackerResult * _Nonnull * _Nonnull Return);
void easyar_castObjectTrackerResultToTargetTrackerResult(const easyar_ObjectTrackerResult * _Nonnull This, /* OUT */ easyar_TargetTrackerResult * _Nonnull * _Nonnull Return);
void easyar_tryCastTargetTrackerResultToObjectTrackerResult(const easyar_TargetTrackerResult * _Nonnull This, /* OUT */ easyar_ObjectTrackerResult * _Nonnull * _Nonnull Return);

bool easyar_ObjectTracker_isAvailable();
void easyar_ObjectTracker_feedbackFrameSink(easyar_ObjectTracker * _Nonnull This, /* OUT */ easyar_FeedbackFrameSink * _Nonnull * _Nonnull Return);
int easyar_ObjectTracker_bufferRequirement(easyar_ObjectTracker * _Nonnull This);
void easyar_ObjectTracker_outputFrameSource(easyar_ObjectTracker * _Nonnull This, /* OUT */ easyar_OutputFrameSource * _Nonnull * _Nonnull Return);
void easyar_ObjectTracker_create(/* OUT */ easyar_ObjectTracker * _Nonnull * _Nonnull Return);
bool easyar_ObjectTracker_start(easyar_ObjectTracker * _Nonnull This);
void easyar_ObjectTracker_stop(easyar_ObjectTracker * _Nonnull This);
void easyar_ObjectTracker_close(easyar_ObjectTracker * _Nonnull This);
void easyar_ObjectTracker_loadTarget(easyar_ObjectTracker * _Nonnull This, easyar_Target * _Nonnull target, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_FunctorOfVoidFromTargetAndBool callback);
void easyar_ObjectTracker_unloadTarget(easyar_ObjectTracker * _Nonnull This, easyar_Target * _Nonnull target, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_FunctorOfVoidFromTargetAndBool callback);
void easyar_ObjectTracker_targets(const easyar_ObjectTracker * _Nonnull This, /* OUT */ easyar_ListOfTarget * _Nonnull * _Nonnull Return);
bool easyar_ObjectTracker_setSimultaneousNum(easyar_ObjectTracker * _Nonnull This, int num);
int easyar_ObjectTracker_simultaneousNum(const easyar_ObjectTracker * _Nonnull This);
void easyar_ObjectTracker__dtor(easyar_ObjectTracker * _Nonnull This);
void easyar_ObjectTracker__retain(const easyar_ObjectTracker * _Nonnull This, /* OUT */ easyar_ObjectTracker * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ObjectTracker__typeName(const easyar_ObjectTracker * _Nonnull This);

void easyar_CalibrationDownloader__ctor(/* OUT */ easyar_CalibrationDownloader * _Nonnull * _Nonnull Return);
void easyar_CalibrationDownloader_download(easyar_CalibrationDownloader * _Nonnull This, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString onCompleted);
void easyar_CalibrationDownloader__dtor(easyar_CalibrationDownloader * _Nonnull This);
void easyar_CalibrationDownloader__retain(const easyar_CalibrationDownloader * _Nonnull This, /* OUT */ easyar_CalibrationDownloader * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_CalibrationDownloader__typeName(const easyar_CalibrationDownloader * _Nonnull This);

int easyar_CloudLocalizeResult_getLocalizeStatus(const easyar_CloudLocalizeResult * _Nonnull This);
void easyar_CloudLocalizeResult_getLocalizedMapID(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_CloudLocalizeResult_getLocalizedMapName(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
easyar_Matrix44F easyar_CloudLocalizeResult_getPose(const easyar_CloudLocalizeResult * _Nonnull This);
easyar_OptionalOfMatrix44F easyar_CloudLocalizeResult_getDeltaT(const easyar_CloudLocalizeResult * _Nonnull This);
void easyar_CloudLocalizeResult_getAllLocalizedMapID(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_ListOfString * _Nonnull * _Nonnull Return);
void easyar_CloudLocalizeResult_getAllPose(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_ListOfMatrix44F * _Nonnull * _Nonnull Return);
void easyar_CloudLocalizeResult_getAllDeltaT(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_ListOfMatrix44F * _Nonnull * _Nonnull Return);
void easyar_CloudLocalizeResult_getExtraInfo(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_CloudLocalizeResult_getExceptionInfo(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_CloudLocalizeResult_getLocalizedBlockId(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_CloudLocalizeResult_getLocalizedBlockTimestamp(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
easyar_OptionalOfVec3D easyar_CloudLocalizeResult_getLocalizedBlockLocation(const easyar_CloudLocalizeResult * _Nonnull This);
void easyar_CloudLocalizeResult_getLocalizedClusterId(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
easyar_OptionalOfVec3D easyar_CloudLocalizeResult_getLocalizedClusterLocation(const easyar_CloudLocalizeResult * _Nonnull This);
easyar_Matrix44F easyar_CloudLocalizeResult_getPoseInCluster(const easyar_CloudLocalizeResult * _Nonnull This);
easyar_OptionalOfMatrix44F easyar_CloudLocalizeResult_getDeltaTForCluster(const easyar_CloudLocalizeResult * _Nonnull This);
easyar_OptionalOfVec3D easyar_CloudLocalizeResult_getDeviceLocation(const easyar_CloudLocalizeResult * _Nonnull This);
void easyar_CloudLocalizeResult__dtor(easyar_CloudLocalizeResult * _Nonnull This);
void easyar_CloudLocalizeResult__retain(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_CloudLocalizeResult * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_CloudLocalizeResult__typeName(const easyar_CloudLocalizeResult * _Nonnull This);
void easyar_castCloudLocalizeResultToFrameFilterResult(const easyar_CloudLocalizeResult * _Nonnull This, /* OUT */ easyar_FrameFilterResult * _Nonnull * _Nonnull Return);
void easyar_tryCastFrameFilterResultToCloudLocalizeResult(const easyar_FrameFilterResult * _Nonnull This, /* OUT */ easyar_CloudLocalizeResult * _Nonnull * _Nonnull Return);

bool easyar_CloudLocalizer_isAvailable();
void easyar_CloudLocalizer_create(easyar_String * _Nonnull server, easyar_String * _Nonnull apiKey, easyar_String * _Nonnull apiSecret, easyar_String * _Nonnull appId, /* OUT */ easyar_CloudLocalizer * _Nonnull * _Nonnull Return);
void easyar_CloudLocalizer_resolve(easyar_CloudLocalizer * _Nonnull This, easyar_InputFrame * _Nonnull inputFrame, easyar_String * _Nonnull message, easyar_OptionalOfVec3F acceleration, easyar_OptionalOfVec3D location, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_FunctorOfVoidFromCloudLocalizeResult callback);
void easyar_CloudLocalizer_close(easyar_CloudLocalizer * _Nonnull This);
void easyar_CloudLocalizer__dtor(easyar_CloudLocalizer * _Nonnull This);
void easyar_CloudLocalizer__retain(const easyar_CloudLocalizer * _Nonnull This, /* OUT */ easyar_CloudLocalizer * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_CloudLocalizer__typeName(const easyar_CloudLocalizer * _Nonnull This);

int easyar_CloudRecognizationResult_getStatus(const easyar_CloudRecognizationResult * _Nonnull This);
void easyar_CloudRecognizationResult_getTarget(const easyar_CloudRecognizationResult * _Nonnull This, /* OUT */ easyar_OptionalOfImageTarget * _Nonnull Return);
void easyar_CloudRecognizationResult_getUnknownErrorMessage(const easyar_CloudRecognizationResult * _Nonnull This, /* OUT */ easyar_OptionalOfString * _Nonnull Return);
void easyar_CloudRecognizationResult__dtor(easyar_CloudRecognizationResult * _Nonnull This);
void easyar_CloudRecognizationResult__retain(const easyar_CloudRecognizationResult * _Nonnull This, /* OUT */ easyar_CloudRecognizationResult * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_CloudRecognizationResult__typeName(const easyar_CloudRecognizationResult * _Nonnull This);

bool easyar_CloudRecognizer_isAvailable();
void easyar_CloudRecognizer_create(easyar_String * _Nonnull cloudRecognitionServiceServerAddress, easyar_String * _Nonnull apiKey, easyar_String * _Nonnull apiSecret, easyar_String * _Nonnull cloudRecognitionServiceAppId, /* OUT */ easyar_CloudRecognizer * _Nonnull * _Nonnull Return);
void easyar_CloudRecognizer_createByCloudSecret(easyar_String * _Nonnull cloudRecognitionServiceServerAddress, easyar_String * _Nonnull cloudRecognitionServiceSecret, easyar_String * _Nonnull cloudRecognitionServiceAppId, /* OUT */ easyar_CloudRecognizer * _Nonnull * _Nonnull Return);
void easyar_CloudRecognizer_resolve(easyar_CloudRecognizer * _Nonnull This, easyar_InputFrame * _Nonnull inputFrame, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_FunctorOfVoidFromCloudRecognizationResult callback);
void easyar_CloudRecognizer_close(easyar_CloudRecognizer * _Nonnull This);
void easyar_CloudRecognizer__dtor(easyar_CloudRecognizer * _Nonnull This);
void easyar_CloudRecognizer__retain(const easyar_CloudRecognizer * _Nonnull This, /* OUT */ easyar_CloudRecognizer * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_CloudRecognizer__typeName(const easyar_CloudRecognizer * _Nonnull This);

void easyar_Buffer_wrap(easyar_Opaque * _Nullable ptr, int size, easyar_FunctorOfVoid deleter, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
void easyar_Buffer_create(int size, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
easyar_Opaque * _Nullable easyar_Buffer_data(const easyar_Buffer * _Nonnull This);
int easyar_Buffer_size(const easyar_Buffer * _Nonnull This);
void easyar_Buffer_memoryCopy(easyar_Opaque * _Nullable src, easyar_Opaque * _Nullable dest, int length);
bool easyar_Buffer_tryCopyFrom(easyar_Buffer * _Nonnull This, easyar_Opaque * _Nullable src, int srcIndex, int index, int length);
bool easyar_Buffer_tryCopyTo(easyar_Buffer * _Nonnull This, int index, easyar_Opaque * _Nullable dest, int destIndex, int length);
void easyar_Buffer_partition(easyar_Buffer * _Nonnull This, int index, int length, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
void easyar_Buffer__dtor(easyar_Buffer * _Nonnull This);
void easyar_Buffer__retain(const easyar_Buffer * _Nonnull This, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_Buffer__typeName(const easyar_Buffer * _Nonnull This);

void easyar_BufferDictionary__ctor(/* OUT */ easyar_BufferDictionary * _Nonnull * _Nonnull Return);
int easyar_BufferDictionary_count(const easyar_BufferDictionary * _Nonnull This);
bool easyar_BufferDictionary_contains(const easyar_BufferDictionary * _Nonnull This, easyar_String * _Nonnull path);
void easyar_BufferDictionary_tryGet(const easyar_BufferDictionary * _Nonnull This, easyar_String * _Nonnull path, /* OUT */ easyar_OptionalOfBuffer * _Nonnull Return);
void easyar_BufferDictionary_set(easyar_BufferDictionary * _Nonnull This, easyar_String * _Nonnull path, easyar_Buffer * _Nonnull buffer);
bool easyar_BufferDictionary_remove(easyar_BufferDictionary * _Nonnull This, easyar_String * _Nonnull path);
void easyar_BufferDictionary_clear(easyar_BufferDictionary * _Nonnull This);
void easyar_BufferDictionary__dtor(easyar_BufferDictionary * _Nonnull This);
void easyar_BufferDictionary__retain(const easyar_BufferDictionary * _Nonnull This, /* OUT */ easyar_BufferDictionary * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_BufferDictionary__typeName(const easyar_BufferDictionary * _Nonnull This);

void easyar_BufferPool__ctor(int block_size, int capacity, /* OUT */ easyar_BufferPool * _Nonnull * _Nonnull Return);
int easyar_BufferPool_block_size(const easyar_BufferPool * _Nonnull This);
int easyar_BufferPool_capacity(const easyar_BufferPool * _Nonnull This);
int easyar_BufferPool_size(const easyar_BufferPool * _Nonnull This);
void easyar_BufferPool_tryAcquire(easyar_BufferPool * _Nonnull This, /* OUT */ easyar_OptionalOfBuffer * _Nonnull Return);
void easyar_BufferPool__dtor(easyar_BufferPool * _Nonnull This);
void easyar_BufferPool__retain(const easyar_BufferPool * _Nonnull This, /* OUT */ easyar_BufferPool * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_BufferPool__typeName(const easyar_BufferPool * _Nonnull This);

void easyar_CameraParameters__ctor(easyar_Vec2I imageSize, easyar_Vec2F focalLength, easyar_Vec2F principalPoint, int cameraDeviceType, int cameraOrientation, /* OUT */ easyar_CameraParameters * _Nonnull * _Nonnull Return);
easyar_Vec2I easyar_CameraParameters_size(const easyar_CameraParameters * _Nonnull This);
easyar_Vec2F easyar_CameraParameters_focalLength(const easyar_CameraParameters * _Nonnull This);
easyar_Vec2F easyar_CameraParameters_principalPoint(const easyar_CameraParameters * _Nonnull This);
int easyar_CameraParameters_cameraDeviceType(const easyar_CameraParameters * _Nonnull This);
int easyar_CameraParameters_cameraOrientation(const easyar_CameraParameters * _Nonnull This);
void easyar_CameraParameters_createWithDefaultIntrinsics(easyar_Vec2I imageSize, int cameraDeviceType, int cameraOrientation, /* OUT */ easyar_CameraParameters * _Nonnull * _Nonnull Return);
void easyar_CameraParameters_getResized(easyar_CameraParameters * _Nonnull This, easyar_Vec2I imageSize, /* OUT */ easyar_CameraParameters * _Nonnull * _Nonnull Return);
int easyar_CameraParameters_imageOrientation(const easyar_CameraParameters * _Nonnull This, int screenRotation);
bool easyar_CameraParameters_imageHorizontalFlip(const easyar_CameraParameters * _Nonnull This, bool manualHorizontalFlip);
easyar_Matrix44F easyar_CameraParameters_projection(const easyar_CameraParameters * _Nonnull This, float nearPlane, float farPlane, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip);
easyar_Matrix44F easyar_CameraParameters_imageProjection(const easyar_CameraParameters * _Nonnull This, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip);
easyar_Vec2F easyar_CameraParameters_screenCoordinatesFromImageCoordinates(const easyar_CameraParameters * _Nonnull This, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, easyar_Vec2F imageCoordinates);
easyar_Vec2F easyar_CameraParameters_imageCoordinatesFromScreenCoordinates(const easyar_CameraParameters * _Nonnull This, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, easyar_Vec2F screenCoordinates);
bool easyar_CameraParameters_equalsTo(const easyar_CameraParameters * _Nonnull This, easyar_CameraParameters * _Nonnull other);
void easyar_CameraParameters__dtor(easyar_CameraParameters * _Nonnull This);
void easyar_CameraParameters__retain(const easyar_CameraParameters * _Nonnull This, /* OUT */ easyar_CameraParameters * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_CameraParameters__typeName(const easyar_CameraParameters * _Nonnull This);

void easyar_Image__ctor(easyar_Buffer * _Nonnull buffer, int format, int width, int height, /* OUT */ easyar_Image * _Nonnull * _Nonnull Return);
void easyar_Image_buffer(const easyar_Image * _Nonnull This, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
int easyar_Image_format(const easyar_Image * _Nonnull This);
int easyar_Image_width(const easyar_Image * _Nonnull This);
int easyar_Image_height(const easyar_Image * _Nonnull This);
void easyar_Image__dtor(easyar_Image * _Nonnull This);
void easyar_Image__retain(const easyar_Image * _Nonnull This, /* OUT */ easyar_Image * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_Image__typeName(const easyar_Image * _Nonnull This);

bool easyar_DenseSpatialMap_isAvailable();
void easyar_DenseSpatialMap_inputFrameSink(easyar_DenseSpatialMap * _Nonnull This, /* OUT */ easyar_InputFrameSink * _Nonnull * _Nonnull Return);
int easyar_DenseSpatialMap_bufferRequirement(easyar_DenseSpatialMap * _Nonnull This);
void easyar_DenseSpatialMap_create(/* OUT */ easyar_DenseSpatialMap * _Nonnull * _Nonnull Return);
bool easyar_DenseSpatialMap_start(easyar_DenseSpatialMap * _Nonnull This);
void easyar_DenseSpatialMap_stop(easyar_DenseSpatialMap * _Nonnull This);
void easyar_DenseSpatialMap_close(easyar_DenseSpatialMap * _Nonnull This);
void easyar_DenseSpatialMap_getMesh(easyar_DenseSpatialMap * _Nonnull This, /* OUT */ easyar_SceneMesh * _Nonnull * _Nonnull Return);
bool easyar_DenseSpatialMap_updateSceneMesh(easyar_DenseSpatialMap * _Nonnull This, bool updateMeshAll);
void easyar_DenseSpatialMap__dtor(easyar_DenseSpatialMap * _Nonnull This);
void easyar_DenseSpatialMap__retain(const easyar_DenseSpatialMap * _Nonnull This, /* OUT */ easyar_DenseSpatialMap * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_DenseSpatialMap__typeName(const easyar_DenseSpatialMap * _Nonnull This);

int easyar_SceneMesh_getNumOfVertexAll(easyar_SceneMesh * _Nonnull This);
int easyar_SceneMesh_getNumOfIndexAll(easyar_SceneMesh * _Nonnull This);
void easyar_SceneMesh_getVerticesAll(easyar_SceneMesh * _Nonnull This, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
void easyar_SceneMesh_getNormalsAll(easyar_SceneMesh * _Nonnull This, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
void easyar_SceneMesh_getIndicesAll(easyar_SceneMesh * _Nonnull This, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
int easyar_SceneMesh_getNumOfVertexIncremental(easyar_SceneMesh * _Nonnull This);
int easyar_SceneMesh_getNumOfIndexIncremental(easyar_SceneMesh * _Nonnull This);
void easyar_SceneMesh_getVerticesIncremental(easyar_SceneMesh * _Nonnull This, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
void easyar_SceneMesh_getNormalsIncremental(easyar_SceneMesh * _Nonnull This, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
void easyar_SceneMesh_getIndicesIncremental(easyar_SceneMesh * _Nonnull This, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
void easyar_SceneMesh_getBlocksInfoIncremental(easyar_SceneMesh * _Nonnull This, /* OUT */ easyar_ListOfBlockInfo * _Nonnull * _Nonnull Return);
float easyar_SceneMesh_getBlockDimensionInMeters(easyar_SceneMesh * _Nonnull This);
void easyar_SceneMesh__dtor(easyar_SceneMesh * _Nonnull This);
void easyar_SceneMesh__retain(const easyar_SceneMesh * _Nonnull This, /* OUT */ easyar_SceneMesh * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_SceneMesh__typeName(const easyar_SceneMesh * _Nonnull This);

void easyar_Accelerometer__ctor(/* OUT */ easyar_Accelerometer * _Nonnull * _Nonnull Return);
bool easyar_Accelerometer_isAvailable(easyar_Accelerometer * _Nonnull This);
bool easyar_Accelerometer_open(easyar_Accelerometer * _Nonnull This);
bool easyar_Accelerometer_openWithSamplingPeriod(easyar_Accelerometer * _Nonnull This, int samplingPeriodMilliseconds);
void easyar_Accelerometer_close(easyar_Accelerometer * _Nonnull This);
easyar_OptionalOfAccelerometerResult easyar_Accelerometer_getCurrentResult(easyar_Accelerometer * _Nonnull This);
void easyar_Accelerometer__dtor(easyar_Accelerometer * _Nonnull This);
void easyar_Accelerometer__retain(const easyar_Accelerometer * _Nonnull This, /* OUT */ easyar_Accelerometer * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_Accelerometer__typeName(const easyar_Accelerometer * _Nonnull This);

void easyar_ARCoreCameraDevice__ctor(/* OUT */ easyar_ARCoreCameraDevice * _Nonnull * _Nonnull Return);
bool easyar_ARCoreCameraDevice_isAvailable();
int easyar_ARCoreCameraDevice_bufferCapacity(const easyar_ARCoreCameraDevice * _Nonnull This);
void easyar_ARCoreCameraDevice_setBufferCapacity(easyar_ARCoreCameraDevice * _Nonnull This, int capacity);
void easyar_ARCoreCameraDevice_inputFrameSource(easyar_ARCoreCameraDevice * _Nonnull This, /* OUT */ easyar_InputFrameSource * _Nonnull * _Nonnull Return);
void easyar_ARCoreCameraDevice_setFocusMode(easyar_ARCoreCameraDevice * _Nonnull This, int focusMode);
bool easyar_ARCoreCameraDevice_start(easyar_ARCoreCameraDevice * _Nonnull This);
void easyar_ARCoreCameraDevice_stop(easyar_ARCoreCameraDevice * _Nonnull This);
void easyar_ARCoreCameraDevice_close(easyar_ARCoreCameraDevice * _Nonnull This);
void easyar_ARCoreCameraDevice__dtor(easyar_ARCoreCameraDevice * _Nonnull This);
void easyar_ARCoreCameraDevice__retain(const easyar_ARCoreCameraDevice * _Nonnull This, /* OUT */ easyar_ARCoreCameraDevice * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ARCoreCameraDevice__typeName(const easyar_ARCoreCameraDevice * _Nonnull This);

void easyar_ARKitCameraDevice__ctor(/* OUT */ easyar_ARKitCameraDevice * _Nonnull * _Nonnull Return);
bool easyar_ARKitCameraDevice_isAvailable();
int easyar_ARKitCameraDevice_bufferCapacity(const easyar_ARKitCameraDevice * _Nonnull This);
void easyar_ARKitCameraDevice_setBufferCapacity(easyar_ARKitCameraDevice * _Nonnull This, int capacity);
void easyar_ARKitCameraDevice_inputFrameSource(easyar_ARKitCameraDevice * _Nonnull This, /* OUT */ easyar_InputFrameSource * _Nonnull * _Nonnull Return);
void easyar_ARKitCameraDevice_setFocusMode(easyar_ARKitCameraDevice * _Nonnull This, int focusMode);
bool easyar_ARKitCameraDevice_start(easyar_ARKitCameraDevice * _Nonnull This);
void easyar_ARKitCameraDevice_stop(easyar_ARKitCameraDevice * _Nonnull This);
void easyar_ARKitCameraDevice_close(easyar_ARKitCameraDevice * _Nonnull This);
void easyar_ARKitCameraDevice__dtor(easyar_ARKitCameraDevice * _Nonnull This);
void easyar_ARKitCameraDevice__retain(const easyar_ARKitCameraDevice * _Nonnull This, /* OUT */ easyar_ARKitCameraDevice * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ARKitCameraDevice__typeName(const easyar_ARKitCameraDevice * _Nonnull This);

void easyar_CameraDevice__ctor(/* OUT */ easyar_CameraDevice * _Nonnull * _Nonnull Return);
bool easyar_CameraDevice_isAvailable();
int easyar_CameraDevice_androidCameraApiType(easyar_CameraDevice * _Nonnull This);
void easyar_CameraDevice_setAndroidCameraApiType(easyar_CameraDevice * _Nonnull This, int type);
int easyar_CameraDevice_bufferCapacity(const easyar_CameraDevice * _Nonnull This);
void easyar_CameraDevice_setBufferCapacity(easyar_CameraDevice * _Nonnull This, int capacity);
void easyar_CameraDevice_inputFrameSource(easyar_CameraDevice * _Nonnull This, /* OUT */ easyar_InputFrameSource * _Nonnull * _Nonnull Return);
void easyar_CameraDevice_setStateChangedCallback(easyar_CameraDevice * _Nonnull This, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_OptionalOfFunctorOfVoidFromCameraState stateChangedCallback);
void easyar_CameraDevice_requestPermissions(easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString permissionCallback);
int easyar_CameraDevice_cameraCount();
bool easyar_CameraDevice_openWithIndex(easyar_CameraDevice * _Nonnull This, int cameraIndex);
bool easyar_CameraDevice_openWithSpecificType(easyar_CameraDevice * _Nonnull This, int type);
bool easyar_CameraDevice_openWithPreferredType(easyar_CameraDevice * _Nonnull This, int type);
bool easyar_CameraDevice_start(easyar_CameraDevice * _Nonnull This);
void easyar_CameraDevice_stop(easyar_CameraDevice * _Nonnull This);
void easyar_CameraDevice_close(easyar_CameraDevice * _Nonnull This);
int easyar_CameraDevice_index(const easyar_CameraDevice * _Nonnull This);
int easyar_CameraDevice_type(const easyar_CameraDevice * _Nonnull This);
void easyar_CameraDevice_cameraParameters(easyar_CameraDevice * _Nonnull This, /* OUT */ easyar_CameraParameters * _Nonnull * _Nonnull Return);
void easyar_CameraDevice_setCameraParameters(easyar_CameraDevice * _Nonnull This, easyar_CameraParameters * _Nonnull cameraParameters);
easyar_Vec2I easyar_CameraDevice_size(const easyar_CameraDevice * _Nonnull This);
int easyar_CameraDevice_supportedSizeCount(const easyar_CameraDevice * _Nonnull This);
easyar_Vec2I easyar_CameraDevice_supportedSize(const easyar_CameraDevice * _Nonnull This, int index);
bool easyar_CameraDevice_setSize(easyar_CameraDevice * _Nonnull This, easyar_Vec2I size);
int easyar_CameraDevice_supportedFrameRateRangeCount(const easyar_CameraDevice * _Nonnull This);
float easyar_CameraDevice_supportedFrameRateRangeLower(const easyar_CameraDevice * _Nonnull This, int index);
float easyar_CameraDevice_supportedFrameRateRangeUpper(const easyar_CameraDevice * _Nonnull This, int index);
int easyar_CameraDevice_frameRateRange(const easyar_CameraDevice * _Nonnull This);
bool easyar_CameraDevice_setFrameRateRange(easyar_CameraDevice * _Nonnull This, int index);
bool easyar_CameraDevice_setFlashTorchMode(easyar_CameraDevice * _Nonnull This, bool on);
bool easyar_CameraDevice_setFocusMode(easyar_CameraDevice * _Nonnull This, int focusMode);
bool easyar_CameraDevice_autoFocus(easyar_CameraDevice * _Nonnull This);
void easyar_CameraDevice__dtor(easyar_CameraDevice * _Nonnull This);
void easyar_CameraDevice__retain(const easyar_CameraDevice * _Nonnull This, /* OUT */ easyar_CameraDevice * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_CameraDevice__typeName(const easyar_CameraDevice * _Nonnull This);

int easyar_CameraDeviceSelector_getAndroidCameraApiType(int preference);
void easyar_CameraDeviceSelector_createCameraDevice(int preference, /* OUT */ easyar_CameraDevice * _Nonnull * _Nonnull Return);
int easyar_CameraDeviceSelector_getFocusMode(int preference);

easyar_Matrix44F easyar_SurfaceTrackerResult_transform(const easyar_SurfaceTrackerResult * _Nonnull This);
void easyar_SurfaceTrackerResult__dtor(easyar_SurfaceTrackerResult * _Nonnull This);
void easyar_SurfaceTrackerResult__retain(const easyar_SurfaceTrackerResult * _Nonnull This, /* OUT */ easyar_SurfaceTrackerResult * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_SurfaceTrackerResult__typeName(const easyar_SurfaceTrackerResult * _Nonnull This);
void easyar_castSurfaceTrackerResultToFrameFilterResult(const easyar_SurfaceTrackerResult * _Nonnull This, /* OUT */ easyar_FrameFilterResult * _Nonnull * _Nonnull Return);
void easyar_tryCastFrameFilterResultToSurfaceTrackerResult(const easyar_FrameFilterResult * _Nonnull This, /* OUT */ easyar_SurfaceTrackerResult * _Nonnull * _Nonnull Return);

bool easyar_SurfaceTracker_isAvailable();
void easyar_SurfaceTracker_inputFrameSink(easyar_SurfaceTracker * _Nonnull This, /* OUT */ easyar_InputFrameSink * _Nonnull * _Nonnull Return);
int easyar_SurfaceTracker_bufferRequirement(easyar_SurfaceTracker * _Nonnull This);
void easyar_SurfaceTracker_outputFrameSource(easyar_SurfaceTracker * _Nonnull This, /* OUT */ easyar_OutputFrameSource * _Nonnull * _Nonnull Return);
void easyar_SurfaceTracker_create(/* OUT */ easyar_SurfaceTracker * _Nonnull * _Nonnull Return);
bool easyar_SurfaceTracker_start(easyar_SurfaceTracker * _Nonnull This);
void easyar_SurfaceTracker_stop(easyar_SurfaceTracker * _Nonnull This);
void easyar_SurfaceTracker_close(easyar_SurfaceTracker * _Nonnull This);
void easyar_SurfaceTracker_alignTargetToCameraImagePoint(easyar_SurfaceTracker * _Nonnull This, easyar_Vec2F cameraImagePoint);
void easyar_SurfaceTracker__dtor(easyar_SurfaceTracker * _Nonnull This);
void easyar_SurfaceTracker__retain(const easyar_SurfaceTracker * _Nonnull This, /* OUT */ easyar_SurfaceTracker * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_SurfaceTracker__typeName(const easyar_SurfaceTracker * _Nonnull This);

void easyar_MotionTrackerCameraDevice__ctor(/* OUT */ easyar_MotionTrackerCameraDevice * _Nonnull * _Nonnull Return);
bool easyar_MotionTrackerCameraDevice_isAvailable();
int easyar_MotionTrackerCameraDevice_getQualityLevel();
bool easyar_MotionTrackerCameraDevice_setFrameRateType(easyar_MotionTrackerCameraDevice * _Nonnull This, int fps);
bool easyar_MotionTrackerCameraDevice_setFocusMode(easyar_MotionTrackerCameraDevice * _Nonnull This, int focusMode);
bool easyar_MotionTrackerCameraDevice_setFrameResolutionType(easyar_MotionTrackerCameraDevice * _Nonnull This, int resolution);
bool easyar_MotionTrackerCameraDevice_setTrackingMode(easyar_MotionTrackerCameraDevice * _Nonnull This, int trackingMode);
void easyar_MotionTrackerCameraDevice_setBufferCapacity(easyar_MotionTrackerCameraDevice * _Nonnull This, int capacity);
int easyar_MotionTrackerCameraDevice_bufferCapacity(const easyar_MotionTrackerCameraDevice * _Nonnull This);
void easyar_MotionTrackerCameraDevice_inputFrameSource(easyar_MotionTrackerCameraDevice * _Nonnull This, /* OUT */ easyar_InputFrameSource * _Nonnull * _Nonnull Return);
bool easyar_MotionTrackerCameraDevice_start(easyar_MotionTrackerCameraDevice * _Nonnull This);
void easyar_MotionTrackerCameraDevice_stop(easyar_MotionTrackerCameraDevice * _Nonnull This);
void easyar_MotionTrackerCameraDevice_close(easyar_MotionTrackerCameraDevice * _Nonnull This);
void easyar_MotionTrackerCameraDevice_hitTestAgainstPointCloud(easyar_MotionTrackerCameraDevice * _Nonnull This, easyar_Vec2F cameraImagePoint, /* OUT */ easyar_ListOfVec3F * _Nonnull * _Nonnull Return);
void easyar_MotionTrackerCameraDevice_hitTestAgainstHorizontalPlane(easyar_MotionTrackerCameraDevice * _Nonnull This, easyar_Vec2F cameraImagePoint, /* OUT */ easyar_ListOfVec3F * _Nonnull * _Nonnull Return);
void easyar_MotionTrackerCameraDevice_getLocalPointsCloud(easyar_MotionTrackerCameraDevice * _Nonnull This, /* OUT */ easyar_ListOfVec3F * _Nonnull * _Nonnull Return);
void easyar_MotionTrackerCameraDevice__dtor(easyar_MotionTrackerCameraDevice * _Nonnull This);
void easyar_MotionTrackerCameraDevice__retain(const easyar_MotionTrackerCameraDevice * _Nonnull This, /* OUT */ easyar_MotionTrackerCameraDevice * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_MotionTrackerCameraDevice__typeName(const easyar_MotionTrackerCameraDevice * _Nonnull This);

void easyar_InputFrameRecorder_input(easyar_InputFrameRecorder * _Nonnull This, /* OUT */ easyar_InputFrameSink * _Nonnull * _Nonnull Return);
int easyar_InputFrameRecorder_bufferRequirement(easyar_InputFrameRecorder * _Nonnull This);
void easyar_InputFrameRecorder_output(easyar_InputFrameRecorder * _Nonnull This, /* OUT */ easyar_InputFrameSource * _Nonnull * _Nonnull Return);
void easyar_InputFrameRecorder_create(/* OUT */ easyar_InputFrameRecorder * _Nonnull * _Nonnull Return);
bool easyar_InputFrameRecorder_start(easyar_InputFrameRecorder * _Nonnull This, easyar_String * _Nonnull filePath, int initialScreenRotation);
void easyar_InputFrameRecorder_stop(easyar_InputFrameRecorder * _Nonnull This);
void easyar_InputFrameRecorder__dtor(easyar_InputFrameRecorder * _Nonnull This);
void easyar_InputFrameRecorder__retain(const easyar_InputFrameRecorder * _Nonnull This, /* OUT */ easyar_InputFrameRecorder * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_InputFrameRecorder__typeName(const easyar_InputFrameRecorder * _Nonnull This);

void easyar_InputFramePlayer_output(easyar_InputFramePlayer * _Nonnull This, /* OUT */ easyar_InputFrameSource * _Nonnull * _Nonnull Return);
void easyar_InputFramePlayer_create(/* OUT */ easyar_InputFramePlayer * _Nonnull * _Nonnull Return);
bool easyar_InputFramePlayer_start(easyar_InputFramePlayer * _Nonnull This, easyar_String * _Nonnull filePath);
void easyar_InputFramePlayer_stop(easyar_InputFramePlayer * _Nonnull This);
void easyar_InputFramePlayer_pause(easyar_InputFramePlayer * _Nonnull This);
bool easyar_InputFramePlayer_resume(easyar_InputFramePlayer * _Nonnull This);
double easyar_InputFramePlayer_totalTime(easyar_InputFramePlayer * _Nonnull This);
double easyar_InputFramePlayer_currentTime(easyar_InputFramePlayer * _Nonnull This);
int easyar_InputFramePlayer_initalScreenRotation(easyar_InputFramePlayer * _Nonnull This);
bool easyar_InputFramePlayer_isCompleted(easyar_InputFramePlayer * _Nonnull This);
void easyar_InputFramePlayer__dtor(easyar_InputFramePlayer * _Nonnull This);
void easyar_InputFramePlayer__retain(const easyar_InputFramePlayer * _Nonnull This, /* OUT */ easyar_InputFramePlayer * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_InputFramePlayer__typeName(const easyar_InputFramePlayer * _Nonnull This);

void easyar_CallbackScheduler__dtor(easyar_CallbackScheduler * _Nonnull This);
void easyar_CallbackScheduler__retain(const easyar_CallbackScheduler * _Nonnull This, /* OUT */ easyar_CallbackScheduler * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_CallbackScheduler__typeName(const easyar_CallbackScheduler * _Nonnull This);

void easyar_DelayedCallbackScheduler__ctor(/* OUT */ easyar_DelayedCallbackScheduler * _Nonnull * _Nonnull Return);
bool easyar_DelayedCallbackScheduler_runOne(easyar_DelayedCallbackScheduler * _Nonnull This);
void easyar_DelayedCallbackScheduler__dtor(easyar_DelayedCallbackScheduler * _Nonnull This);
void easyar_DelayedCallbackScheduler__retain(const easyar_DelayedCallbackScheduler * _Nonnull This, /* OUT */ easyar_DelayedCallbackScheduler * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_DelayedCallbackScheduler__typeName(const easyar_DelayedCallbackScheduler * _Nonnull This);
void easyar_castDelayedCallbackSchedulerToCallbackScheduler(const easyar_DelayedCallbackScheduler * _Nonnull This, /* OUT */ easyar_CallbackScheduler * _Nonnull * _Nonnull Return);
void easyar_tryCastCallbackSchedulerToDelayedCallbackScheduler(const easyar_CallbackScheduler * _Nonnull This, /* OUT */ easyar_DelayedCallbackScheduler * _Nonnull * _Nonnull Return);

void easyar_ImmediateCallbackScheduler_getDefault(/* OUT */ easyar_ImmediateCallbackScheduler * _Nonnull * _Nonnull Return);
void easyar_ImmediateCallbackScheduler__dtor(easyar_ImmediateCallbackScheduler * _Nonnull This);
void easyar_ImmediateCallbackScheduler__retain(const easyar_ImmediateCallbackScheduler * _Nonnull This, /* OUT */ easyar_ImmediateCallbackScheduler * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ImmediateCallbackScheduler__typeName(const easyar_ImmediateCallbackScheduler * _Nonnull This);
void easyar_castImmediateCallbackSchedulerToCallbackScheduler(const easyar_ImmediateCallbackScheduler * _Nonnull This, /* OUT */ easyar_CallbackScheduler * _Nonnull * _Nonnull Return);
void easyar_tryCastCallbackSchedulerToImmediateCallbackScheduler(const easyar_CallbackScheduler * _Nonnull This, /* OUT */ easyar_ImmediateCallbackScheduler * _Nonnull * _Nonnull Return);

void easyar_JniUtility_wrapByteArray(easyar_Opaque * _Nullable bytes, bool readOnly, easyar_FunctorOfVoid deleter, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
void easyar_JniUtility_wrapBuffer(easyar_Opaque * _Nullable directBuffer, easyar_FunctorOfVoid deleter, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
easyar_Opaque * _Nullable easyar_JniUtility_getDirectBufferAddress(easyar_Opaque * _Nullable directBuffer);

void easyar_Log_setLogFunc(easyar_FunctorOfVoidFromLogLevelAndString func);
void easyar_Log_setLogFuncWithScheduler(easyar_CallbackScheduler * _Nonnull scheduler, easyar_FunctorOfVoidFromLogLevelAndString func);
void easyar_Log_resetLogFunc();

void easyar_Storage_setAssetDirPath(easyar_String * _Nonnull path);

void easyar_ImageTargetParameters__ctor(/* OUT */ easyar_ImageTargetParameters * _Nonnull * _Nonnull Return);
void easyar_ImageTargetParameters_image(easyar_ImageTargetParameters * _Nonnull This, /* OUT */ easyar_Image * _Nonnull * _Nonnull Return);
void easyar_ImageTargetParameters_setImage(easyar_ImageTargetParameters * _Nonnull This, easyar_Image * _Nonnull image);
void easyar_ImageTargetParameters_name(easyar_ImageTargetParameters * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ImageTargetParameters_setName(easyar_ImageTargetParameters * _Nonnull This, easyar_String * _Nonnull name);
void easyar_ImageTargetParameters_uid(easyar_ImageTargetParameters * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ImageTargetParameters_setUid(easyar_ImageTargetParameters * _Nonnull This, easyar_String * _Nonnull uid);
void easyar_ImageTargetParameters_meta(easyar_ImageTargetParameters * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ImageTargetParameters_setMeta(easyar_ImageTargetParameters * _Nonnull This, easyar_String * _Nonnull meta);
float easyar_ImageTargetParameters_scale(easyar_ImageTargetParameters * _Nonnull This);
void easyar_ImageTargetParameters_setScale(easyar_ImageTargetParameters * _Nonnull This, float scale);
void easyar_ImageTargetParameters__dtor(easyar_ImageTargetParameters * _Nonnull This);
void easyar_ImageTargetParameters__retain(const easyar_ImageTargetParameters * _Nonnull This, /* OUT */ easyar_ImageTargetParameters * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ImageTargetParameters__typeName(const easyar_ImageTargetParameters * _Nonnull This);

void easyar_ImageTarget__ctor(/* OUT */ easyar_ImageTarget * _Nonnull * _Nonnull Return);
void easyar_ImageTarget_createFromParameters(easyar_ImageTargetParameters * _Nonnull parameters, /* OUT */ easyar_OptionalOfImageTarget * _Nonnull Return);
void easyar_ImageTarget_createFromTargetFile(easyar_String * _Nonnull path, int storageType, /* OUT */ easyar_OptionalOfImageTarget * _Nonnull Return);
void easyar_ImageTarget_createFromTargetData(easyar_Buffer * _Nonnull buffer, /* OUT */ easyar_OptionalOfImageTarget * _Nonnull Return);
bool easyar_ImageTarget_save(easyar_ImageTarget * _Nonnull This, easyar_String * _Nonnull path);
void easyar_ImageTarget_createFromImageFile(easyar_String * _Nonnull path, int storageType, easyar_String * _Nonnull name, easyar_String * _Nonnull uid, easyar_String * _Nonnull meta, float scale, /* OUT */ easyar_OptionalOfImageTarget * _Nonnull Return);
float easyar_ImageTarget_scale(const easyar_ImageTarget * _Nonnull This);
float easyar_ImageTarget_aspectRatio(const easyar_ImageTarget * _Nonnull This);
bool easyar_ImageTarget_setScale(easyar_ImageTarget * _Nonnull This, float scale);
void easyar_ImageTarget_images(easyar_ImageTarget * _Nonnull This, /* OUT */ easyar_ListOfImage * _Nonnull * _Nonnull Return);
int easyar_ImageTarget_runtimeID(const easyar_ImageTarget * _Nonnull This);
void easyar_ImageTarget_uid(const easyar_ImageTarget * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ImageTarget_name(const easyar_ImageTarget * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ImageTarget_setName(easyar_ImageTarget * _Nonnull This, easyar_String * _Nonnull name);
void easyar_ImageTarget_meta(const easyar_ImageTarget * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_ImageTarget_setMeta(easyar_ImageTarget * _Nonnull This, easyar_String * _Nonnull data);
void easyar_ImageTarget__dtor(easyar_ImageTarget * _Nonnull This);
void easyar_ImageTarget__retain(const easyar_ImageTarget * _Nonnull This, /* OUT */ easyar_ImageTarget * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ImageTarget__typeName(const easyar_ImageTarget * _Nonnull This);
void easyar_castImageTargetToTarget(const easyar_ImageTarget * _Nonnull This, /* OUT */ easyar_Target * _Nonnull * _Nonnull Return);
void easyar_tryCastTargetToImageTarget(const easyar_Target * _Nonnull This, /* OUT */ easyar_ImageTarget * _Nonnull * _Nonnull Return);

void easyar_ImageTrackerResult_targetInstances(const easyar_ImageTrackerResult * _Nonnull This, /* OUT */ easyar_ListOfTargetInstance * _Nonnull * _Nonnull Return);
void easyar_ImageTrackerResult_setTargetInstances(easyar_ImageTrackerResult * _Nonnull This, easyar_ListOfTargetInstance * _Nonnull instances);
void easyar_ImageTrackerResult__dtor(easyar_ImageTrackerResult * _Nonnull This);
void easyar_ImageTrackerResult__retain(const easyar_ImageTrackerResult * _Nonnull This, /* OUT */ easyar_ImageTrackerResult * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ImageTrackerResult__typeName(const easyar_ImageTrackerResult * _Nonnull This);
void easyar_castImageTrackerResultToFrameFilterResult(const easyar_ImageTrackerResult * _Nonnull This, /* OUT */ easyar_FrameFilterResult * _Nonnull * _Nonnull Return);
void easyar_tryCastFrameFilterResultToImageTrackerResult(const easyar_FrameFilterResult * _Nonnull This, /* OUT */ easyar_ImageTrackerResult * _Nonnull * _Nonnull Return);
void easyar_castImageTrackerResultToTargetTrackerResult(const easyar_ImageTrackerResult * _Nonnull This, /* OUT */ easyar_TargetTrackerResult * _Nonnull * _Nonnull Return);
void easyar_tryCastTargetTrackerResultToImageTrackerResult(const easyar_TargetTrackerResult * _Nonnull This, /* OUT */ easyar_ImageTrackerResult * _Nonnull * _Nonnull Return);

bool easyar_ImageTracker_isAvailable();
void easyar_ImageTracker_feedbackFrameSink(easyar_ImageTracker * _Nonnull This, /* OUT */ easyar_FeedbackFrameSink * _Nonnull * _Nonnull Return);
int easyar_ImageTracker_bufferRequirement(easyar_ImageTracker * _Nonnull This);
void easyar_ImageTracker_outputFrameSource(easyar_ImageTracker * _Nonnull This, /* OUT */ easyar_OutputFrameSource * _Nonnull * _Nonnull Return);
void easyar_ImageTracker_create(/* OUT */ easyar_ImageTracker * _Nonnull * _Nonnull Return);
void easyar_ImageTracker_createWithMode(int trackMode, /* OUT */ easyar_ImageTracker * _Nonnull * _Nonnull Return);
bool easyar_ImageTracker_start(easyar_ImageTracker * _Nonnull This);
void easyar_ImageTracker_stop(easyar_ImageTracker * _Nonnull This);
void easyar_ImageTracker_close(easyar_ImageTracker * _Nonnull This);
void easyar_ImageTracker_loadTarget(easyar_ImageTracker * _Nonnull This, easyar_Target * _Nonnull target, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_FunctorOfVoidFromTargetAndBool callback);
void easyar_ImageTracker_unloadTarget(easyar_ImageTracker * _Nonnull This, easyar_Target * _Nonnull target, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_FunctorOfVoidFromTargetAndBool callback);
void easyar_ImageTracker_targets(const easyar_ImageTracker * _Nonnull This, /* OUT */ easyar_ListOfTarget * _Nonnull * _Nonnull Return);
bool easyar_ImageTracker_setSimultaneousNum(easyar_ImageTracker * _Nonnull This, int num);
int easyar_ImageTracker_simultaneousNum(const easyar_ImageTracker * _Nonnull This);
void easyar_ImageTracker__dtor(easyar_ImageTracker * _Nonnull This);
void easyar_ImageTracker__retain(const easyar_ImageTracker * _Nonnull This, /* OUT */ easyar_ImageTracker * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_ImageTracker__typeName(const easyar_ImageTracker * _Nonnull This);

void easyar_RealTimeCoordinateTransform__ctor(/* OUT */ easyar_RealTimeCoordinateTransform * _Nonnull * _Nonnull Return);
void easyar_RealTimeCoordinateTransform_setBufferSize(easyar_RealTimeCoordinateTransform * _Nonnull This, int capacity);
int easyar_RealTimeCoordinateTransform_getBufferSize(const easyar_RealTimeCoordinateTransform * _Nonnull This);
bool easyar_RealTimeCoordinateTransform_insertData(easyar_RealTimeCoordinateTransform * _Nonnull This, double timestamp, easyar_Matrix44F localTwc, easyar_Matrix44F mapTcw);
easyar_Matrix44F easyar_RealTimeCoordinateTransform_getPoseInMap(easyar_RealTimeCoordinateTransform * _Nonnull This, double timestamp, int status, easyar_Matrix44F localTwc);
void easyar_RealTimeCoordinateTransform__dtor(easyar_RealTimeCoordinateTransform * _Nonnull This);
void easyar_RealTimeCoordinateTransform__retain(const easyar_RealTimeCoordinateTransform * _Nonnull This, /* OUT */ easyar_RealTimeCoordinateTransform * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_RealTimeCoordinateTransform__typeName(const easyar_RealTimeCoordinateTransform * _Nonnull This);

bool easyar_Recorder_isAvailable();
void easyar_Recorder_requestPermissions(easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString permissionCallback);
void easyar_Recorder_create(easyar_RecorderConfiguration * _Nonnull config, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_OptionalOfFunctorOfVoidFromRecordStatusAndString statusCallback, /* OUT */ easyar_Recorder * _Nonnull * _Nonnull Return);
void easyar_Recorder_start(easyar_Recorder * _Nonnull This);
void easyar_Recorder_updateFrame(easyar_Recorder * _Nonnull This, easyar_TextureId * _Nonnull texture, int width, int height);
bool easyar_Recorder_stop(easyar_Recorder * _Nonnull This);
void easyar_Recorder__dtor(easyar_Recorder * _Nonnull This);
void easyar_Recorder__retain(const easyar_Recorder * _Nonnull This, /* OUT */ easyar_Recorder * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_Recorder__typeName(const easyar_Recorder * _Nonnull This);

void easyar_RecorderConfiguration__ctor(/* OUT */ easyar_RecorderConfiguration * _Nonnull * _Nonnull Return);
void easyar_RecorderConfiguration_setOutputFile(easyar_RecorderConfiguration * _Nonnull This, easyar_String * _Nonnull path);
bool easyar_RecorderConfiguration_setProfile(easyar_RecorderConfiguration * _Nonnull This, int profile);
void easyar_RecorderConfiguration_setVideoSize(easyar_RecorderConfiguration * _Nonnull This, int framesize);
void easyar_RecorderConfiguration_setVideoBitrate(easyar_RecorderConfiguration * _Nonnull This, int bitrate);
void easyar_RecorderConfiguration_setChannelCount(easyar_RecorderConfiguration * _Nonnull This, int count);
void easyar_RecorderConfiguration_setAudioSampleRate(easyar_RecorderConfiguration * _Nonnull This, int samplerate);
void easyar_RecorderConfiguration_setAudioBitrate(easyar_RecorderConfiguration * _Nonnull This, int bitrate);
void easyar_RecorderConfiguration_setVideoOrientation(easyar_RecorderConfiguration * _Nonnull This, int mode);
void easyar_RecorderConfiguration_setZoomMode(easyar_RecorderConfiguration * _Nonnull This, int mode);
void easyar_RecorderConfiguration__dtor(easyar_RecorderConfiguration * _Nonnull This);
void easyar_RecorderConfiguration__retain(const easyar_RecorderConfiguration * _Nonnull This, /* OUT */ easyar_RecorderConfiguration * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_RecorderConfiguration__typeName(const easyar_RecorderConfiguration * _Nonnull This);

int easyar_SparseSpatialMapResult_getMotionTrackingStatus(const easyar_SparseSpatialMapResult * _Nonnull This);
easyar_OptionalOfMatrix44F easyar_SparseSpatialMapResult_getVioPose(const easyar_SparseSpatialMapResult * _Nonnull This);
easyar_OptionalOfMatrix44F easyar_SparseSpatialMapResult_getMapPose(const easyar_SparseSpatialMapResult * _Nonnull This);
bool easyar_SparseSpatialMapResult_getLocalizationStatus(const easyar_SparseSpatialMapResult * _Nonnull This);
void easyar_SparseSpatialMapResult_getLocalizationMapID(const easyar_SparseSpatialMapResult * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_SparseSpatialMapResult__dtor(easyar_SparseSpatialMapResult * _Nonnull This);
void easyar_SparseSpatialMapResult__retain(const easyar_SparseSpatialMapResult * _Nonnull This, /* OUT */ easyar_SparseSpatialMapResult * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_SparseSpatialMapResult__typeName(const easyar_SparseSpatialMapResult * _Nonnull This);
void easyar_castSparseSpatialMapResultToFrameFilterResult(const easyar_SparseSpatialMapResult * _Nonnull This, /* OUT */ easyar_FrameFilterResult * _Nonnull * _Nonnull Return);
void easyar_tryCastFrameFilterResultToSparseSpatialMapResult(const easyar_FrameFilterResult * _Nonnull This, /* OUT */ easyar_SparseSpatialMapResult * _Nonnull * _Nonnull Return);

void easyar_PlaneData__ctor(/* OUT */ easyar_PlaneData * _Nonnull * _Nonnull Return);
int easyar_PlaneData_getType(const easyar_PlaneData * _Nonnull This);
easyar_Matrix44F easyar_PlaneData_getPose(const easyar_PlaneData * _Nonnull This);
float easyar_PlaneData_getExtentX(const easyar_PlaneData * _Nonnull This);
float easyar_PlaneData_getExtentZ(const easyar_PlaneData * _Nonnull This);
void easyar_PlaneData__dtor(easyar_PlaneData * _Nonnull This);
void easyar_PlaneData__retain(const easyar_PlaneData * _Nonnull This, /* OUT */ easyar_PlaneData * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_PlaneData__typeName(const easyar_PlaneData * _Nonnull This);

void easyar_SparseSpatialMapConfig__ctor(/* OUT */ easyar_SparseSpatialMapConfig * _Nonnull * _Nonnull Return);
void easyar_SparseSpatialMapConfig_setLocalizationMode(easyar_SparseSpatialMapConfig * _Nonnull This, int _value);
int easyar_SparseSpatialMapConfig_getLocalizationMode(const easyar_SparseSpatialMapConfig * _Nonnull This);
void easyar_SparseSpatialMapConfig__dtor(easyar_SparseSpatialMapConfig * _Nonnull This);
void easyar_SparseSpatialMapConfig__retain(const easyar_SparseSpatialMapConfig * _Nonnull This, /* OUT */ easyar_SparseSpatialMapConfig * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_SparseSpatialMapConfig__typeName(const easyar_SparseSpatialMapConfig * _Nonnull This);

bool easyar_SparseSpatialMap_isAvailable();
void easyar_SparseSpatialMap_inputFrameSink(easyar_SparseSpatialMap * _Nonnull This, /* OUT */ easyar_InputFrameSink * _Nonnull * _Nonnull Return);
int easyar_SparseSpatialMap_bufferRequirement(easyar_SparseSpatialMap * _Nonnull This);
void easyar_SparseSpatialMap_outputFrameSource(easyar_SparseSpatialMap * _Nonnull This, /* OUT */ easyar_OutputFrameSource * _Nonnull * _Nonnull Return);
void easyar_SparseSpatialMap_create(/* OUT */ easyar_SparseSpatialMap * _Nonnull * _Nonnull Return);
bool easyar_SparseSpatialMap_start(easyar_SparseSpatialMap * _Nonnull This);
void easyar_SparseSpatialMap_stop(easyar_SparseSpatialMap * _Nonnull This);
void easyar_SparseSpatialMap_close(easyar_SparseSpatialMap * _Nonnull This);
void easyar_SparseSpatialMap_getPointCloudBuffer(easyar_SparseSpatialMap * _Nonnull This, /* OUT */ easyar_Buffer * _Nonnull * _Nonnull Return);
void easyar_SparseSpatialMap_getMapPlanes(easyar_SparseSpatialMap * _Nonnull This, /* OUT */ easyar_ListOfPlaneData * _Nonnull * _Nonnull Return);
void easyar_SparseSpatialMap_hitTestAgainstPointCloud(easyar_SparseSpatialMap * _Nonnull This, easyar_Vec2F cameraImagePoint, /* OUT */ easyar_ListOfVec3F * _Nonnull * _Nonnull Return);
void easyar_SparseSpatialMap_hitTestAgainstPlanes(easyar_SparseSpatialMap * _Nonnull This, easyar_Vec2F cameraImagePoint, /* OUT */ easyar_ListOfVec3F * _Nonnull * _Nonnull Return);
void easyar_SparseSpatialMap_getMapVersion(/* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_SparseSpatialMap_unloadMap(easyar_SparseSpatialMap * _Nonnull This, easyar_String * _Nonnull mapID, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_OptionalOfFunctorOfVoidFromBool resultCallBack);
void easyar_SparseSpatialMap_setConfig(easyar_SparseSpatialMap * _Nonnull This, easyar_SparseSpatialMapConfig * _Nonnull config);
void easyar_SparseSpatialMap_getConfig(easyar_SparseSpatialMap * _Nonnull This, /* OUT */ easyar_SparseSpatialMapConfig * _Nonnull * _Nonnull Return);
bool easyar_SparseSpatialMap_startLocalization(easyar_SparseSpatialMap * _Nonnull This);
void easyar_SparseSpatialMap_stopLocalization(easyar_SparseSpatialMap * _Nonnull This);
void easyar_SparseSpatialMap__dtor(easyar_SparseSpatialMap * _Nonnull This);
void easyar_SparseSpatialMap__retain(const easyar_SparseSpatialMap * _Nonnull This, /* OUT */ easyar_SparseSpatialMap * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_SparseSpatialMap__typeName(const easyar_SparseSpatialMap * _Nonnull This);

bool easyar_SparseSpatialMapManager_isAvailable();
void easyar_SparseSpatialMapManager_create(/* OUT */ easyar_SparseSpatialMapManager * _Nonnull * _Nonnull Return);
void easyar_SparseSpatialMapManager_host(easyar_SparseSpatialMapManager * _Nonnull This, easyar_SparseSpatialMap * _Nonnull mapBuilder, easyar_String * _Nonnull apiKey, easyar_String * _Nonnull apiSecret, easyar_String * _Nonnull sparseSpatialMapAppId, easyar_String * _Nonnull name, easyar_OptionalOfImage preview, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_FunctorOfVoidFromBoolAndStringAndString onCompleted);
void easyar_SparseSpatialMapManager_load(easyar_SparseSpatialMapManager * _Nonnull This, easyar_SparseSpatialMap * _Nonnull mapTracker, easyar_String * _Nonnull serverMapId, easyar_String * _Nonnull apiKey, easyar_String * _Nonnull apiSecret, easyar_String * _Nonnull sparseSpatialMapAppId, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_FunctorOfVoidFromBoolAndString onCompleted);
void easyar_SparseSpatialMapManager_clear(easyar_SparseSpatialMapManager * _Nonnull This);
void easyar_SparseSpatialMapManager__dtor(easyar_SparseSpatialMapManager * _Nonnull This);
void easyar_SparseSpatialMapManager__retain(const easyar_SparseSpatialMapManager * _Nonnull This, /* OUT */ easyar_SparseSpatialMapManager * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_SparseSpatialMapManager__typeName(const easyar_SparseSpatialMapManager * _Nonnull This);

int easyar_Engine_schemaHash();
bool easyar_Engine_initialize(easyar_String * _Nonnull key);
void easyar_Engine_onPause();
void easyar_Engine_onResume();
void easyar_Engine_errorMessage(/* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_Engine_versionString(/* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_Engine_name(/* OUT */ easyar_String * _Nonnull * _Nonnull Return);

void easyar_VideoPlayer__ctor(/* OUT */ easyar_VideoPlayer * _Nonnull * _Nonnull Return);
bool easyar_VideoPlayer_isAvailable();
void easyar_VideoPlayer_setVideoType(easyar_VideoPlayer * _Nonnull This, int videoType);
void easyar_VideoPlayer_setRenderTexture(easyar_VideoPlayer * _Nonnull This, easyar_TextureId * _Nonnull texture);
void easyar_VideoPlayer_open(easyar_VideoPlayer * _Nonnull This, easyar_String * _Nonnull path, int storageType, easyar_CallbackScheduler * _Nonnull callbackScheduler, easyar_OptionalOfFunctorOfVoidFromVideoStatus callback);
void easyar_VideoPlayer_close(easyar_VideoPlayer * _Nonnull This);
bool easyar_VideoPlayer_play(easyar_VideoPlayer * _Nonnull This);
void easyar_VideoPlayer_stop(easyar_VideoPlayer * _Nonnull This);
void easyar_VideoPlayer_pause(easyar_VideoPlayer * _Nonnull This);
bool easyar_VideoPlayer_isRenderTextureAvailable(easyar_VideoPlayer * _Nonnull This);
void easyar_VideoPlayer_updateFrame(easyar_VideoPlayer * _Nonnull This);
int easyar_VideoPlayer_duration(easyar_VideoPlayer * _Nonnull This);
int easyar_VideoPlayer_currentPosition(easyar_VideoPlayer * _Nonnull This);
bool easyar_VideoPlayer_seek(easyar_VideoPlayer * _Nonnull This, int position);
easyar_Vec2I easyar_VideoPlayer_size(easyar_VideoPlayer * _Nonnull This);
float easyar_VideoPlayer_volume(easyar_VideoPlayer * _Nonnull This);
bool easyar_VideoPlayer_setVolume(easyar_VideoPlayer * _Nonnull This, float volume);
void easyar_VideoPlayer__dtor(easyar_VideoPlayer * _Nonnull This);
void easyar_VideoPlayer__retain(const easyar_VideoPlayer * _Nonnull This, /* OUT */ easyar_VideoPlayer * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_VideoPlayer__typeName(const easyar_VideoPlayer * _Nonnull This);

void easyar_ImageHelper_decode(easyar_Buffer * _Nonnull buffer, /* OUT */ easyar_OptionalOfImage * _Nonnull Return);

void easyar_SignalSink_handle(easyar_SignalSink * _Nonnull This);
void easyar_SignalSink__dtor(easyar_SignalSink * _Nonnull This);
void easyar_SignalSink__retain(const easyar_SignalSink * _Nonnull This, /* OUT */ easyar_SignalSink * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_SignalSink__typeName(const easyar_SignalSink * _Nonnull This);

void easyar_SignalSource_setHandler(easyar_SignalSource * _Nonnull This, easyar_OptionalOfFunctorOfVoid handler);
void easyar_SignalSource_connect(easyar_SignalSource * _Nonnull This, easyar_SignalSink * _Nonnull sink);
void easyar_SignalSource_disconnect(easyar_SignalSource * _Nonnull This);
void easyar_SignalSource__dtor(easyar_SignalSource * _Nonnull This);
void easyar_SignalSource__retain(const easyar_SignalSource * _Nonnull This, /* OUT */ easyar_SignalSource * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_SignalSource__typeName(const easyar_SignalSource * _Nonnull This);

void easyar_InputFrameSink_handle(easyar_InputFrameSink * _Nonnull This, easyar_InputFrame * _Nonnull inputData);
void easyar_InputFrameSink__dtor(easyar_InputFrameSink * _Nonnull This);
void easyar_InputFrameSink__retain(const easyar_InputFrameSink * _Nonnull This, /* OUT */ easyar_InputFrameSink * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_InputFrameSink__typeName(const easyar_InputFrameSink * _Nonnull This);

void easyar_InputFrameSource_setHandler(easyar_InputFrameSource * _Nonnull This, easyar_OptionalOfFunctorOfVoidFromInputFrame handler);
void easyar_InputFrameSource_connect(easyar_InputFrameSource * _Nonnull This, easyar_InputFrameSink * _Nonnull sink);
void easyar_InputFrameSource_disconnect(easyar_InputFrameSource * _Nonnull This);
void easyar_InputFrameSource__dtor(easyar_InputFrameSource * _Nonnull This);
void easyar_InputFrameSource__retain(const easyar_InputFrameSource * _Nonnull This, /* OUT */ easyar_InputFrameSource * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_InputFrameSource__typeName(const easyar_InputFrameSource * _Nonnull This);

void easyar_OutputFrameSink_handle(easyar_OutputFrameSink * _Nonnull This, easyar_OutputFrame * _Nonnull inputData);
void easyar_OutputFrameSink__dtor(easyar_OutputFrameSink * _Nonnull This);
void easyar_OutputFrameSink__retain(const easyar_OutputFrameSink * _Nonnull This, /* OUT */ easyar_OutputFrameSink * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_OutputFrameSink__typeName(const easyar_OutputFrameSink * _Nonnull This);

void easyar_OutputFrameSource_setHandler(easyar_OutputFrameSource * _Nonnull This, easyar_OptionalOfFunctorOfVoidFromOutputFrame handler);
void easyar_OutputFrameSource_connect(easyar_OutputFrameSource * _Nonnull This, easyar_OutputFrameSink * _Nonnull sink);
void easyar_OutputFrameSource_disconnect(easyar_OutputFrameSource * _Nonnull This);
void easyar_OutputFrameSource__dtor(easyar_OutputFrameSource * _Nonnull This);
void easyar_OutputFrameSource__retain(const easyar_OutputFrameSource * _Nonnull This, /* OUT */ easyar_OutputFrameSource * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_OutputFrameSource__typeName(const easyar_OutputFrameSource * _Nonnull This);

void easyar_FeedbackFrameSink_handle(easyar_FeedbackFrameSink * _Nonnull This, easyar_FeedbackFrame * _Nonnull inputData);
void easyar_FeedbackFrameSink__dtor(easyar_FeedbackFrameSink * _Nonnull This);
void easyar_FeedbackFrameSink__retain(const easyar_FeedbackFrameSink * _Nonnull This, /* OUT */ easyar_FeedbackFrameSink * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_FeedbackFrameSink__typeName(const easyar_FeedbackFrameSink * _Nonnull This);

void easyar_FeedbackFrameSource_setHandler(easyar_FeedbackFrameSource * _Nonnull This, easyar_OptionalOfFunctorOfVoidFromFeedbackFrame handler);
void easyar_FeedbackFrameSource_connect(easyar_FeedbackFrameSource * _Nonnull This, easyar_FeedbackFrameSink * _Nonnull sink);
void easyar_FeedbackFrameSource_disconnect(easyar_FeedbackFrameSource * _Nonnull This);
void easyar_FeedbackFrameSource__dtor(easyar_FeedbackFrameSource * _Nonnull This);
void easyar_FeedbackFrameSource__retain(const easyar_FeedbackFrameSource * _Nonnull This, /* OUT */ easyar_FeedbackFrameSource * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_FeedbackFrameSource__typeName(const easyar_FeedbackFrameSource * _Nonnull This);

void easyar_InputFrameFork_input(easyar_InputFrameFork * _Nonnull This, /* OUT */ easyar_InputFrameSink * _Nonnull * _Nonnull Return);
void easyar_InputFrameFork_output(easyar_InputFrameFork * _Nonnull This, int index, /* OUT */ easyar_InputFrameSource * _Nonnull * _Nonnull Return);
int easyar_InputFrameFork_outputCount(easyar_InputFrameFork * _Nonnull This);
void easyar_InputFrameFork_create(int outputCount, /* OUT */ easyar_InputFrameFork * _Nonnull * _Nonnull Return);
void easyar_InputFrameFork__dtor(easyar_InputFrameFork * _Nonnull This);
void easyar_InputFrameFork__retain(const easyar_InputFrameFork * _Nonnull This, /* OUT */ easyar_InputFrameFork * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_InputFrameFork__typeName(const easyar_InputFrameFork * _Nonnull This);

void easyar_OutputFrameFork_input(easyar_OutputFrameFork * _Nonnull This, /* OUT */ easyar_OutputFrameSink * _Nonnull * _Nonnull Return);
void easyar_OutputFrameFork_output(easyar_OutputFrameFork * _Nonnull This, int index, /* OUT */ easyar_OutputFrameSource * _Nonnull * _Nonnull Return);
int easyar_OutputFrameFork_outputCount(easyar_OutputFrameFork * _Nonnull This);
void easyar_OutputFrameFork_create(int outputCount, /* OUT */ easyar_OutputFrameFork * _Nonnull * _Nonnull Return);
void easyar_OutputFrameFork__dtor(easyar_OutputFrameFork * _Nonnull This);
void easyar_OutputFrameFork__retain(const easyar_OutputFrameFork * _Nonnull This, /* OUT */ easyar_OutputFrameFork * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_OutputFrameFork__typeName(const easyar_OutputFrameFork * _Nonnull This);

void easyar_OutputFrameJoin_input(easyar_OutputFrameJoin * _Nonnull This, int index, /* OUT */ easyar_OutputFrameSink * _Nonnull * _Nonnull Return);
void easyar_OutputFrameJoin_output(easyar_OutputFrameJoin * _Nonnull This, /* OUT */ easyar_OutputFrameSource * _Nonnull * _Nonnull Return);
int easyar_OutputFrameJoin_inputCount(easyar_OutputFrameJoin * _Nonnull This);
void easyar_OutputFrameJoin_create(int inputCount, /* OUT */ easyar_OutputFrameJoin * _Nonnull * _Nonnull Return);
void easyar_OutputFrameJoin_createWithJoiner(int inputCount, easyar_FunctorOfOutputFrameFromListOfOutputFrame joiner, /* OUT */ easyar_OutputFrameJoin * _Nonnull * _Nonnull Return);
void easyar_OutputFrameJoin__dtor(easyar_OutputFrameJoin * _Nonnull This);
void easyar_OutputFrameJoin__retain(const easyar_OutputFrameJoin * _Nonnull This, /* OUT */ easyar_OutputFrameJoin * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_OutputFrameJoin__typeName(const easyar_OutputFrameJoin * _Nonnull This);

void easyar_FeedbackFrameFork_input(easyar_FeedbackFrameFork * _Nonnull This, /* OUT */ easyar_FeedbackFrameSink * _Nonnull * _Nonnull Return);
void easyar_FeedbackFrameFork_output(easyar_FeedbackFrameFork * _Nonnull This, int index, /* OUT */ easyar_FeedbackFrameSource * _Nonnull * _Nonnull Return);
int easyar_FeedbackFrameFork_outputCount(easyar_FeedbackFrameFork * _Nonnull This);
void easyar_FeedbackFrameFork_create(int outputCount, /* OUT */ easyar_FeedbackFrameFork * _Nonnull * _Nonnull Return);
void easyar_FeedbackFrameFork__dtor(easyar_FeedbackFrameFork * _Nonnull This);
void easyar_FeedbackFrameFork__retain(const easyar_FeedbackFrameFork * _Nonnull This, /* OUT */ easyar_FeedbackFrameFork * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_FeedbackFrameFork__typeName(const easyar_FeedbackFrameFork * _Nonnull This);

void easyar_InputFrameThrottler_input(easyar_InputFrameThrottler * _Nonnull This, /* OUT */ easyar_InputFrameSink * _Nonnull * _Nonnull Return);
int easyar_InputFrameThrottler_bufferRequirement(easyar_InputFrameThrottler * _Nonnull This);
void easyar_InputFrameThrottler_output(easyar_InputFrameThrottler * _Nonnull This, /* OUT */ easyar_InputFrameSource * _Nonnull * _Nonnull Return);
void easyar_InputFrameThrottler_signalInput(easyar_InputFrameThrottler * _Nonnull This, /* OUT */ easyar_SignalSink * _Nonnull * _Nonnull Return);
void easyar_InputFrameThrottler_create(/* OUT */ easyar_InputFrameThrottler * _Nonnull * _Nonnull Return);
void easyar_InputFrameThrottler__dtor(easyar_InputFrameThrottler * _Nonnull This);
void easyar_InputFrameThrottler__retain(const easyar_InputFrameThrottler * _Nonnull This, /* OUT */ easyar_InputFrameThrottler * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_InputFrameThrottler__typeName(const easyar_InputFrameThrottler * _Nonnull This);

void easyar_OutputFrameBuffer_input(easyar_OutputFrameBuffer * _Nonnull This, /* OUT */ easyar_OutputFrameSink * _Nonnull * _Nonnull Return);
int easyar_OutputFrameBuffer_bufferRequirement(easyar_OutputFrameBuffer * _Nonnull This);
void easyar_OutputFrameBuffer_signalOutput(easyar_OutputFrameBuffer * _Nonnull This, /* OUT */ easyar_SignalSource * _Nonnull * _Nonnull Return);
void easyar_OutputFrameBuffer_peek(easyar_OutputFrameBuffer * _Nonnull This, /* OUT */ easyar_OptionalOfOutputFrame * _Nonnull Return);
void easyar_OutputFrameBuffer_create(/* OUT */ easyar_OutputFrameBuffer * _Nonnull * _Nonnull Return);
void easyar_OutputFrameBuffer_pause(easyar_OutputFrameBuffer * _Nonnull This);
void easyar_OutputFrameBuffer_resume(easyar_OutputFrameBuffer * _Nonnull This);
void easyar_OutputFrameBuffer__dtor(easyar_OutputFrameBuffer * _Nonnull This);
void easyar_OutputFrameBuffer__retain(const easyar_OutputFrameBuffer * _Nonnull This, /* OUT */ easyar_OutputFrameBuffer * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_OutputFrameBuffer__typeName(const easyar_OutputFrameBuffer * _Nonnull This);

void easyar_InputFrameToOutputFrameAdapter_input(easyar_InputFrameToOutputFrameAdapter * _Nonnull This, /* OUT */ easyar_InputFrameSink * _Nonnull * _Nonnull Return);
void easyar_InputFrameToOutputFrameAdapter_output(easyar_InputFrameToOutputFrameAdapter * _Nonnull This, /* OUT */ easyar_OutputFrameSource * _Nonnull * _Nonnull Return);
void easyar_InputFrameToOutputFrameAdapter_create(/* OUT */ easyar_InputFrameToOutputFrameAdapter * _Nonnull * _Nonnull Return);
void easyar_InputFrameToOutputFrameAdapter__dtor(easyar_InputFrameToOutputFrameAdapter * _Nonnull This);
void easyar_InputFrameToOutputFrameAdapter__retain(const easyar_InputFrameToOutputFrameAdapter * _Nonnull This, /* OUT */ easyar_InputFrameToOutputFrameAdapter * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_InputFrameToOutputFrameAdapter__typeName(const easyar_InputFrameToOutputFrameAdapter * _Nonnull This);

void easyar_InputFrameToFeedbackFrameAdapter_input(easyar_InputFrameToFeedbackFrameAdapter * _Nonnull This, /* OUT */ easyar_InputFrameSink * _Nonnull * _Nonnull Return);
int easyar_InputFrameToFeedbackFrameAdapter_bufferRequirement(easyar_InputFrameToFeedbackFrameAdapter * _Nonnull This);
void easyar_InputFrameToFeedbackFrameAdapter_sideInput(easyar_InputFrameToFeedbackFrameAdapter * _Nonnull This, /* OUT */ easyar_OutputFrameSink * _Nonnull * _Nonnull Return);
void easyar_InputFrameToFeedbackFrameAdapter_output(easyar_InputFrameToFeedbackFrameAdapter * _Nonnull This, /* OUT */ easyar_FeedbackFrameSource * _Nonnull * _Nonnull Return);
void easyar_InputFrameToFeedbackFrameAdapter_create(/* OUT */ easyar_InputFrameToFeedbackFrameAdapter * _Nonnull * _Nonnull Return);
void easyar_InputFrameToFeedbackFrameAdapter__dtor(easyar_InputFrameToFeedbackFrameAdapter * _Nonnull This);
void easyar_InputFrameToFeedbackFrameAdapter__retain(const easyar_InputFrameToFeedbackFrameAdapter * _Nonnull This, /* OUT */ easyar_InputFrameToFeedbackFrameAdapter * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_InputFrameToFeedbackFrameAdapter__typeName(const easyar_InputFrameToFeedbackFrameAdapter * _Nonnull This);

int easyar_InputFrame_index(const easyar_InputFrame * _Nonnull This);
void easyar_InputFrame_image(const easyar_InputFrame * _Nonnull This, /* OUT */ easyar_Image * _Nonnull * _Nonnull Return);
bool easyar_InputFrame_hasCameraParameters(const easyar_InputFrame * _Nonnull This);
void easyar_InputFrame_cameraParameters(const easyar_InputFrame * _Nonnull This, /* OUT */ easyar_CameraParameters * _Nonnull * _Nonnull Return);
bool easyar_InputFrame_hasTemporalInformation(const easyar_InputFrame * _Nonnull This);
double easyar_InputFrame_timestamp(const easyar_InputFrame * _Nonnull This);
bool easyar_InputFrame_hasSpatialInformation(const easyar_InputFrame * _Nonnull This);
easyar_Matrix44F easyar_InputFrame_cameraTransform(const easyar_InputFrame * _Nonnull This);
int easyar_InputFrame_trackingStatus(const easyar_InputFrame * _Nonnull This);
void easyar_InputFrame_create(easyar_Image * _Nonnull image, easyar_CameraParameters * _Nonnull cameraParameters, double timestamp, easyar_Matrix44F cameraTransform, int trackingStatus, /* OUT */ easyar_InputFrame * _Nonnull * _Nonnull Return);
void easyar_InputFrame_createWithImageAndCameraParametersAndTemporal(easyar_Image * _Nonnull image, easyar_CameraParameters * _Nonnull cameraParameters, double timestamp, /* OUT */ easyar_InputFrame * _Nonnull * _Nonnull Return);
void easyar_InputFrame_createWithImageAndCameraParameters(easyar_Image * _Nonnull image, easyar_CameraParameters * _Nonnull cameraParameters, /* OUT */ easyar_InputFrame * _Nonnull * _Nonnull Return);
void easyar_InputFrame_createWithImage(easyar_Image * _Nonnull image, /* OUT */ easyar_InputFrame * _Nonnull * _Nonnull Return);
void easyar_InputFrame__dtor(easyar_InputFrame * _Nonnull This);
void easyar_InputFrame__retain(const easyar_InputFrame * _Nonnull This, /* OUT */ easyar_InputFrame * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_InputFrame__typeName(const easyar_InputFrame * _Nonnull This);

void easyar_FrameFilterResult__dtor(easyar_FrameFilterResult * _Nonnull This);
void easyar_FrameFilterResult__retain(const easyar_FrameFilterResult * _Nonnull This, /* OUT */ easyar_FrameFilterResult * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_FrameFilterResult__typeName(const easyar_FrameFilterResult * _Nonnull This);

void easyar_OutputFrame__ctor(easyar_InputFrame * _Nonnull inputFrame, easyar_ListOfOptionalOfFrameFilterResult * _Nonnull results, /* OUT */ easyar_OutputFrame * _Nonnull * _Nonnull Return);
int easyar_OutputFrame_index(const easyar_OutputFrame * _Nonnull This);
void easyar_OutputFrame_inputFrame(const easyar_OutputFrame * _Nonnull This, /* OUT */ easyar_InputFrame * _Nonnull * _Nonnull Return);
void easyar_OutputFrame_results(const easyar_OutputFrame * _Nonnull This, /* OUT */ easyar_ListOfOptionalOfFrameFilterResult * _Nonnull * _Nonnull Return);
void easyar_OutputFrame__dtor(easyar_OutputFrame * _Nonnull This);
void easyar_OutputFrame__retain(const easyar_OutputFrame * _Nonnull This, /* OUT */ easyar_OutputFrame * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_OutputFrame__typeName(const easyar_OutputFrame * _Nonnull This);

void easyar_FeedbackFrame__ctor(easyar_InputFrame * _Nonnull inputFrame, easyar_OptionalOfOutputFrame previousOutputFrame, /* OUT */ easyar_FeedbackFrame * _Nonnull * _Nonnull Return);
void easyar_FeedbackFrame_inputFrame(const easyar_FeedbackFrame * _Nonnull This, /* OUT */ easyar_InputFrame * _Nonnull * _Nonnull Return);
void easyar_FeedbackFrame_previousOutputFrame(const easyar_FeedbackFrame * _Nonnull This, /* OUT */ easyar_OptionalOfOutputFrame * _Nonnull Return);
void easyar_FeedbackFrame__dtor(easyar_FeedbackFrame * _Nonnull This);
void easyar_FeedbackFrame__retain(const easyar_FeedbackFrame * _Nonnull This, /* OUT */ easyar_FeedbackFrame * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_FeedbackFrame__typeName(const easyar_FeedbackFrame * _Nonnull This);

int easyar_Target_runtimeID(const easyar_Target * _Nonnull This);
void easyar_Target_uid(const easyar_Target * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_Target_name(const easyar_Target * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_Target_setName(easyar_Target * _Nonnull This, easyar_String * _Nonnull name);
void easyar_Target_meta(const easyar_Target * _Nonnull This, /* OUT */ easyar_String * _Nonnull * _Nonnull Return);
void easyar_Target_setMeta(easyar_Target * _Nonnull This, easyar_String * _Nonnull data);
void easyar_Target__dtor(easyar_Target * _Nonnull This);
void easyar_Target__retain(const easyar_Target * _Nonnull This, /* OUT */ easyar_Target * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_Target__typeName(const easyar_Target * _Nonnull This);

void easyar_TargetInstance__ctor(/* OUT */ easyar_TargetInstance * _Nonnull * _Nonnull Return);
int easyar_TargetInstance_status(const easyar_TargetInstance * _Nonnull This);
void easyar_TargetInstance_target(const easyar_TargetInstance * _Nonnull This, /* OUT */ easyar_OptionalOfTarget * _Nonnull Return);
easyar_Matrix44F easyar_TargetInstance_pose(const easyar_TargetInstance * _Nonnull This);
void easyar_TargetInstance__dtor(easyar_TargetInstance * _Nonnull This);
void easyar_TargetInstance__retain(const easyar_TargetInstance * _Nonnull This, /* OUT */ easyar_TargetInstance * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_TargetInstance__typeName(const easyar_TargetInstance * _Nonnull This);

void easyar_TargetTrackerResult_targetInstances(const easyar_TargetTrackerResult * _Nonnull This, /* OUT */ easyar_ListOfTargetInstance * _Nonnull * _Nonnull Return);
void easyar_TargetTrackerResult_setTargetInstances(easyar_TargetTrackerResult * _Nonnull This, easyar_ListOfTargetInstance * _Nonnull instances);
void easyar_TargetTrackerResult__dtor(easyar_TargetTrackerResult * _Nonnull This);
void easyar_TargetTrackerResult__retain(const easyar_TargetTrackerResult * _Nonnull This, /* OUT */ easyar_TargetTrackerResult * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_TargetTrackerResult__typeName(const easyar_TargetTrackerResult * _Nonnull This);
void easyar_castTargetTrackerResultToFrameFilterResult(const easyar_TargetTrackerResult * _Nonnull This, /* OUT */ easyar_FrameFilterResult * _Nonnull * _Nonnull Return);
void easyar_tryCastFrameFilterResultToTargetTrackerResult(const easyar_FrameFilterResult * _Nonnull This, /* OUT */ easyar_TargetTrackerResult * _Nonnull * _Nonnull Return);

int easyar_TextureId_getInt(easyar_TextureId * _Nonnull This);
easyar_Opaque * _Nullable easyar_TextureId_getPointer(easyar_TextureId * _Nonnull This);
void easyar_TextureId_fromInt(int _value, /* OUT */ easyar_TextureId * _Nonnull * _Nonnull Return);
void easyar_TextureId_fromPointer(easyar_Opaque * _Nullable ptr, /* OUT */ easyar_TextureId * _Nonnull * _Nonnull Return);
void easyar_TextureId__dtor(easyar_TextureId * _Nonnull This);
void easyar_TextureId__retain(const easyar_TextureId * _Nonnull This, /* OUT */ easyar_TextureId * _Nonnull * _Nonnull Return);
const char * _Nonnull easyar_TextureId__typeName(const easyar_TextureId * _Nonnull This);

void easyar_ListOfVec3F__ctor(easyar_Vec3F const * _Nullable begin, easyar_Vec3F const * _Nullable end, /* OUT */ easyar_ListOfVec3F * _Nonnull * _Nonnull Return);
void easyar_ListOfVec3F__dtor(easyar_ListOfVec3F * _Nonnull This);
void easyar_ListOfVec3F_copy(const easyar_ListOfVec3F * _Nonnull This, /* OUT */ easyar_ListOfVec3F * _Nonnull * _Nonnull Return);
int easyar_ListOfVec3F_size(const easyar_ListOfVec3F * _Nonnull This);
easyar_Vec3F easyar_ListOfVec3F_at(const easyar_ListOfVec3F * _Nonnull This, int index);

void easyar_ListOfTargetInstance__ctor(easyar_TargetInstance * _Nonnull const * _Nullable begin, easyar_TargetInstance * _Nonnull const * _Nullable end, /* OUT */ easyar_ListOfTargetInstance * _Nonnull * _Nonnull Return);
void easyar_ListOfTargetInstance__dtor(easyar_ListOfTargetInstance * _Nonnull This);
void easyar_ListOfTargetInstance_copy(const easyar_ListOfTargetInstance * _Nonnull This, /* OUT */ easyar_ListOfTargetInstance * _Nonnull * _Nonnull Return);
int easyar_ListOfTargetInstance_size(const easyar_ListOfTargetInstance * _Nonnull This);
easyar_TargetInstance * _Nonnull easyar_ListOfTargetInstance_at(const easyar_ListOfTargetInstance * _Nonnull This, int index);

void easyar_ListOfOptionalOfFrameFilterResult__ctor(easyar_OptionalOfFrameFilterResult const * _Nullable begin, easyar_OptionalOfFrameFilterResult const * _Nullable end, /* OUT */ easyar_ListOfOptionalOfFrameFilterResult * _Nonnull * _Nonnull Return);
void easyar_ListOfOptionalOfFrameFilterResult__dtor(easyar_ListOfOptionalOfFrameFilterResult * _Nonnull This);
void easyar_ListOfOptionalOfFrameFilterResult_copy(const easyar_ListOfOptionalOfFrameFilterResult * _Nonnull This, /* OUT */ easyar_ListOfOptionalOfFrameFilterResult * _Nonnull * _Nonnull Return);
int easyar_ListOfOptionalOfFrameFilterResult_size(const easyar_ListOfOptionalOfFrameFilterResult * _Nonnull This);
easyar_OptionalOfFrameFilterResult easyar_ListOfOptionalOfFrameFilterResult_at(const easyar_ListOfOptionalOfFrameFilterResult * _Nonnull This, int index);

void easyar_ListOfTarget__ctor(easyar_Target * _Nonnull const * _Nullable begin, easyar_Target * _Nonnull const * _Nullable end, /* OUT */ easyar_ListOfTarget * _Nonnull * _Nonnull Return);
void easyar_ListOfTarget__dtor(easyar_ListOfTarget * _Nonnull This);
void easyar_ListOfTarget_copy(const easyar_ListOfTarget * _Nonnull This, /* OUT */ easyar_ListOfTarget * _Nonnull * _Nonnull Return);
int easyar_ListOfTarget_size(const easyar_ListOfTarget * _Nonnull This);
easyar_Target * _Nonnull easyar_ListOfTarget_at(const easyar_ListOfTarget * _Nonnull This, int index);

void easyar_ListOfString__ctor(easyar_String * _Nonnull const * _Nullable begin, easyar_String * _Nonnull const * _Nullable end, /* OUT */ easyar_ListOfString * _Nonnull * _Nonnull Return);
void easyar_ListOfString__dtor(easyar_ListOfString * _Nonnull This);
void easyar_ListOfString_copy(const easyar_ListOfString * _Nonnull This, /* OUT */ easyar_ListOfString * _Nonnull * _Nonnull Return);
int easyar_ListOfString_size(const easyar_ListOfString * _Nonnull This);
easyar_String * _Nonnull easyar_ListOfString_at(const easyar_ListOfString * _Nonnull This, int index);

void easyar_ListOfMatrix44F__ctor(easyar_Matrix44F const * _Nullable begin, easyar_Matrix44F const * _Nullable end, /* OUT */ easyar_ListOfMatrix44F * _Nonnull * _Nonnull Return);
void easyar_ListOfMatrix44F__dtor(easyar_ListOfMatrix44F * _Nonnull This);
void easyar_ListOfMatrix44F_copy(const easyar_ListOfMatrix44F * _Nonnull This, /* OUT */ easyar_ListOfMatrix44F * _Nonnull * _Nonnull Return);
int easyar_ListOfMatrix44F_size(const easyar_ListOfMatrix44F * _Nonnull This);
easyar_Matrix44F easyar_ListOfMatrix44F_at(const easyar_ListOfMatrix44F * _Nonnull This, int index);

void easyar_ListOfImage__ctor(easyar_Image * _Nonnull const * _Nullable begin, easyar_Image * _Nonnull const * _Nullable end, /* OUT */ easyar_ListOfImage * _Nonnull * _Nonnull Return);
void easyar_ListOfImage__dtor(easyar_ListOfImage * _Nonnull This);
void easyar_ListOfImage_copy(const easyar_ListOfImage * _Nonnull This, /* OUT */ easyar_ListOfImage * _Nonnull * _Nonnull Return);
int easyar_ListOfImage_size(const easyar_ListOfImage * _Nonnull This);
easyar_Image * _Nonnull easyar_ListOfImage_at(const easyar_ListOfImage * _Nonnull This, int index);

void easyar_ListOfBlockInfo__ctor(easyar_BlockInfo const * _Nullable begin, easyar_BlockInfo const * _Nullable end, /* OUT */ easyar_ListOfBlockInfo * _Nonnull * _Nonnull Return);
void easyar_ListOfBlockInfo__dtor(easyar_ListOfBlockInfo * _Nonnull This);
void easyar_ListOfBlockInfo_copy(const easyar_ListOfBlockInfo * _Nonnull This, /* OUT */ easyar_ListOfBlockInfo * _Nonnull * _Nonnull Return);
int easyar_ListOfBlockInfo_size(const easyar_ListOfBlockInfo * _Nonnull This);
easyar_BlockInfo easyar_ListOfBlockInfo_at(const easyar_ListOfBlockInfo * _Nonnull This, int index);

void easyar_ListOfPlaneData__ctor(easyar_PlaneData * _Nonnull const * _Nullable begin, easyar_PlaneData * _Nonnull const * _Nullable end, /* OUT */ easyar_ListOfPlaneData * _Nonnull * _Nonnull Return);
void easyar_ListOfPlaneData__dtor(easyar_ListOfPlaneData * _Nonnull This);
void easyar_ListOfPlaneData_copy(const easyar_ListOfPlaneData * _Nonnull This, /* OUT */ easyar_ListOfPlaneData * _Nonnull * _Nonnull Return);
int easyar_ListOfPlaneData_size(const easyar_ListOfPlaneData * _Nonnull This);
easyar_PlaneData * _Nonnull easyar_ListOfPlaneData_at(const easyar_ListOfPlaneData * _Nonnull This, int index);

void easyar_ListOfOutputFrame__ctor(easyar_OutputFrame * _Nonnull const * _Nullable begin, easyar_OutputFrame * _Nonnull const * _Nullable end, /* OUT */ easyar_ListOfOutputFrame * _Nonnull * _Nonnull Return);
void easyar_ListOfOutputFrame__dtor(easyar_ListOfOutputFrame * _Nonnull This);
void easyar_ListOfOutputFrame_copy(const easyar_ListOfOutputFrame * _Nonnull This, /* OUT */ easyar_ListOfOutputFrame * _Nonnull * _Nonnull Return);
int easyar_ListOfOutputFrame_size(const easyar_ListOfOutputFrame * _Nonnull This);
easyar_OutputFrame * _Nonnull easyar_ListOfOutputFrame_at(const easyar_ListOfOutputFrame * _Nonnull This, int index);

#ifdef __cplusplus
}
#endif
