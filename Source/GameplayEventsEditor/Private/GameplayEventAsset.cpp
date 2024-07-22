#include "GameplayEventAsset.h"

#include "GameplayEvent.h"

FGameplayEventAsset::FGameplayEventAsset(EAssetTypeCategories::Type Category)
	: AssetCategory(Category)
{

}

FText FGameplayEventAsset::GetName() const
{
	return FText::FromString(TEXT("Gameplay Event Asset"));
}

FColor FGameplayEventAsset::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FGameplayEventAsset::GetSupportedClass() const
{
	return UGameplayEvent::StaticClass();
}

void FGameplayEventAsset::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
}

uint32 FGameplayEventAsset::GetCategories()
{
	return AssetCategory;
}
