//========================================================
// Project 8 Group 3: Daniel Lee, Ashwath Pratheep, Yuta Itani
// April 3, 2025
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
// Author: Daniel Lee
// Initializes a default Complex object of complex number 0 + 0i
// Parameters: None
// Return Value: None
//========================================================
Complex::Complex()
{
    a = 0;
    b = 0;
}
//========================================================
// Copy Constructor
// Author: Ashwath Pratheep
// Creates a new Complex object as a copy of another.
// parameter c - the Complex object to copy
// Return:
//   none
//========================================================
Complex::Complex(const Complex &c)
{
    a = c.a;
    b = c.b;
}
//========================================================
// Complex(a,b) constructor
// Author: Yuta Itani
// Constructor that sets the real and imaginary value.
// Parameters:
//   x: float that is real value of the complex number
//   y: float - imaginary value of the complex number
// Return:
//   none
//========================================================
Complex::Complex(float x, float y)
{
    a = x;
    b = y;
}
//========================================================
// destructor
// Author: Yuta Itani
// Destroys the complex number object
// Parameters: none
// Return: none
//========================================================
Complex::~Complex()
{
}
//========================================================
// setReal access method
// Author: Daniel Lee
// Sets the real number part of the complex number
// Parameters:
//        r: a float that is the real part of the complex number
// Return Value: None
//========================================================
void Complex::setReal(float r)
{
    a = r;
}
//========================================================
// getReal
// Author: Ashwath Pratheep
// Returns the real part of the complex number.
// parameters - float - the real part of the complex number
// Return:
//     a: the real part of the complex number.
//========================================================
float Complex::getReal() const
{
    return a;
}
//========================================================
// setImag
// Author: Yuta Itani
// It sets the imaginary value
// Parameters:
//   r that is float as new imaginary value
// Return:
//   none
//========================================================
void Complex::setImag(float r)
{
    b = r;
}
//========================================================
// getImag
// Author: Daniel Lee
// Gets the imaginary number part of the complex number
// Parameters:
//        None
// Return Value:
//        b: a float as the imaginary part of the complex number
//========================================================
float Complex::getImag() const
{
    return b;
}
//========================================================
// assignment operator
// Author: Daniel Lee
// Assigns the value of another complex number object to the object that we are intending to assign to
// Parameters:
//        const Complex &c: a complex number object
// Return Value:
//        A reference to this complex number
//========================================================
Complex Complex::operator=(const Complex &c)
{
    a = c.a;
    b = c.b;
    return *this;
}
//========================================================
// addition operator
// Author: Daniel Lee
// Adds two complex numbers
// Parameters:
//        const Complex &c: a complex number object
// Return Value:
//        the result object of addition of two complex numbers
//========================================================
Complex Complex::operator+(const Complex &c) const
{
    return Complex(a + c.a, b + c.b);
}
//========================================================
// operator+
// Author: Ashwath Pratheep
// Adds a float to the real part of the complex number.
//  parameter f - the float value to add
//  Returns: a new Complex object with updated real part
//========================================================
Complex Complex::operator+(float f) const
{
    return Complex(a + f, b);
}
//========================================================
// addition operator
// Author: Yuta Itani
// Adds an integer to the real value
// Parameters:
//   i is integer that is added
// Return:
//   Complex is final complex number
//========================================================
Complex Complex::operator+(int i) const
{
    return Complex(a + i, b);
}
//========================================================
// operator-
// Author: Ashwath Pratheep
// Subtracts another Complex number from this one.
// parameter c - the Complex number to subtract
// Returns: a new complex object representing the difference.
//========================================================
Complex Complex::operator-(const Complex &c) const
{
    return Complex(a - c.a, b - c.b);
}
//========================================================
// subtraction operator
// Author: Daniel Lee
// Subtracts a float from a complex number
// Parameters:
//        f: the float that will be used to subtract
// Return Value:
//        the result object of subtracting a float from a complex number
//========================================================
Complex Complex::operator-(float f) const
{
    Complex res;

    res.a = a - f;
    res.b = b;

    return res;
}
//========================================================
// subtraction operator
// Author: Yuta Itani
// Subtracts an integer from the real value
// Parameters:
//   i: integer that will be subtracted
// Return:
//   Complex: final complex number
//========================================================
Complex Complex::operator-(int i) const
{
    return Complex(a - i, b);
}
//========================================================
// operator*
// Author: Ashwath Pratheep
// Multiplies this Complex number with another.
// parameter c - the Complex number to multiply with
// Returns: a new Complex object representing the product
//========================================================
Complex Complex::operator*(const Complex &c) const
{
    float real = (a * c.a) - (b * c.b); // ac - bd; (a+bi)(c+di)
    float imag = (a * c.b) + (b * c.a); // bc + ad; (a+bi)(c+di)
    return Complex(real, imag);
}
//========================================================
// multiplication operator
// Author: Yuta Itani
// Multiplies real and imaginary values with float
// Parameters:
//   f: float that is multiplied with
// Return:
//   Complex: final complex number
//========================================================
Complex Complex::operator*(float f) const
{
    return Complex(a * f, b * f);
}
//========================================================
// multiplication operator
// Author: Daniel Lee
// Multiplies a complex number by an int
// Parameters:
//        i: the int value to multiply by
// Return Value:
//        the result object of multiplying a complex number by an int
//========================================================
Complex Complex::operator*(int i) const
{
    Complex res;

    res.a = a * i;
    res.b = b * i;

    return res;
}
//========================================================
// division operator
// Author: Yuta Itani
// Dividing complex number
// Parameters:
//   c: the divisor
// Return:
//   Complex: final result of the division
//========================================================
Complex Complex::operator/(const Complex &c) const
{
    if (c.a == 0 && c.b == 0)
    {
        throw runtime_error("Zero devision error occurred!\n");
    }

    float denominator = c.a * c.a + c.b * c.b;
    float realPart = (a * c.a + b * c.b) / denominator;
    float imagPart = (b * c.a - a * c.b) / denominator;

    return Complex(realPart, imagPart);
}
//========================================================
// operator/
// Author: Ashwath Pratheep
// Divides this Complex number by a float.
// parameter f - the float divisor
// Returns: a new Complex object representing the quotient
//========================================================
Complex Complex::operator/(float f) const
{
    if (f == 0)
    {
        throw runtime_error("Zero devision error occurred!\n");
    }

    return Complex(a / f, b / f);
}
//========================================================
// division operator
// Author: Daniel Lee
// Divides a complex number by an int
// Parameters:
//        i: the int value to divide by
// Return Value:
//        the result object of dividing a complex number by an int
//========================================================
Complex Complex::operator/(int i) const
{
    Complex res;

    if (i == 0)
    {
        throw runtime_error("Zero devision error occurred!\n");
    }

    res.a = a / i;
    res.b = b / i;

    return res;
}
//========================================================
// exponentiation
// Author: Daniel Lee
// Operates exponentiation on a complex number
// Parameters:
//        p: the power value for exponentiation
// Return Value:
//        the result object of exponentiation
//========================================================
Complex Complex::operator^(int p) const
{
    Complex res(1, 0);

    if (p == 0)
    {
        return res;
    }
    else if (p > 0)
    {
        for (int i = 0; i < p; i++)
        {
            res = res * (*this);
        }
    }
    else
    {
        if (this->a == 0 && this->b == 0)
        {
            throw runtime_error("Zero devision error occurred!\n");
        }

        Complex reciprocalNum = Complex(1, 0) / (*this);

        for (int i = 0; i < -p; i++)
        {
            res = res * reciprocalNum;
        }
    }

    return res;
}
//========================================================
// operator~
// Author: Daniel Lee
// Operates conjugation on a complex number
// Parameters:
//        None
// Return Value:
//        the result object of conjugation
//========================================================
Complex Complex::operator~() const
{
    Complex res;

    res.a = a;
    res.b = -b;

    return res;
}
//========================================================
// Unary negation operator
// Author: Ashwath Pratheep
// Returns the negation of the Complex number.
// Returns: a new Complex object with both parts negated
//========================================================
Complex Complex::operator-() const
{
    return Complex(-a, -b);
}
//========================================================
// abs
// Author: Yuta Itani
// It calculates the magnitude of the complex number
// Parameters: none
// Return:
//   float - magnitude = sqrt(a^2 + b^2)
//========================================================
float Complex::abs() const
{
    return sqrt(a * a + b * b);
}
//========================================================
// operator==
// Author: Ashwath Pratheep
// Compares two Complex numbers for equality.
// parameter c - the Complex number to compare with
// Returns: True if both real and imaginary parts are equal
//========================================================
bool Complex::operator==(const Complex &c) const
{
    return (a == c.a) && (b == c.b);
}
//========================================================
// inequality operator
// Author: Yuta Itani
// It checks whether two complex numbers are not equal or
// not
// Parameters:
//   c is complex number for comparing
// Return:
//   if real or imaginary values are different, true will
// returned
//========================================================
bool Complex::operator!=(const Complex &c) const
{
    return (a != c.a || b != c.b);
}
//========================================================
// operator>>
// Author: Ashwath Pratheep
// Overloads the >> operator to read a Complex number
// in the format (real, imaginary).
// parameter is - input stream
// parameter c - Complex object to populate
// Returns: reference to input stream
//========================================================
istream &operator>>(istream &is, Complex &c)
{
    char charSign;
    float real = 0, imag = 0;

    if (is >> real) //! read the real nums
    {
        //! read the sign
        if (is.get(charSign))
        {
            if (charSign == '+' || charSign == '-') //! Format: a+bi or a-bi or a+i or a-i
            {
                char sign = charSign;

                //! read a number after the sign
                float imagTemp;
                if (is >> imagTemp) //! Format: a+bi or a-bi
                {
                    //! read 'i'
                    if (is.get(charSign) && charSign == 'i')
                    {
                        //! Success: read format a+bi or a-bi
                        if (sign == '+')
                        {
                            imag = imagTemp;
                        }
                        else
                        {
                            imag = -imagTemp;
                        }
                    }
                    else
                    {
                        //! Invalid format: No 'i' after the number
                    }
                }
                else //! No number after sign, check for the format: a+i or a-i
                {
                    is.clear(); //! failed reading number -> Should clear fail state

                    //! read 'i'
                    if (is.get(charSign) && charSign == 'i')
                    {
                        //! Success: read format a+i or a-i
                        if (sign == '+')
                        {
                            imag = 1;
                        }
                        else
                        {
                            imag = -1;
                        }
                    }
                    else
                    {
                        //! Invalid format: No 'i' after the sign
                    }
                }
            }
            else if (charSign == 'i') //! Format: ai
            {
                imag = real;
                real = 0;
            }
        }
        //! Just a real number if no sign after real -> At this state, real is alread assigned with input?
    }
    else //! failed reading number -> consider when there is only 'i'
    {
        is.clear(); //! failed reading number -> Should clear fail state

        if (is.get(charSign))
        {
            if (charSign == 'i') //! Format: i
            {
                real = 0;
                imag = 1;
            }
            else if (charSign == '+' || charSign == '-') //! Format: +i or -i
            {
                char sign = charSign;

                if (is.get(charSign) && charSign == 'i')
                {
                    real = 0;

                    if (sign == '+')
                    {
                        imag = 1;
                    }
                    else //!!!!!!! Errors on -i
                    {
                        imag = -1;
                    }
                }
                else
                {
                    //! Invalid format: No 'i' found
                }
            }
            else
            {
                //! Invalid format of complex number
            }
        }
    }

    if (!is.fail())
    {
        c.setReal(real);
        c.setImag(imag);
    }

    return is;
}
//========================================================
// overload << for cout
// Author: Yuta Itani
// It makes outputs of the complex number
// Parameters:
//   os: the output stream
//   c: the complex number for printing
// Return:
//   ostream&: the stream after printing
//========================================================
ostream &operator<<(ostream &os, const Complex &c)
{
    if (c.b == 0)
    {
        os << c.a;
    }
    else if (c.a == 0)
    {
        if (c.b == 1)
        {
            os << "i";
        }
        else if (c.b == -1)
        {
            os << "-i";
        }
        else
        {
            os << c.b << "i";
        }
    }
    else
    {
        os << c.a;

        if (c.b > 0)
        {
            if (c.b == 1)
            {
                os << "+i";
            }
            else
            {
                os << "+" << c.b << "i";
            }
        }
        else
        {
            if (c.b == -1)
            {
                os << "-i";
            }
            else
            {
                os << c.b << "i";
            }
        }
    }

    return os;
}
