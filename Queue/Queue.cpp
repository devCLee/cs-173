//===========================================
// CS 173
// Spring 2025
// Queue.cpp
// class method definitions for the queue class
//===========================================

#include <stdexcept> 

//===========================================
// default constructor
//===========================================
template <typename T>
Queue<T>::Queue( )
{
	// first, implicitly call default
	// constructor for any private data

	// default constructor is automatically 
	// called for private List q
	
	// we do not need to add anything else
	// empty list is fine to represent an empty queue
}

//===========================================
// copy constructor
//===========================================
template <typename T>
Queue<T>::Queue( const Queue<T>& queue) 
{
	// call copy constructor for List object
	q(queue.q);
}

//===========================================
// destructor
//===========================================
template <typename T>
Queue<T>::~Queue( )
{
	// implicitly call List destructor at end of this
	// empty destructor
}



//===========================================
// assignment operator
// This operator makes use of the assignment
// operator defined for List objects.
// PARAMETERS: a Queue object queue
// RETURN VALUE: *this after copying queue's 
// List object and assigning it to this 
// object's List object  
//===========================================
template <typename T>
Queue<T>	Queue<T>::operator=	( const Queue<T>& queue ) 
{
	q = queue.q;
	return *this;
}


//===========================================
// size
// This function returns a count of the number
// of items in the queue.
// PARAMETERS: none
// RETURN VALUE: int, # items in queue
//===========================================
template <typename T>
int	Queue<T>::size( ) const
{
	return q.length();
}

//===========================================
// push
// This method adds a new item onto the back
// of the queue.
// PARAMETERS: new item (type T) to add
// RETURN VALUE: none, but calling object
// modified.  
//===========================================
template <typename T>
void Queue<T>::push( const T & item )
{
	// Is this optimized for an array-based 
	// List or a linked list? Why?
	q.append(item);

}

//===========================================
// empty
// This method returns true if the queue is
// empty and false otherwise.  
// PARAMETERS: none
// RETURN VALUE: bool 
//===========================================
template <typename T>
bool Queue<T>::empty( ) const
{
	return q.isEmpty();
}

//===========================================
// pop
// This method removes an item from the front
// of the queue. An exception is generated
// if the queue is empty.
// PARAMETERS: none
// RETURN VALUE: none, but calling object
// modified.  
//===========================================
template <typename T>
void Queue<T>::pop( )
{
	if ( q.isEmpty() )
	{
		throw std::underflow_error("Cannot pop from empty queue");
	}
	// Is this optimized for an array-based 
	// List or a linked list? Why?
	q.remove(0);
}

//===========================================
// peek
// This method returns an item from the front
// of the queue but does not remove it. An 
// exception is generated if the queue is empty.
// PARAMETERS: none
// RETURN VALUE: item of type T at the front of queue
//===========================================
template <typename T>
T Queue<T>::peek( )
{
	if ( q.isEmpty() )
	{
		throw std::underflow_error("Cannot peek from empty stack");
	}
	
	return q[0];
}