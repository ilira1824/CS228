// main.cpp

#include <iostream>
#include "../array.h"

using namespace std;

int main() {
    cout << "Creating a character array of size 7." << endl;

    myArray newArr(7);
    newArr.SetArray('I', 0);
    newArr.SetArray('s', 1);
    newArr.SetArray('r', 2);
    newArr.SetArray('a', 3);
    newArr.SetArray('e', 4);
    newArr.SetArray('l', 5);
    newArr.SetArray('!', 6);

    cout << "Array contents: " << newArr.GetArray(0) <<
            newArr.GetArray(1) << newArr.GetArray(2) <<
            newArr.GetArray(3) << newArr.GetArray(4) << newArr.GetArray(5) << newArr.GetArray(6) << endl;

    return 0;
}

