//FIND MEDIAN OF MEDIANS

//DIVIDE ARRAY INTO GROUPS OF 5 AND FIND MEDIANS RECURSIVELY UNTIL ONE LEFT
void swap(int* arr, int i1, int i2){
    int temp = arr[i2];
    arr[i2] = arr[i1];
    arr[i1] = temp;
    
}
///K = N/2?
//ARRAY IS OF LENGTH N AND KTH SMALLEST ELEMENT IS RETURNED
int mediansOfMedians(int* arr, int n, int k){
    if(k == 0){
        return arr[0];
    }
    if(n<=5){
        for(int i = 1; i<n ;i++){
            for(int j = i-1; j>=0 ; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr, j, j+1);
                }
                else{
                    break;
                }
            }
        }
    }

    //PARTITION ARRAY INTO GROUPS OF 5 ELEMENTS
    int numOfGroups;
    if(n%5 == 0){
        numOfGroups = n/5;
    }
    else{
        numOfGroups = n/5 + 1;
    }

    int medians[numOfGroups];

    for(int i = 0; i<numOfGroups; i++){
        medians[i] = mediansOfMedians(arr + i*5, min(5, n-i*5), min(5, n-i*5)/2); //REDUING ARRAY BY 5 ELEMENTS
        //K IS NUMBER OF ELEMENTS REMAINING/2
        //MIN AS ARRAY MAY BECOME OF LESS THAN 5 ELEMENTS
    }

    int M = select(medians, numOfGroups, (numOfGroups+1)/2);
    //FINDING 1 MEDIAN OF ALL MEDINS


    //PARTITION ARRAY INTO TWO HALVES
    // WITH M AS PIVOT
    int mInd;
    for(int i = 0; i<n ; i++){
        if(L[i] == M){
            mInd = i;
            break;
        }
    }
    int pInd = part(arr, 0, n-1, mInd);

    if(k<=pInd){
        return mediansOfMedians(arr, pInd, k);
    }
    else if (k > pInd+1){
        return mediansOfMedians(arr + pInd + 1, n - pInd - 1, k-pInd-1);
    }
    else{
        return L[pInd];
    }

}
int main(){

}