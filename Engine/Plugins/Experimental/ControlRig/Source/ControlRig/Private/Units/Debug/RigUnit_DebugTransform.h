// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Units/Debug/RigUnit_DebugBase.h"
#include "RigUnit_DebugTransform.generated.h"

UENUM()
enum class ERigUnitDebugTransformMode : uint8
{
	/** Draw as point */
	Point,

	/** Draw as axes */
	Axes,

	/** Draw as box */
	Box,

	/** MAX - invalid */
	Max UMETA(Hidden),
};

USTRUCT(meta=(DisplayName="Draw Transform In Place", Deprecated = "4.25.0"))
struct FRigUnit_DebugTransform : public FRigUnit_DebugBase
{
	GENERATED_BODY()

	FRigUnit_DebugTransform()
	{
		Transform = WorldOffset = FTransform::Identity;
		Mode = ERigUnitDebugTransformMode::Axes;
		Color = FLinearColor::Red;
		Thickness = 0.f;
		Scale = 10.f;
		bEnabled = true;
	}

	RIGVM_METHOD()
	virtual void Execute(const FRigUnitContext& Context) override;

	UPROPERTY(meta = (Input, Output))
	FTransform Transform;

	UPROPERTY(meta = (Input))
	ERigUnitDebugTransformMode Mode;

	UPROPERTY(meta = (Input))
	FLinearColor Color;

	UPROPERTY(meta = (Input))
	float Thickness;

	UPROPERTY(meta = (Input))
	float Scale;

	UPROPERTY(meta = (Input, Constant, CustomWidget = "BoneName"))
	FName Space;

	UPROPERTY(meta = (Input))
	FTransform WorldOffset;

	UPROPERTY(meta = (Input, Constant))
	bool bEnabled;
};

USTRUCT(meta=(DisplayName="Draw Transform", Deprecated = "4.25.0"))
struct FRigUnit_DebugTransformMutable : public FRigUnit_DebugBaseMutable
{
	GENERATED_BODY()

	FRigUnit_DebugTransformMutable()
	{
		Transform = WorldOffset = FTransform::Identity;
		Mode = ERigUnitDebugTransformMode::Axes;
		Color = FLinearColor::Red;
		Thickness = 0.f;
		Scale = 10.f;
		bEnabled = true;
	}

	RIGVM_METHOD()
	virtual void Execute(const FRigUnitContext& Context) override;

	UPROPERTY(meta = (Input))
	FTransform Transform;

	UPROPERTY(meta = (Input))
	ERigUnitDebugTransformMode Mode;

	UPROPERTY(meta = (Input))
	FLinearColor Color;

	UPROPERTY(meta = (Input))
	float Thickness;

	UPROPERTY(meta = (Input))
	float Scale;

	UPROPERTY(meta = (Input, Constant, CustomWidget = "BoneName"))
	FName Space;

	UPROPERTY(meta = (Input))
	FTransform WorldOffset;

	UPROPERTY(meta = (Input, Constant))
	bool bEnabled;
};

USTRUCT()
struct FRigUnit_DebugTransformArrayMutable_WorkData
{
	GENERATED_BODY()
		
	UPROPERTY()
	TArray<FTransform> DrawTransforms;
};

USTRUCT(meta=(DisplayName="Draw Transform Array", Deprecated = "4.25.0"))
struct FRigUnit_DebugTransformArrayMutable : public FRigUnit_DebugBaseMutable
{
 	GENERATED_BODY()

	FRigUnit_DebugTransformArrayMutable()
	{
		Mode = ERigUnitDebugTransformMode::Axes;
		Color = FLinearColor::Red;
		Thickness = 0.f;
		Scale = 10.f;
		WorldOffset = FTransform::Identity;
		bEnabled = true;
	}

	RIGVM_METHOD()
	virtual void Execute(const FRigUnitContext& Context) override;

	UPROPERTY(meta = (Input))
	TArray<FTransform> Transforms;

	UPROPERTY(meta = (Input))
	ERigUnitDebugTransformMode Mode;

	UPROPERTY(meta = (Input))
	FLinearColor Color;

	UPROPERTY(meta = (Input))
	float Thickness;

	UPROPERTY(meta = (Input))
	float Scale;

	UPROPERTY(meta = (Input, Constant, CustomWidget = "BoneName"))
	FName Space;

	UPROPERTY(meta = (Input))
	FTransform WorldOffset;

	UPROPERTY(meta = (Input, Constant))
	bool bEnabled;

	UPROPERTY(transient)
	FRigUnit_DebugTransformArrayMutable_WorkData WorkData;
};