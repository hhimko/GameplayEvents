#pragma once

#include "CoreMinimal.h"
#include "GameplayEventsFactory.generated.h"

UCLASS()
class UGameplayEventsFactory : public UFactory
{
	GENERATED_BODY()

public:
	UGameplayEventsFactory(const FObjectInitializer& ObjectInitializer);

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;

};
