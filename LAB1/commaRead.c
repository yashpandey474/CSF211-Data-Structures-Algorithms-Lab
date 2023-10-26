#include<stdlib.h>
#include<stdio.h>
#include <string.h>

int main(){
    FILE* fp;
    fp = fopen("data.txt", "r");
    char * value = malloc(1000*sizeof(char));

    while(fgets(value, 100, fp)!=NULL){
        char * token = strtok(value, ",");
        while(token!=NULL){
            printf("%s\n", token);
            token = strtok(value, "-,")
        }
   }
}
