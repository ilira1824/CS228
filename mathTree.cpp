// mathTree.cpp
#include <iostream>
#include <sstream>
#include "mathTree.h"

using namespace std;

string stringify(long double x) {
    ostringstream o;
    if (!(o << x))
        throw;
    return o.str();
}

mathTree::mathTree() {
// Add content here
}

mathTree::~mathTree() {
// Add content here
}

void mathTree::ReadExpression(string s) {
// Add content here
}


string mathTree::_readex(treeNode* t, string exp) {
// Add content here
}

double mathTree::ExpressionValue() {
// Add content here
}

double mathTree::_evaluate(treeNode* t) {
// Add content here
}

string mathTree::ReturnInfix() {
    // Add content here
}

string mathTree::_inorder(treeNode* t)
{
// Add content here  
}