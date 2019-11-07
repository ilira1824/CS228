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
	s2 = _readex(root, s);
        
	if (s2 == "")
            return;
        else
            test = "FAIL";
}

// Populates the node t (which has already been allocated) with the prefix expression exp

string mathTree::_readex(treeNode* t, string exp) {
	string first;
	string remaining;
	float f;

	if (t == NULL)
		return "No Tree";

	if (exp == "") {
		t->leafNode = true;
		t->lChild = NULL;
		t->rChild = NULL;
		return "";
	}

	if (exp.find(" ") == std::string::npos) {
		first = exp;
		remaining = "";
		exp = "";
	}
	else {
		first = exp.substr(0, exp.find(" "));
		remaining = exp.substr(exp.find(" ") + 1, exp.length());
		exp = exp.erase(0, exp.find(" "));
	}


	if (first == "+" || first == "*") {
		t->op = first;
		t->lChild = NULL;
		t->rChild = NULL;
		if (exp == "") {
			test = "FAIL";
			return "";
		}

	}

	else {
		f = stof(first);
		t->value = f;
		t->leafNode = true;
		return remaining;
	}

	t->leafNode = false;

	if (t->leafNode == false) {
		if (t->lChild == NULL) {
			t->lChild = new treeNode;
			exp = _readex(t->lChild, remaining);
		}

		if (t->rChild == NULL) {
			t->rChild = new treeNode;
			exp = _readex(t->rChild, exp);
		}
	}

	return exp;
}

// Returns the result of evaluate() on the root of the tree

double mathTree::ExpressionValue() {
    if (test == "FAIL")
        return -100000;
    return _evaluate(root);
}

// Returns the value of the expression rooted at t

double mathTree::_evaluate(treeNode* t) {
	if (t == NULL)
		return 0;

	double lval, rval;

	if (t->leafNode == true)
		return t->value;

	lval = _evaluate(t->lChild);
	rval = _evaluate(t->rChild);

	if (t->op == "*")
		return lval * rval;
	else if (t->op == "+")
		return lval + rval;
	else
		return -1;
}

// Traverses the tree, printing out an infix version of the expression, with parentheses around each expression

string mathTree::ReturnInfix() {
    if (test == "FAIL")
        return test;
    
    return _inorder(root);
}

// Perform an inorder traversal of the tree starting at t

string mathTree::_inorder(treeNode* t)
{
	string s;
	if (t == NULL) // Base case: No recursion will occur if parent node has no children (leaf node)
		return "";

	if (t->leafNode == true) {
            s += stringify(t->value);
        }
            
	else {
            s += "( ";
            s += _inorder(t->lChild);
            s += " ";
            s += t->op;
            s += " ";
            s += _inorder(t->rChild);
            s += " )";
	}

	return s;
}
