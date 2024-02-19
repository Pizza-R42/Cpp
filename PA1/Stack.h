#include <iostream>
#include <climits>
#include <string>
using namespace std;

#ifndef STACK_H_
#define STACK_H_

class Stack {
    
private:
    int maxStackSize, topOfStack;
    int *stack;
    
public:
    
    Stack(int maxStackSize) {
        if (maxStackSize <= 0)
            cout << "Stack size should be a positive integer.";
        else {
            this->maxStackSize = maxStackSize;
            topOfStack = -1;
            stack = new int[maxStackSize];
        }
    }
    
    ~Stack() {
        delete[] stack;
    }
    
    void push(int val) { // complete this method
        if (topOfStack == maxStackSize - 1) {
            cout << "Cannot push! Stack is full";
            return;
        }
        stack[++topOfStack] = val;
    }
    
    int pop() { // complete this method
        if (topOfStack == -1) {
            cout << "Cannot pop!Stack is empty";
            return -1;
        }
        return stack[topOfStack--];

    }
    
    int size() { // complete this method
        return topOfStack + 1;
    }
    
    string toString() {
        if (size() == 0)
            return "[]";
        string out = "[";
        for (int i = 0; i < topOfStack; i++) {
            out += to_string(stack[i]);
            out += ", ";
        }
        out += to_string(stack[topOfStack]);
        out += "]";
        return out;
    }
};

#endif
