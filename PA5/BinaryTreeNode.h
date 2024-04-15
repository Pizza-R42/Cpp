#include <iostream>
using namespace std;

#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

class BinaryTreeNode {

public:
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

	BinaryTreeNode(int value) {
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
	}
};

#endif /* BINARYTREENODE_H_ */
