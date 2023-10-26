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

//PRE-ORDER TRAVERSAL
void preOrder(NODE node){
    if(node == NULL){
        return;
    }
    printf("%d ", node->val);
    preOrder(node->left);
    preOrder(node->right);
}

//POST-ORDER
void postOrder(NODE node){
    if(node == NULL){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->val);
}