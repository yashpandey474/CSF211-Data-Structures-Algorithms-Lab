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

//CALCULATE HEIGHT OF BST
int BSTheight(BST bst){
    NODE current = bst->root;
    if(current == NULL){
        return 0;
    }
    NODE nodeL = current->left;
    NODE nodeR = current->right;
    int height1 = 0;
    int height2 = 0;
    while(left != NULL){
        height1++;
        nodeL = nodeL->left;
    }
    while(right != NULL){
        height2++;
        nodeR = nodeR->right;
    }
    if(height1>height2){
        return height1;
    }
    return height2;
}