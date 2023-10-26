#include <stdlib.h>
#include <stdio.h>

typedef struct person* PERSON;
struct person{
    int id;
    char* name;
    int age;
    int height;
    int weight;
};

void insertInOrder(struct person p, PERSON arr, int n){
    int j = n-1;
    while(j>=0 && p.height < arr[j].height){
        arr[j+1] = arr[j]; 
        j--;
    }
    arr[j+1] = p;
}
void insertionSort(PERSON arr, int size){

    for(int i = 1; i < size; i++){
        insertInOrder(arr[i], arr, i);
    }
}





int main(){
    PERSON arr;
    FILE* fp;
    fp = fopen("dat1000.csv", "r");
    arr = (PERSON)malloc(sizeof(struct person)*1000);

    for(int i = 0 ; i < 1000 ; i ++){
        fscanf(fp, "%d,%[^,],%d,%d,%d\n", &arr[i].id, arr[i].name,&arr[i].age,&arr[i].height,&arr[i].weight);
    }
    insertionSort(arr, 1000);

    for(int i = 0; i < 100 ; i ++){
        printf("%d HEIGHT: %d\n", arr[i].height);
    }
    
}