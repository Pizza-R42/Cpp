#include <iostream>
#include <climits>
using namespace std;

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
    
private:
    
    int maxQueueSize, front, rear, currentSize;
    int *queue;
    
public:
    Queue(int maxQueueSize) {
        if (maxQueueSize <= 0)
            cout << "Queue size should be a positive integer.";
        else {
            this->maxQueueSize = maxQueueSize;
            front = rear = 0;
            currentSize = 0;
            queue = new int[maxQueueSize];
        }
    }
    
    ~Queue() {
        delete[] queue;
    }
    
    void enqueue(int val) { // complete this method
        if (currentSize == maxQueueSize) {
            cout << "Cannot enqueue! Queue is full";
            return;
        }
        queue[rear++] = val;
        currentSize++;
        if (rear == maxQueueSize) {
            rear = 0;
        }
    }
    
    int dequeue() { // complete this method
        if (currentSize == 0) {
            cout << "Cannot dequeue! Queue is empty";
            return -1;
        }
        int _value = queue[front++];
        currentSize--;
        if (front == maxQueueSize) {
            front = 0;
        }
        return _value;
    }
    
    int size() { // complete this method
        return currentSize;
    }
    
    string toString() {
        if (size() == 0)
            return "[]";
        else {
            string output = "[";
            if (rear > front) {
                for (int i = front; i < rear - 1; i++)
                    output += to_string(queue[i]) + ", ";
                output += to_string(queue[rear - 1]) + "]";
            } else {
                for (int i = front; i < maxQueueSize - 1; i++)
                    output += to_string(queue[i]) + ", ";
                output += to_string(queue[maxQueueSize - 1]);
                
                for (int i = 0; i < rear; i++)
                    output += ", " + to_string(queue[i]);
                output += "]";
            }
            return output;
        }
    }
};

#endif
