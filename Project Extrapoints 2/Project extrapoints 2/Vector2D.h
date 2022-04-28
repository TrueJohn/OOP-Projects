#pragma once

class Vector2D {

public:
    Vector2D(double x, double y);

    Vector2D();

    double getX() const;

    double getY() const;

    void setX(double x);

    void setY(double y);

    Vector2D& operator=(const Vector2D& other);

private:
    double x;
    double y;

};