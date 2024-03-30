#ifndef HASHINGWITHCHAINING_H_
#define HASHINGWITHCHAINING_H_

#include <list>
#include <vector>
#include <iterator>
using namespace std;

class HashingWithChaining {

public:

	int TABLE_SIZE;
	vector<list<int>> hashTable;

	HashingWithChaining(int tableSize) {
		TABLE_SIZE = tableSize;
		for (int i = 0; i < TABLE_SIZE; i++)
			hashTable.push_back(list<int>());
	}

	~HashingWithChaining() {
	}

private:

	int hash(int val) {
		return (37 * val + 61) % TABLE_SIZE;
	}

public:

    bool search(int key) { // complete this method

		int index = hash(key);
		for (auto it = hashTable[index].begin(); it != hashTable[index].end(); it++) {
			if (*it == key) {
				return true;
			}
		}
		return false;
    }

    bool insert(int key) { // complete this method
		int index = hash(key);
		if (!search(key)) { 
			hashTable[index].push_back(key);
			return true;
		}
		return false;
		
    }

	bool remove(int key) { // complete this method
		int index = hash(key);
		for (auto it = hashTable[index].begin(); it != hashTable[index].end(); it++) {
			if (*it == key) {
				hashTable[index].erase(it);
				return true;
			}
		}
		return false; 
		
	}

	void printStatistics() {
		int maxSize = hashTable[0].size();
		int minSize = maxSize, total = maxSize;
		for (int i = 1; i < TABLE_SIZE; i++) {
			int size = hashTable[i].size();
			if (size > maxSize)
				maxSize = size;
			else if (size < minSize)
				minSize = size;
			total += size;
		}
		printf(
				"Max length of a chain = %d\nMin length of a chain = %d\nAvg length of chains = %d\n",
				maxSize, minSize, total / TABLE_SIZE);
	}
};

#endif
