//***********************************************************
// LinkedListExample.cpp
// CS 173
// Spring 2025
// Practice creating and traversing a linked list
//***********************************************************

#include <iostream>
using namespace std;

// Struct to represent each node in the list
struct Node{
  float item;
  Node* next;
};

Node* createList();
void printList(Node*);
void deleteList(Node*);
float findMinimum(Node*);

int main() {
  Node* head = createList();
  printList(head);
  cout << endl << "Minimum element in list: " << findMinimum(head) << endl;
  deleteList(head);
  head = nullptr;
  return 0;
}

//***********************************************************
// printList
// Input: headPtr, a pointer to the first node
// Outputs each value on a separate line to cout
//***********************************************************
void printList( Node* headPtr){
  cout << "Not implemented yet" << endl;
}

//***********************************************************
// findMinimum
// Input: headPtr, a pointer to the first node
// Returns the minimum value in the list
//***********************************************************
float findMinimum( Node* headPtr){
  return 0.0;
}

//***********************************************************
// createList
// Prompts a user for floats to add to the list
// Ends prompting when user does not indicate 'y'
// Returns a pointer to the head of the list
//***********************************************************
Node* createList(){
  // use a flag to exit the loop when the user is done
  bool addNewNode = true;
  char yesOrNo = 'y';

  // references to the head of the list and the most recently added item
  Node* head = nullptr; 
  Node* current = nullptr;

  while (addNewNode){
    // special case: the first item
    if (head == nullptr){
      head = new Node;
      current = head;
    }
    else{
      // point the previous node to the new current node
      current -> next = new Node;
      current = current -> next;
      current -> next = nullptr;
    }
     

    // prompt user for current node's value
    cout << "Enter a floating point value: ";
    cin >> current -> item;

    // prompt user to continue
    cout << "Enter another value? (y/n)";
    cin >> yesOrNo;
    addNewNode = yesOrNo == 'y';
  }

  return head;
}

//***********************************************************
// deleteList
// Input: headPtr, a pointer to the first node
// Cleans up the list, deleting every node
//***********************************************************
void deleteList( Node* headPtr){
  Node* tempPtr;

  while (headPtr != nullptr){ 
    tempPtr = headPtr;
    headPtr = headPtr -> next;
    delete tempPtr;
  }
}
