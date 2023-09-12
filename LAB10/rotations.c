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


NODE rotate_left(NODE node){
    NODE a = node->right;
    node->right = a->left;
    a->left = node;
    return a;
}

NODE rotate_right(NODE node){
    NODE a = node->left;
    node->left = a->right;
    a->right = node;
    return a;
}