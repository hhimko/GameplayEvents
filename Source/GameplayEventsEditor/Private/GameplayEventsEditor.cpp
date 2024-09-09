#include "GameplayEventsEditor.h"

#include "GameplayEventAsset.h"
#include "IAssetTools.h"

#define LOCTEXT_NAMESPACE "FGameplayEventsEditorModule"

void FGameplayEventsEditorModule::StartupModule()
{
	// Register the GameplayEvent custom category and asset
	IAssetTools& AssetTools = IAssetTools::Get();
	const EAssetTypeCategories::Type AssetType = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("GameplayEvents")), FText::FromString("Gameplay Events"));

	const TSharedPtr<FGameplayEventAsset> CustomAsset = MakeShared<FGameplayEventAsset>(AssetType);
	AssetTools.RegisterAssetTypeActions(CustomAsset.ToSharedRef());
}

void FGameplayEventsEditorModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGameplayEventsEditorModule, GameplayEventsEditor)
