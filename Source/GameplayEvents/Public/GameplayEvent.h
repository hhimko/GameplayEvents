#pragma once

#include "CoreMinimal.h"
#include "EventTree/GameplayEventTree.h"
#include "GameplayEvent.generated.h"

UCLASS(BlueprintType)
class GAMEPLAYEVENTS_API UGameplayEvent : public UObject
{
	GENERATED_BODY()

public:
	UGameplayEvent();

	UPROPERTY()
	UGameplayEventTree* EventTree;
};
