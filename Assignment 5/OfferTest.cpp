#include "OfferTest.h"

void OfferTest::runAllTests()
{
	std::cout << "\033[1;33mSTARTING OFFER TESTS............\033[0m\n";
	testGetters();
	testString();
	testCopyConstructor();
	testEquals();
	std::cout << "\033[1;32mOffer tests passed!\033[0m\n";
}

void OfferTest::testCopyConstructor() {
	Offer o1("1", "Cluj", "Bucharest", 222, create_date(1, 5, 2022), create_date(1, 6, 2022), all_inclusive);
	Offer o2(o1);

	assert(o2.get_id() == "1");
	assert(o2.get_price() == 222);
	assert(o2.get_type() == all_inclusive);

	o2.set_id("2");

	assert(o2.get_id() == "2");
	assert(o1.get_id() == "1");

}

void OfferTest::testGetters() {
	Offer o1("1", "Cluj", "Craiova", 175, create_date(1, 5, 2022), create_date(1, 6, 2022), all_inclusive);

	assert(o1.get_id() == "1");
	assert(o1.get_price() == 175);
	assert(o1.get_type() == all_inclusive);

}


void OfferTest::testString() {
	Offer o2("2", "Cluj", "Craiova", 155, create_date(4, 9, 2022), create_date(17, 12, 2022), circuit);
	string o2_str = "\nOffer of id 2\nDeparture from Cluj to Craiova\nStart date: 4/9/2022\nEnd date: 17/12/2022\nPrice: 155\nType: circuit\n";
	assert(o2.toString() == o2_str);
}


void OfferTest::testEquals() {
	Offer o1("1", "Cluj", "Bucharest", 222, create_date(4, 9, 2022), create_date(17, 12, 2022), all_inclusive);
	Offer o2("2", "Cluj", "Craiova", 175, create_date(7, 5, 2022), create_date(7, 6, 2022), circuit);

	assert(!(o1 == o2));

	Offer o3("2", "Cluj", "Craiova", 175, create_date(7, 5, 2022), create_date(7, 6, 2022), all_inclusive);

	assert(o2 == o3);

	Offer o4(o1);
	assert(o1 == o4);
}