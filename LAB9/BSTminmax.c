#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node* NODE;
struct node{
    int val;
    NODE left;
    NODE right;
};

typedef sruct bst* BST;
struct bst{
    NODE root;
};


BST new_bst(){
    BST tree = malloc(sizeof(struct bst));
    tree->root = NULL;
    return tree;
}
NODE new_node(int val){
    NODE n = (NODE)malloc(sizeof(struct node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

//FIND MINIMUM
int find_min(BST bst){
    NODE current = bst->root;
    while(current->left != NULL){
        current = current->left;
    }
    return current->val;
}

//FIND MAXIMUM
int find_max(BST bst){

    NODE current = bst->root;
    if(curret == NULL){
        return -1;
    }
    while(current->right != NULL){
        current = current->right;
    }
    return current->val;
}