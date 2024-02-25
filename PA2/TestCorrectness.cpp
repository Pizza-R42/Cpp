#include "LinkedList.h"
#include "DynamicArray.h"
#include "BinarySearchApplications.h"
#include "StackAndQueue.h"

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
	}
}

void testBinarySearch() {
	BinarySearchApplications proj1;
	int A[] = { 1, 1, 3, 7, 9, 14, 14, 14, 14, 14, 14, 18, 27, 39, 39, 39 };
	int length = sizeof(A) / sizeof(int);
    cout << "****************** Finding Predecessor ******************" << endl << endl;

	int B[] = { 1, 0, 39, 47, 36, 12, 6 };
	cout << "Array is ";
	printArray(A, sizeof(A) / sizeof(int));
	cout << endl;
	for (int i = 0; i < sizeof(B) / sizeof(int); i++) {
		int key = B[i];
		int x = proj1.predecessor(A, length, key);
		if (x >= 0)
			cout << "Predecessor of " << B[i] << " is " << A[x] << endl;
		else
			cout << "Predecessor of " << B[i] << " is not defined." << endl;
	}

	cout << "\n****************** Peak Finding ******************\n" << endl;
	int C_1[] = { 15, 18, 21, 25, 29, 31, 35, 23, 14, 9, 1, -1 };
	cout << "Array is ";
	printArray(C_1, sizeof(C_1) / sizeof(int));
	cout << ". Max is at index "
			<< proj1.findPeak(C_1, sizeof(C_1) / sizeof(int));
	cout << endl;

	int C_2[] = { 31, 35, 23, 14, 9, 1, -1 };
	cout << "Array is ";
	printArray(C_2, sizeof(C_2) / sizeof(int));
	cout << ". Max is at index "
			<< proj1.findPeak(C_2, sizeof(C_2) / sizeof(int));
	cout << endl;

	int C_3[] = { 31, 35, 37, 39 };
	cout << "Array is ";
	printArray(C_3, sizeof(C_3) / sizeof(int));
	cout << ". Max is at index "
			<< proj1.findPeak(C_3, sizeof(C_3) / sizeof(int));
	cout << endl;

	int C_4[] = { 36, 35, 32, 29 };
	cout << "Array is ";
	printArray(C_4, sizeof(C_4) / sizeof(int));
	cout << ". Max is at index "
			<< proj1.findPeak(C_4, sizeof(C_4) / sizeof(int));
	cout << endl;
}

LinkedList *part1LinkedList() {

	LinkedList *list = new LinkedList();

	list->insertAtFront(5);
	cout << "Inserting 5 at front. Current list: ";
	list->printList();

	list->insertAtEnd(32);
	cout << "Inserting 32 at end. Current list: ";
	list->printList();

	list->insertAtFront(16);
	cout << "Inserting 16 at front. Current list: ";
	list->printList();

	list->insertAfter(list->getNodeAt(1), 61);
	cout << "Inserting 61 after position 1. Current list: ";
	list->printList();

	list->insertAfter(list->tail, 99);
	cout << "Inserting 99 after tail. Current list: ";
	list->printList();

	list->deleteAfter(list->getNodeAt(1));
	cout << "Deleting after position 1. Current list: ";
	list->printList();

	list->deleteAfter(list->getNodeAt(2));
	cout << "Deleting after position 2. Current list: ";
	list->printList();

	cout << "Trying to delete after position 2: ";
	list->deleteAfter(list->getNodeAt(2));

	list->insertAtFront(5);
	cout << "Inserting 5 at front. Current list: ";
	list->printList();

	list->insertAtEnd(32);
	cout << "Inserting 32 at end. Current list: ";
	list->printList();

	list->insertAtFront(16);
	cout << "Inserting 16 at front. Current list: ";
	list->printList();

	list->insertAtFront(8);
	cout << "Inserting 8 at front. Current list: ";
	list->printList();

	list->insertAtEnd(21);
	cout << "Inserting 21 at end. Current list: ";
	list->printList();

	list->insertAtEnd(50);
	cout << "Inserting 50 at end. Current list: ";
	list->printList();

	list->insertAtEnd(32);
	cout << "Inserting 32 at end. Current list: ";
	list->printList();

	list->insertAtFront(66);
	cout << "Inserting 66 at front. Current list: ";
	list->printList();

	list->insertAtFront(66);
	cout << "Inserting 66 at front. Current list: ";
	list->printList();

	return list;
}

void part2LinkedList(LinkedList *list) {
    cout << "Original List: ";
    list->printList();
    cout << "Reversed List: ";
    list->reverse();
    list->printList();
    
    cout << "\nAfter removing all occurrences of 37: ";
    list->removeAllOccurrencesOf(37);
    list->printList();
    cout << "After removing all occurrences of 21: ";
    list->removeAllOccurrencesOf(21);
    list->printList();
    cout << "After removing all occurrences of 32: ";
    list->removeAllOccurrencesOf(32);
    list->printList();
    cout << "After removing all occurrences of 16: ";
    list->removeAllOccurrencesOf(16);
    list->printList();
    cout << "After removing all occurrences of 66: ";
    list->removeAllOccurrencesOf(66);
    list->printList();
    
    LinkedList list2;
    list2.insertAtFront(50);
    cout << "\nList 1: ";
    list->printList();
    cout << "List 2: ";
    list2.printList();
    cout << "List1 ?= List2 : " << (list->isEqualTo(list2) ? "true" : "false");
    
    list2.insertAtEnd(5);
    list2.insertAtEnd(5);
    list2.insertAtEnd(8);
    cout << "\n\nList 1: ";
    list->printList();
    cout << "List 2: ";
    list2.printList();
    cout << "List1 ?= List2 : " << (list->isEqualTo(list2) ? "true" : "false");
    
    list2.insertAtEnd(8);
    cout << "\n\nList 1: ";
    list->printList();
    cout << "List 2: ";
    list2.printList();
    cout << "List1 ?= List2 : " << (list->isEqualTo(list2) ? "true" : "false");
    
    LinkedList list3;
    list3.insertAtFront(50);
    list3.insertAtEnd(5);
    list3.insertAtEnd(5);
    list3.insertAtEnd(9);
    cout << "\n\nList 1: ";
    list->printList();
    cout << "List 2: ";
    list3.printList();
    cout << "List1 ?= List2 : " << (list->isEqualTo(list3) ? "true" : "false");
    
    LinkedList list4;
    list4.insertAtFront(50);
    list4.insertAtEnd(8);
    list4.insertAtEnd(5);
    list4.insertAtEnd(5);
    cout << "\n\nList 1: ";
    list->printList();
    cout << "List 2: ";
    list4.printList();
    cout << "List1 ?= List2 : " << (list->isEqualTo(list4) ? "true" : "false");
    cout << endl;
}

void testDynamicArrayCorrectness() {
	DynamicArray da(1);
	cout
			<< "****************** Test Dynamic Array Correctness ******************"
			<< endl << endl;
	for (int i = 0; i < 17; i++) {
		da.insertAtEnd(i * 5);
		da.printArray();
		cout << " Num elements: " << da.size() << ", Length: " << da.capacity()
				<< endl;
	}
	cout << endl;
	for (int i = 0; i < 17; i++) {
		da.deleteLast();
		da.printArray();
		cout << " Num elements: " << da.size() << ", Length: " << da.capacity()
				<< endl;
	}
}

void testLinkedListCorrectness() {
	cout
			<< "****************** Test Linked List Correctness ******************\n"
			<< endl;
	LinkedList *list = part1LinkedList();

	cout << endl;
	part2LinkedList(list);
    delete list;
}

static void testStackAndQueue() {
    cout << "****************** Test Stack-and-Queue Correctness ******************\n" << endl;
    int arr[] = {5, 7, 9, 5, 3, 2, 5, 1, 4, 5, 5, 5, 7, 9, 10, 56, 78, 5, 23, 21, 5};
    int n = sizeof(arr)/sizeof(int);
    stack<int> stackObj;
    queue<int> queueObj;
    for (int a : arr) {
        stackObj.push(a);
        queueObj.push(a);
    }
    int keys[] = {7, 5, 32};
    cout << "Stack content: ";
    printArray(arr, n);
    cout << endl;
    for (int key : keys)
        printf("Number of occurrences of %d is %d\n", key, StackAndQueue::countKeyInStack(stackObj, key));
    
    cout << endl << "Queue content: ";
    printArray(arr, n);
    cout << endl;
    for (int key : keys)
        printf("Number of occurrences of %d is %d\n", key, StackAndQueue::countKeyInQueue(queueObj, key));
}

int main() {

	testBinarySearch();
	cout << endl;
	testLinkedListCorrectness();
	cout << endl;
	testDynamicArrayCorrectness();
    cout << endl;
    testStackAndQueue();
	return 1;
}
