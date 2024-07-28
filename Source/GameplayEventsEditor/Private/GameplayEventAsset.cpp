#include "GameplayEventAsset.h"

#include "GameplayEvent.h"
#include "GameplayEventsEditorApplication.h"

FGameplayEventAsset::FGameplayEventAsset(EAssetTypeCategories::Type Category)
	: AssetCategory(Category)
{

}

FText FGameplayEventAsset::GetName() const
{
	return FText::FromName(StaticName);
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
	for (UObject* Object : InObjects)
	{
		UGameplayEvent* GameplayEvent = Cast<UGameplayEvent>(Object);
		if (GameplayEvent != nullptr)
		{
			FGameplayEventsEditorApplication* App = new FGameplayEventsEditorApplication(GameplayEvent);
			const TSharedRef<FGameplayEventsEditorApplication> Application(App);
			Application->InitAssetEditor(EditWithinLevelEditor);
		}
	}
}

uint32 FGameplayEventAsset::GetCategories()
{
	return AssetCategory;
}
