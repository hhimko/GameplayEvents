#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FGameplayEventsEditorApplication;

class FGameplayEventsApplicationMode : public FApplicationMode
{
public:
	static inline const FName StaticName = TEXT("GameplayEventsApplicationMode");

	FGameplayEventsApplicationMode(const TSharedPtr<FGameplayEventsEditorApplication>& Application);

	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PreDeactivateMode() override;
	virtual void PostActivateMode() override;

private:
	TWeakPtr<FGameplayEventsEditorApplication> WeakApplication;
	FWorkflowAllowedTabSet AllowedTabSet;

};