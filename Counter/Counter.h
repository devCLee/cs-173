//=============================================
// CS 173
// Fall 2024
// Counter.h
// A templated counter class specification.
//==========================================

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Counter
{
	public:
				Counter		();
				Counter		( T v );
		void	increment	();
		T		getCount	();
		void	reset		();

		friend ostream& operator<< ( ostream& os, const Counter<T>& c )
		{
			os << c.count;
			return os;
		}
	private:
		T   	count;
		T		start;

};

#include "Counter.cpp"