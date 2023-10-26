//FUNCTION SIGNATURES FOR STACK

#ifndef STACK_H
#define STACK_H

#include "bool.h"
#include "element.h"

typedef struct Stack Stack;

Stack* createStack();

bool push(Stack* stack, Element ele);

bool pop(Stack* stack);

bool isEmpty(Stack* stack);

void freeStack(Stack* stack);

bool isFull(Stack* stack);
Element*top(Stack* stack);

#endif