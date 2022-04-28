#include "GammaCorrection.h"
#include <cmath>

GammaCorrectionProcessor::GammaCorrectionProcessor() : gamma(1) {}

GammaCorrectionProcessor::GammaCorrectionProcessor(int _gamma) : gamma(_gamma) {}



void GammaCorrectionProcessor::filter(const Image& src, Image& dst) {
    dst.release();
    dst = Image(src.size());
    for (int i = 0; i < src.get_height(); i++)
        for (int j = 0; j < src.get_width(); j++)
            dst.at(i, j) = Max_VAL(pow(int(src.atConst(i, j)), this->gamma));
    dst.refresh();
}