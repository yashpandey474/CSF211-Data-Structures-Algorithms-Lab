#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct student student;
typedef struct list* LIST;
typedef struct node* NODE;
struct student{
    long long int ID;
    char name[30];
};

struct node{
    NODE next;
    student ele;
};

struct list{
    NODE head;
    int count;
};

LIST createList(){
    LIST myLIST = (LIST)malloc(sizeof(struct list));
    myLIST->head = NULL;
    myLIST->count = 0;
    return myLIST;
}
NODE createNode(student ele){
    NODE myNode = (NODE)malloc(sizeof(struct node));
    myNode->ele = ele;
    myNode->next = NULL;
    return myNode;
}
void insertFirst(LIST l1, NODE n1){
    n1->next = l1->head;
    l1->head = n1;
    l1->count++;
}
int function1(student stu, int size){
    return (stu.ID)%(size);
}

int function2(student stu,  int size){
    int maxPos = 1;
    for(; maxPos<size; maxPos *=2);
    maxPos/=2;
    return (stu.ID)%maxPos;
}
int isPrime(int n){
    int ans = 1;
    for(int i =2; i<n; i++){
        if(n%i == 0){
            ans = 0;
            break;
        }
    }
}
int function3(student stu, int size){
    //PRIME NUMBER JUST LESS THAN SIZE
    int number = 2;
    for(int i = 2; i<stu.ID; i++){
        if(isPrime(i)){
            number = i;
            continue;
        }
    }
    return stu.ID%number;
}

// int function4(student stu, int size){
//     //h(k) = |m(kA mod 1)|
//     double a = 0.6180339887;
//     int m = size;
//     double res =(double)((a*stu.ID)%1);
//     return floor(m*res);
// }

void hashElement(LIST* hashTable, student stu, int size){
    int hashFunc = function1(stu, size);
    printf("FUNC = %d\n", hashFunc);
    insertFirst(hashTable[0], createNode(stu));
    return;
}
int main(){
    FILE* fp = fopen("t1_data.txt", "r");
    int n;
    fscanf(fp, "%d\n", &n);

    long long int ID;
    char name[30];

    //HASH TABLE RESOLVING BY CHAINING: SIZE = 2*N
    LIST* hashTable = (LIST*)malloc(sizeof(LIST)*2*n);

    for(int i  =0; i<2*n; i++){
        hashTable[i] = createList();
    }
    student stu;
    printf("SIZE = %d\n", 2*n);
    for(int i  = 0; i<n; i++){
        fscanf(fp, "%lld, %[^\n]\n", &stu.ID, stu.name);
        // printf("NAME = %s\n", name);
        hashElement(hashTable, stu, 2*n);
    }

    int collisions = 0;
    for(int i = 0; i<2*n; i++){
        if(hashTable[i]->count != 1){
            collisions+=hashTable[i]->count;
        }
    }
    printf("TOTAL COLLISIONS = %d\n", collisions);
}