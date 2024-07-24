#include "ApplicationModes/GameplayEventsApplicationMode.h"

#include "GameplayEventsEditorApplication.h"
#include "Factories/TabFactories/EventGraphTabFactory.h"
#include "Factories/TabFactories/PropertiesTabFactory.h"
#include "Framework/Docking/TabManager.h"

FGameplayEventsApplicationMode::FGameplayEventsApplicationMode(const TSharedPtr<FGameplayEventsEditorApplication>& Application)
	: FApplicationMode(StaticName)
	, WeakApplication(Application)
{
	AllowedTabSet.RegisterFactory(MakeShareable(new FPropertiesTabFactory(Application)));

	TabLayout = FTabManager::NewLayout(TEXT("GameplayEventsApplicationModeLayout"))
	->AddArea
	(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
		->Split
		(
			FTabManager::NewStack()->AddTab(FPropertiesTabFactory::StaticName, ETabState::OpenedTab)
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
