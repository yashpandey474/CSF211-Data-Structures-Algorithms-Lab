//SINGLE POINTER ITERATION FROM LEFT TO RIGHT
//PIVOT SWAPPED WITH LAST ELEMENT
//J INCREMEMENTED FROM 1 TO N-1 AND IF LESS THAN PIVOT, SWAPPED WITH A[I]

void swap(int* arr, int i1, int i2){
    int temp = arr[i2];
    arr[i2] = arr[i1];
    arr[i1] = temp;
    return;
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


int main(){

}