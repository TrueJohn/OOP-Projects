#pragma once
#include <string>
#include <ostream>
#include <sstream>
using std::string;

typedef struct {
	unsigned int day, month, year;
}Date;



Date create_date(unsigned int day, unsigned int month, unsigned int year);
bool equals(const Date* d1, const Date* d2);

enum offer_type {
	circuit,
	city_break,
	cruise, 
	all_inclusive
};

class Offer
{
public:
	Offer();
	Offer(string, string, string, unsigned int, Date, Date, offer_type);
	Offer(const Offer& other);

	const string& get_id() const;
	offer_type get_type() const;
	unsigned int get_price() const;

	void set_id(string);

	bool operator==(const Offer& other) const;

	string toString() const;

private:
	string id, departure, destination;
	unsigned int price;
	Date start_date, end_Date;
	offer_type type;


};

