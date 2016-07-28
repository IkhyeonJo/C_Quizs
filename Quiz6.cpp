#include <stdio.h>

int main(void){
	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int b[4][5]={{13,14,15,16,17},{18,19,20,21,22},{23,24,25,26,27},{28,29,30,31,32}};
	int c[3][5];
	int count[2];
	
	for(count[0]=0; count[0]<3; count[0]++){
	for(count[1]=0; count[1]<5; count[1]++){
		c[count[0]][count[1]]= a[count[0]][0]*b[0][count[1]] + a[count[0]][1]*b[1][count[1]] + a[count[0]][2]*b[2][count[1]] + a[count[0]][3]*b[3][count[1]];
		printf("%d ", c[count[0]][count[1]]);
	}
	printf("\n");
	}
	return 0;
}
