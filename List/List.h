/*=======================================================
 CS 173
 List.h
 Spring 2025

 This file contains the class definition for the List class.

 ------------------------------------------------------------
 DESCRIPTION:
 The List class is an ordered collection of items.  The items must
 all be of the same datatype specified by a template.

 The number of items in the list is specified by the length()
 of the list.  Items in the list are indexed from 0 (first item)
 to length-1 (last item).  It is generally a run-time error to
 attempt to index a list outside of this range.  The list grows
 dynamically so that it is never full.

 Items may be inserted into the list and removed from the list.
 Values at individual indices may be accessed and/or changed.

 ------------------------------------------------------------
 CONSTRUCTORS:
 There is a default constructor creating an empty list.
 There is a copy constructor to create a new list from an
     existing one.

 ------------------------------------------------------------
 ACCESS:
 isEmpty: returns true if the list is empty, false otherwise.
 length: returns the number of items in the list.
 operator[i]: accesses (by reference) the int at position i.
 toString: returns a string containing the list items.
          example: "( 1, 2, 3 )"
 cout <<: overloads the cout << operator for printing the list.

 ------------------------------------------------------------
 MODIFIERS:
 append: adds a new item onto the end of the list.
 insert: inserts a new item in the list at the specified position,
         moves the other items down to make room.
 remove: removes the item at the specified position.
 assignment operator: can assign one list from another.
 operator+: concatenates two lists into a new list.
 clear: removes all items from the list.
 desctructor: cleans up the memory of the list.

 =======================================================*/

#include <iostream>
using namespace std;

#ifndef LIST_H
#define LIST_H

#define DEFAULT_ARRAY_SIZE 10

template <typename T>
class List
{
public:
            List        (  );
            List        ( const List<T>& l );
           ~List        (  );
    List<T> operator=   ( const List<T>& l );
    void    append      ( T item );
    void    insert      ( T item, int position );
    int     length      (  ) const;
    T&      operator[]  ( int position ) const;
    void    remove      ( int position );
    bool    isEmpty     (  ) const;
    List<T> operator+   ( const List<T>& l ) const;
    void    clear       (  );

    // this operator is already defined here for ostreams like cout
    // you should be able to test this as soon as you implement the
    // default constructor as follows:
    // List<int> l1;
    // cout << l1;
    friend ostream& operator<< ( ostream& os, const List<T>& l )
    {
        os << "[ ";
        for ( int i = 0; i < l.size-1; i++ )
            os << l.arr[i] << ", ";
        if ( l.size != 0 )
            os << l.arr[l.size-1] << " ]";
        else
            os << " ]";
        return os;
    }

private:
    // the maximum capacity of the array storing the list
    int     capacity;
    // the current number of items in the list
    int     size;
    // the dynamically allocated array storing the list
    T*       arr;

    // make the array twice as big to hold more items
    void    reallocate  ( void );
};

#include "List.cpp" // this is necessary because the list
                    // class is a template and cannot be
                    // compiled separately.
#endif
