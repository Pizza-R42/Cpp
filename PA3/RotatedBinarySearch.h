#ifndef ROTATEDBINARYSEARCH_H_
#define ROTATEDBINARYSEARCH_H_

class RotatedBinarySearch {
    
public:
    
    static int search(int *array, int length, int key) { // complete this function
        int max_index = maxIndex(array, 0, length - 1);
    
        if (array[max_index] == key)
            return max_index;
        else if (key >= array[0])
            return binarySearch(array, 0, max_index - 1, key);
        else
            return binarySearch(array, max_index + 1, length - 1, key);
    }
    
    static int maxIndex(int *array, int left, int right) { // complete this function
        if (left == right)
            return left;

        int mid = (left + right) / 2;
        if (array[mid + 1] < array[mid])
            return mid;
        else if (array[mid] < array[left])
            return maxIndex(array, left, mid);
        else
            return maxIndex(array, mid + 1, right);
    }
    
    static int binarySearch(int *array, int left, int right, int key) {
        if (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] == key) {
                return mid;
            } else if (array[mid] < key)
                return binarySearch(array, mid + 1, right, key);
            else
                return binarySearch(array, left, mid - 1, key);
        }
        return -1;
    }
};

#endif /* ROTATEDBINARYSEARCH_H_ */
