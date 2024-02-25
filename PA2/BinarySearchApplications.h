#include <iostream>
using namespace std;

class BinarySearchApplications {

public:

    int predecessor(int array[], int arrayLen, int key) { // complete this method
        int low = 0;
        int high = arrayLen - 1;
        int result = -1; 

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (array[mid] == key)
                return mid;

            if (array[mid] <= key) {
                result = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
    
    int findPeak(int twoToneArray[], int arrayLen) { // complete this method
        int low = 0;
        int high = arrayLen - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (twoToneArray[mid] > twoToneArray[mid + 1]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
