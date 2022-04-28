#pragma once
#include "Offer.h"
#include <cassert>
#include <iostream>

class OfferTest
{
public:
	static void runAllTests();
private:
	static void testCopyConstructor();
	static void testGetters();
	static void testString();
	static void testEquals();
};

