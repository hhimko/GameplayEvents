#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FGameplayEventsEditorApplication;

class FEventGraphTabFactory : public FWorkflowTabFactory
{
public:
	static constexpr FName StaticName = TEXT("EventGraphTab");

	FEventGraphTabFactory(const TSharedPtr<FGameplayEventsEditorApplication>& Application);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

private:
	TWeakPtr<FGameplayEventsEditorApplication> WeakApplication;

};
