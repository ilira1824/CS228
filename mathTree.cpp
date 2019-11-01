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
// Reads an expression in prefix notation and builds a tree appropriately
}


string mathTree::_readex(treeNode* t, string exp) {
// Populates the node t (which has already been allocated) with the prefix expression exp
}

double mathTree::ExpressionValue() {
// Returns the result of evaluate() on the root of the tree
}

double mathTree::_evaluate(treeNode* t) {
// Returns the value of the expression rooted at t
}

string mathTree::ReturnInfix() {
// Traverses the tree, printing out an infix version of the expression, with parentheses around each expression
}

string mathTree::_inorder(treeNode* t)
{
    if (t == NULL)
        return;
    _inorder(t->lChild);
    cout << t->value << endl;
    _inorder(t->rChild);
    cout << t->rChild << endl;
// Add content here  
}
