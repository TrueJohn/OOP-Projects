#include "Test_Brightness_and_Contrast.h"
#include <cassert>

void Test_Brightness_and_Contrast::Test_all()
{
	assert(Test_Brightness_and_Contrast_default_constructor() == true);
	assert(Test_Brightness_and_Contrast_constructor() == true);
	assert(Test_Brightness_and_Contrast_process() == true);
}

bool Test_Brightness_and_Contrast::Test_Brightness_and_Contrast_default_constructor()
{
	BrightnessContrastFilter filter;

	assert(filter.gain == 1);
	assert(filter.bias == 0);
	

	return true;
}
bool Test_Brightness_and_Contrast::Test_Brightness_and_Contrast_constructor()
{
	BrightnessContrastFilter filter(2,4);

	assert(filter.gain == 2);
	assert(filter.bias == 4);


	return true;
}

bool Test_Brightness_and_Contrast::Test_Brightness_and_Contrast_process()
{
	Image image1=Image::zeros(1,1),image2;

	BrightnessContrastFilter filter(2, 4);

	filter.filter(image1, image2);

	assert(image1.at(0, 0) == 0);

	return true;
}
