#pragma once

#include "Image.h"

class ImageProcessor {

public:

    virtual void filter(const Image&, Image&) = 0;
};
