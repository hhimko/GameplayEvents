#include "EventTree/EventTreeNodes.h"

UEventTreeNode::UEventTreeNode()
{
	RemoveNodeAction = FExecuteAction::CreateWeakLambda(this, [this]() { this->DestroyNode(); });
}

void UEventTreeNode::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
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
