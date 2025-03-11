//=========================================================
// Daniel Lee
// March 2, 2025
// DLee_cs173_project6.cpp
// This program reads a data in the form of a number n and then n data points.
// The data points will be (x,y) pairs where indicating where there is a hole in the ozone when the simulation starts.
// All x and y values will be between 0 and 14 inclusive.
// This program then would simulate the ozone layer for 24 months.
// During every month of the simulation, the program prints out a 15x15 grid
// of ozone status using 'O' to indicate where a hole is and 'X' to indicate a non-hole.
// The program output should include a print of the starting configuration.
// This will result in 25 grids being printed.
//=========================================================
#include <iostream>

using namespace std;

const int ROWS = 15;
const int COLS = 15;

void printArray(char grid[ROWS][COLS]);
void updateGrid(char grid[ROWS][COLS], char tempGrid[ROWS][COLS]);
int checkRow(char grid[ROWS][COLS], int rowIndex, int colIndex);
int checkCol(char grid[ROWS][COLS], int rowIndex, int colIndex);
int checkDiagonal(char grid[ROWS][COLS], int rowIndex, int colIndex);

int main(void)
{
    char grid[ROWS][COLS];
    char tempGrid[ROWS][COLS];
    int numberHoles;
    int x, y;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = 'X';
            tempGrid[i][j] = 'X';
        }
    }

    cin >> numberHoles;

    for (int i = 0; i < numberHoles; i++)
    {

        cin >> x >> y;

        grid[x][y] = 'O';
        tempGrid[x][y] = 'O';
    }

    printArray(grid);

    for (int i = 0; i < 24; i++)
    {
        updateGrid(grid, tempGrid);
        printArray(grid);
    }

    return 0;
}

//=============================================================
// printArray
// Parameters:
//      grid, a 15x15 2D array of chars representing the grid of ozone.
// Return value: none, but prints to the screen.
//=============================================================
void printArray(char grid[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    cout << endl;

    return;
}

//=============================================================
// updateGrid
// Updates the grid based on the updating rules
// Parameters:
//    grid, a 15x15 2D array of chars representing the grid of ozone.
//    tempGrid, a 15x15 2D array of chars that stores the next state.
// Return value: none, but updates both arrays.
//=============================================================
void updateGrid(char grid[ROWS][COLS], char tempGrid[ROWS][COLS])
{
    for (int j = 0; j < ROWS; j++)
    {
        for (int k = 0; k < COLS; k++)
        {
            int totalHoles = 0;
            totalHoles += checkRow(grid, j, k);
            totalHoles += checkCol(grid, j, k);
            totalHoles += checkDiagonal(grid, j, k);

            if (grid[j][k] == 'O')
            {
                if (!(totalHoles == 2 || totalHoles == 3))
                {
                    tempGrid[j][k] = 'X';
                }
            }
            else
            {
                if (totalHoles == 3)
                {
                    tempGrid[j][k] = 'O';
                }
            }
        }
    }

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            grid[r][c] = tempGrid[r][c];
        }
    }

    return;
}

//=============================================================
// checkRow
// checks whether the left or right element in the 2D array is a hole
// Parameters:
//    grid, a 15x15 2D array of chars representing the grid of ozone.
//    rowIndex, the row index of the array element that we are trying to examine.
//    colIndex, the column index of the array element that we are trying to examine.
// Return value:
//    an integer that indicates the sum of the number of holes detected.
//=============================================================
int checkRow(char grid[ROWS][COLS], int rowIndex, int colIndex)
{
    int rowSum = 0;
    if (colIndex - 1 < 0)
    {
        if (grid[rowIndex][colIndex + 1] == 'O')
        {
            rowSum += 1;
        }

        return rowSum;
    }
    else if (colIndex + 1 > COLS - 1)
    {
        if (grid[rowIndex][colIndex - 1] == 'O')
        {
            rowSum += 1;
        }

        return rowSum;
    }
    else
    {
        if (grid[rowIndex][colIndex + 1] == 'O')
        {
            rowSum += 1;
        }
        if (grid[rowIndex][colIndex - 1] == 'O')
        {
            rowSum += 1;
        }

        return rowSum;
    }
}

//=============================================================
// checkCol
// checks whether the up or down element in the 2D array is a hole
// Parameters:
//    grid, a 15x15 2D array of chars representing the grid of ozone
//    rowIndex, the row index of the array element that we are trying to examine.
//    colIndex, the column index of the array element that we are trying to examine.
// Return value:
//    an integer that indicates the sum of the number of holes detected.
//=============================================================
int checkCol(char grid[ROWS][COLS], int rowIndex, int colIndex)
{
    int colSum = 0;

    if (rowIndex - 1 < 0)
    {
        if (grid[rowIndex + 1][colIndex] == 'O')
        {
            colSum += 1;
        }

        return colSum;
    }
    else if (rowIndex + 1 > ROWS - 1)
    {
        if (grid[rowIndex - 1][colIndex] == 'O')
        {
            colSum += 1;
        }

        return colSum;
    }
    else
    {
        if (grid[rowIndex + 1][colIndex] == 'O')
        {
            colSum += 1;
        }
        if (grid[rowIndex - 1][colIndex] == 'O')
        {
            colSum += 1;
        }

        return colSum;
    }
}

//=============================================================
// checkDiagonals
// checks whether there are holes in the four diagonal directions of elements in the 2D array
// Parameters:
//    grid, a 15x15 2D array of chars representing the grid of ozone
//    rowIndex, the row index of the array element that we are trying to examine.
//    colIndex, the column index of the array element that we are trying to examine.
// Return value:
//    an integer that indicates the sum of the number of holes detected.
//=============================================================
int checkDiagonal(char grid[ROWS][COLS], int rowIndex, int colIndex)
{
    int diagonalSum = 0;

    // upper-right diagonal
    if (rowIndex - 1 >= 0 && colIndex + 1 < COLS)
    {
        if (grid[rowIndex - 1][colIndex + 1] == 'O')
        {
            diagonalSum += 1;
        }
    }

    // lower-right diagonal
    if (rowIndex + 1 < ROWS && colIndex + 1 < COLS)
    {
        if (grid[rowIndex + 1][colIndex + 1] == 'O')
        {
            diagonalSum += 1;
        }
    }

    // upper-left diagonal
    if (rowIndex - 1 >= 0 && colIndex - 1 >= 0)
    {
        if (grid[rowIndex - 1][colIndex - 1] == 'O')
        {
            diagonalSum += 1;
        }
    }

    // lower-left diagonal
    if (rowIndex + 1 < ROWS && colIndex - 1 >= 0)
    {
        if (grid[rowIndex + 1][colIndex - 1] == 'O')
        {
            diagonalSum += 1;
        }
    }

    return diagonalSum;
}