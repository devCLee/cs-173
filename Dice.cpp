//====================================================================================
// Daniel Lee
// March 9, 2025
// Dice.cpp
// This implementation file is a dice class implementation.
// Contains definitions for all methods declared in Dice.h
//====================================================================================

#include "Dice.h" // need to include function declarations before definitions
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//====================================================================================
// Default Dice constructor
// Creates a regular, six-sided dice
// Called when no parameters are given
//====================================================================================
Dice::Dice()
{
    srand(time(NULL));
    sidesNum = 6;
    isProbSetUp = false;
}

//====================================================================================
// Custom Dice constructor
// Creates a dice of specified number of sides (between 2 and 1000).
// Called when an integer is given
//====================================================================================
Dice::Dice(int sides)
{
    srand(time(NULL));
    isProbSetUp = false;

    if (!(2 <= sides && sides <= 1000))
    {
        cerr << "Provided number of sides of the dice: " << sides << " is invalid. Resetting to: 6" << endl;
        sidesNum = 6;
    }
    else
    {
        sidesNum = sides;
    }
}

//====================================================================================
// Weighted probabilities Dice constructor
// Creates a dice of weighted probabilities with specified number of sides (between 2 and 1000).
// Called when an array of floats and an integer size parameter for the array is given
//====================================================================================
Dice::Dice(float array[], int arraySize)
{
    srand(time(NULL));

    if (!(2 <= arraySize && arraySize <= 1000))
    {
        cerr << "Provided number of sides of the dice: " << arraySize << " is invalid. Resetting to: 6" << endl;
        sidesNum = 6;
        isProbSetUp = false;
    }
    else
    {
        sidesNum = arraySize;

        isProbSetUp = true;

        for (int i = 0; i < arraySize; i++)
        {
            probSetUp[i] = array[i];
        }
    }
}

//====================================================================================
// Dice destructor
// Called when an object goes out of scope/is destroyed
//====================================================================================
Dice::~Dice()
{
}

//====================================================================================
// roll()
// A function that returns a random value on our dice after a simulated roll.
// Parameters:  None
// Returns: returns a random value on our dice after a simulated roll.
//====================================================================================
int Dice::roll() const
{
    if (!isProbSetUp)
    {
        return (rand() % sidesNum) + 1;
    }
    else
    {
        float probSum = 0;

        float diceRandomVal = float(rand()) / float(RAND_MAX);

        for (int i = 0; i < sidesNum; i++)
        {
            probSum += probSetUp[i];

            if (diceRandomVal <= probSum)
            {
                return i + 1;
            }
        }

        return sidesNum; // return the last side of the dice when rounding errors occur
    }
}