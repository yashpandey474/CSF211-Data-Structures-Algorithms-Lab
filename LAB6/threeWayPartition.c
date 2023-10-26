//THREE PARTITIONS: LLESS THAN, EQUAL TO, GREATER THAN
void swap(int* arr, int i1, int i2){
    int temp = arr[i2];
    arr[i2] = arr[i1];
    arr[i1] = temp;
    return;
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

}