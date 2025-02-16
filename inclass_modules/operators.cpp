#include <iostream>
using namespace std;

// Forward declarations
void ex2();
void ex3();

int main()
{
    int x = 6;
    int y = 3;

    cout << x + y << endl;    // 6 + 3 = 9
    cout << x - y << endl;    // 6 - 3 = 3
    cout << x * y << endl;    // 6 * 3 = 18
    cout << x / y << endl;    // 6 / 3 = 2
    cout << y / x << endl;    // 3 / 6 = 0 (integer division)
    cout << x % y << endl;    // 6 % 3 = 0
    cout << y % x << endl;    // 3 % 6 = 3
    cout << float(y) << endl; // 3.0 (explicitly cast y to float)
    cout << 25 / 4 << endl;   // 6 (integer division)
    cout << 15 / 3.0 << endl; // 5.0 (floating-point division)

    cout << "#############################" << endl;

    // Call the functions
    ex2();
    ex3();

    return 0; // Good practice in C++
}

void ex2()
{
    int x = 7;
    int y = 2;

    cout << x + y++ << endl; // Uses y, then increments y
    cout << ++x - y << endl; // Increments x, then uses x
    cout << x * --y << endl; // Decrements y, then uses y
    cout << x / y + 1 << endl;
    cout << y / x++ << endl;     // Uses x, then increments x
    cout << x % ++y << endl;     // Increments y, then uses y
    cout << y % x-- + 3 << endl; // Uses x, then decrements x

    cout << "#############################" << endl;
}

void ex3()
{
    int x = 9;
    int y = 4;
    int z = 2;

    z = x % y; // 9 % 4 = 1
    cout << z << endl;

    z += x % y; // z = z + (9 % 4) = 1 + 1 = 2
    cout << z << endl;

    z -= x % y; // z = z - (9 % 4) = 2 - 1 = 1
    cout << z << endl;

    z *= x % y + 1; // z *= 1 + 1 = z * 2 = 1 * 2 = 2
    cout << z << endl;

    z *= x % y++; // x % y = 9 % 4 = 1, then y++ (y becomes 5)
                  // z = 2 * 1 = 2
    cout << z << endl;

    z /= x; // z = 2 / 9 (integer division) = 0
    cout << z << endl;
}
