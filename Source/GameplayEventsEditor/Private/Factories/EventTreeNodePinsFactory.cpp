#include "Factories/EventTreeNodePinsFactory.h"

#include "EventTree/EventTreeNodePin.h"

TSharedPtr<SGraphPin> FEventTreeNodePinsFactory::CreatePin(UEdGraphPin* Pin) const
{
	if (Pin->PinType.PinSubCategory == SEventTreeNodePin::PinSubCategoryName) {
		return SNew(SEventTreeNodePin, Pin);
	}

	return nullptr;
}
