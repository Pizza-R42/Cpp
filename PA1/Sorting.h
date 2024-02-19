#include <iostream>
using namespace std;

#ifndef SORTING_H_
#define SORTING_H_

class Sorting {
    
public:
    
    void selectionSort(int array[], int arrayLen) { // complete this method
        for (int i = 0; i < arrayLen - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < arrayLen; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(array[i], array[minIndex]);
            }
        }
    }
    
    void insertionSort(int array[], int arrayLen) { // complete this method
        for (int i = 1; i < arrayLen; i++) {
            int num = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > num) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = num;
        }
    }
    
    void printArray(int A[], int length) {
        cout << "[";
        for (int i = 0; i < length - 1; i++)
            cout << A[i] << ", ";
        cout << A[length - 1] << "]";
    }
};

#endif
