//
//  main.cpp
//  LinkedLists
//
//  Created by Guled on 2/23/16.
//  Copyright © 2016 Somnibyte. All rights reserved.
//

#include <iostream>
#include "linkedlist.h"
using namespace std;

int main(int argc, const char * argv[]) {
    

    LinkedList list = LinkedList();
    
    list.addNewItem(1);
    list.addNewItem(2);
    list.addNewItem(3);
    list.addItemToBeginning(50);
    list.addItemAfter(list.getTop(), 900);
    list.deleteNode(list.getTop());
    list.printData();


    return 0;
}
