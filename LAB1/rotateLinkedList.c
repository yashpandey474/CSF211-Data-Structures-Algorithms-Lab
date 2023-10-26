#include <stdio.h>
#include <stdlib.h>

int main(){
    typedef struct node* NODE;
    struct node{
        int ele;
        NODE next;
    };

    typedef struct linkedList* LIST;
    struct linkedList{
        int count;
        NODE head;
    };

    void printList(LIST l1){
        if(l1->count==0){
            printf("Empty list");
        }
        else{
            NODE temp;
            temp = l1->head;
            while(temp->next!=NULL){
                printf("%d", temp->ele);
                temp = temp->next;
            }
            printf("%d", temp->ele);
        }
    }
    void rotate(LIST l1, int k){
        NODE temp = l1->head;

        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next = l1->head;

        temp = l1->head;
        int ele1 = l1->head->ele;
        NODE prev;
        int count = l1->count;
        for(int i = 0; i<count; i++){
            prev = temp;
            for(int j = 0; j<k; j++){
                temp = temp->next;
            }
            prev->ele = temp->ele;
            temp = prev->next;
        }
        //set back to linear lsit

        temp = l1->head;
        for(int i = 0;i<count-k;i++){
            temp = temp->next;
        }
        temp->ele = ele1;
        temp = l1->head;
        while(temp->next != l1->head){
            temp = temp->next;
        }
        temp->next = NULL;
        printList(l1);
    }

    LIST createLinkedList(){
        LIST myList;
        myList = (LIST)(malloc(sizeof(struct linkedList)));
        myList->head = NULL;
        myList->count = 0;
        return myList;
    }

    void addNode(int ele, LIST l1){
        NODE node;
        node = (NODE)(malloc(sizeof(struct node)));
        node->ele = ele;
        node->next = NULL;
        if(l1->count==0){
            l1->head = node;
            l1->count++;
            return;
        }
        NODE temp;
        temp = l1->head;
        
        while((temp->next)!=NULL){
            temp = temp->next;
        }
        temp->next = node;
        l1->count++;
    }

    LIST list = createLinkedList();
    addNode(1, list);
    addNode(2, list);
    addNode(3, list);
    addNode(4, list);
    printList(list);
    rotate(list, 1);

    


}