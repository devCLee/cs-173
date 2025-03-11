//=============================================================
// CS 173
// sudoku.cpp
// Spring 2025
// Some practice problems for 2D arrays
// TO-DO: implement checkBoxes, checkRows, and checkColumns to
// see if the solved puzzle is valid
//=============================================================

#include <iostream>
#include <iomanip>
using namespace std;

typedef int sudokuGrid[9][9]; // lets us refer to a 9x9 2D array of ints as a sudokuGrid

void printPuzzle(const sudokuGrid grid);
bool checkBoxes(const sudokuGrid grid);
bool checkBox(const sudokuGrid grid, int rowStart, int colStart);
bool checkRows(const sudokuGrid grid);
bool checkRow(const sudokuGrid grid, int rowIndex);
bool checkCols(const sudokuGrid grid);
bool checkCol(const sudokuGrid grid, int colIndex);

int main(void)
{

   sudokuGrid puzzle1 = {{4, 3, 5, 2, 6, 9, 7, 8, 1},
                         {6, 8, 2, 5, 7, 1, 4, 9, 3},
                         {1, 9, 7, 8, 3, 4, 5, 6, 2},
                         {8, 2, 6, 1, 9, 5, 3, 4, 7},
                         {3, 7, 4, 6, 8, 2, 9, 1, 5},
                         {9, 5, 1, 7, 4, 3, 6, 2, 8},
                         {5, 1, 9, 3, 2, 6, 8, 7, 4},
                         {2, 4, 8, 9, 5, 7, 1, 3, 6},
                         {7, 6, 3, 4, 1, 8, 2, 5, 9}};

   sudokuGrid puzzle2 = {{4, 3, 5, 2, 6, 9, 7, 8, 1},
                         {8, 8, 2, 5, 7, 1, 4, 9, 3}, // 8 is duplicated, 6 is missing
                         {1, 9, 7, 8, 3, 4, 5, 6, 2},
                         {8, 2, 6, 1, 9, 5, 3, 4, 7},
                         {3, 7, 4, 6, 8, 2, 9, 1, 5},
                         {9, 5, 1, 7, 4, 3, 6, 2, 8},
                         {5, 1, 9, 3, 2, 6, 8, 7, 4},
                         {2, 4, 8, 9, 5, 7, 1, 3, 6},
                         {7, 6, 3, 4, 1, 8, 2, 5, 9}};

   cout << "Puzzle 1:" << endl
        << endl;
   printPuzzle(puzzle1);

   cout << "Is this puzzle a valid solution? ";
   if (checkRows(puzzle1) && checkCols(puzzle1) && checkBoxes(puzzle1))
   {
      cout << "Yes" << endl
           << endl;
   }
   else
   {
      cout << "No" << endl
           << endl;
   }

   cout << "Puzzle 2:" << endl
        << endl;
   printPuzzle(puzzle2);

   cout << "Is this puzzle a valid solution? ";
   if (checkRows(puzzle2) && checkCols(puzzle2) && checkBoxes(puzzle2))
   {
      cout << "Yes" << endl
           << endl;
   }
   else
   {
      cout << "No" << endl
           << endl;
   }
}

//=============================================================
// printPuzzle
// PARAMETERS:
//    grid, a 9x9 2D array of ints representing a sudoku board
// RETURN VALUE: none, but prints to the screen.
//=============================================================

void printPuzzle(const sudokuGrid grid)
{
   cout << " ___________________________________" << endl; // top border
   for (int r = 0; r < 9; r++)
   {
      cout << "| "; // left border
      for (int c = 0; c < 9; c++)
      {
         cout << grid[r][c];
         if ((c + 1) % 3 == 0)
         {
            cout << " | ";
         }
         else
         {
            cout << "   ";
         }
      }
      cout << endl;
      if ((r + 1) % 3 == 0)
      {
         cout << "-------------------------------------" << endl;
      }
   }
}

//=============================================================
// checkBoxes
// checks whether all 3x3 boxes inside a sudoku grid are valid
// PARAMETERS:
//    grid, a 9x9 2D array of ints representing a sudoku board
// RETURN VALUE:
//    true if each box contains 1..9 each exactly once
//    false otherwise
//=============================================================
bool checkBoxes(const sudokuGrid grid)
{
   // Loop through all 9 boxes (3x3 grid of boxes)
   for (int rowStart = 0; rowStart < 9; rowStart += 3)
   {
      for (int colStart = 0; colStart < 9; colStart += 3)
      {
         if (!checkBox(grid, rowStart, colStart))
         {
            return false; // If any box is invalid, the grid is invalid
         }
      }
   }
   return true; // All boxes are valid
}

//=============================================================
// checkBox
// checks whether a 3x3 box inside a sudoku grid is valid
// PARAMETERS:
//    grid, a 9x9 2D array of ints representing a sudoku board
//    startRow, an int representing the start index for the rows
//       in the box being checked
//    startCol, an int representing the start index for the
//       columbns in the box being checked
// RETURN VALUE:
//    true if the box contains 1..9 each exactly once
//    false otherwise
//=============================================================

bool checkBox(const sudokuGrid grid, int rowStart, int colStart)
{
   // Use an array to track which numbers we've seen
   bool seen[10] = {false}; // Index 0 not used (valid numbers are 1-9)

   // Check all cells in the 3x3 box
   for (int row = rowStart; row < rowStart + 3; row++)
   {
      for (int col = colStart; col < colStart + 3; col++)
      {
         int num = grid[row][col];

         // Check if the number is valid (1-9)
         if (num < 1 || num > 9)
         {
            return false;
         }

         // Check if we've seen this number before in this box
         if (seen[num])
         {
            return false; // Duplicate found
         }

         // Mark this number as seen
         seen[num] = true;
      }
   }

   // Check if all numbers 1-9 are present
   for (int i = 1; i <= 9; i++)
   {
      if (!seen[i])
      {
         return false; // Missing a number
      }
   }

   return true; // All checks passed
}

//=============================================================
// checkRows
// checks whether all 9 rows inside a sudoku grid are valid
// PARAMETERS:
//    grid, a 9x9 2D array of ints representing a sudoku board
// RETURN VALUE:
//    true if each row contains 1..9 each exactly once
//    false otherwise
//=============================================================
bool checkRows(const sudokuGrid grid)
{
   // Check each row
   for (int row = 0; row < 9; row++)
   {
      if (!checkRow(grid, row))
      {
         return false; // If any row is invalid, the grid is invalid
      }
   }
   return true; // All rows are valid
}

//=============================================================
// checkRow
// checks whether a specified row inside a sudoku grid is valid
// PARAMETERS:
//    grid, a 9x9 2D array of ints representing a sudoku board
//    rowIndex, an int representing the index for the row
//      being checked
// RETURN VALUE:
//    true if the row contains 1..9 each exactly once
//    false otherwise
//=============================================================

bool checkRow(const sudokuGrid grid, int rowIndex)
{
   // Use an array to track which numbers we've seen
   bool seen[10] = {false}; // Index 0 not used (valid numbers are 1-9)

   // Check all cells in the row
   for (int col = 0; col < 9; col++)
   {
      int num = grid[rowIndex][col];

      // Check if the number is valid (1-9)
      if (num < 1 || num > 9)
      {
         return false;
      }

      // Check if we've seen this number before in this row
      if (seen[num])
      {
         return false; // Duplicate found
      }

      // Mark this number as seen
      seen[num] = true;
   }

   // Check if all numbers 1-9 are present
   for (int i = 1; i <= 9; i++)
   {
      if (!seen[i])
      {
         return false; // Missing a number
      }
   }

   return true; // All checks passed
}

//=============================================================
// checkCols
// checks whether all 9 columns inside a sudoku grid are valid
// PARAMETERS:
//    grid, a 9x9 2D array of ints representing a sudoku board
// RETURN VALUE:
//    true if each column contains 1..9 each exactly once
//    false otherwise
//=============================================================
bool checkCols(const sudokuGrid grid)
{
   // Check each column
   for (int col = 0; col < 9; col++)
   {
      if (!checkCol(grid, col))
      {
         return false; // If any column is invalid, the grid is invalid
      }
   }
   return true; // All columns are valid
}

//=============================================================
// checkCol
// checks whether a specified column inside a sudoku grid is valid
// PARAMETERS:
//    grid, a 9x9 2D array of ints representing a sudoku board
//    colIndex, an int representing the index for the column
//      being checked
// RETURN VALUE:
//    true if the column contains 1..9 each exactly once
//    false otherwise
//=============================================================

bool checkCol(const sudokuGrid grid, int colIndex)
{
   // Use an array to track which numbers we've seen
   bool seen[10] = {false}; // Index 0 not used (valid numbers are 1-9)

   // Check all cells in the column
   for (int row = 0; row < 9; row++)
   {
      int num = grid[row][colIndex];

      // Check if the number is valid (1-9)
      if (num < 1 || num > 9)
      {
         return false;
      }

      // Check if we've seen this number before in this column
      if (seen[num])
      {
         return false; // Duplicate found
      }

      // Mark this number as seen
      seen[num] = true;
   }

   // Check if all numbers 1-9 are present
   for (int i = 1; i <= 9; i++)
   {
      if (!seen[i])
      {
         return false; // Missing a number
      }
   }

   return true; // All checks passed
}