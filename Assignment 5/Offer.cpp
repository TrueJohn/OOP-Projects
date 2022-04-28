#include "Offer.h"
#include <fstream>
#include <sstream>

using std::ostringstream;
using std::to_string;

Date create_date(unsigned int day, unsigned int month, unsigned int year) {
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

bool equals(const Date* d1, const Date* d2) {
    return (d1->day == d2->day && d1->month == d2->month && d1->year == d2->year);
}


Offer::Offer() :
    id{ "0" },
    departure{ "no location" },
    destination{ "no location" },
    price{ 0 }
{
    start_date.day = start_date.month = start_date.year = 0;
    end_Date.day = end_Date.month = end_Date.year = 0;
    type = circuit;
}

Offer::Offer(string _id, string _departure, string _destination, unsigned int _price, Date start, Date end, offer_type type) :
    id{ _id },
    departure{ _departure },
    destination{ _destination },
    price{ _price }
{
    this->start_date = start;
    this->end_Date = end;
    this->type = type;
}

Offer::Offer(const Offer& other) {
    this->departure = other.departure;
    this->destination = other.destination;
    this->id = other.id;
    this->price = other.price;
    this->start_date = other.start_date;
    this->end_Date = other.end_Date;
    this->type = other.type;
}

const string& Offer::get_id() const {
    return this->id;
}

offer_type Offer::get_type() const {
    return this->type;
}

unsigned int Offer::get_price() const {
    return this->price;
}

void Offer::set_id(string id) {
    this->id = id;
}


string Offer::toString() const {
    ostringstream res;
    res << "\nOffer of id " << id << "\n";
    res << "Departure from " << departure << " to " << destination << "\n";
    res << "Start date: " << to_string(start_date.day) << "/" << to_string(start_date.month) << "/" << to_string(start_date.year) << "\n";
    res << "End date: " << to_string(end_Date.day) << "/" << to_string(end_Date.month) << "/" << to_string(end_Date.year) << "\n";
    res << "Price: " << to_string(price) << "\n";

    string _type = "";
    switch (type) {
    case 0:
        _type = "circuit";
        break;
    case 1:
        _type = "city_break";
        break;
    case 2:
        _type = "cruise";
        break;
    case 3:
        _type = "all_inclusive";
        break;
    }

    res << "Type: " << _type << "\n";
    return res.str();
}

bool Offer::operator==(const Offer& other) const {
    return (
        this->id == other.id && this->departure == other.departure && this->destination == other.destination && equals(&this->start_date, &other.start_date) && equals(&this->end_Date, &other.end_Date)
        );
}