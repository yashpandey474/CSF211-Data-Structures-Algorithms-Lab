//Take text from test1.txt and paste to text2.txt

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    FILE *fp1;
    fp = fopen("text1.txt", "r");
    fp1 = fopen("text2.txt", "w");
    char c[100];
    int n;
    // scanf("%s", c);
    // printf("Enter %s", c);
    fscanf(fp, " %s", c);
    fprintf(fp1, "%s",c);
    
    // fclose(fp);
    // fclose(fp1);
}