//===========================================
// CS173
// Spring 2025
// Stack.h
// class declaration for the stack class
//===========================================

#ifndef STACK_H
#define STACK_H

#include "List.h"

template <typename T>
class Stack
{	
	public:
				Stack		(  );
				Stack		( const Stack<T> &stack );
				~Stack		(  );
		Stack<T> operator=	( const Stack<T> &stack );
		int		size		(  ) const;
		void	push		( const T &item );
		bool	empty		(  ) const;
		void	pop			(  );
		T		top			(  );

	private:
		List<T>  s; // our stack has-a List (example of composition)
	

};


#include "Stack.cpp"

#endif  