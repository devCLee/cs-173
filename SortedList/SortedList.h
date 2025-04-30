//========================================================
// CS 173
// Spring 2025
// SortedList.h
// This file contains the SortedList class declaration.
// SortedList inherits from List -- we get all of its
// public members but not direct access to its private
// members. We override the functionality of some methods
// to ensure our items are always sorted in descending order.  
//========================================================

#include "List.h"

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

template <class T> 
class SortedList : public List<T>
{
    public:
                    SortedList  ( ) : List<T>(){}
                    SortedList  ( const SortedList<T> &mylist ) : List<T>(mylist){}
        void		append		( const T &item	);// override base class behavior
        void		insert		( const T &item, int index ); // override base class behavior
        void		insert		( const T &item ); // specific to SortedList -- no index required

};


#include "SortedList.cpp"

#endif