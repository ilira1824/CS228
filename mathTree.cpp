// mathTree.cpp
#include <iostream>
#include <sstream>
#include <string>
#include "mathTree.h"

using namespace std;

string stringify(long double x) {
    ostringstream o;
    if (!(o << x))
        throw;
    return o.str();
}

// Default constructor

mathTree::mathTree() {
    root = t = NULL;
}

// Clean up any dynamically allocated data

mathTree::~mathTree() {

}

// Reads an expression in prefix notation and builds a tree appropriately

void mathTree::ReadExpression(string s) {
    string s2;
    
    root = new treeNode;
    s2 = _readex(root,s);
    
    if (s2 == "")
        return;
}

// Populates the node t (which has already been allocated) with the prefix expression exp

string mathTree::_readex(treeNode* t, string exp) {
    char first; 
    string remaining;
    float f;
    
    if (t == NULL)
        return "No Tree";
    
    if (exp == "") {
        t->leafNode = true;
        t->lChild = NULL;
        t->rChild = NULL;
    }
    
    first = exp[0];
    if (exp.find(" ") == std::string::npos)
        remaining = exp;
    remaining = exp.substr(exp.find(" ") + 1, exp.length());
    exp = exp.erase(0,exp.find(" "));
    
    
    if (first == '+' || first == '*')
        t->op = first;
    else {
        f = (float)(first);
        t->value = f;
    }

    t->leafNode = false;
    t->lChild = new treeNode;
    exp = _readex(t->lChild, exp);
    
    t->leafNode = false;
    t->rChild = new treeNode;
    exp = _readex(t->rChild, exp);
    
    return exp;
}

// Returns the result of evaluate() on the root of the tree

double mathTree::ExpressionValue() {
    return _evaluate(root);
}

// Returns the value of the expression rooted at t

double mathTree::_evaluate(treeNode* t) {
    if (t == NULL)
        return 0;
    
    int lval, rval;
    
    if (t->leafNode == true)
        return t->value;
    
    lval = _evaluate(t->lChild);
    rval = _evaluate(t->rChild);
    
    if (t->op == '*')
        return lval * rval;
    else if (t->op == '+')
        return lval + rval;
    else
        return -1;
}

// Traverses the tree, printing out an infix version of the expression, with parentheses around each expression

string mathTree::ReturnInfix() {
    return _inorder(root);
}

// Perform an inorder traversal of the tree starting at t

string mathTree::_inorder(treeNode* t)
{
    string s;
    if (t == NULL) // Base case: No recursion will occur if parent node has no children (leaf node)
        return "";
        
    if (t->leafNode == true)
        s += stringify(t->value);
    else {
        s += _inorder(t->lChild);
        s += t->op;
        s += _inorder(t->rChild);
    }
    
    return s;
}
