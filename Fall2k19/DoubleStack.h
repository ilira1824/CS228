// DoubleStack.h

#ifndef __DOUBLESTACK_H__
#define __DOUBLESTACK_H__

class DoubleStack
{
public:
  DoubleStack();         // Default constructor, the stack is empty to start
  ~DoubleStack();        // Default destructor

  void PushA(char value); // Add "value" to the top of stack A
  void PushB(char value); // Add "value" to the top of stack B

  char PopA(); // Remove and return the item on the top of stack A
  char PopB(); // Remove and return the item on the top of stack B

  char TopA(); // Return the item on the top of stack A
  char TopB(); // Return the item on the top of stack B

  unsigned int size();        // Return the number of items in the stack

private:
    char arr[20];
    int openA, openB;
};


#endif
