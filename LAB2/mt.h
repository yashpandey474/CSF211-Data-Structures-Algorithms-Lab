#ifndef MT_H
#define MT_H
size_t heapMemory;
#define ADDMEM sizeof(int)

void* myalloc(size_t size);

void myfree(void* ptr);
#endif