#include "OddEvenStack.h"
#include "Stack.h"
#include "Queue.h"
#include "Sorting.h"

void testStack() {
    int stackSize = 7;
    Stack stack(stackSize);
    cout << "**** Push Test ****" << endl;
    cout << endl;
    for (int i = 1; i <= 4; i++) {
        int x = i * 5;
        stack.push(x);
        cout << "Push " << x << endl;
        cout << "Stack: " << stack.toString() << endl;
        cout << "Size: " << stack.size() << endl;
        cout <<  endl;
    }
    cout << "**** Pop Test ****" << endl;
    cout << endl;
    for (int i = 1; i <= 2; i++) {
        cout << "Stack: (Popped " << stack.pop() << ") ";
        cout << stack.toString() << endl;
        cout << "Size: " << stack.size() << endl;
        cout << endl;
    }
    
    cout << "**** Push Test ****" << endl;
    cout << endl;
    for (int i = 1; i <= 5; i++) {
        int x = i * 7;
        stack.push(x);
        cout << "Push " << x << endl;
        cout << "Stack: " << stack.toString() << endl;
        cout << "Size: " << stack.size() << endl;
        cout << endl;
    }
    cout << "**** Pop Test ****" << endl;
    cout << endl;
    for (int i = 1; i <= 7; i++) {
        cout << "Stack: (Popped " << stack.pop() << ") ";
        cout << stack.toString() << endl;
        cout << "Size: " << stack.size() << endl;
        cout << endl;
    }
}

void testQueue()  {
    int queueSize = 7;
    Queue queue(queueSize);
    cout << "**** Enqueue Test ****" << endl;
    cout << endl;
    for (int i = 1; i <= 4; i++) {
        int x = i * 5;
        queue.enqueue(x);
        cout << "Enqueue " << x << endl;
        cout << "Queue: " << queue.toString() << endl;
        cout << "Size: " << queue.size() << endl;
        cout << endl;
    }
    cout << "**** Dequeue Test ****" << endl;
    cout << endl;
    for (int i = 1; i <= 2; i++) {
        cout << "Queue: (Dequeued " << queue.dequeue() << ") ";
        cout << queue.toString() << endl;
        cout << "Size: " << queue.size() << endl;
        cout << endl;
    }
    cout << "**** Enqueue Test ****" << endl;
    cout << endl;
    for (int i = 1; i <= 5; i++) {
        int x = i * 7;
        queue.enqueue(x);
        cout << "Enqueue " << x << endl;
        cout << "Queue: " << queue.toString() << endl;
        cout << "Size: " << queue.size() << endl;
        cout << endl;
    }
    cout << "**** Dequeue Test ****" << endl;
    cout << endl;
    for (int i = 1; i <= 4; i++) {
        cout << "Queue: (Dequeued " << queue.dequeue() << ") ";
        cout << queue.toString() << endl;
        cout << "Size: " << queue.size() << endl;
        cout << endl;
    }
    cout << "**** Enqueue Test ****\n" << endl;
    for (int i = 1; i <= 4; i++) {
        int x = i * 7;
        queue.enqueue(x);
        cout << "Enqueue " << x << endl;
        cout << "Queue: " << queue.toString() << endl;
        cout << "Size: " << queue.size() << endl;
        cout << endl;
    }
    cout << "**** Dequeue Test ****\n" << endl;
    for (int i = 1; i <= 7; i++) {
        cout << "Queue: (Dequeued " << queue.dequeue() << ") ";
        cout << queue.toString() << endl;
        cout << "Size: " << queue.size() << endl;
        cout << endl;
    }
}

void testOddEvenStack() {
    cout << "**** Odd/Even Stack ****\n" << endl;
    OddEvenStack os_stack(10);
    int contents[] = { 2, 3, 12, 24, 33, 11, 21, 93, 6, 43 };
    for (int i = 0; i < sizeof(contents)/sizeof(int); i++) {
        printf("Pushing %2d...", contents[i]);
        os_stack.push(contents[i]);
        cout << " Stack content: " << os_stack.toString();
        cout << "; Stack Size: " << os_stack.size() << endl;
    }
    cout << endl;
    cout << "Popping  odd: " << os_stack.popOdd();
    cout << "; Stack Size: " << os_stack.size() << endl;
    printf("Pushing %2d...", 100);
    os_stack.push(100);
    cout << " Stack content: " << os_stack.toString();
    cout << "; Stack Size: " << os_stack.size() << endl;
    cout << "Popping  odd: " << os_stack.popOdd();
    cout << "; Stack Size: " << os_stack.size() << endl;
    cout << "Popping  odd: " << os_stack.popOdd();
    cout << "; Stack Size: " << os_stack.size() << endl;
    cout << "Popping  odd: " << os_stack.popOdd();
    cout << "; Stack Size: " << os_stack.size() << endl;
    cout << "Popping  odd: " << os_stack.popOdd();
    cout << "; Stack Size: " << os_stack.size() << endl;
    cout << "Popping even: " << os_stack.popEven();
    cout << "; Stack Size: " << os_stack.size() << endl;
    cout << "Popping even: " << os_stack.popEven();
    cout << "; Stack Size: " << os_stack.size() << endl;
    cout << "Popping even: " << os_stack.popEven();
    cout << "; Stack Size: " << os_stack.size() << endl;
    cout << "Popping even: " << os_stack.popEven();
    cout << "; Stack Size: " << os_stack.size() << endl;
    cout << "Popping  odd: " << os_stack.popOdd();
    cout << "; Stack Size: " << os_stack.size() << endl;
    cout << "Popping even: " << os_stack.popEven();
    cout << "; Stack Size: " << os_stack.size() << endl;
}

void testSorting() {
    cout << endl << "**** Sorting ****" << endl << endl;
    Sorting sortObj;
    int A[] = { 13, 17, 8, 14, 1 };
    int lenA = sizeof(A) / sizeof(int);
    cout << "Original Array: ";
    sortObj.printArray(A, lenA);
    sortObj.selectionSort(A, lenA);
    cout << endl << "Selection Sorted Array: ";
    sortObj.printArray(A, lenA);
    
    cout << endl << endl;
    
    int B[] = { -13, -17, -8, -14, -1, -20 };
    int lenB = sizeof(B) / sizeof(int);
    cout << "Original Array: ";
    sortObj.printArray(B, lenB);
    sortObj.insertionSort(B, lenB);
    cout << endl << "Insertion Sorted Array: ";
    sortObj.printArray(B, lenB);
    cout << endl;
}

int main() {
    testStack();
    testQueue();
    testOddEvenStack();
    testSorting();
    return 1;
}
