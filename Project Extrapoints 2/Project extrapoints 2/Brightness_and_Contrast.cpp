#include "Brightness_and_Contrast.h"

BrightnessContrastFilter::BrightnessContrastFilter() : BrightnessContrastFilter(1, 0) {}

BrightnessContrastFilter::BrightnessContrastFilter(int _gain, int _bias) : gain(_gain), bias(_bias) {}



void BrightnessContrastFilter::filter(const Image& src, Image& dst) {
    dst.release();
    dst = Image(src.size());
    for (int i = 0; i < src.get_height(); i++)
        for (int j = 0; j < src.get_width(); j++)
            dst.at(i, j) = Max_VAL((this->gain * int(src.atConst(i, j))) + this->bias);
    dst.refresh();
}