//========================================================
// CS 173
// main.cpp
// March 2024
// This file tests the complex class.
//========================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Complex.h"

int main(void)
{
    // basic constructor tests
    Complex c1(4, 2), c2(3.1, -1), c3;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;

    Complex c9(4);
    cout << "c9 = " << c9 << endl;
    c9 = -c1;
    cout << "c9 = " << c9 << endl;

    // addition tests
    c3 = c1 + c2;
    cout << "c3 = c1+c2 = " << c3 << endl;

    c3 = c1 + 7;
    cout << "c3 = c1+7 = " << c3 << endl;

    c3 = c1 + 7.7;
    cout << "c3 = c1+7.7 = " << c3 << endl;

    // subtraction tests
    c3 = c1 - c2;
    cout << "c3 = c1-c2 = " << c3 << endl;

    c3 = c1 - 7;
    cout << "c3 = c1-7 = " << c3 << endl;

    c3 = c1 - 7.7;
    cout << "c3 = c1-7.7 = " << c3 << endl;

    // multiplication
    c3 = c1 * c2;
    cout << "c3 = c1*c2 = " << c3 << endl;

    c3 = c1 * 7;
    cout << "c3 = c1*7 = " << c3 << endl;

    c3 = c1 * 7.7;
    cout << "c3 = c1*7.7 = " << c3 << endl;

    // conjugate test
    c3 = ~c1;
    cout << "c3 = ~c1 = " << c3 << endl;

    c3 = ~c2;
    cout << "c3 = ~c2 = " << c3 << endl;

    // division test
    c3 = c1 / c2;
    cout << "c3 = c1/c2 = " << c3 << endl;

    c3 = c1 / 2;
    cout << "c3 = c1/2 = " << c3 << endl;

    c3 = c1 / 2.2;
    cout << "c3 = c1/2.2 = " << c3 << endl;

    // exponentiation test
    c3 = c1 ^ 3;
    cout << c1 << "^" << 3 << " = " << c3 << endl;

    c3 = c1 ^ 0;
    cout << c1 << "^" << 0 << " = " << c3 << endl;

    c3 = c1 ^ -3;
    cout << c1 << "^" << -3 << " = " << c3 << endl;

    // abs test
    cout << "c1.abs() = " << c1.abs() << endl;

    // cin >> test
    cout << "Enter c3: ";
    cin >> c3;
    cout << c3 << endl;

    return 0;
}
