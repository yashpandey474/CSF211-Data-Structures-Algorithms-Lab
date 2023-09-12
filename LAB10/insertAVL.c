#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODE;
struct node
{
    NODE left;
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
    node->key = key;
    return node;
}

NODE insertAVL(NODE root, int value){
    if(root == NULL){
        root = new_node(value);
    }

    else if(value < root->key){
        root->left = insertAVL(root->left, value);
    }
    else{
        root->right = insertAVL(root->right, value);
    }


    int balance = is_height_balanced(root);
    if(balance == -1){

        if(value < root->key){
            if(value<root->left->key){
                //LL ROTATION
                root = rotate_right(root);
            }
            else{
                //LR rotation
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
        else{
            if(value>root->right->key){
                //RR Imbalance
                root = rotate_left(root);
            }
            else{
                //RL imbalance
                root->right = rotate_right(root);
                root = rotate_left(root);
            }
        }
    }

    return root;

}

int main(){
    bst tree = new_bst();
    insertAVL(tree, 1);
    insertAVL(tree, 2);
    insertAVL(tree, 3);
    
}