#include "Factories/TabFactories/EventGraphTabFactory.h"

#include "GameplayEventsEditorApplication.h"

FEventGraphTabFactory::FEventGraphTabFactory(const TSharedPtr<FGameplayEventsEditorApplication>& Application)
	: FWorkflowTabFactory(StaticName, Application)
	, WeakApplication(Application)
{
	TabLabel = FText::FromName(StaticName);
	ViewMenuDescription = FText::FromString(TEXT("Displays the primary GameplayEvents editor tab."));
	ViewMenuTooltip = FText::FromString(TEXT("Display the primary GameplayEvents editor tab."));
}

TSharedRef<SWidget> FEventGraphTabFactory::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(STextBlock).Text(FText::FromString(TEXT("Hello, World!")));
}

FText FEventGraphTabFactory::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FText::FromString(TEXT("GameplayEvents editor tab."));
}
