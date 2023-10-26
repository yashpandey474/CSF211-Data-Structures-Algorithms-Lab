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

//DELETE A NODE
void delete(BST bst, NODE node){
    if(node == NULL){
        return;
    }
    if(node->left == NULL && node->right == NULL){
        //LEAF NODE
        NODE current = bst->root;
        while (current != NULL)
        {
            if(current->left == node){
                current->left = NULL;
                break;
            }
            if(current->right == node){
                break;
            }
            if(node->val < current->val){
                current = current->left;
            }
            else{
                current= current->right;
            }
            /* code */
        }
        free(node);
        return;
    }

    if(node->left == NULL){
        //HAS LEFT NODE
        NODE current =  bst->root;
        if(current == node){
            bst->root = node->right;
            free(node);
            return;
        }
        while(current != NULL){
            if(current->left == node){
                current->left = node->right;
                break;

            }
            if(current->right == node){
                current->right = node->ight;
                break;
            }
            if(node->val < current->val){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        free(node);
        return;
    }

    if(node->right == NULL){
        NODE current = bst->root;
        if(current == node){
            bst->root = node->left;
            free(node);
            return;
        }
        while(current != NULL){
            if(current->left == node){
                current->left = node->left;
                break;
            }
            if(current->right == node){
                current->right = node->left;
                break;
            }
            if(node->val < current->val){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        free(node);
        return;
    }

    NODE temp = successor(node);
    node->val = temp->val;
    delete(bst, temp);
    return;

}