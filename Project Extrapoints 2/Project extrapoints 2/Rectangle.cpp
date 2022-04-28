#include <stdexcept>
#include <iostream>
#include "Rectangle.h"

using std::min;
using std::max;

Rectangle::Rectangle():width(0), height(0), cornerX(0), cornerY(0) {}

Rectangle::Rectangle(unsigned long width, unsigned long height, unsigned long cornerX, unsigned long cornerY) :
    width(width), height(height), cornerX(cornerX), cornerY(cornerY) {}

Rectangle::Rectangle(const Rectangle& rectangle) {
    this->width = rectangle.width;
    this->height = rectangle.height;
    this->cornerX = rectangle.cornerX;
    this->cornerY = rectangle.cornerY;
}

Rectangle::Rectangle(const Size& _size, const Point& _corner) {
    this->width = _size.getWidth();
    this->height = _size.getHeight();
    this->cornerX = _corner.getX();
    this->cornerY = _corner.getY();
}


Rectangle::Rectangle(const Point& topLeft, const Point& bottomRight) {
    if (topLeft.getX() > bottomRight.getX() ||
        topLeft.getY() > bottomRight.getY()) {
        throw std::invalid_argument("Invalid rectangle");
    }
    this->width = bottomRight.getX() - topLeft.getX();
    this->height = bottomRight.getY() - topLeft.getY();
    this->cornerX = topLeft.getX();
    this->cornerY = topLeft.getY();

}

unsigned long Rectangle::getWidth() const {
    return this->width;
}

unsigned long Rectangle::getHeight() const {
    return this->height;
}

unsigned long Rectangle::getCornerX() const {
    return this->cornerX;
}

unsigned long Rectangle::getCornerY() const {
    return this->cornerY;
}

Size Rectangle::getSize() const {
    return { this->width, this->height };
}


Point Rectangle::getCorner() const {
    return { this->cornerX, this->cornerY };
}

Point Rectangle::getTopLeft() const {
    return { this->cornerX, this->cornerY };
}

Point Rectangle::getBottomRight() const {
    return { this->cornerX + this->width - 1, this->cornerY + this->height - 1 };
}

void Rectangle::setWidth(unsigned long _width) {
    this->width = _width;
}

void Rectangle::setHeight(unsigned long _height) {
    this->height = _height;
}

void Rectangle::setCornerX(unsigned long _cornerX) {
    this->cornerX = _cornerX;
}

void Rectangle::setCornerY(unsigned long _cornerY) {
    this->cornerY = _cornerY;
}

void Rectangle::setSize(const Size& _size) {
    this->width = _size.getWidth();
    this->height = _size.getHeight();
}

void Rectangle::setCorner(const Point& _corner) {
    this->cornerX = _corner.getX();
    this->cornerY = _corner.getY();
}


Rectangle& Rectangle::operator=(const Rectangle& rectangle) {
    this->width = rectangle.width;
    this->height = rectangle.height;
    this->cornerX = rectangle.cornerX;
    this->cornerY = rectangle.cornerY;
    return *this;
}

Rectangle& Rectangle::operator+(Vector2D& translation) {
    static Rectangle temp = *this;
    long newCornerX = this->cornerX + translation.getX();
    newCornerX > 0 ? temp.cornerX = newCornerX : temp.cornerX = 0;
    long newCornerY = this->cornerY + translation.getY();
    newCornerY > 0 ? temp.cornerY = newCornerY : temp.cornerY = 0;
    return temp;
}

Rectangle& Rectangle::operator-(Vector2D& translation) {
    static Rectangle temp = *this;
    long newCornerX = this->cornerX - translation.getX();
    newCornerX > 0 ? temp.cornerX = newCornerX : temp.cornerX = 0;
    long newCornerY = this->cornerY - translation.getY();
    newCornerY > 0 ? temp.cornerY = newCornerY : temp.cornerY = 0;
    return temp;
}



Rectangle& Rectangle::operator&(const Rectangle& other) {
    
    if (this->cornerX > other.cornerX + other.width ||
        this->cornerY > other.cornerY + other.height ||
        this->cornerX + this->width < other.cornerX ||
        this->cornerY + this->height < other.cornerY) {
        throw std::invalid_argument("Rectangles do not intersect");
       
    }
    auto intersectionWidth =min(min(this->width, other.height + other.cornerX - this->cornerX),this->width + this->cornerX - other.cornerX);
    
    auto intersectionHeight =min(min(this->height, other.height + other.cornerY - this->cornerY),this->height + this->cornerY - other.cornerY);
    
    unsigned newCornerX = std::max(this->cornerX, other.cornerX);
    
    unsigned newCornerY = std::max(this->cornerY, other.cornerY);
    
    static Rectangle temp(intersectionWidth, intersectionHeight, newCornerX, newCornerY);
    return temp;
}

Rectangle& Rectangle::operator|(const Rectangle& other) {
    
    unsigned newCornerX =
        min(this->getTopLeft().getX(), other.getTopLeft().getX());
    unsigned newCornerY =
        min(this->getTopLeft().getY(), other.getTopLeft().getY());
    unsigned long rightmostX =
        max(this->getBottomRight().getX(), other.getBottomRight().getX());
    unsigned long bottommostY =
        max(this->getBottomRight().getY(), other.getBottomRight().getY());
    static Rectangle temp(rightmostX - newCornerX + 1, bottommostY - newCornerY + 1, newCornerX, newCornerY);
    return temp;
}




