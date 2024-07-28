#include "GameplayEventsEditorApplication.h"

#include "ApplicationModes/GameplayEventsApplicationMode.h"
#include "Kismet2/BlueprintEditorUtils.h"

FGameplayEventsEditorApplication::FGameplayEventsEditorApplication(UGameplayEvent* GameplayEvent)
	: WorkingEvent(GameplayEvent)
{
	EventGraph = FBlueprintEditorUtils::CreateNewGraph(WorkingEvent, NAME_None, UEdGraph::StaticClass(), UEdGraphSchema::StaticClass());
}

void FGameplayEventsEditorApplication::InitAssetEditor(const TSharedPtr<IToolkitHost>& InToolkitHost)
{
	const EToolkitMode::Type Mode = InToolkitHost.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;
	FWorkflowCentricApplication::InitAssetEditor(Mode, InToolkitHost, StaticName, FTabManager::FLayout::NullLayout, true, true, WorkingEvent);
}

void FGameplayEventsEditorApplication::PostInitAssetEditor()
{
	// Register application modes
	const TSharedRef<FGameplayEventsApplicationMode> ApplicationMode = MakeShareable(new FGameplayEventsApplicationMode(SharedThis(this)));
	AddApplicationMode(FGameplayEventsApplicationMode::StaticName, ApplicationMode);

	SetCurrentMode(FGameplayEventsApplicationMode::StaticName);
}

void FGameplayEventsEditorApplication::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FWorkflowCentricApplication::RegisterTabSpawners(InTabManager);
}
