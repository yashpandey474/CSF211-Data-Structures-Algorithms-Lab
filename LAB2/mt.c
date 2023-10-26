//myalloc allocates space extra tot he size of the data
#include <stdlib.h>
#include <stdio.h>
#include "mt.h"


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
