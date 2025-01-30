#include <iostream>

using namespace std;

int main()
{
    string word = "Happy";

    cout << word.length() << endl;
    cout << word.find("p") << endl;
    cout << word.substr(3, 2) << endl;
    cout << word.at(0) << endl;

    return 0;
}