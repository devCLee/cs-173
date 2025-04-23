//==============================================================
// Daniel Lee
// April 16th
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
    head = nullptr; //! Initializied List object must be empty?
}
//==============================================================
// copy constructor
// Creates a new List object as a copy of another.
// Parameters:
//      const List<T>& mylist: the List object to copy
// Return: None
//==============================================================
template <typename T>
List<T>::List(const List<T> &mylist)
{
    head = nullptr; //! ? Do I need this?????

    Node *currentNode = mylist.head;
    while (currentNode != nullptr)
    {
        append(currentNode->item); //! ??????????????
        currentNode = currentNode->next;
    }
}
//==============================================================
// destructor
// Cleans up the memory of the list.
// Parameters: none
// Return: none
//==============================================================
//! 질문
template <typename T>
List<T>::~List()
{
    clear();
}
//==============================================================
// operator=
// Assigns the value of another List object to the object that we are intending to assign to
// Parameters:
//        const List<T>& mylist: a List object
// Return Value:
//        A reference to this List object
//==============================================================
template <typename T>
List<T> List<T>::operator=(const List<T> &mylist)
{

    //! Checking for self-assigning scenario
    if (this == &mylist)
        return mylist;

    //! Destructor???
    clear();

    //! Acts like a copy constructor
    Node *currentNode = mylist.head;
    while (currentNode != nullptr)
    {
        append(currentNode->item);
        currentNode = currentNode->next;
    }

    return *this;
}
//==============================================================
// append
// Appends a new item onto the back of the list.
// Parameters:
//        item: the item that should be appended onto the back of the list.
// Return Value:
//        None
//==============================================================
template <typename T>
void List<T>::append(const T &item)
{
    Node *appendedNode = new Node;
    appendedNode->item = item;
    appendedNode->next = nullptr;

    //! Check whether it is empty list
    if (head == nullptr)
    {
        head = appendedNode;
    }
    else
    {
        Node *currentNode = head;
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = appendedNode;
    }
}
//==============================================================
// insert  ( item, index )
// Inserts a new value at the specified position.
// Parameters:
//        item: the new value that should be inserted into the list.
//        index: the index position that the item should be inserted into.
// Return Value:
//        None
//==============================================================
template <typename T>
void List<T>::insert(const T &item, int index)
{
    int size = length();
    if (index < 0 || index > size)
    {
        throw runtime_error("Error occurred! Invalid index!\n");
    }

    Node *insertedNode = new Node;
    insertedNode->item = item;

    if (index == 0)
    {
        insertedNode->next = head; //!!!!!! ??????????
        head = insertedNode;       //!!!!!! ??????????
    }
    else if (index == size)
    {
        append(item);
    }
    else
    {
        Node *currentNode = head;
        for (int i = 0; i < index - 1; i++)
        {
            currentNode = currentNode->next;
        }

        insertedNode->next = currentNode->next;
        currentNode->next = insertedNode;
    }
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
    int count = 0;
    Node *currentNode = head;

    while (currentNode != nullptr) //! currentNode != nullptr ??? currentNode->next != nullptr
    {
        count += 1;
        currentNode = currentNode->next;
    }

    return count;
}
//==============================================================
// operator[] //! Last 3
// Valid indices are 0 to size-1.   Invalid indices generate
// a run-time error and end the program.
// Accesses (by reference) the item at the specified index.
// Parameters:
//        index: the index position that the function is trying to access.
// Return Value:
//        the array element in the position index.
//==============================================================
template <typename T>
T &List<T>::operator[](int index) const
{
    int size = length();
    if (index < 0 || index >= size)
    {
        throw runtime_error("Error occurred! Invalid index!\n");
    }

    Node *currentNode = head;
    for (int i = 0; i < index; i++)
    {
        currentNode = currentNode->next;
    }

    return currentNode->item;
}
//==============================================================
// remove //! Last 3
// Valid indices are 0 to size-1.   Invalid indices generate
// a run-time error and end the program.
// Removes an item at the specified location. Valid indices are 0 to size-1.
// Invalid indices generate a run-time error and end the program.
// Parameters:
//        index: the index position of the element that the function is trying to remove.
// Return Value:
//        None
//==============================================================
template <typename T>
void List<T>::remove(int index)
{
    int size = length();
    if (index < 0 || index >= size)
    {
        throw runtime_error("Error occurred! Invalid index!\n");
    }

    Node *nodeToDelete = nullptr;

    if (index == 0)
    {
        nodeToDelete = head;
        head = head->next;

        delete nodeToDelete;
    }
    else
    {
        Node *currentNode = head;

        for (int i = 0; i < index - 1; ++i)
        {
            currentNode = currentNode->next;
        }

        nodeToDelete = currentNode->next;
        currentNode->next = nodeToDelete->next;

        delete nodeToDelete;
    }
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
    return head == nullptr;
}
//==============================================================
// operator+  (concatenate two lists) //! Last 3
// Concatenates two lists into a new list. Does not change either existing list.
// Parameters:
//        const List<T>& mylist: the List object
// Return Value:
//        newList: the result of the concatenation of two lists.
//==============================================================
//! 질문
template <typename T>
List<T> List<T>::operator+(const List<T> &mylist) const
{
    // Create a new list
    List<T> newConcatList(*this);

    // Add all elements from the second list
    Node *current = mylist.head;
    while (current != nullptr)
    {
        newConcatList.append(current->item);
        current = current->next;
    }

    return newConcatList;
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
    Node *currentNode = head;

    while (currentNode != nullptr)
    {
        Node *nextNode = currentNode->next;

        delete currentNode;

        currentNode = nextNode;
    }

    head = nullptr; //! Avoid dangling pointer
}