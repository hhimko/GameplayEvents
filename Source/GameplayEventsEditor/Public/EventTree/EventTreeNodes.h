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

private:
	FUIAction RemoveNodeAction;

};
