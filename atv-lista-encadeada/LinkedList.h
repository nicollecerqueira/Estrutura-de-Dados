#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    bool isEmpty() const;
    int getSize() const;
    int get(int position) const;
    void set(int position, int value);
    void insert(int position, int value);
    void remove(int position);
    void printList() const;
};

#endif // LINKEDLIST_H
