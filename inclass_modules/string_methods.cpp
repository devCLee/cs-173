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

    string s = "Banana";
    string upper = "";
    cin >> s;
    // loop through each character in s and convert it to uppercase
    for (int i = 0; i < s.length(); i++)
    {
        char c = toupper(s.at(i));
        upper += c;
    }
    cout << upper << endl;
    char c = toupper('x');
    cout << c << endl;
    if (s.find("x") == string::npos)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << s.find("x") << endl;
    }
    return 0;
}