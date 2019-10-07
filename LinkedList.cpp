
// LinkedList.cpp

#include <stdlib.h>
#include "LinkedList.h"

// Default constructor, the list is empty to start

LinkedList::LinkedList() {
	head = sptr = temp = cur = NULL;
}

// Default destructor, must delete all nodes

LinkedList::~LinkedList() {
	while (head) {
		sptr = head;			// Save node
		head = head->next;		// Traverse through list
		delete sptr;			// Delete stored node
	}
}

// Add a node containing "value" to the front

void LinkedList::InsertFront(double value) {
	sptr = new Node;				// Assign input value to the dynamically created node
	sptr->data = value;

	if (head == NULL) {				// If the list is empty
		sptr->next = NULL;
		head = sptr;				// New node becomes head, it's next pointer is NULL
	}
	else {
		sptr->next = head;
		head = sptr;				// New node becomes head, it's next pointer is old head
	}
}

// Add a node containing "value" to position "index"

void LinkedList::Insert(double value, unsigned int index) {
	if (index > GetLength() || index < 0)	// Throw function if index goes beyond end of list or negative number; Sanitize inputs
		throw - 1;

	if (index == 0) {				// 0 index would be the front of the list, already built function for head (InsertFront)
		InsertFront(value);
		return;
	}

	sptr = new Node;				// Dynamically create node and assign value to it
	sptr->data = value;

	temp = head;

	for (int i = 1; i < index; i++) {		// Have Temp pointer traverse through list until PRECEDING node of index
		temp = temp->next;
	}

	sptr->next = temp->next;		// New node points to SUCCEDING node of index
	temp->next = sptr;				// Preceding node points to new node
}

// Return value at position "index"

double LinkedList::GetNode(unsigned int index) {
	if (index > GetLength() - 1 || index < 0)	// Throw function if index goes beyond end of list or negative number
		throw - 1;

	cur = head;

	for (int x = 0; x < index; x++) {			// Traverse through list to SPECIFIED node
		cur = cur->next;
	}

	return cur->data;							// Return value of node
}


// Return the index of the node containing "value"

unsigned int LinkedList::Search(double value) {
	cur = head;

	for (int index = 0; cur != NULL; index++) {		// Traverse thorugh list until input value equals value of node
		if (cur->data == value)
			return index;
		cur = cur->next;
	}
	throw - 1;									// If traversed through entire list and no node found, it doesn't exist
}


// Delete the node at position "index", return the value that was there

double LinkedList::DeleteNode(unsigned int index) {
	if (index > GetLength() || index < 0) // Sanitize inputs
		throw - 1;

	unsigned int val;
	cur = head;

	if (index == 0) {			// If head of list
		head = head->next;		// New head is equal to what head points to
		val = cur->data;		// Save value of deleted node
		delete cur;				// Free memory of "deleted" node
		return val;
	}

	for (int i = 1; i < index; i++) {	// If not head, traverse through list to PRECEDING node
		cur = cur->next;
	}

	temp = cur->next;			// Temp points to node to be deleted
	val = temp->data;			// Save value of node to be deleted
	temp = temp->next;			// Temp now points to SUCCEDING node
	delete cur->next;			// Free memory of "deleted node"
	cur->next = temp;			// PRECEDING node now points to SUCCEDING node

	return val;
}

// This function reverses the order of all nodes so the first node is now the
// last and the last is now the first (and all between). So a list containing 
// (4, 0, 2, 11, 29) would be (29, 11, 2, 0, 4) after Reverse() is called.

void LinkedList::Reverse() {
	cur = head;
	temp = NULL, sptr = NULL;

	while (cur) {
		sptr = cur->next;		// Store next

		cur->next = temp;		// Reverse cur node's pointer

		temp = cur;				// Move pointers one position ahead
		cur = sptr;
	}
	head = temp;

}

// Return the number of nodes in the list
// Traverses through list to determine length, doesn't use private length variable in class

int LinkedList::GetLength() {
	cur = head;
	int len = 0;

	while (cur) {
		cur = cur->next;
		len++;
	}

	return len;
}