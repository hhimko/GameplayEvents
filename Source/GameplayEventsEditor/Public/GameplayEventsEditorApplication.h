#pragma once

#include "CoreMinimal.h"
#include "Misc/NotifyHook.h"
#include "EditorUndoClient.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"

class FGameplayEventsEditorApplication : public FWorkflowCentricApplication, public FEditorUndoClient, public FNotifyHook
{
public:
	virtual ~FGameplayEventsEditorApplication() override {  }

	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	void InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InToolkitHost, UObject* InObject);

	virtual FName GetToolkitFName() const override { return FName(TEXT("GameplayEventsEditorApplication")); }
	virtual FText GetBaseToolkitName() const override { return FText::FromString(TEXT("GameplayEventsEditorApplication")); }
	virtual FString GetWorldCentricTabPrefix() const override { return TEXT("GameplayEventsEditorApplication"); }
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor(FColor::Magenta); }
	virtual FString GetDocumentationLink() const override { return TEXT("https://github.com/hhimko/GameplayEvents"); }
	virtual void OnToolkitHostingStarted(const TSharedRef<IToolkit>& Toolkit) override { }
	virtual void OnToolkitHostingFinished(const TSharedRef<IToolkit>& Toolkit) override { }

};
