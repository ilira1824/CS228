// DoubleStack.cpp
//
//
//
// Israel Lira


#include "DoubleStack.h"
#include <iostream>

// Default constructor, the stack is empty to start
DoubleStack::DoubleStack() {
    openA = 0;                    // Stack A starts at 0 index of array and works up
    openB = 19;                   // Stack B starts at 19 index of array and works down
}


// Default destructor
DoubleStack::~DoubleStack() {
// Insert your code here 
}

// Add "value" to the top of stack A
void DoubleStack::PushA(char value) {
    if (openA > openB)            // if the start of Stack A is greater than the start of Stack B
        throw -1;                 // Stack A cannot use Stack B memory
    
    arr[openA] = value;           // "Top" of stack is assigned value
    openA++;                      // Assign next open array spot
}

// Add "value" to the top of stack B
void DoubleStack::PushB(char value) {
    if (openB < openA)            // Stack B cannot go into Stack A memory
        throw -1;
    
    arr[openB] = value;
    openB--;
}

// Remove and return the item on the top of stack A
char DoubleStack::PopA() {
    if (openA == 0)               // Make sure stack A is populated
        throw -1;
    
    char c = TopA();
    openA--;                      // "Delete" top of stack A
    return c;
}

// Remove and return the item on the top of stack B
char DoubleStack::PopB() {
    if (openB == 19)              // Make sure stack B is populated
        throw -1;
    
    char c = TopB();
    openB++;                      // "Delete" top of stack B
    return c;
}

// Return the item on the top of stack A
char DoubleStack::TopA() {
    if (openA == 0)               // Make sure stack A is populated
        throw -1;
    
    return arr[openA - 1];        // Return whatever is before the "open" index
}

// Return the item on the top of stack B
char DoubleStack::TopB() {
    if (openB == 19)              // Make sure stack B is populated
        throw -1;
    
    return arr[openB + 1];        // Return whatever is before the "open" index
}

// Return the number of items in the stack
unsigned int DoubleStack::size() {
    return openA + (19 - openB);  // Return size of stack A PLUS stack B
}