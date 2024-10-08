#include "ApplicationModes/GameplayEventsApplicationMode.h"

#include "GameplayEventsEditorApplication.h"
#include "Factories/TabFactories/EventTreeTabFactory.h"
#include "Factories/TabFactories/EventPropertiesTabFactory.h"
#include "Framework/Docking/TabManager.h"

FGameplayEventsApplicationMode::FGameplayEventsApplicationMode(const TSharedPtr<FGameplayEventsEditorApplication>& Application)
	: FApplicationMode(StaticName)
	, WeakApplication(Application)
{
	AllowedTabSet.RegisterFactory(MakeShareable(new FEventTreeTabFactory(Application)));
	AllowedTabSet.RegisterFactory(MakeShareable(new FEventPropertiesTabFactory(Application)));

	TabLayout = FTabManager::NewLayout(TEXT("GameplayEventsApplicationModeLayout"))
	->AddArea
	(
		FTabManager::NewPrimaryArea()
		->SetOrientation(Orient_Vertical)
		->Split
		(
			FTabManager::NewSplitter()
			->SetOrientation(Orient_Horizontal)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.8f)
				->AddTab(FEventTreeTabFactory::StaticName, ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.2f)
				->AddTab(FEventPropertiesTabFactory::StaticName, ETabState::OpenedTab)
			)
		)
	);
}

void FGameplayEventsApplicationMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	const TSharedPtr<FGameplayEventsEditorApplication> Application = WeakApplication.Pin();
	if (Application != nullptr)
	{
		Application->PushTabFactories(AllowedTabSet);
	}

	FApplicationMode::RegisterTabFactories(InTabManager);
}

void FGameplayEventsApplicationMode::PreDeactivateMode()
{
	FApplicationMode::PreDeactivateMode();
}

void FGameplayEventsApplicationMode::PostActivateMode()
{
	FApplicationMode::PostActivateMode();
}
