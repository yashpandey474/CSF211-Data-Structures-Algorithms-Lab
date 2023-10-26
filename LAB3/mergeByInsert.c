//MERGING TWO SORTED ARRAYS
//READING FROM SECOND ARRAY AND INSERT IN ORDER EADCH ELEMENT TO ARR1

#include <stdlib.h>
#include <stdio.h>

void insertInOrder(int ele, int* l1, int n1){
    int i = n1;
    while(i>=0 && l1[i]>ele){
        l1[i+1] = l1[i];
        i--;
    }
    l1[i+1] = ele;
}

void mergeByInsert(int* l1, int n1, int* l2, int n2){
    for(int i = 1; i<=n2; i++){
        insertInOrder(l2[i], l1, i-1);
    }
}

int main(){

}