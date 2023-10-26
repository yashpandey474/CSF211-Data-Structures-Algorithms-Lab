//APPLY 2 SUM FOR EVERY ELEMENT IN THE RRAY AFTER SORTING

#include <stdlib.h>
#include <stdio.h>

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

void twosum(int* arr, int start, int end, int val){
    int sum = 0;
    int s = start;
    int e = end;
    while(start<end){
        sum = arr[s] + arr[e];
        if(sum<val){
            s++;
        }
        if(sum>val){
            e--;
        }
        if(sum==val){
            printf("VALUES: %d %d %d\n", (0-val), arr[s], arr[e]);
            break;
        }
    }
}
int main(){
    int* arr;
    arr = (int*) malloc(sizeof(int)*5);

    arr[0] = 1;
    arr[1] = -1;
    arr[2] = 0;
    arr[3] = 4;
    arr[4] = -4;

    mergeSort(arr, 0, 4);

    for (int i = 0 ; i<3; i ++){
        int curr = arr[i];
        twosum(arr, i+1, 5-1, 0-curr);
    }
}