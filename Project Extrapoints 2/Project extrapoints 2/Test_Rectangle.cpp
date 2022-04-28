#include "Test_Rectangle.h"
#include <cassert>

void Test_Rectangle::Test_all()
{
	assert(this->Test_Rectangle_default_constructor() == true);
	assert(this->Test_Rectangle_constructor1() == true);
	assert(this->Test_Rectangle_constructor2() == true);
	assert(this->Test_Rectangle_constructor3() == true);
	assert(this->Test_Rectangle_constructor4() == true);
	assert(this->Test_Rectangle_operator1() == true);
	assert(this->Test_Rectangle_operator2() == true);
	assert(this->Test_Rectangle_operator3() == true);
	assert(this->Test_Rectangle_operator4() == true);
	assert(this->Test_Rectangle_operator5() == true);
	assert(this->Test_Rectangle_getSize() == true);
	assert(this->Test_Rectangle_setSize() == true);
	assert(this->Test_getCorner() == true);
	assert(this->Test_getCornerX() == true);
	assert(this->Test_getCornerY() == true);
	assert(this->Test_getTopLeft() == true);
	assert(this->Test_getWidth() == true);
	assert(this->Test_getHeight() == true);
	assert(this->Test_setWidth() == true);
	assert(this->Test_setCorner() == true);
	assert(this->Test_setCornerX() == true);
	assert(this->Test_setCornerY() == true);
	assert(this->Test_setHeight() == true);
	assert(this->Test_setWidth() == true);
	

}

bool Test_Rectangle::Test_Rectangle_default_constructor()
{
	Rectangle rect;

	assert(rect.getWidth() == 0);
	assert(rect.getHeight() == 0);
	assert(rect.getCornerX() == 0);
	assert(rect.getCornerY() == 0);

	return true;
}

bool Test_Rectangle::Test_Rectangle_constructor1()
{
	unsigned long width=10;
	unsigned long height=5;
	unsigned long cornerX=2;
	unsigned long cornerY=4;



	Rectangle rect(width,height,cornerX,cornerY);

	assert(rect.getWidth() == width);
	assert(rect.getHeight() == height);
	assert(rect.getCornerX() == cornerX);
	assert(rect.getCornerY() == cornerY);


	return true;
}
bool Test_Rectangle::Test_Rectangle_constructor2()
{
	unsigned long width = 10;
	unsigned long height = 5;
	unsigned long cornerX = 2;
	unsigned long cornerY = 4;



	Rectangle rect1(width, height, cornerX, cornerY);
	Rectangle rect2(rect1);
	assert(rect2.getWidth() == width);
	assert(rect2.getHeight() == height);
	assert(rect2.getCornerX() == cornerX);
	assert(rect2.getCornerY() == cornerY);


	return true;
}

bool Test_Rectangle::Test_Rectangle_constructor3()
{
	unsigned long width=4;
	unsigned long height=6;
	unsigned long xcorner = 4;
	unsigned long ycorner = 3;
	Size a(width, height);
	Point corner(xcorner, ycorner);
	Rectangle rect(a, corner);

	assert(rect.getWidth() == width);
	assert(rect.getHeight() == height);
	assert(rect.getCornerX() == xcorner);
	assert(rect.getCornerY() == ycorner);

	return true;
}

bool Test_Rectangle::Test_Rectangle_constructor4()
{
	unsigned long xcorner1 = 4;
	unsigned long ycorner1 = 3;
	unsigned long xcorner2 = 5;
	unsigned long ycorner2 = 8;
	Point topLeft_corner(xcorner1, ycorner1);
	Point bottomRight_corner(xcorner2, ycorner2);

	Rectangle rect(topLeft_corner, bottomRight_corner);

	assert(rect.getTopLeft().getX() == xcorner1);
	assert(rect.getTopLeft().getY() == ycorner1);
	
	try
	{
		Rectangle rect1(bottomRight_corner, topLeft_corner);
		
	}
	catch(...){

		assert(true);
	}
	

	return true;
}

bool Test_Rectangle::Test_Rectangle_operator1()
{
	unsigned long width = 10;
	unsigned long height = 5;
	unsigned long cornerX = 2;
	unsigned long cornerY = 4;



	Rectangle rect1(width, height, cornerX, cornerY);
	Rectangle rect2;
	rect2 = rect1;
	assert(rect2.getWidth() == width);
	assert(rect2.getHeight() == height);
	assert(rect2.getCornerX() == cornerX);
	assert(rect2.getCornerY() == cornerY);


	return true;
}

bool Test_Rectangle::Test_Rectangle_operator2()
{
	unsigned long width = 10;
	unsigned long height = 5;
	unsigned long cornerX = 2;
	unsigned long cornerY = 4;



	Rectangle rect1(width, height, cornerX, cornerY);

	Vector2D vect(2, 3);
	
	rect1 =rect1 + vect;

	assert(rect1.getCornerX() == 4);
	assert(rect1.getCornerY() == 7);


	return true;
}

bool Test_Rectangle::Test_Rectangle_operator3()
{
	unsigned long width = 10;
	unsigned long height = 5;
	unsigned long cornerX = 6;
	unsigned long cornerY = 8;



	Rectangle rect1(width, height, cornerX, cornerY);

	Vector2D vect(2, 3);

	rect1 = rect1 - vect;

	assert(rect1.getCornerX() == 4);
	assert(rect1.getCornerY() == 5);


	return true;


}

bool Test_Rectangle::Test_Rectangle_operator4()
{
	unsigned long width1 = 5;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	unsigned long width2 = 5;
	unsigned long height2 = 5;
	unsigned long cornerX2 = 2;
	unsigned long cornerY2 = 2;


	Rectangle rect1(width1, height1, cornerX1, cornerY1);

	Rectangle rect2(width2, height2, cornerX2, cornerY2);

	Rectangle rect3;
	

	rect3 = rect1 & rect2;

	assert(rect3.getCornerX() == 2);
	assert(rect3.getCornerY() == 2);
	assert(rect3.getHeight() == 4);
	assert(rect3.getWidth() == 4);

	try {
		Rectangle rect4(1, 2, 100, 100);
		rect4 = rect4 & rect3;
	}
	catch (...) {
		assert(true);
	}

	return true;


}

bool Test_Rectangle::Test_Rectangle_operator5()
{
	unsigned long width1 = 5;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	unsigned long width2 = 2;
	unsigned long height2 = 5;
	unsigned long cornerX2 = 6;
	unsigned long cornerY2 = 6;


	Rectangle rect1(width1, height1, cornerX1, cornerY1);

	Rectangle rect2(width2, height2, cornerX2, cornerY2);

	Rectangle rect3;


	rect3 = rect1 | rect2;

	assert(rect3.getWidth() == 7);

	return true;
}

bool Test_Rectangle::Test_getWidth()
{
	unsigned long width1 = 5;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(width1, height1, cornerX1, cornerY1);

	assert(rect1.getWidth() == 5);

	return true;
}

bool Test_Rectangle::Test_getHeight()
{
	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(width1, height1, cornerX1, cornerY1);

	assert(rect1.getHeight() == height1);

	return true;
}

bool Test_Rectangle::Test_getCornerX()
{
	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(width1, height1, cornerX1, cornerY1);

	assert(rect1.getCornerX() == Point(1, 1).getX());

	return true;

}

bool Test_Rectangle::Test_getCornerY()
{
	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(width1, height1, cornerX1, cornerY1);

	assert(rect1.getCornerY() == Point(1, 1).getY());

	return true;
}

bool Test_Rectangle::Test_Rectangle_getSize()
{
	unsigned long width = 10;
	unsigned long height = 5;
	unsigned long cornerX = 2;
	unsigned long cornerY = 4;



	Rectangle rect1(width, height, cornerX, cornerY);

	Size size1(width, height);

	assert(rect1.getSize().getHeight() == size1.getHeight());
	assert(rect1.getSize().getWidth() == size1.getWidth());

	return true;
}

bool Test_Rectangle::Test_getCorner()
{
	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(width1, height1, cornerX1, cornerY1);

	assert(rect1.getCorner().getX() == Point(1, 1).getX());
	assert(rect1.getCorner().getY() == Point(1, 1).getY());

	return true;
}

bool Test_Rectangle::Test_getTopLeft()
{

	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(width1, height1, cornerX1, cornerY1);

	assert(rect1.getTopLeft().getX() == Point(1, 1).getX());
	assert(rect1.getTopLeft().getY() == Point(1, 1).getY());

	return true;
}

bool Test_Rectangle::Test_setWidth()
{
	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(0, height1, cornerX1, cornerY1);

	rect1.setWidth(width1);
	assert(rect1.getWidth()==width1);

	return true;
}

bool Test_Rectangle::Test_setHeight()
{
	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(width1, 0, cornerX1, cornerY1);

	rect1.setHeight(height1);
	assert(rect1.getHeight() == height1);

	return true;
}

bool Test_Rectangle::Test_setCornerX()
{
	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(width1, height1, 0, cornerY1);

	rect1.setCornerX(cornerX1);

	assert(rect1.getCornerX() == cornerX1);

	return true;
}

bool Test_Rectangle::Test_setCornerY()
{
	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(width1, height1, cornerX1, 0);

	rect1.setCornerY(cornerY1);

	assert(rect1.getCornerY() == cornerY1);

	return true;

}

bool Test_Rectangle::Test_Rectangle_setSize()
{
	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 1;
	unsigned long cornerY1 = 1;

	Rectangle rect1(2, 3, cornerX1, cornerY1);

	Size size1(width1, height1);

	rect1.setSize(size1);

	assert(rect1.getSize().getHeight() == size1.getHeight());
	assert(rect1.getSize().getWidth() == size1.getWidth());

	return true;
}

bool Test_Rectangle::Test_setCorner()
{
	unsigned long width1 = 6;
	unsigned long height1 = 5;
	unsigned long cornerX1 = 7;
	unsigned long cornerY1 = 6;

	Rectangle rect1(width1, height1, 0, 0);

	Point point1(cornerX1, cornerY1);

	rect1.setCorner(point1);

	assert(rect1.getCornerX()==cornerX1);
	assert(rect1.getCornerY()==cornerY1);


	return true;
}


