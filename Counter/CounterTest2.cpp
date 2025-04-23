//=============================================
// CS 173
// Fall 2024
// CounterTest2.cpp 
//=============================================

#include <iostream>
using namespace std;
#include <string>
#include "CharCounter.h"

int main()
{
	CharCounter i1;
	CharCounter i2('F');

	cout << "i1 (default ) = " << i1 << endl;
	cout << "i2 (init to F)= " << i2 << endl;
	
	i1.increment();
	i1.increment();
	i2.increment();

	cout << "increment i1 twice\n";
	cout << "increment i2 once\n";
	
	cout << "i1 = " << i1 << endl;
	cout << "i2 = " << i2 << endl;
	
	return 0;
}
