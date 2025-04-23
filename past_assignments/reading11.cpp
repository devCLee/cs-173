#include <iostream>
using namespace std;

class Number
{
public:
    int n;

    Number(int set_n)
    {
        n = set_n;
    }

    Number operator+(const Number &numA)
    {
        cout << "this->n: " << this->n << endl;
        cout << "numA.n: " << numA.n << endl;

        return Number(this->n + numA.n);
    }
};

int main(void)
{
    Number a(5);
    Number b(10);

    Number c = b + a;

    cout << "c.n: " << c.n << endl;

    cout << "----------------------" << endl;

    int x1 = 10;
    int x2 = 20;
    int x3 = 100;

    int *p1 = &x1;
    int *p2 = &x2;
    int *p3 = &x3;

    *p1 = 5;
    *p2 = *p3;
    p3 = p1;

    cout << p1 << endl;
    cout << p3 << endl;
    cout << "Line 1: " << x1 << endl;
    cout << "Line 2: " << *p2 << endl;
    cout << "Line 3: " << *p3 << endl;
    cout << p1 << endl;
    cout << p3 << endl;

    return 0;
}
