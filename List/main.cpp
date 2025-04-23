//==============================================================
// CS 173
// Fall 2024
// main.cpp
// This file is a driver for the List class.
//==============================================================

#include <iostream>
using namespace std;
#include "List.h"

//==============================================================
// main
//==============================================================

int main(void)
{
    List<int> l1; //! default constructor

    l1.append(1); //! append
    l1.append(2);
    l1.append(3);
    List<int> l2(l1); //! copy constructor
    List<int> l3;

    l1.insert(4, 1);                                 //! insert
    cout << "l1 = " << l1 << endl;                   //! cout <<
    cout << "l1.length() = " << l1.length() << endl; //! length

    l1[2] = 10; //! operator[]
    cout << "l1 = " << l1 << endl;
    cout << "l1.length() = " << l1.length() << endl;

    l1.remove(1); //! remove
    cout << "l1 = " << l1 << endl;
    cout << "l1.length() = " << l1.length() << endl;

    l3 = l2 + l1; //! operator+ operator=
    cout << "l3 = l2 + l1 = " << l3 << endl;
    cout << "l3.length() = " << l3.length() << endl;

    cout << "l2 = " << l2 << endl;

    l2.clear(); //! clear
    cout << "l2.clear() = " << l2 << endl;
    cout << "l2.length() = " << l2.length() << endl;
    cout << "l2 = " << l2 << endl;

    // Test the "doubling" ability of the list
    List<char> l5;
    for (char c = 'a'; c <= 'g'; c++)
        l5.append(c); //! append()
    List<char> l6 = l5;
    for (char c = 'h'; c <= 'z'; c++)
        l5.append(c);
    List<char> l7 = l5;
    l5.remove(19); //! remove

    cout << "l5 = " << l5 << endl;
    cout << "l6 = " << l6 << endl;
    cout << "l7 = " << l7 << endl;

    return 0;
}
