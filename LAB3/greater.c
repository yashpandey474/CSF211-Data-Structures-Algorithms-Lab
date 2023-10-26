//array of integers given. find integer where number of integers greater thn p eqals to p

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void merge(int* l1, int s1, int e1, int* l2, int s2, int e2, int* l3, int s3, int e3){
    int i, j, k;
    i = s1;
    j = s2;
    k = s3;
    int* l4;
    l4 = (int*) malloc(sizeof(int)*(e3-s3));

    while(i<=e1 && j<= e2){
        if(l1[i]<=l2[j]){
            l4[k++] = l1[i++];
        }else{
            l4[k++] = l2[j++];
        }
    }
    while(i<=e1){
        l4[k++] = l1[i++];
    }
    while(j<=e2){
        l4[k++] = l2[j++];
    }

    for(int k1 = s3; k1<=e3; k1++){
        l3[k1] =  l4[k1];
    }
}

void mergeSort(int* arr, int start, int end){
    if(end-start < 1){
        return;
    }
    if(start<=end){
        int mid = (start+end)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, mid, arr, mid+1, end, arr, start, end);
    
    }
}
int main(){
    int* arr;
    arr =  (int*) malloc(sizeof(int)*4);
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 3;
    arr[3] = 2;

    mergeSort(arr, 0, 3);

    for(int i = 0 ; i  < 4; i++){
        printf("%d\n", arr[i]);
    }

    //FIND ELEMENT WHERE NO OF GREATER ARE EQUAL
    bool flag;
    flag = false;
    for(int i = 0 ; i < 4; i++){
        if(arr[i] == 4-i-1){
            printf("ELEMENT FOUND: %d",arr[i]);
            flag = true;
        }
    }
    if(!flag){
        printf("NO ELEMENT FOUND");
    }

}