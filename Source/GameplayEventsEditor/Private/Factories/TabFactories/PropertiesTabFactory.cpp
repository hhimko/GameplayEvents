#include "Factories/TabFactories/PropertiesTabFactory.h"

#include "GameplayEventsEditorApplication.h"

FPropertiesTabFactory::FPropertiesTabFactory(const TSharedPtr<FGameplayEventsEditorApplication>& Application)
	: FWorkflowTabFactory(StaticName, Application)
	, WeakApplication(Application)
{
	TabLabel = FText::FromName(StaticName);
	ViewMenuDescription = FText::FromString(TEXT("Gameplay event properties editor tab."));
	ViewMenuTooltip = FText::FromString(TEXT("Display gameplay event properties editor tab."));
}

TSharedRef<SWidget> FPropertiesTabFactory::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	const TSharedPtr<FGameplayEventsEditorApplication> Application = WeakApplication.Pin();
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));

	FDetailsViewArgs Args;
	Args.bSearchInitialKeyFocus = true;

	const TSharedPtr<IDetailsView> DetailsView = PropertyEditorModule.CreateDetailView(Args);
	DetailsView->SetObject(Application->GetAsset());

	return SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.FillHeight(1.f)
		.HAlign(HAlign_Fill)
		[
			DetailsView.ToSharedRef()
		];
}

FText FPropertiesTabFactory::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FText::FromString(TEXT("GameplayEvents editor tab."));
}
