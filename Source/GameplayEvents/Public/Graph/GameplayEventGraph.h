#pragma once

#include "CoreMinimal.h"
#include "UObject/NameTypes.h"
#include "GameplayEventGraphNode.h"
#include "GameplayEventGraph.generated.h"

UCLASS()
class GAMEPLAYEVENTS_API UGameplayEventGraph : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<UGameplayEventGraphNode*> Nodes;

};
