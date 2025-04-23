//=============================================
// CS 173
// Fall 2024
// IntCounter.h 
//=============================================

#include <iostream>
#include <string>
using namespace std;

class IntCounter
{
private:
	int count;
public:
			IntCounter();
			IntCounter( int v );
	void	increment();
	void	reset();
	int		getCount();
	
	friend ostream& operator<< ( ostream& os, const IntCounter& ic )
	{
		os << ic.count;
		return os;
	}
};

	
