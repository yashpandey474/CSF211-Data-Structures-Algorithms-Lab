//IMPLEMENT ALL FUNCTIONS OF LNKED_LIST.H

#include "linked_list.h"
#include <stdlib.h>
#include "mt.h"
// struct node
// {
//     Element data;
//     struct node *next;
// };
// typedef struct node node;
// typedef node * NODE;

// struct linked_list
// {
//     int count;
//     NODE head;
//     // NODE tail; // Not required for stack. Required for Queue
// };
// typedef struct linked_list linked_list;
// typedef linked_list * LIST;

// void insertNodeIntoList(NODE node, LIST list);
// // This function inserts a node at the beginning of the list.

// void removeFirstNode(LIST list);
// // This function removes the first node from the list.

// // void insertNodeAtEnd(NODE node, LIST list); // Not required for stack. Required for Queue
// // This function inserts a node at the end of the list.

// void destroyList(LIST list);

LIST createNewList(){
    LIST myList;
    myList = (LIST) myalloc(sizeof(linked_list));
    myList->count = 0;
    myList->head = NULL;
    return myList;
}
NODE createNewNode(Element data){
    NODE myNode;
    myNode = (NODE) myalloc(sizeof(node));
    myNode->data = data;
    myNode->next = NULL;
    return myNode;
}

void insertNodeIntoList(NODE node, LIST list){
    node->next = list->head;
    list->head = node;
    list->count++;
    return;
}

void removeFirstNode(LIST list){
    if(list->head == NULL){
        return;
    }
    else{
        NODE temp = list->head;
        list->head = temp->next;
        myfree(temp);
        list->count--;
        return;
    }
}

void insertNodeAtEnd(NODE node, LIST list){
    NODE temp;
    if(list->head == NULL){
        list->head = node;
        list->count++;
        return;
    }
    else{
        temp = list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
        list->count++;
        return;
    }
}

void destroyList(LIST list){
    NODE temp;
    NODE next_;
    temp = list->head;

    while(temp!= NULL){
        next_ = temp->next;
        myfree(temp);
        temp = next_;
    }
    myfree(list);
    return;
}

bool isListEMpty(LIST list){
    return list->head == NULL;
}

