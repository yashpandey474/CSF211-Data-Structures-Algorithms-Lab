#include "count.h"
#include <stdio.h>
int main(void){
    char string[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", string);

    int n = count(string);
    printf("Count: %d", n);


}