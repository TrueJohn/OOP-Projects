#include "Test_Vector2D.h"
#include <cassert>
void Test_Vector2D::Test_all()
{
	assert(this->Test_Vector2D_default_constructor() == true);
	assert(this->Test_Vector2D_constructor1() == true);
	assert(this->Test_Vector2D_operator() == true);
	assert(this->Test_getX() == true);
	assert(this->Test_getY() == true);
	assert(this->Test_setX() == true);
	assert(this->Test_setY() == true);

}

bool Test_Vector2D::Test_Vector2D_default_constructor()
{
	Vector2D vector;
	
	assert(vector.getX() == 0);
	assert(vector.getY() == 0);

	return true;
}

bool Test_Vector2D::Test_Vector2D_constructor1()
{
	double x=2.0;
	double y=3.0;

	Vector2D vector(x,y);

	assert(vector.getX() == x);
	assert(vector.getY() == y);

	return true;
}

bool Test_Vector2D::Test_Vector2D_operator()
{
	double x = 2.0;
	double y = 3.0;

	Vector2D vector1(x, y);
	Vector2D vector2;

	vector2 = vector1;

	assert(vector2.getX() == x);
	assert(vector2.getY() == y);

	return true;
}

bool Test_Vector2D::Test_getX()
{
	double x = 2.0;
	double y = 3.0;

	Vector2D vector1(x, y);

	assert(vector1.getX() == x);

	return true;
}

bool Test_Vector2D::Test_getY()
{
	double x = 2.0;
	double y = 3.0;

	Vector2D vector(x, y);

	assert(vector.getY() == y);

	return true;
}

bool Test_Vector2D::Test_setX()
{
	double x = 2.0;
	double y = 3.0;

	Vector2D vector(0.0, y);

	vector.setX(x);
	
	assert(vector.getX() == x);

	return true;
}

bool Test_Vector2D::Test_setY()
{
	double x = 2.0;
	double y = 3.0;

	Vector2D vector(x, 0.0);

	vector.setY(y);

	assert(vector.getY() == y);

	return true;
}
