#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FGameplayEventsEditorApplication;

class FEventPropertiesTabFactory : public FWorkflowTabFactory
{
public:
	static inline const FName StaticName = TEXT("EventPropertiesTab");

	FEventPropertiesTabFactory(const TSharedPtr<FGameplayEventsEditorApplication>& Application);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

private:
	TWeakPtr<FGameplayEventsEditorApplication> WeakApplication;

};
