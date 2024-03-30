#include <iostream>
#include "BSTNode.h"
using namespace std;

#ifndef BST_H_
#define BST_H_

class BST {

public:

	BSTNode *root;

	BST() {
		root = NULL;
	}

	BST(int *A, int length) {
		root = NULL;
		for (int i = 0; i < length; i++)
			insert(A[i]);
	}

	~BST() {
		if (root != NULL)
			deepClean(root);
	}

	BSTNode *search(int key) {
		BSTNode *tmp = root;
		while (tmp != NULL) {
			if (tmp->value == key)
				return tmp;
			else if (tmp->value > key)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		return NULL;
	}

    BSTNode *insert(int key) { // complete this method
		
		if (size() == 0) {
			root = new BSTNode(key);
			return root;
		}

		BSTNode* tmp = root;
		BSTNode* parent = NULL;
		while (tmp != NULL) {
			if (tmp->value == key) {
				return NULL;
			}
			else if (tmp->value < key) {
				parent = tmp;
				tmp = tmp->right;
			}
			else {
				parent = tmp;
				tmp = tmp->left;
			}
		}

		BSTNode* newNode = new BSTNode(key); 
		newNode->parent = parent; 

		if (parent->value > key)
			parent->left = newNode;
		else
			parent->right = newNode;

		while (parent != NULL) {
			parent->size++;
			parent = parent->parent;
		}

		return newNode;
    }

    bool remove(int key) { // complete this method
		BSTNode* nodeToBeDeleted = search(key); 
		if (nodeToBeDeleted == NULL) 
			return false;
		 
		BSTNode* parent = nodeToBeDeleted->parent; 

		if (nodeToBeDeleted->left != NULL && nodeToBeDeleted->right != NULL) { 
			BSTNode* maxNode = findMax(nodeToBeDeleted->left); 
			nodeToBeDeleted->value = maxNode->value; 
			nodeToBeDeleted = maxNode; 
		}
		parent = nodeToBeDeleted->parent;
		while (parent != NULL) {
			parent->size--;  
			parent = parent->parent; 
		} 

		if (nodeToBeDeleted->left == NULL && nodeToBeDeleted->right == NULL) 
			removeLeaf(nodeToBeDeleted); 
		else
			removeNodeWithOneChild(nodeToBeDeleted);

		return true;
    }

private:

    void removeLeaf(BSTNode *leaf) { // complete this method
		if (leaf == root) {
			delete root;
			root = NULL;
		}
		else {
			BSTNode* parent = leaf->parent;
			if (parent->left == leaf)
				parent->left = NULL;
			else
				parent->right = NULL;
			delete leaf;
		}
    }

    void removeNodeWithOneChild(BSTNode *node) { // complete this method
		BSTNode* child = (node->left != NULL) ? node->left : node->right;

		if (node == root) {
			root = child;
			if (child != NULL)
				child->parent = NULL;
			delete node;
		}
		else {
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;

			if (child != NULL)
				child->parent = node->parent;

			delete node;
		}
    }

public:

    BSTNode* lca(int x, int y) { // complete this method
		BSTNode* nodeX = search(x);
		BSTNode* nodeY = search(y);

		if (nodeX == NULL || nodeY == NULL)
			return NULL;

		if (x == y)
			return nodeX;

		int minVal = min(x, y);
		int maxVal = max(x, y);

		BSTNode* tmp = root;
		while (tmp != NULL) {
			if (tmp->value < minVal)
				tmp = tmp->right;
			else if (tmp->value > maxVal)
				tmp = tmp->left;
			else
				break;
		}
		return tmp;
    }

    int rank(int key) { // complete this method
		int rank = 0;
		BSTNode* tmp = root;

		while (tmp != NULL) {
			if (tmp->value <= key) {
				rank++;
				if (tmp->left != NULL)
					rank += tmp->left->size;
				tmp = tmp->right;
			}
			else {
				tmp = tmp->left;
			}
		}
		return rank;
    }

	static BSTNode *findMin(BSTNode *node) {
		if (NULL == node)
			return NULL;
		while (node->left != NULL) {
			node = node->left;
		}
		return node;
	}

	static BSTNode *findMax(BSTNode *node) {
		if (NULL == node)
			return NULL;
		while (node->right != NULL) {
			node = node->right;
		}
		return node;
	}

	void print(BSTNode *node) {
		if (NULL != node) {
			node->toString();
			cout << " ";
			print(node->left);
			print(node->right);
		}
	}

	static int getHeight(BSTNode *node) {
		if (node == NULL)
			return 0;
		else
			return 1 + max(getHeight(node->left), getHeight(node->right));
	}

	static void deepClean(BSTNode *node) {
		if (node->left != NULL)
			deepClean(node->left);
		if (node->right != NULL)
			deepClean(node->right);
		delete node;
	}

public:

	int getTreeHeight() {
		return getHeight(root);
	}

	void print() {
		print(root);
	}

	int size() {
		return root == NULL ? 0 : root->size;
	}
};

#endif
