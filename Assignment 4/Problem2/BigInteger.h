#pragma once

#include<string>
#include<iostream>


class BigInteger {

public:
    BigInteger();

    BigInteger(std::string s);

    BigInteger(const BigInteger &other);

    ~BigInteger();

    BigInteger &operator=(const BigInteger &other);

    int sgn() const;

    friend BigInteger abs(BigInteger A);

    void negate();

    BigInteger &operator++();

    const BigInteger operator++(int t);

    friend std::ostream &operator<<(std::ostream &stream, const BigInteger &N);

    friend bool operator==(const BigInteger &A, const BigInteger &B);

    friend bool operator<(const BigInteger &A, const BigInteger &B);

    friend bool operator<=(const BigInteger &A, const BigInteger &B);

    friend bool operator>(const BigInteger &A, const BigInteger &B);

    friend bool operator>=(const BigInteger &A, const BigInteger &B);

    friend BigInteger operator+(const BigInteger &A, const BigInteger &B);

    friend BigInteger operator+=(BigInteger &A, const BigInteger &B);

    friend BigInteger operator-(const BigInteger &A, const BigInteger &B);

    friend BigInteger operator-=(BigInteger &A, const BigInteger &B);


private:
    int sign;
    int *digits;
    int length;

    

    BigInteger add(BigInteger const &, int = -1) const;

    BigInteger sub(const BigInteger &) const;

    int compare(const BigInteger &N) const;

    friend void update_length(BigInteger &);

    friend void check_zero(BigInteger &);

    friend short addition_case(const BigInteger &, const BigInteger &);

    friend BigInteger neg_dig(BigInteger const &);

    friend BigInteger add_dig(const BigInteger &, const BigInteger &);

    friend BigInteger digitize(BigInteger const &);

    std::string to_string() const;
};
