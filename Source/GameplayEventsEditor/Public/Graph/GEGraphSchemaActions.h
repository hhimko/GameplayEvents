#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraph.h"
#include "GEGraphSchemaActions.generated.h"

USTRUCT()
struct FGEGraphSchemaAction_NewNode : public FEdGraphSchemaAction
{
	GENERATED_BODY()

public:
	static inline const FText NodeCategory = FText::FromString(TEXT("Nodes"));
	static inline const FText MenuDesc = FText::FromString(TEXT("New Event Node"));
	static inline const FText ToolTip = FText::FromString(TEXT("Create a new gameplay event node"));

	FGEGraphSchemaAction_NewNode();

	virtual UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;

};