#pragma once

#include "DynamicArray.h"
#include "Offer.h"
#include "FilteringPrice.h"
#include "FilteringType.h"
#include "FilteringCriteriaTypeAndPrice.h"
#include <cassert>

class FilteringTest
{
public:
	static void runAllTests();
private:
	static DynamicArray<Offer> arr;
	static Offer o1, o2, o3, o4, o5;
	static void testFilteringPrice();
	static void testFilteringType();
	static void testFilteringPriceAndType();
	static void testfilter();
};
