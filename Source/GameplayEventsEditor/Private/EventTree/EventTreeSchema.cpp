#include "EventTree/EventTreeSchema.h"

#include "EventTree/EventTreeSchemaActions.h"

void UEventTreeSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	TArray<TSharedPtr<FEdGraphSchemaAction>> NodeActions;
	NodeActions.Add(MakeShared<FEventTreeSchemaAction_NewNode>());
	
	ContextMenuBuilder.AddActionList(NodeActions, TEXT("GameplayEvents"));
}

void UEventTreeSchema::CreateDefaultNodesForGraph(UEdGraph& Graph) const
{
	Super::CreateDefaultNodesForGraph(Graph);
}

const FPinConnectionResponse UEventTreeSchema::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
	return Super::CanCreateConnection(A, B);
}
