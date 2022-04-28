#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "DynamicArray.h"
#include "Offer.h"
#include "FilteringPrice.h"
#include "FilteringType.h"
#include "FilteringCriteriaTypeAndPrice.h"

using std::string;
using std::vector;
using std::find;

class Menu {
public:
	Menu();
	void start() const;
	void display_menu() const;
	void display_offers(DynamicArray&) const;
	int get_task() const;
	unsigned int get_price() const;
	offer_type get_type() const;
	Offer get_offer() const;

private:
	string menu;
	vector<char> validInputs;
};
