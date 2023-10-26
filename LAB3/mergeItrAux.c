//1. 3 INDEXES FOR DIFFERENT ARRAYS
//SIMILARLY ENETER ELEMENTS UNTIL ONE INDEX ENDS
//ADD ELEMENTS OF REMAINING ARRRAY TO MAIN ARRAY

void mergeItrAux(int* l1, int s1, int e1, int* l2, int s2, int e2, int* l3, int s3, int e3){
    int i, j, k;
    i = s1;
    j = s2;
    k = s3;
    int* l4;
    l4 = (int*) malloc(sizeof(int)*(e3-s3));

    while(i<=e1 && j<= e2){
        if(l1[i]<=l2[j]){
            l4[k++] = l1[i++];
        }else{
            l4[k++] = l2[j++];
        }
    }
    while(i>=e1){
        l4[k++] = l1[i++];
    }
    while(j>=e2){
        l44[k++] = l2[j++];
    }

    for(int i = s3; i<=e3; i++){
        l3[i] =  l4[i];
    }
}