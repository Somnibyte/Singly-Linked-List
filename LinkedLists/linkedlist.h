#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <cstdlib>
#include <iostream>
#include "node.h"

class LinkedList {
    
public:
    // Constructor
    LinkedList(){top = NULL;}
    ~LinkedList();
    
    void printData();
    void addNewItem(int value);
    bool nodeExists(int targetValue);
    void addItemToBeginning(int value);
    void addItemAfter(Node* node, int value);
    Node* getTop(){return top;}
    void topSetter(Node* sentinel){top = sentinel;}
    void deleteNode(Node* after_me);
    void deleteNodeWithValue(int value);
    Node* insertionSort();
    void selectionSort();
    
private:
    Node* top;
    Node* createNewNode(int value, Node* newNode);
    
};


#endif
