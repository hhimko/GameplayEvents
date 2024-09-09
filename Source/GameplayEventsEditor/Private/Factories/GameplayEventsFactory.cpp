#include "Factories/GameplayEventsFactory.h"

#include "GameplayEvent.h"

UGameplayEventsFactory::UGameplayEventsFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UGameplayEvent::StaticClass();
}

UObject* UGameplayEventsFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UGameplayEvent* GameplayEvent = NewObject<UGameplayEvent>(InParent, InName, Flags);
	return GameplayEvent;
}

bool UGameplayEventsFactory::CanCreateNew() const
{
	return true;
}
