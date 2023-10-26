//ITERATIVE VERSION OF INSERTION SORT

void insertInOrder(int ele, int A[], int n){
    int j = n;
    while(j>=0 && ele<A[j]){
        A[j+1] = A[j];
        j--;
    }
    A[j+1] = ele;
}
void insertionSort(int A[], int n){

    for(int j = 1; j<n; j++){
        insertInOrder(A[j], A, j-1);
    }
}