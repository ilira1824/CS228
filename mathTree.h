// mathTree.h

#ifndef __MATHTREE_H__
#define __MATHTREE_H__

#include <string>
using namespace std;

struct treeNode {
    bool leafNode; // true for leaves, false otherwise
    char op;       // For non-leaves, this can be '+' or '*'
    double value;  // Numeric value for leaves

    treeNode* lChild; // Pointer to left child node, NULL if we're at a leaf
    treeNode* rChild; // Pointer to right child node, NULL if we're at a leaf
};

class mathTree {
public:
    mathTree(); // Set stuff up in the constructor
    ~mathTree(); // Clean up any dynamically-allocated data here

    double ExpressionValue(); // Returns the result of evaluate() on
                          // the root of the tree
    
    void ReadExpression(string s); // Reads an expression in prefix 
                          // notation & builds a tree appropriately
    
    string ReturnInfix(); // Traverses the tree, returning an infix 
                          // version of the expression as a string,
                          // with parentheses around each expression 

private:
    double _evaluate(treeNode* t); // Returns the value of the 
                                  // expression rooted at t
    
    string _readex(treeNode* t, string exp);
    string _inorder(treeNode* t);
    
    treeNode *root, *t;
    
};

#endif

