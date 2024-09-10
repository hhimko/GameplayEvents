#pragma once

#include "EdGraphUtilities.h"

struct FEventTreeNodePinsFactory : public FGraphPanelPinFactory
{
public:
	virtual ~FEventTreeNodePinsFactory() override { }
	virtual TSharedPtr<SGraphPin> CreatePin(UEdGraphPin* Pin) const override;

};