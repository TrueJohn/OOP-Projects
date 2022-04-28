#pragma once
#include "FilteringCriteria.h"

class FilteringPrice :public FilteringCriteria {
public:
	FilteringPrice();
	FilteringPrice(unsigned int);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);
	void set_price(unsigned int);
	inline unsigned int get_price() const { return this->price; };

private:
	unsigned int price;
};
