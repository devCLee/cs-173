//========================================================
// CS 173
// Spring 2025
// SortedList.h
// This file contains the SortedList class definitions.
// SortedList inherits from List -- we get all of its
// public members but not direct access to its private
// members. We override the functionality of some methods
// to ensure our items are always sorted in descending order.  
//========================================================

//========================================================
// insert
// PARAMETERS:
// item: the item to insert of template type T
// RETURN VALUE:
// none, but the list is altered with the new addition
//========================================================
template <class T>
void SortedList<T>::insert  ( const T &item )
{
	bool insertPositionFound = false;
    int pos = 0;
    int size = List<T>::length();
    while(!insertPositionFound && pos < size){
        // compare the item we are inserting to the item at each position
        // until we find where it should go
        if (item > (*this)[pos]){
            insertPositionFound = true; // will cause us to exit the loop
        }
        else{
            pos++;
        }
    }
    // call the base class' insert method
    List<T>::insert(item, pos);
}

//========================================================
// insert
// PARAMETERS:
// item: the item to insert of template type T
// index: the location to insert the item (irrelevant here)
// RETURN VALUE:
// none, but the list is altered with the new addition
//========================================================
template <class T>
void SortedList<T>::insert  ( const T &item, int index )
{
	// call our derived class' insert method
    insert(item);
}

//========================================================
// append
// PARAMETERS:
// item: the item to insert of template type T
// RETURN VALUE:
// none, but the list is altered with the new addition
//========================================================
template <class T>
void SortedList<T>::append  ( const T &item )
{
	// call our derived class' insert method
    insert(item);
}