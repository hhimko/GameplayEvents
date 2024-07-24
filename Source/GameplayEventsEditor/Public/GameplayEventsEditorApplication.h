#pragma once

#include "CoreMinimal.h"
#include "Misc/NotifyHook.h"
#include "EditorUndoClient.h"
#include "GameplayEvent.h"
#include "GameplayEventAsset.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"

class FGameplayEventsEditorApplication : public FWorkflowCentricApplication, public FEditorUndoClient, public FNotifyHook
{
public:
	static constexpr FName StaticName = TEXT("GameplayEventsEditorApplication");

	FGameplayEventsEditorApplication();
	virtual ~FGameplayEventsEditorApplication() override {  }

	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	void InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InToolkitHost, UObject* InObject);

	UGameplayEvent* GetAsset() const { return Asset;  }

	virtual FName GetToolkitFName() const override { return StaticName; }
	virtual FText GetBaseToolkitName() const override { return FText::FromName(StaticName); }
	virtual FString GetWorldCentricTabPrefix() const override { return StaticName.ToString(); }
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor(FColor::Magenta); }
	virtual FString GetDocumentationLink() const override { return TEXT("https://github.com/hhimko/GameplayEvents"); }
	virtual void OnToolkitHostingStarted(const TSharedRef<IToolkit>& Toolkit) override { }
	virtual void OnToolkitHostingFinished(const TSharedRef<IToolkit>& Toolkit) override { }

private:
	UGameplayEvent* Asset;

};
