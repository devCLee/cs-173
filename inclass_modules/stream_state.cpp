//*********************************************************
// CS 173, Spring 2025
// StreamState program
// This program demonstrates testing the state of a stream
// TO-DO: test what happens when given the wrong file name
// TO-DO: update program to read from the file until no more
// input can be read
// Test this by adding more pairs of measurements to
// measures.dat
//*********************************************************
#include <fstream> // For file I/O
#include <iostream>
using namespace std;
int main()
{
  int height;
  int width;
  ifstream inFile; // Declare our stream

  inFile.open("measures.dat"); // Attempt to open file

  // inFile.open("measures.dat2"); // Wrong file name

  if (!inFile) // Was it opened?
  {
    cerr << "Can't open the input file."; // No--display message
    return 1;                             // Terminate program -- 1 signals failure
  }

  inFile >> height >> width;

  while (inFile)
  {

    cout << "For a height of " << height
         << " and a width of " << width
         << ", the area is " << height * width << endl;

    inFile >> height >> width;
  }

  return 0;
}
