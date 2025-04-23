//========================================================
// CS 173
// Fall 2024
// listdriver.cpp
// This file tests the List class.
//========================================================

#include <iostream>
#include "List.h"

int main(void)
{
	List<int> list1;
	cout << "list1 = " << list1 << endl; //! default 	list1 = [ ]

	for (int i = 1; i <= 10; i++)
		list1.append(i);

	cout << "list1 = " << list1 << endl; //! append		list1 = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]

	List<int> list2(list1);
	cout << "list2 = " << list2 << endl; //! copy		list2 = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]

	cout << "\nlist1.insert(50,10);\nlist1.insert(0,0)\n";
	cout << "list1.remove(1);\n";
	list2[2] = 100; //! operator[]
	list1.insert(50, 10);
	list1.insert(0, 0);
	list1.remove(1);
	cout << "list2 = " << list2 << endl; //! list2 = [ 1, 2, 100, 4, 5, 6, 7, 8, 9, 10 ]
	cout << "list1 = " << list1 << endl; //! insert, remove
	//! list1 = [ 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 50 ]

	cout << "\nlist3 new empty\n";
	List<int> list3;
	cout << "list3 size = " << list3.length() << endl; //! length		list3 size = 0
	if (list3.isEmpty())
		cout << "list3 empty\n"; //! isEmpty		list3 empty
	else
		cout << "list3 not empty\n";

	cout << "\nlist3 = list1+list2\n";
	list3 = list1 + list2;
	cout << "list3 = " << list3 << endl; //! operator=, operator+
	//! list3 = [ 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 50, 1, 2, 100, 4, 5, 6, 7, 8, 9, 10 ]

	cout << "list3 size = " << list3.length() << endl; //! list3 size = 21
	if (list3.isEmpty())
		cout << "list3 empty\n";
	else
		cout << "list3 not empty\n"; //! list3 not empty

	cout << "\nlist3.clear()\n";
	list3.clear();

	cout << "list3 size = " << list3.length() << endl; //! clear		list3 size = 0
	if (list3.isEmpty())
		cout << "list3 empty\n"; //! list3 empty
	else
		cout << "list3 not empty\n";

	List<char> l5;
	for (char c = 'a'; c < 'p'; c++)
		l5.insert(c, 0);
	cout << "l5 = " << l5 << endl;
	//! l5 = [ o, n, m, l, k, j, i, h, g, f, e, d, c, b, a ]
	l5[0] = 'Z';
	l5.remove(1);
	cout << "l5 = " << l5 << endl;
	//! l5 = [ Z, m, l, k, j, i, h, g, f, e, d, c, b, a ]

	return 0;
}
