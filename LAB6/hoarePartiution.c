//IMPLEMENTING HOARE'S PARTITIONING

void swap(int* arr, int i1, int i2){
    int temp = arr[i2];
    arr[i2] = arr[i1];
    arr[i1] = temp;
    return;
}

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



int main(){

}