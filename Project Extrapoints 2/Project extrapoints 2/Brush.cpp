#include "Brush.h"
#include <cmath>
#include<iostream>

bool Draw::drawCircle(Image& img, Point center, int radius, unsigned char color) {

    unsigned long centerY = center.getY();
    unsigned long centerX = center.getX();
    unsigned int height = img.get_height();
    unsigned int width = img.get_width();
    if (radius == 0)
        return false;
    if (centerX + radius >= width || centerY + radius >= height ||
        (long)(centerX - radius) < 0 || (long)(centerY - radius) < 0)
        return false;
    
    for (int y = centerY; y < height; y++)
        for (int x = centerX; x < width; x++)
            if ((pow((x - centerX), 2)) + (pow((y - centerY), 2)) <= pow(radius, 2))
                img.at(y, x) += color;

    for (int y = 0; y < centerY; y++)
        for (int x = 0; x < centerX; x++)
            if ((pow((centerX - x), 2)) + (pow((centerY - y), 2)) <= pow(radius, 2))
                img.at(y, x) += color;

    for (int y = 0; y < centerY; y++)
        for (int x = centerX; x < width; x++)
            if ((pow((x - centerX), 2)) + (pow((centerY - y), 2)) <= pow(radius, 2))
                img.at(y, x) += color;

    for (int y = centerY; y <= height; y++)
        for (int x = 0; x <= centerX; x++)
            if ((pow((centerX - x), 2)) + (pow((y - centerY), 2)) <= pow(radius, 2))
                img.at(y, x) += color;
    img.refresh();
    return true;
}

bool Draw::drawLine(Image& img, Point p1, Point p2, unsigned char color) {
   
    int x0 = p1.getX();
    int y0 = p1.getY();
    int x1 = p2.getX();
    int y1 = p2.getY();
    if (x0 == x1 && y0 == y1)
        return false;
    if (x0 > img.get_width() || x1 > img.get_width() || y0 > img.get_height() || y1 > img.get_height())
        return false;

    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1)
            Draw::plotLineLow(img, x1, y1, x0, y0, color);
        else
            Draw::plotLineLow(img, x0, y0, x1, y1, color);
    }
    else {
        if (y0 > y1)
            Draw::plotLineHigh(img, x1, y1, x0, y0, color);
        else
            Draw::plotLineHigh(img, x0, y0, x1, y1, color);
    }
    img.refresh();
    return true;
}

void Draw::plotLineLow(Image& img, int x0, int y0, int x1, int y1, unsigned char color) {

    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }
    int D = 2 * dy - dx;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        img.at(x, y) += color;
        if (D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        }
        else
            D = D + 2 * dy;
    }
}

void Draw::plotLineHigh(Image& img, int x0, int y0, int x1, int y1, unsigned char color) {

    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    int D = 2 * dx - dy;
    int x = x0;
    for (int y = y0; y <= y1; y++) {
        img.at(x, y) += color;
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else
            D = D + 2 * dx;
    }
}

bool Draw::drawRectangle(Image& img, Point tl, Point br, unsigned char color) {

    if (tl.getX() > img.get_width() || tl.getY() > img.get_height() || br.getX() > img.get_width() || br.getY() > img.get_height())
        return false;
    if (tl.getX() > br.getX() || tl.getY() > br.getY())
        return false;
    for (int x = tl.getX(); x <= br.getX(); x++)
        for (int y = tl.getY(); y <= br.getY(); y++)
            img.at(y, x) += color;
    img.refresh();
    return true;
}

bool Draw::drawRectangle(Image& img, Rectangle r, unsigned char color) {

    return Draw::drawRectangle(img, r.getTopLeft(), r.getBottomRight(), color);
}