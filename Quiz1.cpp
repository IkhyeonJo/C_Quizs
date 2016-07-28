#include <stdio.h>

int main(void){
	int integer;
	float real_number;
	char letter;
	char string;
	
	printf("Input integer, real number, letter, string type characters!!\n");
	scanf("%d %f %c", &integer, &real_number, &letter);
	printf("%d %f %c ", integer, real_number, letter);
	
	while(string !='\n'){
		scanf("%c", &string);
		printf("%c", string);
	}
	return 0;
}
