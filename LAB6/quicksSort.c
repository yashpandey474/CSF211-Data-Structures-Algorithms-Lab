//IMPLEMENT QUICKSORT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

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

    if(arr[lt]<pivot && lt<hi){
        pivPos = lt;
    }
    else{
        pivPos = lt-1;
    }
    swap(arr, lo, pivPos);
    return pivPos;

}

int randomPivot(int* arr, int lo, int hi){
    struct timeval tv;
    gettimeofday(&tv, NULL);;
    srand(tv.tv_usec*1000000 + tv.tv_sec);

    return (rand()%(hi-lo+1)+lo);
}

int pivot(int* arr, int lo, int hi){
    return randomPivot(arr, lo, hi);
}

int part(int* arr, int lo, int hi, int pInd){
    return hoarePartition(arr, lo, hi, pInd);
}
void qs(int* arr, int lo, int hi){
    if(lo<hi){
        int p = pivot(arr, lo, hi); //SELECT AN INDEX FOR PIVOT
        p = part(arr, lo, hi, p); //PARTITITON ARRAY AROUND THE PIVOR

        qs(arr, lo, p-1);
        qs(arr, p+1, hi);
    }


}

int main(){

    int* arr = (int*)malloc(sizeof(int)*5);
    
    for(int i = 0; i<5; i++){
        arr[i] = -i;
    }
    qs(arr, 0, 4);
    for(int i = 0; i<5; i++){
        printf("ELEMENT = %d\n", arr[i]);
    }

}