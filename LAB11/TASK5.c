
// IMPLEMENTING THE O(NLOGN) HEAPSORT THAT SORTS AN ARRAY IN PLACE WITH CONSTANT SPACE
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

typedef struct person person;
struct person
{
    int id;
    char name[100];
    int age;
    int height;
    int weight;
};


typedef struct heap *Heap;
struct heap
{
    person *data;    // ARRAY OF ELEMENTS
    int size;     // LAST VALID INDEX
    int capacity; // IS ANOTHER LEVEL NEEDED?
    int depth;    // CURRENT LEVEL/DEPTH OF TREE
};

Heap heap_Create()
{
    Heap h = (Heap)malloc(sizeof(struct heap));
    h->data = (person*)malloc(sizeof(person));
    h->size = 0;
    h->capacity = 1; // CAN HAVE ONE ELEMENT: 2^0
    h->depth = 0;
    return h;
}

// T1: ADD_TO_TREE: INPUT A BINARY TREE AND AN INTEGER AND PLACE ELEMENT INTO NEXT FREE SLOT
void add_to_tree(Heap tree, person element)
{
    // KEEP TREE NEARLY COMPLETE

    // NEW LEVEL NOT INTRODUCED UNLESS PREVIOUS COMPLETELY FILLED

    if (tree->size == tree->capacity)
    {
        tree->depth++;
        tree->data = (person*)realloc(tree->data, sizeof(person) * (tree->capacity + pow(2, tree->depth)));
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

    if (left < h->size && h->data[left].height > h->data[index].height)
    {
        largest = left;
    }

    if (right < h->size && h->data[right].height > h->data[index].height)
    {
        largest = right;
    }

    if (largest != index)
    {
        // SWAP
        person temp = h->data[index];
        h->data[index] = h->data[largest];
        h->data[largest] = temp;
        max_heapify(h, largest);
    }
}

// T3: BUILD_MAX_HEAP
Heap build_max_heap(Heap h)
{
    // Heap h = heap_Create();

    // for (int i = 0; i < array_size; i++)
    // {
    //     add_to_tree(h, input_array[i]);
    // }

    for (int i = h->size / 2; i > 0; i--)
    {
        max_heapify(h, i);
    }

    return h;
}

// HEAPSORT
void heap_sort(Heap h)
{
    h = build_max_heap(h); // BUILD A MAX HEAP FROM ARRAY

    for (int i = h->size - 1; i >= 1; i--)
    {
        // SWAP FIRST ELEMENT WITH LAST IN HEAP
        person temp = h->data[0];
        h->data[0] = h->data[i];
        h->data[i] = temp;

        // REDUCE THE HEAP SIZE FOR NEXT MAX ELEMENT
        h->size--;

        // ALWAYS RUN MAX_HEAPIFY ON FIRST ELEMENT (WHERE SWAP IN HEAP)
        max_heapify(h, 0);
    }
}


int main(){
    FILE* fp = fopen("dat1000.csv", "r");

    //DYNAMIC ARRAY
    person* array = (person*)malloc(sizeof(person)*1000);
    // MODIFY HEAPSORT TO SORT ARRAYS OF TYPE STRUCT PERSON
    Heap h = heap_Create(array);

    for(int i = 0; i<1000; i++){
        fscanf(fp, "%d,%[^\,],%d,%d,%d\n", &array[i].id, array[i].name, &array[i].height, &array[i].weight, &array[i].age);
        printf("HEIGHT = %d\n", array[i].age);
        add_to_tree(h, array[i]);
    }

    //PERFORM HEAP SORT
    heap_sort(h);

    for(int i = 0; i<1000; i++){
        printf("SORTED HEIGHT = %d\n", h->data[i].height);
    }

}

