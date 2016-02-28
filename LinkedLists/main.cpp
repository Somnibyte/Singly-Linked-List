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
    list.addNewItem(1);
    list.addNewItem(2);
    list.selectionSort();
    list.printData();

    
    //sortedList.topSetter(list.insertionSort());
    //sortedList.printData();


    return 0;
}
