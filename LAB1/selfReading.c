//Reads itself
#include <stdlib.h>
#include <stdio.h>


//open file

int main(){
    FILE * fp;
    fp = fopen("selfReading.c","r");
    char * string;
    char c;
    do {
         c = getc(fp);   // read character 
         putchar(c);     // display character
    }
    while(c != EOF);
    fclose(fp);
}