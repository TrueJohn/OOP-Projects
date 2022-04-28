#include "BigInteger.h"
#include <cctype> 
#include <iomanip>
#include <iostream>

using std::ostringstream;
using std::ostream;

#define MAX_SIZE 2500

BigInteger::BigInteger() {

	this->sign = 0;

	this->digits = new int[MAX_SIZE] {0};

	this->length = 0;
}

BigInteger::BigInteger(std::string s) {

	this->sign = 1;

	this->length = 0;

	this->digits = new int[MAX_SIZE] {0};


	if (s.length() > MAX_SIZE)
		if (!(s.size() == MAX_SIZE + 1 && (s[0] == '+' || s[0] == '-')))
			return;

	for (int i = s.size() - 1; i >= 0; i--) 
	{
		if (i == 0 && s[0] == '-') {
			this->sign = -1;
			continue;
		}

		if (isdigit(s[i])) {
			this->length++;
			this->digits[MAX_SIZE - this->length] = s[i] - int('0');
		}
	}

	check_zero(*this);
}

BigInteger::BigInteger(const BigInteger& other) {

	this->sign = other.sign;

	this->length = other.length;

	this->digits = new int[MAX_SIZE] {0};

	for (int i = 0; i < MAX_SIZE; i++)
		this->digits[i] = other.digits[i];

}

BigInteger::~BigInteger() {

	delete[] this->digits;
}

BigInteger& BigInteger::operator=(const BigInteger& other) {

	if (this == &other)
		return *this;

	delete[] this->digits;

	this->length = other.length;

	this->sign = other.sign;

	this->digits = new int[MAX_SIZE] {0};

	std::copy(other.digits, other.digits + MAX_SIZE, this->digits);

	return *this;
}

int BigInteger::sgn() const {

	return this->sign;
}

BigInteger abs(BigInteger A) {

	if (A.sign)
		A.sign = +1;

	return A;
}

void BigInteger::negate() {

	this->sign *= -1;
}

BigInteger& BigInteger::operator++() {

	BigInteger rez = (*this) + BigInteger("1");

	*this = rez;

	return *this;
}

const BigInteger BigInteger::operator++(int t) {

	BigInteger rez = *this;

	if (t != 0)
		(*this) += BigInteger(std::to_string(t));
	else
		++(*this);

	return rez;
}

ostream& operator<<(ostream& stream, const BigInteger& N) {

	stream << N.to_string();
	return stream;
}

bool operator==(const BigInteger& A, const BigInteger& B) {

	if (!A.compare(B))
		return true;
	else
		return false;
}

bool operator<(const BigInteger& A, const BigInteger& B) {

	if (A.compare(B) == -1)
		return true;
	else
		return false;
}

bool operator<=(const BigInteger& A, const BigInteger& B) {

	if (A.compare(B) != 1)
		return true;
	else
		return false;
}

bool operator>(const BigInteger& A, const BigInteger& B) {

	if (A.compare(B) == 1)
		return true;
	else
		return false;
}

bool operator>=(const BigInteger& A, const BigInteger& B) {

	if (A.compare(B) != -1)
		return true;
	else
		return false;
}

BigInteger operator+(const BigInteger& A, const BigInteger& B) {

	return A.add(B);
};

BigInteger operator+=(BigInteger& A, const BigInteger& B) {

	A = A.add(B);

	return A;
}

BigInteger operator-(const BigInteger& A, const BigInteger& B) {

	return A.sub(B);
}

BigInteger operator-=(BigInteger& A, const BigInteger& B) {

	A = A.sub(B);

	return A;
}

void update_length(BigInteger& A) {

	int leading = 0;

	while (A.digits[leading] == 0 && leading != (MAX_SIZE - 1))
		leading++;

	A.length = MAX_SIZE - leading;

}

void check_zero(BigInteger& A) {

	for (int i = MAX_SIZE - 1; i >= MAX_SIZE - A.length; i--) {
		if (A.digits[i] != 0)
			return;
	}

	A.length = 0;

	A.sign = 0;
}

short addition_case(const BigInteger& A, const BigInteger& B) {

	if (A.sign == +1) {
		if (B.sign == +1)
			return 1;
		if (B.sign == -1)
			return 3;
	}

	if (A.sign == -1) {
		if (B.sign == +1)
			return 2;
		if (B.sign == -1)
			return 4;
	}

	return 0;
}

BigInteger neg_dig(BigInteger const& A) {

	BigInteger rez;

	rez.length = A.length;

	rez.sign = 0;

	for (int i = MAX_SIZE - 1; i >= MAX_SIZE - A.length; i--)
		rez.digits[i] = -A.digits[i];

	return rez;
}

BigInteger add_dig(const BigInteger& A, const BigInteger& B) {

	BigInteger rez;

	rez.length = A.length;

	rez.sign = 0;

	for (int i = 0; i < MAX_SIZE; i++)
		rez.digits[i] = A.digits[i] + B.digits[i];

	return rez;
}

BigInteger digitize(BigInteger const& A) {

	BigInteger rez;

	rez.length = A.length;

	rez.sign = 0;

	for (int i = 0; i < MAX_SIZE; i++)
		rez.digits[i] = A.digits[i];

	int cb = 0;

	for (int i = MAX_SIZE - 1; i >= 0; i--) 
	{
		rez.digits[i] += cb;

		cb = 0;

		if (rez.digits[i] > 9) {
			rez.digits[i] -= 10;
			cb++;
		}

		if (rez.digits[i] < 0) {
			rez.digits[i] += 10;
			cb--;
		}

	}

	update_length(rez);

	return rez;
}

BigInteger BigInteger::add(BigInteger const& A, int _case) const {

	BigInteger rez;

	BigInteger add1 = *this;

	BigInteger add2 = A;

	if (_case == -1) _case = addition_case(*this, add2);

	switch (_case)
	{
	case 0:

		abs(add1) > abs(add2) ? rez = add1 : rez = add2;

		break;

	case 1:

		rez = add_dig(add1, add2);

		rez = digitize(rez);

		rez.sign = +1;

		break;
	case 2:
		if (abs(add1) < abs(add2)) 
		{
			add1 = neg_dig(add1);

			rez = add_dig(add2, add1);

			rez = digitize(rez);

			rez.sign = +1;
		}
		else 
		{

			add2 = neg_dig(add2);

			rez = add_dig(add1, add2);

			rez = digitize(rez);

			rez.sign = -1;
		}
		break;
	case 3:

		if (abs(add1) > abs(add2)) 
		{
			add2 = neg_dig(add2);

			rez = add_dig(add1, add2);

			rez = digitize(rez);

			rez.sign = +1;
		}
		else 
		{
			add1 = neg_dig(add1);

			rez = add_dig(add2, add1);

			rez = digitize(rez);

			rez.sign = -1;
		}
		break;

	case 4:
		rez = add_dig(add1, add2);
		rez = digitize(rez);
		rez.sign = -1;
		break;

	default:
		return { "0" };
	}

	check_zero(rez);

	return rez;
}

BigInteger BigInteger::sub(const BigInteger& N) const {

	int _case = 0;
	if (this->sign == +1)
	{
		if (N.sign == +1)
			_case = 3;

		if (N.sign == -1)
			_case = 1;
	}
	if (this->sign == -1) 
	{
		if (N.sign == +1)
			_case = 4;

		if (N.sign == -1)
			_case = 2;
	}
	return this->add(N, _case);
}

int BigInteger::compare(const BigInteger& N) const {

	if (this->sign == 0) {

		if (N.sign != 0)
			return N.sign * -1;

		else
			return 0;
	}

	if (this->sign != N.sign)
		return this->sign;

	if (this->length < N.length)
		return -1 * this->sign;

	else if (this->length > N.length)
		return 1 * this->sign;

	else {
		for (int i = MAX_SIZE - this->length; i < MAX_SIZE; i++) 
		{
			if (this->length == 0)
				break;

			if (this->digits[i] > N.digits[i])
				return 1 * this->sign;

			if (this->digits[i] < N.digits[i])
				return -1 * this->sign;
		}
		return 0;
	}
}

std::string BigInteger::to_string() const {

	std::string str = "";
	
	if (this->length == 0)
		return "0";

	else 
	{

		if (this->sign == -1)
			str.push_back('-');

		for (int i = MAX_SIZE - this->length; i < MAX_SIZE; i++)
			str.push_back(this->digits[i] + '0');
	}

	return str;
}