//======================================================
// CS173
// Rational.cpp
// March 2024
// This file contains our Rational number class function
// definitions.
//======================================================

#include "Rational.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cmath>
using namespace std;

// Constructors

// Rational(n,d)
// Input: int n, optional int d
// Set numerator to n, set deonminator to d (or 1)
// Input: int n, optional int d
// Convert to simplest representation

Rational::Rational()
{
}

Rational::Rational(int n, int d)
{
    numerator = n;
    denominator = d;

    normalize();

    cout << "Newly created Rational: " << numerator << "/" << denominator << endl;
}

// Copy constructor
Rational::Rational(const Rational &r)
{
    numerator = r.numerator;
    denominator = r.denominator;
}

// Destructor
Rational::~Rational()
{
    // Nothing special to clean up
}

//=================================================
// gcd
// This function takes two integers as parameters, computes the GCD following Euclid's algorithm, and returns the value of the GCD.
// Parameters:
//      num_a: a non-negative integer.
//      num_b: a non-negative integer.
// Return Value:
//      An integer, which is the value of the GCD of two non-negative integers from the input.
//=================================================
int Rational::gcd(int num_a, int num_b)
{
    num_a = std::abs(num_a);
    num_b = std::abs(num_b);

    if (num_b == 0)
    {
        return num_a;
    }

    while (num_b != 0)
    {
        int temp = num_b;
        num_b = num_a % num_b;
        num_a = temp;
    }

    return num_a;

    // if (b == 0){
    // return a;
    // }
    //
    // return gcd(b, a%b)
}

void Rational::normalize()
{
    if (denominator == 0)
    {
        throw runtime_error("Rational number denominator should not be 0!\n");
    }
    else if (denominator < 0) // flip the signs to make denominator positive!
    {
        // Move negative sign to numerator
        numerator = -numerator;
        denominator = -denominator;
    }
    if (numerator == 0)
    {
        denominator = 1;
        return;
    }
    else
    {
        int divisor = gcd(std::abs(numerator), denominator);

        // numerator /= denominator;

        if (divisor > 1)
        {
            numerator /= divisor;
            denominator /= divisor;
        }
    }
}

// Addition with Rational
Rational Rational::operator+(const Rational &r) const
{
    int d = denominator * r.denominator;
    int n = denominator * r.numerator + r.denominator * numerator;

    Rational result(n, d);

    return result;
}

// Addition with int
Rational Rational::operator+(int n) const
{
    return *this + Rational(n);

    // int d = denominator;
    // int n = denominator * n + numerator;
    //
    // Rational result(n, d);
    //
    // return result;
}

// Subtraction with Rational
Rational Rational::operator-(const Rational &r) const
{
    return Rational(
        numerator * r.denominator - r.numerator * denominator,
        denominator * r.denominator);
}

// Subtraction with int
Rational Rational::operator-(int i) const
{
    return *this - Rational(i);
}

// Multiplication with Rational
Rational Rational::operator*(const Rational &r) const
{
    return Rational(
        numerator * r.numerator,
        denominator * r.denominator);
}

// Multiplication with int
Rational Rational::operator*(int i) const
{
    return *this * Rational(i);
}

// Division with Rational
Rational Rational::operator/(const Rational &r) const
{
    if (r.numerator == 0)
    {
        throw std::invalid_argument("Division by zero");
    }
    return Rational(
        numerator * r.denominator,
        denominator * r.numerator);
}

// Division with int
Rational Rational::operator/(int i) const
{
    if (i == 0)
    {
        throw std::invalid_argument("Division by zero");
    }
    return *this / Rational(i);
}

// Negation
Rational Rational::operator-() const
{
    return Rational(-numerator, denominator);
}

// Exponentiation
Rational Rational::operator^(int power) const
{
    if (power == 0)
    {
        return Rational(1);
    }

    if (power < 0)
    {
        // Negative power: invert the rational and negate the power
        if (numerator == 0)
        {
            throw std::invalid_argument("Cannot raise zero to a negative power");
        }
        return Rational(denominator, numerator) ^ (-power);
    }

    // For positive powers, compute directly
    int num = 1, den = 1;
    for (int i = 0; i < power; i++)
    {
        num *= numerator;
        den *= denominator;
    }

    return Rational(num, den);
}

// Set numerator
void Rational::setNumerator(int n)
{
    numerator = n;
    normalize();
}

// Get numerator
int Rational::getNumerator() const
{
    return numerator;
}

// Set denominator
void Rational::setDenominator(int d)
{
    if (d == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    denominator = d;
    normalize();
}

// Get denominator
int Rational::getDenominator() const
{
    return denominator;
}

// Set both numerator and denominator
void Rational::set(int n, int d)
{
    if (d == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    numerator = n;
    denominator = d;
    normalize();
}

// Convert to float
float Rational::getf() const
{
    return static_cast<float>(numerator) / denominator;
}

// Get absolute value
Rational Rational::abs() const
{
    return Rational(std::abs(numerator), denominator);
}

// Assignment operator
Rational &Rational::operator=(const Rational &r)
{
    if (this != &r)
    {
        numerator = r.numerator;
        denominator = r.denominator;
    }
    return *this;
}

// Equality operator
bool Rational::operator==(const Rational &r) const
{
    // Assuming both are already simplified
    return numerator == r.numerator && denominator == r.denominator;
}

// Inequality operator
bool Rational::operator!=(const Rational &r) const
{
    return !(*this == r);
}

// Less than operator
bool Rational::operator<(const Rational &r) const
{
    return numerator * r.denominator < r.numerator * denominator;
}

// Less than or equal operator
bool Rational::operator<=(const Rational &r) const
{
    return numerator * r.denominator <= r.numerator * denominator;
}

// Greater than operator
bool Rational::operator>(const Rational &r) const
{
    return numerator * r.denominator > r.numerator * denominator;
}

// Greater than or equal operator
bool Rational::operator>=(const Rational &r) const
{
    return numerator * r.denominator >= r.numerator * denominator;
}

// Output stream operator
std::ostream &operator<<(std::ostream &os, const Rational &r)
{
    if (r.denominator == 1)
    {
        os << r.numerator;
    }
    else if (r.numerator == 0)
    {
        os << 0;
    }
    else
    {
        os << r.numerator << "/" << r.denominator;
    }
    return os;
}

// Input stream operator
std::istream &operator>>(std::istream &is, Rational &r)
{
    std::string input;
    is >> input;

    // Parse the input
    size_t slashPos = input.find('/');
    if (slashPos != std::string::npos)
    {
        // Input is in the form "a/b"
        std::string numStr = input.substr(0, slashPos);
        std::string denStr = input.substr(slashPos + 1);

        int num, den;
        std::stringstream(numStr) >> num;
        std::stringstream(denStr) >> den;

        if (den == 0)
        {
            is.setstate(std::ios::failbit);
            return is;
        }

        r.set(num, den);
    }
    else
    {
        // Input is just "a"
        int num;
        std::stringstream(input) >> num;
        r.set(num, 1);
    }

    return is;
}

// Non-member binary operators with int on the left side
Rational operator+(int i, const Rational &r)
{
    return r + i;
}

Rational operator-(int i, const Rational &r)
{
    return Rational(i) - r;
}

Rational operator*(int i, const Rational &r)
{
    return r * i;
}

Rational operator/(int i, const Rational &r)
{
    return Rational(i) / r;
}