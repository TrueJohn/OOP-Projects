#include "FilteringPrice.h"

FilteringPrice::FilteringPrice(unsigned int _price) :
	price{ _price }
{

}

DynamicArray FilteringPrice::filter(DynamicArray& data) {
	DynamicArray filteredArr;
	for (int i = 0; i < data.getLength(); i++) {
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