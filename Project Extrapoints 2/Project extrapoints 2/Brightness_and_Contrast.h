#pragma once
#include "ImageProcessor.h"
#include "Test_Brightness_and_Contrast.h"
class BrightnessContrastFilter : public ImageProcessor {

public:

    friend class Test_Brightness_and_Contrast;
    
    BrightnessContrastFilter();

    BrightnessContrastFilter(int _gain, int _bias);

    
    void filter(const Image&, Image&) override;

private:

    int gain;
    int bias;
};
