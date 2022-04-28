#include "OfferTest.h"
#include "FilteringTest.h"
#include "DynamicArrayTest.h"
#include "FilteringPrice.h"
#include "FilteringType.h"

#include <iostream>
using namespace std;

#include "DynamicArray.h"

int main() {

	OfferTest::runAllTests();
	FilteringTest::runAllTests();
	DynamicArrayTest::runAllTests();

	return 0;
}