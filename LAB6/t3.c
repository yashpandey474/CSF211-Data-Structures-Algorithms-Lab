//IMPLEMENT QUICKSORT WITH BEST PARITTION SCHEME AND EACH OF PIVOT MECHANISMS
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int* arr, int i1, int i2){
    int temp = arr[i2];
    arr[i2] = arr[i1];
    arr[i1] = temp;
    return;
}
int median(int a, int b, int c){
    if(a<=b && b<=c || c<=b && b<=a){
        return b;
    }
    if(b<=a && b<=c || c<=a && a<=b){
        return a;
    }
    if(a<=c && c<=b || b<=c && c<=a){
        return c;
    }
}
////////////////////////////// PIVOT SELECTION TECHNIQUES ////////////////////////////
int randomPivot(int* arr, int lo, int hi){
    struct timeval tv;
    gettimeofday(&tv, NULL);;
    srand(tv.tv_usec*1000000 + tv.tv_sec);

    return (rand()%(hi-lo+1)+lo);
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
int medianOfThree(int* arr, int lo, int hi){
    int med = median(lo, hi, (lo+hi)/2);
    if(med == arr[lo]){
        return lo;
    }
    if(med == arr[hi]){
        return hi;
    }
    return (lo+hi)/2;
}
int quickSelect(int L[], int n, int k)
{
    int pivot = 0;
    int lo = 0;
    int hi = n - 1;
    int pInd = hoarePartition(L, lo, hi, pivot);
    if (k <= pInd)
    return quickSelect(L, pInd, k);
    else if (k > pInd + 1)
    return quickSelect(L + pInd + 1, n - pInd - 1, k - pInd - 1);
    else
    return L[pInd];
}

////////////////////////// MOST EFFICIENT PARTITIONING - HOARE'S PARTITIONING //////////////////////

int hoarePartititon(int* arr, int lo, int hi, int pInd){
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


int pivot(int* arr, int lo, int hi){
    return randomPivot(arr, lo, hi);
}

int part(int* arr, int lo, int hi, int pInd){
    return hoarePartition(arr, lo, hi, pInd);
}
void qsr(int* arr, int lo, int hi){
    if(lo<hi){
        int p = randomPivot(arr, lo, hi); //SELECT AN INDEX FOR PIVOT
        p = part(arr, lo, hi, p); //PARTITITON ARRAY AROUND THE PIVOR

        qsr(arr, lo, p-1);
        qsr(arr, p+1, hi);
    }
}
void qsm3(int* arr, int lo, int hi){
    if(lo<hi){
        int p = medianOfThree(arr, lo, hi); //SELECT AN INDEX FOR PIVOT
        p = part(arr, lo, hi, p); //PARTITITON ARRAY AROUND THE PIVOR

        qsm3(arr, lo, p-1);
        qsm3(arr, p+1, hi);
    }
}

void qss(int* arr, int lo, int hi){
    if(lo<hi){
        int p =quickSelect(arr, lo, (lo+hi)/2); //SELECT AN INDEX FOR PIVOT
        p = part(arr, lo, hi, p); //PARTITITON ARRAY AROUND THE PIVOR

        qss(arr, lo, p-1);
        qss(arr, p+1, hi);
    }
}


int main(){
    FILE* fp0 = fopen("int0.txt", "r");
    FILE* fp1 = fopen("int1.txt", "r");
    FILE* fp2 = fopen("int2.txt", "r");
    FILE* fp3 = fopen("int3.txt", "r");
    FILE* fp4 = fopen("int4.txt", "r");
    FILE* fp5 = fopen("int5.txt", "r");
    int* arr0 = (int*)malloc(sizeof(int)*1000);
    int* arr1 = (int*)malloc(sizeof(int)*1000);
    int* arr2 = (int*)malloc(sizeof(int)*1000);
    int* arr3 = (int*)malloc(sizeof(int)*50);
    int* arr4 = (int*)malloc(sizeof(int)*1000);
    int* arr5 = (int*)malloc(sizeof(int)*1000000);
    //READ FROM INT0, INT1, INT2, INT4
    for(int i = 0;i<1000; i++){
        fscanf(fp0, "%d\n", &arr0[i]);
        fscanf(fp1, "%d\n", &arr1[i]);
        fscanf(fp2, "%d\n", &arr2[i]);
        fscanf(fp4, "%d\n", &arr4[i]);
    }
    //READ FROM INT3
    for(int i = 0; i<50 ;i++){
        fscanf(fp3, "%d\n", &arr3[i]);
    }
    //READ FROM INT5
    for(int i = 0; i<1000000 ;i++){
        fscanf(fp5, "%d\n", &arr5[i]);
    }

    struct timeval  t1, t2;
    double time_taken;

    printf("1. QUICK SORT WITH RANDOM PIVOT\n");
    gettimeofday(&t1, NULL);
    qsr(arr0, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qsr(arr1, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qsr(arr2, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qsr(arr3, 0, 49);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qsr(arr4, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qsr(arr5, 0, 999999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);


    printf("1. QUICK SORT WITH MEDIAN OF THREE PIVOT\n");
    gettimeofday(&t1, NULL);
    qsm3(arr0, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qsm3(arr1, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qsm3(arr2, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qsm3(arr3, 0, 49);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qsm3(arr4, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qsm3(arr5, 0, 999999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);


    printf("1. QUICK SORT WITH QUICKSELECT PIVOT\n");
    gettimeofday(&t1, NULL);
    qss(arr0, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qss(arr1, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qss(arr2, 0, 999);
    gettimeofday(&t2, NULL);
    gettimeofday(&t1, NULL);
    qss(arr3, 0, 49);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qss(arr4, 0, 999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
    gettimeofday(&t1, NULL);
    qss(arr5, 0, 999999);
    gettimeofday(&t2, NULL);
    time_taken = ((t2.tv_sec - t1.tv_sec)*1000000) + (t2.tv_usec - t1.tv_usec);
    printf("TIME TAKEN = %f\n",time_taken);
}