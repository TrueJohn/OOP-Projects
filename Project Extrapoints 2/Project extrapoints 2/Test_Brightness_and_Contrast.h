#pragma once
#include "Brightness_and_Contrast.h"
class Test_Brightness_and_Contrast{

public:

    friend class Brightness_and_Contrast;

    void Test_all();


private:


    bool Test_Brightness_and_Contrast_default_constructor();

    bool Test_Brightness_and_Contrast_constructor();

    bool Test_Brightness_and_Contrast_process();

};