//===========================================
// CS 173
// Spring 2025
// Stack.cpp
// class method definitions for the stack class
//===========================================

#include <stdexcept> 

//===========================================
// default constructor
//===========================================
template <typename T>
Stack<T>::Stack( )
{
	// first, implicitly call default
	// constructor for any private data

	// default constructor is automatically 
	// called for private List s
	
	// we do not need to add anything else
	// empty list is fine to represent an empty stack
}

//===========================================
// copy constructor
//===========================================
template <typename T>
Stack<T>::Stack( const Stack<T> &stack ) 
{
	// call copy constructor for List object
	s(stack.s);
}

//===========================================
// destructor
//===========================================
template <typename T>
Stack<T>::~Stack( )
{
	// implicitly call List destructor at end of this
	// empty destructor
}



//===========================================
// assignment operator
// This operator makes use of the assignment
// operator defined for List objects.
// PARAMETERS: a Stack object stack
// RETURN VALUE: *this after copying stack's 
// List object and assigning it to this 
// object's List object  
//===========================================
template <typename T>
Stack<T>	Stack<T>::operator=	( const Stack<T> &stack ) 
{
	s = stack.s;
	return *this;
}


//===========================================
// size
// This function returns a count of the number
// of items in the stack.
// PARAMETERS: none
// RETURN VALUE: int, # items in stack
//===========================================
template <typename T>
int	Stack<T>::size( ) const
{
	return s.length();
}

//===========================================
// push
// This method adds a new item onto the top
// of the stack.
// PARAMETERS: new item (type T) to add
// RETURN VALUE: none, but calling object
// modified.  
//===========================================
template <typename T>
void Stack<T>::push( const T & item )
{
	// Is this optimized for an array-based 
	// List or a linked list? Why?
	s.append(item);

}

//===========================================
// empty
// This method returns true if the stack is
// empty and false otherwise.  
// PARAMETERS: none
// RETURN VALUE: bool 
//===========================================
template <typename T>
bool Stack<T>::empty( ) const
{
	return s.isEmpty();
}

//===========================================
// pop
// This method removes an item from the top
// of the stack and returns it. An exception
// is generated if the stack is empty.
// PARAMETERS: none
// RETURN VALUE: top item on the stack of type T
//===========================================
template <typename T>
void Stack<T>::pop( )
{
	if ( s.isEmpty() )
	{
		throw std::underflow_error("Cannot pop from empty stack");
	}
	// Is this optimized for an array-based 
	// List or a linked list? Why?
	int pos = s.length()-1;
	s.remove(pos);
}

//===========================================
// peek
// This method returns an item from the top
// of the stack but does not remove it.   An exception
// is generated if the stack is empty.
// PARAMETERS: none
// RETURN VALUE: top item on the stack of type T
//===========================================
template <typename T>
T Stack<T>::top( )
{
	if ( s.isEmpty() )
	{
		throw std::underflow_error("Cannot peek from empty stack");
	}
	
	int pos = s.length()-1;
	return s[pos];
}