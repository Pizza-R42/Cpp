#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#ifndef StackAndQueue_h
#define StackAndQueue_h

class StackAndQueue {

public:
    
    static int countKeyInStack(stack<int> &arg, int key) { // complete this method
        int count = 0;
        stack<int> temp = arg;
        while (temp.size() > 0) {
            if (temp.top() == key) {
                count++;
            }
            temp.pop();
        }
        return count;

    }

    static int countKeyInQueue(queue<int> &arg, int key) { // complete this method
        int count = 0;
        for (int i = 0; i < arg.size(); i++) {
            int val = arg.front();
            if (val == key) {
                count++;
            }
            arg.pop();
            arg.push(val);
        }
        return count;
    }
};

#endif /* StackAndQueue_h */
