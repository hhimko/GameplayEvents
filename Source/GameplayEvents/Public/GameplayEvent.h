#pragma once

#include "CoreMinimal.h"
#include "Graph/GameplayEventGraph.h"
#include "GameplayEvent.generated.h"

UCLASS(BlueprintType)
class GAMEPLAYEVENTS_API UGameplayEvent : public UObject
{
	GENERATED_BODY()

public:
	UGameplayEvent();

	UPROPERTY()
	UGameplayEventGraph* Graph;
};
