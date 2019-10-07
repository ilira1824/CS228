// DoubleStack.cpp

#include "DoubleStack.h"
#include <iostream>

// Default constructor, the stack is empty to start
DoubleStack::DoubleStack() {
// Insert your code here
    openA = 0;
    openB = 19;
}


// Default destructor
DoubleStack::~DoubleStack() {
// Insert your code here 
}

// Add "value" to the top of stack A
void DoubleStack::PushA(char value) {
    if (openA > openB)
        throw -1;
    
    arr[openA] = value;
    openA++;
}

// Add "value" to the top of stack B
void DoubleStack::PushB(char value) {
    if (openB < openA)
        throw -1;
    
    arr[openB] = value;
    openB--;
}

// Remove and return the item on the top of stack A
char DoubleStack::PopA() {
    if (openA == 0)
        throw -1;
    
    char c = TopA();
    openA--;
    return c;
}

// Remove and return the item on the top of stack B
char DoubleStack::PopB() {
    if (openB == 19)
        throw -1;
    
    char c = TopB();
    openB++;
    return c;
}

// Return the item on the top of stack A
char DoubleStack::TopA() {
    if (openA == 0)
        throw -1;
    
    return arr[openA - 1];
}

// Return the item on the top of stack B
char DoubleStack::TopB() {
    if (openB == 19)
        throw -1;
    
    return arr[openB + 1];
}

// Return the number of items in the stack
unsigned int DoubleStack::size() {
    return openA + (19 - openB);
}