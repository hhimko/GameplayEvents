#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraph.h"
#include "EventTreeSchema.generated.h"

UCLASS()
class UEventTreeSchema : public UEdGraphSchema
{
	GENERATED_BODY()

public:
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
	virtual void CreateDefaultNodesForGraph(UEdGraph& Graph) const override;
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;

};
