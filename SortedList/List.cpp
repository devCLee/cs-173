//==============================================================
// Daniel Lee
// April 16, 2025
// List.cpp
// This file contains the class method definitions for
// the List class.
//==============================================================

#include <iostream>
#include <stdlib.h>
#include "List.h"
using namespace std;

//==============================================================
// default constructor
// Initializes a default List object.
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
List<T>::List()
{
    capacity = DEFAULT_ARRAY_SIZE;
    size = 0;
    arr = new T[capacity];
}

//==============================================================
// copy constructor
// Creates a new List object as a copy of another.
// Parameters:
//      const List<T> &l: the List object to copy
// Return: None
//==============================================================
template <typename T>
List<T>::List(const List<T> &l)
{
    capacity = l.capacity;
    size = l.size;
    arr = new T[capacity];

    //! Deep copy: array itself is a pointer!
    for (int i = 0; i < size; i++)
    {
        arr[i] = l.arr[i];
    }
}

//==============================================================
// destructor
// Cleans up the memory of the list.
// Parameters: none
// Return: none
//==============================================================
template <typename T>
List<T>::~List()
{
    delete[] arr;
}

//==============================================================
// operator=
// Assigns the value of another List object to the object that we are intending to assign to
// Parameters:
//        const List<T> &l: a List object
// Return Value:
//        A reference to this List object
//==============================================================
template <typename T>
List<T> List<T>::operator=(const List<T> &l)
{

    //! Checking for self-assigning scenario
    if (this == &l)
    {
        return l;
    }

    delete[] arr;

    arr = new T[capacity];

    capacity = l.capacity;
    size = l.size;

    for (int i = 0; i < size; i++)
    {
        arr[i] = l.arr[i];
    }

    return *this;
}
//==============================================================
//! append
// Appends a new item onto the back of the list.
// Parameters:
//        item: the item that should be appended onto the back of the list.
// Return Value:
//        None
//==============================================================
template <typename T>
void List<T>::append(T item)
{
    if (size >= capacity)
    {
        reallocate();
    }

    arr[size] = item;
    size++;
}
//==============================================================
//! insert  ( item, position )
// Inserts a new value at the specified position.
// Parameters:
//        item: the new value that should be inserted into the list.
//        position: the index position that the item should be inserted into.
// Return Value:
//        None
//==============================================================
template <typename T>
void List<T>::insert(T item, int position)
{
    if (position < 0 || position > size)
    {
        throw runtime_error("Error occurred! Invalid index!\n");
    }

    if (size >= capacity)
    {
        reallocate();
    }

    for (int i = size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = item;
    size++;
}
//==============================================================
// length
// Identifies the number of items in the list.
// Parameters: None
// Return Value:
//        the number of items in the list.
//==============================================================
template <typename T>
int List<T>::length() const
{
    return size;
}
//==============================================================
// operator[]
// Accesses (by reference) the item at the specified index.
// Parameters:
//        position: the index position that the function is trying to access.
// Return Value:
//        the array element in the position index.
//==============================================================
template <typename T>
T &List<T>::operator[](int position) const
{
    if (position < 0 || position >= size)
    {
        throw runtime_error("Error occurred! Invalid index!\n");
    }

    return arr[position];
}
//==============================================================
// remove
// Removes an item at the specified location. Valid indices are 0 to size-1.
// Invalid indices generate a run-time error and end the program.
// Parameters:
//        position: the index position of the element that the function is trying to remove.
// Return Value:
//        None
//==============================================================
template <typename T>
void List<T>::remove(int position)
{
    if (position < 0 || position >= size)
    {
        throw runtime_error("Error occurred! Invalid index!\n");
    }

    for (int i = position; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size = size - 1;
}
//==============================================================
// isEmpty
// Identifies if the list is empty
// Parameters:
//        None
// Return Value:
//        Returns a Boolean value true if the list is empty, a Boolean value false otherwise.
//==============================================================
template <typename T>
bool List<T>::isEmpty() const
{
    return size == 0;
}
//==============================================================
//! operator+  (concatenate two lists)
// Concatenates two lists into a new list. Does not change either existing list.
// Parameters:
//        const List<T> &l: the List object
// Return Value:
//        newList: the result of the concatenation of two lists.
//==============================================================
template <typename T>
List<T> List<T>::operator+(const List<T> &l) const
{
    List<T> newList;

    for (int i = 0; i < size; i++)
    {
        newList.append(arr[i]);
    }

    for (int i = 0; i < l.size; i++)
    {
        newList.append(l.arr[i]);
    }

    return newList;
}
//==============================================================
// clear
// Removes all items from the list.
// Parameters:
//        None
// Return Value:
//        None
//==============================================================
template <typename T>
void List<T>::clear()
{
    size = 0;
}
//==============================================================
// reallocate
// double the size of the array holding the list
// Parameters:
//        None
// Return Value:
//        None
//==============================================================
template <typename T>
void List<T>::reallocate()
{
    int updatedCapacity = capacity * 2;
    T *newArr = new T[updatedCapacity];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;

    capacity = updatedCapacity;
    arr = newArr;
}
//==============================================================
