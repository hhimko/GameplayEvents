#include "GameplayEventAsset.h"

#include "GameplayEvent.h"
#include "GameplayEventsEditorApplication.h"

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
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (UObject* Object : InObjects)
	{
		UGameplayEvent* GameplayEvent = Cast<UGameplayEvent>(Object);
		if (GameplayEvent != nullptr)
		{
			TSharedRef<FGameplayEventsEditorApplication> Application(new FGameplayEventsEditorApplication());
			Application->InitEditor(Mode, EditWithinLevelEditor, GameplayEvent);
		}
	}
}

uint32 FGameplayEventAsset::GetCategories()
{
	return AssetCategory;
}
