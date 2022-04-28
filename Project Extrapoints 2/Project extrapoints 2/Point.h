#pragma once
#include <fstream>

class Point {

public:
    friend class Image;

    friend class Brush;

    Point(unsigned long x, unsigned long y);

    Point();

    Point(const Point& point);

    Point& operator=(const Point& point);

    friend std::ostream& operator<<(std::ostream& out, const Point&);

    friend std::istream& operator>>(std::istream& in, Point&);

    unsigned long getX() const;

    unsigned long getY() const;

    void setX(unsigned long x);

    void setY(unsigned long y);

private:
    unsigned long x; 
    unsigned long y;

};