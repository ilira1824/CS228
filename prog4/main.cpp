// main.cpp

#include <iostream>
#include "../Airport.h"

using namespace std;

int main() {
    
    char x[128];
    
    cout << "Starting the first simulation." << endl;

    Airport(5, 2, 0.1, 0.2, 45, 120);

    cout << "First simulation finished (press enter to continue)" << endl;

    cin >> x;

    cout << "Starting the second simulation." << endl;

    Airport(15, 10, 0.9, 0.9, 30, 1440);

    cout << "Second simulation finished" << endl;
    
    return 0;
}

