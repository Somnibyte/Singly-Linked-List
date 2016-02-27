//
//  main.cpp
//  LinkedLists
//
//  Created by Guled on 2/23/16.
//

#include <iostream>
#include "linkedlist.h"
using namespace std;

int main(int argc, const char * argv[]) {
    

    LinkedList list = LinkedList();
    LinkedList sortedList;
    
    list.addNewItem(3);
    list.addNewItem(2);
    list.addNewItem(1);
    sortedList.topSetter(list.insertionSort());
    sortedList.printData();
    list.addItemToBeginning(50);
    list.addItemAfter(list.getTop(), 900);
    list.deleteNode(list.getTop());
    list.deleteNodeWithValue(50);
    list.printData();
    


    return 0;
}
