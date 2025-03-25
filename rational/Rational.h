//======================================================
// CS 173
// Rational.h
// Fall 2024
// This file contains our Rational number class declaration.
//======================================================

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
using namespace std;

class Rational
{
public:
    // Constructors
    Rational();                  // Default constructor
    Rational(const Rational &r); // Copy constructor -- allows a user to create a Date object from another Date object
    Rational(int n, int d = 1);  // Parameterized constructor; default value of 1 for d

    // Destructor
    ~Rational();

    // Arithmetic operators
    Rational operator+(const Rational &r) const;
    Rational operator+(int n) const;
    Rational operator-(const Rational &r) const;
    Rational operator-(int i) const;
    Rational operator*(const Rational &r) const;
    Rational operator*(int i) const;
    Rational operator/(const Rational &r) const;
    Rational operator/(int i) const;
    Rational operator-() const;
    Rational operator^(int power) const;

    // Modifiers and Accessors
    void setNumerator(int n);
    int getNumerator() const;
    void setDenominator(int d);
    int getDenominator() const;
    void set(int n, int d);
    float getf() const;
    Rational abs() const;

    // Assignment operator
    Rational &operator=(const Rational &r);

    // Comparison operators
    bool operator==(const Rational &r) const;
    bool operator!=(const Rational &r) const;
    bool operator<(const Rational &r) const;
    bool operator<=(const Rational &r) const;
    bool operator>(const Rational &r) const;
    bool operator>=(const Rational &r) const;

    // Friend functions for I/O operations
    friend std::ostream &operator<<(std::ostream &os, const Rational &r);
    friend std::istream &operator>>(std::istream &is, Rational &r);

private:
    // data members
    int numerator;
    int denominator;
    void normalize();
    int gcd(int a, int b);
};

// Non-member operator functions for operations with int on the left side
Rational operator+(int i, const Rational &r);
Rational operator-(int i, const Rational &r);
Rational operator*(int i, const Rational &r);
Rational operator/(int i, const Rational &r);

#endif