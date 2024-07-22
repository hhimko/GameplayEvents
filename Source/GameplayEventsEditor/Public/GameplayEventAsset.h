#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class IToolkitHost;

class FGameplayEventAsset : public FAssetTypeActions_Base
{
public:
	FGameplayEventAsset(EAssetTypeCategories::Type Category);

	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
	virtual uint32 GetCategories() override;

private:
	EAssetTypeCategories::Type AssetCategory;

};
