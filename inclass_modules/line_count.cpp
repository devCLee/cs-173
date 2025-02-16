//****************************************************
// CS 173, Spring 2025
// Program reads a file and outputs the line number
// and the number of characters in the line
//****************************************************
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void letterCount(string line, int count);

void lineCount(istream &file, int &count);

int main()
{
  ifstream inFile;
  inFile.open("test.dat");
  int count = 0;
  lineCount(inFile, count);
  cout << "Number of lines: " << count << endl;
  return 0;
}

//*****************************************************
// letterCount
// The number of characters in line is output
// Parameters: a string representing one line of text,
//             an int count
// Return: none
// Side effects?
//*****************************************************
void letterCount(string line, int count) //!  int &count
{
  count = line.length();
  cout << " has " << count << " characters. " << endl;
}

//*****************************************************
// lineCount
// Calculates the number of lines in a file
// Parameters: an istream object called file,
//             an int count
// Return: none
// Side effects? How does the count get passed back?
//*****************************************************
void lineCount(istream &file, int &count)
{
  string line;
  getline(file, line);

  while (file)
  {
    count++;
    cout << "Line " << count;
    letterCount(line, count);
    getline(file, line);
  }
}
