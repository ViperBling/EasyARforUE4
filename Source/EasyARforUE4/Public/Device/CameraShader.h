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

		Vertices[0].Position = FVector4(-1.0f, 1.0f, 1.0f, 1.0f);
		Vertices[0].UV = FVector2D(0, 0);

		Vertices[1].Position = FVector4(1.0f, 1.0f, 1.0f, 1.0f);
		Vertices[1].UV = FVector2D(1, 0);

		Vertices[2].Position = FVector4(-1.0f, -1.0f, 1.0f, 1.0f);
		Vertices[2].UV = FVector2D(0, 1);

		Vertices[3].Position = FVector4(1.0f, -1.0f, 1.0f, 1.0f);
		Vertices[3].UV = FVector2D(1, 1);

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
	// SHADER_PARAMETER(FMatrix, Projection)
	SHADER_PARAMETER_SRV(Texture2D, BackTexture)
	SHADER_PARAMETER(uint32, OutWidth)
	SHADER_PARAMETER(uint32, SRGBToLinear)
	SHADER_PARAMETER(FVector2D, UVScale)
	SHADER_PARAMETER_SAMPLER(SamplerState, BaseSampler)
	SHADER_PARAMETER_SAMPLER(SamplerState, BaseSamplerUV)
END_SHADER_PARAMETER_STRUCT()

class FCameraBackgroundPS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FCameraBackgroundPS);
	SHADER_USE_PARAMETER_STRUCT(FCameraBackgroundPS, FGlobalShader);
	using FParameters = FCameraBackgroundParameters;

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::ES3_1);
	}
};