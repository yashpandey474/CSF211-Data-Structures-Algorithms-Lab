//BLOOM FILTER OF 256 BITS.


#include <stdio.h>
#include <stdllib.h>
#include <math.h>





int hash1(int k, int size){
    return k%size;
}

int hash2(int k, int size){
    double a == 0.6180339887;
    double res = a*k;
    res = res - ((int)res);
    return size*res;
}

int hsh3(int k){
    return k%43;
}

int hash4(int k){
    int res = pow(k, k>>3);
    return res%256;
}

int hash5(int k){
    return 255 - (k%197);
}
int main(){
    FILE* fp = fopen("bloom_numbers.txt", "r");
    int n = 50;
    int size = 256;
    size = size/(sizeof(int)*8);

    int* filter = (int*)malloc(sizeof(int)*size);
    for(int i = 0; i<50; i++){
        
    }
}
