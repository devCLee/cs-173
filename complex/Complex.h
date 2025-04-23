//========================================================
// CS 173
// Complex.h
// Spring 2025
// This file contains the class declaration for the
// Complex number class.
// DO NOT CHANGE THIS FILE!!!
//========================================================

#include <iostream>
using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
   Complex();
   Complex(const Complex &c);
   Complex(float x, float y = 0);
   ~Complex();
   void setReal(float r);
   float getReal() const;
   void setImag(float r);
   float getImag() const;
   Complex operator=(const Complex &c);
   Complex operator+(const Complex &c) const;
   Complex operator+(float f) const;
   Complex operator+(int i) const;
   Complex operator-(const Complex &c) const;
   Complex operator-(float f) const;
   Complex operator-(int i) const;
   Complex operator*(const Complex &c) const;
   Complex operator*(float f) const;
   Complex operator*(int i) const;
   Complex operator/(const Complex &c) const;
   Complex operator/(float f) const;
   Complex operator/(int i) const;
   Complex operator~() const;
   Complex operator^(int p) const;
   float abs() const;
   Complex operator-() const;
   bool operator==(const Complex &c) const;
   bool operator!=(const Complex &c) const;

   friend ostream &operator<<(ostream &os, const Complex &c);
   friend istream &operator>>(istream &is, Complex &c);

private:
   float a; // number = a + bi
   float b;
};

#endif
