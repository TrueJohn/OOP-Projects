#pragma once
#include "Rectangle.h"

class Test_Rectangle {

public:

    friend class Rectangle;

    void Test_all();

private:
    bool Test_Rectangle_default_constructor();

    bool Test_Rectangle_constructor1();

    bool Test_Rectangle_constructor2();

    bool Test_Rectangle_constructor3();

    bool Test_Rectangle_constructor4();

    bool Test_Rectangle_operator1();

    bool Test_Rectangle_operator2();
    
    bool Test_Rectangle_operator3();
    
    bool Test_Rectangle_operator4();
    
    bool Test_Rectangle_operator5();

    bool Test_getWidth();

    bool Test_getHeight();

    bool Test_getCornerX();

    bool Test_getCornerY();

    bool Test_Rectangle_getSize();

    bool Test_getCorner();

    bool Test_getTopLeft();

    bool Test_setWidth();

    bool Test_setHeight();

    bool Test_setCornerX();

    bool Test_setCornerY();

    bool Test_Rectangle_setSize();

    bool Test_setCorner();

};