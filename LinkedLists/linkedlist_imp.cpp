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
        std::cout << top->data << std::endl;
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


void LinkedList::deleteNodeWithValue(int targetValue){
 
    Node* nextNode = top->next;
    Node* prevNode = top;
    
    while(top != NULL){
        
        if(top->data == targetValue){
            Node* temp = top;
            top = top->next;
            free(temp);
            break;
        }else if (nextNode->data == targetValue){
            
            Node* temp = nextNode;
            nextNode = nextNode->next;
            prevNode->next = nextNode;
            free(temp);
            break;
        }
        
        nextNode = nextNode->next;
        prevNode = prevNode->next;
    }
}



Node*::LinkedList::insertionSort(){
    
    // Create a new sentinel
    Node* newSentinel = createNewNode(top->data, top);
    newSentinel->next = NULL;
    
    // Node pointer to keep track of unsorted list
    Node* nextItem = top->next;
    
    // Node pointer to keep track of sorted list
    Node* after_me = newSentinel;
    
    while(nextItem != NULL){
        
        // Save a cell from the unsorted list to be used in the sorted list
        Node* newCell = createNewNode(nextItem->data, NULL);
        
        // Move on to the next item in the unsorted list
        nextItem = nextItem->next;
        
        // Make the unsorted sentinel start in the beginning
        after_me = newSentinel;
        
        
        // Check the case where the new item is the smaller than the first item in the sorted list
        if(newCell->data < after_me->data){
            // We can now use the sorted lists sentinel to put this item in the front
            Node* oldCell = newSentinel;
            newSentinel = newCell;
            newSentinel->next = oldCell;
        }else {
            // Position the "after_me" Node pointer to the correct position in order to insert the new item
            while(after_me != NULL && after_me->data < newCell->data){
                after_me = after_me->next;
            }
            
            // Add the new cell
            after_me->next = newCell;
        }
       
    }
    
    
    
    
    
    
    
    return newSentinel;
}


void LinkedList::selectionSort() {
    
    // Loop through each node
    
    Node* cursor = top;
    
    while(cursor != NULL){
        
        Node* min = cursor;
        
        Node* nextNode = cursor->next;
        
        while(nextNode != NULL){
            
            if(nextNode->data < min->data){
                
                min = nextNode;
            }else{
                nextNode = nextNode->next;

            }
            
        }
        
        if(min != cursor){
            //swap
            int tempData = cursor->data;
            cursor->data = min->data;
            min->data = tempData;
        }
        
        cursor = cursor->next;
    }
    
    
}





