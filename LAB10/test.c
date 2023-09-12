#include <stdio.h>
#include <stdlib.h>


typedef struct node* NODE;
struct node{
    NODE left;
    NODE right;
    int key;
};
typedef struct bst* bst;
struct bst{
    NODE root;
    int key;

};


int height(NODE node){
    if(node == NULL || (node->left == NULL && node->right == NULL)){
        return 0;
    }
    return max(height(node->left), height(node->right)) + 1;

}

int is_height_balanced(NODE node){
    if(abs(height(node->left) - height(node->right)) > 1){
        return -1;
    }
    return 0;
}
int is_avl(struct node* bst){
    int x = height(bst->left);
    int y = height(bst->right);

    if(bst == NULL){
        return 0;
    }

    if(abs(x-y) > 1){
        return -1;
    }

    return is_avl(bst->right) && is_avl(bst->left);
}