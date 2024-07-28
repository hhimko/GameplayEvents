#include "Factories/TabFactories/EventGraphTabFactory.h"

#include "GameplayEventsEditorApplication.h"
#include "GraphEditor.h"

FEventGraphTabFactory::FEventGraphTabFactory(const TSharedPtr<FGameplayEventsEditorApplication>& Application)
	: FWorkflowTabFactory(StaticName, Application)
	, WeakApplication(Application)
{
	TabLabel = FText::FromString(TEXT("Event Graph"));
	ViewMenuDescription = FText::FromString(TEXT("Displays the gameplay event graph tab."));
	ViewMenuTooltip = FText::FromString(TEXT("Display the gameplay event graph tab."));
}

TSharedRef<SWidget> FEventGraphTabFactory::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	const TSharedPtr<FGameplayEventsEditorApplication> Application = WeakApplication.Pin();

	return SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		.HAlign(HAlign_Fill)
		[
			SNew(SGraphEditor)
			.IsEditable(true)
			.GraphToEdit(Application->GetEventGraph())
		];
}

FText FEventGraphTabFactory::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FText::FromString(TEXT("Gameplay event graph tab."));
}
