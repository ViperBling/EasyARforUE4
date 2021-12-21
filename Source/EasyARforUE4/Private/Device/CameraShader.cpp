#include "Device/CameraShader.h"

#include "CommonRenderResources.h"
#include "ShaderParameterUtils.h"
#include "RHIStaticStates.h"

IMPLEMENT_GLOBAL_SHADER(FCameraBackgroundVS, "/EasyARShaders/Private/CameraRender.usf", "MainVS", SF_Vertex);
IMPLEMENT_GLOBAL_SHADER(FCameraBackgroundPS, "/EasyARShaders/Private/CameraRender.usf", "MainPS", SF_Pixel);