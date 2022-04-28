#pragma once

#include "FilteringCriteria.h"

class FilteringType : public FilteringCriteria {
private:
	offer_type type;
public:
	FilteringType();
	FilteringType(offer_type);
	DynamicArray filter(DynamicArray& data);
	void set_type(offer_type);
};
