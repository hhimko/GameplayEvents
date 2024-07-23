#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FGameplayEventsEditorApplication;

class FGameplayEventsTabFactory : public FWorkflowTabFactory
{
public:
	FGameplayEventsTabFactory(TSharedPtr<FGameplayEventsEditorApplication> Application);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

private:
	TWeakPtr<FGameplayEventsEditorApplication> WeakApplication;
};
