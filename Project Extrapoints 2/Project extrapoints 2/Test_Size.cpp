#include "Size.h"
#include <cassert>
#include "Test_Size.h"
#include <iostream>

void Test_Size::Test_all()
{
	assert(this->Test_getHeight() == true);
	assert(this->Test_getWidth() == true);
	assert(this->Test_setHeight() == true);
	assert(this->Test_setWidth() == true);
	assert(this->Test_size_constructor1() == true);
	assert(this->Test_size_constructor2() == true);
	assert(this->Test_size_constructor3() == true);
	assert(this->Test_size_default_constructor() == true);
	assert(this->Test_size_operator() == true);
	

}

bool Test_Size::Test_size_default_constructor()
{
	unsigned long height = 0;
	unsigned long width = 0;
	Size a;
	assert(a.getHeight() == height);
	assert(a.getWidth() == width);

	return true;
}

bool Test_Size::Test_size_constructor1() {
	
	unsigned long height = 20;
	unsigned long width = 10;
	Size a;
	a.setHeight(height);
	a.setWidth(width);
	assert(a.getHeight() == height);
	assert(a.getWidth() == width);

	return true;
};

bool Test_Size::Test_size_constructor2() {
	unsigned long height = 20;
	unsigned long width = 10;
	Size a(width,height);
	assert(a.getHeight() == height);
	assert(a.getWidth() == width);
	return true;
}
bool Test_Size::Test_size_constructor3()
{
	unsigned long width= 20;
	unsigned long height = 20;


	Size a(width, height);
	Size b(a);
	assert(b.getHeight() == height);
	assert(b.getWidth() == width);


	return true;
}
;

bool Test_Size::Test_size_operator() {
	unsigned long height = 20;
	unsigned long width = 10;
	Size a;
	Size b(width, height);
	a = b;
	
	assert(a.getHeight()==height);
	assert(a.getWidth() == width);

	return true;
};

bool Test_Size::Test_getWidth() {
	unsigned long height = 20;
	unsigned long width = 10;
	Size a(width, height);
	assert(a.getWidth() == width);
	return true;
};

bool Test_Size::Test_getHeight() {
	unsigned long height = 20;
	unsigned long width = 10;
	Size a(width, height);
	assert(a.getHeight() == height);
	return true;
};

bool Test_Size::Test_setWidth() {
	unsigned long width = 10;
	Size a;
	a.setWidth(width);
	assert(a.getWidth() == width);
	return true;
};

bool Test_Size::Test_setHeight() {
	unsigned long height = 10;
	Size a;
	a.setHeight(height);
	assert(a.getHeight() == height);
	return true;
};


