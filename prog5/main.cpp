// main.cpp

#include <iostream>
#include <string>
#include "../mathTree.h"


using namespace std;

void testTree(string s, string i, double v);

int main() {

    // Prefix notation: * + * 4 2 3 8
    // Infix version: (((4 * 2) + 3) * 8)
    // Evaluated value: 88

    testTree("+ 5 * 2 2", "( 5 + ( 2 * 2 ) )", 9);
    
    testTree("* * 3 + 1 2 2", "( ( 3 * ( 1 + 2 ) ) * 2 )", 18);
    
    testTree("+ 2.11 9.66", "( 2.11 + 9.66 )", 11.77);
    
    testTree("* 0.2 -1.0", "( 0.2 * -1.0 )", -0.2);
    
    testTree("* +", "FAIL", -100000);
    
    testTree("3.22", "3.22", 3.22);
    
    testTree("+ 1 2 3", "FAIL", -100000);        
            
    return 0;
}

void testTree(string s, string i, double v) {
    string infix;
    double value;


    cout << "Prefix notation: " << s << endl;
    mathTree m;
    try {
        m.ReadExpression(s);

        cout << "ReadExpression completed" << endl;

        try {
            infix = m.ReturnInfix();
            cout << "Infix: " << infix << " -- should be " << i << endl;
        }        catch (...) {
            cout << "ReturnInfix failed on " << s << endl;
        }

        try {
            value = m.ExpressionValue();
            cout << "Value: " << value << " -- should be " << v << endl;
        }        catch (...) {
            cout << "ExpressionValue failed on " << s << endl;
        }


    }    catch (...) {
        cout << "ReadExpression failed on " << s << endl;
    }

}