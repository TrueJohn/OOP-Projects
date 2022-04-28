#pragma once
#include "Point.h"
class Test_Point {

public:

    friend class Point;

    void Test_all();


private:


    bool Test_Point_default_constructor();

    bool Test_Point_constructor1();

    bool Test_Point_constructor2();

    bool Test_Point_operator();

    bool Test_getX();

    bool Test_getY();

    bool Test_setX();

    bool Test_setY();
    
    bool Test_ostream();

    bool Test_istream();
    
};