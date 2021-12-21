#pragma once

#include "CommonRenderResources.h"
#include "ShaderParameterUtils.h"
#include "RHIStaticStates.h"
#include "CameraRenderer.h"



class FCameraBackgroundVB : public FVertexBuffer
{
public:
	void InitRHI() override
	{
		TResourceArray<FFilterVertex, VERTEXBUFFER_ALIGNMENT> Vertices;
		Vertices.SetNumUninitialized(6);

		Vertices[0].Position = FVector4(1, 1, 0, 1);
		Vertices[0].UV = FVector2D(1, 1);

		Vertices[1].Position = FVector4(-1, 1, 0, 1);
		Vertices[1].UV = FVector2D(0, 1);

		Vertices[2].Position = FVector4(1, -1, 0, 1);
		Vertices[2].UV = FVector2D(1, 0);

		Vertices[3].Position = FVector4(-1, -1, 0, 1);
		Vertices[3].UV = FVector2D(0, 0);

		// Create vertex buffer. Fill buffer with initial data upon creation
		FRHIResourceCreateInfo CreateInfo(&Vertices);
		VertexBufferRHI = RHICreateVertexBuffer(Vertices.GetResourceDataSize(), BUF_Static, CreateInfo);
	}
};

inline TGlobalResource<FCameraBackgroundVB> GCameraBackgroundVB;

class FCameraBackgroundVS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FCameraBackgroundVS);

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}

	FCameraBackgroundVS() { }
	FCameraBackgroundVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer) : FGlobalShader(Initializer) { }
};

BEGIN_SHADER_PARAMETER_STRUCT(FCameraBackgroundParameters, )
	SHADER_PARAMETER(FMatrix, Projection)
	SHADER_PARAMETER_SRV(Texture2D, BackTexture)
	SHADER_PARAMETER_SRV(Texture2D, BackTextureUV)
	// SHADER_PARAMETER_SRV(Texture2D, BackTextureU)
	// SHADER_PARAMETER_SRV(Texture2D, BackTextureV)
	SHADER_PARAMETER_SAMPLER(SamplerState, Sampler)
END_SHADER_PARAMETER_STRUCT()

class FCameraBackgroundPS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FCameraBackgroundPS);
	SHADER_USE_PARAMETER_STRUCT(FCameraBackgroundPS, FGlobalShader);
    using FParameters = FCameraBackgroundParameters;
	
	// class FShaderPF_RGB : SHADER_PERMUTATION_ENUM_CLASS("ShaderPF_RGB", EShaderPixelFormat);
	// class FShaderPF_BGR : SHADER_PERMUTATION_ENUM_CLASS("ShaderPF_BGR", EShaderPixelFormat);
	// class FShaderPF_NV12 : SHADER_PERMUTATION_ENUM_CLASS("ShaderPF_NV12", EShaderPixelFormat);
	// class FShaderPF_NV21 : SHADER_PERMUTATION_ENUM_CLASS("ShaderPF_NV21", EShaderPixelFormat);
	// class FShaderPF_I420 : SHADER_PERMUTATION_ENUM_CLASS("ShaderPF_I420", EShaderPixelFormat);
	//
	// using FPermutationDomain = TShaderPermutationDomain<
	// 	FShaderPF_RGB, FShaderPF_BGR,
	// 	FShaderPF_NV12, FShaderPF_NV21,
	// 	FShaderPF_I420>;

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::ES3_1);
	}
};