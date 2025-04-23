//=============================================
// CS 173
// Fall 2024
// CounterTest1.cpp 
//=============================================

#include <iostream>
using namespace std;
#include <string>
#include "IntCounter.h"

int main()
{
	IntCounter i1;
	IntCounter i2(3);

	cout << "i1 (default ) = " << i1 << endl;
	cout << "i2 (init to 3)= " << i2 << endl;
	
	i1.increment();
	i1.increment();
	i2.increment();

	cout << "increment i1 twice\n";
	cout << "increment i2 once\n";
	
	cout << "i1 = " << i1 << endl;
	cout << "i2 = " << i2 << endl;
	
	i2.reset();
	cout << "i2 (reset)= " << i2 << endl;
	
	return 0;
}
