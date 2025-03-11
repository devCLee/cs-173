#include <iostream>
#include <limits.h>
using namespace std;

int main(){

    int exampleInt = 1;
    cout << "Size of int: " << sizeof(exampleInt) << endl;

    cout << "Max value that can be stored in an int: " << INT_MAX << endl;

    int exampleIntArr[10];
    cout << "Size of int array: " << sizeof(exampleIntArr) << endl;

    return 0;
}