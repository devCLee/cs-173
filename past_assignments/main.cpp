//=====================================================
// CS 173
// Fall 2024
// main.cpp
// This program is a test driver for the dice class
//=====================================================
#include <iostream>
#include "Dice.h"
using namespace std;

int main()
{
   Dice d1; // default constructor, 6 sided dice.
   cout << "Rolling 6 sided dice\n";
   for (int i = 0; i < 10; i++)
   {
      cout << "\td1 roll = " << d1.roll() << endl;
   }

   Dice d2(9999); // 10 sided dice
   cout << "Rolling 10 sided dice\n";
   for (int i = 0; i < 10; i++)
   {
      cout << "\td2 roll = " << d2.roll() << endl;
   }

   float values[] = {0.5, 0.25, 0.25};
   Dice d3(values, 3);
   cout << "Rolling dice based on specified probabilities\n";
   for (int i = 0; i < 10; i++)
   {
      // cout << endl;
      cout << "\td3 roll = " << d3.roll() << endl;
      // cout << endl;
   }

   // while (true)
   //{
   //    if (d3.roll() == 2)
   //    {
   //       cout << "found" << endl;
   //       break;
   //    }
   // }

   return 0;
}
