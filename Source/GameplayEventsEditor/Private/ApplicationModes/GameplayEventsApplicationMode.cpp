#include "ApplicationModes/GameplayEventsApplicationMode.h"

#include "GameplayEventsEditorApplication.h"
#include "Factories/GameplayEventsTabFactory.h"
#include "Framework/Docking/TabManager.h"

FGameplayEventsApplicationMode::FGameplayEventsApplicationMode(const TSharedPtr<FGameplayEventsEditorApplication>& Application)
	: FApplicationMode(StaticName)
	, WeakApplication(Application)
{
	AllowedTabSet.RegisterFactory(MakeShareable(new FGameplayEventsTabFactory(Application)));

	TabLayout = FTabManager::NewLayout(TEXT("GameplayEventsApplicationModeLayout"))->AddArea
	(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)->Split
		(
			FTabManager::NewStack()->AddTab(FGameplayEventsTabFactory::StaticName, ETabState::OpenedTab)
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
