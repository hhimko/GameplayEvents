#include "Graph/GEGraphSchemaActions.h"

#include "Graph/GEGraphNodes.h"

FGEGraphSchemaAction_NewNode::FGEGraphSchemaAction_NewNode()
	: Super(NodeCategory, MenuDesc, ToolTip, 0)
{

}

UEdGraphNode* FGEGraphSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode)
{
	UGEGraphNode* Node = NewObject<UGEGraphNode>(ParentGraph);

	Node->NodePosX = Location.X;
	Node->NodePosY = Location.Y;

	ParentGraph->Modify();
	ParentGraph->AddNode(Node, true, bSelectNewNode);

	return Node;
}
