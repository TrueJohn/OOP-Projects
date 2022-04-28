#pragma once
#include "Vector2D.h"
class Test_Vector2D {

public:

    friend class Vector2D;

    void Test_all();


private:
    

    bool Test_Vector2D_default_constructor();

    bool Test_Vector2D_constructor1();

    bool Test_Vector2D_operator();

    bool Test_getX();

    bool Test_getY();

    bool Test_setX();

    bool Test_setY();
};