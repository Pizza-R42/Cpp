#include <vector>
using namespace std;

#ifndef HASHINGWITHPROBING_H_
#define HASHINGWITHPROBING_H_

class HashingWithProbing {
    
public:
    
    vector<int> hashTable;
    int _size;
    int _garbage;
    
    int EMPTY = -1;
    int TOMBSTONE = -9;
    
    HashingWithProbing(int initSize) {
        init(initSize);
    }
    
private:
    
    int hash(int val) {
        return (37 * val + 61) % capacity();
    }
    
    void init(int capacity) { // complete this method
        _size = 0;
        _garbage = 0;
        hashTable.clear();
        for (int i = 0; i < capacity; i++) {
            hashTable.push_back(EMPTY);
        }
    }
    
    void resize(int newTableSize) { // complete this method
        vector<int> keys;
        for (int i = 0; i < hashTable.size(); i++) {
            if (hashTable[i] != EMPTY && hashTable[i] != TOMBSTONE) {
                keys.push_back(hashTable[i]);
            }
        }
        init(newTableSize);
        for (int i = 0; i < keys.size(); i++) {
            insert(keys[i]);
        }

    }
    
public:
    
    int search(int key) { // complete this method
        int hashValue = hash(key);
        for (int i = 0; i < capacity(); i++) {
            if (hashTable[hashValue] == key) {
                return hashValue;
            }
            if (hashTable[hashValue] == EMPTY) {
                return -1;
            }
            hashValue++;
            if (hashValue == capacity()) {
                hashValue = 0;
            }
        }
        return -1;
    }
    
    int insert(int key) { // complete this method
        if (_size + _garbage == capacity()) {
            resize(2 * _size);
        }
        int hashValue = hash(key);
        for (int i = 0; i < capacity(); i++) {
            if (hashTable[hashValue] == key) {
                return -1;
            }
            if (hashTable[hashValue] == EMPTY) {
                break;
            }
            hashValue++;
            if (hashValue == capacity()) {
                hashValue = 0;
            }
        }
        hashTable[hashValue] = key;
        _size++;
        return hashValue;
    }
    
    int remove(int key) { // complete this method
        int index = search(key);
        if (index < 0) {
            return -1;
        }
        hashTable[index] = TOMBSTONE;
        _garbage++;
        _size--;
        if (_garbage * 2 == capacity()) {
            resize(2 * _size);
        }
        return index;
    }
    
    int capacity() {
        return hashTable.size();
    }
    
    int size() {
        return _size;
    }
};

#endif /* HASHINGWITHPROBING_H_ */
