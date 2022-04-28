#include "Image.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>
#include <iomanip>

using std::cout;
using std::endl;

Image::Image() : width(0), height(0), max_val(0), data(nullptr) {}

Image::Image(unsigned int w, unsigned int h) : width(w), height(h), max_val(0) {

	this->data = new unsigned char* [h];
	for (unsigned i = 0; i < h; i++)
		this->data[i] = new unsigned char[w] {0};
}

Image::Image(const Size& size) : width(size.width), height(size.height), max_val(0) {

	this->data = new unsigned char* [size.height];
	for (unsigned i = 0; i < size.height; i++)
		this->data[i] = new unsigned char[size.width];
}

Image::Image(const Image& other) {

	this->height = other.height; 
	this->width = other.width;
	this->max_val = other.max_val;

	this->data = new unsigned char* [this->height]; 
	for (unsigned i = 0; i < this->height; i++)
		this->data[i] = new unsigned char[this->width];

	for (unsigned i = 0; i < this->height; i++) 
		for (unsigned j = 0; j < this->width; j++)
			this->data[i][j] = other.data[i][j];
}

Image::~Image() {
	this->release();
}


bool Image::load(const string& path) {
	
	std::ifstream pgmSrc(path);
	string type = "0";
	unsigned int width = 0, height = 0;
	unsigned char maxval = 0;
	unsigned int temp_int;
	std::string temp_str;
	while (pgmSrc >> temp_str) {
		if (temp_str[0] == '#') {
			pgmSrc.ignore(1000, '\n'); 
			continue;
		}
		if (type == "0") {
			type = temp_str;
			if (type != "P2") 
				return false;
			continue;
		}
		if (!width) {
			width = std::stoi(temp_str);
			if (width < 1) return false;
			continue;
		}
		if (!height) {
			height = std::stoi(temp_str);
			if (height < 1) return false;
			continue;
		}
		if (!maxval) {
			temp_int = std::stoi(temp_str);
			maxval = Max_VAL(temp_int);
			if ((int)maxval == 0) {
				*this = Image(width, height);
				return true;
			}
		}
		if (type != "0" && width && height && maxval)
			break;
	}
	if (type == "0" || !width || !height || !maxval) 
		return false;

	Image temp_image(width, height);
	temp_image.max_val = maxval;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (pgmSrc.eof()) return false; 
			pgmSrc >> temp_int;
			temp_image.data[i][j] = Max_VAL(temp_int);
			if (temp_image.data[i][j] > maxval)
				temp_image.data[i][j] = maxval;
		}
	}

	*this = temp_image;
	pgmSrc.close();
	return true;
}

bool Image::save(const string& path) {
	
	std::regex r("^.*\.(pgm|PGM)$");
	if (!std::regex_match(path, r))
		return false;
	if (this->isEmpty())
		return false;

	std::ofstream pgmBuild(path);

	pgmBuild << "P2\n";
	pgmBuild << this->width << " " << this->height << endl;
	pgmBuild << this->max_val << endl;
	for (unsigned i = 0; i < this->height; i++) {
		for (unsigned j = 0; j < this->width; j++)
			pgmBuild << std::setw(3) << (int)this->data[i][j] << " ";
		pgmBuild << endl;
	}

	pgmBuild.close();
	return true;
};

Image& Image::operator=(const Image& other) {

	if (this == &other)
		return *this;
	for (unsigned i = 0; i < this->height; ++i)
		delete[] this->data[i];
	delete[] this->data;

	this->height = other.height;
	this->width = other.width;
	this->max_val = other.max_val;

	this->data = new unsigned char* [this->height];
	for (unsigned i = 0; i < this->height; i++)
		this->data[i] = new unsigned char[this->width];
	for (unsigned i = 0; i < this->height; i++)
		for (unsigned j = 0; j < this->width; j++)
			this->data[i][j] = other.data[i][j];

	return *this;
}

bool operator==(const Image& A, const Image& B) {

	if (A.height != B.height ||
		A.width != B.width ||
		A.max_val != B.max_val)
		return false;
	for (unsigned i = 0; i < A.height; i++)
		for (unsigned j = 0; j < A.width; j++)
			if (A.data[i][j] != B.data[i][j])
				return false;
	return true;
}

bool operator!=(const Image& A, const Image& B) {
	return !(A == B);
}

Image Image::operator+(const Image& B){

	if (this->height != B.height ||
		this->width != B.width)
		return *this; 

	Image temp(this->width, this->height);
	int temp_int;
	for (unsigned i = 0; i < this->height; i++)
		for (unsigned j = 0; j < this->width; j++) {
			temp_int = (int)this->data[i][j] + (int)B.data[i][j];
			temp.data[i][j] = Max_VAL(temp_int);
		}

	temp.refresh();
	return temp;
}

Image Image::operator-(const Image& B) {
	if (this->height != B.height ||
		this->width != B.width)
		return *this;

	Image temp(this->width, this->height);
	int temp_int;
	for (unsigned i = 0; i < this->height; i++)
		for (unsigned j = 0; j < this->width; j++) {
			temp_int = (int)this->data[i][j] - (int)B.data[i][j];
			temp.data[i][j] = Max_VAL(temp_int);
		}

	temp.refresh();
	return temp;
}

Image Image::operator*(const Image& B) {

	if (this->height != B.height ||
		this->width != B.width)
		return *this;

	Image temp(this->width, this->height);
	int temp_int;
	for (unsigned i = 0; i < this->height; i++)
		for (unsigned j = 0; j < this->width; j++) {
			temp_int = (int)this->data[i][j] * (int)B.data[i][j];
			temp.data[i][j] = Max_VAL(temp_int);
		}

	temp.refresh();
	return temp;
}

Image Image::operator+(const int& b) {

	Image temp(this->width, this->height);
	int temp_int;
	for (unsigned i = 0; i < this->height; i++)
		for (unsigned j = 0; j < this->width; j++) {
			temp_int = (int)this->data[i][j] + b;
			temp.data[i][j] = Max_VAL(temp_int);
		}

	temp.refresh();
	return temp;
}

Image Image::operator-(const int& b) {
	Image temp(this->width, this->height);
	int temp_int;
	for (unsigned i = 0; i < this->height; i++)
		for (unsigned j = 0; j < this->width; j++) {
			temp_int = (int)this->data[i][j] - b;
			temp.data[i][j] = Max_VAL(temp_int);
		}

	temp.refresh();
	return temp;
}

Image Image::operator*(const int& b) {
	Image temp(this->width, this->height);
	int temp_int;
	for (unsigned i = 0; i < this->height; i++)
		for (unsigned j = 0; j < this->width; j++) {
			temp_int = (int)this->data[i][j] * b;
			temp.data[i][j] = Max_VAL(temp_int);
		}

	temp.refresh();
	return temp;
}

bool Image::isEmpty() const {
	return data == nullptr;
}

unsigned int Image::get_width() const {
	return this->width;
}

unsigned int Image::get_height() const {
	return this->height;
}

void Image::set_width(unsigned int width1){

	this->width=width1;
}

void Image::set_height(unsigned int height1){
	this->height=height1;
}


unsigned char* Image::row(int y) {
	if (y > this->height - 1)
		throw std::out_of_range("Invalid index");
	return this->data[y];
}

void Image::release() {
	
	delete[] this->data;
	this->height = 0;
	this->width = 0;
	this->max_val = 0;
	this->data = nullptr;
}

void Image::refresh() {
	int max = -1;
	for (unsigned i = 0; i < this->height; i++)
		for (unsigned j = 0; j < this->width; j++)
			if (this->data[i][j] > max)
				max = this->data[i][j];
	this->max_val = max;
}

Size Image::size() const {
	return { this->width, this->height };
}

bool Image::getROI(Image& roiImg, const Rectangle& roiRect) {
	return this->getROI(roiImg, roiRect.cornerX, roiRect.cornerY, roiRect.width, roiRect.height);
}

bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
	if (x + width > this->width || y + height > this->height)
		return false;
	if (!roiImg.isEmpty())
		roiImg.release();

	roiImg = Image(width, height);
	for (unsigned i = 0; i < height; i++)
		for (unsigned j = 0; j < width; j++)
			*(*(roiImg.data + i) + j) = *(*(this->data + y + i) + x + j); //pointer arithmetic
	roiImg.refresh();
	return true;
}

unsigned char& Image::at(unsigned int y, unsigned int x) {
	if (x > this->width - 1 || y > this->height - 1)
		throw std::out_of_range("Invalid index");
	return this->data[y][x];
}

unsigned char Image::atConst(unsigned int y, unsigned int x) const {
	if (x > this->width - 1 || y > this->height - 1)
		throw std::out_of_range("Invalid index");
	return this->data[y][x];
}

unsigned char& Image::at(Point pt) {
	return this->at(pt.y, pt.x);
}

std::ostream& operator<<(std::ostream& os, const Image& dt) {
	os << "Image: " << dt.width << "x" << dt.height << std::endl;
	for (unsigned i = 0; i < dt.height; i++) {
		for (unsigned j = 0; j < dt.width; j++)
			os << std::setw(3) << (int)dt.data[i][j] << " ";
		os << std::endl;
	}
	return os;
}

Image Image::zeros(unsigned int width, unsigned int height) {
	return generateFilled(width, height, 0);
}

Image Image::ones(unsigned int width, unsigned int height) {
	return generateFilled(width, height, 1);
}

Image Image::max(unsigned int width, unsigned int height) {
	return generateFilled(width, height, 255);
}

Image Image::generateFilled(unsigned int width, unsigned int height, unsigned int value) {
	Image temp(width, height);
	for (unsigned i = 0; i < height; i++)
		for (unsigned j = 0; j < width; j++)
			temp.data[i][j] = Max_VAL(value);
	temp.max_val = Max_VAL(value);
	return temp;
}