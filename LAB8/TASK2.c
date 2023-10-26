//IMPLEMENT OPEN ADDRESSING

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int collisions = 0;
enum slotStatus {Empty, Filled, Deleted};
typedef struct hash_table_element ele;
typedef struct student student;

struct student{
    long long int ID;
    char name[30];
};

struct hash_table_element{
    student ele;
    enum slotStatus status;
};

int auxHash(long long int ID, int m){
    double a = 0.6180339887;
    double res = ID*a;
    res = (ID*a) - (int)(ID*a);
    
    return m*res;
}
int hash(long long int ID, int m, int i){
    int pos = 0;
    pos = (auxHash(ID, m) + i)%m;
    return pos;
}

void insert(ele* table, student stu, int m){
    for(int i = 0 ;i<m; i++){
        int pos = hash(stu.ID, m, i);
        if(table[pos].status != Filled){
            table[pos].ele = stu;
            table[pos].status = Filled;
            return;
        }
        else{
            collisions+=1;
        }
    }
}

void delete(ele* table, long long int ID, int m){
    for(int i = 0; i<m; i++){
        int pos = hash(ID,m, i);
        if(table[pos].status == Empty){
            break;
        }
        if(table[pos].status == Filled && table[pos].ele.ID == ID){
            table[pos].status = Deleted;
            printf("DELETED NAME %s\n", table[pos].ele.name);
            return;
        }
    }
}

student* search(ele* table, long long int ID, int m ){
    student* stu = (student*)malloc(sizeof(student));
    for(int i = 0 ;i<m; i++){
        int pos = hash(ID, m, i);
        if(table[pos].status == Empty){
            return NULL;
        }
        else{
            if(table[pos].status == Filled && table[pos].ele.ID == ID){
                *stu = table[pos].ele;
                return stu;
            }
        }
    }
    return NULL;
}

int main(){

    FILE* fp = fopen("t1_queries.txt", "r");
    int n = 1024;

    ele* hashTable = (ele*)malloc(sizeof(ele)*n);
    for(int i = 0; i<n; i++){
        hashTable[i].status = Empty;
    }
    char name[30];
    long long int ID;
    student stu;

    student* stu1 = (student*)malloc(sizeof(student));
    for(int i = 0; i<100; i++){
        fscanf(fp, "%d,", &n);
        printf("n = %d\n", n);
        if(n == 1){
            fscanf(fp, "%lld,%[^\n]\n", &stu.ID, stu.name);
            insert(hashTable, stu, 1024);
            printf("INSERTED ID %lld NAME %s\n", stu.ID, stu.name);
        }
        else if(n==2){
            fscanf(fp, "%lld\n", &ID);
            delete(hashTable, ID, 1024);
            printf("DELETED ID %lld\n", ID);
        }
        else{
            fscanf(fp, "%lld\n", &ID);
            stu1 = search(hashTable, ID, 1024);
            if(stu1 == NULL){
                continue;
            }
            printf("SEARCHED STUDENT NAME = %s\n", stu1->name);
        }
    }

    printf("TOTAL COLLISIONS = %d\n", collisions);

    
}