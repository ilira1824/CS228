// main.cpp

#include <iostream>
#include "../DoubleStack.h"

using namespace std;

int main()
{
    cout << "Creating a double stack." << endl;

    DoubleStack ds;

    ds.PushA('a');
    ds.PushA('b');
    ds.PushB('c');
    ds.PushB('d');

    cout << "There are " << ds.size() << " items on the stack (should be 4)." << endl;

    cout << "Popped from A: " << ds.PopA() << " (should be b)." << endl;
    cout << "Popped from B: " << ds.PopB() << " (should be d)." << endl;

    ds.PushA('e');
    ds.PushA('f');
    ds.PushB('g');
    ds.PushB('h');

    cout << "There are " << ds.size() << " items on the stack (should be 6)." << endl;

    cout << "Top of A: " << ds.TopA() << " (should be f)." << endl;
    cout << "Top of B: " << ds.TopB() << " (should be h)." << endl;

    cout << "There are " << ds.size() << " items on the stack (should be 6)." << endl;

    for (int i = 0; i < 14; i++)
    {
        try
        {
            ds.PushA('i' + i);
        }
        catch (...)
        {
            cout << "Failed to push character " << 'i' + i << endl;
        }
    }

    try
    {
        ds.PushA('?');
        cout << "PushA should have failed!" << endl;
    }
    catch (...)
    {
        cout << "PushA properly failed" << endl;
    }

    try
    {
        ds.PushB('?');
        cout << "PushB should have failed!" << endl;
    }
    catch (...)
    {
        cout << "PushB properly failed" << endl;
    }


    for (int i = 0; i < 17; i++)
        ds.PopA();

    for (int i = 0; i < 3; i++)
        ds.PopB();


    try
    {
        cout << "Popped from A: " << ds.PopA() << " (fail)" << endl;
    }
    catch (...)
    {
        cout << "PopA properly failed" << endl;
    }

    try
    {
        cout << "Popped from B: " << ds.PopB() << " (fail)" << endl;
    }
    catch (...)
    {
        cout << "PopB properly failed" << endl;
    }






    cout << "Finished" << endl;

    return 0;
}

