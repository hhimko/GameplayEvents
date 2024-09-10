#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "EventTreeSchemaActions.generated.h"

USTRUCT()
struct FEventTreeSchemaAction_NewNode : public FEdGraphSchemaAction
{
	GENERATED_BODY()

public:
	static inline const FText NodeCategory = FText::FromString(TEXT("EventTree"));
	static inline const FText MenuDesc = FText::FromString(TEXT("New Tree Node"));
	static inline const FText ToolTip = FText::FromString(TEXT("Create a new EventTree node"));

	FEventTreeSchemaAction_NewNode();

	virtual UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;

};