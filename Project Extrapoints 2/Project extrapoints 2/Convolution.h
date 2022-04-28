#pragma once
#include "ImageProcessor.h"
#include <vector>

using std::vector;

enum class ConvolutionType {
    IDENTITY,
    MEAN_BLUR,
    GAUSSIAN_BLUR,
    HORIZONTAL_SOBEL,
    VERTICAL_SOBEL
};

class ConvolutionProcessor : public ImageProcessor {
public:
    ConvolutionProcessor(ConvolutionType); 

    ConvolutionProcessor(ConvolutionType, unsigned char (*)(long, int)); 


    ConvolutionProcessor(const vector<vector<int>>&, int kernelWidth, unsigned char (*)(long, int));

    void filter(const Image&, Image&) override;

    friend unsigned char downScale255(long peak, int current);

private:
    vector<vector<int>> kernel;

    int kernelWidth;

    unsigned char (*downScaler)(long, int);
};