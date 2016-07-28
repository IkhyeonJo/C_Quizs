#include <stdio.h>

typedef struct student_grade{
	char student_name[100];
	float score[3]; // 0:english, 1:math, 2:total
} STUDENT;

void Swap(STUDENT std[10], int count, int count1);

int main(void){
	STUDENT std[10];
	int count, count1, scores;
	char score_name[3][8]={"english", "math", "total"};
	
	for(count=0; count<10; count++){
	
	printf("name : ");
	scanf("%s", std[count].student_name);
	
	printf("%s score : ", score_name[0]);
	scanf("%f", &std[count].score[0]);
	
	printf("%s score : ", score_name[1]);
	scanf("%f", &std[count].score[1]);
	
	std[count].score[2] = std[count].score[0] + std[count].score[1];
	
	printf("\n");
	}
	
	printf("\n\n\n");
	for(scores=0; scores<3; scores++){
	for(count1=0; count1<10; count1++){
	for(count=count1+1; count<10; count++){
	
		if(std[count1].score[scores] < std[count].score[scores])
		Swap(std, count1, count);
	}
	}
	printf("%s score\n\n", score_name[scores]);
	for(count=0; count<10; count++)
	printf("%s:%.1f name:%s\n", score_name[scores],std[count].score[scores], std[count].student_name);
	printf("\n\n");
	}
	
	return 0;
}

void Swap(STUDENT std[10], int count1, int count){
	STUDENT std_temp;
	std_temp=std[count1];
	std[count1]=std[count];
	std[count]=std_temp;
}

