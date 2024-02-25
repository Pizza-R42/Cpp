#include "LinkedList.h"
#include "DynamicArray.h"

const int CLOCKS_PER_MILLISEC = CLOCKS_PER_SEC / 1000;

void testTime() {

    cout
            << "****************** Time Test Dynamic Array vs LinkedList ****************** \n"
            << endl;
    double insTimeDA = 0, insTimeLL = 0, delTimeDA = 0, delTimeLL = 0,
            scanTimeDA = 0, scanTimeLL = 0, randAccessTimeDA = 0,
            randAccessTimeLL = 0;
    long totalInsDelScan = 0, totalRandAccess = 0;
    int numRandAccess = 1000;
    srand(clock());
    int round = 0;
    int *randAccessIndexes = new int[numRandAccess];
    for (int num = 1000000; num <= 50000000; num *= 1.2) {
        DynamicArray da(1);
        LinkedList ll;

        long start = clock();
        for (int i = 0; i < num; i++) {
            da.insertAtEnd(i);
        }
        insTimeDA += (clock() - start);

        start = clock();
        for (int i = 0; i < num; i++) {
            ll.insertAtFront(i);
        }
        insTimeLL += (clock() - start);

        start = clock();
        for (int i = 0; i < num; i++) {
            da.access(i);
        }
        scanTimeDA += (clock() - start);

        start = clock();
        ListNode *tmp = ll.head;
        for (int i = 0; i < num; i++) {
            tmp = tmp->next;
        }
        scanTimeLL += (clock() - start);

        for (int j = 0; j < numRandAccess; j++)
            randAccessIndexes[j] = rand() % da.size();

        start = clock();
        for (int j = 0; j < numRandAccess; j++)
            da.access(randAccessIndexes[j]);
        randAccessTimeDA += (clock() - start);

        start = clock();
        for (int j = 0; j < numRandAccess; j++)
            ll.getNodeAt(randAccessIndexes[j]);
        randAccessTimeLL += (clock() - start);

        start = clock();
        for (int i = 0; i < num; i++) {
            da.deleteLast();
        }
        delTimeDA += (clock() - start);

        start = clock();
        for (int i = 0; i < num; i++) {
            ll.deleteHead();
        }
        delTimeLL += (clock() - start);

        cout << "Round " << round << " Completed" << endl;
        round++;
        totalInsDelScan += num;
        totalRandAccess += numRandAccess;
    }
    delete[] randAccessIndexes;
    cout << "\nTotal number of insertions, scans, and deletions (each) = "
            << totalInsDelScan << endl;
    cout << "Total number of random accesses = " << totalRandAccess << endl;
    printf("\nInsertion time of dynamic array = %.2fms\n",
            insTimeDA / CLOCKS_PER_MILLISEC);
    printf("Insertion time of linked list = %.2fms\n",
            insTimeLL / CLOCKS_PER_MILLISEC);
    cout << endl;
    printf("Scan time of dynamic array = %.2fms\n",
            scanTimeDA / CLOCKS_PER_MILLISEC);
    printf("Scan time of linked list = %.2fms\n",
            scanTimeLL / CLOCKS_PER_MILLISEC);
    cout << endl;
    printf("Deletion time of dynamic array = %.2fms\n",
            delTimeDA / CLOCKS_PER_MILLISEC);
    printf("Deletion time of linked list = %.2fms\n",
            delTimeLL / CLOCKS_PER_MILLISEC);
    cout << endl;
    printf("Access time of dynamic array = %.2fms\n",
            randAccessTimeDA / CLOCKS_PER_MILLISEC);
    printf("Access time of linked list = %.2fms\n",
            randAccessTimeLL / CLOCKS_PER_MILLISEC);
}

int main() {
    testTime();
    return 1;
}
