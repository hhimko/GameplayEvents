#include "Factories/TabFactories/EventTreeTabFactory.h"

#include "GameplayEventsEditorApplication.h"
#include "GraphEditor.h"

FEventTreeTabFactory::FEventTreeTabFactory(const TSharedPtr<FGameplayEventsEditorApplication>& Application)
	: FWorkflowTabFactory(StaticName, Application)
	, WeakApplication(Application)
{
	TabLabel = FText::FromString(TEXT("EventTree"));
	ViewMenuDescription = FText::FromString(TEXT("Displays the gameplay event tree tab."));
	ViewMenuTooltip = FText::FromString(TEXT("Display the gameplay event tree tab."));
}

TSharedRef<SWidget> FEventTreeTabFactory::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
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

FText FEventTreeTabFactory::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FText::FromString(TEXT("GameplayEvents event tree tab."));
}
