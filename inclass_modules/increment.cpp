//*********************************************************
// CS 173, Spring 2025
// increment.cpp
// This program demonstrates the difference between passing
// by reference and passing by value. What do you think this
// program will output?
//*********************************************************
#include <iostream>
using namespace std;

int incrementByValue(int num);
int incrementByReference(int &num);

int main()
{
    int x = 1;
    int y;
    int z = 3;
    y = 1;

    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;
    cout << "Increment x by value: " << incrementByValue(x) << endl;
    cout << "Value now saved in x: " << x << endl;
    cout << "Increment y by reference: " << incrementByReference(y) << endl;
    cout << "Value now saved in y: " << y << endl;
    return 0;
}

// *********************************************************
// incrementByValue
// demonstrates pass by value
// Input: int num
// Returns: ______
// Side effects?
// *********************************************************
int incrementByValue(int num)
{
    return ++num; // Watch out for the difference with num++
}

// *********************************************************
// incrementByReference
// demonstrates pass by reference
// Input: int& num (what does this mean?)
// Returns: ______
//! Side effects? -> Changes the value stored in the memory address!
// *********************************************************
int incrementByReference(int &num)
{
    return ++num;
}