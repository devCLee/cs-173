#include <iostream>
#include <string>
using namespace std;

int main()
{

    int inputData;
    int quotient;
    string remainder = "";

    cin >> inputData;

    while (quotient != 0)
    {
        remainder += to_string(inputData % 2);
    }

    cout << inputData / 2 << endl;
}