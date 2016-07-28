#include <stdio.h>

int main(void){
	int a[3][4]={ {0,1,2,3},{4,5,6,7},{8,9,10,11}};
	int count[2];
	
	for(count[0]=0; count[0]<3; count[0]++){
	for(count[1]=0; count[1]<4; count[1]++){
	a[count[0]][count[1]]+=a[count[0]][count[1]];
	printf("%d ", a[count[0]][count[1]]);
	}
	printf("\n");
	}
	return 0;
}
