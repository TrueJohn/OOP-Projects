#pragma once
class Size {

public:

    friend class Image;

    Size();

    Size(unsigned long width, unsigned long height);

    Size(const Size&);

    Size& operator=(const Size&);

    unsigned long getWidth() const;

    unsigned long getHeight() const;

    void setWidth(int width);

    void setHeight(int height);

private:
    unsigned long width;
    unsigned long height;

};