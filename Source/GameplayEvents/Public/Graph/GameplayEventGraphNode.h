#pragma once

#include "CoreMinimal.h"
#include "UObject/NameTypes.h"
#include "GameplayEventGraphNode.generated.h"

UCLASS()
class GAMEPLAYEVENTS_API UGameplayEventGraphNodePin : public UObject
{
	GENERATED_BODY()

public:
	UGameplayEventGraphNodePin();
	UGameplayEventGraphNodePin(const FName& Name, const FGuid& Guid);

	UPROPERTY(BlueprintReadOnly)
	FName Name;

	UPROPERTY(BlueprintReadOnly)
	FGuid Guid;

	UPROPERTY(BlueprintReadOnly)
	UGameplayEventGraphNodePin* Connection;

};

UCLASS()
class GAMEPLAYEVENTS_API UGameplayEventGraphNode : public UObject
{
	GENERATED_BODY()

public:
	UGameplayEventGraphNode();
	UGameplayEventGraphNode(const FVector2D& Position, UGameplayEventGraphNodePin* InputPin, UGameplayEventGraphNodePin* OutputPin);

	UPROPERTY(BlueprintReadOnly)
	FVector2D Position;

	UPROPERTY(BlueprintReadOnly)
	UGameplayEventGraphNodePin* InputPin;

	UPROPERTY(BlueprintReadOnly)
	UGameplayEventGraphNodePin* OutputPin;

};
