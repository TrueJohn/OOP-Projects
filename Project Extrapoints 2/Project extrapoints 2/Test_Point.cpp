#include "Test_Point.h"
#include "Point.h"
#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
void Test_Point::Test_all()
{   
    assert(this->Test_Point_default_constructor() == true);
    assert(this->Test_Point_constructor1() == true);
    assert(this->Test_Point_constructor2() == true); 
    assert(this->Test_Point_operator() == true);
    assert(this->Test_getX() == true);
    assert(this->Test_getY() == true);
    assert(this->Test_setX() == true);
    assert(this->Test_setY() == true);
    assert(this->Test_ostream() == true);
    assert(this->Test_istream() == true);
    
}

bool Test_Point::Test_Point_default_constructor()
{
    Point a;
    assert(a.getX() == 0);
    assert(a.getY() == 0);

    return true;
}

bool Test_Point::Test_Point_constructor1()
{
    unsigned long x = 10;
    unsigned long y = 20;
    Point a(x, y);
    assert(a.getX() == x);
    assert(a.getY() == y);

    return true;
}

bool Test_Point::Test_Point_constructor2()
{
    unsigned long x = 10;
    unsigned long y = 20;
    Point a(x, y);
    Point b(a);
    assert(b.getX() == x);
    assert(b.getY() == y);

    return true;
}

bool Test_Point::Test_Point_operator()
{
    unsigned long x = 10;
    unsigned long y = 20;
    Point a(x, y);
    Point b;
    b = a;
    assert(b.getX() == x);
    assert(b.getY() == y);

    return true;
}

bool Test_Point::Test_getX()
{
    unsigned long x = 10;
    unsigned long y = 20;
    Point a(x, y);
    assert(a.getX() == x);

    return true;
}

bool Test_Point::Test_getY()
{
    unsigned long x = 10;
    unsigned long y = 20;
    Point a(x, y);
    assert(a.getY() == y);

    return true;
}

bool Test_Point::Test_setX()
{
    unsigned long x = 10;
    unsigned long y = 20;
    Point a(0, y);
    a.setX(x);
    assert(a.getX() == x);

    return true;
}

bool Test_Point::Test_setY()
{
    unsigned long x = 10;
    unsigned long y = 20;
    Point a(x, 0);
    a.setY(y);
    assert(a.getY() == y);

    return true;
}

bool Test_Point::Test_ostream()
{
    unsigned long x = 10;
    unsigned long y = 20;
    Point a(x, y);
    std::ostringstream sstr;
    std::string s = "(10,20)";
    sstr << a;
    assert(sstr.str().compare(s) == 0);

    return true;
}

bool Test_Point::Test_istream()
{

    Point a;
    std::istringstream sstr("(10,20)");
    std::string s1="";
    sstr>>a;

    assert(a.getX() == 10);
    assert(a.getY() == 20);
   

    return true;

}
