//=====================================================
// CS 173
// Spring 2025
// main.cpp
// This program is a test driver for the Date class.
// We can create Date objects here and call their public
// methods. What happens if we try to access their private
// members?
// To compile: g++ -o main main.cpp Date.cpp
// OR run the provided makefile using the command: make
//=====================================================

#include <iostream>
#include "Date.h"
using namespace std;

int main(){
    // test date functionality

    Date date1; // uses default constructor
    cout << "Date 1: "; 
    date1.printDate(); 
    cout << endl;
    Date date2(Date::MAR, 10, 2026); // uses standard constructor
    cout << "Date 2: "; 
    date2.printDate();
    cout << endl;
    Date date3(date2); // uses custom constructor
    cout << "Date 3 (copy of Date 2): ";
    date3.printDate(); 
    cout << endl;

    cout << "Date 3's year:" << date3.getYear() << endl;
    date3.setYear(2030);
    cout << "After changing Date 3's year:" << endl;
    cout << "Date 3's year:" << date3.getYear() << endl;
    cout << "Date 2's year:" << date2.getYear() << endl;

    cout << "Date 2's month:" << date2.getMonth() << endl;
    date2.setMonth(Date::NOV);
    cout << "After changing Date 2's month:" << endl;
    cout << "Date 2's month:" << date2.getMonth() << endl;
    cout << "Date 3's month:" << date2.getMonth() << endl;

    cout << "Set Date 1's day to an invalid value: " << endl;
    date1.setDay(45);
    cout << date1.getDay() << endl;

    cout << "Date 1: "; 
    date1.printDate(); 
    cout << endl;
    cout << "Date 2: "; 
    date2.printDate(); 
    cout << endl;
    cout << "Date 3: "; 
    date3.printDate(); 
    cout << endl;


    return 0;
}