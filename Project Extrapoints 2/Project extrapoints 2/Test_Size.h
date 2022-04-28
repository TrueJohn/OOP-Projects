#pragma once
#include "Size.h"
class Test_Size {

public:

    friend class Size;

    void Test_all();


private:
    

    bool Test_size_default_constructor();

    bool Test_size_constructor1();

    bool Test_size_constructor2();

    bool Test_size_constructor3();

    bool Test_size_operator();

    bool Test_getWidth();

    bool Test_getHeight();

    bool Test_setWidth();

    bool Test_setHeight();
};