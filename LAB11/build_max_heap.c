/*
build_max_heap() that takes as input an array of integers that
represents a binary tree and outputs another array that represents the heap that would be
formed from the binary tree. 
Your function obviously should call the max_heapify() function within it.
*/

// MAKE MAX HEAP PROPERTY SATISFY AT A LEVEL
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct heap *Heap;
struct heap
{
    int *data;    // ARRAY OF ELEMENTS
    int size;     // LAST VALID INDEX
    int capacity; // IS ANOTHER LEVEL NEEDED?
    int depth;    // CURRENT LEVEL/DEPTH OF TREE
};

Heap heap_Create()
{
    Heap h = (Heap)malloc(sizeof(struct heap));
    h->data = (int *)malloc(sizeof(int));
    h->size = 0;
    h->capacity = 1; // CAN HAVE ONE ELEMENT: 2^0
    h->depth = 0;
    return h;
}

// T1: ADD_TO_TREE: INPUT A BINARY TREE AND AN INTEGER AND PLACE ELEMENT INTO NEXT FREE SLOT
void add_to_tree(Heap tree, int element)
{
    // KEEP TREE NEARLY COMPLETE

    // NEW LEVEL NOT INTRODUCED UNLESS PREVIOUS COMPLETELY FILLED

    if (tree->size == tree->capacity)
    {
        tree->depth++;
        tree->data = (int *)realloc(tree->data, sizeof(int) * (tree->capacity + pow(2, tree->depth)));
        tree->capacity += pow(2, tree->depth);
    }

    tree->data[tree->size] = element;
    tree->size++;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct heap *Heap;
struct heap
{
    int *data;    // ARRAY OF ELEMENTS
    int size;     // LAST VALID INDEX
    int capacity; // IS ANOTHER LEVEL NEEDED?
    int depth;    // CURRENT LEVEL/DEPTH OF TREE
};

Heap heap_Create()
{
    Heap h = (Heap)malloc(sizeof(struct heap));
    h->data = (int *)malloc(sizeof(int));
    h->size = 0;
    h->capacity = 1; // CAN HAVE ONE ELEMENT: 2^0
    h->depth = 0;
    return h;
}

// T1: ADD_TO_TREE: INPUT A BINARY TREE AND AN INTEGER AND PLACE ELEMENT INTO NEXT FREE SLOT
void add_to_tree(Heap tree, int element)
{
    // KEEP TREE NEARLY COMPLETE

    // NEW LEVEL NOT INTRODUCED UNLESS PREVIOUS COMPLETELY FILLED

    if (tree->size == tree->capacity)
    {
        tree->depth++;
        tree->data = (int *)realloc(tree->data, sizeof(int) * (tree->capacity + pow(2, tree->depth)));
        tree->capacity += pow(2, tree->depth);
    }

    tree->data[tree->size] = element;
    tree->size++;
}

int parent(Heap h, int node)
{

    return (node - 1) / 2;
}

int left_child(Heap h, int node)
{

    return 2 * node + 1;
}

int right_child(Heap h, int node)
{

    return 2 * node + 2;
}

// WORST CASE TIME COMPLEXITY = O(LOGN)
void max_heapify(Heap h, int index)
{
    int left = left_child(h, index);
    int right = right_child(h, index);
    int largest = index;

    if (left < h->size && h->data[left] > h->data[index])
    {
        largest = left;
    }

    if (right < h->size && h->data[right] > h->data[index])
    {
        largest = right;
    }

    if (largest != index)
    {
        // SWAP
        int temp = h->data[index];
        h->data[index] = h->data[largest];
        h->data[largest] = temp;
        max_heapify(h, largest);
    }
}


//T3: BUILD_MAX_HEAP
Heap build_max_heap(int* input_array, int array_size){
    Heap h = heap_Create();
    
    for(int i = 0; i<array_size; i++){
        add_to_tree(h, input_array[i]);
    }

    for(int i = h->size/2; i>0; i--){
        max_heapify(h, i);
    }

    return h;
}