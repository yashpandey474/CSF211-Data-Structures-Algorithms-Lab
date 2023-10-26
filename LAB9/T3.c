#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


typedef struct node* NODE;
struct node{
    int val;
    NODE left;
    NODE right;
};

typedef sruct bst* BST;
sstruct bst{
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

//TEST IF IT SATIFIES SEARC TREE PROPERTY
bool BSTproperty(NODE current, bool right, int rootVal){
    if(current == NULL){
        return true;
    }
    if(right){
        if(current->val < rootVal){
            return false;
        }
    }
    else{
        if(current->val>rootVal){
            return false;
        }
    }
    if(!BSTproperty(current->left) || !BSTproperty(current->right)){
        return false;
    }
    return true;
    

}