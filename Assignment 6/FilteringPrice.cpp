#include "FilteringPrice.h"

FilteringPrice::FilteringPrice(unsigned int _price) :
	price{ _price }
{

}

DynamicArray<Offer> FilteringPrice::filter(DynamicArray<Offer>& data) {
	DynamicArray<Offer> filteredArr;
	for (int i = 0; i < data.get_length(); i++) {
		//cout << data.get(i).get_price() << " ";
		if (data.get(i).get_price() < this->price) {
			filteredArr.append(data.get(i));
		}
	}
	return filteredArr;
}

void FilteringPrice::set_price(unsigned int newPrice) {
	price = newPrice;
}

FilteringPrice::FilteringPrice() {
	price = 0;
}