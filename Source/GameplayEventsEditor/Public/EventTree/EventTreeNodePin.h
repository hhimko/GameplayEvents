#pragma once

#include "KismetPins/SGraphPinColor.h"

class SEventTreeNodePin : public SGraphPin
{
public:
	SLATE_BEGIN_ARGS(SEventTreeNodePin) {}
	SLATE_END_ARGS()

	static inline const FName PinSubCategoryName = TEXT("EventTreeNodePin");

	void Construct(const FArguments& InArgs, UEdGraphPin* InPin);

};
