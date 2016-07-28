#include <stdio.h>

int main(void){
	int inputs[5], count;
	int max=inputs[0];
	
	printf("input integer type five numbers : ");
	scanf("%d %d %d %d %d", &inputs[0], &inputs[1], &inputs[2], &inputs[3], &inputs[4]);
	//printf("%d %d %d %d %d", inputs[0], inputs[1], inputs[2], inputs[3], inputs[4]);
	for(count=1; count<5; count++)
		if(max<inputs[count]) 
		max=inputs[count];
	
	printf("max = %d\n", max);
	return 0;
}
