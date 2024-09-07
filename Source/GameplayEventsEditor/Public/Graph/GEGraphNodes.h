#pragma once

#include "EdGraph/EdGraphNode.h"
#include "GEGraphNodes.generated.h"

UCLASS()
class UGEGraphNode : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UGEGraphNode();

	virtual void GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const override;

private:
	FUIAction RemoveNodeAction;

};
