#include "EventTree/GameplayEventTreeNode.h"

UGameplayEventTreeNodePin::UGameplayEventTreeNodePin()
	: Name(NAME_None)
	, Guid({})
	, Connection(nullptr)
{

}

UGameplayEventTreeNode::UGameplayEventTreeNode()
	: Position(FVector2D::ZeroVector)
	, InputPin(nullptr)
	, OutputPin(nullptr)
{

}

UGameplayEventTreeNodePin::UGameplayEventTreeNodePin(const FName& Name, const FGuid& Guid)
	: Name(Name)
	, Guid(Guid)
	, Connection(nullptr)
{

}

UGameplayEventTreeNode::UGameplayEventTreeNode(const FVector2D& Position, UGameplayEventTreeNodePin* InputPin, UGameplayEventTreeNodePin* OutputPin)
	: Position(Position)
	, InputPin(InputPin)
	, OutputPin(OutputPin)
{

}
