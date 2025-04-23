//==============================================================
// Matt Kretchmar
// April 2024
// Qd_shallow.cpp
// A simple class illustrating dynamic data allocation using
// incorrect shallow copying techniques.
//==============================================================
#include <iostream>
using namespace std;

//==============================================================
class Qs
{
public:
  Qs(void);
  Qs(const Qs &q);
  ~Qs(void);
  Qs operator=(const Qs &q);
  void set(int v) { *ptr = v; }
  int get(void) { return *ptr; }
  Qs operator+(const Qs &q) const;

private:
  int *ptr;
};

//--------------------------------------------------------------
// default constructor
//--------------------------------------------------------------
Qs::Qs(void)
{
  ptr = new int;
  *ptr = 0;
}
//--------------------------------------------------------------
// copy constructor
//--------------------------------------------------------------
Qs::Qs(const Qs &q)
{
  ptr = q.ptr; //! shallow copy = wrong!!!
}
//--------------------------------------------------------------
// destructor
//--------------------------------------------------------------
Qs::~Qs(void)
{
  delete ptr;
}
//--------------------------------------------------------------
// assignment operator
//--------------------------------------------------------------
Qs Qs::operator=(const Qs &q)
{
  ptr = q.ptr; // shallow copy is wrong!!!

  return *this;
}
//--------------------------------------------------------------
Qs Qs::operator+(const Qs &q) const
{
  Qs ret;
  *(ret.ptr) = *ptr + *(q.ptr);
  return ret;
}

//==============================================================
int main(void)
{
  Qs q1, q2;
  q1.set(5);

  cout << "\n*** Part 1 ***\n";
  q2 = q1;
  cout << "q1 = " << q1.get() << endl;
  cout << "q2 = " << q2.get() << endl;

  cout << "\n*** Part 2 ***\n";
  q1.set(7);
  cout << "q1 = " << q1.get() << endl;
  cout << "q2 = " << q2.get() << endl;

  cout << "\n*** Part 3 ***\n";
  Qs q3;
  q3 = q1 + q2;
  cout << "q3 = " << q3.get() << endl;
  return 0;
}
