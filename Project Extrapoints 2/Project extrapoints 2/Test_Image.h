#pragma once
#include "Image.h"
class Test_Image {

public:

    friend class Image;

    void Test_all();


private:


    bool Test_Image_default_constructor();

    bool Test_get_Height();

    bool Test_get_Width();

    bool Test_set_Height();

    bool Test_set_Width();

};