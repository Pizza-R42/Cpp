#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>

#include "math.h"
#include "BST.h"
#include "HashingWithChaining.h"
#include "HashingWithProbing.h"
using namespace std;

int getLargestBoundedPrime(int n) {

	bool *prime = new bool[n + 1];
	for (int i = 0; i < n; i++)
		prime[i] = true;

	for (int p = 2; p <= sqrt(n); p++) {
		// If prime[p] is not changed, then it is a prime
		if (prime[p]) {
			// Update all multiples of p
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Get Largest Prime <= n
	for (int i = n; i >= 2; i--) {
		if (prime[i])
			return i;
	}
	delete[] prime;
	return 2;
}

void compareHashingAndBST() {
	cout << "****************** Time Test Dictionary ******************" << endl
			<< endl;

	int U = 1000000;
	int CHAINING_TABLE_SIZE = getLargestBoundedPrime(U / 10);
	int INITIAL_PROBING_SIZE = 128;

	HashingWithChaining hChain(CHAINING_TABLE_SIZE);
	HashingWithProbing hProbing(INITIAL_PROBING_SIZE);
	BST bst;

	long totalChainIns = 0, totalProbingIns = 0, totalBSTIns = 0;
	long totalChainSearch = 0, totalProbingSearch = 0, totalBSTSearch = 0;
	long totalChainDel = 0, totalProbingDel = 0, totalBSTDel = 0;

	int *generatedNum = new int[U];

	int numFailedInsertions = 0;

	for (int i = 0; i < U; i++) {
		int val = rand() % U;
		generatedNum[i] = val;
		clock_t startTime = clock();
		bool inserted = hChain.insert(val);
		if (!inserted)
			numFailedInsertions++;
		totalChainIns += clock() - startTime;

		startTime = clock();
		if (bst.insert(val) != NULL && !inserted)
			throw "Something went wrong with insertion!";
		totalBSTIns += clock() - startTime;

		startTime = clock();
		if (hProbing.insert(val) >= 0 && !inserted)
			throw "Something went wrong with insertion!";
		totalProbingIns += clock() - startTime;
	}

	int numFailedSearches = 0;
	for (int i = 0; i < U; i++) {

		double randDouble = (double) rand() / RAND_MAX;
		int val = randDouble > 0.5 ? rand() % U : generatedNum[rand() % U];

		clock_t startTime = clock();
		bool found = hChain.search(val);
		if (!found)
			numFailedSearches++;
		totalChainSearch += clock() - startTime;

		startTime = clock();
		if (bst.search(val) && !found)
			throw "Something went wrong with search!";
		totalBSTSearch += clock() - startTime;

		startTime = clock();
		if (hProbing.search(val) >= 0 && !found)
			throw "Something went wrong with search!";
		totalProbingSearch += clock() - startTime;
	}

	int numFailedDeletions = 0;
	for (int i = 0; i < U; i++) {
		double randDouble = (double) rand() / RAND_MAX;
		int val = randDouble > 0.5 ? rand() % U : generatedNum[rand() % U];

		clock_t startTime = clock();
		bool deleted = hChain.remove(val);
		if (!deleted)
			numFailedDeletions++;
		totalChainDel += clock() - startTime;

		startTime = clock();
		if (bst.remove(val) && !deleted)
			throw "Something went wrong with deletion!";
		totalBSTDel += clock() - startTime;

		startTime = clock();
		if (hProbing.remove(val) >= 0 && !deleted)
			throw "Something went wrong with deletion!";
		totalProbingDel += clock() - startTime;
	}

	delete[] generatedNum;

	cout << "*** Hashing With Chaining ***" << endl << endl;
	hChain.printStatistics();
	cout << "Total time over " << U << " insertion attempts ("
			<< numFailedInsertions << " failed): " << totalChainIns
			<< " (may vary with each execution)" << endl;
	cout << "Total time over " << U << " search attempts (" << numFailedSearches
			<< " failed): " << totalChainSearch
			<< " (may vary with each execution)" << endl;
	cout << "Total time over " << U << " deletion attempts ("
			<< numFailedDeletions << " failed): " << totalChainDel
			<< " (may vary with each execution)" << endl;

	cout << endl << "*** Hashing With Probing ***" << endl << endl;
	cout << "Size of Probing table = " << hProbing.capacity()
			<< ". Number of Tombstones = " << hProbing._garbage << endl;
	cout << "Total time over " << U << " insertion attempts ("
			<< numFailedInsertions << " failed): " << totalProbingIns
			<< " (may vary with each execution)" << endl;
	cout << "Total time over " << U << " search attempts (" << numFailedSearches
			<< " failed): " << totalProbingSearch
			<< " (may vary with each execution)" << endl;
	cout << "Total time over " << U << " deletion attempts ("
			<< numFailedDeletions << " failed): " << totalProbingDel
			<< " (may vary with each execution)" << endl;

	cout << endl << "*** BST ***" << endl << endl;
	cout << "Height of BST = " << bst.getTreeHeight() << endl;
	cout << "Total time over " << U << " insertion attempts ("
			<< numFailedInsertions << " failed): " << totalBSTIns
			<< " (may vary with each execution)" << endl;
	cout << "Total time over " << U << " search attempts (" << numFailedSearches
			<< " failed): " << totalBSTSearch
			<< " (may vary with each execution)" << endl;
	cout << "Total time over " << U << " deletion attempts ("
			<< numFailedDeletions << " failed): " << totalBSTDel
			<< " (may vary with each execution)" << endl;
}

int main() {
	srand(clock());
	compareHashingAndBST();
	return 1;
}

