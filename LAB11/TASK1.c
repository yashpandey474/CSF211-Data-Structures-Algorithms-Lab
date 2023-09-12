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
