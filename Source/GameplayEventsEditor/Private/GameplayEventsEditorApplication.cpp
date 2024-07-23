#include "GameplayEventsEditorApplication.h"

#include "ApplicationModes/GameplayEventsApplicationMode.h"

void FGameplayEventsEditorApplication::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FWorkflowCentricApplication::RegisterTabSpawners(InTabManager);
}

void FGameplayEventsEditorApplication::InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InToolkitHost, UObject* InObject)
{
	TArray<UObject*> ObjectsToEdit;
	ObjectsToEdit.Add(InObject);
	InitAssetEditor(Mode, InToolkitHost, StaticName, FTabManager::FLayout::NullLayout, true, true, ObjectsToEdit);

	// Register application modes
	const TSharedRef<FGameplayEventsApplicationMode> ApplicationMode = MakeShareable(new FGameplayEventsApplicationMode(SharedThis(this)));
	AddApplicationMode(FGameplayEventsApplicationMode::StaticName, ApplicationMode);

	SetCurrentMode(FGameplayEventsApplicationMode::StaticName);
}
