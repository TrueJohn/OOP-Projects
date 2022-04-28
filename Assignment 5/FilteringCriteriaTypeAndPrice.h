#pragma once

#include "FilteringPrice.h"
#include "FilteringType.h"

class FilteringCriteriaTypeAndPrice : public FilteringCriteria {
private:
	FilteringPrice byPrice;
	FilteringType byType;
public:
	FilteringCriteriaTypeAndPrice(unsigned int, offer_type);
	DynamicArray filter(DynamicArray& data);
};
