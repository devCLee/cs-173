//===========================================
// CS 173
// Spring 2025
// main.cpp
// This file tests a Queue implementation
// Put your List.h and List.cpp files in
// this directory and compile with the
// makefile: make
//===========================================

#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;


int main ( )
{
	Queue<int>  queue;
	
	cout << "size of queue = " << queue.size() << endl;
	cout << "is empty? " << queue.empty() << endl;
	
	queue.push(3);
	queue.push(7);
	queue.push(1);
	queue.push(2);
	queue.push(4);
	cout << "size of queue = " << queue.size() << endl;
	
	cout << "is empty? " << queue.empty() << endl;
	
	while ( !queue.empty() )
	{
		int item = queue.peek();
		queue.pop();
		cout << "popped " << item << endl;
	}
	Queue<string> queue2;
	queue2.push("awesome!");
	queue2.push("is");
	queue2.push("CS173");
	
	while ( !queue2.empty() )
	{
		cout << "queue2 pop: " << queue2.peek() << endl;
		queue2.pop();
	}
	return 0;
}