#include <iostream>
#include <vector>
using namespace std;

#ifndef MERGESORTANDFRIENDS_H_
#define MERGESORTANDFRIENDS_H_

class MergeSortAndFriends {
    
public:
    
    static vector<int> commonElements(int *A, int *B, int lenA, int lenB) { // complete this function
        vector<int> common;
        int a = 0, b = 0;

        while (a < lenA && b < lenB) {
            if (A[a] < B[b])
                a++;
            else if (A[a] > B[b])
                b++;
            else {
                common.push_back(A[a]);
                a++;
                while (a < lenA && A[a] == B[b])
                    a++;
            }
        }

        return common;
    }
    
private:
    
    static vector<int> binaryMerge(vector<int> &A, vector<int> &B) { // complete this function
        vector<int> C;
        int i = 0, j = 0;

        while (i < A.size() && j < B.size()) {
            if (A[i] <= B[j]) {
                C.push_back(A[i]);
                i++;
            }
            else {
                C.push_back(B[j]);
                j++;
            }
        }
        while (i < A.size()) {
            C.push_back(A[i]);
            i++;
        }

        while (j < B.size()) {
            C.push_back(B[j]);
            j++;
        }

        return C;
    }
    
public:
    
    static vector<int> kWayMerge(vector<vector<int>> &lists) { // complete this function
        int k = lists.size();

        if (k == 1)
            return lists[0];

        vector<vector<int>> mergedLists;

        for (int i = 0; i < k / 2; i++) {
            vector<int> merged = binaryMerge(lists[2 * i], lists[2 * i + 1]);
            mergedLists.push_back(merged);
        }

        if (k % 2 != 0)
            mergedLists.push_back(lists[k - 1]);

        return kWayMerge(mergedLists);
    }
    
private:
    
    static vector<int> subList(vector<int> &array, int left, int right) {
        vector<int> list;
        for (int i = left; i <= right; i++)
            list.push_back(array[i]);
        return list;
    }
    
public:
    
    static void mergesort(vector<int> &array, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergesort(array, left, mid);
            mergesort(array, mid + 1, right);
            vector<int> A = subList(array, left, mid);
            vector<int> B = subList(array, mid + 1, right);
            vector<int> mergedArray = binaryMerge(A, B);
            int i = left;
            int j = 0;
            while (j <= right - left)
                array[i++] = mergedArray[j++];
        }
    }
};

#endif /* MERGESORTANDFRIENDS_H_ */
