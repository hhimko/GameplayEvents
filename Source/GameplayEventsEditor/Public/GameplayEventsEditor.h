#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

struct FEventTreeNodePinsFactory;

class FGameplayEventsEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedPtr<FEventTreeNodePinsFactory> PinFactory;

};
