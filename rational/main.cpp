//===============================================
// CS 173
// Fall 2024
// main.cpp
// This is the driver/test file for the Rational
// class
//===============================================

#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
    Rational r1(0, 3); // 0/3
    Rational r2(3);    // 3/1
    Rational r5(1, 8);
    Rational r3(0, 99);  // 0/1
    Rational r4(15, 27); // 5/9

    r1 = r5 + r4;

    return 0;
}