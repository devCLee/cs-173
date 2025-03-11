/*
This function finds and returns the smallest row-maximum value
in a 2D array.
PARAMETERS:
data: a 2D array of integers with ROWS rows and COLS columns.
    ROWS and COLS are global const integers defined elsewhere
RETURN VALUE:
This function computes the maximum integer in each row.  It then returns the minimum value among all these row-maximums.
*/
#include <iostream>
using namespace std;

const int ROWS = 4;
const int COLS = 4;

int minimax(int data[ROWS][COLS]);

int main()
{
    int data[ROWS][COLS] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}};

    cout << minimax(data) << endl;

    return 0;
}

int minimax(int data[ROWS][COLS])
{
    int globalMin;
    int rowMax;

    for (int r = 0; r < ROWS; r++)
    {
        // initialize to first value in this row
        rowMax = data[r][0];
        for (int c = 1; c < COLS; c++)
        {
            // found larger value in this row
            if (data[r][c] > rowMax)
                rowMax = data[r][c];
        }
        // record globalMin if we find a smaller rowMax
        if (r == 0 || rowMax < globalMin)
            globalMin = rowMax;
    }
    return globalMin;

    // int rowMax[ROWS];
    // for (int i = 0; i < ROWS; i++)
    //{
    //     int maxElt = data[i][0];
    //     for (int j = 1; j < COLS; j++)
    //     {
    //         if (maxElt < data[i][j])
    //         {
    //             maxElt = data[i][j];
    //         }
    //     }
    //     rowMax[i] = maxElt;
    // }
    // int minElt = rowMax[0];
    // for (int i = 1; i < ROWS; i++)
    //{
    //     if (minElt > rowMax[i])
    //     {
    //         minElt = rowMax[i];
    //     }
    // }
    // return minElt;
}
