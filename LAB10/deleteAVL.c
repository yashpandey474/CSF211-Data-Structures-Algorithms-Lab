#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODE;
struct node
{
    NODE left;
    int height;
    NODE right;
    int key;
};
typedef struct bst *bst;
struct bst
{
    NODE root;
    int key;
};


NODE deleteAVL(NODE node, int value){

    if(node == NULL){
        //NOT FOUND
        return NULL;
    }


    else if (value < node->key){
        node->left = deleteAVL(node->left, value);
        node->height = 1 + height(node->left ) > height(node->right) ?  height(node->left) : height(node->right);
    }
    else if (value > node->key){
        node->right = deleteAVL(node->right, value);
        node->height = 1 + height(node->left) > height(node->right)?height(node->left):height(node->right);
    }
    else{


        //VALUE AT CURRENT NODE
        if(node->left == NULL && node->right == NULL){
            free(node);
            node = NULL;
        }
        else if (node->left == NULL){
            NODE temp = node;
            node = node->right;
            free(temp);
        }
        else if (node->right == NULL){
            node = node->left;
        }

        else
        {
            height(node->left) : height(node->right);
        }
    }
    int balance = balance_factor(node);
    // balance factor is left height - right height
    if (balance > 1)
    {
        // left subtree is longer
        if (balance_factor(node->left) >= 0)
        {
            // node has both children
            struct node *temp = predecessor(node);
            node->value = temp->value;
            node->left = deleteAVL(node->left, temp->value);
            node->height = 1 + height(node->left) > height(node->right) ? 12
                                                                          // LL imbalance
                                                                          node = rotate_right(node);
            node->right->height = 1 + (height(node->right->left) >
                                               height(node->right->right)
                                           ? height(node->right->left)
                                           : height(node->right->right));
            node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
        }
        else
        {
            node->left->left->height = 1 + (height(node->left->left->left) >
                                                    height(node->left->left->right)
                                                ? height(node->left->left->left)
                                                : height(node->left->left->right));
            node->left->height = 1 + (height(node->left->left) >
                                              height(node->left->right)
                                          ? height(node->left->left)
                                          : height(node->left->right));
            node = rotate_right(node);
            node->right->height = 1 + (height(node->right->left) >
                                               height(node->right->right)
                                           ? height(node->right->left)
                                           : height(node->right->right));
            node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
        }
    }
    else if (balance < -1)
    {
        // right subtree is longer
        if (balance_factor(node->right) <= 0)
        {
            // RR imbalance
            node = rotate_left(node);
            node->left->height = 1 + (height(node->left->left) >
                                              height(node->left->right)
                                          ? height(node->left->left)
                                          : height(node->left->right));
            node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
        }
        else
        {
            // LR imbalance
            node->left = rotate_left(node->left);
            13

                // RL imbalance
                node->right = rotate_right(node->right);
            node->right->right->height = 1 + (height(node->right->right->left) >
                                                      height(node->right->right->right)
                                                  ? height(node->right->right->left)
                                                  : height(node->right->right->right));
            node->right->height = 1 + (height(node->right->left) >
                                               height(node->right->right)
                                           ? height(node->right->left)
                                           : height(node->right->right));
            node = rotate_left(node);
            node->left->height = 1 + (height(node->left->left) >
                                              height(node->left->right)
                                          ? height(node->left->left)
                                          : height(node->left->right));
            node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
        }
    }
    return node;
}
    
