#pragma once

#include "CoreMinimal.h"
#include "UObject/NameTypes.h"
#include "GameplayEventGraphNode.generated.h"

UCLASS()
class GAMEPLAYEVENTS_API UGameplayEventGraphNodePin : public UObject
{
	GENERATED_BODY()

public:
	UGameplayEventGraphNodePin(const FName& Name, const FGuid& Guid);

	UPROPERTY()
	FName Name;

	UPROPERTY()
	FGuid Guid;

	UPROPERTY()
	UGameplayEventGraphNodePin* Connection;

};

UCLASS()
class GAMEPLAYEVENTS_API UGameplayEventGraphNode : public UObject
{
	GENERATED_BODY()

public:
	UGameplayEventGraphNode(const FVector2D& Position, UGameplayEventGraphNodePin* InputPin, UGameplayEventGraphNodePin* OutputPin);

	UPROPERTY()
	FVector2D Position;

	UPROPERTY()
	UGameplayEventGraphNodePin* InputPin;

	UPROPERTY()
	UGameplayEventGraphNodePin* OutputPin;

};
