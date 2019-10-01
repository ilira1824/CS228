
// LinkedList.cpp

#include <stdlib.h>
#include "LinkedList.h"
#include <iostream>

// Default constructor, the list is empty to start

LinkedList::LinkedList() {
   head = sptr = temp = cur = NULL;
}

// Default destructor, must delete all nodes

LinkedList::~LinkedList() {

}

// Add a node containing "value" to the front

void LinkedList::InsertFront(double value) {
  sptr = new Node;
  sptr->data = value;

  if (head == NULL) {
    sptr -> next = NULL;
    head = sptr;
  }
  else {
    sptr->next = head;
    head = sptr;
  }
}

// Add a node containing "value" to position "index"

void LinkedList::Insert(double value, unsigned int index) {
    if (index == 0) {
      InsertFront(value);
      return;
    }

    sptr = new Node;
    sptr->data = value;
    
    temp = head;

    if (index > GetLength())
      throw -1;

    for(int i = 1; i < index; i++) {
      temp = temp->next;
    }

    sptr->next = temp->next;
    temp->next = sptr;
}

// Return value at position "index"

double LinkedList::GetNode(unsigned int index) {
  if (index > GetLength() - 1)
    throw -1;
  
  cur = head;

  for (int x = 0; x < index; x++) {
    cur = cur->next;
  }
  
  return cur->data;
}


// Return the index of the node containing "value"

unsigned int LinkedList::Search(double value) {
  cur = head;

  for (int index = 0; cur != NULL; index++) {
    if (cur->data == value)
      return index;
    cur = cur->next;
  }
  throw -1;
}


// Delete the node at position "index", return the value that was there

double LinkedList::DeleteNode(unsigned int index) {
  if (index > GetLength())
    throw -1;

  unsigned int val;
  cur = head;

  if (index == 0) {
    head = head->next; // Doesn't work if only 1 item in list
    val = cur->data;
    delete cur;
    return val;
  }

  for (int i = 1; i < index; i++) {
    cur = cur->next;
  }

  temp = cur->next;
  val = temp->data;
  temp = temp->next;
  delete cur->next;
  cur->next = temp;

  return val;
}

// This function reverses the order of all nodes so the first node is now the
// last and the last is now the first (and all between). So a list containing 
// (4, 0, 2, 11, 29) would be (29, 11, 2, 0, 4) after Reverse() is called.

void LinkedList::Reverse() {
   cur = head; 
   temp = NULL, sptr = NULL; 
  
        while (cur) { 
            // Store next 
            sptr = cur->next; 
  
            // Reverse current node's pointer 
            cur->next = temp; 
  
            // Move pointers one position ahead. 
            temp = cur; 
            cur = sptr; 
        } 
        head = temp; 

}

// Return the number of nodes in the list

int LinkedList::GetLength() {
  cur = head;
  int len = 0;

  while (cur) {
    cur = cur->next;
    len++;
  }

  return len;
}
