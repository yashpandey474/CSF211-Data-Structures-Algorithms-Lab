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

//FIND IN-ORDER PREDECESSOR
NODE predecessor(NODE node){
    if(node->left == NULL){
        return NULL;
    }
    NODE current = node->left;
    while(current->right != NULL){
        current = current->right;
    }
    return current;
}

//FIND IN-ORDER SUCCESSOR
NODE successor(NODE node){
    if(node->right == NULL){
        return NULL;
    }
    NODE currennt = node->right;
    while(current->left != NULL){
        current = current->left;
    }
    return current;

}