// MAKE MAX HEAP PROPERTY SATISFY AT A LEVEL
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Write a function that takes as input a heap (an array) and a particular level or depth
 * and returns the total number of nodes present in the heap at that depth.
 */

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


//T4: RETURN THE NUMBER OF NODES AT THAT DEPTH
int number_of_nodes_depth(Heap h, int depth){
    int count = 0;

    int first_index = pow(2, depth) - 1;
    int last_index = pow(2, depth+1) - 2;

    //IF ALL NODES IN DEPTH NOT PRESENT
    if(last_index >= h->size){
        last_index = h->size;
    }
    

    //IF NO ELEMENTS AT DEPTH
    if(first_index >= h->size){
        return 0;
    }

    //COUNT NUMBER OF NODES AT THE DEPTH
    return last_index - first_index;
}
