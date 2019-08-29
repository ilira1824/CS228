// array.cpp

#include "array.h"

myArray::myArray()
{
    _size = 16;
    _array = new char[16];
}

myArray::myArray(int size)
{
    _size = size;
    _array = new char[size];
}

myArray::~myArray()
{
    delete [] _array;
}

void myArray::SetArray(char newVal, int index)
{
    _array[index] = newVal;
}

char myArray::GetArray(int index)
{
    return _array[index];
}

