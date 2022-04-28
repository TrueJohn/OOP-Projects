#include "Test_Image.h"
#include <cassert>

void Test_Image::Test_all()
{
	assert(this->Test_Image_default_constructor() == true);
	
	assert(this->Test_get_Width() == true);
	assert(this->Test_get_Height() == true);
	assert(this->Test_set_Width() == true);
	assert(this->Test_set_Height() == true);

}

bool Test_Image::Test_Image_default_constructor()
{
	Image imag;

	assert(imag.get_height() == 0);
	assert(imag.get_width() == 0);

	return true;
}


bool Test_Image::Test_get_Height()
{
	unsigned int width = 4;
	unsigned int height = 8;

	Image imag(width,height);

	assert(imag.get_height() == height);

	return true;
}

bool Test_Image::Test_get_Width()
{
	unsigned int width = 4;
	unsigned int height = 8;

	Image imag(width, height);

	assert(imag.get_width() == width);
	

	return true;
}

bool Test_Image::Test_set_Height()
{
	unsigned int width = 4;
	unsigned int height = 8;

	Image imag;

	imag.set_height(height);
	imag.set_width(width);

	assert(imag.get_height() == height);

	return true;
}

bool Test_Image::Test_set_Width()
{
	unsigned int width = 4;
	unsigned int height = 8;

	Image imag;

	imag.set_height(height);
	imag.set_width(width);

	assert(imag.get_width() == width);

	return true;
}
