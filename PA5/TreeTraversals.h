#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

#ifndef TREETRAVERSALS_H_
#define TREETRAVERSALS_H_

class TreeTraversals {
    
public:
    
    static void preOrder(BinaryTreeNode* node) { // complete this method
        cout << node->value << " ";
        if (node->left) {
            preOrder(node->left);
        }
        if (node->right) {
            preOrder(node->right);
        }
    }
    
    static void inOrder(BinaryTreeNode *node) { // complete this method
        if (node->left) {
            inOrder(node->left);
        }
        cout << node->value << " ";
        if (node->right) {
            inOrder(node->right);
        }
    }
    
    static void postOrder(BinaryTreeNode *node) { // complete this method
        if (node->left) {
            postOrder(node->left);
        }
        if (node->right) {
            postOrder(node->right);
        }
        cout << node->value << " ";
    }
};

#endif /* TREETRAVERSALS_H_ */
