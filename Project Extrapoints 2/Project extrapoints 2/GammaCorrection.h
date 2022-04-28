#pragma once
#include "ImageProcessor.h"
#include "Test_GammaCorrection.h"
class GammaCorrectionProcessor : public ImageProcessor {
public:

    friend class Test_GammaCorrection;

    GammaCorrectionProcessor();
    
    GammaCorrectionProcessor(int gamma);

    void filter(const Image&, Image&) override;

private:
    int gamma;
};

