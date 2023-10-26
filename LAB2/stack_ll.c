//MPLEMENTING STACK WITH LINKED_LIST
#include "linked_list.h"
#include "stack.h"
#define STACK_SIZE 100
#include <stdlib.h>
#include "mt.h"
// NODE createNewNode(Element data);
// // This function allocates memory for a new node and returns a pointer to it.
// // The next pointer is set to NULL and the data is set to the value passed in.

// void insertNodeIntoList(NODE node, LIST list);
// // This function inserts a node at the beginning of the list.

// void removeFirstNode(LIST list);
// // This function removes the first node from the list.

// // void insertNodeAtEnd(NODE node, LIST list); // Not required for stack. Required for Queue
// // This function inserts a node at the end of the list.

// void destroyList(LIST list);
#include <stdio.h>

// size_t heapMemory;
// #define ADDMEM sizeof(int)

// void* myalloc(size_t size){
//     void* ptr = malloc(size+ADDMEM);
//     if(ptr == NULL){
//         return NULL;
//     }
//     *(int*)ptr = size;
//     heapMemory += size;
//     return ptr+ADDMEM;
// }

// void myfree(void* ptr){
//     int size =*(int*)(ptr-ADDMEM);
//     heapMemory -= size;
//     free (ptr-ADDMEM);
// }

struct Stack{
    LIST list;
};
Stack* createStack(){
    Stack* stack;
    stack = (Stack*) myalloc(sizeof(Stack));
    stack->list = createNewList();
    return stack;
}

bool push(Stack* stack, Element ele){
    if(isFull(stack)){
        return false;
    }
    NODE node = createNewNode(ele);
    insertNodeIntoList(node, stack->list);
    return true;
}

bool pop(Stack* stack){
    if(isEmpty(stack)){
        return false;
    }
    removeFirstNode(stack->list);
    return true;
}

bool isEmpty(Stack* stack){
    return stack->list->head == NULL;
}

void freeStack(Stack* stack){
    destroyList(stack->list);
    myfree(stack);
}

bool isFull(Stack* stack){
    return stack->list->count == STACK_SIZE;
}



Element* top(Stack* stack){
    Element ele = stack->list->head->data;
    Element* e1 = (Element*) myalloc(sizeof(Element));
    e1->int_value = ele.int_value;
    e1->float_value = ele.float_value;
    return e1;
}