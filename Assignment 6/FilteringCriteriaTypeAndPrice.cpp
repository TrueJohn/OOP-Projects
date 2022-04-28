#include "FilteringCriteriaTypeAndPrice.h"


FilteringCriteriaTypeAndPrice::FilteringCriteriaTypeAndPrice(unsigned int price, offer_type type)
{
	byPrice.set_price(price);
	byType.set_type(type);
}

DynamicArray<Offer> FilteringCriteriaTypeAndPrice::filter(DynamicArray<Offer>& data) {
	DynamicArray<Offer> filteredArr;
	filteredArr = byPrice.filter(data);
	filteredArr = byType.filter(filteredArr);
	return filteredArr;
}