#pragma once
#include "Vector2D.h"
#include "Point.h"
#include "Size.h"

class Rectangle {

public:

    friend class Image;

    Rectangle();

    Rectangle(unsigned long width, unsigned long height, unsigned long cornerX, unsigned long cornerY);

    Rectangle(const Rectangle& rectangle);

    Rectangle(const Size& size, const Point& corner);

    Rectangle(const Point& topLeft, const Point& bottomRight);

    Rectangle& operator=(const Rectangle& rectangle);

    Rectangle& operator+(Vector2D& vector);

    Rectangle& operator-(Vector2D& vector);

    Rectangle& operator&(const Rectangle& rectangle);

    Rectangle& operator|(const Rectangle& rectangle);

    

    unsigned long getWidth() const;

    unsigned long getHeight() const;

    unsigned long getCornerX() const;

    unsigned long getCornerY() const;

    Size getSize() const;

    Point getCorner() const;

    Point getTopLeft() const;

    Point getBottomRight() const;

    void setWidth(unsigned long width);

    void setHeight(unsigned long height);

    void setCornerX(unsigned long cornerX);

    void setCornerY(unsigned long cornerY);

    void setSize(const Size& size);

    void setCorner(const Point& corner);

private:
    unsigned long width;
    unsigned long height;
    unsigned long cornerX;
    unsigned long cornerY;

};