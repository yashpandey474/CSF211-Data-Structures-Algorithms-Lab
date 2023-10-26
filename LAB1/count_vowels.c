//cOUNT VOWELS
#include "count.h"
int count(char* string){
	
	int n = 0;
	for(int i = 0; i<strlen(string); i++){
		char c = string[i];
		
		if(c=='a'||c=='e'||c=='i'||c == 'o' || c=='u'){
			n++;
		}
	}
	return n;
}