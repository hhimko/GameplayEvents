#include "EventTree/EventTreeSchemaActions.h"

#include "EventTree/EventTreeNodes.h"

FEventTreeSchemaAction_NewNode::FEventTreeSchemaAction_NewNode()
	: Super(NodeCategory, MenuDesc, ToolTip, 0)
{

}

UEdGraphNode* FEventTreeSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode)
{
	UEventTreeNode* TreeNode = NewObject<UEventTreeNode>(ParentGraph);

	TreeNode->NodePosX = Location.X;
	TreeNode->NodePosY = Location.Y;

	ParentGraph->Modify();
	ParentGraph->AddNode(TreeNode, true, bSelectNewNode);

	return TreeNode;
}
