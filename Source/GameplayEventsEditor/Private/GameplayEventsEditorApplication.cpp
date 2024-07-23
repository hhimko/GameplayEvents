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
	InitAssetEditor(Mode, InToolkitHost, TEXT("GameplayEventsEditor"), FTabManager::FLayout::NullLayout, true, true, ObjectsToEdit);

	const TSharedRef<FGameplayEventsApplicationMode> ApplicationMode = MakeShareable(new FGameplayEventsApplicationMode(SharedThis(this)));
	AddApplicationMode(TEXT("GameplayEventsApplicationMode"), ApplicationMode);

	SetCurrentMode(TEXT("GameplayEventsApplicationMode"));
}
