#include "Factories/GameplayEventsFactory.h"

#include "GameplayEvent.h"

UGameplayEventsFactory::UGameplayEventsFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UGameplayEvent::StaticClass();
}

UObject* UGameplayEventsFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UGameplayEvent* Asset = NewObject<UGameplayEvent>(InParent, InName, Flags);
	return Asset;
}

bool UGameplayEventsFactory::CanCreateNew() const
{
	return true;
}
