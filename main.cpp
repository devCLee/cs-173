//=====================================================
// CS 173
// Fall 2024
// main.cpp
// This program is a test driver for the dice class
//=====================================================

#include <iostream>
#include "Dice.h"
using namespace std;

int main ()
{
   Dice  d1; // default constructor, 6 sided dice.
   cout << "Rolling 6 sided dice\n";
   for ( int i = 0; i < 10; i++ )
   {
      cout << "\td1 roll = " << d1.roll() << endl;
   }

   Dice d2(10); // 10 sided dice
   cout << "Rolling 10 sided dice\n";
   for ( int i = 0; i < 10; i++ )
   {
      cout << "\td2 roll = " << d2.roll() << endl;
   }

   return 0;
}
