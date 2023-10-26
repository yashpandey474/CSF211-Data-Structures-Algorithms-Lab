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
void insert(BST bst, NODE node){
    if(bst->root == NULL){
        bst->root = node;
        return;
    }

    NODE ccurrent = bst->root;
    while(current !=NULL){
        if(node->val < current->val){
            if(current->left == NULL){
                current->left = node;
                return;
            }
            current = current->left;
        }
        else{
            if(current->right == NULL){
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

void constructBS(int* arr, int size){
    BST bst = new_bst();
    for(int i = 0 ; i<size; i++){
        NODE n = new_node(arr[i]);
        insert(bst, n);
    }
    return bst;
}