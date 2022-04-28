#include "Vector2D.h"

Vector2D::Vector2D() : x(0), y(0) {}


Vector2D::Vector2D(double _x, double _y) : x(_x), y(_y) {}


double Vector2D::getX() const {
    return this->x;
}

double Vector2D::getY() const {
    return this->y;
}

void Vector2D::setX(double x1) {
    this->x = x1;
}

void Vector2D::setY(double y1) {
    this->y = y1;
}

Vector2D& Vector2D::operator=(const Vector2D& other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}