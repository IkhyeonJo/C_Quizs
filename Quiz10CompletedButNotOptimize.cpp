#include <stdio.h>
#include <windows.h>

void GotoXy(int x, int y);
void Initialization(char map[8][16], char stack[8][16], char adventurer_coordinate[2]);
void DrawMapAndAdventurer(char map[8][16], char adventurer_coordinate[2]);

int main(void){
	char map[8][16]; 
	char stack[8][16];
	char adventurer_coordinate[2];
	int i;
	
	Initialization(map, stack, adventurer_coordinate);
	
	while( !(adventurer_coordinate[0]==14 && adventurer_coordinate[1]==7) ){ // The coordinate of final destination
		
	for(i=0; ; i++){ // Start Search mark and Write mark
		if( (stack[adventurer_coordinate[1]][adventurer_coordinate[0]+2] == i) && (adventurer_coordinate[0]+2<16) ){
			adventurer_coordinate[0]+=2;
			stack[adventurer_coordinate[1]][adventurer_coordinate[0]]++;
			break;
		}
		else if( (stack[adventurer_coordinate[1]-1][adventurer_coordinate[0]] == i) && (adventurer_coordinate[1]-1>-1) ){
			adventurer_coordinate[1]-=1;
			stack[adventurer_coordinate[1]][adventurer_coordinate[0]]++;
			break;
		}
		else if( (stack[adventurer_coordinate[1]][adventurer_coordinate[0]-2]== i) && (adventurer_coordinate[0]-2>-2) ){
			adventurer_coordinate[0]-=2;
			stack[adventurer_coordinate[1]][adventurer_coordinate[0]]++;
			break;
		}
		else if((stack[adventurer_coordinate[1]+1][adventurer_coordinate[0]] == i) && (adventurer_coordinate[1]+1<8) ){
			adventurer_coordinate[1]+=1;
			stack[adventurer_coordinate[1]][adventurer_coordinate[0]]++;
			break;
		}
	} // end Search mark and Write mark
		system("cls");
		DrawMapAndAdventurer(map, adventurer_coordinate);
		Sleep(100);
	}
		
	getchar();
	GotoXy(20,20);
	printf("end");
	
	return 0;
}

void GotoXy(int x, int y){
 COORD CursorPosition = {x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void Initialization(char map[8][16], char stack[8][16], char adventurer_coordinate[2]){
	int i,j;
	
	for(i=0; i<8; i++){
		for(j=0; j<16; j++){
			map[i][j]=0;
			stack[i][j]=0;
		}
	}
	
	stack[1][4]=map[1][4]=-1;
	stack[1][8]=map[1][8]=-1;
	stack[1][12]=map[1][12]=-1;
	stack[2][0]=map[2][0]=-1;
	stack[2][2]=map[2][2]=-1;
	stack[2][4]=map[2][4]=-1;
	stack[2][6]=map[2][6]=-1;
	stack[2][8]=map[2][8]=-1;
	stack[2][12]=map[2][12]=-1;
	stack[3][12]=map[3][12]=-1;
	stack[4][4]=map[4][4]=-1;
	stack[4][8]=map[4][8]=-1;
	stack[4][10]=map[4][10]=-1;
	stack[4][12]=map[4][12]=-1;
	stack[4][14]=map[4][14]=-1;
	stack[5][2]=map[5][2]=-1;
	stack[5][4]=map[5][4]=-1;
	stack[6][6]=map[6][6]=-1;
	stack[6][10]=map[6][10]=-1;
	stack[6][12]=map[6][12]=-1;
	stack[6][14]=map[6][14]=-1;
	stack[7][2]=map[7][2]=-1;
	stack[7][6]=map[7][6]=-1;
	
	for(i=0; i<2; i++)
	adventurer_coordinate[i]=0;
	
	stack[0][0]=1;
	
	DrawMapAndAdventurer(map, adventurer_coordinate);
}

void DrawMapAndAdventurer(char map[8][16], char adventurer_coordinate[2]){
	int x,y;
	for(y=0; y<8; y++){
		for(x=0; x<16; x+=2){
			if(map[y][x]==-1)
			printf("бс");
			else
			printf("бр");
		}
		printf("\n");
	}
	GotoXy(adventurer_coordinate[0], adventurer_coordinate[1]);
	printf("б┌");
}
