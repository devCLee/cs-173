//===========================================
// CS173
// Spring 2025
// Queue.h
// class declaration for the queue class
//===========================================

#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <typename T>
class Queue
{	
	public:
				Queue		(  );
				Queue		( const Queue<T>& queue );
				~Queue		(  );
	    Queue<T> operator=	( const Queue<T>& queue );
		int		size		(  ) const;
		void	push		( const T& item );
		bool	empty		(  ) const;
		void	pop			(  );
		T		peek		(  );

	private:
		List<T>  q; // our queue has-a List (example of composition)
	

};


#include "Queue.cpp"

#endif  