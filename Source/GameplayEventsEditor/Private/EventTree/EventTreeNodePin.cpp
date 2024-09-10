#include "EventTree/EventTreeNodePin.h"

void SEventTreeNodePin::Construct(const FArguments& InArgs, UEdGraphPin* InPin)
{
	return SGraphPin::Construct(SGraphPin::FArguments(), InPin);
}
