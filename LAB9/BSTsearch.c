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

int search(BST bst, int key){{
    NODE current = bst->root;
    while(current != NULL){
        if(current->val == key){
            return 1;
        }
        if(current->val > key){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return 0;
}}