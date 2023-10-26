#include "stack.h"
#define STACK_SIZE 100
#include <stdlib.h>

struct Stack{
    Element data[STACK_SIZE];
    int top;
};
//myalloc allocates space extra tot he size of the data

#include <stdio.h>

size_t heapMemory;
#define ADDMEM sizeof(int)

void* myalloc(size_t size){
    void* ptr = malloc(size+ADDMEM);
    if(ptr == NULL){
        return NULL;
    }
    *(int*)ptr = size;
    heapMemory += size;
    return ptr+ADDMEM;
}

void myfree(void* ptr){
    int size =*(int*)(ptr-ADDMEM);
    heapMemory -= size;
    free (ptr-ADDMEM);
}


Stack* createStack(){
    Stack* stack;
    stack = (Stack*) myalloc(sizeof(Stack));
    if(stack!=NULL){
        stack->top = -1;
    }
    return stack;
}

bool push(Stack* stack, Element ele){
    if(isFull(stack)){
        return false;
    }
    stack->top++;
    stack->data[stack->top] = ele;
    return true;
}

bool pop(Stack* stack){
    if(isEmpty(stack)){
        return false;
    }
    stack->top--;
    return true;
}

bool isEmpty(Stack* stack){
    return stack->top == -1;
}

bool isFull(Stack* stack){
    return stack->top == STACK_SIZE-1;
}

void freeStack(Stack* stack){
    myfree(stack);
    return;
}

Element* top(Stack* stack){
    if(isEmpty(stack)){
        Element* ele;
        ele = (Element*) myalloc(sizeof(Element));
        ele->int_value = -1;
        return ele;
    }
    Element * ele;
    ele = (Element*) myalloc(sizeof(Element));
    Element ele1 = stack->data[stack->top];
    ele->int_value = ele1.int_value;
    ele->float_value = ele1.float_value;
    return ele;
}