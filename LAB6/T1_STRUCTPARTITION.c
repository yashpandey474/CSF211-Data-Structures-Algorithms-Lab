//TWO-WAY ANND THREE WAY OF HOARE AND LUMOTU PARTITION
//STRUCT PERSON, BASED ON HEIGHT
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
typedef struct person person;
struct person{
    int id;
    char name[50];
    int age;
    int height;
    int weight;
};
void swap(person* arr, int i1, int i2){
    person temp = arr[i2];
    arr[i2] = arr[i1];
    arr[i1] = temp;
    return;
}

int hoarePartititon(person* arr, int lo, int hi, int pInd){
    //SWAP PIVOT WITH FIRST ELEMENT
    int lt, rt, pivPos;
    person pivot;
    swap(arr, lo, pInd);
    lt = lo +1; //LEFT POINTER
    rt = hi; //RIGHT POINTER
    pivot = arr[lo];

    while(lt < rt){
        //ITERATE FROM LEFT UNTIL ELEMNTGREATER THAN PIVOT
        for(; lt<=hi && arr[lt].height<=pivot.height; lt++);
        //ITERATE FROM RIGHT UNTIL ELEMENT LESS THAN EQUAL TO PIVOT
        for(;arr[rt].height>pivot.height; rt--);

        if(lt<rt){
            swap(arr, lt, rt);
            lt++;
            rt--;
        }
    }

    if(arr[lt].height<pivot.height && lt<hi){
        pivPos = lt;
    }
    else{
        pivPos = lt-1;
    }
    swap(arr, lo, pivPos);
    return pivPos;

}

int threeWayPartition(person* arr, int lo, int hi, int pInd){
    //SWAP PIVOT WITH HI ELLEMENT
    int lt, rt, mid, pivPos;
    person pivot;
    swap(arr, pInd, hi);
    lt = lo;
    mid = lo;
    rt = hi-1;

    while(mid<=rt){
        if(arr[mid].height<pivot.height){
            swap(arr, lt, mid);
            lt++;
            mid++;
        }
        else if (arr[mid].height>pivot.height){
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

int lomutoPartition(person* arr, int lo, int hi, int pInd){
    //SWAP PIVOT WITH HIGHER EEMENT
    int n, i, pivPos;
    person pivot;
    swap(arr, pInd, hi);

    n = (hi-lo+1);
    i = lo;
    pivot = arr[hi];

    for(int j = lo+1; j<n; j++){
        if(arr[j].height<=pivot.height){
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i+1, hi);
    pInd = i+1;
    return pInd;
    
}




int main(){
    FILE* fp = fopen("dat10000.csv", "r");
    person* arr1 = (person*)malloc(sizeof(person)*10000);
    person* arr2 = (person*)malloc(sizeof(person)*10000);
    person* arr3 = (person*)malloc(sizeof(person)*10000);
    for(int i = 0; i<10000; i++){
        fscanf(fp, "%d,%[^,],%d,%d,%d\n", &arr1[i].id, arr1[i].name, &arr1[i].height, &arr1[i].weight, &arr1[i].age);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    //PARTITITON ALL THREE AND COMPRE TIMES
    struct timeval t1, t2;
    double time_taken;

    gettimeofday(&t1, NULL);
    hoarePartititon(arr1, 0, 999, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    threeWayPartition(arr2, 0, 999, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    threeWayPartition(arr3, 0, 999, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    //HOARE PARTITITON IS FASTEST

    

}