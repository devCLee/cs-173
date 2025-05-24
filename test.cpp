#include <iostream>
using namespace std;

int main()
{
    int x = 4;
    int y = 5;

    string myString = "computer";

    cout << 7 - 23 / 8 * x + 6 << endl;

    cout << 19.0 / 3 - 7 + 2 * y << endl;

    cout << 19 % 3 - 7 + 2 * y++ << endl;
    cout << 7 - 23 / 8 * --x + 6 << endl;

    cout << (!true && !false || false) << endl;
    cout << (!true && !false || true) << endl;

    cout << (!false && !false || false) << endl;
    cout << myString.substr(3, 3) << endl;
}