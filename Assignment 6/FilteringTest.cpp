#include "FilteringTest.h"
#include <iostream>
void FilteringTest::runAllTests()
{
	// TODO your code here
	std::cout << "\033[1;33mSTARTING FILTERING TESTS........\033[0m\n";
	testFilteringPrice();
	testFilteringType();
	testFilteringPriceAndType();
	testfilter();
	std::cout << "\033[1;32mFiltering tests passed\033[0m\n";
}

DynamicArray<Offer> FilteringTest::arr;

Offer FilteringTest::o1("1", "Cluj", "Craiova", 155, create_date(1, 5, 2022), create_date(1, 6, 2022), all_inclusive);
Offer FilteringTest::o2("2", "Cluj", "Bucharest", 174, create_date(1, 5, 2022), create_date(1, 6, 2022), circuit);
Offer FilteringTest::o3("3", "Cluj", "Brasov", 325, create_date(1, 5, 2022), create_date(1, 6, 2022), circuit);
Offer FilteringTest::o4("4", "Cluj", "Arad", 412, create_date(1, 5, 2022), create_date(1, 6, 2022), city_break);
Offer FilteringTest::o5("5", "Cluj", "Timisoara", 451, create_date(1, 5, 2022), create_date(1, 6, 2022), all_inclusive);


void FilteringTest::testFilteringPrice() {
	arr.append(o1);
	arr.append(o2);
	arr.append(o3);
	arr.append(o4);
	arr.append(o5);

	FilteringPrice p1(201);
	DynamicArray<Offer> filteredArr = p1.filter(arr);
	assert(filteredArr.get_length() == 2);
	assert(filteredArr.get(0) == o1);
	assert(filteredArr.get(1) == o2);

	p1.set_price(99);
	filteredArr = p1.filter(arr);
	assert(filteredArr.get_length() == 0);

	p1.set_price(1101);
	filteredArr = p1.filter(arr);
	assert(filteredArr.get_length() == arr.get_length());
	for (int i = 0; i < filteredArr.get_length(); i++) assert(filteredArr.get(i) == arr.get(i));

}

void FilteringTest::testFilteringType() {
	FilteringType t(circuit);
	DynamicArray<Offer> filteredArr = t.filter(arr);

	assert(filteredArr.get_length() == 2);
	assert(filteredArr.get(0) == o2);
	assert(filteredArr.get(1) == o3);

	t.set_type(city_break);
	filteredArr = t.filter(arr);

	assert(filteredArr.get_length() == 1);
	assert(filteredArr.get(0) == o4);

	t.set_type(cruise);
	filteredArr = t.filter(arr);
	assert(filteredArr.get_length() == 0);
}


void FilteringTest::testFilteringPriceAndType() {
	FilteringCriteriaTypeAndPrice tp1(203, all_inclusive);
	DynamicArray<Offer> filteredArr = tp1.filter(arr);
	assert(filteredArr.get_length() == 1);
	assert(filteredArr.get(0) == o1);

	FilteringCriteriaTypeAndPrice tp2(203, cruise);
	filteredArr = tp2.filter(arr);
	assert(filteredArr.get_length() == 0);

	FilteringCriteriaTypeAndPrice tp3(451, all_inclusive);
	filteredArr = tp3.filter(arr);
	assert(filteredArr.get_length() == 1);
	assert(filteredArr.get(0) == o1);
}

void FilteringTest::testfilter()
{
	DynamicArray<Offer> data;
	DynamicArray<Offer> data2;
	FilteringCriteria filter;
	data=filter.filter(data);

}
