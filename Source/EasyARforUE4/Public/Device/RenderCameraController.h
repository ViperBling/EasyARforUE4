#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "easyar/types.hpp"
#include "RenderCameraController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRenderCameraDelegate);
class RenderCameraEventHandler;
class RenderCameraParameters;

UCLASS()
class URenderCameraController : public UCameraComponent
{
	GENERATED_BODY()
public:
	TSharedPtr<RenderCameraParameters> ExternalParameters;
	TSharedPtr<RenderCameraEventHandler> RenderEvent;
};

class RenderCameraEventHandler
{
public:
	FRenderCameraDelegate PreRender;
	FRenderCameraDelegate PostRender;

private:
	void OnPreRender()
	{
		if (PreRender.IsBound())
			PreRender.Broadcast();
	}
	void OnPostRender()
	{
		if (PostRender.IsBound())
			PostRender.Broadcast();
	}
};

class RenderCameraParameters
{
public:
	RenderCameraParameters(){}	
private:
	inline static FVector PositionScale = FVector(1, -1, -1);

	~RenderCameraParameters()
	{
		Parameters = nullptr;
	}

public:
	FString DeviceModel;
	FVector PositionOffset;
	FVector RotationOffset;
	FVector2D Size;
	// FVector2D FocalLength;
	// FVector2D PrincipalPoint;
	
	FTransform Transform;
	std::shared_ptr<easyar::CameraParameters> Parameters;

	void Build(std::shared_ptr<easyar::CameraParameters> CameraParameters)
	{
		FVector Translation = PositionOffset * PositionScale;
		Transform.SetTranslation(Translation);
		FRotator Rotator(RotationOffset.X, RotationOffset.Y, RotationOffset.Z);
		Transform.SetRotation(FQuat(Rotator));
		Transform.SetScale3D(FVector(1.));
		if (Parameters != nullptr)
		{
			Parameters = nullptr;
		}
		
		Parameters = easyar::CameraParameters::createWithDefaultIntrinsics(
			easyar::Vec2I{(int)Size.X, (int)Size.Y},
			CameraParameters->cameraDeviceType(),
			CameraParameters->cameraOrientation());
	}
};