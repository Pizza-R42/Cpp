#include "ListNode.h"

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class LinkedList {
    
public:
    
    ListNode *head, *tail;
    int size;
    
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }
    
    ~LinkedList() {
        while (size > 0)
            deleteHead();
    }
    
    void insertAfter(ListNode *argNode, int value) { // complete this method
        
        ListNode* newNode = new ListNode(value);
        newNode->next = argNode->next;
        argNode->next = newNode;
        if (argNode == tail) {
            tail = newNode;
        }
        size++; 

    }
    
    void deleteAfter(ListNode *argNode) { // complete this method
        if (argNode == nullptr || argNode->next == nullptr) {
            return;
        }
        ListNode* nodeToDelete = argNode->next;
        argNode->next = nodeToDelete->next;
        if (nodeToDelete == tail) {
            tail = argNode; 
        }
        delete nodeToDelete;
        size--;
        
    }
    
    void reverse() { // complete this method
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        tail = head; 
        head = prev;
        
    }
    
    void removeAllOccurrencesOf(int key) { // complete this method
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (current != nullptr) {
            if (current->value == key) {
                if (current == head) {
                    head = current->next;
                    delete current;
                    current = head;
                }
                else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
                size--;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
        tail = prev; 
    }
    
    bool isEqualTo(LinkedList &arg) { // complete this method
        if (size != arg.getSize()) {
            return false;
        }
        ListNode* current1 = head;
        ListNode* current2 = arg.head;
        while (current1 != nullptr) {
            if (current1->value != current2->value) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return true;
    }
    
    ListNode *insertAtFront(int value) { // complete this method
        ListNode* newNode = new ListNode(value);
        if (size == 0) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        size++;
        return newNode;
    }
    
    ListNode *insertAtEnd(int value) { // complete this method
        ListNode* newNode = new ListNode(value);
        if (size == 0) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        return newNode;
    }
    
    void deleteHead() {
        if (0 == size) {
            cout << "Cannot delete from an empty list" << endl;
        } else if (1 == size) {
            size--;
            delete head;
        } else {
            size--;
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    
    ListNode *getNodeAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "No such position exists" << endl;
            return NULL;
        } else {
            ListNode *tmp = head;
            for (int i = 0; i < pos; i++)
                tmp = tmp->next;
            return tmp;
        }
    }
    
    void printList() {
        if (size == 0)
            cout << "[]" << endl;
        else {
            ListNode *tmp = head;
            cout << "[";
            for (int i = 0; i < size - 1; i++) {
                cout << tmp->value << " -> ";
                tmp = tmp->next;
            }
            cout << tail->value << "]" << endl;
        }
    }
    
    int getSize() {
        return size;
    }
};

#endif /* LINKEDLIST_H_ */
