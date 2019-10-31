// array.h

#ifndef __ARRAY_H__
#define __ARRAY_H__

class myArray
{
public:
  myArray();         // Default constructor, creates an array of length 16
  myArray(int size); // Constructor, creates an array of length x
  ~myArray();        // Default destructor

  void SetArray(char newVal, int index); // Set value at array[index] to newVal
  char GetArray(int index);         // Return value at array[index]

  int GetSize() { return _size; }// Return the size of the array

private:
  int _size;      // The number of elements in the array
  char *_array;      // The array itself, dynamically allocated

};


#endif

