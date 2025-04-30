//===========================================
// CS 173
// Spring 2025
// main.cpp
// This file tests a SortedList implementation
// Put your List.h and List.cpp files in
// this directory and compile with the
// makefile: make
//===========================================

#include <iostream>
#include <string>
#include "SortedList.h"
#include "List.h"
using namespace std;

const int SIZE = 5;

int main ( )
{
	// base class
	List<int> unsorted;
	// derived class
	SortedList<int> sorted;

	int values[SIZE] = {27,43,21,-5,18};

	for(int i = 0; i < SIZE; i++){
		// insert the same values into both Lists
		unsorted.append(values[i]);
		sorted.append(values[i]);
	}

	cout << "Unsorted List: " << unsorted << endl;
	cout << "Sorted List: " << sorted << endl;

	return 0;
}