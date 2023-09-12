/**
 * You are given an integer array gifts that denotes the number of gifts present in various piles. 
 * This means that gifts[i] denotes the number of gifts present in the ith pile. Every second, you greedily find the pile that has 
 * the most number of gifts and pick enough gifts from the pile 
 * to always leave behind the square root of the number of gifts
 * initially present in the pile (if the square root is fractional, you leave behind only the integer part).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct heap
{
    int *data; // INTEGER ITSELF IS THE KEY
    int size;
    int capacity;
    int depth;
};

typedef struct heap *Heap;

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
    if (h->size <= node)
    {
        printf("NODE DOESN'T EXIST");
        return -1;
    }

    return (node - 1) / 2;
}

int left_child(Heap h, int node)
{
    if (h->size <= node)
    {
        printf("NODE DOESN'T EXIST");
        return -1;
    }

    return 2 * node + 1;
}

int right_child(Heap h, int node)
{
    if (h->size <= node)
    {
        printf("NODE DOESN'T EXIST");
        return -1;
    }
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

    if (right < h->size && h->data[right] > h->data[largest])
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

void insert(Heap h, int value)
{
    add_to_tree(h, value);
    // Complete the function here

    int index = h->size - 1;
    while (index > 0 && h->data[parent(h, index)] < h->data[index])
    {
        int temp = h->data[parent(h, index)];
        h->data[parent(h, index)] = h->data[index];
        h->data[index] = temp;

        index = parent(h, index);
    }

    return;
}

int maximum(Heap h)
{
    if (h->size == 0)
        return -1; // -1 denotes that the heap is empty
    else
        return h->data[0];
}

// RUNNING TIME = O(LOGN)
int extract_maximum(Heap h)
{
    int max = maximum(h);

    h->data[0] = h->data[h->size - 1];
    h->size--;
    max_heapify(h, 0);
    // Complete the function here
    return max;
}

void increase_key(Heap h, int index, int k)
{
    if (k < h->data[index])
    {
        printf("KEY CANNOT BE DECREASED");
        return;
    }

    h->data[index] = k;
    // Complete the function here

    while (index > 0 && h->data[parent(h, index)] < h->data[index])
    {
        int temp = h->data[parent(h, index)];
        h->data[parent(h, index)] = h->data[index];
        h->data[index] = temp;

        index = parent(h, index);
    }
    return;
}

int pick_gifts(int* gifts, int size, int k){
    //TOTAL NUMBER OF GIFTS AFTER K SECONDS HAVE PASSED
    

    //EVERY SECOND:
    //CHANGE THE KEY OF ELEMENT WITH MAX PRIORITY TO SQUARE-ROOT(KEY)

    //CREATE A PRIORITY QUEUE WITH THE ELEMENTS
    Heap h = heap_Create();

    //INSERT EACH ELEMENT INTO ARRAY
    for(int i = 0; i<size; i++){
        insert(h, gifts[i]);
    }

    //CHANGE KEY OF MAX ELEMENT
    for(int i = 0; i<k; i++){
        //CANNOT USE INCREASE-KEY
        int max = extract_maximum(h);
        max = (int)sqrt(max);

        //INSERT BACK THE ELEMENT
        insert(h, max);
    }

    //FIND SUM OF ELEMENTS
    int sum = 0;
    for(int i = 0; i<h->size; i++){
        sum+= h->data[i];
    }
    return sum;
}

int main(){
    int* gifts = (int*)malloc(sizeof(int)*5);
    for(int i = 0 ;i<5; i++){
        gifts[i] = 2*i;
    }
    int total = pick_gifts(gifts, 5, 5);

    printf("TOTAL = %d\n", total);
}