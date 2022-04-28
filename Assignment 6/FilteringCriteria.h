#pragma once
#include "DynamicArray.h"
// you can add all your filtering classes in this module
class FilteringCriteria
{

public:
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);
};

