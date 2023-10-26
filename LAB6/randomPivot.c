//GENERATE A RNDOM PIVOT
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int randomPivot(int* arr, int lo, int hi){
    struct timeval tv;
    gettimeofday(&tv, NULL);;
    srand(tv.tv_usec*1000000 + tv.tv_sec);

    return (rand()%(hi-lo+1)+lo);
}


int main(){
    
}