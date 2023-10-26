#include <stdio.h>
#include <stdlib.h>
typedef struct criminal* CRIM;
typedef struct crime* CRIMES;
enum vals{Arson = 10, Assault = 5, Burglary = 5, Mischief = 5,
lacerny = 10, GTA = 10, homic = 20, breaking = 5};
struct crime{
    int val;
    int year;
    int crim_id;
};
struct criminal{
    int id;
    int age;
    char name[1000];
    int criminality;
};
void merge(CRIM l1, int s1, int e1, CRIM l2, int s2, int e2, CRIM l3, int s3, int e3){
    int i, j, k;
    i = s1;
    j = s2;
    k = 0;
    CRIM l4;
    l4 = (CRIM) malloc(sizeof(struct criminal)*(e3-s3+1));

    while(i<=e1 && j<=e2){
        if(l1[i].criminality<=l2[j].criminality){
            l4[k++] = l1[i++];
        }else{
            l4[k++] = l2[j++];
        }
    }
    while(i<=e1){
        l4[k++] = l1[i++];
    }
    while(j<=e2){
        l4[k++] = l2[j++];
    }

    for(int k1 = 0; k1<=e3-s3; k1++){
        l3[k1+s3] = l4[k1];
    }
    free(l4);
}

void mergeSort(CRIM arr, int start, int end){
    if(end-start < 1){
        return;
    }
    if(start<=end){
        int mid = (start+end)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, mid, arr, mid+1, end, arr, start, end);
    
    }
}

int calcriminality(CRIMES arr, int size, int id, int age){
    int sum = 0;
    for(int i = 0 ; i < size; i++){
        if(arr[i].crim_id == id){
            if(age - (2023-arr[i].year)<=18){
                sum+=arr[i].val*0.5;
            }
            sum+=arr[i].val;
        }
    }
    printf("%d", sum);
    return sum;
}
int main(){
    FILE* fp;

    int n1;
    fp = fopen("crimes.txt", "r");
    fscanf(fp, "%d\n", &n1);
    CRIMES crimeArr;
    crimeArr = (CRIMES) malloc(sizeof(struct crime)*n1);

    for(int i = 0 ; i < n1 ; i ++){
        char* crime1;
        fscanf(fp, "%[^,], %d, %d\n", crime1, &crimeArr[i].year, &crimeArr[i].crim_id);
        printf("%d", crimeArr[i].year);
        if(crime1 == "ARSON" || crime1 == "GRAND LACERNY" || crime1 == "GRAND THEFT AUTO" || crime1 == "ROBBERY"){
            crimeArr[i].val = 10;
        }
        if(crime1 == "HOMICIDE"){
            crimeArr[i].val = 20;
        }
        else{
            crimeArr[i].val = 5;
        }
    }
    printf("%d", calcriminality(crimeArr, n1, 100043, 21));


    FILE* fp1;
    fp1 = fopen("criminal_database.txt", "r");
    int n;
    fscanf(fp1, "%d\n", &n);
    printf("N = %d", n);

    CRIM arr;
    arr = (CRIM) malloc(sizeof(struct criminal)*n);

    // printf("NAME = %s", arr[0].name);
    for(int i = 0; i <  n ; i++){
        fscanf(fp1, "%[^,],%d,%d", arr[i].name,&arr[i].age, &arr[i].id);
        printf("ID = %s\n", arr[i].name);

        int sum = 0;
        for(int j = 0 ; j < n1; j++){
            if(crimeArr[j].crim_id == arr[i].id){
                if((arr[i].age - (2023-crimeArr[j].year))<=18){
                    sum+=crimeArr[j].val*0.5;
                }
                sum+=crimeArr[j].val;
            }
        }
        printf("%d\n", sum);
        arr[i].criminality = sum;
    }

    
    
    mergeSort(arr, 0, n-1);

    for(int i = 0 ; i < n ; i++ ){
        printf("%d\n", arr[i].criminality);
    }


    //ARRAY OF CRIMES AND ARRAY OF CRIMINALS CREATED
    //NOW, ASSIGN EACH CRIMINAL A CRIMINALITY VAL
    


}