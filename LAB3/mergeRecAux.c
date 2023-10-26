//1. MERGE TWO SORTED ARRAYS
//2. USE AN AUX ARRAY TO STORE ELEMENTS
//3. RECURSIVE METHOD


void merge(int* l1, int s1, int e1, int* l2, int s2, int e2, int* l3, int s3, int e3){
    if(s1>e1 ){
        if(s2>e2){
            return;
        }
        if(s3>e3){
            return;
        }
        l3[s3] = l2[s2];
        merge(l1, s1, e1, l2, s2+1, e2, l3, s3+1, e3);
    }
    if(s2>e2){
        if(s1>e1){
            return;
        }
        if(s3>e3){
            return;
        }
        l3[s3] = l1[s1];
        merge(l1, s1+1, e1, l2, s2, e2, l3, s3+1, e3);
    }

    if(l1[s1] <= l2[s2]){
        l3[s3] = l1[s1];
        merge(l1, s1+1, e1, l2, s2, e2, l3, s3+1, e3);
    }
    else{
        l3[s3] = l2[s2];
        merge(l1, s1, e1, l2, s2+1, e2, l3, s3+1, e3);
    }

    
}