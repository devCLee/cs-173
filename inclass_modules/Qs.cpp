//==============================================================
// Matt Kretchmar
// April 2024
// Qs.cpp
// A simple class illustrating static data with shallow copying
// Note I am putting all three files (Qs.cpp Qs.h and main.cpp)
// into the same source file for simplicity of file transfer
// even though this is not the correct way to build and manage
// a class.
//==============================================================
#include <iostream>
using namespace std;

//==============================================================
class Qs
{
public:
        Qs        ( void )    { value = 0; }
void    set       ( int v )   { value = v; }
int     get       ( void )    { return value; }
Qs      operator+ ( const Qs &q ) const;
private:
  int value;      // a static value in a class
};

//--------------------------------------------------------------
// addition operator overload
//--------------------------------------------------------------
Qs      Qs::operator+   ( const Qs &q ) const
{
  Qs ret;
  ret.value = value + q.value;
  return ret;
}

//==============================================================
int main ( void )
{
  Qs q1, q2;
  q1.set(5);
  q2 = q1;
  cout << "q1 = " << q1.get() << endl;
  cout << "q2 = " << q2.get() << endl;

  q1.set(7);
  cout << "q1 = " << q1.get() << endl;
  cout << "q2 = " << q2.get() << endl;

  Qs q3;
  q3 = q1 + q2;
  cout << "q3 = " << q3.get() << endl;
  return 0;
}
