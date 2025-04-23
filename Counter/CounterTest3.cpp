//=============================================
// CS 173
// Fall 2024
// CounterTest3.cpp
// A templated counter class use.
//==============================================

#include <iostream>
#include <string>
#include "Counter.h"
using namespace std;


int main()
{
	Counter<int>    c1;
	Counter<char>	c2('A');

	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	
	c1.increment();
	c1.increment();
	c2.increment();
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;

	c1.reset();
	cout << "c1 = " << c1 << endl;

	c2.reset();
	cout << "c2 = " << c2 << endl;
		
	return 0;
}


