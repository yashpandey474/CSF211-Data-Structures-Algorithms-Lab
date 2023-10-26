//SEGREGATE ZEROES ON ONE SIDE ANND ONES ON OTHER SIDE OF ARRRAY
#include <stdio.h>
#include <stdlib.h>

void swap(int* arr, int i1, int i2){
    int temp = arr[i2];
    arr[i2] = arr[i1];
    arr[i1] = temp;
    return;
}

int hoarePartition(int* arr, int lo, int hi, int pInd){
    //SWAP PIVOT WITH FIRST ELEMENT
    int pivot, lt, rt, pivPos;
    swap(arr, lo, pInd);
    lt = lo +1; //LEFT POINTER
    rt = hi; //RIGHT POINTER
    pivot = arr[lo];

    while(lt < rt){
        //ITERATE FROM LEFT UNTIL ELEMNTGREATER THAN PIVOT
        for(; lt<=hi && arr[lt]<=pivot; lt++);
        //ITERATE FROM RIGHT UNTIL ELEMENT LESS THAN EQUAL TO PIVOT
        for(;arr[rt]>pivot; rt--);

        if(lt<rt){
            swap(arr, lt, rt);
            lt++;
            rt--;
        }
    }

    if(arr[lt]<pivot && lt<=hi){
        pivPos = lt;
    }
    else{
        pivPos = lt-1;
    }
    swap(arr, lo, pivPos);
    return pivPos;

}
int lomutoPartition(int* arr, int lo, int hi, int pInd){
    //SWAP PIVOT WITH HIGHER EEMENT
    int n, i, pivot, pivPos;
    swap(arr, pInd, hi);

    n = (hi-lo+1);
    i = lo;
    pivot = arr[hi];

    for(int j = lo+1; j<n; j++){
        if(arr[j]<=pivot){
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i+1, hi);
    pInd = i+1;
    return pInd;
    
}
int threeWayPartition(int* arr, int lo, int hi, int pInd){
    //SWAP PIVOT WITH HI ELLEMENT
    int lt, rt, mid, pivot, pivPos;
    swap(arr, pInd, hi);
    lt = lo;
    mid = lo;
    rt = hi-1;

    while(mid<=rt){
        if(arr[mid]<pivot){
            swap(arr, lt, mid);
            lt++;
            mid++;
        }
        else if (arr[mid]>pivot){
            swap(arr, rt, mid);
            rt--;
        }
        else{
            mid++;
        }
    }
    //FINAL PIVOT POSITION IS MID
    pivPos = mid;
    swap(arr, mid, hi); //PIVOT WS KEPT AT HI
    return pivPos;




}

int main(){
    int* arr = (int*)malloc(sizeof(int)*20);
    for(int i = 0; i<20 ;i++){
        arr[i] = i%2;
    }
    swap(arr, 0, 1);
    // hoarePartition(arr, 0, 19, 1);
    // threeWayPartition(arr, 0, 19, 1);
    for(int i = 0; i<20 ;i++){
        printf("%d\n", arr[i]);
    }
    
}