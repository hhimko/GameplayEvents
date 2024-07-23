#include "Factories/GameplayEventsTabFactory.h"
#include "GameplayEventsEditorApplication.h"

FGameplayEventsTabFactory::FGameplayEventsTabFactory(TSharedPtr<FGameplayEventsEditorApplication> Application)
	: FWorkflowTabFactory(FName("GameplayEventsTab"), Application)
	, WeakApplication(Application)
{
	TabLabel = FText::FromString(TEXT("GameplayEventsTab"));
	ViewMenuDescription = FText::FromString(TEXT("Displays the primary GameplayEvents editor tab."));
	ViewMenuTooltip = FText::FromString(TEXT("Display the primary GameplayEvents editor tab."));
}

TSharedRef<SWidget> FGameplayEventsTabFactory::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(STextBlock).Text(FText::FromString(TEXT("Hello, World!")));
}

FText FGameplayEventsTabFactory::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FText::FromString(TEXT("GameplayEvents editor tab."));
}
