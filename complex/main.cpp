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
    cout << "c1 = " << c1 << endl; // 4+2i
    cout << "c2 = " << c2 << endl; // 3.1-i
    cout << "c3 = " << c3 << endl; // 0

    Complex c4(c1);
    cout << c4 << endl;

    c1.setReal(5);

    cout << c1 << endl;

    float f = c1.getReal();

    cout << f << endl;

    c1.setImag(5);

    cout << c1 << endl;

    float k = c1.getImag();

    cout << k << endl;

    // Complex c9(4);
    // cout << "c9 = " << c9 << endl; // 4
    // c9 = -c1;
    // cout << "c9 = " << c9 << endl; // -4-2i
    //
    //// addition tests
    // c3 = c1 + c2;
    // cout << "c3 = c1+c2 = " << c3 << endl; // 7.1+i
    //
    // c3 = c1 + 7;
    // cout << "c3 = c1+7 = " << c3 << endl; // 11+2i
    //
    // c3 = c1 + (float)7.7;
    // cout << "c3 = c1+7.7 = " << c3 << endl; // 11.7+2i
    //
    //// subtraction tests
    // c3 = c1 - c2;
    // cout << "c3 = c1-c2 = " << c3 << endl; // 0.9+3i
    //
    // c3 = c1 - 7;
    // cout << "c3 = c1-7 = " << c3 << endl; // -3+2i
    //
    // c3 = c1 - (float)7.7;
    // cout << "c3 = c1-7.7 = " << c3 << endl; // -3.7+2i
    //
    //// multiplication
    // c3 = c1 * c2;
    // cout << "c3 = c1*c2 = " << c3 << endl; // 14.4+2.2i
    //
    // c3 = c1 * 7;
    // cout << "c3 = c1*7 = " << c3 << endl; // 28+14i
    //
    // c3 = c1 * (float)7.7;
    // cout << "c3 = c1*7.7 = " << c3 << endl; // 30.8+15.4i
    //
    //// conjugate test
    // c3 = ~c1;
    // cout << "c3 = ~c1 = " << c3 << endl; // 4-2i
    //
    // c3 = ~c2;
    // cout << "c3 = ~c2 = " << c3 << endl; // 3.1+i
    //
    //// division test
    // c3 = c1 / c2;
    // cout << "c3 = c1/c2 = " << c3 << endl; // 0.980207+0.961357i
    //
    // c3 = c1 / 2;
    // cout << "c3 = c1/2 = " << c3 << endl; // 2+i
    //
    // c3 = c1 / (float)2.2;
    // cout << "c3 = c1/2.2 = " << c3 << endl; // 1.81818+0.909091i
    //
    //// exponentiation test
    // c3 = c1 ^ 3;
    // cout << c1 << "^" << 3 << " = " << c3 << endl; // 16+88i
    //
    // c3 = c1 ^ 0;
    // cout << c1 << "^" << 0 << " = " << c3 << endl; // 1
    //
    // c3 = c1 ^ -3;
    // cout << c1 << "^" << -3 << " = " << c3 << endl; // 0.002-0.011i
    //
    //// abs test
    // cout << "c1.abs() = " << c1.abs() << endl; // 4.47214
    //
    //// cin >> test
    // cout << "Enter c3: ";
    // cin >> c3;          // 5+5i
    // cout << c3 << endl; // 5+5i

    return 0;
}
