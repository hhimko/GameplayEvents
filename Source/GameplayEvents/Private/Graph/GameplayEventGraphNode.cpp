#include "Graph/GameplayEventGraphNode.h"

UGameplayEventGraphNodePin::UGameplayEventGraphNodePin()
	: Name(NAME_None)
	, Guid({})
	, Connection(nullptr)
{

}

UGameplayEventGraphNode::UGameplayEventGraphNode()
	: Position(FVector2D::ZeroVector)
	, InputPin(nullptr)
	, OutputPin(nullptr)
{

}

UGameplayEventGraphNodePin::UGameplayEventGraphNodePin(const FName& Name, const FGuid& Guid)
	: Name(Name)
	, Guid(Guid)
	, Connection(nullptr)
{

}

UGameplayEventGraphNode::UGameplayEventGraphNode(const FVector2D& Position, UGameplayEventGraphNodePin* InputPin, UGameplayEventGraphNodePin* OutputPin)
	: Position(Position)
	, InputPin(InputPin)
	, OutputPin(OutputPin)
{

}
