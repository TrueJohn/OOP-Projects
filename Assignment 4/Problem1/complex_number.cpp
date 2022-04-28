#include "complex_number.h"
#include <sstream>
#include <iomanip>
#include <math.h>
#include <string.h>



Complex:: Complex() {

	this->real = 0;
	this->imag = 0;

};

Complex:: Complex(float real, float imag){

	this->real = real;
	this->imag = imag;

};

float Complex::getReal() {
	
	return this->real ;
};

void Complex::setReal(float real) {
	this->real = real;
};

float Complex::getImag() {
	
	return this->imag;
};

void Complex::setImag(float imag) {

	this->imag=imag;
}

Complex Complex::conjugate() const {

	return Complex(this->real, -this->imag);

};

Complex Complex::add(Complex a) const {

	return Complex(this->real + a.getReal(), this->imag + a.getImag());
};

Complex Complex::subtract(Complex c) const {

	return Complex(this->real - c.getReal(), this->imag - c.getImag());
};

Complex Complex::multiply(Complex c) const {

	return Complex(this->real * c.getReal() - this->imag * c.getImag(), this->real * c.getImag() + this->imag * c.getReal());
};

void Complex::multiply(float s) {
	real *= s;
	imag *= s;
};

bool Complex::equals(Complex other) const {

	return ((((this->real - other.real) < 0.001)) && ((this->imag - other.imag) < 0.01));
};

float Complex::magnitude() {

	return (float)sqrt(this->real * this->real + this->imag * this->imag);
};

float Complex::phase() {

	return (float)atan2(this->imag, this->real);
};

void Complex::toPolar(float* r, float* theta) {
	*r = magnitude();
	*theta = phase();
};

std::string Complex::toString() const {

	std::string s;
	if (this->real == 0 && this->imag == 0)
		return "0";

	std::ostringstream str;
	str << std::setprecision(2) << std::fixed;

	if (this->imag == 0) {
		str << this->real;
		return str.str();
	}
	if (this->imag < 0)
		str << this->real << this->imag << "i";
	else
		str << this->real << "+" << this->imag << "i";
	return str.str();

};

//operators
Complex Complex:: operator-(const Complex& c) const {

	return this->subtract(c);
};

Complex Complex:: operator*(const Complex& c) const {

	return this->multiply(c);
};

Complex operator+(const Complex& c1, const Complex c2) {

	return c1.add(c2);
};

std::istream& operator>>(std::istream& in, Complex& c) {

	in >> c.real;
	in >> c.imag;
	return in;

};

std::ostream& operator<<(std::ostream& out, const Complex& c) {

	out << c.toString();
	return out;

};

