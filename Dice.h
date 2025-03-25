//==========================================
// Daniel Lee
// March 9, 2025
// Dice.h
// This specification file is a dice class specification.
// Here we declare the functions and data
// members for a C++ class representing a
// Dice Abstract Data Type (ADT).
//==========================================
#ifndef DICE_H // prevents conflicts if header file is included in multiple cpp files
#define DICE_H

class Dice
{
public:
    Dice(); // default constructor
    Dice(int sides);
    Dice(float array[], int arraySize);
    ~Dice(); // destructor

    int roll() const;

private:
    // data members
    int sidesNum;
    float probSetUp[1000];
    bool isProbSetUp;
};

#endif