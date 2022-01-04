//=============================================================================================================================
//
// EasyAR Sense 4.4.0.9304-eb4ecde40
// Copyright (c) 2015-2021 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

import Foundation

public class RefBase {
    fileprivate let cdata_: OpaquePointer
    fileprivate let deleter_: (OpaquePointer) -> Void

    fileprivate init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        cdata_ = cdata
        deleter_ = deleter
    }

    deinit {
        deleter_(cdata_)
    }
}

let TypeNameToConstructor: [String : (OpaquePointer) -> RefBase] = [
    "ObjectTargetParameters": { cdata in ObjectTargetParameters(cdata: cdata, deleter: easyar_ObjectTargetParameters__dtor) },
    "ObjectTarget": { cdata in ObjectTarget(cdata: cdata, deleter: easyar_ObjectTarget__dtor) },
    "ObjectTrackerResult": { cdata in ObjectTrackerResult(cdata: cdata, deleter: easyar_ObjectTrackerResult__dtor) },
    "ObjectTracker": { cdata in ObjectTracker(cdata: cdata, deleter: easyar_ObjectTracker__dtor) },
    "CalibrationDownloader": { cdata in CalibrationDownloader(cdata: cdata, deleter: easyar_CalibrationDownloader__dtor) },
    "CloudLocalizeResult": { cdata in CloudLocalizeResult(cdata: cdata, deleter: easyar_CloudLocalizeResult__dtor) },
    "CloudLocalizer": { cdata in CloudLocalizer(cdata: cdata, deleter: easyar_CloudLocalizer__dtor) },
    "CloudRecognizationResult": { cdata in CloudRecognizationResult(cdata: cdata, deleter: easyar_CloudRecognizationResult__dtor) },
    "CloudRecognizer": { cdata in CloudRecognizer(cdata: cdata, deleter: easyar_CloudRecognizer__dtor) },
    "Buffer": { cdata in Buffer(cdata: cdata, deleter: easyar_Buffer__dtor) },
    "BufferDictionary": { cdata in BufferDictionary(cdata: cdata, deleter: easyar_BufferDictionary__dtor) },
    "BufferPool": { cdata in BufferPool(cdata: cdata, deleter: easyar_BufferPool__dtor) },
    "CameraParameters": { cdata in CameraParameters(cdata: cdata, deleter: easyar_CameraParameters__dtor) },
    "Image": { cdata in Image(cdata: cdata, deleter: easyar_Image__dtor) },
    "DenseSpatialMap": { cdata in DenseSpatialMap(cdata: cdata, deleter: easyar_DenseSpatialMap__dtor) },
    "SceneMesh": { cdata in SceneMesh(cdata: cdata, deleter: easyar_SceneMesh__dtor) },
    "Accelerometer": { cdata in Accelerometer(cdata: cdata, deleter: easyar_Accelerometer__dtor) },
    "ARCoreCameraDevice": { cdata in ARCoreCameraDevice(cdata: cdata, deleter: easyar_ARCoreCameraDevice__dtor) },
    "ARKitCameraDevice": { cdata in ARKitCameraDevice(cdata: cdata, deleter: easyar_ARKitCameraDevice__dtor) },
    "CameraDevice": { cdata in CameraDevice(cdata: cdata, deleter: easyar_CameraDevice__dtor) },
    "SurfaceTrackerResult": { cdata in SurfaceTrackerResult(cdata: cdata, deleter: easyar_SurfaceTrackerResult__dtor) },
    "SurfaceTracker": { cdata in SurfaceTracker(cdata: cdata, deleter: easyar_SurfaceTracker__dtor) },
    "MotionTrackerCameraDevice": { cdata in MotionTrackerCameraDevice(cdata: cdata, deleter: easyar_MotionTrackerCameraDevice__dtor) },
    "InputFrameRecorder": { cdata in InputFrameRecorder(cdata: cdata, deleter: easyar_InputFrameRecorder__dtor) },
    "InputFramePlayer": { cdata in InputFramePlayer(cdata: cdata, deleter: easyar_InputFramePlayer__dtor) },
    "CallbackScheduler": { cdata in CallbackScheduler(cdata: cdata, deleter: easyar_CallbackScheduler__dtor) },
    "DelayedCallbackScheduler": { cdata in DelayedCallbackScheduler(cdata: cdata, deleter: easyar_DelayedCallbackScheduler__dtor) },
    "ImmediateCallbackScheduler": { cdata in ImmediateCallbackScheduler(cdata: cdata, deleter: easyar_ImmediateCallbackScheduler__dtor) },
    "ImageTargetParameters": { cdata in ImageTargetParameters(cdata: cdata, deleter: easyar_ImageTargetParameters__dtor) },
    "ImageTarget": { cdata in ImageTarget(cdata: cdata, deleter: easyar_ImageTarget__dtor) },
    "ImageTrackerResult": { cdata in ImageTrackerResult(cdata: cdata, deleter: easyar_ImageTrackerResult__dtor) },
    "ImageTracker": { cdata in ImageTracker(cdata: cdata, deleter: easyar_ImageTracker__dtor) },
    "RealTimeCoordinateTransform": { cdata in RealTimeCoordinateTransform(cdata: cdata, deleter: easyar_RealTimeCoordinateTransform__dtor) },
    "Recorder": { cdata in Recorder(cdata: cdata, deleter: easyar_Recorder__dtor) },
    "RecorderConfiguration": { cdata in RecorderConfiguration(cdata: cdata, deleter: easyar_RecorderConfiguration__dtor) },
    "SparseSpatialMapResult": { cdata in SparseSpatialMapResult(cdata: cdata, deleter: easyar_SparseSpatialMapResult__dtor) },
    "PlaneData": { cdata in PlaneData(cdata: cdata, deleter: easyar_PlaneData__dtor) },
    "SparseSpatialMapConfig": { cdata in SparseSpatialMapConfig(cdata: cdata, deleter: easyar_SparseSpatialMapConfig__dtor) },
    "SparseSpatialMap": { cdata in SparseSpatialMap(cdata: cdata, deleter: easyar_SparseSpatialMap__dtor) },
    "SparseSpatialMapManager": { cdata in SparseSpatialMapManager(cdata: cdata, deleter: easyar_SparseSpatialMapManager__dtor) },
    "VideoPlayer": { cdata in VideoPlayer(cdata: cdata, deleter: easyar_VideoPlayer__dtor) },
    "SignalSink": { cdata in SignalSink(cdata: cdata, deleter: easyar_SignalSink__dtor) },
    "SignalSource": { cdata in SignalSource(cdata: cdata, deleter: easyar_SignalSource__dtor) },
    "InputFrameSink": { cdata in InputFrameSink(cdata: cdata, deleter: easyar_InputFrameSink__dtor) },
    "InputFrameSource": { cdata in InputFrameSource(cdata: cdata, deleter: easyar_InputFrameSource__dtor) },
    "OutputFrameSink": { cdata in OutputFrameSink(cdata: cdata, deleter: easyar_OutputFrameSink__dtor) },
    "OutputFrameSource": { cdata in OutputFrameSource(cdata: cdata, deleter: easyar_OutputFrameSource__dtor) },
    "FeedbackFrameSink": { cdata in FeedbackFrameSink(cdata: cdata, deleter: easyar_FeedbackFrameSink__dtor) },
    "FeedbackFrameSource": { cdata in FeedbackFrameSource(cdata: cdata, deleter: easyar_FeedbackFrameSource__dtor) },
    "InputFrameFork": { cdata in InputFrameFork(cdata: cdata, deleter: easyar_InputFrameFork__dtor) },
    "OutputFrameFork": { cdata in OutputFrameFork(cdata: cdata, deleter: easyar_OutputFrameFork__dtor) },
    "OutputFrameJoin": { cdata in OutputFrameJoin(cdata: cdata, deleter: easyar_OutputFrameJoin__dtor) },
    "FeedbackFrameFork": { cdata in FeedbackFrameFork(cdata: cdata, deleter: easyar_FeedbackFrameFork__dtor) },
    "InputFrameThrottler": { cdata in InputFrameThrottler(cdata: cdata, deleter: easyar_InputFrameThrottler__dtor) },
    "OutputFrameBuffer": { cdata in OutputFrameBuffer(cdata: cdata, deleter: easyar_OutputFrameBuffer__dtor) },
    "InputFrameToOutputFrameAdapter": { cdata in InputFrameToOutputFrameAdapter(cdata: cdata, deleter: easyar_InputFrameToOutputFrameAdapter__dtor) },
    "InputFrameToFeedbackFrameAdapter": { cdata in InputFrameToFeedbackFrameAdapter(cdata: cdata, deleter: easyar_InputFrameToFeedbackFrameAdapter__dtor) },
    "InputFrame": { cdata in InputFrame(cdata: cdata, deleter: easyar_InputFrame__dtor) },
    "FrameFilterResult": { cdata in FrameFilterResult(cdata: cdata, deleter: easyar_FrameFilterResult__dtor) },
    "OutputFrame": { cdata in OutputFrame(cdata: cdata, deleter: easyar_OutputFrame__dtor) },
    "FeedbackFrame": { cdata in FeedbackFrame(cdata: cdata, deleter: easyar_FeedbackFrame__dtor) },
    "Target": { cdata in Target(cdata: cdata, deleter: easyar_Target__dtor) },
    "TargetInstance": { cdata in TargetInstance(cdata: cdata, deleter: easyar_TargetInstance__dtor) },
    "TargetTrackerResult": { cdata in TargetTrackerResult(cdata: cdata, deleter: easyar_TargetTrackerResult__dtor) },
    "TextureId": { cdata in TextureId(cdata: cdata, deleter: easyar_TextureId__dtor) },
]

fileprivate class OpaquePointerContainer {
    public let ptr_: OpaquePointer
    public let deleter_: (OpaquePointer) -> Void
    public init(_ ptr: OpaquePointer, _ deleter: @escaping (OpaquePointer) -> Void) {
        ptr_ = ptr
        deleter_ = deleter
    }
    deinit {
        deleter_(ptr_)
    }
}

fileprivate class AutoRelease {
    private var containers: [OpaquePointerContainer]
    public init() {
        containers = []
    }
    public func add(_ container : OpaquePointerContainer) -> OpaquePointerContainer {
        containers.append(container)
        return container
    }
    public func dispose() -> Void {
        containers = []
    }
}

fileprivate func defaultValue<T>() -> T {
    let ptr = UnsafeMutablePointer<T>.allocate(capacity: 1)
    defer {
        ptr.deallocate()
    }
    let retval = ptr.pointee
    return retval;
}

fileprivate func Optional_retain(_ ptr: OpaquePointer?, _ retain: @convention(c) (OpaquePointer, UnsafeMutablePointer<OpaquePointer>) -> Void) -> OpaquePointer? {
    if let p = ptr {
        let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            pptr.deallocate()
        }
        retain(p, &pptr.pointee)
        return pptr.pointee
    } else {
        return nil
    }
}

fileprivate func String_to_c(_ _ar_ : AutoRelease, _ s: String) -> OpaquePointerContainer {
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    s.utf8CString.withUnsafeBufferPointer { p in
        easyar_String_from_utf8(p.baseAddress, p.baseAddress?.advanced(by: p.count - 1), pptr)
    }
    let ptr = pptr.pointee
    return _ar_.add(OpaquePointerContainer(ptr, { p in easyar_String__dtor(p) }))
}

fileprivate func String_from_c(_ ptr: OpaquePointerContainer) -> String {
    let begin = easyar_String_begin(ptr.ptr_)
    let count = begin == nil ? 0 : begin!.distance(to: easyar_String_end(ptr.ptr_)!)
    let arr = [UInt8](UnsafeBufferPointer<UInt8>(start: UnsafePointer<UInt8>(OpaquePointer(begin)), count: count))
    return String(bytes: arr, encoding: String.Encoding.utf8)!
}

fileprivate func Object_from_c<T>(_ ptr: OpaquePointer, _ typeNameGetter: (OpaquePointer) -> UnsafePointer<CChar>) -> T {
    let typeName = String(cString: typeNameGetter(ptr))
    if let ctor = TypeNameToConstructor[typeName] {
        if let o = ctor(ptr) as? T {
            return o
        } else {
            fatalError("ValueNotOfType")
        }
    } else {
        fatalError("ConstructorNotExistForType")
    }
}

fileprivate func Matrix44F_to_c(_ r: Matrix44F) -> easyar_Matrix44F {
    return easyar_Matrix44F(data: (r.data.0, r.data.1, r.data.2, r.data.3, r.data.4, r.data.5, r.data.6, r.data.7, r.data.8, r.data.9, r.data.10, r.data.11, r.data.12, r.data.13, r.data.14, r.data.15))
}
fileprivate func Matrix44F_from_c(_ r: easyar_Matrix44F) -> Matrix44F {
    return Matrix44F(r.data.0, r.data.1, r.data.2, r.data.3, r.data.4, r.data.5, r.data.6, r.data.7, r.data.8, r.data.9, r.data.10, r.data.11, r.data.12, r.data.13, r.data.14, r.data.15)
}

fileprivate func Matrix33F_to_c(_ r: Matrix33F) -> easyar_Matrix33F {
    return easyar_Matrix33F(data: (r.data.0, r.data.1, r.data.2, r.data.3, r.data.4, r.data.5, r.data.6, r.data.7, r.data.8))
}
fileprivate func Matrix33F_from_c(_ r: easyar_Matrix33F) -> Matrix33F {
    return Matrix33F(r.data.0, r.data.1, r.data.2, r.data.3, r.data.4, r.data.5, r.data.6, r.data.7, r.data.8)
}

fileprivate func Vec3D_to_c(_ r: Vec3D) -> easyar_Vec3D {
    return easyar_Vec3D(data: (r.data.0, r.data.1, r.data.2))
}
fileprivate func Vec3D_from_c(_ r: easyar_Vec3D) -> Vec3D {
    return Vec3D(r.data.0, r.data.1, r.data.2)
}

fileprivate func Vec4F_to_c(_ r: Vec4F) -> easyar_Vec4F {
    return easyar_Vec4F(data: (r.data.0, r.data.1, r.data.2, r.data.3))
}
fileprivate func Vec4F_from_c(_ r: easyar_Vec4F) -> Vec4F {
    return Vec4F(r.data.0, r.data.1, r.data.2, r.data.3)
}

fileprivate func Vec3F_to_c(_ r: Vec3F) -> easyar_Vec3F {
    return easyar_Vec3F(data: (r.data.0, r.data.1, r.data.2))
}
fileprivate func Vec3F_from_c(_ r: easyar_Vec3F) -> Vec3F {
    return Vec3F(r.data.0, r.data.1, r.data.2)
}

fileprivate func Vec2F_to_c(_ r: Vec2F) -> easyar_Vec2F {
    return easyar_Vec2F(data: (r.data.0, r.data.1))
}
fileprivate func Vec2F_from_c(_ r: easyar_Vec2F) -> Vec2F {
    return Vec2F(r.data.0, r.data.1)
}

fileprivate func Vec4I_to_c(_ r: Vec4I) -> easyar_Vec4I {
    return easyar_Vec4I(data: (r.data.0, r.data.1, r.data.2, r.data.3))
}
fileprivate func Vec4I_from_c(_ r: easyar_Vec4I) -> Vec4I {
    return Vec4I(r.data.0, r.data.1, r.data.2, r.data.3)
}

fileprivate func Vec2I_to_c(_ r: Vec2I) -> easyar_Vec2I {
    return easyar_Vec2I(data: (r.data.0, r.data.1))
}
fileprivate func Vec2I_from_c(_ r: easyar_Vec2I) -> Vec2I {
    return Vec2I(r.data.0, r.data.1)
}

fileprivate func BlockInfo_to_c(_ r: BlockInfo) -> easyar_BlockInfo {
    return easyar_BlockInfo(x: r.x, y: r.y, z: r.z, numOfVertex: r.numOfVertex, startPointOfVertex: r.startPointOfVertex, numOfIndex: r.numOfIndex, startPointOfIndex: r.startPointOfIndex, version: r.version)
}
fileprivate func BlockInfo_from_c(_ r: easyar_BlockInfo) -> BlockInfo {
    return BlockInfo(r.x, r.y, r.z, r.numOfVertex, r.startPointOfVertex, r.numOfIndex, r.startPointOfIndex, r.version)
}

fileprivate func AccelerometerResult_to_c(_ r: AccelerometerResult) -> easyar_AccelerometerResult {
    return easyar_AccelerometerResult(x: r.x, y: r.y, z: r.z, timestamp: r.timestamp)
}
fileprivate func AccelerometerResult_from_c(_ r: easyar_AccelerometerResult) -> AccelerometerResult {
    return AccelerometerResult(r.x, r.y, r.z, r.timestamp)
}

fileprivate func MagnetometerResult_to_c(_ r: MagnetometerResult) -> easyar_MagnetometerResult {
    return easyar_MagnetometerResult(x: r.x, y: r.y, z: r.z, timestamp: r.timestamp)
}
fileprivate func MagnetometerResult_from_c(_ r: easyar_MagnetometerResult) -> MagnetometerResult {
    return MagnetometerResult(r.x, r.y, r.z, r.timestamp)
}

fileprivate func FunctorOfVoid_func(_ state: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    let f = UnsafeMutablePointer<() -> Void>(state).pointee
    f()
}
fileprivate func FunctorOfVoid_to_c(_ f: @escaping () -> Void) -> easyar_FunctorOfVoid {
    let s = UnsafeMutablePointer<() -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoid(_state: OpaquePointer(s), _func: FunctorOfVoid_func, _destroy: { p in UnsafeMutablePointer<() -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func ListOfVec3F_to_c(_ _ar_ : AutoRelease, _ l: [Vec3F]) -> OpaquePointerContainer {
    let arr = l.map({ e in Vec3F_to_c(e) })
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    arr.withUnsafeBufferPointer { bp in
        easyar_ListOfVec3F__ctor(UnsafePointer<easyar_Vec3F>(bp.baseAddress), UnsafePointer<easyar_Vec3F>(bp.baseAddress?.advanced(by: bp.count)), pptr)
    }
    return _ar_.add(OpaquePointerContainer(pptr.pointee, { p in easyar_ListOfVec3F__dtor(p) }))
}
fileprivate func ListOfVec3F_from_c(_ _ar_ : AutoRelease, _ l: OpaquePointerContainer) -> [Vec3F] {
    let size = Int(easyar_ListOfVec3F_size(l.ptr_))
    var values = [Vec3F]()
    values.reserveCapacity(size)
    for k in 0..<size {
        let v = easyar_ListOfVec3F_at(l.ptr_, Int32(k))
        values.append(Vec3F_from_c(v))
    }
    return values
}

fileprivate func ListOfTargetInstance_to_c(_ _ar_ : AutoRelease, _ l: [TargetInstance]) -> OpaquePointerContainer {
    let arr = l.map({ e in e.cdata_ })
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    arr.withUnsafeBufferPointer { bp in
        easyar_ListOfTargetInstance__ctor(UnsafePointer<OpaquePointer>(bp.baseAddress), UnsafePointer<OpaquePointer>(bp.baseAddress?.advanced(by: bp.count)), pptr)
    }
    return _ar_.add(OpaquePointerContainer(pptr.pointee, { p in easyar_ListOfTargetInstance__dtor(p) }))
}
fileprivate func ListOfTargetInstance_from_c(_ _ar_ : AutoRelease, _ l: OpaquePointerContainer) -> [TargetInstance] {
    let size = Int(easyar_ListOfTargetInstance_size(l.ptr_))
    var values = [TargetInstance]()
    values.reserveCapacity(size)
    for k in 0..<size {
        var v = easyar_ListOfTargetInstance_at(l.ptr_, Int32(k))
        easyar_TargetInstance__retain(v, &v)
        values.append((Object_from_c(v, easyar_TargetInstance__typeName) as TargetInstance))
    }
    return values
}

fileprivate func ListOfOptionalOfFrameFilterResult_to_c(_ _ar_ : AutoRelease, _ l: [FrameFilterResult?]) -> OpaquePointerContainer {
    let arr = l.map({ e in (e.map({(p) in easyar_OptionalOfFrameFilterResult(has_value: true, value: p.cdata_)}) ?? easyar_OptionalOfFrameFilterResult(has_value: false, value: defaultValue())) })
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    arr.withUnsafeBufferPointer { bp in
        easyar_ListOfOptionalOfFrameFilterResult__ctor(UnsafePointer<easyar_OptionalOfFrameFilterResult>(bp.baseAddress), UnsafePointer<easyar_OptionalOfFrameFilterResult>(bp.baseAddress?.advanced(by: bp.count)), pptr)
    }
    return _ar_.add(OpaquePointerContainer(pptr.pointee, { p in easyar_ListOfOptionalOfFrameFilterResult__dtor(p) }))
}
fileprivate func ListOfOptionalOfFrameFilterResult_from_c(_ _ar_ : AutoRelease, _ l: OpaquePointerContainer) -> [FrameFilterResult?] {
    let size = Int(easyar_ListOfOptionalOfFrameFilterResult_size(l.ptr_))
    var values = [FrameFilterResult?]()
    values.reserveCapacity(size)
    for k in 0..<size {
        var v = easyar_ListOfOptionalOfFrameFilterResult_at(l.ptr_, Int32(k))
        v.value = Optional_retain(v.value, easyar_FrameFilterResult__retain)
        values.append((v.has_value ? (Object_from_c(v.value!, easyar_FrameFilterResult__typeName) as FrameFilterResult) : nil))
    }
    return values
}

fileprivate func FunctorOfVoidFromOutputFrame_func(_ state: OpaquePointer, _ arg0: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    var varg0 = arg0
    easyar_OutputFrame__retain(varg0, &varg0)
    let sarg0 = (Object_from_c(varg0, easyar_OutputFrame__typeName) as OutputFrame)
    let f = UnsafeMutablePointer<(OutputFrame) -> Void>(state).pointee
    f(sarg0)
}
fileprivate func FunctorOfVoidFromOutputFrame_to_c(_ f: @escaping (OutputFrame) -> Void) -> easyar_FunctorOfVoidFromOutputFrame {
    let s = UnsafeMutablePointer<(OutputFrame) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromOutputFrame(_state: OpaquePointer(s), _func: FunctorOfVoidFromOutputFrame_func, _destroy: { p in UnsafeMutablePointer<(OutputFrame) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func FunctorOfVoidFromTargetAndBool_func(_ state: OpaquePointer, _ arg0: OpaquePointer, _ arg1: Bool, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    var varg0 = arg0
    easyar_Target__retain(varg0, &varg0)
    let sarg0 = (Object_from_c(varg0, easyar_Target__typeName) as Target)
    let sarg1 = arg1
    let f = UnsafeMutablePointer<(Target, Bool) -> Void>(state).pointee
    f(sarg0, sarg1)
}
fileprivate func FunctorOfVoidFromTargetAndBool_to_c(_ f: @escaping (Target, Bool) -> Void) -> easyar_FunctorOfVoidFromTargetAndBool {
    let s = UnsafeMutablePointer<(Target, Bool) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromTargetAndBool(_state: OpaquePointer(s), _func: FunctorOfVoidFromTargetAndBool_func, _destroy: { p in UnsafeMutablePointer<(Target, Bool) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func ListOfTarget_to_c(_ _ar_ : AutoRelease, _ l: [Target]) -> OpaquePointerContainer {
    let arr = l.map({ e in e.cdata_ })
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    arr.withUnsafeBufferPointer { bp in
        easyar_ListOfTarget__ctor(UnsafePointer<OpaquePointer>(bp.baseAddress), UnsafePointer<OpaquePointer>(bp.baseAddress?.advanced(by: bp.count)), pptr)
    }
    return _ar_.add(OpaquePointerContainer(pptr.pointee, { p in easyar_ListOfTarget__dtor(p) }))
}
fileprivate func ListOfTarget_from_c(_ _ar_ : AutoRelease, _ l: OpaquePointerContainer) -> [Target] {
    let size = Int(easyar_ListOfTarget_size(l.ptr_))
    var values = [Target]()
    values.reserveCapacity(size)
    for k in 0..<size {
        var v = easyar_ListOfTarget_at(l.ptr_, Int32(k))
        easyar_Target__retain(v, &v)
        values.append((Object_from_c(v, easyar_Target__typeName) as Target))
    }
    return values
}

fileprivate func FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_func(_ state: OpaquePointer, _ arg0: Int32, _ arg1: easyar_OptionalOfString, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    let sarg0 = CalibrationDownloadStatus(rawValue: arg0)!
    var varg1 = arg1
    if (varg1.has_value) {
        var _varg_value_ = varg1.value!
        easyar_String_copy(_varg_value_, &_varg_value_)
        varg1.value = _varg_value_
    }
    let sarg1 = (varg1.has_value ? String_from_c(_ar_.add(OpaquePointerContainer(varg1.value!, { p in easyar_String__dtor(p) }))) : nil)
    let f = UnsafeMutablePointer<(CalibrationDownloadStatus, String?) -> Void>(state).pointee
    f(sarg0, sarg1)
}
fileprivate func FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_to_c(_ f: @escaping (CalibrationDownloadStatus, String?) -> Void) -> easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString {
    let s = UnsafeMutablePointer<(CalibrationDownloadStatus, String?) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString(_state: OpaquePointer(s), _func: FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_func, _destroy: { p in UnsafeMutablePointer<(CalibrationDownloadStatus, String?) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func ListOfString_to_c(_ _ar_ : AutoRelease, _ l: [String]) -> OpaquePointerContainer {
    let arr = l.map({ e in String_to_c(_ar_, e).ptr_ })
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    arr.withUnsafeBufferPointer { bp in
        easyar_ListOfString__ctor(UnsafePointer<OpaquePointer>(bp.baseAddress), UnsafePointer<OpaquePointer>(bp.baseAddress?.advanced(by: bp.count)), pptr)
    }
    return _ar_.add(OpaquePointerContainer(pptr.pointee, { p in easyar_ListOfString__dtor(p) }))
}
fileprivate func ListOfString_from_c(_ _ar_ : AutoRelease, _ l: OpaquePointerContainer) -> [String] {
    let size = Int(easyar_ListOfString_size(l.ptr_))
    var values = [String]()
    values.reserveCapacity(size)
    for k in 0..<size {
        var v = easyar_ListOfString_at(l.ptr_, Int32(k))
        easyar_String_copy(v, &v)
        values.append(String_from_c(_ar_.add(OpaquePointerContainer(v, { p in easyar_String__dtor(p) }))))
    }
    return values
}

fileprivate func ListOfMatrix44F_to_c(_ _ar_ : AutoRelease, _ l: [Matrix44F]) -> OpaquePointerContainer {
    let arr = l.map({ e in Matrix44F_to_c(e) })
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    arr.withUnsafeBufferPointer { bp in
        easyar_ListOfMatrix44F__ctor(UnsafePointer<easyar_Matrix44F>(bp.baseAddress), UnsafePointer<easyar_Matrix44F>(bp.baseAddress?.advanced(by: bp.count)), pptr)
    }
    return _ar_.add(OpaquePointerContainer(pptr.pointee, { p in easyar_ListOfMatrix44F__dtor(p) }))
}
fileprivate func ListOfMatrix44F_from_c(_ _ar_ : AutoRelease, _ l: OpaquePointerContainer) -> [Matrix44F] {
    let size = Int(easyar_ListOfMatrix44F_size(l.ptr_))
    var values = [Matrix44F]()
    values.reserveCapacity(size)
    for k in 0..<size {
        let v = easyar_ListOfMatrix44F_at(l.ptr_, Int32(k))
        values.append(Matrix44F_from_c(v))
    }
    return values
}

fileprivate func FunctorOfVoidFromCloudLocalizeResult_func(_ state: OpaquePointer, _ arg0: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    var varg0 = arg0
    easyar_CloudLocalizeResult__retain(varg0, &varg0)
    let sarg0 = (Object_from_c(varg0, easyar_CloudLocalizeResult__typeName) as CloudLocalizeResult)
    let f = UnsafeMutablePointer<(CloudLocalizeResult) -> Void>(state).pointee
    f(sarg0)
}
fileprivate func FunctorOfVoidFromCloudLocalizeResult_to_c(_ f: @escaping (CloudLocalizeResult) -> Void) -> easyar_FunctorOfVoidFromCloudLocalizeResult {
    let s = UnsafeMutablePointer<(CloudLocalizeResult) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromCloudLocalizeResult(_state: OpaquePointer(s), _func: FunctorOfVoidFromCloudLocalizeResult_func, _destroy: { p in UnsafeMutablePointer<(CloudLocalizeResult) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func ListOfImage_to_c(_ _ar_ : AutoRelease, _ l: [Image]) -> OpaquePointerContainer {
    let arr = l.map({ e in e.cdata_ })
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    arr.withUnsafeBufferPointer { bp in
        easyar_ListOfImage__ctor(UnsafePointer<OpaquePointer>(bp.baseAddress), UnsafePointer<OpaquePointer>(bp.baseAddress?.advanced(by: bp.count)), pptr)
    }
    return _ar_.add(OpaquePointerContainer(pptr.pointee, { p in easyar_ListOfImage__dtor(p) }))
}
fileprivate func ListOfImage_from_c(_ _ar_ : AutoRelease, _ l: OpaquePointerContainer) -> [Image] {
    let size = Int(easyar_ListOfImage_size(l.ptr_))
    var values = [Image]()
    values.reserveCapacity(size)
    for k in 0..<size {
        var v = easyar_ListOfImage_at(l.ptr_, Int32(k))
        easyar_Image__retain(v, &v)
        values.append((Object_from_c(v, easyar_Image__typeName) as Image))
    }
    return values
}

fileprivate func FunctorOfVoidFromCloudRecognizationResult_func(_ state: OpaquePointer, _ arg0: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    var varg0 = arg0
    easyar_CloudRecognizationResult__retain(varg0, &varg0)
    let sarg0 = (Object_from_c(varg0, easyar_CloudRecognizationResult__typeName) as CloudRecognizationResult)
    let f = UnsafeMutablePointer<(CloudRecognizationResult) -> Void>(state).pointee
    f(sarg0)
}
fileprivate func FunctorOfVoidFromCloudRecognizationResult_to_c(_ f: @escaping (CloudRecognizationResult) -> Void) -> easyar_FunctorOfVoidFromCloudRecognizationResult {
    let s = UnsafeMutablePointer<(CloudRecognizationResult) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromCloudRecognizationResult(_state: OpaquePointer(s), _func: FunctorOfVoidFromCloudRecognizationResult_func, _destroy: { p in UnsafeMutablePointer<(CloudRecognizationResult) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func ListOfBlockInfo_to_c(_ _ar_ : AutoRelease, _ l: [BlockInfo]) -> OpaquePointerContainer {
    let arr = l.map({ e in BlockInfo_to_c(e) })
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    arr.withUnsafeBufferPointer { bp in
        easyar_ListOfBlockInfo__ctor(UnsafePointer<easyar_BlockInfo>(bp.baseAddress), UnsafePointer<easyar_BlockInfo>(bp.baseAddress?.advanced(by: bp.count)), pptr)
    }
    return _ar_.add(OpaquePointerContainer(pptr.pointee, { p in easyar_ListOfBlockInfo__dtor(p) }))
}
fileprivate func ListOfBlockInfo_from_c(_ _ar_ : AutoRelease, _ l: OpaquePointerContainer) -> [BlockInfo] {
    let size = Int(easyar_ListOfBlockInfo_size(l.ptr_))
    var values = [BlockInfo]()
    values.reserveCapacity(size)
    for k in 0..<size {
        let v = easyar_ListOfBlockInfo_at(l.ptr_, Int32(k))
        values.append(BlockInfo_from_c(v))
    }
    return values
}

fileprivate func FunctorOfVoidFromInputFrame_func(_ state: OpaquePointer, _ arg0: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    var varg0 = arg0
    easyar_InputFrame__retain(varg0, &varg0)
    let sarg0 = (Object_from_c(varg0, easyar_InputFrame__typeName) as InputFrame)
    let f = UnsafeMutablePointer<(InputFrame) -> Void>(state).pointee
    f(sarg0)
}
fileprivate func FunctorOfVoidFromInputFrame_to_c(_ f: @escaping (InputFrame) -> Void) -> easyar_FunctorOfVoidFromInputFrame {
    let s = UnsafeMutablePointer<(InputFrame) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromInputFrame(_state: OpaquePointer(s), _func: FunctorOfVoidFromInputFrame_func, _destroy: { p in UnsafeMutablePointer<(InputFrame) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func FunctorOfVoidFromCameraState_func(_ state: OpaquePointer, _ arg0: Int32, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    let sarg0 = CameraState(rawValue: arg0)!
    let f = UnsafeMutablePointer<(CameraState) -> Void>(state).pointee
    f(sarg0)
}
fileprivate func FunctorOfVoidFromCameraState_to_c(_ f: @escaping (CameraState) -> Void) -> easyar_FunctorOfVoidFromCameraState {
    let s = UnsafeMutablePointer<(CameraState) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromCameraState(_state: OpaquePointer(s), _func: FunctorOfVoidFromCameraState_func, _destroy: { p in UnsafeMutablePointer<(CameraState) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func FunctorOfVoidFromPermissionStatusAndString_func(_ state: OpaquePointer, _ arg0: Int32, _ arg1: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    let sarg0 = PermissionStatus(rawValue: arg0)!
    var varg1 = arg1
    easyar_String_copy(varg1, &varg1)
    let sarg1 = String_from_c(_ar_.add(OpaquePointerContainer(varg1, { p in easyar_String__dtor(p) })))
    let f = UnsafeMutablePointer<(PermissionStatus, String) -> Void>(state).pointee
    f(sarg0, sarg1)
}
fileprivate func FunctorOfVoidFromPermissionStatusAndString_to_c(_ f: @escaping (PermissionStatus, String) -> Void) -> easyar_FunctorOfVoidFromPermissionStatusAndString {
    let s = UnsafeMutablePointer<(PermissionStatus, String) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromPermissionStatusAndString(_state: OpaquePointer(s), _func: FunctorOfVoidFromPermissionStatusAndString_func, _destroy: { p in UnsafeMutablePointer<(PermissionStatus, String) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func FunctorOfVoidFromLogLevelAndString_func(_ state: OpaquePointer, _ arg0: Int32, _ arg1: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    let sarg0 = LogLevel(rawValue: arg0)!
    var varg1 = arg1
    easyar_String_copy(varg1, &varg1)
    let sarg1 = String_from_c(_ar_.add(OpaquePointerContainer(varg1, { p in easyar_String__dtor(p) })))
    let f = UnsafeMutablePointer<(LogLevel, String) -> Void>(state).pointee
    f(sarg0, sarg1)
}
fileprivate func FunctorOfVoidFromLogLevelAndString_to_c(_ f: @escaping (LogLevel, String) -> Void) -> easyar_FunctorOfVoidFromLogLevelAndString {
    let s = UnsafeMutablePointer<(LogLevel, String) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromLogLevelAndString(_state: OpaquePointer(s), _func: FunctorOfVoidFromLogLevelAndString_func, _destroy: { p in UnsafeMutablePointer<(LogLevel, String) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func FunctorOfVoidFromRecordStatusAndString_func(_ state: OpaquePointer, _ arg0: Int32, _ arg1: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    let sarg0 = RecordStatus(rawValue: arg0)!
    var varg1 = arg1
    easyar_String_copy(varg1, &varg1)
    let sarg1 = String_from_c(_ar_.add(OpaquePointerContainer(varg1, { p in easyar_String__dtor(p) })))
    let f = UnsafeMutablePointer<(RecordStatus, String) -> Void>(state).pointee
    f(sarg0, sarg1)
}
fileprivate func FunctorOfVoidFromRecordStatusAndString_to_c(_ f: @escaping (RecordStatus, String) -> Void) -> easyar_FunctorOfVoidFromRecordStatusAndString {
    let s = UnsafeMutablePointer<(RecordStatus, String) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromRecordStatusAndString(_state: OpaquePointer(s), _func: FunctorOfVoidFromRecordStatusAndString_func, _destroy: { p in UnsafeMutablePointer<(RecordStatus, String) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func ListOfPlaneData_to_c(_ _ar_ : AutoRelease, _ l: [PlaneData]) -> OpaquePointerContainer {
    let arr = l.map({ e in e.cdata_ })
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    arr.withUnsafeBufferPointer { bp in
        easyar_ListOfPlaneData__ctor(UnsafePointer<OpaquePointer>(bp.baseAddress), UnsafePointer<OpaquePointer>(bp.baseAddress?.advanced(by: bp.count)), pptr)
    }
    return _ar_.add(OpaquePointerContainer(pptr.pointee, { p in easyar_ListOfPlaneData__dtor(p) }))
}
fileprivate func ListOfPlaneData_from_c(_ _ar_ : AutoRelease, _ l: OpaquePointerContainer) -> [PlaneData] {
    let size = Int(easyar_ListOfPlaneData_size(l.ptr_))
    var values = [PlaneData]()
    values.reserveCapacity(size)
    for k in 0..<size {
        var v = easyar_ListOfPlaneData_at(l.ptr_, Int32(k))
        easyar_PlaneData__retain(v, &v)
        values.append((Object_from_c(v, easyar_PlaneData__typeName) as PlaneData))
    }
    return values
}

fileprivate func FunctorOfVoidFromBool_func(_ state: OpaquePointer, _ arg0: Bool, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    let sarg0 = arg0
    let f = UnsafeMutablePointer<(Bool) -> Void>(state).pointee
    f(sarg0)
}
fileprivate func FunctorOfVoidFromBool_to_c(_ f: @escaping (Bool) -> Void) -> easyar_FunctorOfVoidFromBool {
    let s = UnsafeMutablePointer<(Bool) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromBool(_state: OpaquePointer(s), _func: FunctorOfVoidFromBool_func, _destroy: { p in UnsafeMutablePointer<(Bool) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func FunctorOfVoidFromBoolAndStringAndString_func(_ state: OpaquePointer, _ arg0: Bool, _ arg1: OpaquePointer, _ arg2: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    let sarg0 = arg0
    var varg1 = arg1
    easyar_String_copy(varg1, &varg1)
    let sarg1 = String_from_c(_ar_.add(OpaquePointerContainer(varg1, { p in easyar_String__dtor(p) })))
    var varg2 = arg2
    easyar_String_copy(varg2, &varg2)
    let sarg2 = String_from_c(_ar_.add(OpaquePointerContainer(varg2, { p in easyar_String__dtor(p) })))
    let f = UnsafeMutablePointer<(Bool, String, String) -> Void>(state).pointee
    f(sarg0, sarg1, sarg2)
}
fileprivate func FunctorOfVoidFromBoolAndStringAndString_to_c(_ f: @escaping (Bool, String, String) -> Void) -> easyar_FunctorOfVoidFromBoolAndStringAndString {
    let s = UnsafeMutablePointer<(Bool, String, String) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromBoolAndStringAndString(_state: OpaquePointer(s), _func: FunctorOfVoidFromBoolAndStringAndString_func, _destroy: { p in UnsafeMutablePointer<(Bool, String, String) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func FunctorOfVoidFromBoolAndString_func(_ state: OpaquePointer, _ arg0: Bool, _ arg1: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    let sarg0 = arg0
    var varg1 = arg1
    easyar_String_copy(varg1, &varg1)
    let sarg1 = String_from_c(_ar_.add(OpaquePointerContainer(varg1, { p in easyar_String__dtor(p) })))
    let f = UnsafeMutablePointer<(Bool, String) -> Void>(state).pointee
    f(sarg0, sarg1)
}
fileprivate func FunctorOfVoidFromBoolAndString_to_c(_ f: @escaping (Bool, String) -> Void) -> easyar_FunctorOfVoidFromBoolAndString {
    let s = UnsafeMutablePointer<(Bool, String) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromBoolAndString(_state: OpaquePointer(s), _func: FunctorOfVoidFromBoolAndString_func, _destroy: { p in UnsafeMutablePointer<(Bool, String) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func FunctorOfVoidFromVideoStatus_func(_ state: OpaquePointer, _ arg0: Int32, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    let sarg0 = VideoStatus(rawValue: arg0)!
    let f = UnsafeMutablePointer<(VideoStatus) -> Void>(state).pointee
    f(sarg0)
}
fileprivate func FunctorOfVoidFromVideoStatus_to_c(_ f: @escaping (VideoStatus) -> Void) -> easyar_FunctorOfVoidFromVideoStatus {
    let s = UnsafeMutablePointer<(VideoStatus) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromVideoStatus(_state: OpaquePointer(s), _func: FunctorOfVoidFromVideoStatus_func, _destroy: { p in UnsafeMutablePointer<(VideoStatus) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func FunctorOfVoidFromFeedbackFrame_func(_ state: OpaquePointer, _ arg0: OpaquePointer, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    var varg0 = arg0
    easyar_FeedbackFrame__retain(varg0, &varg0)
    let sarg0 = (Object_from_c(varg0, easyar_FeedbackFrame__typeName) as FeedbackFrame)
    let f = UnsafeMutablePointer<(FeedbackFrame) -> Void>(state).pointee
    f(sarg0)
}
fileprivate func FunctorOfVoidFromFeedbackFrame_to_c(_ f: @escaping (FeedbackFrame) -> Void) -> easyar_FunctorOfVoidFromFeedbackFrame {
    let s = UnsafeMutablePointer<(FeedbackFrame) -> Void>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfVoidFromFeedbackFrame(_state: OpaquePointer(s), _func: FunctorOfVoidFromFeedbackFrame_func, _destroy: { p in UnsafeMutablePointer<(FeedbackFrame) -> Void>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func FunctorOfOutputFrameFromListOfOutputFrame_func(_ state: OpaquePointer, _ arg0: OpaquePointer, _ Return: UnsafeMutablePointer<OpaquePointer>, _ _exception: UnsafeMutablePointer<OpaquePointer?>) -> Void {
    let _ar_ = AutoRelease()
    defer {
        _ar_.dispose()
    }
    _exception.pointee = nil
    var varg0 = arg0
    easyar_ListOfOutputFrame_copy(varg0, &varg0)
    let sarg0 = ListOfOutputFrame_from_c(_ar_, _ar_.add(OpaquePointerContainer(varg0, { p in easyar_ListOfOutputFrame__dtor(p) })))
    let f = UnsafeMutablePointer<([OutputFrame]) -> OutputFrame>(state).pointee
    let _return_value_ = f(sarg0)
    var _return_value_c_ = _return_value_.cdata_
    easyar_OutputFrame__retain(_return_value_c_, &_return_value_c_)
    Return.pointee = _return_value_c_
}
fileprivate func FunctorOfOutputFrameFromListOfOutputFrame_to_c(_ f: @escaping ([OutputFrame]) -> OutputFrame) -> easyar_FunctorOfOutputFrameFromListOfOutputFrame {
    let s = UnsafeMutablePointer<([OutputFrame]) -> OutputFrame>.allocate(capacity: 1)
    s.initialize(to: f)
    return easyar_FunctorOfOutputFrameFromListOfOutputFrame(_state: OpaquePointer(s), _func: FunctorOfOutputFrameFromListOfOutputFrame_func, _destroy: { p in UnsafeMutablePointer<([OutputFrame]) -> OutputFrame>(p).deinitialize(count: 1).deallocate() })
}

fileprivate func ListOfOutputFrame_to_c(_ _ar_ : AutoRelease, _ l: [OutputFrame]) -> OpaquePointerContainer {
    let arr = l.map({ e in e.cdata_ })
    let pptr = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
    defer {
        pptr.deallocate()
    }
    arr.withUnsafeBufferPointer { bp in
        easyar_ListOfOutputFrame__ctor(UnsafePointer<OpaquePointer>(bp.baseAddress), UnsafePointer<OpaquePointer>(bp.baseAddress?.advanced(by: bp.count)), pptr)
    }
    return _ar_.add(OpaquePointerContainer(pptr.pointee, { p in easyar_ListOfOutputFrame__dtor(p) }))
}
fileprivate func ListOfOutputFrame_from_c(_ _ar_ : AutoRelease, _ l: OpaquePointerContainer) -> [OutputFrame] {
    let size = Int(easyar_ListOfOutputFrame_size(l.ptr_))
    var values = [OutputFrame]()
    values.reserveCapacity(size)
    for k in 0..<size {
        var v = easyar_ListOfOutputFrame_at(l.ptr_, Int32(k))
        easyar_OutputFrame__retain(v, &v)
        values.append((Object_from_c(v, easyar_OutputFrame__typeName) as OutputFrame))
    }
    return values
}

///ObjectTargetParameters represents the parameters to create a `ObjectTarget`_ .
public class ObjectTargetParameters : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTargetParameters__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_ObjectTargetParameters__dtor(ptr) })
    }
    ///Gets `Buffer`_ dictionary.
    public func bufferDictionary() -> BufferDictionary {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTargetParameters_bufferDictionary(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_BufferDictionary__typeName) as BufferDictionary)
    }
    ///Sets `Buffer`_ dictionary. obj, mtl and jpg/png files shall be loaded into the dictionay, and be able to be located by relative or absolute paths.
    public func setBufferDictionary(_ bufferDictionary: BufferDictionary) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTargetParameters_setBufferDictionary(cdata_, bufferDictionary.cdata_)
    }
    ///Gets obj file path.
    public func objPath() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTargetParameters_objPath(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Sets obj file path.
    public func setObjPath(_ objPath: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTargetParameters_setObjPath(cdata_, String_to_c(_ar_, objPath).ptr_)
    }
    ///Gets target name. It can be used to distinguish targets.
    public func name() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTargetParameters_name(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Sets target name.
    public func setName(_ name: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTargetParameters_setName(cdata_, String_to_c(_ar_, name).ptr_)
    }
    ///Gets the target uid. You can set this uid in the json config as a method to distinguish from targets.
    public func uid() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTargetParameters_uid(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Sets target uid.
    public func setUid(_ uid: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTargetParameters_setUid(cdata_, String_to_c(_ar_, uid).ptr_)
    }
    ///Gets meta data.
    public func meta() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTargetParameters_meta(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Sets meta data。
    public func setMeta(_ meta: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTargetParameters_setMeta(cdata_, String_to_c(_ar_, meta).ptr_)
    }
    ///Gets the scale of model. The value is the physical scale divided by model coordinate system scale. The default value is 1. (Supposing the unit of model coordinate system is 1 meter.)
    public func scale() -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ObjectTargetParameters_scale(cdata_)
        return _return_value_
    }
    ///Sets the scale of model. The value is the physical scale divided by model coordinate system scale. The default value is 1. (Supposing the unit of model coordinate system is 1 meter.)
    ///It is needed to set the model scale in rendering engine separately.
    public func setScale(_ size: Float) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTargetParameters_setScale(cdata_, size)
    }
}

///ObjectTarget represents 3d object targets that can be tracked by `ObjectTracker`_ .
///The size of ObjectTarget is determined by the `obj` file. You can change it by changing the object `scale`, which is default to 1.
///A ObjectTarget can be tracked by `ObjectTracker`_ after a successful load into the `ObjectTracker`_ using `ObjectTracker.loadTarget`_ .
public class ObjectTarget : Target {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTarget__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_ObjectTarget__dtor(ptr) })
    }
    ///Creates a target from parameters.
    public static func createFromParameters(_ parameters: ObjectTargetParameters) -> ObjectTarget? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfObjectTarget>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTarget_createFromParameters(parameters.cdata_, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_ObjectTarget__typeName) as ObjectTarget) : nil)
    }
    ///Creats a target from obj, mtl and jpg/png files.
    public static func createFromObjectFile(_ path: String, _ storageType: StorageType, _ name: String, _ uid: String, _ meta: String, _ scale: Float) -> ObjectTarget? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfObjectTarget>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTarget_createFromObjectFile(String_to_c(_ar_, path).ptr_, storageType.rawValue, String_to_c(_ar_, name).ptr_, String_to_c(_ar_, uid).ptr_, String_to_c(_ar_, meta).ptr_, scale, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_ObjectTarget__typeName) as ObjectTarget) : nil)
    }
    ///The scale of model. The value is the physical scale divided by model coordinate system scale. The default value is 1. (Supposing the unit of model coordinate system is 1 meter.)
    public func scale() -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ObjectTarget_scale(cdata_)
        return _return_value_
    }
    ///The bounding box of object, it contains the 8 points of the box.
    ///Vertices's indices are defined and stored following the rule:
    ///::
    ///
    ///      4-----7
    ///     /|    /|
    ///    5-----6 |    z
    ///    | |   | |    |
    ///    | 0---|-3    o---y
    ///    |/    |/    /
    ///    1-----2    x
    public func boundingBox() -> [Vec3F] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTarget_boundingBox(cdata_, _return_value_)
        return ListOfVec3F_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfVec3F__dtor(p) })))
    }
    ///Sets model target scale, this will overwrite the value set in the json file or the default value. The value is the physical scale divided by model coordinate system scale. The default value is 1. (Supposing the unit of model coordinate system is 1 meter.)
    ///It is needed to set the model scale in rendering engine separately.
    ///It also should been done before loading ObjectTarget into  `ObjectTracker`_ using `ObjectTracker.loadTarget`_.
    public func setScale(_ scale: Float) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ObjectTarget_setScale(cdata_, scale)
        return _return_value_
    }
    ///Returns the target id. A target id is a integer number generated at runtime. This id is non-zero and increasing globally.
    public override func runtimeID() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ObjectTarget_runtimeID(cdata_)
        return _return_value_
    }
    ///Returns the target uid. A target uid is useful in cloud based algorithms. If no cloud is used, you can set this uid in the json config as a alternative method to distinguish from targets.
    public override func uid() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTarget_uid(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Returns the target name. Name is used to distinguish targets in a json file.
    public override func name() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTarget_name(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Set name. It will erase previously set data or data from cloud.
    public override func setName(_ name: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTarget_setName(cdata_, String_to_c(_ar_, name).ptr_)
    }
    ///Returns the meta data set by setMetaData. Or, in a cloud returned target, returns the meta data set in the cloud server.
    public override func meta() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTarget_meta(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Set meta data. It will erase previously set data or data from cloud.
    public override func setMeta(_ data: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTarget_setMeta(cdata_, String_to_c(_ar_, data).ptr_)
    }
}

///Result of `ObjectTracker`_ .
public class ObjectTrackerResult : TargetTrackerResult {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns the list of `TargetInstance`_ contained in the result.
    public override func targetInstances() -> [TargetInstance] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTrackerResult_targetInstances(cdata_, _return_value_)
        return ListOfTargetInstance_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfTargetInstance__dtor(p) })))
    }
    ///Sets the list of `TargetInstance`_ contained in the result.
    public override func setTargetInstances(_ instances: [TargetInstance]) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTrackerResult_setTargetInstances(cdata_, ListOfTargetInstance_to_c(_ar_, instances).ptr_)
    }
}

///ObjectTracker implements 3D object target detection and tracking.
///ObjectTracker occupies (1 + SimultaneousNum) buffers of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components. Refer to `Overview <Overview.html>`__ .
///After creation, you can call start/stop to enable/disable the track process. start and stop are very lightweight calls.
///When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
///ObjectTracker inputs `FeedbackFrame`_ from feedbackFrameSink. `FeedbackFrameSource`_ shall be connected to feedbackFrameSink for use. Refer to `Overview <Overview.html>`__ .
///Before a `Target`_ can be tracked by ObjectTracker, you have to load it using loadTarget/unloadTarget. You can get load/unload results from callbacks passed into the interfaces.
public class ObjectTracker : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns true.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ObjectTracker_isAvailable()
        return _return_value_
    }
    ///`FeedbackFrame`_ input port. The InputFrame member of FeedbackFrame must have raw image, timestamp, and camera parameters.
    public func feedbackFrameSink() -> FeedbackFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTracker_feedbackFrameSink(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_FeedbackFrameSink__typeName) as FeedbackFrameSink)
    }
    ///Camera buffers occupied in this component.
    public func bufferRequirement() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ObjectTracker_bufferRequirement(cdata_)
        return _return_value_
    }
    ///`OutputFrame`_ output port.
    public func outputFrameSource() -> OutputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTracker_outputFrameSource(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSource__typeName) as OutputFrameSource)
    }
    ///Creates an instance.
    public static func create() -> ObjectTracker {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTracker_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_ObjectTracker__typeName) as ObjectTracker)
    }
    ///Starts the track algorithm.
    public func start() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ObjectTracker_start(cdata_)
        return _return_value_
    }
    ///Stops the track algorithm. Call start to start the track again.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTracker_stop(cdata_)
    }
    ///Close. The component shall not be used after calling close.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTracker_close(cdata_)
    }
    ///Load a `Target`_ into the tracker. A Target can only be tracked by tracker after a successful load.
    ///This method is an asynchronous method. A load operation may take some time to finish and detection of a new/lost target may take more time during the load. The track time after detection will not be affected. If you want to know the load result, you have to handle the callback data. The callback will be called from the thread specified by `CallbackScheduler`_ . It will not block the track thread or any other operations except other load/unload.
    public func loadTarget(_ target: Target, _ callbackScheduler: CallbackScheduler, _ callback: @escaping (Target, Bool) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTracker_loadTarget(cdata_, target.cdata_, callbackScheduler.cdata_, FunctorOfVoidFromTargetAndBool_to_c(callback))
    }
    ///Unload a `Target`_ from the tracker.
    ///This method is an asynchronous method. An unload operation may take some time to finish and detection of a new/lost target may take more time during the unload. If you want to know the unload result, you have to handle the callback data. The callback will be called from the thread specified by `CallbackScheduler`_ . It will not block the track thread or any other operations except other load/unload.
    public func unloadTarget(_ target: Target, _ callbackScheduler: CallbackScheduler, _ callback: @escaping (Target, Bool) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ObjectTracker_unloadTarget(cdata_, target.cdata_, callbackScheduler.cdata_, FunctorOfVoidFromTargetAndBool_to_c(callback))
    }
    ///Returns current loaded targets in the tracker. If an asynchronous load/unload is in progress, the returned value will not reflect the result until all load/unload finish.
    public func targets() -> [Target] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ObjectTracker_targets(cdata_, _return_value_)
        return ListOfTarget_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfTarget__dtor(p) })))
    }
    ///Sets the max number of targets which will be the simultaneously tracked by the tracker. The default value is 1.
    public func setSimultaneousNum(_ num: Int32) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ObjectTracker_setSimultaneousNum(cdata_, num)
        return _return_value_
    }
    ///Gets the max number of targets which will be the simultaneously tracked by the tracker. The default value is 1.
    public func simultaneousNum() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ObjectTracker_simultaneousNum(cdata_)
        return _return_value_
    }
}

public enum CalibrationDownloadStatus : Int32 {
    ///Download successful.
    case Successful = 0
    ///Data is already latest.
    case NotModified = 1
    ///Connection error
    case ConnectionError = 2
    ///Unexpected error
    case UnexpectedError = 3
}

///CalibrationDownloader is used for download and update of calibration data in MotionTracker. The calibration data will only take effect after reallocation of MotionTracker.
public class CalibrationDownloader : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CalibrationDownloader__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_CalibrationDownloader__dtor(ptr) })
    }
    public func download(_ callbackScheduler: CallbackScheduler, _ onCompleted: @escaping (CalibrationDownloadStatus, String?) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CalibrationDownloader_download(cdata_, callbackScheduler.cdata_, FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_to_c(onCompleted))
    }
}

public enum CloudLocalizeStatus : Int32 {
    ///Spatial maps are localized.
    case FoundMaps = 0
    ///No spatial maps are localized.
    case MapsNotFound = 1
    ///Protocol error
    case ProtocolError = 2
    ///Exception caught
    case ExceptionCaught = 3
    ///Request time out (more than 1 minute)
    case RequestTimeout = 4
    ///Request time interval is too low
    case RequestIntervalTooLow = 5
}

public class CloudLocalizeResult : FrameFilterResult {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns localization status.
    public func getLocalizeStatus() -> CloudLocalizeStatus {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudLocalizeResult_getLocalizeStatus(cdata_)
        return CloudLocalizeStatus(rawValue: _return_value_)!
    }
    ///Returns ID of the best correspond localized map.
    public func getLocalizedMapID() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizeResult_getLocalizedMapID(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Returns the name of the best correspond localized map.
    public func getLocalizedMapName() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizeResult_getLocalizedMapName(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Returns the camera pose at the best correspond localized map coordinates.
    public func getPose() -> Matrix44F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudLocalizeResult_getPose(cdata_)
        return Matrix44F_from_c(_return_value_)
    }
    ///Returns the transform from local coordinates (if exists) to the best correspond map coordinates.
    public func getDeltaT() -> Matrix44F? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudLocalizeResult_getDeltaT(cdata_)
        return (_return_value_.has_value ? Matrix44F_from_c(_return_value_.value) : nil)
    }
    ///Returns ID of all localized maps.
    public func getAllLocalizedMapID() -> [String] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizeResult_getAllLocalizedMapID(cdata_, _return_value_)
        return ListOfString_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfString__dtor(p) })))
    }
    ///Returns the camera pose at all localized map coordinates.
    public func getAllPose() -> [Matrix44F] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizeResult_getAllPose(cdata_, _return_value_)
        return ListOfMatrix44F_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfMatrix44F__dtor(p) })))
    }
    ///Returns the transform from local coordinates (if exists) to all map coordinates.
    public func getAllDeltaT() -> [Matrix44F] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizeResult_getAllDeltaT(cdata_, _return_value_)
        return ListOfMatrix44F_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfMatrix44F__dtor(p) })))
    }
    ///Returns extra informations of the localization.
    public func getExtraInfo() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizeResult_getExtraInfo(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Returns detailed exception message.
    public func getExceptionInfo() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizeResult_getExceptionInfo(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Returns the block id of the best correspond localized map.
    public func getLocalizedBlockId() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizeResult_getLocalizedBlockId(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Returns the block timestamp of the best correspond localized map.
    public func getLocalizedBlockTimestamp() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizeResult_getLocalizedBlockTimestamp(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Returns the block location of the best correspond localized map.
    public func getLocalizedBlockLocation() -> Vec3D? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudLocalizeResult_getLocalizedBlockLocation(cdata_)
        return (_return_value_.has_value ? Vec3D_from_c(_return_value_.value) : nil)
    }
    ///Returns the cluster id of the best correspond localized map.
    public func getLocalizedClusterId() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizeResult_getLocalizedClusterId(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Returns the cluster location of the best correspond localized map.
    public func getLocalizedClusterLocation() -> Vec3D? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudLocalizeResult_getLocalizedClusterLocation(cdata_)
        return (_return_value_.has_value ? Vec3D_from_c(_return_value_.value) : nil)
    }
    ///Returns the camera pose in the cluster which the best correspond localized map belongs to.
    public func getPoseInCluster() -> Matrix44F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudLocalizeResult_getPoseInCluster(cdata_)
        return Matrix44F_from_c(_return_value_)
    }
    ///Returns the transform from local coordinates (if exists) to the best correspond map coordinates.
    public func getDeltaTForCluster() -> Matrix44F? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudLocalizeResult_getDeltaTForCluster(cdata_)
        return (_return_value_.has_value ? Matrix44F_from_c(_return_value_.value) : nil)
    }
    ///Returns the location of device.
    public func getDeviceLocation() -> Vec3D? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudLocalizeResult_getDeviceLocation(cdata_)
        return (_return_value_.has_value ? Vec3D_from_c(_return_value_.value) : nil)
    }
}

///CloudLocalizer implements cloud based localization.
public class CloudLocalizer : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns true.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudLocalizer_isAvailable()
        return _return_value_
    }
    ///Creates an instance and connects to the server.
    public static func create(_ server: String, _ apiKey: String, _ apiSecret: String, _ appId: String) -> CloudLocalizer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudLocalizer_create(String_to_c(_ar_, server).ptr_, String_to_c(_ar_, apiKey).ptr_, String_to_c(_ar_, apiSecret).ptr_, String_to_c(_ar_, appId).ptr_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_CloudLocalizer__typeName) as CloudLocalizer)
    }
    ///Send localization request.
    ///Send `InputFrame`_ to resolve a cloud localization. `InputFrame`_ should have at least image data and camera parameters.
    ///message input is a json string.
    ///acceleration is optional which is the readings from device accelerometer.
    ///location is optional which is the readings from device location manager.
    public func resolve(_ inputFrame: InputFrame, _ message: String, _ acceleration: Vec3F?, _ location: Vec3D?, _ callbackScheduler: CallbackScheduler, _ callback: @escaping (CloudLocalizeResult) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CloudLocalizer_resolve(cdata_, inputFrame.cdata_, String_to_c(_ar_, message).ptr_, (acceleration.map({(p) in easyar_OptionalOfVec3F(has_value: true, value: Vec3F_to_c(p))}) ?? easyar_OptionalOfVec3F(has_value: false, value: defaultValue())), (location.map({(p) in easyar_OptionalOfVec3D(has_value: true, value: Vec3D_to_c(p))}) ?? easyar_OptionalOfVec3D(has_value: false, value: defaultValue())), callbackScheduler.cdata_, FunctorOfVoidFromCloudLocalizeResult_to_c(callback))
    }
    ///Stops the localization and closes connection. The component shall not be used after calling close.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CloudLocalizer_close(cdata_)
    }
}

public enum CloudRecognizationStatus : Int32 {
    ///Unknown error
    case UnknownError = 0
    ///A target is recognized.
    case FoundTarget = 1
    ///No target is recognized.
    case TargetNotFound = 2
    ///Reached the access limit
    case ReachedAccessLimit = 3
    ///Request interval too low
    case RequestIntervalTooLow = 4
}

public class CloudRecognizationResult : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns recognition status.
    public func getStatus() -> CloudRecognizationStatus {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudRecognizationResult_getStatus(cdata_)
        return CloudRecognizationStatus(rawValue: _return_value_)!
    }
    ///Returns the recognized target when status is FoundTarget.
    public func getTarget() -> ImageTarget? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfImageTarget>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudRecognizationResult_getTarget(cdata_, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_ImageTarget__typeName) as ImageTarget) : nil)
    }
    ///Returns the error message when status is UnknownError.
    public func getUnknownErrorMessage() -> String? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfString>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudRecognizationResult_getUnknownErrorMessage(cdata_, _return_value_)
        return (_return_value_.pointee.has_value ? String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee.value!, { p in easyar_String__dtor(p) }))) : nil)
    }
}

///CloudRecognizer implements cloud recognition. It can only be used after created a recognition image library on the cloud. Please refer to EasyAR CRS documentation.
///When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
///Before using a CloudRecognizer, an `ImageTracker`_ must be setup and prepared. Any target returned from cloud should be manually put into the `ImageTracker`_ using `ImageTracker.loadTarget`_ if it need to be tracked. Then the target can be used as same as a local target after loaded into the tracker. When a target is recognized, you can get it from callback, and you should use target uid to distinguish different targets. The target runtimeID is dynamically created and cannot be used as unique identifier in the cloud situation.
public class CloudRecognizer : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns true.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CloudRecognizer_isAvailable()
        return _return_value_
    }
    ///Creates an instance and connects to the server.
    public static func create(_ cloudRecognitionServiceServerAddress: String, _ apiKey: String, _ apiSecret: String, _ cloudRecognitionServiceAppId: String) -> CloudRecognizer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudRecognizer_create(String_to_c(_ar_, cloudRecognitionServiceServerAddress).ptr_, String_to_c(_ar_, apiKey).ptr_, String_to_c(_ar_, apiSecret).ptr_, String_to_c(_ar_, cloudRecognitionServiceAppId).ptr_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_CloudRecognizer__typeName) as CloudRecognizer)
    }
    ///Creates an instance and connects to the server with Cloud Secret.
    public static func createByCloudSecret(_ cloudRecognitionServiceServerAddress: String, _ cloudRecognitionServiceSecret: String, _ cloudRecognitionServiceAppId: String) -> CloudRecognizer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CloudRecognizer_createByCloudSecret(String_to_c(_ar_, cloudRecognitionServiceServerAddress).ptr_, String_to_c(_ar_, cloudRecognitionServiceSecret).ptr_, String_to_c(_ar_, cloudRecognitionServiceAppId).ptr_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_CloudRecognizer__typeName) as CloudRecognizer)
    }
    ///Send recognition request. The lowest available request interval is 300ms.
    public func resolve(_ inputFrame: InputFrame, _ callbackScheduler: CallbackScheduler, _ callback: @escaping (CloudRecognizationResult) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CloudRecognizer_resolve(cdata_, inputFrame.cdata_, callbackScheduler.cdata_, FunctorOfVoidFromCloudRecognizationResult_to_c(callback))
    }
    ///Stops the recognition and closes connection. The component shall not be used after calling close.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CloudRecognizer_close(cdata_)
    }
}

///Buffer stores a raw byte array, which can be used to access image data.
///To access image data in Java API, get buffer from `Image`_ and copy to a Java byte array.
///You can always access image data since the first version of EasyAR Sense. Refer to `Image`_ .
public class Buffer : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Wraps a raw memory block. When Buffer is released by all holders, deleter callback will be invoked to execute user-defined memory destruction. deleter must be thread-safe.
    public static func wrap(_ ptr: OpaquePointer?, _ size: Int32, _ deleter: @escaping () -> Void) -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Buffer_wrap(ptr, size, FunctorOfVoid_to_c(deleter), _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Creates a Buffer of specified byte size.
    public static func create(_ size: Int32) -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Buffer_create(size, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Returns raw data address.
    public func data() -> OpaquePointer? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Buffer_data(cdata_)
        return _return_value_
    }
    ///Byte size of raw data.
    public func size() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Buffer_size(cdata_)
        return _return_value_
    }
    ///Copies raw memory. It can be used in languages or platforms without complete support for memory operations.
    public static func memoryCopy(_ src: OpaquePointer?, _ dest: OpaquePointer?, _ length: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Buffer_memoryCopy(src, dest, length)
    }
    ///Tries to copy data from a raw memory address into Buffer. If copy succeeds, it returns true, or else it returns false. Possible failure causes includes: source or destination data range overflow.
    public func tryCopyFrom(_ src: OpaquePointer?, _ srcIndex: Int32, _ index: Int32, _ length: Int32) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Buffer_tryCopyFrom(cdata_, src, srcIndex, index, length)
        return _return_value_
    }
    ///Tries to copy data from Buffer to user array. If copy succeeds, it returns true, or else it returns false. Possible failure causes includes: source or destination data range overflow.
    public func tryCopyTo(_ index: Int32, _ dest: OpaquePointer?, _ destIndex: Int32, _ length: Int32) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Buffer_tryCopyTo(cdata_, index, dest, destIndex, length)
        return _return_value_
    }
    ///Creates a sub-buffer with a reference to the original Buffer. A Buffer will only be released after all its sub-buffers are released.
    public func partition(_ index: Int32, _ length: Int32) -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Buffer_partition(cdata_, index, length, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    public func tryCopyFromByteArray(_ src: [UInt8]) -> Bool {
        return tryCopyFromByteArray(src, 0, 0, Int32(src.count))
    }
    public func tryCopyFromByteArray(_ src: [UInt8], _ srcIndex: Int32, _ index: Int32, _ length: Int32) -> Bool {
        let srcSize = src.count
        let destSize = size()
        if (length < 0) || (srcIndex < 0) || (srcIndex > srcSize) || (srcIndex + length > srcSize) || (index < 0) || (index > destSize) || (index + length > destSize) {
            return false
        }
        if length == 0 { return true }
        var result = false
        src.withUnsafeBytes { p -> Void in
            result = tryCopyFrom(OpaquePointer(p.baseAddress!), srcIndex, index, length)
        }
        return result
    }
    public func tryCopyToByteArray(_ dest: [UInt8]) -> Bool {
        return tryCopyToByteArray(0, dest, 0, Int32(dest.count))
    }
    public func tryCopyToByteArray(_ index: Int32, _ dest: [UInt8], _ destIndex: Int32, _ length: Int32) -> Bool {
        let srcSize = size()
        let destSize = dest.count
        if (length < 0) || (index < 0) || (index > srcSize) || (index + length > srcSize) || (destIndex < 0) || (destIndex > destSize) || (destIndex + length > destSize) {
            return false
        }
        if length == 0 { return true }
        var result = false
        dest.withUnsafeBytes { p -> Void in
            result = tryCopyTo(0, OpaquePointer(p.baseAddress!), destIndex, length)
        }
        return result
    }
}

///A mapping from file path to `Buffer`_ . It can be used to represent multiple files in the memory.
public class BufferDictionary : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_BufferDictionary__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_BufferDictionary__dtor(ptr) })
    }
    ///Current file count.
    public func count() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_BufferDictionary_count(cdata_)
        return _return_value_
    }
    ///Checks if a specified path is in the dictionary.
    public func contains(_ path: String) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_BufferDictionary_contains(cdata_, String_to_c(_ar_, path).ptr_)
        return _return_value_
    }
    ///Tries to get the corresponding `Buffer`_ for a specified path.
    public func tryGet(_ path: String) -> Buffer? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfBuffer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_BufferDictionary_tryGet(cdata_, String_to_c(_ar_, path).ptr_, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_Buffer__typeName) as Buffer) : nil)
    }
    ///Sets `Buffer`_ for a specified path.
    public func set(_ path: String, _ buffer: Buffer) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_BufferDictionary_set(cdata_, String_to_c(_ar_, path).ptr_, buffer.cdata_)
    }
    ///Removes a specified path.
    public func remove(_ path: String) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_BufferDictionary_remove(cdata_, String_to_c(_ar_, path).ptr_)
        return _return_value_
    }
    ///Clears the dictionary.
    public func clear() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_BufferDictionary_clear(cdata_)
    }
}

///BufferPool is a memory pool to reduce memory allocation time consumption for functionality like custom camera interoperability, which needs to allocate memory buffers of a fixed size repeatedly.
public class BufferPool : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///block_size is the byte size of each `Buffer`_ .
    ///capacity is the maximum count of `Buffer`_ .
    public convenience init(_ block_size: Int32, _ capacity: Int32) {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_BufferPool__ctor(block_size, capacity, _return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_BufferPool__dtor(ptr) })
    }
    ///The byte size of each `Buffer`_ .
    public func block_size() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_BufferPool_block_size(cdata_)
        return _return_value_
    }
    ///The maximum count of `Buffer`_ .
    public func capacity() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_BufferPool_capacity(cdata_)
        return _return_value_
    }
    ///Current acquired count of `Buffer`_ .
    public func size() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_BufferPool_size(cdata_)
        return _return_value_
    }
    ///Tries to acquire a memory block. If current acquired count of `Buffer`_ does not reach maximum, a new `Buffer`_ is fetched or allocated, or else null is returned.
    public func tryAcquire() -> Buffer? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfBuffer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_BufferPool_tryAcquire(cdata_, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_Buffer__typeName) as Buffer) : nil)
    }
}

public enum CameraDeviceType : Int32 {
    ///Unknown location
    case Unknown = 0
    ///Rear camera
    case Back = 1
    ///Front camera
    case Front = 2
}

///MotionTrackingStatus describes the quality of device motion tracking.
public enum MotionTrackingStatus : Int32 {
    ///Result is not available and should not to be used to render virtual objects or do 3D reconstruction. This value occurs temporarily after initializing, tracking lost or relocalizing.
    case NotTracking = 0
    ///Tracking is available, but the quality of the result is not good enough. This value occurs temporarily due to weak texture or excessive movement. The result can be used to render virtual objects, but should generally not be used to do 3D reconstruction.
    case Limited = 1
    ///Tracking with a good quality. The result can be used to render virtual objects or do 3D reconstruction.
    case Tracking = 2
}

///Camera parameters, including image size, focal length, principal point, camera type and camera rotation against natural orientation.
public class CameraParameters : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init(_ imageSize: Vec2I, _ focalLength: Vec2F, _ principalPoint: Vec2F, _ cameraDeviceType: CameraDeviceType, _ cameraOrientation: Int32) {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CameraParameters__ctor(Vec2I_to_c(imageSize), Vec2F_to_c(focalLength), Vec2F_to_c(principalPoint), cameraDeviceType.rawValue, cameraOrientation, _return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_CameraParameters__dtor(ptr) })
    }
    ///Image size.
    public func size() -> Vec2I {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_size(cdata_)
        return Vec2I_from_c(_return_value_)
    }
    ///Focal length, the distance from effective optical center to CCD plane, divided by unit pixel density in width and height directions. The unit is pixel.
    public func focalLength() -> Vec2F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_focalLength(cdata_)
        return Vec2F_from_c(_return_value_)
    }
    ///Principal point, coordinates of the intersection point of principal axis on CCD plane against the left-top corner of the image. The unit is pixel.
    public func principalPoint() -> Vec2F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_principalPoint(cdata_)
        return Vec2F_from_c(_return_value_)
    }
    ///Camera device type. Default, back or front camera. On desktop devices, there are only default cameras. On mobile devices, there is a differentiation between back and front cameras.
    public func cameraDeviceType() -> CameraDeviceType {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_cameraDeviceType(cdata_)
        return CameraDeviceType(rawValue: _return_value_)!
    }
    ///Camera rotation against device natural orientation.
    ///For Android phones and some Android tablets, this value is 90 degrees.
    ///For Android eye-wear and some Android tablets, this value is 0 degrees.
    ///For all current iOS devices, this value is 90 degrees.
    public func cameraOrientation() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_cameraOrientation(cdata_)
        return _return_value_
    }
    ///Creates CameraParameters with default camera intrinsics. Default intrinsics are calculated by image size, which is not very precise.
    public static func createWithDefaultIntrinsics(_ imageSize: Vec2I, _ cameraDeviceType: CameraDeviceType, _ cameraOrientation: Int32) -> CameraParameters {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CameraParameters_createWithDefaultIntrinsics(Vec2I_to_c(imageSize), cameraDeviceType.rawValue, cameraOrientation, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_CameraParameters__typeName) as CameraParameters)
    }
    ///Get equivalent CameraParameters for a different camera image size.
    public func getResized(_ imageSize: Vec2I) -> CameraParameters {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CameraParameters_getResized(cdata_, Vec2I_to_c(imageSize), _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_CameraParameters__typeName) as CameraParameters)
    }
    ///Calculates the angle required to rotate the camera image clockwise to align it with the screen.
    ///screenRotation is the angle of rotation of displaying screen image against device natural orientation in clockwise in degrees.
    ///For iOS(UIInterfaceOrientationPortrait as natural orientation):
    ///* UIInterfaceOrientationPortrait: rotation = 0
    ///* UIInterfaceOrientationLandscapeRight: rotation = 90
    ///* UIInterfaceOrientationPortraitUpsideDown: rotation = 180
    ///* UIInterfaceOrientationLandscapeLeft: rotation = 270
    ///For Android:
    ///* Surface.ROTATION_0 = 0
    ///* Surface.ROTATION_90 = 90
    ///* Surface.ROTATION_180 = 180
    ///* Surface.ROTATION_270 = 270
    public func imageOrientation(_ screenRotation: Int32) -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_imageOrientation(cdata_, screenRotation)
        return _return_value_
    }
    ///Calculates whether the image needed to be flipped horizontally. The image is rotated, then flipped in rendering. When cameraDeviceType is front, a flip is automatically applied. Pass manualHorizontalFlip with true to add a manual flip.
    public func imageHorizontalFlip(_ manualHorizontalFlip: Bool) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_imageHorizontalFlip(cdata_, manualHorizontalFlip)
        return _return_value_
    }
    ///Calculates the perspective projection matrix needed by virtual object rendering. The projection transforms points from camera coordinate system to clip coordinate system ([-1, 1]^4). The form of perspective projection matrix is the same as OpenGL, that matrix multiply column vector of homogeneous coordinates of point on the right, ant not like Direct3D, that matrix multiply row vector of homogeneous coordinates of point on the left. But data arrangement is row-major, not like OpenGL's column-major. Clip coordinate system and normalized device coordinate system are defined as the same as OpenGL's default.
    public func projection(_ nearPlane: Float, _ farPlane: Float, _ viewportAspectRatio: Float, _ screenRotation: Int32, _ combiningFlip: Bool, _ manualHorizontalFlip: Bool) -> Matrix44F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_projection(cdata_, nearPlane, farPlane, viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip)
        return Matrix44F_from_c(_return_value_)
    }
    ///Calculates the orthogonal projection matrix needed by camera background rendering. The projection transforms points from image quad coordinate system ([-1, 1]^2) to clip coordinate system ([-1, 1]^4), with the undefined two dimensions unchanged. The form of orthogonal projection matrix is the same as OpenGL, that matrix multiply column vector of homogeneous coordinates of point on the right, ant not like Direct3D, that matrix multiply row vector of homogeneous coordinates of point on the left. But data arrangement is row-major, not like OpenGL's column-major. Clip coordinate system and normalized device coordinate system are defined as the same as OpenGL's default.
    public func imageProjection(_ viewportAspectRatio: Float, _ screenRotation: Int32, _ combiningFlip: Bool, _ manualHorizontalFlip: Bool) -> Matrix44F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_imageProjection(cdata_, viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip)
        return Matrix44F_from_c(_return_value_)
    }
    ///Transforms points from image coordinate system ([0, 1]^2) to screen coordinate system ([0, 1]^2). Both coordinate system is x-left, y-down, with origin at left-top.
    public func screenCoordinatesFromImageCoordinates(_ viewportAspectRatio: Float, _ screenRotation: Int32, _ combiningFlip: Bool, _ manualHorizontalFlip: Bool, _ imageCoordinates: Vec2F) -> Vec2F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_screenCoordinatesFromImageCoordinates(cdata_, viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip, Vec2F_to_c(imageCoordinates))
        return Vec2F_from_c(_return_value_)
    }
    ///Transforms points from screen coordinate system ([0, 1]^2) to image coordinate system ([0, 1]^2). Both coordinate system is x-left, y-down, with origin at left-top.
    public func imageCoordinatesFromScreenCoordinates(_ viewportAspectRatio: Float, _ screenRotation: Int32, _ combiningFlip: Bool, _ manualHorizontalFlip: Bool, _ screenCoordinates: Vec2F) -> Vec2F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_imageCoordinatesFromScreenCoordinates(cdata_, viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip, Vec2F_to_c(screenCoordinates))
        return Vec2F_from_c(_return_value_)
    }
    ///Checks if two groups of parameters are equal.
    public func equalsTo(_ other: CameraParameters) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraParameters_equalsTo(cdata_, other.cdata_)
        return _return_value_
    }
}

///PixelFormat represents the format of image pixel data. All formats follow the pixel direction from left to right and from top to bottom.
public enum PixelFormat : Int32 {
    ///Unknown
    case Unknown = 0
    ///256 shades grayscale
    case Gray = 1
    ///YUV_NV21
    case YUV_NV21 = 2
    ///YUV_NV12
    case YUV_NV12 = 3
    ///YUV_I420
    case YUV_I420 = 4
    ///YUV_YV12
    case YUV_YV12 = 5
    ///RGB888
    case RGB888 = 6
    ///BGR888
    case BGR888 = 7
    ///RGBA8888
    case RGBA8888 = 8
    ///BGRA8888
    case BGRA8888 = 9
}

///Image stores an image data and represents an image in memory.
///Image raw data can be accessed as byte array. The width/height/etc information are also accessible.
///You can always access image data since the first version of EasyAR Sense.
///
///You can do this in iOS
///::
///
///    #import <easyar/buffer.oc.h>
///    #import <easyar/image.oc.h>
///
///    easyar_OutputFrame * outputFrame = [outputFrameBuffer peek];
///    if (outputFrame != nil) {
///        easyar_Image * i = [[outputFrame inputFrame] image];
///        easyar_Buffer * b = [i buffer];
///        char * bytes = calloc([b size], 1);
///        memcpy(bytes, [b data], [b size]);
///        // use bytes here
///        free(bytes);
///    }
///
///Or in Android
///::
///
///    import cn.easyar.*;
///
///    OutputFrame outputFrame = outputFrameBuffer.peek();
///    if (outputFrame != null) {
///        InputFrame inputFrame = outputFrame.inputFrame();
///        Image i = inputFrame.image();
///        Buffer b = i.buffer();
///        byte[] bytes = new byte[b.size()];
///        b.copyToByteArray(0, bytes, 0, bytes.length);
///        // use bytes here
///        b.dispose();
///        i.dispose();
///        inputFrame.dispose();
///        outputFrame.dispose();
///    }
public class Image : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init(_ buffer: Buffer, _ format: PixelFormat, _ width: Int32, _ height: Int32) {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Image__ctor(buffer.cdata_, format.rawValue, width, height, _return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_Image__dtor(ptr) })
    }
    ///Returns buffer inside image. It can be used to access internal data of image. The content of `Buffer`_ shall not be modified, as they may be accessed from other threads.
    public func buffer() -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Image_buffer(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Returns image format.
    public func format() -> PixelFormat {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Image_format(cdata_)
        return PixelFormat(rawValue: _return_value_)!
    }
    ///Returns image width.
    public func width() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Image_width(cdata_)
        return _return_value_
    }
    ///Returns image height.
    public func height() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Image_height(cdata_)
        return _return_value_
    }
}

///Square matrix of 4. The data arrangement is row-major.
public struct Matrix44F {
    ///The raw data of matrix.
    public var data: (Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, Float)

    public init(_ data_0: Float, _ data_1: Float, _ data_2: Float, _ data_3: Float, _ data_4: Float, _ data_5: Float, _ data_6: Float, _ data_7: Float, _ data_8: Float, _ data_9: Float, _ data_10: Float, _ data_11: Float, _ data_12: Float, _ data_13: Float, _ data_14: Float, _ data_15: Float) {
        self.data = (data_0, data_1, data_2, data_3, data_4, data_5, data_6, data_7, data_8, data_9, data_10, data_11, data_12, data_13, data_14, data_15);
    }
}

///Square matrix of 3. The data arrangement is row-major.
public struct Matrix33F {
    ///The raw data of matrix.
    public var data: (Float, Float, Float, Float, Float, Float, Float, Float, Float)

    public init(_ data_0: Float, _ data_1: Float, _ data_2: Float, _ data_3: Float, _ data_4: Float, _ data_5: Float, _ data_6: Float, _ data_7: Float, _ data_8: Float) {
        self.data = (data_0, data_1, data_2, data_3, data_4, data_5, data_6, data_7, data_8);
    }
}

///3 dimensional vector of double.
public struct Vec3D {
    ///The raw data of vector.
    public var data: (Double, Double, Double)

    public init(_ data_0: Double, _ data_1: Double, _ data_2: Double) {
        self.data = (data_0, data_1, data_2);
    }
}

///4 dimensional vector of float.
public struct Vec4F {
    ///The raw data of vector.
    public var data: (Float, Float, Float, Float)

    public init(_ data_0: Float, _ data_1: Float, _ data_2: Float, _ data_3: Float) {
        self.data = (data_0, data_1, data_2, data_3);
    }
}

///3 dimensional vector of float.
public struct Vec3F {
    ///The raw data of vector.
    public var data: (Float, Float, Float)

    public init(_ data_0: Float, _ data_1: Float, _ data_2: Float) {
        self.data = (data_0, data_1, data_2);
    }
}

///2 dimensional vector of float.
public struct Vec2F {
    ///The raw data of vector.
    public var data: (Float, Float)

    public init(_ data_0: Float, _ data_1: Float) {
        self.data = (data_0, data_1);
    }
}

///4 dimensional vector of int.
public struct Vec4I {
    ///The raw data of vector.
    public var data: (Int32, Int32, Int32, Int32)

    public init(_ data_0: Int32, _ data_1: Int32, _ data_2: Int32, _ data_3: Int32) {
        self.data = (data_0, data_1, data_2, data_3);
    }
}

///2 dimensional vector of int.
public struct Vec2I {
    ///The raw data of vector.
    public var data: (Int32, Int32)

    public init(_ data_0: Int32, _ data_1: Int32) {
        self.data = (data_0, data_1);
    }
}

///DenseSpatialMap is used to reconstruct the environment accurately and densely. The reconstructed model is represented by `triangle mesh`, which is denoted simply by `mesh`.
///DenseSpatialMap occupies 1 buffers of camera.
public class DenseSpatialMap : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns True when the device supports dense reconstruction, otherwise returns False.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_DenseSpatialMap_isAvailable()
        return _return_value_
    }
    ///Input port for input frame. For DenseSpatialMap to work, the inputFrame must include image and it's camera parameters and spatial information (cameraTransform and trackingStatus). See also `InputFrameSink`_ .
    public func inputFrameSink() -> InputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_DenseSpatialMap_inputFrameSink(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSink__typeName) as InputFrameSink)
    }
    ///Camera buffers occupied in this component.
    public func bufferRequirement() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_DenseSpatialMap_bufferRequirement(cdata_)
        return _return_value_
    }
    ///Create `DenseSpatialMap`_ object.
    public static func create() -> DenseSpatialMap {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_DenseSpatialMap_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_DenseSpatialMap__typeName) as DenseSpatialMap)
    }
    ///Start or continue runninng `DenseSpatialMap`_ algorithm.
    public func start() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_DenseSpatialMap_start(cdata_)
        return _return_value_
    }
    ///Pause the reconstruction algorithm. Call `start` to resume reconstruction.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_DenseSpatialMap_stop(cdata_)
    }
    ///Close `DenseSpatialMap`_ algorithm.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_DenseSpatialMap_close(cdata_)
    }
    ///Get the mesh management object of type `SceneMesh`_ . The contents will automatically update after calling the `DenseSpatialMap.updateSceneMesh`_ function.
    public func getMesh() -> SceneMesh {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_DenseSpatialMap_getMesh(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_SceneMesh__typeName) as SceneMesh)
    }
    ///Get the lastest updated mesh and save it to the `SceneMesh`_ object obtained by `DenseSpatialMap.getMesh`_ .
    ///The parameter `updateMeshAll` indicates whether to perform a `full update` or an `incremental update`. When `updateMeshAll` is True, `full update` is performed. All meshes are saved to `SceneMesh`_ . When `updateMeshAll` is False, `incremental update` is performed, and only the most recently updated mesh is saved to `SceneMesh`_ .
    ///`Full update` will take extra time and memory space, causing performance degradation.
    public func updateSceneMesh(_ updateMeshAll: Bool) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_DenseSpatialMap_updateSceneMesh(cdata_, updateMeshAll)
        return _return_value_
    }
}

///The dense reconstructed model is represented by triangle mesh, or simply denoted as mesh. Because mesh updates frequently, in order to ensure efficiency, the mesh of the whole reconstruction model is divided into many mesh blocks. A mesh block is composed of a cube about 1 meter long, with attributes such as vertices and indices.
///
///BlockInfo is used to describe the content of a mesh block. (x, y, z) is the index of mesh block, the coordinates of a mesh block's origin in world coordinate system can be obtained by  multiplying (x, y, z) by the physical size of mesh block. You may filter the part you want to display in advance by the mesh block's world coordinates for the sake of saving rendering time.
public struct BlockInfo {
    ///x in index (x, y, z) of mesh block.
    public var x: Int32
    ///y in index (x, y, z) of mesh block.
    public var y: Int32
    ///z in index (x, y, z) of mesh block.
    public var z: Int32
    ///Number of vertices in a mesh block.
    public var numOfVertex: Int32
    ///startPointOfVertex is the starting position of the vertex data stored in the vertex buffer, indicating from where the stored vertices belong to current mesh block. It is not equal to the number of bytes of the offset from the beginning of vertex buffer. The offset is startPointOfVertex*3*4 bytes.
    public var startPointOfVertex: Int32
    ///The number of indices in a mesh block. Each of three consecutive vertices form a triangle.
    public var numOfIndex: Int32
    ///Similar to startPointOfVertex. startPointOfIndex is the starting position of the index data stored in the index buffer, indicating from where the stored indices belong to current mesh block. It is not equal to the number of bytes of the offset from the beginning of index buffer. The offset is startPointOfIndex*3*4 bytes.
    public var startPointOfIndex: Int32
    ///Version represents how many times the mesh block has updated. The larger the version, the newer the block. If the version of a mesh block increases after calling `DenseSpatialMap.updateSceneMesh`_ , it indicates that the mash block has changed.
    public var version: Int32

    public init(_ x: Int32, _ y: Int32, _ z: Int32, _ numOfVertex: Int32, _ startPointOfVertex: Int32, _ numOfIndex: Int32, _ startPointOfIndex: Int32, _ version: Int32) {
        self.x = x;
        self.y = y;
        self.z = z;
        self.numOfVertex = numOfVertex;
        self.startPointOfVertex = startPointOfVertex;
        self.numOfIndex = numOfIndex;
        self.startPointOfIndex = startPointOfIndex;
        self.version = version;
    }
}

///SceneMesh is used to manage and preserve the results of `DenseSpatialMap`_.
///There are two kinds of meshes saved in SceneMesh, one is the mesh of the whole reconstructed scene, hereinafter referred to as `meshAll`, the other is the recently updated mesh, hereinafter referred to as `meshUpdated`. `meshAll` is a whole mesh, including all vertex data and index data, etc. `meshUpdated` is composed of several `mesh block` s, each `mesh block` is a cube, which contains the mesh formed by the object surface in the corresponding cube space.
///`meshAll` is available only when the `DenseSpatialMap.updateSceneMesh`_ method is called specifying that all meshes need to be updated. If `meshAll` has been updated previously and not updated in recent times, the data in `meshAll` is remain the same.
public class SceneMesh : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Get the number of vertices in `meshAll`.
    public func getNumOfVertexAll() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SceneMesh_getNumOfVertexAll(cdata_)
        return _return_value_
    }
    ///Get the number of indices in `meshAll`. Since every 3 indices form a triangle, the returned value should be a multiple of 3.
    public func getNumOfIndexAll() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SceneMesh_getNumOfIndexAll(cdata_)
        return _return_value_
    }
    ///Get the position component of the vertices in `meshAll` (in the world coordinate system). The position of a vertex is described by three coordinates (x, y, z) in meters. The position data are stored tightly in `Buffer`_ by `x1, y1, z1, x2, y2, z2, ...` Each component is of `float` type.
    public func getVerticesAll() -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SceneMesh_getVerticesAll(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Get the normal component of vertices in `meshAll`. The normal of a vertex is described by three components (nx, ny, nz). The normal is normalized, that is, the length is 1. Normal data are stored tightly in `Buffer`_ by `nx1, ny1, nz1, nx2, ny2, nz2,....` Each component is of `float` type.
    public func getNormalsAll() -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SceneMesh_getNormalsAll(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Get the index data in `meshAll`. Each triangle is composed of three indices (ix, iy, iz). Indices are stored tightly in `Buffer`_ by `ix1, iy1, iz1, ix2, iy2, iz2,...` Each component is of `int32` type.
    public func getIndicesAll() -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SceneMesh_getIndicesAll(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Get the number of vertices in `meshUpdated`.
    public func getNumOfVertexIncremental() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SceneMesh_getNumOfVertexIncremental(cdata_)
        return _return_value_
    }
    ///Get the number of indices in `meshUpdated`. Since every 3 indices form a triangle, the returned value should be a multiple of 3.
    public func getNumOfIndexIncremental() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SceneMesh_getNumOfIndexIncremental(cdata_)
        return _return_value_
    }
    ///Get the position component of the vertices in `meshUpdated` (in the world coordinate system). The position of a vertex is described by three coordinates (x, y, z) in meters. The position data are stored tightly in `Buffer`_ by `x1, y1, z1, x2, y2, z2, ...` Each component is of `float` type.
    public func getVerticesIncremental() -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SceneMesh_getVerticesIncremental(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Get the normal component of vertices in `meshUpdated`. The normal of a vertex is described by three components (nx, ny, nz). The normal is normalized, that is, the length is 1. Normal data are stored tightly in `Buffer`_ by `nx1, ny1, nz1, nx2, ny2, nz2,....` Each component is of `float` type.
    public func getNormalsIncremental() -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SceneMesh_getNormalsIncremental(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Get the index data in `meshUpdated`. Each triangle is composed of three indices (ix, iy, iz). Indices are stored tightly in `Buffer`_ by `ix1, iy1, iz1, ix2, iy2, iz2,...` Each component is of `int32` type.
    public func getIndicesIncremental() -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SceneMesh_getIndicesIncremental(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Gets the description object of `mesh block` in `meshUpdate`. The return value is an array of `BlockInfo`_ elements, each of which is a detailed description of a `mesh block`.
    public func getBlocksInfoIncremental() -> [BlockInfo] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SceneMesh_getBlocksInfoIncremental(cdata_, _return_value_)
        return ListOfBlockInfo_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfBlockInfo__dtor(p) })))
    }
    ///Get the edge length of a `mesh block` in meters.
    public func getBlockDimensionInMeters() -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SceneMesh_getBlockDimensionInMeters(cdata_)
        return _return_value_
    }
}

///Accelerometer reading.
///
///The positive direction of x-axis is from the device center to its right side of the screen.
///The positive direction of y-axis is from the device center to its top side of the screen.
///The positive direction of z-axis is from the device center perpendicular to the screen outward.
///
///The unit of x, y, z is m/s^2.
///The unit of timestamp is second.
public struct AccelerometerResult {
    public var x: Float
    public var y: Float
    public var z: Float
    public var timestamp: Double

    public init(_ x: Float, _ y: Float, _ z: Float, _ timestamp: Double) {
        self.x = x;
        self.y = y;
        self.z = z;
        self.timestamp = timestamp;
    }
}

///Accelerometer calls the accelerometer provided by the operating system, and outputs `AccelerometerResult`_ .
///When it is not needed anymore, call close function to close it. It shall not be used after calling close.
///It is not recommended to open the accelerometer multiple times simultaneously, which may cause failure on open or cause precision downgrade.
public class Accelerometer : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Accelerometer__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_Accelerometer__dtor(ptr) })
    }
    ///Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
    public func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Accelerometer_isAvailable(cdata_)
        return _return_value_
    }
    ///Opens the device. Sampling period is defined by implementation. If failed, it will return false.
    public func `open`() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Accelerometer_open(cdata_)
        return _return_value_
    }
    ///Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
    public func openWithSamplingPeriod(_ samplingPeriodMilliseconds: Int32) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Accelerometer_openWithSamplingPeriod(cdata_, samplingPeriodMilliseconds)
        return _return_value_
    }
    ///Closes. It shall not be used after calling close.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Accelerometer_close(cdata_)
    }
    ///Gets the most recent result. If there is no result, it returns empty.
    public func getCurrentResult() -> AccelerometerResult? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Accelerometer_getCurrentResult(cdata_)
        return (_return_value_.has_value ? AccelerometerResult_from_c(_return_value_.value) : nil)
    }
}

public enum ARCoreCameraDeviceFocusMode : Int32 {
    ///Auto focus mode
    case Auto = 0
    ///Fixed focus mode
    case Fixed = 1
}

///ARCoreCameraDevice implements a camera device based on ARCore, which outputs `InputFrame`_  (including image, camera parameters, timestamp, 6DOF location, and tracking status).
///Loading of libarcore_sdk_c.so with java.lang.System.loadLibrary is required.
///After creation, start/stop can be invoked to start or stop video stream capture.
///When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
///ARCoreCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use. Refer to `Overview <Overview.html>`__ .
///bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck. Refer to `Overview <Overview.html>`__ .
///Caution: Currently, ARCore(v1.13.0) has memory leaks on creating and destroying sessions. Repeated creations and destructions will cause an increasing and non-reclaimable memory footprint.
public class ARCoreCameraDevice : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ARCoreCameraDevice__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_ARCoreCameraDevice__dtor(ptr) })
    }
    ///Checks if the component is available. It returns true only on Android when ARCore is installed.
    ///If called with libarcore_sdk_c.so not loaded, it returns false.
    ///Notice: If ARCore is not supported on the device but ARCore apk is installed via side-loading, it will return true, but ARCore will not function properly.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ARCoreCameraDevice_isAvailable()
        return _return_value_
    }
    ///`InputFrame`_ buffer capacity. The default is 8.
    public func bufferCapacity() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ARCoreCameraDevice_bufferCapacity(cdata_)
        return _return_value_
    }
    ///Sets `InputFrame`_ buffer capacity.
    public func setBufferCapacity(_ capacity: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ARCoreCameraDevice_setBufferCapacity(cdata_, capacity)
    }
    ///`InputFrame`_ output port.
    public func inputFrameSource() -> InputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ARCoreCameraDevice_inputFrameSource(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSource__typeName) as InputFrameSource)
    }
    ///Sets focus mode to focusMode. Call before start.
    public func setFocusMode(_ focusMode: ARCoreCameraDeviceFocusMode) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ARCoreCameraDevice_setFocusMode(cdata_, focusMode.rawValue)
    }
    ///Starts video stream capture.
    public func start() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ARCoreCameraDevice_start(cdata_)
        return _return_value_
    }
    ///Stops video stream capture.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ARCoreCameraDevice_stop(cdata_)
    }
    ///Close. The component shall not be used after calling close.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ARCoreCameraDevice_close(cdata_)
    }
}

public enum ARKitCameraDeviceFocusMode : Int32 {
    ///Auto focus mode
    case Auto = 0
    ///Fixed focus mode
    case Fixed = 1
}

///ARKitCameraDevice implements a camera device based on ARKit, which outputs `InputFrame`_ (including image, camera parameters, timestamp, 6DOF location, and tracking status).
///After creation, start/stop can be invoked to start or stop data collection.
///When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
///ARKitCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use. Refer to `Overview <Overview.html>`__ .
///bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck. Refer to `Overview <Overview.html>`__ .
public class ARKitCameraDevice : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ARKitCameraDevice__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_ARKitCameraDevice__dtor(ptr) })
    }
    ///Checks if the component is available. It returns true only on iOS 11 or later when ARKit is supported by hardware.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ARKitCameraDevice_isAvailable()
        return _return_value_
    }
    ///`InputFrame`_ buffer capacity. The default is 8.
    public func bufferCapacity() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ARKitCameraDevice_bufferCapacity(cdata_)
        return _return_value_
    }
    ///Sets `InputFrame`_ buffer capacity.
    public func setBufferCapacity(_ capacity: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ARKitCameraDevice_setBufferCapacity(cdata_, capacity)
    }
    ///`InputFrame`_ output port.
    public func inputFrameSource() -> InputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ARKitCameraDevice_inputFrameSource(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSource__typeName) as InputFrameSource)
    }
    ///Sets focus mode to focusMode. Call before start. Valid since iOS 11.3.
    public func setFocusMode(_ focusMode: ARKitCameraDeviceFocusMode) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ARKitCameraDevice_setFocusMode(cdata_, focusMode.rawValue)
    }
    ///Starts video stream capture.
    public func start() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ARKitCameraDevice_start(cdata_)
        return _return_value_
    }
    ///Stops video stream capture.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ARKitCameraDevice_stop(cdata_)
    }
    ///Close. The component shall not be used after calling close.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ARKitCameraDevice_close(cdata_)
    }
}

public enum CameraDeviceFocusMode : Int32 {
    ///Normal auto focus mode. You should call autoFocus to start the focus in this mode.
    case Normal = 0
    ///Continuous auto focus mode
    case Continousauto = 2
    ///Infinity focus mode
    case Infinity = 3
    ///Macro (close-up) focus mode. You should call autoFocus to start the focus in this mode.
    case Macro = 4
    ///Medium distance focus mode
    case Medium = 5
}

public enum AndroidCameraApiType : Int32 {
    ///Android Camera1
    case Camera1 = 0
    ///Android Camera2
    case Camera2 = 1
}

public enum CameraDevicePresetProfile : Int32 {
    ///The same as AVCaptureSessionPresetPhoto.
    case Photo = 0
    ///The same as AVCaptureSessionPresetHigh.
    case High = 1
    ///The same as AVCaptureSessionPresetMedium.
    case Medium = 2
    ///The same as AVCaptureSessionPresetLow.
    case Low = 3
}

public enum CameraState : Int32 {
    ///Unknown
    case Unknown = 0x00000000
    ///Disconnected
    case Disconnected = 0x00000001
    ///Preempted by another application.
    case Preempted = 0x00000002
}

///CameraDevice implements a camera device, which outputs `InputFrame`_ (including image, camera paramters, and timestamp). It is available on Windows, Mac, Android and iOS.
///After open, start/stop can be invoked to start or stop data collection. start/stop will not change previous set camera parameters.
///When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
///CameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use. Refer to `Overview <Overview.html>`__ .
///bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck. Refer to `Overview <Overview.html>`__ .
///On Android, it is required to add android.permission.CAMERA to AndroidManifest.xml for use.
///On iOS, it is required to add NSCameraUsageDescription to Info.plist for use.
public class CameraDevice : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CameraDevice__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_CameraDevice__dtor(ptr) })
    }
    ///Checks if the component is available. It returns true only on Windows, Mac, Android or iOS.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_isAvailable()
        return _return_value_
    }
    ///Gets current camera API (camera1 or camera2) on Android. camera1 is better for compatibility, but lacks some necessary information such as timestamp. camera2 has compatibility issues on some devices.
    public func androidCameraApiType() -> AndroidCameraApiType {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_androidCameraApiType(cdata_)
        return AndroidCameraApiType(rawValue: _return_value_)!
    }
    ///Sets current camera API (camera1 or camera2) on Android. It must be called before calling openWithIndex, openWithSpecificType or openWithPreferredType, or it will not take effect.
    ///It is recommended to use `CameraDeviceSelector`_ to create camera with camera API set to recommended based on primary algorithm to run.
    public func setAndroidCameraApiType(_ type: AndroidCameraApiType) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CameraDevice_setAndroidCameraApiType(cdata_, type.rawValue)
    }
    ///`InputFrame`_ buffer capacity. The default is 8.
    public func bufferCapacity() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_bufferCapacity(cdata_)
        return _return_value_
    }
    ///Sets `InputFrame`_ buffer capacity.
    public func setBufferCapacity(_ capacity: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CameraDevice_setBufferCapacity(cdata_, capacity)
    }
    ///`InputFrame`_ output port.
    public func inputFrameSource() -> InputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CameraDevice_inputFrameSource(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSource__typeName) as InputFrameSource)
    }
    ///Sets callback on state change to notify state of camera disconnection or preemption. It is only available on Windows.
    public func setStateChangedCallback(_ callbackScheduler: CallbackScheduler, _ stateChangedCallback: ((CameraState) -> Void)?) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CameraDevice_setStateChangedCallback(cdata_, callbackScheduler.cdata_, (stateChangedCallback.map({(p) in easyar_OptionalOfFunctorOfVoidFromCameraState(has_value: true, value: FunctorOfVoidFromCameraState_to_c(p))}) ?? easyar_OptionalOfFunctorOfVoidFromCameraState(has_value: false, value: defaultValue())))
    }
    ///Requests camera permission from operating system. You can call this function or request permission directly from operating system. It is only available on Android and iOS. On other platforms, it will call the callback directly with status being granted. This function need to be called from the UI thread.
    public static func requestPermissions(_ callbackScheduler: CallbackScheduler, _ permissionCallback: ((PermissionStatus, String) -> Void)?) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CameraDevice_requestPermissions(callbackScheduler.cdata_, (permissionCallback.map({(p) in easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString(has_value: true, value: FunctorOfVoidFromPermissionStatusAndString_to_c(p))}) ?? easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString(has_value: false, value: defaultValue())))
    }
    ///Gets count of cameras recognized by the operating system.
    public static func cameraCount() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_cameraCount()
        return _return_value_
    }
    ///Opens a camera by index.
    public func openWithIndex(_ cameraIndex: Int32) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_openWithIndex(cdata_, cameraIndex)
        return _return_value_
    }
    ///Opens a camera by specific camera device type. If no camera is matched, false will be returned. On Mac, camera device types can not be distinguished.
    public func openWithSpecificType(_ type: CameraDeviceType) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_openWithSpecificType(cdata_, type.rawValue)
        return _return_value_
    }
    ///Opens a camera by camera device type. If no camera is matched, the first camera will be used.
    public func openWithPreferredType(_ type: CameraDeviceType) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_openWithPreferredType(cdata_, type.rawValue)
        return _return_value_
    }
    ///Starts video stream capture.
    public func start() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_start(cdata_)
        return _return_value_
    }
    ///Stops video stream capture. It will only stop capture and will not change previous set camera parameters and connection.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CameraDevice_stop(cdata_)
    }
    ///Close. The component shall not be used after calling close.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CameraDevice_close(cdata_)
    }
    ///Camera index.
    public func index() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_index(cdata_)
        return _return_value_
    }
    ///Camera type.
    public func type() -> CameraDeviceType {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_type(cdata_)
        return CameraDeviceType(rawValue: _return_value_)!
    }
    ///Camera parameters, including image size, focal length, principal point, camera type and camera rotation against natural orientation. Call after a successful open.
    public func cameraParameters() -> CameraParameters {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CameraDevice_cameraParameters(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_CameraParameters__typeName) as CameraParameters)
    }
    ///Sets camera parameters. Call after a successful open.
    public func setCameraParameters(_ cameraParameters: CameraParameters) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_CameraDevice_setCameraParameters(cdata_, cameraParameters.cdata_)
    }
    ///Gets the current preview size. Call after a successful open.
    public func size() -> Vec2I {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_size(cdata_)
        return Vec2I_from_c(_return_value_)
    }
    ///Gets the number of supported preview sizes. Call after a successful open.
    public func supportedSizeCount() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_supportedSizeCount(cdata_)
        return _return_value_
    }
    ///Gets the index-th supported preview size. It returns {0, 0} if index is out of range. Call after a successful open.
    public func supportedSize(_ index: Int32) -> Vec2I {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_supportedSize(cdata_, index)
        return Vec2I_from_c(_return_value_)
    }
    ///Sets the preview size. The available nearest value will be selected. Call size to get the actual size. Call after a successful open. frameRateRange may change after calling setSize.
    public func setSize(_ size: Vec2I) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_setSize(cdata_, Vec2I_to_c(size))
        return _return_value_
    }
    ///Gets the number of supported frame rate ranges. Call after a successful open.
    public func supportedFrameRateRangeCount() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_supportedFrameRateRangeCount(cdata_)
        return _return_value_
    }
    ///Gets range lower bound of the index-th supported frame rate range. Call after a successful open.
    public func supportedFrameRateRangeLower(_ index: Int32) -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_supportedFrameRateRangeLower(cdata_, index)
        return _return_value_
    }
    ///Gets range upper bound of the index-th supported frame rate range. Call after a successful open.
    public func supportedFrameRateRangeUpper(_ index: Int32) -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_supportedFrameRateRangeUpper(cdata_, index)
        return _return_value_
    }
    ///Gets current index of frame rate range. Call after a successful open.
    public func frameRateRange() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_frameRateRange(cdata_)
        return _return_value_
    }
    ///Sets current index of frame rate range. Call after a successful open.
    public func setFrameRateRange(_ index: Int32) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_setFrameRateRange(cdata_, index)
        return _return_value_
    }
    ///Sets flash torch mode to on. Call after a successful open.
    public func setFlashTorchMode(_ on: Bool) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_setFlashTorchMode(cdata_, on)
        return _return_value_
    }
    ///Sets focus mode to focusMode. Call after a successful open.
    public func setFocusMode(_ focusMode: CameraDeviceFocusMode) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_setFocusMode(cdata_, focusMode.rawValue)
        return _return_value_
    }
    ///Does auto focus once. Call after start. It is only available when FocusMode is Normal or Macro.
    public func autoFocus() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDevice_autoFocus(cdata_)
        return _return_value_
    }
}

public enum CameraDevicePreference : Int32 {
    ///Optimized for `ImageTracker`_ , `ObjectTracker`_ and `CloudRecognizer`_ .
    case PreferObjectSensing = 0
    ///Optimized for `SurfaceTracker`_ .
    case PreferSurfaceTracking = 1
    ///Optimized for Motion Tracking .
    case PreferMotionTracking = 2
}

///It is used for selecting camera API (camera1 or camera2) on Android. camera1 is better for compatibility, but lacks some necessary information such as timestamp. camera2 has compatibility issues on some devices.
///Different preferences will choose camera1 or camera2 based on usage.
public class CameraDeviceSelector {
    ///Gets recommended Android Camera API type by a specified preference.
    public static func getAndroidCameraApiType(_ preference: CameraDevicePreference) -> AndroidCameraApiType {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDeviceSelector_getAndroidCameraApiType(preference.rawValue)
        return AndroidCameraApiType(rawValue: _return_value_)!
    }
    ///Creates `CameraDevice`_ by a specified preference.
    public static func createCameraDevice(_ preference: CameraDevicePreference) -> CameraDevice {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_CameraDeviceSelector_createCameraDevice(preference.rawValue, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_CameraDevice__typeName) as CameraDevice)
    }
    ///Gets recommended Camera FocusMode type by a specified preference.
    public static func getFocusMode(_ preference: CameraDevicePreference) -> CameraDeviceFocusMode {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_CameraDeviceSelector_getFocusMode(preference.rawValue)
        return CameraDeviceFocusMode(rawValue: _return_value_)!
    }
}

///Magnetometer reading.
///
///The positive direction of x-axis is from the device center to its right side of the screen.
///The positive direction of y-axis is from the device center to its top side of the screen.
///The positive direction of z-axis is from the device center perpendicular to the screen outward.
///
///The unit of x, y, z is uT(micro-Tesla).
///The unit of timestamp is second.
public struct MagnetometerResult {
    public var x: Float
    public var y: Float
    public var z: Float
    public var timestamp: Double

    public init(_ x: Float, _ y: Float, _ z: Float, _ timestamp: Double) {
        self.x = x;
        self.y = y;
        self.z = z;
        self.timestamp = timestamp;
    }
}

///Result of `SurfaceTracker`_ .
public class SurfaceTrackerResult : FrameFilterResult {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Camera transform against world coordinate system. Camera coordinate system and world coordinate system are all right-handed. For the camera coordinate system, the origin is the optical center, x-right, y-up, and z in the direction of light going into camera. (The right and up, on mobile devices, is the right and up when the device is in the natural orientation.) For the world coordinate system, y is up (to the opposite of gravity). The data arrangement is row-major, not like OpenGL's column-major.
    public func transform() -> Matrix44F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SurfaceTrackerResult_transform(cdata_)
        return Matrix44F_from_c(_return_value_)
    }
}

///SurfaceTracker implements tracking with environmental surfaces.
///SurfaceTracker occupies one buffer of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components. Refer to `Overview <Overview.html>`__ .
///After creation, you can call start/stop to enable/disable the track process. start and stop are very lightweight calls.
///When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
///SurfaceTracker inputs `InputFrame`_ from inputFrameSink. `InputFrameSource`_ shall be connected to inputFrameSink for use. Refer to `Overview <Overview.html>`__ .
public class SurfaceTracker : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns true only on Android or iOS when accelerometer and gyroscope are available.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SurfaceTracker_isAvailable()
        return _return_value_
    }
    ///`InputFrame`_ input port. InputFrame must have raw image, timestamp, and camera parameters.
    public func inputFrameSink() -> InputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SurfaceTracker_inputFrameSink(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSink__typeName) as InputFrameSink)
    }
    ///Camera buffers occupied in this component.
    public func bufferRequirement() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SurfaceTracker_bufferRequirement(cdata_)
        return _return_value_
    }
    ///`OutputFrame`_ output port.
    public func outputFrameSource() -> OutputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SurfaceTracker_outputFrameSource(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSource__typeName) as OutputFrameSource)
    }
    ///Creates an instance.
    public static func create() -> SurfaceTracker {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SurfaceTracker_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_SurfaceTracker__typeName) as SurfaceTracker)
    }
    ///Starts the track algorithm.
    public func start() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SurfaceTracker_start(cdata_)
        return _return_value_
    }
    ///Stops the track algorithm. Call start to start the track again.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SurfaceTracker_stop(cdata_)
    }
    ///Close. The component shall not be used after calling close.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SurfaceTracker_close(cdata_)
    }
    ///Sets the tracking target to a point on camera image. For the camera image coordinate system ([0, 1]^2), x-right, y-down, and origin is at left-top corner. `CameraParameters.imageCoordinatesFromScreenCoordinates`_ can be used to convert points from screen coordinate system to camera image coordinate system.
    public func alignTargetToCameraImagePoint(_ cameraImagePoint: Vec2F) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SurfaceTracker_alignTargetToCameraImagePoint(cdata_, Vec2F_to_c(cameraImagePoint))
    }
}

public enum MotionTrackerCameraDeviceQualityLevel : Int32 {
    ///The device does not support motion tracking. It has not our passed our verification or is waiting for calibration.
    case NotSupported = 0
    ///The device has not passed all our verification. Real time scale is unstable. It can be used in AR showcase or other desktop-scale applications.
    case Bad = 1
    ///The device has not passed all our verification. Real time scale is almost accurate. It can be used in AR showcase, AR games or other room-scale applications.
    case Limited = 2
    ///The device has passed all our verification. Real time scale is accurate. It can be used in AR showcase, AR games, 3D reconstruction or other building-scale applications.
    case Good = 3
}

public enum MotionTrackerCameraDeviceFPS : Int32 {
    ///Frame rate is 30 fps, the actual fps will vary with device capabilities. It is the default setting.
    case Camera_FPS_30 = 0
    ///Frame rate is 60 fps or 30 fps, the actual fps will vary with device capabilities.
    case Camera_FPS_60 = 1
}

public enum MotionTrackerCameraDeviceFocusMode : Int32 {
    ///Continuous auto focus mode, high image definition and good tracking performance. The actual focus mode will vary with device capabilities. It is the default setting.
    case Continousauto = 0
    ///Focus is fixed on Medium distance, medium image definition and better tracking performance. The actual focus mode will vary with device capabilities.
    case Medium = 1
}

public enum MotionTrackerCameraDeviceResolution : Int32 {
    ///Resolution is typically 1280 x 960 or 1280 x 720, the actual resolution will vary with device capabilities. It is the default setting.
    case Resolution_1280 = 0
    ///Resolution is typically 640 x 480 or 640 x 360, the actual resolution will vary with device capabilities.
    case Resolution_640 = 1
}

public enum MotionTrackerCameraDeviceTrackingMode : Int32 {
    ///Tracking and hitTestAgainstPointCloud is supported, but plane detection, relocation and anchor are not. It has low CPU and memory usage.
    case VIO = 0
    ///SLAM(Simultaneous tracking and mapping) supports relocation, plane detection and hitTestAgainstPointCloud. CPU and memory usage are higher. Real time pose correction of anchor is not supported.
    case SLAM = 1
    ///Anchor is SLAM(Simultaneous tracking and mapping) with real time pose correction.  CPU and memory usage are highest。Anchor supports relocation, plane detection, hitTestAgainstPointCloud and pose correction. Anchor is automatically saved when hitTestAgainstPointCloud is called.
    case Anchor = 2
}

///MotionTrackerCameraDevice implements a camera device with metric-scale six degree-of-freedom motion tracking, which outputs `InputFrame`_  (including image, camera parameters, timestamp, 6DOF pose and tracking status).
///After creation, start/stop can be invoked to start or stop data flow.
///When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
///MotionTrackerCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for further use. Refer to `Overview <Overview.html>`__ .
public class MotionTrackerCameraDevice : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Create MotionTrackerCameraDevice object.
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_MotionTrackerCameraDevice__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_MotionTrackerCameraDevice__dtor(ptr) })
    }
    ///Check if the devices supports motion tracking. Returns True if the device supports Motion Tracking, otherwise returns False.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_MotionTrackerCameraDevice_isAvailable()
        return _return_value_
    }
    ///Get the quality of Motion Tracking on the device. You can decide whether to start Motion Tracking.
    public static func getQualityLevel() -> MotionTrackerCameraDeviceQualityLevel {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_MotionTrackerCameraDevice_getQualityLevel()
        return MotionTrackerCameraDeviceQualityLevel(rawValue: _return_value_)!
    }
    ///Sets current index of frame rate. Call before start. If this function is not called, the default is 30 fps.
    public func setFrameRateType(_ fps: MotionTrackerCameraDeviceFPS) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_MotionTrackerCameraDevice_setFrameRateType(cdata_, fps.rawValue)
        return _return_value_
    }
    ///Sets focus mode to focusMode. Call before start. If this function is not called, the default is Continousauto.
    public func setFocusMode(_ focusMode: MotionTrackerCameraDeviceFocusMode) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_MotionTrackerCameraDevice_setFocusMode(cdata_, focusMode.rawValue)
        return _return_value_
    }
    ///Sets current index of frame resolution. Call before start. If this function is not called, the default is 1280 x 960 or 1280 x 720.
    public func setFrameResolutionType(_ resolution: MotionTrackerCameraDeviceResolution) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_MotionTrackerCameraDevice_setFrameResolutionType(cdata_, resolution.rawValue)
        return _return_value_
    }
    ///Sets current tracking mode. Call before start. If this function is not called, the default is Anchor.
    public func setTrackingMode(_ trackingMode: MotionTrackerCameraDeviceTrackingMode) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_MotionTrackerCameraDevice_setTrackingMode(cdata_, trackingMode.rawValue)
        return _return_value_
    }
    ///Set `InputFrame`_ buffer capacity.
    ///bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is higher than this number, the device will not output new `InputFrame`_ until previous `InputFrame`_ has been released. This may cause screen stuck. Refer to `Overview <Overview.html>`__ .
    public func setBufferCapacity(_ capacity: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_MotionTrackerCameraDevice_setBufferCapacity(cdata_, capacity)
    }
    ///Get `InputFrame`_ buffer capacity. The default is 8.
    public func bufferCapacity() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_MotionTrackerCameraDevice_bufferCapacity(cdata_)
        return _return_value_
    }
    ///`InputFrame`_ output port.
    public func inputFrameSource() -> InputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_MotionTrackerCameraDevice_inputFrameSource(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSource__typeName) as InputFrameSource)
    }
    ///Start motion tracking or resume motion tracking after pause.
    ///Notice: Calling start after pausing will trigger device relocalization. Tracking will resume when the relocalization process succeeds.
    public func start() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_MotionTrackerCameraDevice_start(cdata_)
        return _return_value_
    }
    ///Pause motion tracking. Call `start` to trigger relocation, resume motion tracking if the relocation succeeds.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_MotionTrackerCameraDevice_stop(cdata_)
    }
    ///Close motion tracking. The component shall not be used after calling close.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_MotionTrackerCameraDevice_close(cdata_)
    }
    ///Perform hit test against the point cloud and return the nearest 3D point. The 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space.
    ///For the camera image coordinate system ([0, 1]^2), x-right, y-down, and origin is at left-top corner. `CameraParameters.imageCoordinatesFromScreenCoordinates`_ can be used to convert points from screen coordinate system to camera image coordinate system.
    public func hitTestAgainstPointCloud(_ cameraImagePoint: Vec2F) -> [Vec3F] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_MotionTrackerCameraDevice_hitTestAgainstPointCloud(cdata_, Vec2F_to_c(cameraImagePoint), _return_value_)
        return ListOfVec3F_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfVec3F__dtor(p) })))
    }
    ///Performs ray cast from the user's device in the direction of given screen point.
    ///Intersections with horizontal plane is detected in real time in the current field of view,and return the 3D point nearest to ray on horizontal plane.
    ///For the camera image coordinate system ([0, 1]^2), x-right, y-down, and origin is at left-top corner. `CameraParameters.imageCoordinatesFromScreenCoordinates`_ can be used to convert points from screen coordinate system to camera image coordinate system.
    ///The output point cloud coordinate on Horizontal plane is in the world coordinate system. The 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space.
    public func hitTestAgainstHorizontalPlane(_ cameraImagePoint: Vec2F) -> [Vec3F] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_MotionTrackerCameraDevice_hitTestAgainstHorizontalPlane(cdata_, Vec2F_to_c(cameraImagePoint), _return_value_)
        return ListOfVec3F_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfVec3F__dtor(p) })))
    }
    ///Returns the vector of point cloud coordinate. Each 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space.
    public func getLocalPointsCloud() -> [Vec3F] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_MotionTrackerCameraDevice_getLocalPointsCloud(cdata_, _return_value_)
        return ListOfVec3F_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfVec3F__dtor(p) })))
    }
}

///Input frame recorder.
///There is an input frame input port and an input frame output port. It can be used to record input frames into an EIF file. Refer to `Overview <Overview.html>`__ .
///All members of this class is thread-safe.
public class InputFrameRecorder : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input port.
    public func input() -> InputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameRecorder_input(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSink__typeName) as InputFrameSink)
    }
    ///Camera buffers occupied in this component.
    public func bufferRequirement() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrameRecorder_bufferRequirement(cdata_)
        return _return_value_
    }
    ///Output port.
    public func output() -> InputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameRecorder_output(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSource__typeName) as InputFrameSource)
    }
    ///Creates an instance.
    public static func create() -> InputFrameRecorder {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameRecorder_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameRecorder__typeName) as InputFrameRecorder)
    }
    ///Starts frame recording. initialScreenRotation is the initial screen rotation when recording data, and it will be used in rendering for playback. The definition of screen rotation is the same as in `CameraParameters`_ .
    public func start(_ filePath: String, _ initialScreenRotation: Int32) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrameRecorder_start(cdata_, String_to_c(_ar_, filePath).ptr_, initialScreenRotation)
        return _return_value_
    }
    ///Stops frame recording. It will only stop recording and will not affect connection.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_InputFrameRecorder_stop(cdata_)
    }
}

///Input frame player.
///There is an input frame output port. It can be used to get input frame from an EIF file. Refer to `Overview <Overview.html>`__ .
///All members of this class is thread-safe.
public class InputFramePlayer : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Output port.
    public func output() -> InputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFramePlayer_output(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSource__typeName) as InputFrameSource)
    }
    ///Creates an instance.
    public static func create() -> InputFramePlayer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFramePlayer_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFramePlayer__typeName) as InputFramePlayer)
    }
    ///Starts frame play.
    public func start(_ filePath: String) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFramePlayer_start(cdata_, String_to_c(_ar_, filePath).ptr_)
        return _return_value_
    }
    ///Stops frame play.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_InputFramePlayer_stop(cdata_)
    }
    ///Pauses frame play.
    public func pause() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_InputFramePlayer_pause(cdata_)
    }
    ///Resumes frame play.
    public func resume() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFramePlayer_resume(cdata_)
        return _return_value_
    }
    ///Total expected playback time span. The unit is second.
    public func totalTime() -> Double {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFramePlayer_totalTime(cdata_)
        return _return_value_
    }
    ///Current playback time point. The unit is second. The initial value is 0.
    public func currentTime() -> Double {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFramePlayer_currentTime(cdata_)
        return _return_value_
    }
    ///The initial screen rotation when recording data.
    public func initalScreenRotation() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFramePlayer_initalScreenRotation(cdata_)
        return _return_value_
    }
    ///Whether the playback is completed.
    public func isCompleted() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFramePlayer_isCompleted(cdata_)
        return _return_value_
    }
}

///Callback scheduler.
///There are two subclasses: `DelayedCallbackScheduler`_ and `ImmediateCallbackScheduler`_ .
///`DelayedCallbackScheduler`_ is used to delay callback to be invoked manually, and it can be used in single-threaded environments (such as various UI environments).
///`ImmediateCallbackScheduler`_ is used to mark callback to be invoked when event is dispatched, and it can be used in multi-threaded environments (such as server or service daemon).
public class CallbackScheduler : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
}

///Delayed callback scheduler.
///It is used to delay callback to be invoked manually, and it can be used in single-threaded environments (such as various UI environments).
///All members of this class is thread-safe.
public class DelayedCallbackScheduler : CallbackScheduler {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_DelayedCallbackScheduler__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_DelayedCallbackScheduler__dtor(ptr) })
    }
    ///Executes a callback. If there is no callback to execute, false is returned.
    public func runOne() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_DelayedCallbackScheduler_runOne(cdata_)
        return _return_value_
    }
}

///Immediate callback scheduler.
///It is used to mark callback to be invoked when event is dispatched, and it can be used in multi-threaded environments (such as server or service daemon).
///All members of this class is thread-safe.
public class ImmediateCallbackScheduler : CallbackScheduler {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Gets a default immediate callback scheduler.
    public static func getDefault() -> ImmediateCallbackScheduler {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImmediateCallbackScheduler_getDefault(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_ImmediateCallbackScheduler__typeName) as ImmediateCallbackScheduler)
    }
}

///JNI utility class.
///It is used in Unity to wrap Java byte array and ByteBuffer.
///It is not supported on iOS.
public class JniUtility {
    ///Wraps Java's byte[]。
    public static func wrapByteArray(_ bytes: OpaquePointer?, _ readOnly: Bool, _ deleter: @escaping () -> Void) -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_JniUtility_wrapByteArray(bytes, readOnly, FunctorOfVoid_to_c(deleter), _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Wraps Java's java.nio.ByteBuffer, which must be a direct buffer.
    public static func wrapBuffer(_ directBuffer: OpaquePointer?, _ deleter: @escaping () -> Void) -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_JniUtility_wrapBuffer(directBuffer, FunctorOfVoid_to_c(deleter), _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Get the raw address of a direct buffer of java.nio.ByteBuffer by calling JNIEnv->GetDirectBufferAddress.
    public static func getDirectBufferAddress(_ directBuffer: OpaquePointer?) -> OpaquePointer? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_JniUtility_getDirectBufferAddress(directBuffer)
        return _return_value_
    }
}

public enum LogLevel : Int32 {
    ///Error
    case Error = 0
    ///Warning
    case Warning = 1
    ///Information
    case Info = 2
}

///Log class.
///It is used to setup a custom log output function.
public class Log {
    ///Sets custom log output function. The log output function should be thread-safe.
    public static func setLogFunc(_ `func`: @escaping (LogLevel, String) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Log_setLogFunc(FunctorOfVoidFromLogLevelAndString_to_c(`func`))
    }
    ///Sets custom log output function and run it in scheduler.
    public static func setLogFuncWithScheduler(_ scheduler: CallbackScheduler, _ `func`: @escaping (LogLevel, String) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Log_setLogFuncWithScheduler(scheduler.cdata_, FunctorOfVoidFromLogLevelAndString_to_c(`func`))
    }
    ///Clears custom log output function and reverts to default log output function.
    public static func resetLogFunc() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Log_resetLogFunc()
    }
}

public class Storage {
    ///Sets asset root path.
    public static func setAssetDirPath(_ path: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Storage_setAssetDirPath(String_to_c(_ar_, path).ptr_)
    }
}

///ImageTargetParameters represents the parameters to create a `ImageTarget`_ .
public class ImageTargetParameters : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTargetParameters__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_ImageTargetParameters__dtor(ptr) })
    }
    ///Gets image.
    public func image() -> Image {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTargetParameters_image(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Image__typeName) as Image)
    }
    ///Sets image.
    public func setImage(_ image: Image) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTargetParameters_setImage(cdata_, image.cdata_)
    }
    ///Gets target name. It can be used to distinguish targets.
    public func name() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTargetParameters_name(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Sets target name.
    public func setName(_ name: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTargetParameters_setName(cdata_, String_to_c(_ar_, name).ptr_)
    }
    ///Gets the target uid. A target uid is useful in cloud based algorithms. If no cloud is used, you can set this uid in the json config as an alternative method to distinguish from targets.
    public func uid() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTargetParameters_uid(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Sets target uid.
    public func setUid(_ uid: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTargetParameters_setUid(cdata_, String_to_c(_ar_, uid).ptr_)
    }
    ///Gets meta data.
    public func meta() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTargetParameters_meta(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Sets meta data。
    public func setMeta(_ meta: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTargetParameters_setMeta(cdata_, String_to_c(_ar_, meta).ptr_)
    }
    ///Gets the scale of image. The value is the physical image width divided by 1 meter. The default value is 1.
    public func scale() -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTargetParameters_scale(cdata_)
        return _return_value_
    }
    ///Sets the scale of image. The value is the physical image width divided by 1 meter. The default value is 1.
    ///It is needed to set the model scale in rendering engine separately.
    public func setScale(_ scale: Float) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTargetParameters_setScale(cdata_, scale)
    }
}

///ImageTarget represents planar image targets that can be tracked by `ImageTracker`_ .
///The fields of ImageTarget need to be filled with the create... method before it can be read. And ImageTarget can be tracked by `ImageTracker`_ after a successful load into the `ImageTracker`_ using `ImageTracker.loadTarget`_ .
public class ImageTarget : Target {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTarget__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_ImageTarget__dtor(ptr) })
    }
    ///Creates a target from parameters.
    public static func createFromParameters(_ parameters: ImageTargetParameters) -> ImageTarget? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfImageTarget>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTarget_createFromParameters(parameters.cdata_, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_ImageTarget__typeName) as ImageTarget) : nil)
    }
    ///Creates a target from an etd file.
    public static func createFromTargetFile(_ path: String, _ storageType: StorageType) -> ImageTarget? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfImageTarget>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTarget_createFromTargetFile(String_to_c(_ar_, path).ptr_, storageType.rawValue, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_ImageTarget__typeName) as ImageTarget) : nil)
    }
    ///Creates a target from an etd data buffer.
    public static func createFromTargetData(_ buffer: Buffer) -> ImageTarget? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfImageTarget>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTarget_createFromTargetData(buffer.cdata_, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_ImageTarget__typeName) as ImageTarget) : nil)
    }
    ///Saves as an etd file.
    public func save(_ path: String) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTarget_save(cdata_, String_to_c(_ar_, path).ptr_)
        return _return_value_
    }
    ///Creates a target from an image file. If not needed, name, uid, meta can be passed with empty string, and scale can be passed with default value 1. Jpeg and png files are supported.
    public static func createFromImageFile(_ path: String, _ storageType: StorageType, _ name: String, _ uid: String, _ meta: String, _ scale: Float) -> ImageTarget? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfImageTarget>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTarget_createFromImageFile(String_to_c(_ar_, path).ptr_, storageType.rawValue, String_to_c(_ar_, name).ptr_, String_to_c(_ar_, uid).ptr_, String_to_c(_ar_, meta).ptr_, scale, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_ImageTarget__typeName) as ImageTarget) : nil)
    }
    ///The scale of image. The value is the physical image width divided by 1 meter. The default value is 1.
    public func scale() -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTarget_scale(cdata_)
        return _return_value_
    }
    ///The aspect ratio of image, width divided by height.
    public func aspectRatio() -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTarget_aspectRatio(cdata_)
        return _return_value_
    }
    ///Sets image target scale, this will overwrite the value set in the json file or the default value. The value is the physical image width divided by 1 meter. The default value is 1.
    ///It is needed to set the model scale in rendering engine separately.
    public func setScale(_ scale: Float) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTarget_setScale(cdata_, scale)
        return _return_value_
    }
    ///Returns a list of images that stored in the target. It is generally used to get image data from cloud returned target.
    public func images() -> [Image] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTarget_images(cdata_, _return_value_)
        return ListOfImage_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfImage__dtor(p) })))
    }
    ///Returns the target id. A target id is a integer number generated at runtime. This id is non-zero and increasing globally.
    public override func runtimeID() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTarget_runtimeID(cdata_)
        return _return_value_
    }
    ///Returns the target uid. A target uid is useful in cloud based algorithms. If no cloud is used, you can set this uid in the json config as a alternative method to distinguish from targets.
    public override func uid() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTarget_uid(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Returns the target name. Name is used to distinguish targets in a json file.
    public override func name() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTarget_name(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Set name. It will erase previously set data or data from cloud.
    public override func setName(_ name: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTarget_setName(cdata_, String_to_c(_ar_, name).ptr_)
    }
    ///Returns the meta data set by setMetaData. Or, in a cloud returned target, returns the meta data set in the cloud server.
    public override func meta() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTarget_meta(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Set meta data. It will erase previously set data or data from cloud.
    public override func setMeta(_ data: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTarget_setMeta(cdata_, String_to_c(_ar_, data).ptr_)
    }
}

public enum ImageTrackerMode : Int32 {
    ///Quality is preferred.
    case PreferQuality = 0
    ///Performance is preferred.
    case PreferPerformance = 1
}

///Result of `ImageTracker`_ .
public class ImageTrackerResult : TargetTrackerResult {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns the list of `TargetInstance`_ contained in the result.
    public override func targetInstances() -> [TargetInstance] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTrackerResult_targetInstances(cdata_, _return_value_)
        return ListOfTargetInstance_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfTargetInstance__dtor(p) })))
    }
    ///Sets the list of `TargetInstance`_ contained in the result.
    public override func setTargetInstances(_ instances: [TargetInstance]) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTrackerResult_setTargetInstances(cdata_, ListOfTargetInstance_to_c(_ar_, instances).ptr_)
    }
}

///ImageTracker implements image target detection and tracking.
///ImageTracker occupies (1 + SimultaneousNum) buffers of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components. Refer to `Overview <Overview.html>`__ .
///After creation, you can call start/stop to enable/disable the track process. start and stop are very lightweight calls.
///When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
///ImageTracker inputs `FeedbackFrame`_ from feedbackFrameSink. `FeedbackFrameSource`_ shall be connected to feedbackFrameSink for use. Refer to `Overview <Overview.html>`__ .
///Before a `Target`_ can be tracked by ImageTracker, you have to load it using loadTarget/unloadTarget. You can get load/unload results from callbacks passed into the interfaces.
public class ImageTracker : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns true.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTracker_isAvailable()
        return _return_value_
    }
    ///`FeedbackFrame`_ input port. The InputFrame member of FeedbackFrame must have raw image, timestamp, and camera parameters.
    public func feedbackFrameSink() -> FeedbackFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTracker_feedbackFrameSink(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_FeedbackFrameSink__typeName) as FeedbackFrameSink)
    }
    ///Camera buffers occupied in this component.
    public func bufferRequirement() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTracker_bufferRequirement(cdata_)
        return _return_value_
    }
    ///`OutputFrame`_ output port.
    public func outputFrameSource() -> OutputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTracker_outputFrameSource(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSource__typeName) as OutputFrameSource)
    }
    ///Creates an instance. The default track mode is `ImageTrackerMode.PreferQuality`_ .
    public static func create() -> ImageTracker {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTracker_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_ImageTracker__typeName) as ImageTracker)
    }
    ///Creates an instance with a specified track mode. On lower-end phones, `ImageTrackerMode.PreferPerformance`_ can be used to keep a better performance with a little quality loss.
    public static func createWithMode(_ trackMode: ImageTrackerMode) -> ImageTracker {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTracker_createWithMode(trackMode.rawValue, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_ImageTracker__typeName) as ImageTracker)
    }
    ///Starts the track algorithm.
    public func start() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTracker_start(cdata_)
        return _return_value_
    }
    ///Stops the track algorithm. Call start to start the track again.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTracker_stop(cdata_)
    }
    ///Close. The component shall not be used after calling close.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTracker_close(cdata_)
    }
    ///Load a `Target`_ into the tracker. A Target can only be tracked by tracker after a successful load.
    ///This method is an asynchronous method. A load operation may take some time to finish and detection of a new/lost target may take more time during the load. The track time after detection will not be affected. If you want to know the load result, you have to handle the callback data. The callback will be called from the thread specified by `CallbackScheduler`_ . It will not block the track thread or any other operations except other load/unload.
    public func loadTarget(_ target: Target, _ callbackScheduler: CallbackScheduler, _ callback: @escaping (Target, Bool) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTracker_loadTarget(cdata_, target.cdata_, callbackScheduler.cdata_, FunctorOfVoidFromTargetAndBool_to_c(callback))
    }
    ///Unload a `Target`_ from the tracker.
    ///This method is an asynchronous method. An unload operation may take some time to finish and detection of a new/lost target may take more time during the unload. If you want to know the unload result, you have to handle the callback data. The callback will be called from the thread specified by `CallbackScheduler`_ . It will not block the track thread or any other operations except other load/unload.
    public func unloadTarget(_ target: Target, _ callbackScheduler: CallbackScheduler, _ callback: @escaping (Target, Bool) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_ImageTracker_unloadTarget(cdata_, target.cdata_, callbackScheduler.cdata_, FunctorOfVoidFromTargetAndBool_to_c(callback))
    }
    ///Returns current loaded targets in the tracker. If an asynchronous load/unload is in progress, the returned value will not reflect the result until all load/unload finish.
    public func targets() -> [Target] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageTracker_targets(cdata_, _return_value_)
        return ListOfTarget_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfTarget__dtor(p) })))
    }
    ///Sets the max number of targets which will be the simultaneously tracked by the tracker. The default value is 1.
    public func setSimultaneousNum(_ num: Int32) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTracker_setSimultaneousNum(cdata_, num)
        return _return_value_
    }
    ///Gets the max number of targets which will be the simultaneously tracked by the tracker. The default value is 1.
    public func simultaneousNum() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_ImageTracker_simultaneousNum(cdata_)
        return _return_value_
    }
}

public class RealTimeCoordinateTransform : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Create RealTimeCoordinateTransform object.
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_RealTimeCoordinateTransform__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_RealTimeCoordinateTransform__dtor(ptr) })
    }
    ///Set buffer size，the unit of capacity is seconds. The data within capacity seconds from now will be saved.
    ///BufferSize represents the capacity of the buffer. If there is more than capacity seconds of data in the buffer, the latest data will be input to the buffer and the oldest frame of data will be released.
    public func setBufferSize(_ capacity: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_RealTimeCoordinateTransform_setBufferSize(cdata_, capacity)
    }
    ///Get buffer capacity. The default is 15 seconds. The data within 15 seconds from now will be saved.
    public func getBufferSize() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_RealTimeCoordinateTransform_getBufferSize(cdata_)
        return _return_value_
    }
    ///Input data to the cache, the data includes localTwc and mapTcw at the time timestamp. localTwc means camera pose at local coordinates, mapTcw means the camera pose at the localized map coordinates.
    public func insertData(_ timestamp: Double, _ localTwc: Matrix44F, _ mapTcw: Matrix44F) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_RealTimeCoordinateTransform_insertData(cdata_, timestamp, Matrix44F_to_c(localTwc), Matrix44F_to_c(mapTcw))
        return _return_value_
    }
    ///Returns the camera pose in the localized map after insert motionTracking status and localTwc at the time timestamp. localTwc means camera pose at local coordinates.
    public func getPoseInMap(_ timestamp: Double, _ status: MotionTrackingStatus, _ localTwc: Matrix44F) -> Matrix44F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_RealTimeCoordinateTransform_getPoseInMap(cdata_, timestamp, status.rawValue, Matrix44F_to_c(localTwc))
        return Matrix44F_from_c(_return_value_)
    }
}

///Recorder implements recording for current rendering screen.
///Currently Recorder only works on Android (4.3 or later) and iOS with OpenGL ES 2.0 context.
///Due to the dependency to OpenGLES, every method in this class (except requestPermissions, including the destructor) has to be called in a single thread containing an OpenGLES context.
///**Unity Only** If in Unity, Multi-threaded rendering is enabled, scripting thread and rendering thread will be two separate threads, which makes it impossible to call updateFrame in the rendering thread. For this reason, to use Recorder, Multi-threaded rendering option shall be disabled.
///On Android, it is required to add android.permission.RECORD_AUDIO to AndroidManifest.xml for use.
///On iOS, it is required to add NSMicrophoneUsageDescription to Info.plist for use.
public class Recorder : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns true only on Android 4.3 or later, or on iOS.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Recorder_isAvailable()
        return _return_value_
    }
    ///Requests recording permissions from operating system. You can call this function or request permission directly from operating system. It is only available on Android and iOS. On other platforms, it will call the callback directly with status being granted. This function need to be called from the UI thread.
    public static func requestPermissions(_ callbackScheduler: CallbackScheduler, _ permissionCallback: ((PermissionStatus, String) -> Void)?) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Recorder_requestPermissions(callbackScheduler.cdata_, (permissionCallback.map({(p) in easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString(has_value: true, value: FunctorOfVoidFromPermissionStatusAndString_to_c(p))}) ?? easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString(has_value: false, value: defaultValue())))
    }
    ///Creates an instance and initialize recording. statusCallback will dispatch event of status change and corresponding log.
    public static func create(_ config: RecorderConfiguration, _ callbackScheduler: CallbackScheduler, _ statusCallback: ((RecordStatus, String) -> Void)?) -> Recorder {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Recorder_create(config.cdata_, callbackScheduler.cdata_, (statusCallback.map({(p) in easyar_OptionalOfFunctorOfVoidFromRecordStatusAndString(has_value: true, value: FunctorOfVoidFromRecordStatusAndString_to_c(p))}) ?? easyar_OptionalOfFunctorOfVoidFromRecordStatusAndString(has_value: false, value: defaultValue())), _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Recorder__typeName) as Recorder)
    }
    ///Start recording.
    public func start() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Recorder_start(cdata_)
    }
    ///Update and record a frame using texture data.
    public func updateFrame(_ texture: TextureId, _ width: Int32, _ height: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Recorder_updateFrame(cdata_, texture.cdata_, width, height)
    }
    ///Stop recording. When calling stop, it will wait for file write to end and returns whether recording is successful.
    public func stop() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Recorder_stop(cdata_)
        return _return_value_
    }
}

public enum RecordProfile : Int32 {
    ///1080P, low quality
    case Quality_1080P_Low = 0x00000001
    ///1080P, middle quality
    case Quality_1080P_Middle = 0x00000002
    ///1080P, high quality
    case Quality_1080P_High = 0x00000004
    ///720P, low quality
    case Quality_720P_Low = 0x00000008
    ///720P, middle quality
    case Quality_720P_Middle = 0x00000010
    ///720P, high quality
    case Quality_720P_High = 0x00000020
    ///480P, low quality
    case Quality_480P_Low = 0x00000040
    ///480P, middle quality
    case Quality_480P_Middle = 0x00000080
    ///480P, high quality
    case Quality_480P_High = 0x00000100
    ///default resolution and quality, same as `Quality_720P_Middle`
    public static let Quality_Default = RecordProfile(rawValue: 0x00000010)!
}

public enum RecordVideoSize : Int32 {
    ///1080P
    case Vid1080p = 0x00000002
    ///720P
    case Vid720p = 0x00000010
    ///480P
    case Vid480p = 0x00000080
}

public enum RecordZoomMode : Int32 {
    ///If output aspect ratio does not fit input, content will be clipped to fit output aspect ratio.
    case NoZoomAndClip = 0x00000000
    ///If output aspect ratio does not fit input, content will not be clipped and there will be black borders in one dimension.
    case ZoomInWithAllContent = 0x00000001
}

public enum RecordVideoOrientation : Int32 {
    ///video recorded is landscape
    case Landscape = 0x00000000
    ///video recorded is portrait
    case Portrait = 0x00000001
}

public enum RecordStatus : Int32 {
    ///recording start
    case OnStarted = 0x00000002
    ///recording stopped
    case OnStopped = 0x00000004
    ///start fail
    case FailedToStart = 0x00000202
    ///file write succeed
    case FileSucceeded = 0x00000400
    ///file write fail
    case FileFailed = 0x00000401
    ///runtime info with description
    case LogInfo = 0x00000800
    ///runtime error with description
    case LogError = 0x00001000
}

///RecorderConfiguration is startup configuration for `Recorder`_ .
public class RecorderConfiguration : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_RecorderConfiguration__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_RecorderConfiguration__dtor(ptr) })
    }
    ///Sets absolute path for output video file.
    public func setOutputFile(_ path: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_RecorderConfiguration_setOutputFile(cdata_, String_to_c(_ar_, path).ptr_)
    }
    ///Sets recording profile. Default value is Quality_720P_Middle.
    ///This is an all-in-one configuration, you can control in more advanced mode with other APIs.
    public func setProfile(_ profile: RecordProfile) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_RecorderConfiguration_setProfile(cdata_, profile.rawValue)
        return _return_value_
    }
    ///Sets recording video size. Default value is Vid720p.
    public func setVideoSize(_ framesize: RecordVideoSize) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_RecorderConfiguration_setVideoSize(cdata_, framesize.rawValue)
    }
    ///Sets recording video bit rate. Default value is 2500000.
    public func setVideoBitrate(_ bitrate: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_RecorderConfiguration_setVideoBitrate(cdata_, bitrate)
    }
    ///Sets recording audio channel count. Default value is 1.
    public func setChannelCount(_ count: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_RecorderConfiguration_setChannelCount(cdata_, count)
    }
    ///Sets recording audio sample rate. Default value is 44100.
    public func setAudioSampleRate(_ samplerate: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_RecorderConfiguration_setAudioSampleRate(cdata_, samplerate)
    }
    ///Sets recording audio bit rate. Default value is 96000.
    public func setAudioBitrate(_ bitrate: Int32) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_RecorderConfiguration_setAudioBitrate(cdata_, bitrate)
    }
    ///Sets recording video orientation. Default value is Landscape.
    public func setVideoOrientation(_ mode: RecordVideoOrientation) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_RecorderConfiguration_setVideoOrientation(cdata_, mode.rawValue)
    }
    ///Sets recording zoom mode. Default value is NoZoomAndClip.
    public func setZoomMode(_ mode: RecordZoomMode) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_RecorderConfiguration_setZoomMode(cdata_, mode.rawValue)
    }
}

///Describes the result of mapping and localization. Updated at the same frame rate with OutputFrame.
public class SparseSpatialMapResult : FrameFilterResult {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Obtain motion tracking status.
    public func getMotionTrackingStatus() -> MotionTrackingStatus {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SparseSpatialMapResult_getMotionTrackingStatus(cdata_)
        return MotionTrackingStatus(rawValue: _return_value_)!
    }
    ///Returns pose of the origin of VIO system in camera coordinate system.
    public func getVioPose() -> Matrix44F? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SparseSpatialMapResult_getVioPose(cdata_)
        return (_return_value_.has_value ? Matrix44F_from_c(_return_value_.value) : nil)
    }
    ///Returns the pose of origin of the map in camera coordinate system, when localization is successful.
    ///Otherwise, returns pose of the origin of VIO system in camera coordinate system.
    public func getMapPose() -> Matrix44F? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SparseSpatialMapResult_getMapPose(cdata_)
        return (_return_value_.has_value ? Matrix44F_from_c(_return_value_.value) : nil)
    }
    ///Returns true if the system can reliablly locate the pose of the device with regard to the map.
    ///Once relocalization succeeds, relative pose can be updated by motion tracking module.
    ///As long as the motion tracking module returns normal tracking status, the localization status is also true.
    public func getLocalizationStatus() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SparseSpatialMapResult_getLocalizationStatus(cdata_)
        return _return_value_
    }
    ///Returns current localized map ID.
    public func getLocalizationMapID() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMapResult_getLocalizationMapID(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
}

public enum PlaneType : Int32 {
    ///Horizontal plane
    case Horizontal = 0
    ///Vertical plane
    case Vertical = 1
}

public class PlaneData : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Constructor
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_PlaneData__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_PlaneData__dtor(ptr) })
    }
    ///Returns the type of this plane.
    public func getType() -> PlaneType {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_PlaneData_getType(cdata_)
        return PlaneType(rawValue: _return_value_)!
    }
    ///Returns the pose of the center of the detected plane.The pose's transformed +Y axis will be point normal out of the plane, with the +X and +Z axes orienting the extents of the bounding rectangle.
    public func getPose() -> Matrix44F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_PlaneData_getPose(cdata_)
        return Matrix44F_from_c(_return_value_)
    }
    ///Returns the length of this plane's bounding rectangle measured along the local X-axis of the coordinate space centered on the plane.
    public func getExtentX() -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_PlaneData_getExtentX(cdata_)
        return _return_value_
    }
    ///Returns the length of this plane's bounding rectangle measured along the local Z-axis of the coordinate frame centered on the plane.
    public func getExtentZ() -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_PlaneData_getExtentZ(cdata_)
        return _return_value_
    }
}

public enum LocalizationMode : Int32 {
    ///Attempt to perform localization in current SparseSpatialMap until success.
    case UntilSuccess = 0
    ///Perform localization only once
    case Once = 1
    ///Keep performing localization and adjust result on success
    case KeepUpdate = 2
    ///Keep performing localization and adjust localization result only when localization returns different map ID from previous results
    case ContinousLocalize = 3
}

///Configuration used to set the localization mode.
public class SparseSpatialMapConfig : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Constructor
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMapConfig__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_SparseSpatialMapConfig__dtor(ptr) })
    }
    ///Sets localization configurations. See also `LocalizationMode`_.
    public func setLocalizationMode(_ value: LocalizationMode) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SparseSpatialMapConfig_setLocalizationMode(cdata_, value.rawValue)
    }
    ///Returns localization configurations. See also `LocalizationMode`_.
    public func getLocalizationMode() -> LocalizationMode {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SparseSpatialMapConfig_getLocalizationMode(cdata_)
        return LocalizationMode(rawValue: _return_value_)!
    }
}

///Provides core components for SparseSpatialMap, can be used for sparse spatial map building as well as localization using existing map. Also provides utilities for point cloud and plane access.
///SparseSpatialMap occupies 2 buffers of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components. Refer to `Overview <Overview.html>`__ .
public class SparseSpatialMap : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Check whether SparseSpatialMap is is available, always return true.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SparseSpatialMap_isAvailable()
        return _return_value_
    }
    ///Input port for input frame. For SparseSpatialMap to work, the inputFrame must include camera parameters, timestamp and spatial information. See also `InputFrameSink`_
    public func inputFrameSink() -> InputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMap_inputFrameSink(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSink__typeName) as InputFrameSink)
    }
    ///Camera buffers occupied in this component.
    public func bufferRequirement() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SparseSpatialMap_bufferRequirement(cdata_)
        return _return_value_
    }
    ///Output port for output frame. See also `OutputFrameSource`_
    public func outputFrameSource() -> OutputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMap_outputFrameSource(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSource__typeName) as OutputFrameSource)
    }
    ///Construct SparseSpatialMap.
    public static func create() -> SparseSpatialMap {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMap_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_SparseSpatialMap__typeName) as SparseSpatialMap)
    }
    ///Start SparseSpatialMap system.
    public func start() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SparseSpatialMap_start(cdata_)
        return _return_value_
    }
    ///Stop SparseSpatialMap from running。Can resume running by calling start().
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SparseSpatialMap_stop(cdata_)
    }
    ///Close SparseSpatialMap. SparseSpatialMap can no longer be used.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SparseSpatialMap_close(cdata_)
    }
    ///Returns the buffer of point cloud coordinate. Each 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space, each of which takes 4 bytes.
    public func getPointCloudBuffer() -> Buffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMap_getPointCloudBuffer(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Buffer__typeName) as Buffer)
    }
    ///Returns detected planes in SparseSpatialMap.
    public func getMapPlanes() -> [PlaneData] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMap_getMapPlanes(cdata_, _return_value_)
        return ListOfPlaneData_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfPlaneData__dtor(p) })))
    }
    ///Perform hit test against the point cloud. The results are returned sorted by their distance to the camera in ascending order.
    public func hitTestAgainstPointCloud(_ cameraImagePoint: Vec2F) -> [Vec3F] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMap_hitTestAgainstPointCloud(cdata_, Vec2F_to_c(cameraImagePoint), _return_value_)
        return ListOfVec3F_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfVec3F__dtor(p) })))
    }
    ///Performs ray cast from the user's device in the direction of given screen point.
    ///Intersections with detected planes are returned. 3D positions on physical planes are sorted by distance from the device in ascending order.
    ///For the camera image coordinate system ([0, 1]^2), x-right, y-down, and origin is at left-top corner. `CameraParameters.imageCoordinatesFromScreenCoordinates`_ can be used to convert points from screen coordinate system to camera image coordinate system.
    ///The output point cloud coordinate is in the world coordinate system.
    public func hitTestAgainstPlanes(_ cameraImagePoint: Vec2F) -> [Vec3F] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMap_hitTestAgainstPlanes(cdata_, Vec2F_to_c(cameraImagePoint), _return_value_)
        return ListOfVec3F_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfVec3F__dtor(p) })))
    }
    ///Get the map data version of the current SparseSpatialMap.
    public static func getMapVersion() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMap_getMapVersion(_return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///UnloadMap specified SparseSpatialMap data via callback function.The return value of callback indicates whether unload map succeeds (true) or fails (false).
    public func unloadMap(_ mapID: String, _ callbackScheduler: CallbackScheduler, _ resultCallBack: ((Bool) -> Void)?) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SparseSpatialMap_unloadMap(cdata_, String_to_c(_ar_, mapID).ptr_, callbackScheduler.cdata_, (resultCallBack.map({(p) in easyar_OptionalOfFunctorOfVoidFromBool(has_value: true, value: FunctorOfVoidFromBool_to_c(p))}) ?? easyar_OptionalOfFunctorOfVoidFromBool(has_value: false, value: defaultValue())))
    }
    ///Set configurations for SparseSpatialMap. See also `SparseSpatialMapConfig`_.
    public func setConfig(_ config: SparseSpatialMapConfig) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SparseSpatialMap_setConfig(cdata_, config.cdata_)
    }
    ///Returns configurations for SparseSpatialMap. See also `SparseSpatialMapConfig`_.
    public func getConfig() -> SparseSpatialMapConfig {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMap_getConfig(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_SparseSpatialMapConfig__typeName) as SparseSpatialMapConfig)
    }
    ///Start localization in loaded maps. Should set `LocalizationMode`_ first.
    public func startLocalization() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SparseSpatialMap_startLocalization(cdata_)
        return _return_value_
    }
    ///Stop localization in loaded maps.
    public func stopLocalization() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SparseSpatialMap_stopLocalization(cdata_)
    }
}

///SparseSpatialMap manager class, for managing sharing.
public class SparseSpatialMapManager : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Check whether SparseSpatialMapManager is is available. It returns true when the operating system is Windows, Mac, iOS or Android.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_SparseSpatialMapManager_isAvailable()
        return _return_value_
    }
    ///Creates an instance.
    public static func create() -> SparseSpatialMapManager {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_SparseSpatialMapManager_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_SparseSpatialMapManager__typeName) as SparseSpatialMapManager)
    }
    ///Creates a map from `SparseSpatialMap`_ and upload it to EasyAR cloud servers. After completion, a serverMapId will be returned for loading map from EasyAR cloud servers.
    public func host(_ mapBuilder: SparseSpatialMap, _ apiKey: String, _ apiSecret: String, _ sparseSpatialMapAppId: String, _ name: String, _ preview: Image?, _ callbackScheduler: CallbackScheduler, _ onCompleted: @escaping (Bool, String, String) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SparseSpatialMapManager_host(cdata_, mapBuilder.cdata_, String_to_c(_ar_, apiKey).ptr_, String_to_c(_ar_, apiSecret).ptr_, String_to_c(_ar_, sparseSpatialMapAppId).ptr_, String_to_c(_ar_, name).ptr_, (preview.map({(p) in easyar_OptionalOfImage(has_value: true, value: p.cdata_)}) ?? easyar_OptionalOfImage(has_value: false, value: defaultValue())), callbackScheduler.cdata_, FunctorOfVoidFromBoolAndStringAndString_to_c(onCompleted))
    }
    ///Loads a map from EasyAR cloud servers by serverMapId. To unload the map, call `SparseSpatialMap.unloadMap`_ with serverMapId.
    public func load(_ mapTracker: SparseSpatialMap, _ serverMapId: String, _ apiKey: String, _ apiSecret: String, _ sparseSpatialMapAppId: String, _ callbackScheduler: CallbackScheduler, _ onCompleted: @escaping (Bool, String) -> Void) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SparseSpatialMapManager_load(cdata_, mapTracker.cdata_, String_to_c(_ar_, serverMapId).ptr_, String_to_c(_ar_, apiKey).ptr_, String_to_c(_ar_, apiSecret).ptr_, String_to_c(_ar_, sparseSpatialMapAppId).ptr_, callbackScheduler.cdata_, FunctorOfVoidFromBoolAndString_to_c(onCompleted))
    }
    ///Clears allocated cache space.
    public func clear() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SparseSpatialMapManager_clear(cdata_)
    }
}

public class Engine {
    ///Gets the version schema hash, which can be used to ensure type declarations consistent with runtime library.
    public static func schemaHash() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Engine_schemaHash()
        return _return_value_
    }
    public static func initialize(_ key: String) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        if (easyar_Engine_schemaHash() != -2089645540) {
            fatalError("SchemaHashNotMatched");
        }
        let _return_value_ = easyar_Engine_initialize(String_to_c(_ar_, key).ptr_)
        return _return_value_
    }
    ///Handles the app onPause, pauses internal tasks.
    public static func onPause() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Engine_onPause()
    }
    ///Handles the app onResume, resumes internal tasks.
    public static func onResume() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Engine_onResume()
    }
    ///Gets error message on initialization failure.
    public static func errorMessage() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Engine_errorMessage(_return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Gets the version number of EasyARSense.
    public static func versionString() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Engine_versionString(_return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Gets the product name of EasyARSense. (Including variant, operating system and CPU architecture.)
    public static func name() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Engine_name(_return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
}

public enum VideoStatus : Int32 {
    ///Status to indicate something wrong happen in video open or play.
    case Error = -1
    ///Status to show video finished open and is ready for play.
    case Ready = 0
    ///Status to indicate video finished play and reached the end.
    case Completed = 1
}

public enum VideoType : Int32 {
    ///Normal video.
    case Normal = 0
    ///Transparent video, left half is the RGB channel and right half is alpha channel.
    case TransparentSideBySide = 1
    ///Transparent video, top half is the RGB channel and bottom half is alpha channel.
    case TransparentTopAndBottom = 2
}

///VideoPlayer is the class for video playback.
///EasyAR supports normal videos, transparent videos and streaming videos. The video content will be rendered into a texture passed into the player through setRenderTexture.
///This class only supports OpenGLES2 texture.
///Due to the dependency to OpenGLES, every method in this class (including the destructor) has to be called in a single thread containing an OpenGLES context.
///Current version requires width and height being mutiples of 16.
///
///Supported video file formats
///Windows: Media Foundation-compatible formats, more can be supported via extra codecs. Please refer to `Supported Media Formats in Media Foundation <https://docs.microsoft.com/en-us/windows/win32/medfound/supported-media-formats-in-media-foundation>`__ . DirectShow is not supported.
///Mac: Not supported.
///Android: System supported formats. Please refer to `Supported media formats <https://developer.android.com/guide/topics/media/media-formats>`__ .
///iOS: System supported formats. There is no reference in effect currently.
public class VideoPlayer : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_VideoPlayer__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_VideoPlayer__dtor(ptr) })
    }
    ///Checks if the component is available. It returns true only on Windows, Android or iOS. It's not available on Mac.
    public static func isAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_VideoPlayer_isAvailable()
        return _return_value_
    }
    ///Sets the video type. The type will default to normal video if not set manually. It should be called before open.
    public func setVideoType(_ videoType: VideoType) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_VideoPlayer_setVideoType(cdata_, videoType.rawValue)
    }
    ///Passes the texture to display video into player. It should be set before open.
    public func setRenderTexture(_ texture: TextureId) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_VideoPlayer_setRenderTexture(cdata_, texture.cdata_)
    }
    ///Opens a video from path.
    ///path can be a local video file (path/to/video.mp4) or url (http://www.../.../video.mp4). storageType indicates the type of path. See `StorageType`_ for more description.
    ///This method is an asynchronous method. Open may take some time to finish. If you want to know the open result or the play status while playing, you have to handle callback. The callback will be called from a different thread. You can check if the open finished successfully and start play after a successful open.
    public func `open`(_ path: String, _ storageType: StorageType, _ callbackScheduler: CallbackScheduler, _ callback: ((VideoStatus) -> Void)?) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_VideoPlayer_open(cdata_, String_to_c(_ar_, path).ptr_, storageType.rawValue, callbackScheduler.cdata_, (callback.map({(p) in easyar_OptionalOfFunctorOfVoidFromVideoStatus(has_value: true, value: FunctorOfVoidFromVideoStatus_to_c(p))}) ?? easyar_OptionalOfFunctorOfVoidFromVideoStatus(has_value: false, value: defaultValue())))
    }
    ///Closes the video.
    public func close() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_VideoPlayer_close(cdata_)
    }
    ///Starts or continues to play video.
    public func play() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_VideoPlayer_play(cdata_)
        return _return_value_
    }
    ///Stops the video playback.
    public func stop() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_VideoPlayer_stop(cdata_)
    }
    ///Pauses the video playback.
    public func pause() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_VideoPlayer_pause(cdata_)
    }
    ///Checks whether video texture is ready for render. Use this to check if texture passed into the player has been touched.
    public func isRenderTextureAvailable() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_VideoPlayer_isRenderTextureAvailable(cdata_)
        return _return_value_
    }
    ///Updates texture data. This should be called in the renderer thread when isRenderTextureAvailable returns true.
    public func updateFrame() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_VideoPlayer_updateFrame(cdata_)
    }
    ///Returns the video duration. Use after a successful open.
    public func duration() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_VideoPlayer_duration(cdata_)
        return _return_value_
    }
    ///Returns the current position of video. Use after a successful open.
    public func currentPosition() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_VideoPlayer_currentPosition(cdata_)
        return _return_value_
    }
    ///Seeks to play to position . Use after a successful open.
    public func seek(_ position: Int32) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_VideoPlayer_seek(cdata_, position)
        return _return_value_
    }
    ///Returns the video size. Use after a successful open.
    public func size() -> Vec2I {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_VideoPlayer_size(cdata_)
        return Vec2I_from_c(_return_value_)
    }
    ///Returns current volume. Use after a successful open.
    public func volume() -> Float {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_VideoPlayer_volume(cdata_)
        return _return_value_
    }
    ///Sets volume of the video. Use after a successful open.
    public func setVolume(_ volume: Float) -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_VideoPlayer_setVolume(cdata_, volume)
        return _return_value_
    }
}

///Image helper class.
public class ImageHelper {
    ///Decodes a JPEG or PNG file.
    public static func decode(_ buffer: Buffer) -> Image? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfImage>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_ImageHelper_decode(buffer.cdata_, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_Image__typeName) as Image) : nil)
    }
}

///Signal input port.
///It is used to expose input port for a component.
///All members of this class is thread-safe.
public class SignalSink : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input data.
    public func handle() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SignalSink_handle(cdata_)
    }
}

///Signal output port.
///It is used to expose output port for a component.
///All members of this class is thread-safe.
public class SignalSource : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Sets data handler.
    public func setHandler(_ handler: (() -> Void)?) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SignalSource_setHandler(cdata_, (handler.map({(p) in easyar_OptionalOfFunctorOfVoid(has_value: true, value: FunctorOfVoid_to_c(p))}) ?? easyar_OptionalOfFunctorOfVoid(has_value: false, value: defaultValue())))
    }
    ///Connects to input port.
    public func connect(_ sink: SignalSink) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SignalSource_connect(cdata_, sink.cdata_)
    }
    ///Disconnects.
    public func disconnect() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_SignalSource_disconnect(cdata_)
    }
}

///Input frame input port.
///It is used to expose input port for a component.
///All members of this class is thread-safe.
public class InputFrameSink : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input data.
    public func handle(_ inputData: InputFrame) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_InputFrameSink_handle(cdata_, inputData.cdata_)
    }
}

///Input frame output port.
///It is used to expose output port for a component.
///All members of this class is thread-safe.
public class InputFrameSource : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Sets data handler.
    public func setHandler(_ handler: ((InputFrame) -> Void)?) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_InputFrameSource_setHandler(cdata_, (handler.map({(p) in easyar_OptionalOfFunctorOfVoidFromInputFrame(has_value: true, value: FunctorOfVoidFromInputFrame_to_c(p))}) ?? easyar_OptionalOfFunctorOfVoidFromInputFrame(has_value: false, value: defaultValue())))
    }
    ///Connects to input port.
    public func connect(_ sink: InputFrameSink) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_InputFrameSource_connect(cdata_, sink.cdata_)
    }
    ///Disconnects.
    public func disconnect() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_InputFrameSource_disconnect(cdata_)
    }
}

///Output frame input port.
///It is used to expose input port for a component.
///All members of this class is thread-safe.
public class OutputFrameSink : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input data.
    public func handle(_ inputData: OutputFrame) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_OutputFrameSink_handle(cdata_, inputData.cdata_)
    }
}

///Output frame output port.
///It is used to expose output port for a component.
///All members of this class is thread-safe.
public class OutputFrameSource : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Sets data handler.
    public func setHandler(_ handler: ((OutputFrame) -> Void)?) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_OutputFrameSource_setHandler(cdata_, (handler.map({(p) in easyar_OptionalOfFunctorOfVoidFromOutputFrame(has_value: true, value: FunctorOfVoidFromOutputFrame_to_c(p))}) ?? easyar_OptionalOfFunctorOfVoidFromOutputFrame(has_value: false, value: defaultValue())))
    }
    ///Connects to input port.
    public func connect(_ sink: OutputFrameSink) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_OutputFrameSource_connect(cdata_, sink.cdata_)
    }
    ///Disconnects.
    public func disconnect() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_OutputFrameSource_disconnect(cdata_)
    }
}

///Feedback frame input port.
///It is used to expose input port for a component.
///All members of this class is thread-safe.
public class FeedbackFrameSink : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input data.
    public func handle(_ inputData: FeedbackFrame) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_FeedbackFrameSink_handle(cdata_, inputData.cdata_)
    }
}

///Feedback frame output port.
///It is used to expose output port for a component.
///All members of this class is thread-safe.
public class FeedbackFrameSource : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Sets data handler.
    public func setHandler(_ handler: ((FeedbackFrame) -> Void)?) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_FeedbackFrameSource_setHandler(cdata_, (handler.map({(p) in easyar_OptionalOfFunctorOfVoidFromFeedbackFrame(has_value: true, value: FunctorOfVoidFromFeedbackFrame_to_c(p))}) ?? easyar_OptionalOfFunctorOfVoidFromFeedbackFrame(has_value: false, value: defaultValue())))
    }
    ///Connects to input port.
    public func connect(_ sink: FeedbackFrameSink) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_FeedbackFrameSource_connect(cdata_, sink.cdata_)
    }
    ///Disconnects.
    public func disconnect() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_FeedbackFrameSource_disconnect(cdata_)
    }
}

///Input frame fork.
///It is used to branch and transfer input frame to multiple components in parallel.
///All members of this class is thread-safe.
public class InputFrameFork : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input port.
    public func input() -> InputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameFork_input(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSink__typeName) as InputFrameSink)
    }
    ///Output port.
    public func output(_ index: Int32) -> InputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameFork_output(cdata_, index, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSource__typeName) as InputFrameSource)
    }
    ///Output count.
    public func outputCount() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrameFork_outputCount(cdata_)
        return _return_value_
    }
    ///Creates an instance.
    public static func create(_ outputCount: Int32) -> InputFrameFork {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameFork_create(outputCount, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameFork__typeName) as InputFrameFork)
    }
}

///Output frame fork.
///It is used to branch and transfer output frame to multiple components in parallel.
///All members of this class is thread-safe.
public class OutputFrameFork : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input port.
    public func input() -> OutputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameFork_input(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSink__typeName) as OutputFrameSink)
    }
    ///Output port.
    public func output(_ index: Int32) -> OutputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameFork_output(cdata_, index, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSource__typeName) as OutputFrameSource)
    }
    ///Output count.
    public func outputCount() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_OutputFrameFork_outputCount(cdata_)
        return _return_value_
    }
    ///Creates an instance.
    public static func create(_ outputCount: Int32) -> OutputFrameFork {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameFork_create(outputCount, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameFork__typeName) as OutputFrameFork)
    }
}

///Output frame join.
///It is used to aggregate output frame from multiple components in parallel.
///All members of this class is thread-safe.
///It shall be noticed that connections and disconnections to the inputs shall not be performed during the flowing of data, or it may stuck in a state that no frame can be output. (It is recommended to complete dataflow connection before start a camera.)
public class OutputFrameJoin : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input port.
    public func input(_ index: Int32) -> OutputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameJoin_input(cdata_, index, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSink__typeName) as OutputFrameSink)
    }
    ///Output port.
    public func output() -> OutputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameJoin_output(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSource__typeName) as OutputFrameSource)
    }
    ///Input count.
    public func inputCount() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_OutputFrameJoin_inputCount(cdata_)
        return _return_value_
    }
    ///Creates an instance. The default joiner will be used, which takes input frame from the first input and first result or null of each input. The first result of every input will be placed at the corresponding input index of results of the final output frame.
    public static func create(_ inputCount: Int32) -> OutputFrameJoin {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameJoin_create(inputCount, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameJoin__typeName) as OutputFrameJoin)
    }
    ///Creates an instance. A custom joiner is specified.
    public static func createWithJoiner(_ inputCount: Int32, _ joiner: @escaping ([OutputFrame]) -> OutputFrame) -> OutputFrameJoin {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameJoin_createWithJoiner(inputCount, FunctorOfOutputFrameFromListOfOutputFrame_to_c(joiner), _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameJoin__typeName) as OutputFrameJoin)
    }
}

///Feedback frame fork.
///It is used to branch and transfer feedback frame to multiple components in parallel.
///All members of this class is thread-safe.
public class FeedbackFrameFork : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input port.
    public func input() -> FeedbackFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_FeedbackFrameFork_input(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_FeedbackFrameSink__typeName) as FeedbackFrameSink)
    }
    ///Output port.
    public func output(_ index: Int32) -> FeedbackFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_FeedbackFrameFork_output(cdata_, index, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_FeedbackFrameSource__typeName) as FeedbackFrameSource)
    }
    ///Output count.
    public func outputCount() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_FeedbackFrameFork_outputCount(cdata_)
        return _return_value_
    }
    ///Creates an instance.
    public static func create(_ outputCount: Int32) -> FeedbackFrameFork {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_FeedbackFrameFork_create(outputCount, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_FeedbackFrameFork__typeName) as FeedbackFrameFork)
    }
}

///Input frame throttler.
///There is a input frame input port and a input frame output port. It can be used to prevent incoming frames from entering algorithm components when they have not finished handling previous workload.
///InputFrameThrottler occupies one buffer of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components. Refer to `Overview <Overview.html>`__ .
///All members of this class is thread-safe.
///It shall be noticed that connections and disconnections to signalInput shall not be performed during the flowing of data, or it may stuck in a state that no frame can be output. (It is recommended to complete dataflow connection before start a camera.)
public class InputFrameThrottler : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input port.
    public func input() -> InputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameThrottler_input(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSink__typeName) as InputFrameSink)
    }
    ///Camera buffers occupied in this component.
    public func bufferRequirement() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrameThrottler_bufferRequirement(cdata_)
        return _return_value_
    }
    ///Output port.
    public func output() -> InputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameThrottler_output(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSource__typeName) as InputFrameSource)
    }
    ///Input port for clearance signal.
    public func signalInput() -> SignalSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameThrottler_signalInput(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_SignalSink__typeName) as SignalSink)
    }
    ///Creates an instance.
    public static func create() -> InputFrameThrottler {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameThrottler_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameThrottler__typeName) as InputFrameThrottler)
    }
}

///Output frame buffer.
///There is an output frame input port and output frame fetching function. It can be used to convert output frame fetching from asynchronous pattern to synchronous polling pattern, which fits frame by frame rendering.
///OutputFrameBuffer occupies one buffer of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components. Refer to `Overview <Overview.html>`__ .
///All members of this class is thread-safe.
public class OutputFrameBuffer : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input port.
    public func input() -> OutputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameBuffer_input(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSink__typeName) as OutputFrameSink)
    }
    ///Camera buffers occupied in this component.
    public func bufferRequirement() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_OutputFrameBuffer_bufferRequirement(cdata_)
        return _return_value_
    }
    ///Output port for frame arrival. It can be connected to `InputFrameThrottler.signalInput`_ .
    public func signalOutput() -> SignalSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameBuffer_signalOutput(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_SignalSource__typeName) as SignalSource)
    }
    ///Fetches the most recent `OutputFrame`_ .
    public func peek() -> OutputFrame? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfOutputFrame>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameBuffer_peek(cdata_, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_OutputFrame__typeName) as OutputFrame) : nil)
    }
    ///Creates an instance.
    public static func create() -> OutputFrameBuffer {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrameBuffer_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameBuffer__typeName) as OutputFrameBuffer)
    }
    ///Pauses output of `OutputFrame`_ . After execution, all results of `OutputFrameBuffer.peek`_ will be empty. `OutputFrameBuffer.signalOutput`_  is not affected.
    public func pause() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_OutputFrameBuffer_pause(cdata_)
    }
    ///Resumes output of `OutputFrame`_ .
    public func resume() -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_OutputFrameBuffer_resume(cdata_)
    }
}

///Input frame to output frame adapter.
///There is an input frame input port and an output frame output port. It can be used to wrap an input frame into an output frame, which can be used for rendering without an algorithm component. Refer to `Overview <Overview.html>`__ .
///All members of this class is thread-safe.
public class InputFrameToOutputFrameAdapter : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input port.
    public func input() -> InputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameToOutputFrameAdapter_input(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSink__typeName) as InputFrameSink)
    }
    ///Output port.
    public func output() -> OutputFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameToOutputFrameAdapter_output(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSource__typeName) as OutputFrameSource)
    }
    ///Creates an instance.
    public static func create() -> InputFrameToOutputFrameAdapter {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameToOutputFrameAdapter_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameToOutputFrameAdapter__typeName) as InputFrameToOutputFrameAdapter)
    }
}

///Input frame to feedback frame adapter.
///There is an input frame input port, a historic output frame input port and a feedback frame output port. It can be used to combine an input frame and a historic output frame into a feedback frame, which is required by algorithm components such as `ImageTracker`_ .
///On every input of an input frame, a feedback frame is generated with a previously input historic feedback frame. If there is no previously input historic feedback frame, it is null in the feedback frame.
///InputFrameToFeedbackFrameAdapter occupies one buffer of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components. Refer to `Overview <Overview.html>`__ .
///All members of this class is thread-safe.
public class InputFrameToFeedbackFrameAdapter : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Input port.
    public func input() -> InputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameToFeedbackFrameAdapter_input(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameSink__typeName) as InputFrameSink)
    }
    ///Camera buffers occupied in this component.
    public func bufferRequirement() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrameToFeedbackFrameAdapter_bufferRequirement(cdata_)
        return _return_value_
    }
    ///Side input port for historic output frame input.
    public func sideInput() -> OutputFrameSink {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameToFeedbackFrameAdapter_sideInput(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_OutputFrameSink__typeName) as OutputFrameSink)
    }
    ///Output port.
    public func output() -> FeedbackFrameSource {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameToFeedbackFrameAdapter_output(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_FeedbackFrameSource__typeName) as FeedbackFrameSource)
    }
    ///Creates an instance.
    public static func create() -> InputFrameToFeedbackFrameAdapter {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrameToFeedbackFrameAdapter_create(_return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrameToFeedbackFrameAdapter__typeName) as InputFrameToFeedbackFrameAdapter)
    }
}

///Input frame.
///It includes image, camera parameters, timestamp, camera transform matrix against world coordinate system, and tracking status,
///among which, camera parameters, timestamp, camera transform matrix and tracking status are all optional, but specific algorithms may have special requirements on the input.
public class InputFrame : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Index, an automatic incremental value, which is different for every input frame.
    public func index() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrame_index(cdata_)
        return _return_value_
    }
    ///Gets image.
    public func image() -> Image {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrame_image(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_Image__typeName) as Image)
    }
    ///Checks if there are camera parameters.
    public func hasCameraParameters() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrame_hasCameraParameters(cdata_)
        return _return_value_
    }
    ///Gets camera parameters.
    public func cameraParameters() -> CameraParameters {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrame_cameraParameters(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_CameraParameters__typeName) as CameraParameters)
    }
    ///Checks if there is temporal information (timestamp).
    public func hasTemporalInformation() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrame_hasTemporalInformation(cdata_)
        return _return_value_
    }
    ///Timestamp. In seconds.
    public func timestamp() -> Double {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrame_timestamp(cdata_)
        return _return_value_
    }
    ///Checks if there is spatial information (cameraTransform and trackingStatus).
    public func hasSpatialInformation() -> Bool {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrame_hasSpatialInformation(cdata_)
        return _return_value_
    }
    ///Camera transform matrix against world coordinate system. Camera coordinate system and world coordinate system are all right-handed. For the camera coordinate system, the origin is the optical center, x-right, y-up, and z in the direction of light going into camera. (The right and up, on mobile devices, is the right and up when the device is in the natural orientation.) The data arrangement is row-major, not like OpenGL's column-major.
    public func cameraTransform() -> Matrix44F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrame_cameraTransform(cdata_)
        return Matrix44F_from_c(_return_value_)
    }
    ///Gets device motion tracking status: `MotionTrackingStatus`_ .
    public func trackingStatus() -> MotionTrackingStatus {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_InputFrame_trackingStatus(cdata_)
        return MotionTrackingStatus(rawValue: _return_value_)!
    }
    ///Creates an instance.
    public static func create(_ image: Image, _ cameraParameters: CameraParameters, _ timestamp: Double, _ cameraTransform: Matrix44F, _ trackingStatus: MotionTrackingStatus) -> InputFrame {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrame_create(image.cdata_, cameraParameters.cdata_, timestamp, Matrix44F_to_c(cameraTransform), trackingStatus.rawValue, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrame__typeName) as InputFrame)
    }
    ///Creates an instance with image, camera parameters, and timestamp.
    public static func createWithImageAndCameraParametersAndTemporal(_ image: Image, _ cameraParameters: CameraParameters, _ timestamp: Double) -> InputFrame {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrame_createWithImageAndCameraParametersAndTemporal(image.cdata_, cameraParameters.cdata_, timestamp, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrame__typeName) as InputFrame)
    }
    ///Creates an instance with image and camera parameters.
    public static func createWithImageAndCameraParameters(_ image: Image, _ cameraParameters: CameraParameters) -> InputFrame {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrame_createWithImageAndCameraParameters(image.cdata_, cameraParameters.cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrame__typeName) as InputFrame)
    }
    ///Creates an instance with image.
    public static func createWithImage(_ image: Image) -> InputFrame {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_InputFrame_createWithImage(image.cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrame__typeName) as InputFrame)
    }
}

///FrameFilterResult is the base class for result classes of all synchronous algorithm components.
public class FrameFilterResult : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
}

///Output frame.
///It includes input frame and results of synchronous components.
public class OutputFrame : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init(_ inputFrame: InputFrame, _ results: [FrameFilterResult?]) {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrame__ctor(inputFrame.cdata_, ListOfOptionalOfFrameFilterResult_to_c(_ar_, results).ptr_, _return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_OutputFrame__dtor(ptr) })
    }
    ///Index, an automatic incremental value, which is different for every output frame.
    public func index() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_OutputFrame_index(cdata_)
        return _return_value_
    }
    ///Corresponding input frame.
    public func inputFrame() -> InputFrame {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrame_inputFrame(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrame__typeName) as InputFrame)
    }
    ///Results of synchronous components.
    public func results() -> [FrameFilterResult?] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_OutputFrame_results(cdata_, _return_value_)
        return ListOfOptionalOfFrameFilterResult_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfOptionalOfFrameFilterResult__dtor(p) })))
    }
}

///Feedback frame.
///It includes an input frame and a historic output frame for use in feedback synchronous components such as `ImageTracker`_ .
public class FeedbackFrame : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init(_ inputFrame: InputFrame, _ previousOutputFrame: OutputFrame?) {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_FeedbackFrame__ctor(inputFrame.cdata_, (previousOutputFrame.map({(p) in easyar_OptionalOfOutputFrame(has_value: true, value: p.cdata_)}) ?? easyar_OptionalOfOutputFrame(has_value: false, value: defaultValue())), _return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_FeedbackFrame__dtor(ptr) })
    }
    ///Input frame.
    public func inputFrame() -> InputFrame {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_FeedbackFrame_inputFrame(cdata_, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_InputFrame__typeName) as InputFrame)
    }
    ///Historic output frame.
    public func previousOutputFrame() -> OutputFrame? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfOutputFrame>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_FeedbackFrame_previousOutputFrame(cdata_, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_OutputFrame__typeName) as OutputFrame) : nil)
    }
}

public enum PermissionStatus : Int32 {
    ///Permission granted
    case Granted = 0x00000000
    ///Permission denied
    case Denied = 0x00000001
    ///A error happened while requesting permission.
    case Error = 0x00000002
}

///StorageType represents where the images, jsons, videos or other files are located.
///StorageType specifies the root path, in all interfaces, you can use relative path relative to the root path.
public enum StorageType : Int32 {
    ///The app path.
    ///Android: the application's `persistent data directory <https://developer.android.google.cn/reference/android/content/pm/ApplicationInfo.html#dataDir>`__
    ///iOS: the application's sandbox directory
    ///Windows: Windows: the application's executable directory
    ///Mac: the application’s executable directory (if app is a bundle, this path is inside the bundle)
    case App = 0
    ///The assets path.
    ///Android: assets directory (inside apk)
    ///iOS: the application's executable directory
    ///Windows: EasyAR.dll directory
    ///Mac: libEasyAR.dylib directory
    ///**Note:** *this path is different if you are using Unity3D. It will point to the StreamingAssets folder.*
    case Assets = 1
    ///The absolute path (json/image path or video path) or url (video only).
    case Absolute = 2
}

///Target is the base class for all targets that can be tracked by `ImageTracker`_ or other algorithms inside EasyAR.
public class Target : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns the target id. A target id is a integer number generated at runtime. This id is non-zero and increasing globally.
    public func runtimeID() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_Target_runtimeID(cdata_)
        return _return_value_
    }
    ///Returns the target uid. A target uid is useful in cloud based algorithms. If no cloud is used, you can set this uid in the json config as a alternative method to distinguish from targets.
    public func uid() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Target_uid(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Returns the target name. Name is used to distinguish targets in a json file.
    public func name() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Target_name(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Set name. It will erase previously set data or data from cloud.
    public func setName(_ name: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Target_setName(cdata_, String_to_c(_ar_, name).ptr_)
    }
    ///Returns the meta data set by setMetaData. Or, in a cloud returned target, returns the meta data set in the cloud server.
    public func meta() -> String {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_Target_meta(cdata_, _return_value_)
        return String_from_c(_ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_String__dtor(p) })))
    }
    ///Set meta data. It will erase previously set data or data from cloud.
    public func setMeta(_ data: String) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_Target_setMeta(cdata_, String_to_c(_ar_, data).ptr_)
    }
}

public enum TargetStatus : Int32 {
    ///The status is unknown.
    case Unknown = 0
    ///The status is undefined.
    case Undefined = 1
    ///The target is detected.
    case Detected = 2
    ///The target is tracked.
    case Tracked = 3
}

///TargetInstance is the tracked target by trackers.
///An TargetInstance contains a raw `Target`_ that is tracked and current status and pose of the `Target`_ .
public class TargetInstance : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    public convenience init() {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_TargetInstance__ctor(_return_value_)
        self.init(cdata: _return_value_.pointee, deleter: { ptr in easyar_TargetInstance__dtor(ptr) })
    }
    ///Returns current status of the tracked target. Usually you can check if the status equals `TargetStatus.Tracked` to determine current status of the target.
    public func status() -> TargetStatus {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_TargetInstance_status(cdata_)
        return TargetStatus(rawValue: _return_value_)!
    }
    ///Gets the raw target. It will return the same `Target`_ you loaded into a tracker if it was previously loaded into the tracker.
    public func target() -> Target? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<easyar_OptionalOfTarget>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_TargetInstance_target(cdata_, _return_value_)
        return (_return_value_.pointee.has_value ? (Object_from_c(_return_value_.pointee.value!, easyar_Target__typeName) as Target) : nil)
    }
    ///Returns current pose of the tracked target. Camera coordinate system and target coordinate system are all right-handed. For the camera coordinate system, the origin is the optical center, x-right, y-up, and z in the direction of light going into camera. (The right and up, on mobile devices, is the right and up when the device is in the natural orientation.) The data arrangement is row-major, not like OpenGL's column-major.
    public func pose() -> Matrix44F {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_TargetInstance_pose(cdata_)
        return Matrix44F_from_c(_return_value_)
    }
}

///TargetTrackerResult is the base class of `ImageTrackerResult`_ and `ObjectTrackerResult`_ .
public class TargetTrackerResult : FrameFilterResult {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Returns the list of `TargetInstance`_ contained in the result.
    public func targetInstances() -> [TargetInstance] {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_TargetTrackerResult_targetInstances(cdata_, _return_value_)
        return ListOfTargetInstance_from_c(_ar_, _ar_.add(OpaquePointerContainer(_return_value_.pointee, { p in easyar_ListOfTargetInstance__dtor(p) })))
    }
    ///Sets the list of `TargetInstance`_ contained in the result.
    public func setTargetInstances(_ instances: [TargetInstance]) -> Void {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        easyar_TargetTrackerResult_setTargetInstances(cdata_, ListOfTargetInstance_to_c(_ar_, instances).ptr_)
    }
}

///TextureId encapsulates a texture object in rendering API.
///For OpenGL/OpenGLES, getInt and fromInt shall be used. For Direct3D, getPointer and fromPointer shall be used.
public class TextureId : RefBase {
    fileprivate override init(cdata: OpaquePointer, deleter: @escaping (OpaquePointer) -> Void) {
        super.init(cdata: cdata, deleter: deleter)
    }
    ///Gets ID of an OpenGL/OpenGLES texture object.
    public func getInt() -> Int32 {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_TextureId_getInt(cdata_)
        return _return_value_
    }
    ///Gets pointer of a Direct3D texture object.
    public func getPointer() -> OpaquePointer? {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = easyar_TextureId_getPointer(cdata_)
        return _return_value_
    }
    ///Creates from ID of an OpenGL/OpenGLES texture object.
    public static func fromInt(_ value: Int32) -> TextureId {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_TextureId_fromInt(value, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_TextureId__typeName) as TextureId)
    }
    ///Creates from pointer of a Direct3D texture object.
    public static func fromPointer(_ ptr: OpaquePointer?) -> TextureId {
        let _ar_ = AutoRelease()
        defer {
            _ar_.dispose()
        }
        let _return_value_ = UnsafeMutablePointer<OpaquePointer>.allocate(capacity: 1)
        defer {
            _return_value_.deallocate()
        }
        easyar_TextureId_fromPointer(ptr, _return_value_)
        return (Object_from_c(_return_value_.pointee, easyar_TextureId__typeName) as TextureId)
    }
}
