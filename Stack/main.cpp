//===========================================
// CS 173
// Spring 2025
// main.cpp
// This file tests a Stack implementation
// Put your List.h and List.cpp files in
// this directory and compile with the
// makefile: make
//===========================================

#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int main()
{
	Stack<int> stack;

	cout << "size of stack = " << stack.size() << endl;
	cout << "is empty? " << stack.empty() << endl;

	stack.push(3);
	stack.push(7);
	stack.push(1);
	stack.push(2);
	stack.push(4);
	cout << "size of stack = " << stack.size() << endl;

	cout << "is empty? " << stack.empty() << endl;

	while (!stack.empty())
	{
		int item = stack.top();
		stack.pop();
		cout << "popped " << item << endl;
	}
	Stack<string> stack2;
	stack2.push("awesome!");
	stack2.push("is");
	stack2.push("CS173");

	while (!stack2.empty())
	{
		cout << "stack2 pop: " << stack2.top() << endl;
		stack2.pop();
	}
	return 0;

	Stack<string> stack3;

	string userInput;
	cout << "Type input" << endl;
	cin >> userInput;

	int length = userInput.length();

	for (int i = 0; i < length; i++)
	{
		stack3.push(userInput[i]);
	}

	while (!stack3.empty())
	{
		int leftCount
	}
}