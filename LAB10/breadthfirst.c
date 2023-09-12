//BREADTH FIRST TRAVERSAL OF AVL TREE
#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODE;
struct node
{
    NODE left;
    NODE right;
    int key;
};
typedef struct bst *bst;
struct bst
{
    NODE root;
    int key;
};



void trsverse_bfs(NODE node){
    if(node == NULL){
        return;
    }
    NODE queue[100];
    int front = 0;
    int back = 0;
    queue[back++] = node; //ENQUEUE A NODE

    while(front != back){
        NODE current = queue[front++]; //DEQUEUE A NODE
        printf("%d", current->value); //print value

        if(current->left){
            queue[back++] = current->left;
        }
        if(current->right){
            queue[back++] = current->right;
        }
    }
}
