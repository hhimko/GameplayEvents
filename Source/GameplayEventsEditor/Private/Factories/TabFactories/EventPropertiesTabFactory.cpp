#include "Factories/TabFactories/EventPropertiesTabFactory.h"

#include "GameplayEventsEditorApplication.h"

FEventPropertiesTabFactory::FEventPropertiesTabFactory(const TSharedPtr<FGameplayEventsEditorApplication>& Application)
	: FWorkflowTabFactory(StaticName, Application)
	, WeakApplication(Application)
{
	TabLabel = FText::FromString(TEXT("Event Properties"));
	ViewMenuDescription = FText::FromString(TEXT("Gameplay event properties editor tab."));
	ViewMenuTooltip = FText::FromString(TEXT("Display gameplay event properties editor tab."));
}

TSharedRef<SWidget> FEventPropertiesTabFactory::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	const TSharedPtr<FGameplayEventsEditorApplication> Application = WeakApplication.Pin();
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));

	FDetailsViewArgs Args;
	Args.bSearchInitialKeyFocus = true;

	const TSharedPtr<IDetailsView> DetailsView = PropertyEditorModule.CreateDetailView(Args);
	DetailsView->SetObject(Application->GetEvent());

	return SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.FillHeight(1.f)
		.HAlign(HAlign_Fill)
		[
			DetailsView.ToSharedRef()
		];
}

FText FEventPropertiesTabFactory::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FText::FromString(TEXT("GameplayEvents properties tab."));
}
