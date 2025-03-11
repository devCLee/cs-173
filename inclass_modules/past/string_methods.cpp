#include <iostream>
#include <string>
using namespace std;

void ex1();
void ex2();

int main()
{

    ex1();
    cout << "#####################" << endl;
    ex2();

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

void ex1()
{
    string s1 = "Breaking news";
    string s2 = "new";
    string s3 = "News";
    string s4 = "173";
    int num = 2025;

    cout << s1.length() << endl;
    cout << s2.size() << endl;
    cout << s3.length() << endl;
    cout << s4.size() << endl;
    cout << s1.find(s2) << endl;
    cout << s2.find(s1) << endl;
    cout << s1.find(s3) << endl;
    cout << s1.substr(0, 5) << endl;
    cout << s1.substr(4, 4) << endl;
    cout << s2.substr(1, 2) << endl;
    cout << s4.substr(2, 4) << endl;
    cout << s1.at(9) << endl;
    cout << s2.at(1) << endl;
    cout << s2.at(10) << endl;
    cout << s4 + num << endl;
    cout << stoi(s4) + num << endl;
    cout << s4 + to_string(num) << endl;

    return;
}

void ex2()
{
    char c1 = toupper('a');
    cout << c1;

    char c2 = toupper('A');
    cout << c2;

    char c3 = toupper('7');
    cout << c3;

    char c4 = toupper('!');
    cout << c4;

    return;
}