#include <sstream>
#include "Point.h"
#include <iostream>
#include <string>

Point::Point(unsigned long x, unsigned long y) : x(x), y(y) {}

Point::Point() : x(0), y(0) {}

Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point& Point::operator=(const Point& point) {
	this->x = point.x;
	this->y = point.y;
	return *this;
}

unsigned long Point::getX() const {
	return this->x;
}

unsigned long Point::getY() const {
	return this->y;
}

void Point::setX(unsigned long x) {
	this->x = x;
}

void Point::setY(unsigned long y) {
	this->y = y;
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
	std::ostringstream ss;
	ss << "(" << point.getX() << "," << point.getY() << ")";
	out << ss.str();
	return out;
}

std::istream& operator>>(std::istream& in, Point& point) {
	//(x,y)
	char c;
	in >> c;
	in >> point.x;
	in >> c;
	in >> point.y;

	return in;
}