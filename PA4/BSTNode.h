#include <iostream>
using namespace std;

#ifndef BSTNODE_H_
#define BSTNODE_H_

class BSTNode {

public:

	int value, size;
	BSTNode *left, *right, *parent;

	BSTNode(int val) {
		// each node is inserted as a leaf
		value = val;
        size = 1;
		left = NULL;
		right = NULL;
		parent = NULL;
	}

	void toString() {
		if (parent == NULL)
			cout << "<" << value << ", null>";
		else
			cout << "<" << value << ", " << parent->value << ">";
	}
};

#endif
