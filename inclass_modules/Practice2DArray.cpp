//=============================================================
// CS 173
// Practice2DArray.cpp
// Fall 2024
// Some practice problems for 2D arrays
// TO-DO: implement printArray, minValue, smallestColSumIndex,
// and areRowsIncreasing functions
// To think about: could typedef help us here?
//=============================================================

#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

const int ROWS = 4;
const int COLS = 5;

void printArray(int array[ROWS][COLS]);
int minValue(int array[ROWS][COLS]);
int smallestColSumIndex(int array[ROWS][COLS]);
bool areRowsIncreasing(int array[ROWS][COLS]);

int main(void)
{
   int a[ROWS][COLS] = {{1, 2, 3, 4, 5},
                        {2, 3, 4, 5, 6},
                        {4, 5, 6, 7, 8},
                        {3, 4, 5, 6, 7}};

   int b[ROWS][COLS] = {{1, 2, 3, 4, 5},
                        {4, 5, 6, 7, 8},
                        {1, 2, 3, 4, 5},
                        {8, 4, 5, 5, 7}};

   // test array printing
   cout << "Array a: \n";
   printArray(a);
   cout << "Array b: \n";
   printArray(b);

   // test findMin
   cout << "Min of a = " << minValue(a) << endl;
   cout << "Min of b = " << minValue(b) << endl;

   // test smallestColSumIndex
   cout << "Min colsum index of a = " << smallestColSumIndex(a) << endl;
   cout << "Min colsum index of b = " << smallestColSumIndex(b) << endl;

   // test smallestColSumIndex
   cout << "areRowsIncreasing for a = " << areRowsIncreasing(a) << endl;
   cout << "areRowsIncreasing for b = " << areRowsIncreasing(b) << endl;
}

//=============================================================
// printArray
// PARAMETERS:
// Array of size ROWS x COLS where these array sizes
// are global variables.  Array type is integer.
// RETURN VALUE: none, but prints to the screen.
//=============================================================

void printArray(int array[ROWS][COLS])
{
   for (int i = 0; i < ROWS; i++)
   {
      for (int j = 0; j < COLS; j++)
      {
         cout << array[i][j] << " ";
      }
      cout << endl;
   }

   return;
}

//=============================================================
// minValue
// PARAMETERS:
// Array of size ROWS x COLS where these array sizes
// are global variables.  Array type is integer.  Assumes array
// is not empty (ROWS>0, COLS>0)
// RETURN VALUE: the smallest value in the whole array
//=============================================================
//! 퀴즈 출제 요소!!!!!
int minValue(int array[ROWS][COLS])
{
   int minValue = array[0][0];

   for (int i = 0; i < ROWS; i++)
   {
      for (int j = 0; j < COLS; j++)
      {
         if (minValue > array[i][j])
         {
            minValue = array[i][j];
         }
      }
   }

   return minValue;
}

//=============================================================
// smallestColSumIndex
// PARAMETERS:
// Array of size ROWS x COLS where these array sizes
// are global variables.  Array type is integer.  Assumes array
// is not empty (ROWS>0, COLS>0)
// RETURN VALUE: This function computes the sum of all columns,
// then returns the index of the column with the smallest sum
//=============================================================
int smallestColSumIndex(int array[ROWS][COLS])
{
   // int colSums[COLS];
   //
   // for (int j = 0; j < COLS; j++)
   //{
   //   int elts = 0;
   //
   //   for (int i = 0; i < ROWS; i++)
   //   {
   //      elts += array[i][j];
   //   }
   //   colSums[j] = elts;
   //}
   //
   // for (int i = 0; i < COLS; i++)
   //{
   //   cout << colSums[i] << " ";
   //}
   //
   // cout << endl;
   //
   // int minSumColIndex = 0;
   // for (int i = 1; i < COLS; i++)
   //{
   //   if (colSums[i] < colSums[minSumColIndex])
   //   {
   //      minSumColIndex = i;
   //   }
   //}

   int min = INT_MAX;
   int minIndex = -1;

   for (int j = 0; j < COLS; j++)
   {
      int sum = 0;

      for (int i = 0; i < ROWS; i++)
      {
         sum += array[i][j];
      }

      cout << "Sum of items in column: " << j << ": " << sum << endl;

      if (sum <= min)
      {
         min = sum;
         minIndex = j;
         cout << "Found a new min: " << min << " at column " << minIndex << endl;
      }
   }

   return minIndex;
}

//=============================================================
// areRowsIncreasing
// PARAMETERS:
// Array of size ROWS x COLS where these array sizes
// are global variables.  Array type is integer.
// RETURN VALUE: true if for every row in the matrix, the values
// across the row are strictly monotonically increasing (never
// decreasing or staying constant).
//=============================================================
bool areRowsIncreasing(int array[ROWS][COLS])
{
   for (int i = 0; i < ROWS; i++)
   {
      for (int j = 0; j < COLS - 1; j++)
      {
         if (array[i][j] > array[i][j + 1])
         {
            return false;
         }
      }
   }
   return true;
}
