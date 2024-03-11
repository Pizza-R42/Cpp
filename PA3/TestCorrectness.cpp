#include <iostream>
#include <vector>
#include "Recursion.h"
#include "LinkedList.h"
#include "MergeSortAndFriends.h"
#include "RotatedBinarySearch.h"
using namespace std;

static vector<int> arrayToList(int *arr, int len) {
    vector<int> list;
    for (int i = 0; i < len; i++)
        list.push_back(arr[i]);
    return list;
}

static vector<vector<int>> twoDArrayToList(int **arr, int* numColumns, int numRow) {
    vector<vector<int>> list;
    for (int i = 0; i < numRow; i++) {
        vector<int> row = arrayToList(arr[i], numColumns[i]);
        list.push_back(row);
    }
    return list;
}

static void printArray(int *A, int len) {
    if (len == 0) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (int i = 0; i < len - 1; i++) {
        cout << A[i] << ", ";
    }
    cout << A[len - 1] << "]";
}

static void printVector(vector<int> &vect) {
    if (vect.size() == 0) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (int i = 0; i < vect.size() - 1; i++) {
        cout << vect.at(i) << ", ";
    }
    cout << vect.at(vect.size() - 1) << "]";
}

static void testRecursion() {
    cout << "*** Test Recursion ***\n" << endl;
    int A[] = { 123076, 689201, 6592073, 12461, 1355171 };
    
    for (int a = 0; a < sizeof(A) / sizeof(int); a++)
        printf("Sum of even digits in %d is %d\n", A[a],
               Recursion::sumEvenDigits(A[a]));

    int B[] = { 1, 2, 3, 4, 5 };
    for (int b = 0; b < sizeof(B) / sizeof(int); b++) {
        printf(
                "\nAll binary strings of length %d that have more ones than zeroes\n",
                B[b]);
        Recursion::binaryStringsWithMoreOnes(B[b]);
    }
}

static void testRotatedHelper(int *array, int arrayLen, int keys[],
        int numKeys) {
    cout << "Array is: ";
    printArray(array, arrayLen);
    cout << endl;
    
    cout << "Maximum is at index: " << RotatedBinarySearch::maxIndex(array, 0, arrayLen-1) << "\n" << endl;
    for (int a = 0; a < numKeys; a++) {
        int index = RotatedBinarySearch::search(array, arrayLen, keys[a]);
        bool actuallyExists = false;
        for (int i = 0; i < arrayLen; i++)
            if (array[i] == keys[a]) {
                actuallyExists = true;
                break;
            }
        if ((actuallyExists && index < 0) || (!actuallyExists && index >= 0)
                || (index >= 0 && array[index] != keys[a])) {
            throw "Something is wrong!!!!";
        }
        if (index >= 0)
            printf("Key %2d found at index %d\n", keys[a], index);
        else
            printf("Key %2d not found\n", keys[a]);
    }
}

static void testRotatedArray() {
    cout << "\n*** Test Rotated Array ***\n" << endl;
    int A[] = { 8, 10, 14, 17, 19, 21, 1, 3, 5, 6 };
    int keys_A[] = { 8, 9, 13, 14, 15, 17, 18, 19, 20, 21, 24, 1, 2, 3, 4, 5, 6,
            7, 9, 10, 12 };
    testRotatedHelper(A, sizeof(A) / sizeof(int), keys_A,
            sizeof(keys_A) / sizeof(int));

    cout << endl;
    int B[] = { 10, 1, 5, 7 };
    int keys_B[] = { 8, 10, 12, 0, 1, 3, 5, 6, 7, 9 };
    testRotatedHelper(B, sizeof(B) / sizeof(int), keys_B,
            sizeof(keys_B) / sizeof(int));

    cout << endl;
    int C[] = { 12, 1, 5, 7, 10, 11 };
    int keys_C[] = { 8, 10, 11, 12, 0, 1, 3, 5, 6, 7, 9 };
    testRotatedHelper(C, sizeof(C) / sizeof(int), keys_C,
            sizeof(keys_C) / sizeof(int));

    cout << endl;
    int D[] = { 12, 10, 11 };
    int keys_D[] = { 8, 10, 11, 12, 15 };
    testRotatedHelper(D, sizeof(D) / sizeof(int), keys_D,
            sizeof(keys_D) / sizeof(int));

    cout << endl;
    int E[] = { 12, 1 };
    int keys_E[] = { 0, 1, 4, 12, 14 };
    testRotatedHelper(E, sizeof(E) / sizeof(int), keys_E,
            sizeof(keys_E) / sizeof(int));
}

static void testMergesort() {
    MergeSortAndFriends merge;
    cout << "\n*** Test Mergesort ***\n" << endl;
    int A[] = { 19, 1, 12, 100, 7, 8, 4, -10, 88, 100, 349, 0, 7, -10 };
    int len = sizeof(A) / sizeof(int);
    cout << "Original Array: ";
    printArray(A, len);
    vector<int> vect = arrayToList(A, len);
    merge.mergesort(vect, 0, len - 1);
    cout << "\nSorted Array:   ";
    printVector(vect);
}

static void testCommonElements() {
    cout << "\n*** Test Common Elements in Sorted Arrays ***\n" << endl;
    
    int A[] = { 1, 1, 3, 7, 9, 14, 14, 14, 14, 14, 14, 18, 23, 39, 39, 39 };
    int B[] = { 1, 1, 5, 7, 9, 14, 23, 27, 39, 39 };
    cout << "Array 1: ";
    printArray(A, sizeof(A) / sizeof(int));
    cout << endl;
    cout << "Array 2: ";
    printArray(B, sizeof(B) / sizeof(int));
    cout << endl;
    cout << "Common elements are ";
    vector<int> ans = MergeSortAndFriends::commonElements(A, B, sizeof(A)/sizeof(int), sizeof(B)/sizeof(int));
    printVector(ans);
    cout << endl;
    cout << endl;
    
    int C[] = { 1, 1, 3, 7, 9, 14, 14, 14, 14, 14, 14, 18, 23, 39, 39, 39 };
    int D[] = { 8, 17, 17, 26, 38, 43, 43 };
    cout << "Array 1: ";
    printArray(C, sizeof(C) / sizeof(int));
    cout << endl;
    cout << "Array 2: ";
    printArray(D, sizeof(D) / sizeof(int));
    cout << endl;
    cout << "Common elements are ";
    ans = MergeSortAndFriends::commonElements(C, D, sizeof(C)/sizeof(int), sizeof(D)/sizeof(int));
    printVector(ans);
    cout << endl;
    cout << endl;
    
    int E[] = { 1, 3, 7, 9, 14, 18, 23, 39 };
    int F[] = { 1, 5, 7, 9, 14, 39 };
    cout << "Array 1: ";
    printArray(E, sizeof(E) / sizeof(int));
    cout << endl;
    cout << "Array 2: ";
    printArray(F, sizeof(F) / sizeof(int));
    cout << endl;
    cout << "Common elements are ";
    ans = MergeSortAndFriends::commonElements(E, F, sizeof(E)/sizeof(int), sizeof(F)/sizeof(int));
    printVector(ans);
    cout << endl;
}

static void testKSortedMerge() {
    cout << "\n\n*** Test Merging k Sorted Arrays ***\n" << endl;
    int list0[] = { 1, 5, 9, 18 };
    int list1[] = { -10, 5, 18, 67, 100 };
    int list2[] = { -12, -9, -6, 0, 1, };
    int list3[] = { -65, -32, 10, };
    int list4[] = { 1, 19, 45, 67 };
    int *jagged[] = { list0, list1, list2, list3, list4 };
    int k;
    
    k = 5;
    int eachListLength1[] = { 4, 5, 5, 3, 4 };
    cout << "Original sorted arrays" << endl;
    for (int i = 0; i < k; i++) {
        printArray(jagged[i], eachListLength1[i]);
        cout << endl;
    }
    vector<vector<int>> lists = twoDArrayToList(jagged, eachListLength1, k);
    vector<int> mergedList = MergeSortAndFriends::kWayMerge(lists);
    cout << endl << "Final merged array: ";
    printVector(mergedList);
    
    k = 4;
    int eachListLength2[] = { 4, 5, 5, 3 };
    cout << endl << endl << "Original sorted arrays" << endl;
    for (int i = 0; i < k; i++) {
        printArray(jagged[i], eachListLength2[i]);
        cout << endl;
    }
    lists = twoDArrayToList(jagged, eachListLength1, k);
    mergedList = MergeSortAndFriends::kWayMerge(lists);
    cout << "\nFinal merged array: ";
    printVector(mergedList);
    
    k = 2;
    int eachListLength3[] = { 4, 5 };
    cout << endl << endl << "Original sorted arrays" << endl;
    for (int i = 0; i < k; i++) {
        printArray(jagged[i], eachListLength2[i]);
        cout << endl;
    }
    cout << "\nFinal merged array: ";
    lists = twoDArrayToList(jagged, eachListLength1, k);
    mergedList = MergeSortAndFriends::kWayMerge(lists);
    printVector(mergedList);
    
    k = 1;
    int eachListLength4[] = { 4 };
    cout << endl << endl << "Original sorted arrays" << endl;
    for (int i = 0; i < k; i++) {
        printArray(jagged[i], eachListLength2[i]);
        cout << endl;
    }
    cout << "\nFinal merged array: ";
    lists = twoDArrayToList(jagged, eachListLength1, k);
    mergedList = MergeSortAndFriends::kWayMerge(lists);
    printVector(mergedList);
    cout << endl;
}

static void testMergesortLinkedList() {
    cout << "\n*** Mergesort Linked List ***\n" << endl;

    LinkedList list;

    list.insertAtFront(5);
    list.insertAtEnd(32);
    list.insertAtFront(16);
    list.insertAtFront(5);
    list.insertAtEnd(32);
    list.insertAtFront(16);
    list.insertAtFront(8);
    list.insertAtEnd(21);
    list.insertAtEnd(50);
    list.insertAtEnd(32);
    list.insertAtFront(66);
    list.insertAtFront(66);
    list.insertAtFront(-12);
    cout << "Original List: ";
    list.printList();
    list.mergesort();
    cout << "Sorted List:   ";
    list.printList();
}

int main() {
    testRecursion();
    testRotatedArray();
    testCommonElements();
    testMergesort();
    testKSortedMerge();
    testMergesortLinkedList();


    return 1;
}

