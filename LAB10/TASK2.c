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


NODE new_node(int key){
    NODE node = (NODE)malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->key = key;
    return node;
}

int is_height_balanced(NODE node){
    return (abs(get_height(node->left) - get_height(node->right)) > 1?-1:1);
}


int get_height(NODE node){
    if(!node){
        return 0;
    }
    return node->height;
}

//INSERTAVL HAS TIME: O(HEIGHT^2): STORE INFO ABOUT HEIGHT
NODE insertAVL(NODE root, int value)
{
    if (root == NULL)
    {
        root = new_node(value);
    }

    else if (value < root->key)
    {
        root->left = insertAVL(root->left, value);
    }
    else
    {
        root->right = insertAVL(root->right, value);
    }

    int balance = is_height_balanced(root);
    if (balance == -1)
    {

        if (value < root->key)
        {
            if (value < root->left->key)
            {
                // LL ROTATION
                root = rotate_right(root);
            }
            else
            {
                // LR rotation
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
        else
        {
            if (value > root->right->key)
            {
                // RR Imbalance
                root = rotate_left(root);
            }
            else
            {
                // RL imbalance
                root->right = rotate_right(root);
                root = rotate_left(root);
            }
        }
    }
    //UPDATE HEIGHT OF ROOT NODE
    root->height = 1 + max(get_height(root->left), get_height(root->right));

    return root;
}