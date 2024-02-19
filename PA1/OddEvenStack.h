#include <iostream>
#include <climits>
#include <string>
using namespace std;

#ifndef ODDEVENSTACK_H_
#define ODDEVENSTACK_H_

class OddEvenStack {
    
private:
    
    int maxStackSize, oddTos, evenTos;
    int *stack;
    
public:
    
    OddEvenStack(int maxStackSize) { // complete the constructor
        if (maxStackSize <= 0)
            cout << "Stack size should be a positive integer.";
        else {
            this->maxStackSize = maxStackSize;
            oddTos = -1;
            evenTos = maxStackSize;
            stack = new int[maxStackSize];
            for (int i = 0; i < maxStackSize; i++) {
                stack[i] = 0;
            }
        }
    }
    
    ~OddEvenStack() {
        delete[] stack;
    }
    
    int size() { // complete this method 
        return (maxStackSize - evenTos) + (oddTos + 1);
    }
    
    void push(int val) { // complete this method
        if (size() == maxStackSize) {
            cout << "Cannot push! Stack is full";
            return;
        }
        if (val % 2 == 0) {
            stack[--evenTos] = val;
        }
        else {
            stack[++oddTos] = val;
        }
    }
    
    int popOdd() { // complete this method
        if (oddTos == -1) {
            return -1;
        }
        return stack[oddTos--];
        
    }
    
    int popEven() { // complete this method
        if (evenTos == maxStackSize) {
            return -1;
        }
        return stack[evenTos++];
    }
    
    string toString() {
        string out = "[";
        for (int i = 0; i < maxStackSize - 1; i++) {
            out += to_string(stack[i]) + ", ";
        }
        out += to_string(stack[maxStackSize - 1]) + "]";
        return out;
    }
};

#endif /* ODDEVENSTACK_H_ */
