#include <iostream>
#include <string>
using namespace std;

#ifndef RECURSION_H_
#define RECURSION_H_

class Recursion {

public:

    static int sumEvenDigits(int n) { // complete this function
        if (n == 0) {
            return 0;
        }
        int digit = n % 10;
        if (digit % 2 == 0) {
            return digit + sumEvenDigits(n / 10);
        }
        else {
            return sumEvenDigits(n / 10);
        }
    }

	static void binaryStringsWithMoreOnes(int n) {
        binaryStringsWithMoreOnes("", 0, 0, n);
	}

private:

	static void binaryStringsWithMoreOnes(string str, int numZeroes,int numOnes, int n) { // complete this function
        if (str.length() == n) {
            if (numOnes > numZeroes) {
                cout << str << endl;
            }
            return;
        }
        binaryStringsWithMoreOnes(str + "0", numZeroes + 1, numOnes, n);
        binaryStringsWithMoreOnes(str + "1", numZeroes, numOnes + 1, n);
    }
};

#endif /* RECURSION_H_ */
