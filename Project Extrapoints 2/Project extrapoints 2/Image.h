#pragma once
#include "Utility.h"
#include <string>

#define Max_VAL(val) (unsigned char)(val <= 0 ? 0 : val >= 255 ? 255 : val)

using std::string;

class Image {
public:

	Image();

	Image(unsigned int w, unsigned int h);

	Image(const Image& other);

	Image(const Size&);

	~Image();

	unsigned int get_width() const;

	unsigned int get_height() const;
	
	void set_width(unsigned int);

	void set_height(unsigned int);


	bool load(const string& path);

	bool save(const string& path);

	Image& operator=(const Image& other);

	friend bool operator==(const Image& A, const Image& B);

	friend bool operator!=(const Image& A, const Image& B);

	Image operator+(const Image& B);

	Image operator-(const Image& B);

	Image operator*(const Image& B);

	Image operator+(const int& b);

	Image operator-(const int& b);

	Image operator*(const int& b);

	bool getROI(Image& roiImg, const Rectangle& roiRect);

	bool getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

	bool isEmpty() const;

	Size size() const;

	

	unsigned char& at(unsigned int y, unsigned int x);

	unsigned char atConst(unsigned int y, unsigned int x) const;

	unsigned char& at(Point pt);

	unsigned char* row(int y);

	void release();

	void refresh();

	friend std::ostream& operator<<(std::ostream& os, const Image& dt);

	static Image zeros(unsigned int width, unsigned int height);

	static Image ones(unsigned int width, unsigned int height);

	static Image max(unsigned int width, unsigned int height);

	static Image generateFilled(unsigned int width, unsigned int height, unsigned int value);

private:
	unsigned char** data;
	unsigned int max_val;
	unsigned int width;
	unsigned int height;
};
