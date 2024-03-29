#include "Convolution.h"

#include <utility>

unsigned char downScale255(long peak, int current) {
    if (peak >= 0 && peak <= 255) 
        return (unsigned char)current;

    double scalePercentage = 255.0 / peak * 100.0;
    double downscaledCurrent = (float)current / 100 * scalePercentage;

    return (unsigned char)downscaledCurrent;
}

ConvolutionProcessor::ConvolutionProcessor(ConvolutionType _type) : ConvolutionProcessor(_type, downScale255) {}

ConvolutionProcessor::ConvolutionProcessor(ConvolutionType _type, unsigned char (*_downScalerFunc)(long, int)) :
    kernelWidth(3),
    downScaler(_downScalerFunc) {
    switch (_type) {
    case ConvolutionType::IDENTITY:
        this->kernel = { {0, 0, 0},
                        {0, 1, 0},
                        {0, 0, 0} };
        break;
    case ConvolutionType::MEAN_BLUR:
        this->kernel = { {1, 1, 1},
                        {1, 1, 1},
                        {1, 1, 1} };
        break;
    case ConvolutionType::GAUSSIAN_BLUR:
        this->kernel = { {1, 2, 1},
                        {2, 4, 2},
                        {1, 2, 1} };
        break;
    case ConvolutionType::HORIZONTAL_SOBEL:
        this->kernel = { {1,  2,  1},
                        {0,  0,  0},
                        {-1, -2, -1} };
        break;
    case ConvolutionType::VERTICAL_SOBEL:
        this->kernel = { {-1, 0, 1},
                        {-2, 0, 2},
                        {-1, 0, 1} };
        break;
    }
}

ConvolutionProcessor::ConvolutionProcessor(const vector<vector<int>>& _kernel, int _kernelWidth,
    unsigned char (*_downScalerFunc)(long, int)) :
    kernel(_kernel),
    kernelWidth(_kernelWidth),
    downScaler(_downScalerFunc) {}

void ConvolutionProcessor::filter(const Image& src, Image& dst) {
    int kernelCenter = this->kernelWidth / 2;
    vector<vector<int>> tempStorage(src.get_height(), vector<int>(src.get_width(), 0));
    long peak = -1;

    if (!dst.isEmpty())
        dst.release();

    dst = Image(src.size());

    for (int y = 0; y < dst.get_height(); y++) {
        for (int x = 0; x < dst.get_width(); x++) {

            int sum = 0;
            for (int ky = 0; ky < this->kernelWidth; ky++) {
                for (int kx = 0; kx < this->kernelWidth; kx++) {
                    int srcX = x + kx - kernelCenter;
                    int srcY = y + ky - kernelCenter;

                    if (srcX < 0 || srcX >= src.get_width() || srcY < 0 || srcY >= src.get_height())
                        
                        continue;

                    sum += src.atConst(srcY, srcX) * this->kernel[ky][kx];
                }

                
                if (sum > peak) peak = sum;
                tempStorage[y][x] = sum;
            }
        }
    }

   
    for (int y = 0; y < dst.get_height(); y++)
        for (int x = 0; x < dst.get_width(); x++)
            dst.at(y, x) = this->downScaler(peak, tempStorage[y][x]);

    dst.refresh();
}