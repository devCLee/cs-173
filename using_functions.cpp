//=========================================================
// CS 173, Spring 2025
//
// This program demonstrates function definitions and
// input/output.
//
// TO-DO: take input from the command line (an integer to
// pass to square() and cube())

// TO-DO: try with different inputs -- can you find points
// where overflow occurs? What range of inputs are valid?

// TO-DO: write a helper function that returns true if input
// is valid, false otherwise
// TO-DO: make each function return -1 if input is invalid
// Thought exercise: what happens if the user enters
// something other than an integer?
//=========================================================

//! 2^31 - 1
//! Safe bound: ~ 2^30 = 2^10 * 2^10 * 2^10 = 1024^3
//! Typically, integers are stored as 4 bytes (32 bits). This means that in almost all machines, the maximum integer value will be 2^(31) - 1 = +2147483647.

#include <iostream> // preprocessor directives

using namespace std; // lets us use identifiers defined in std

int square(int); // function prototypes -- come before main()
int cube(int);   // tell us what functions are defined in the program & return & parameter types
int checkValid(int, int);
int checkValid2(int, int);

int main()
{
  int squareParam;
  int cubeParam;

  cin >> squareParam;
  cin >> cubeParam;

  checkValid(squareParam, cubeParam);

  checkValid2(squareParam, cubeParam);

  cout << "The square of input is " << square(squareParam) << endl;
  cout << "and the cube of input is " << cube(cubeParam) << endl;
  return 0; // what does returning 0 from main mean?
}

//=========================================================
// square
// Computes and returns the square of an integer
// Parameter:
//    n, the integer to be squared
// Return:
//    n^2
//=========================================================
int square(int n)
{
  return n * n;
}

//=========================================================
// cube
// Computes and returns the cube of an integer
// Parameter:
//    n, the integer to be cubed
// Return:
//    n^3
//=========================================================
int cube(int n)
{
  return n * n * n;
}

int checkValid(int i, int j)
{

  bool res = true;

  if (i > 46340 || j > 1290)
  {
    res = false;
    return res;
  }
  else
  {
    return res;
  }
}

int checkValid2(int i, int j)
{

  bool res = true;

  if (i > 46340 || j > 1290)
  {
    res = false;
    return -1;
  }
  else
  {
    return res;
  }
}