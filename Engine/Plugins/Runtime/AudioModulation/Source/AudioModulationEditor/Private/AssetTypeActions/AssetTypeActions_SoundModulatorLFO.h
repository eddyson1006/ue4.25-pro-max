// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class FAssetTypeActions_SoundModulatorLFO : public FAssetTypeActions_Base
{
public:
	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_SoundModulatorLFO", "Control Modulator (LFO)"); }
	virtual FColor GetTypeColor() const override { return FColor(237, 237, 0); }
	virtual const TArray<FText>& GetSubMenus() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override { return EAssetTypeCategories::Sounds; }
};
