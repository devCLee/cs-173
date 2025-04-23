//========================================================
// put all group names here
// Complex.cpp
// Spring 2025
// This file contains the class methods for the
// Complex number class.
//========================================================

#include "Complex.h"
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

//========================================================
// default constructor
//========================================================

//========================================================
// copy constructor
//========================================================

//========================================================
// Complex(a,b) constructor
// Complex::Complex(float x, float y)
// Constructor that sets the real and imaginary value.
// Parameters:
//   x: float that is real value of the complex number
//   y: float - imaginary value of the complex number
// Return:
//   none 
//========================================================
Complex::Complex(float x, float y) {
    a = x;
    b = y;
}
//========================================================
// destructor
// Complex::~Complex()
// Parameters: none
// Return: none
//========================================================
Complex::~Complex() {

}
//========================================================
// setReal access method
//========================================================

//========================================================
// getReal access method
//========================================================

//========================================================
// setImag
// void Complex::setImag(float r)
// It sets the imaginary value
// Parameters:
//   r that is float as new imaginary value
// Return:
//   none
//========================================================
void Complex::setImag(float r) {
    b = r;
}
//========================================================
// getImag
//========================================================

//========================================================
// assignment operator
// bool Complex::operator!=(const Complex& c) const
// It checks whether two complex numbers are not equal or 
// not
// Parameters:
//   c is complex number for comparing
// Return:
//   if real or imaginary values are different, true will
// returned
//========================================================
bool Complex::operator!=(const Complex& c) const {
    return (a != c.a || b != c.b);
}
//========================================================
// addition operators
// Complex Complex::operator+(int i) const 
// Adds an integer to the real value
// Parameters:
//   i is integer that is added
// Return:
//   Complex is final complex number
//========================================================
Complex Complex::operator+(int i) const {
    return Complex(a + i, b);
}

//========================================================
// subtraction operators
// Complex Complex::operator-(int i) const
// Subtracts an integer from the real value
// Parameters:
//   i: integer that will be subtracted
// Return:
//   Complex: final complex number
//========================================================
Complex Complex::operator-(int i) const {
    return Complex(a - i, b);
}

//========================================================
// multiplication operators
// Complex Complex::operator*(float f) const
// Multiplies real and imaginary values with float
// Parameters:
//   f: float that is multiplied with
// Return:
//   Complex: final complex number
//========================================================
Complex Complex::operator*(float f) const {
    return Complex(a * f, b * f);
}
//========================================================
// division operators
// Complex Complex::operator/(const Complex& c) const
// Dividing complex number
// Parameters:
//   c: the divisor
// Return:
//   Complex: final result of the division
//========================================================
Complex Complex::operator/(const Complex& c) const {
    float denominator = c.a * c.a + c.b * c.b;
    float realPart = (a * c.a + b * c.b) / denominator;
    float imagPart = (b * c.a - a * c.b) / denominator;
    return Complex(realPart, imagPart);
}
//========================================================
// exponentiation
//========================================================

//========================================================
// operator~
//========================================================

//========================================================
// abs
// float Complex::abs() const
// It calculates the magnitude of the complex number
// Parameters: none
// Return:
//   float - magnitude = sqrt(a^2 + b^2)
//========================================================
float Complex::abs() const {
    return sqrt(a * a + b * b);
}
//========================================================
// equality operator
//========================================================

//========================================================
// inequality operator
//========================================================

//========================================================
// overload >> for cin
//========================================================

//========================================================
// overload << for cout
// ostream& operator<<(ostream& os, const Complex& c)
// It makes outputs of the complex number
// Parameters:
//   os: the output stream
//   c: the complex number for printing
// Return:
//   ostream&: the stream after printing
//========================================================
ostream& operator<<(ostream& os, const Complex& c) {
    if (c.b == 0)
        os << c.a;
    else if (c.a == 0)
        os << c.b << "i";
    else if (c.b == 1)
        os << c.a << "+i";
    else if (c.b == -1)
        os << c.a << "-i";
    else if (c.b < 0)
        os << c.a << c.b << "i";
    else
        os << c.a << "+" << c.b << "i";

    return os;
}