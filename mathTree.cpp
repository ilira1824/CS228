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
    deleteTree(root);
}

void mathTree::deleteTree(treeNode* t) {
    if (t == NULL) return;  
  
    // Does postorder traversal of list so we don't lose where the children are
    // Recursively deletes both subtrees
    deleteTree(t->lChild);  
    deleteTree(t->rChild);  
    
    // Then deletes parent node
    delete(t);  
}

// Reads an expression in prefix notation and builds a tree appropriately

void mathTree::ReadExpression(string s) {
    string s2;

    root = new treeNode;
    s2 = _readex(root, s);

    if (s2 == "")               // If s2 is not empty, than the tree built is invalid
        return;
    else
        test = "FAIL";
}

// Populates the node t (which has already been allocated) with the prefix expression exp

string mathTree::_readex(treeNode* t, string exp) {
    string first;
    string remaining;

    if (t == NULL)              // Sanitize inputs: can't send a null pointer
        return "FAIL";

    if (exp == "") {            //Base case: if string is empty, stop building the tree
        return exp;
    }

    /*********STRING MANIPLUATION***********/
    // Two strings, first and remaining
        // first holds what will be insert into the node
        // remaining holds everything after first, useful for recursion
    
    
    // If the string has no space, then string has last value to be input into tree
    // Ex. "3", the string has no space and is therefore the last element to be set in the tree
    // Remaining is just empty string
    if (exp.find(" ") == std::string::npos) {
        first = exp;
        remaining = "";
        exp = "";
    }
    // If there are spaces, then the first string is equal to the exp string up to the first space
    // the remaining string is equal to the exp string after the first string
    else {
        first = exp.substr(0, exp.find(" "));
        remaining = exp.substr(exp.find(" ") + 1, exp.length());
        exp = exp.erase(0, exp.find(" "));
    }
    
    
    /********ADDING VALUE TO NODE************/
    // Multiple things to do depending on if first string is an operator or not
        // If first is operator, prepare node for recursion
        // If it's a value, return what's left of string
    
    // If first string is an operator, set the op data element to first string
    // Since it has an operator, it CANNOT be a leaf node
    // If the remaining node is empty, the expression is invalid. The tree would have operators with no values to operate on
    if (first == "+" || first == "*") {
        t->op = first;
        t->leafNode = false;
        if (exp == "") {
            test = "FAIL";
            return "";
        }
    }
    
    // If it's not an operator, then it's a value
    // The node is a leaf node since values CANNOT have children
    // Set the value data element of t equal to the DOUBLE version of the first string
    // Return remaining so recursion can continue if needed
    else {
        t->value = stod(first);
        t->leafNode = true;
        t->lChild = NULL;
        t->rChild = NULL;
        return remaining;
    }

    
    /***********RECURSION*************/
    // The code will only get to this point if it's at non-leaf node and if remaining isn't empty
    
    // If the current node is a non-leaf Node and remaining still have stuff in it
    // Create a new treeNode and have the lChild data element point to it
    // Then perform recursion and send it the remaining string
    if (t->leafNode == false) {
        t->lChild = new treeNode;
        exp = _readex(t->lChild, remaining);

        // Since the recursion returns exp as a string, exp effectively becomes the new remaining string
        // Perform recursion again but send exp instead of remaining
        t->rChild = new treeNode;
        exp = _readex(t->rChild, exp);
    }

    // Return whatever is remaining of the original string, should be empty if the tree is valid
    return exp;
}

// Returns the result of evaluate() on the root of the tree

double mathTree::ExpressionValue() {
    if (test == "FAIL")                 // Checks to see the tree built from Readexpression is valid
        return -100000;
    return _evaluate(root);
}

// Returns the value of the expression rooted at t

double mathTree::_evaluate(treeNode* t) {
    if (t == NULL)
        return 0;

    double lval, rval;

    if (t->leafNode == true)            // Base case, just return value of node
        return t->value;

    
    // lval holds the value of the left subtree
    // rval holds the value of the right subtree
    lval = _evaluate(t->lChild);
    rval = _evaluate(t->rChild);

    
    // Do whatever operation the op data element of the parent on the values of both subtrees
    if (t->op == "*")
        return lval * rval;
    else if (t->op == "+")
        return lval + rval;
    else
        return -1;
}

// Traverses the tree, printing out an infix version of the expression, with parentheses around each expression

string mathTree::ReturnInfix() {
    if (test == "FAIL")                     // Checks to see the tree built from Readexpression is valid
        return test;

    return _inorder(root);
}

// Perform an inorder traversal of the tree starting at t

string mathTree::_inorder(treeNode* t) {
    string s;
    if (t == NULL)
        return "";

    if (t->leafNode == true) {              // Base Case: just add the value of the node to a string
        s += stringify(t->value);
    }
    else {                             
        s += "( ";
        s += _inorder(t->lChild);           // Recursively adds the value of the left subtree to the s string
        s += " ";
        s += t->op;                         // Adds value of parent to the s string
        s += " ";
        s += _inorder(t->rChild);           // Recursively adds the value of the right subtree to the s string
        s += " )";
    }

    return s;
}
