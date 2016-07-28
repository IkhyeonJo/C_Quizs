#include <stdio.h>
#define CASE_CHANGE 32

int main(void){
	char letter;
	
	printf("letter case changer! input the string : ");
	
	while(letter!='\n'){
		scanf("%c", &letter);
		if(letter>='A' && letter<='Z') letter+=CASE_CHANGE;
		else if(letter>='a' && letter<='z') letter-=CASE_CHANGE;
		printf("%c", letter); 
	}
	return 0;
}
