#pragma once

#include "EdGraph/EdGraphNode.h"
#include "EventTreeNodes.generated.h"

UCLASS()
class UEventTreeNode : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UEventTreeNode();

	virtual void GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const override;

	UEdGraphPin* GetInputPin() const;
	TArray<UEdGraphPin*> GetOutputPins() const;

protected:
	template<typename T>
	static T* CreateNew(UEdGraph* ParentGraph, const FVector2D& Location)
	{
		T* TreeNode = NewObject<T>(ParentGraph);
		TreeNode->CreateNewGuid();

		TreeNode->NodePosX = Location.X;
		TreeNode->NodePosY = Location.Y;

		return TreeNode;
	}

private:
	FUIAction RemoveNodeAction;

};

UCLASS()
class UEventTreeNode_Start : public UEventTreeNode
{
	GENERATED_BODY()

public:
	UEventTreeNode_Start();

	static UEventTreeNode_Start* CreateNew(UEdGraph* ParentGraph, const FVector2D& Location);

};
