#pragma once

#include "CoreMinimal.h"
#include "UObject/NameTypes.h"
#include "GameplayEventTreeNode.generated.h"

UCLASS()
class GAMEPLAYEVENTS_API UGameplayEventTreeNodePin : public UObject
{
	GENERATED_BODY()

public:
	UGameplayEventTreeNodePin();
	UGameplayEventTreeNodePin(const FName& Name, const FGuid& Guid);

	UPROPERTY(BlueprintReadOnly)
	FName Name;

	UPROPERTY(BlueprintReadOnly)
	FGuid Guid;

	UPROPERTY(BlueprintReadOnly)
	UGameplayEventTreeNodePin* Connection;

};

UCLASS()
class GAMEPLAYEVENTS_API UGameplayEventTreeNode : public UObject
{
	GENERATED_BODY()

public:
	UGameplayEventTreeNode();
	UGameplayEventTreeNode(const FVector2D& Position, UGameplayEventTreeNodePin* InputPin, UGameplayEventTreeNodePin* OutputPin);

	UPROPERTY(BlueprintReadOnly)
	FVector2D Position;

	UPROPERTY(BlueprintReadOnly)
	UGameplayEventTreeNodePin* InputPin;

	UPROPERTY(BlueprintReadOnly)
	UGameplayEventTreeNodePin* OutputPin;

};
