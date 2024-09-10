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

UEdGraphPin* UEventTreeNode::GetInputPin() const
{
	for (UEdGraphPin* Pin : Pins)
	{
		const FEdGraphPinType T = Pin->PinType;
		if (Pin->Direction == EGPD_Input && T.PinCategory == UEdGraphSchema_K2::PC_Exec && T.PinSubCategory == UEdGraphSchema_K2::PN_Execute) {
			return Pin;
		}
	}

	return nullptr;
}

TArray<UEdGraphPin*> UEventTreeNode::GetOutputPins() const
{
	TArray<UEdGraphPin*> OutputPins;

	for (UEdGraphPin* Pin : Pins)
	{
		const FEdGraphPinType T = Pin->PinType;
		if (Pin->Direction == EGPD_Output && T.PinCategory == UEdGraphSchema_K2::PC_Exec && T.PinSubCategory == UEdGraphSchema_K2::PN_Then) {
			OutputPins.Add(Pin);
		}
	}

	return OutputPins;
}

UEventTreeNode_Start::UEventTreeNode_Start()
{

}

UEventTreeNode_Start* UEventTreeNode_Start::CreateNew(UEdGraph* ParentGraph, const FVector2D& Location)
{
	UEventTreeNode_Start* TreeNode = CreateNew<UEventTreeNode_Start>(ParentGraph, Location);

	TreeNode->CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Then);

	return TreeNode;
}
