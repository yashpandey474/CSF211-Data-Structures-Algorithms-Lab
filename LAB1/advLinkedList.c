//deleteAt(), insertFIrst(), search()

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

    void deleteAt(int pos, LIST l1){
        NODE temp;
        NODE prev;
        temp = l1->head;

        for(int i = 1; i<pos; i++){
            prev = temp;
            if(i==pos){
                prev->next = temp->next;
                l1->count--;
                free(temp);
            }
            temp = temp->next;
        }
        
    }
}