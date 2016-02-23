#include "linkedlist.h"

Node*::LinkedList::createNewNode(int value, Node* newNode){
    Node* temp;
    
    temp = new Node;
    temp->data = value;
    temp->next = newNode;
    
    return temp;
}


void LinkedList::addNewItem(int value){
    
    if(top == NULL){
        top = createNewNode(value, top);
    }else {
        Node *prev = top;
        
        while(prev->next != NULL){
            prev = prev->next;
        }
        
        prev->next = createNewNode(value, prev->next);
    }
}

void LinkedList::printData(){

    while(top != NULL){
        std::cout << top->data;
        top = top->next;
    }
    
}

bool LinkedList::nodeExists(int targetValue){
    
    while(top != NULL){
        if(top->data == targetValue)
            return true;
        
        top = top->next;
    }
    
    return false;
}

void LinkedList::addItemToBeginning(int value){
    
    Node* new_node;
    
    new_node = new Node;
    new_node->data = value;
    new_node->next = top->next;
    top->next = new_node;
    
}


void LinkedList::addItemAfter(Node *node, int value){
    
    Node* new_node;
    
    new_node = new Node;
    new_node->data = value;
    new_node->next = node->next;
    node->next = new_node;
}


void LinkedList::deleteNode(Node *after_me){
    Node* targetNode = after_me->next;
    after_me->next = after_me->next->next;
    free(targetNode);
}


LinkedList::~LinkedList(){
    while(top != NULL){
        Node* next_cell = top->next;
        
        free(top);
        
        top = next_cell;
    }
}
