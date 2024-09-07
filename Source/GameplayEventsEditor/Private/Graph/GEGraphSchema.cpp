#include "Graph/GEGraphSchema.h"

#include "Graph/GEGraphSchemaActions.h"

void UGEGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	TArray<TSharedPtr<FEdGraphSchemaAction>> NodeActions;
	NodeActions.Add(MakeShared<FGEGraphSchemaAction_NewNode>());
	
	ContextMenuBuilder.AddActionList(NodeActions, TEXT("GameplayEvents"));
}

void UGEGraphSchema::CreateDefaultNodesForGraph(UEdGraph& Graph) const
{
	Super::CreateDefaultNodesForGraph(Graph);
}

const FPinConnectionResponse UGEGraphSchema::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
	return Super::CanCreateConnection(A, B);
}
