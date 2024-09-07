#include "Graph/GEGraphNodes.h"

UGEGraphNode::UGEGraphNode()
{
	RemoveNodeAction = FExecuteAction::CreateWeakLambda(this, [this]() { this->DestroyNode(); });
}

void UGEGraphNode::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	FToolMenuSection& DefaultSection = Menu->FindOrAddSection(NAME_None);

	DefaultSection.AddMenuEntry(
		TEXT("RemoveNodeEntry"), 
		FText::FromString(TEXT("Remove Node")),
		FText::FromString(TEXT("Remove the node from graph")),
		FSlateIcon(),
		RemoveNodeAction
	);
}
