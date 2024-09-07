#include "GameplayEventsEditorApplication.h"

#include "ApplicationModes/GameplayEventsApplicationMode.h"
#include "Graph/GEGraphSchema.h"
#include "Kismet2/BlueprintEditorUtils.h"

FGameplayEventsEditorApplication::FGameplayEventsEditorApplication(UGameplayEvent* GameplayEvent)
	: Event(GameplayEvent)
{
	EventGraph = FBlueprintEditorUtils::CreateNewGraph(Event, NAME_None, UEdGraph::StaticClass(), UGEGraphSchema::StaticClass());
	RestoreEditorGraphFromRuntimeEvent();
}

void FGameplayEventsEditorApplication::InitAssetEditor(const TSharedPtr<IToolkitHost>& InToolkitHost)
{
	const EToolkitMode::Type Mode = InToolkitHost.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;
	FWorkflowCentricApplication::InitAssetEditor(Mode, InToolkitHost, StaticName, FTabManager::FLayout::NullLayout, true, true, Event);

	GraphChangedDelegateHandle = EventGraph->AddOnGraphChangedHandler(
		FOnGraphChanged::FDelegate::CreateSP(SharedThis(this), &FGameplayEventsEditorApplication::OnGraphChanged)
	);
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

void FGameplayEventsEditorApplication::OnClose()
{
	EventGraph->RemoveOnGraphChangedHandler(GraphChangedDelegateHandle);
	UpdateRuntimeEventFromEditorGraph();
	FWorkflowCentricApplication::OnClose();
}

void FGameplayEventsEditorApplication::OnGraphChanged(const FEdGraphEditAction& EditAction)
{
	UpdateRuntimeEventFromEditorGraph();
}

void FGameplayEventsEditorApplication::RestoreEditorGraphFromRuntimeEvent()
{

}

void FGameplayEventsEditorApplication::UpdateRuntimeEventFromEditorGraph()
{

}
