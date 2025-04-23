//=====================================================
// CS 173
// Fall 2024
// randtest.cpp
// This program illustrates the use of random number
// generators in c/c++
//=====================================================

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
   // The random number generator creates a sequence of
   // random-looking integers.   The sequence is repeatable
   // thus to "feel random" you should start the sequence
   // at an arbritrary point.   This is accomplished using
   // the srand command which seeds the sequence with a
   // starting point.   Each time you run the program, you
   // would like a different seed value.  This can be
   // accomplished by prompting the user to enter a seed.
   // Or you can use the system clock which will provide
   // a different seed value each time you run the program.

   // This command illustrates how to use the time() function
   // to get the system clock and use it as a seed value
   // for srand().
   srand(time(NULL));

   // To obtain the next random integer in the sequence
   // we use the rand() function.  Since this is a big
   // integer with values larger than we normally need,
   // it is common to use the % operator to get a range
   // of random values.   Here we generate 10 random values
   // between 0 and 4 inclusive.
   for (int i = 0; i < 10; i++)
      cout << "value = " << rand() % 5 << endl;

   return 0;
}
