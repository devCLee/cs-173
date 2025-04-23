//=============================================
// CS 173
// Fall 2024
// IntCounter.h 
//=============================================

#include <iostream>
#include <string>
using namespace std;

class CharCounter
{
	public:
				CharCounter();
				CharCounter( char v );
		void	increment();
		void	reset();
		char	getCount();
		
		friend ostream& operator<< ( ostream& os, const CharCounter& cc )
		{
			os << cc.count;
			return os;
		}
	private:
		char count;
};

	
