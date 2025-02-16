#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    int x;

    cin >> x;

    cout << typeid(x).name << endl;

    return 0;
}