#include "EventTree/EventTreeSchemaActions.h"

#include "EventTree/EventTreeNodes.h"
#include "EdGraph/EdGraph.h"

FEventTreeSchemaAction_NewNode::FEventTreeSchemaAction_NewNode()
	: Super(NodeCategory, MenuDesc, ToolTip, 0)
{

}

UEdGraphNode* FEventTreeSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode)
{
	UEventTreeNode* TreeNode = UEventTreeNode::CreateNew(ParentGraph, Location);

	if (FromPin != nullptr) {
		TreeNode->GetSchema()->TryCreateConnection(FromPin, TreeNode->GetPinAt(0));
	}

	ParentGraph->Modify();
	ParentGraph->AddNode(TreeNode, true, bSelectNewNode);

	return TreeNode;
}
