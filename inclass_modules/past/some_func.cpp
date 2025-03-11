//************************************************************
// CS 173, Spring 2025
// This program demonstrates global and local variables
//************************************************************
#include <iostream>
using namespace std;

void someFunc(float); // Function prototype!

const int A = 17;  // Global or local? 
int b;             // Global or local?  
int c;             // Global or local?

int main() {
  b = 4;  // Global or local?
  c = 6;  // Global or local?
  someFunc(42.8);
  cout << "b = " << b << endl; // Output???
  cout << "c = " << c << endl; // Output???
  return 0;
}

//*******************************************************
// someFunc()
// Outputs some values to demonstrate scope
// Parameters: float c
// Return: None
//*******************************************************
void someFunc(float c)  // Global or local?
{
  float b;  // Global or local?
  b = 2.3;

  cout << " A = " << A << endl;  // Output???
  cout << " b = " << b << endl;  // Output???
  cout << " c = " << c << endl;  // Output???
}
