#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <climits>
#include <list>
#include <iterator>

#include "BST.h"
#include "HashingWithChaining.h"
#include "HashingWithProbing.h"

using namespace std;

int arrayIns[] = { 11, 12, 15, 17, 12, 19, 4, 5, 11, 19, 20, 32, 77, 65, 66, 88,
		99, 10, 8, 19, 15, 66, 11, 19, 0, 3, 2, 55, 67, 78, 39 };
const int numInsert = sizeof(arrayIns) / sizeof(int);

int searchArray[] = { 29, 3, 19, 27, 12, 34, 4, 5, 19, 20, 32, 45, 37, 25, 99,
		25, 8, 24, 12, 16 };
const int numSearch = sizeof(searchArray) / sizeof(int);

int deleteArray[] = { 11, 16, 12, 15, 5, 17, 19, 4, 5, 20, 32, 17, 19, 39, 99,
		10, 8, 19, 15, 21, 0, 55, 3, 78, 66 };
const int numDelete = sizeof(deleteArray) / sizeof(int);

const int cleanUp[] = { 77, 65, 2, 88, 39, 67 };
const int numCleanUp = sizeof(cleanUp) / sizeof(int);

static const int CHAINING_TABLE_SIZE = 7;
static const int INITIAL_PROBING_TABLE_SIZE = 2;

void printArray(int *A, int len) {
	if (0 == len)
		cout << "[]";
	else {
		cout << "[";
		for (int i = 0; i < len - 1; i++) {
			if (A[i] == INT_MAX)
				cout << "infty, ";
			else
				cout << A[i] << ", ";
		}
		if (A[len - 1] == INT_MAX)
			cout << "infty]";
		else
			cout << A[len - 1] << "]";
		cout << endl;
	}
}

void printArray(vector<int> &A, int len) {
    if (0 == len)
        cout << "[]";
    else {
        cout << "[";
        for (int i = 0; i < len - 1; i++) {
            if (A[i] == INT_MAX)
                cout << "infty, ";
            else
                cout << A[i] << ", ";
        }
        if (A[len - 1] == INT_MAX)
            cout << "infty]";
        else
            cout << A[len - 1] << "]";
        cout << endl;
    }
}

void printList(list<int> &A) {
	if (0 == A.size())
		cout << "[]" << endl;
	else {
		list<int>::iterator it;
		cout << "[";
		for (it = A.begin(); next(it) != A.end(); ++it)
			cout << *it << ", ";
		cout << *it << "]";
		cout << endl;
	}
}

void printList(list<int> *A) {
	if (0 == A->size())
		cout << "[]" << endl;
	else {
		list<int>::iterator it;
		cout << "[";
		for (it = A->begin(); next(it) != A->end(); ++it)
			cout << *it << ", ";
		cout << *it << "]";
		cout << endl;
	}
}

HashingWithChaining *testHashing() {
	cout << "****************** Hashing with Chaining ******************"
			<< endl << endl;
	HashingWithChaining *hChain = new HashingWithChaining(CHAINING_TABLE_SIZE);

	cout << "Inserting the following numbers: ";
	printArray(arrayIns, numInsert);

	for (int i = 0; i < numInsert; i++) {
		hChain->insert(arrayIns[i]);
	}

	cout << endl << "*** Hash Table Structure (after insertion) ***" << endl;
	int size = 0;
	for (int i = 0; i < CHAINING_TABLE_SIZE; i++) {
		cout << "Slot " << i << ": ";
		printList(hChain->hashTable[i]);
		size += hChain->hashTable[i].size();
	}
	cout << endl << "Size of hash table: " << size << endl;

	cout << "\n*** Searching Hash Table ***" << endl;
	list<int> foundList;
	list<int> notFoundList;

	for (int i = 0; i < numSearch; i++) {
		int val = searchArray[i];
		bool found = hChain->search(val);
		if (found)
			foundList.push_back(val);
		else
			notFoundList.push_back(val);
	}
	cout << "Found: ";
	printList(foundList);
	cout << "Did not find: ";
	printList(notFoundList);
	cout << endl << "*** Deleting Hash Table ***" << endl;

	list<int> deleteList;
	list<int> deleteNotFoundList;
	for (int i = 0; i < numDelete; i++) {
		int val = deleteArray[i];
		bool deleted = hChain->remove(val);
		if (deleted)
			deleteList.push_back(val);
		else
			deleteNotFoundList.push_back(val);
	}
	cout << "Deleted: ";
	printList(deleteList);
	cout << "Did not find: ";
	printList(deleteNotFoundList);

	cout << endl << "*** Hash Table Structure (after deletion) ***" << endl;
	size = 0;
	for (int i = 0; i < CHAINING_TABLE_SIZE; i++) {
		cout << "Slot " << i << ": ";
		printList(hChain->hashTable[i]);
		size += hChain->hashTable[i].size();
	}
	cout << endl << "Size of hash table: " << size << endl;
	return hChain;
}



HashingWithProbing *testProbing() {
	cout << "\n****************** Hashing with Probing ******************"
			<< endl << endl;
	HashingWithProbing *hProbing = new HashingWithProbing(
			INITIAL_PROBING_TABLE_SIZE);

	cout << "Inserting the following numbers: ";
	printArray(arrayIns, numInsert);

	for (int i = 0; i < numInsert; i++) {
		hProbing->insert(arrayIns[i]);
	}

	cout << endl << "*** Hash Table Structure (after insertion) ***" << endl;
	printArray(hProbing->hashTable, hProbing->capacity());
	cout << endl << "Size of hash table: " << hProbing->size() << endl;

	cout << "\n*** Searching Hash Table ***" << endl;
	list<int> foundList;
	list<int> notFoundList;

	for (int i = 0; i < numSearch; i++) {
		int val = searchArray[i];
		if (hProbing->search(val) >= 0)
			foundList.push_back(val);
		else
			notFoundList.push_back(val);
	}
	cout << "Found: ";
	printList(foundList);
	cout << "Did not find: ";
	printList(notFoundList);
	cout << endl << "*** Deleting Hash Table ***" << endl;

	list<int> deleteList;
	list<int> deleteNotFoundList;
	for (int i = 0; i < numDelete; i++) {
		int val = deleteArray[i];
		if (hProbing->remove(val) >= 0)
			deleteList.push_back(val);
		else
			deleteNotFoundList.push_back(val);
	}
	cout << "Deleted: ";
	printList(deleteList);
	cout << "Did not find: ";
	printList(deleteNotFoundList);

	cout << endl << "*** Hash Table Structure (after deletion) ***" << endl;
	printArray(hProbing->hashTable, hProbing->capacity());
	cout << endl << "Size of hash table: " << hProbing->size() << endl;
	return hProbing;
}

BST *testBST() {
	cout << "\n****************** BST ******************" << endl << endl;

	BST *bst = new BST();
	cout << "Inserting the following numbers: ";
	printArray(arrayIns, numInsert);

	for (int i = 0; i < numInsert; i++) {
		bst->insert(arrayIns[i]);
	}

	cout << endl << "*** BST Structure (after insertion) ***" << endl;
	bst->print();
	cout << endl << endl << "Size of BST: " << bst->size() << endl;

	cout << "\n*** Searching BST ***" << endl;
	list<int> foundList;
	list<int> notFoundList;

	for (int i = 0; i < numSearch; i++) {
		int val = searchArray[i];
		if (bst->search(val) != NULL)
			foundList.push_back(val);
		else
			notFoundList.push_back(val);
	}
	cout << "Found: ";
	printList(foundList);
	cout << "Did not find: ";
	printList(notFoundList);
	cout << endl << "*** Deleting BST ***" << endl;

	list<int> deleteList;
	list<int> deleteNotFoundList;
	for (int i = 0; i < numDelete; i++) {
		int val = deleteArray[i];
		bool deleted = bst->remove(val);
		if (deleted)
			deleteList.push_back(val);
		else
			deleteNotFoundList.push_back(val);
	}
	cout << "Deleted: ";
	printList(deleteList);
	cout << "Did not find: ";
	printList(deleteNotFoundList);

	cout << endl << "*** BST Structure (after deletion) ***" << endl;
	bst->print();
	cout << endl << endl << "Size of BST: " << bst->size() << endl;
	return bst;
}

void testBSTApplications() {
    cout << "\n\n****************** BST Applications ******************"
    << endl << endl;
    int testArray[] = {50, 25, 80, 15, 40, 60, 90, 10, 20, 35, 45, 55, 65, 85, 95};
    int lenTestArray = sizeof(testArray)/sizeof(int);
    cout << "Numbers in BST: ";
    printArray(testArray, lenTestArray);
    cout << endl;
    BST bst(testArray, lenTestArray);
    int LCA1[] = {20, 35, 95, 90, 40, 23, 82};
    int LCA2[] = {45, 45, 25, 65, 40, 85, 35};
    int lcaLength = sizeof(LCA1)/sizeof(int);
    for (int i = 0; i < lcaLength; i++) {
        BSTNode *lca = bst.lca(LCA1[i], LCA2[i]);
        cout << "LCA of " << LCA1[i] << " and " << LCA2[i] << " is ";
        if (lca == NULL)
            cout << "undefined" << endl;
        else cout << lca->value << endl;
    }
    cout << endl;
    int RANK[] = {10, 54, 18, 42, 37, 34, 9, 95, 57, 44, 67, 88, 62, 47, 100};
    for (int key : RANK)
        cout << "Rank of " << key << " is " << bst.rank(key) << endl;
    
}

static void cleanTest(HashingWithChaining *chaining,
		HashingWithProbing *probing, BST *bst) { 
	cout << "\n****************** Clean up ******************" << endl;
	for (int i = 0; i < numCleanUp; i++) {
		chaining->remove(cleanUp[i]);
		probing->remove(cleanUp[i]);
		bst->remove(cleanUp[i]);
	}
	int size = 0;
	for (int i = 0; i < CHAINING_TABLE_SIZE; i++)
		size += chaining->hashTable[i].size();

	cout << "\nSize of chaining: " << size << endl;
	cout << "Size of probing: " << probing->size() << endl;
	cout << "Size of BST: " << bst->size();
}

int main() {
	HashingWithChaining *chaining = testHashing();
	HashingWithProbing *probing = testProbing();
	BST *bst = testBST();
	cleanTest(chaining, probing, bst);
	delete chaining;
	delete probing;
	delete bst;
	testBSTApplications();
	return 1;
}
