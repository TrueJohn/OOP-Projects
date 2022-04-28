#pragma once

#include "Image.h"

class Draw {
public:
    static bool drawCircle(Image& img, Point center, int radius, unsigned char color);

    static bool drawLine(Image& img, Point start, Point end, unsigned char color);

    static bool drawRectangle(Image& img, Rectangle r, unsigned char color);

    static bool drawRectangle(Image& img, Point tl, Point br, unsigned char color);

private:
    static void plotLineLow(Image& img, int x0, int y0, int x1, int y1, unsigned char color);

    static void plotLineHigh(Image& img, int x0, int y0, int x1, int y1, unsigned char color);

};
