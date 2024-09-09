#pragma once

#include "CoreMinimal.h"
#include "UObject/NameTypes.h"
#include "GameplayEventTreeNode.h"
#include "GameplayEventTree.generated.h"

UCLASS()
class GAMEPLAYEVENTS_API UGameplayEventTree : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<UGameplayEventTreeNode*> Nodes;

};
