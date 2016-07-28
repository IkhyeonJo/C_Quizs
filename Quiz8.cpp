#include <stdio.h>
#include <windows.h>
#include <math.h>

void GotoXy(int x, int y);

int main(void){
	FILE *fp;
	char data[100]={0};
	int i,j,count,count1;
	int number_data[50]={0};
	int max, minimum;
	int differentiation[49];
	
	fp=fopen("Quiz7Data.txt", "r");
	
	if(fp == NULL)
	printf("file open fail!\n");
	else
	printf("file open success!\n");

	for(j=0; j<50; j++){
	//printf("j:%d\n",j);
	fgets(data, 100, fp);
	for(i=0; (data[i]!=10&&i<100); i++){
	//printf("data[%d] : %d\n", i,data[i]);
	}
	count=(i-1);
	//printf("count:%d\n", count);
	if(data[0] != '-'){
	for(count1=0; count1<=count; count1++){
		number_data[j]+=(data[count1]-'0')*pow(10,count-count1);
	}
	//printf("number_data[%d]=%d\n", j,number_data[j]);
	}
	
	else{
	for(count1=1; count1<=count; count1++){
		number_data[j]+=(data[count1]-'0')*pow(10,count-count1);
	}
	number_data[j]=-number_data[j];
	//printf("number_data[%d]=%d\n", j,number_data[j]);	
	}
	}
	
	for(i=0; i<49; i++){
	differentiation[i]=number_data[i+1]-number_data[i];
	//printf("number_data[%d](%d) + number_data[%d](%d) =differentiation[%d](%d)\n", i,number_data[i],i+1,number_data[i+1],i,differentiation[i]);
	}
	
	max=differentiation[0];
	minimum=differentiation[0];
	
	for(i=0; i<49; i++){
		if(max<differentiation[i])
		max=differentiation[i];
		if(minimum>differentiation[i])
		minimum=differentiation[i];
	}
	//printf("max : %d, minimum : %d\n", max, minimum);
	
	minimum=-minimum;
	
	max>minimum ? max=max : max=minimum; 
	
	
	
	for(i=0; i<49; i++){
	if(differentiation[i]>0){
	for(j=0; j<differentiation[i]; j++){
	
		GotoXy(i, max-j);
		printf("-");
		//Sleep(1);
	}
	}
	else{
	for(j=0; j>differentiation[i]; j--){
	
	GotoXy(i, max+abs(j));
	printf("-");
		//Sleep(1);
	}
	}
	}
	
	GotoXy(49,max+minimum); // for end
	
	fclose(fp);
	return 0;
}

void GotoXy(int x, int y)
{
 COORD CursorPosition = {x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
