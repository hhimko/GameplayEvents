#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"
#include "Misc/NotifyHook.h"
#include "EditorUndoClient.h"
#include "GameplayEvent.h"

class FGameplayEventsEditorApplication : public FWorkflowCentricApplication, public FEditorUndoClient, public FNotifyHook
{
public:
	static inline const FName StaticName = TEXT("GameplayEventsEditorApplication");

	explicit FGameplayEventsEditorApplication(UGameplayEvent* GameplayEvent);
	virtual ~FGameplayEventsEditorApplication() override { }

	UGameplayEvent* GetEvent() const { return Event; }
	UEdGraph* GetEventGraph() const { return EventGraph; }

	void InitAssetEditor(const TSharedPtr<IToolkitHost>& InToolkitHost);

protected:
	virtual void PostInitAssetEditor() override;
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void OnToolkitHostingStarted(const TSharedRef<IToolkit>& Toolkit) override { }
	virtual void OnToolkitHostingFinished(const TSharedRef<IToolkit>& Toolkit) override { }

	virtual FName GetToolkitFName() const override { return StaticName; }
	virtual FText GetBaseToolkitName() const override { return FText::FromName(StaticName); }
	virtual FString GetWorldCentricTabPrefix() const override { return StaticName.ToString(); }
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor(FColor::Magenta); }
	virtual FString GetDocumentationLink() const override { return TEXT("https://github.com/hhimko/GameplayEvents"); }

	virtual void OnClose() override;

private:
	void OnGraphChanged(const FEdGraphEditAction& EditAction);

	void RestoreEditorGraphFromRuntimeEvent();
	void UpdateRuntimeEventFromEditorGraph();

	UGameplayEvent* Event;
	UEdGraph* EventGraph;

	FDelegateHandle GraphChangedDelegateHandle;

};
