#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    cout << "Enter a nonnegative integer: ";
    cin >> num;

    // Special case for 0
    if (num == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    string binaryStr;
    // Perform division by 2 repeatedly to extract binary digits
    while (num > 0)
    {
        int remainder = num % 2;
        // Convert the remainder (0 or 1) to its corresponding char ('0' or '1')
        char binaryDigit = remainder + '0';
        // Prepend the binary digit to the string
        binaryStr = binaryDigit + binaryStr;
        num /= 2;
    }

    cout << binaryStr << endl;
    return 0;
}
