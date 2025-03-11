//=========================================================
// Daniel Lee
// February 7, 2025
// DLee_cs173_project3.cpp
// This program runs Euclid's algorithm for finding the GCD of two natural numbers, num_a and num_b.
// It checks if num_b is 0 and if so, num_a is the GCD.
// Otherwise, the GCD of num_a and num_b is the GCD of num_b and (num_a mod num_b).
// This C++ program reads in two integer inputs (num_a and num_b) and outputs the GCD of num_a and num_b.
//=========================================================

#include <iostream>

using namespace std;

int gcd(int, int); // function prototypes -- come before main()

int main()
{
    int num_a;
    int num_b;
    bool repeat = true;

    while (repeat)
    {
        cin >> num_a >> num_b;
        // cin >> num_b;

        if (cin.fail()) // Check if cin is in the FAIL STATE
        {
            cin.clear();              // Clear the error state of cin
            cin.ignore(100000, '\n'); // Ignore any invalid input left in the buffer

            cerr << "Each input should be a non-negative integer! Your input is not an integer! Try again giving two valid inputs!" << endl;
        }
        else
        {
            if (num_a < 0 || num_b < 0)
            {
                cerr << "Each input should be a non-negative integer! Your input contains one or more negative integer! Try again giving two valid inputs!" << endl;
            }
            else
            {
                repeat = false;
            }
        }
    }

    cout << gcd(num_a, num_b) << endl;

    return 0;
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
int gcd(int num_a, int num_b)
{

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
}