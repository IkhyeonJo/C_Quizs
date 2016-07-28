#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define LEFT_KEY 75
#define RIGHT_KEY 77
#define UP_KEY 72
#define DOWN_KEY 80
#define SNAKE_X_COORDINATE 0
#define SNAKE_Y_COORDINATE 1
#define FIRST_SNAKE_HEAD_X_COORDINATE 50
#define FIRST_SNAKE_HEAD_Y_COORDINATE 15

void GotoXy(int x, int y);
void Initialization(char snake[2][3100], char food_coordinate[2]);
void DrawFrame(void);
void FrameWidth(void);
void FrameHeigh(void);
void VoidSnake(char snake[2][3100]);
void FirstSnakeInfo(char snake[2][3100]);
void GenerateFood(char snake[2][3100], char food_coordinate[2]);
void DrawSnakeAndFood(char snake[2][3100], char food_coordinate[2]);
void ContentsChecker(char snake[2][3100], char *direction, char food_coordinate[2]);
char ChangeDirection(char key);
char UpdateCoordinate(char direction, char snake[2][3100]);
void AddBody(char snake[2][3100], char for_add_body);
void EraseSnakeAndFood(char snake[2][3100], char food_coordinate[2]);
void KeyProcess(char *direction);
void IsEatFoodCheck(char snake[2][3100], char food_coordinate[2], char for_add_body);
int DeathCheck(char snake[2][3100]);

int main(void){
	char snake[2][3100];
	char direction=RIGHT_KEY; // FIRST DIRECTION
	char food_coordinate[2];
	char for_add_body;
	
	srand((unsigned int)(time(NULL)));
	Initialization(snake, food_coordinate);
	
	while(1){
		
		KeyProcess(&direction);
		
		EraseSnakeAndFood(snake, food_coordinate);
		for_add_body=UpdateCoordinate(direction, snake);
		DrawSnakeAndFood(snake, food_coordinate);
		IsEatFoodCheck(snake, food_coordinate, for_add_body);
		
		if(DeathCheck(snake)){
			GotoXy(0,0);
			printf("Game Over!");
			getchar();
			return 0;
		}
		
		Sleep(1000);
		//ContentsChecker(snake, &direction, food_coordinate);
	}
	
	return 0;
}
 
void GotoXy(int x, int y){
 COORD CursorPosition = {x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void Initialization(char snake[2][3100], char food_coordinate[2]){
	VoidSnake(snake);
	DrawFrame();
	FirstSnakeInfo(snake);
	GenerateFood(snake, food_coordinate);
	DrawSnakeAndFood(snake, food_coordinate);
}

void VoidSnake(char snake[2][3100]){
	int i,j;
	for(i=0; i<2; i++){
		for(j=0; j<3100; j++){
			snake[i][j]=0;
		}
	}
	
}

void DrawFrame(void){
	FrameWidth();
	FrameHeigh();
} 

void FrameWidth(void){
	int x;
	for(x=0; x<100; x=x+2){
		GotoXy(x,0);
		printf("бс");
		GotoXy(x,29);
		printf("бс");
	}
}

void FrameHeigh(void){
	int y;
	for(y=1; y<29; y++){
		GotoXy(0,y);
		printf("бс");
		GotoXy(98,y);
		printf("бс");
	}
}

void FirstSnakeInfo(char snake[2][3100]){
	int init_body_length;
	
	// snake_head
	snake[0][0]=FIRST_SNAKE_HEAD_X_COORDINATE;
	snake[1][0]=FIRST_SNAKE_HEAD_Y_COORDINATE;
	
	//printf("HeadX:%d HeadY:%d\n", snake[0][0], snake[1][0]);
	
	for(init_body_length=1; init_body_length<=3; init_body_length++)
	{
		// snake_body
		snake[0][init_body_length]=FIRST_SNAKE_HEAD_X_COORDINATE-init_body_length;
		snake[1][init_body_length]=FIRST_SNAKE_HEAD_Y_COORDINATE;
		//printf("Body:%c BodyX:%d BodyY:%d\n", snake[0][init], snake[1][init], snake[2][init]);
	}
}

void GenerateFood(char snake[2][3100], char food_coordinate[2]){
	int i;
	
	food_coordinate[0]=rand()%96+2;
	food_coordinate[1]=rand()%28+1;
	
	
	for(i=0; i<3100; i++){
		if(snake[0][i]==food_coordinate[0] || snake[1][i]==food_coordinate[1]){
		food_coordinate[0]=rand()%96+2;
		food_coordinate[1]=rand()%28+1;
		i=0;	
		}
	}
	
}

void DrawSnakeAndFood(char snake[2][3100], char food_coordinate[2]){
	int info;
	for(info=1; info<3100; info++){
		if(snake[0][info]!=0){
			GotoXy(snake[0][info], snake[1][info]);
			printf("O");
		}
		else break;
	}
	GotoXy((int)snake[0][0], (int)snake[1][0]);
	printf("@");
	GotoXy((int)food_coordinate[0], (int)food_coordinate[1]);
	printf("*");
}

void KeyProcess(char *direction){
	char key;
	
	if(kbhit()){
		key=getch();
		
		if(key==-32)
		key=getch();
		
		if( (key==LEFT_KEY) || (key == RIGHT_KEY) || (key == UP_KEY) || (key == DOWN_KEY) ) // can change the direction arrow key only 
		*direction = ChangeDirection(key);
		
		}
}

void ContentsChecker(char snake[2][3100], char *direction, char food_coordinate[2]){
	int i,j;
	for(i=0; i<2; i++){
	for(j=0; snake[i][j]!=0; j++){
			printf("snake[%d][%d]=%d\n", i,j,snake[i][j]);
		}
	}
	
	printf("food_coordinate[0]=%d, food_coordinate[1]=%d, direction=%d\n", food_coordinate[0], food_coordinate[1], *direction);
}

char ChangeDirection(char key){
	switch(key){
			case LEFT_KEY : return LEFT_KEY;
			case RIGHT_KEY : return RIGHT_KEY;
			case UP_KEY : return UP_KEY;
			case DOWN_KEY : return DOWN_KEY;
			default : break; 
		}
}

char UpdateCoordinate(char direction, char snake[2][3100]){
	char difference[2]={0};
	int i;
	
	switch(direction){
		case RIGHT_KEY : 
		snake[0][0]++;
		difference[0]=1;
		if( (snake[0][0]==snake[0][1]) && (snake[1][0]==snake[1][1]) ){
			snake[0][0]-=2;
			difference[0]=-1;
		}
		break;
		
		case LEFT_KEY :
		snake[0][0]--;
		difference[0]=-1;
		if( (snake[0][0]==snake[0][1]) && (snake[1][0]==snake[1][1]) ){
			snake[0][0]+=2;
			difference[0]=1;
		}
		break;
		
		case UP_KEY :
		snake[1][0]--;
		difference[1]=-1;
		if( (snake[0][0]==snake[0][1]) && (snake[1][0]==snake[1][1]) ){
			snake[1][0]+=2;
			difference[1]=1;
		}
		break;
		
		case DOWN_KEY :
		snake[1][0]++;
		difference[1]=1;
		if( (snake[0][0]==snake[0][1]) && (snake[1][0]==snake[1][1]) ){
			snake[1][0]-=2;
			difference[1]=-1;
		}
		break;
		
		default :
		printf("default!\n");
		return -111; // for exit (garbage value)
		
	}
	
	for(i=0; snake[0][i+1]!=0; i++){
		if(difference[0]==1 || difference[0]==-1){
			if(snake[1][i]==snake[1][i+1]){
				if(difference[0]==1) snake[0][i+1]=snake[0][i]-1;
				else if(difference[0]==-1) snake[0][i+1]=snake[0][i]+1;
				difference[0]=snake[0][i]-snake[0][i+1];
				difference[1]=0;
			}
			else{
				difference[1]=snake[1][i]-snake[1][i+1];
				snake[1][i+1]=snake[1][i];
				difference[0]=0;
			}
		}
		else if(difference[1]==1 || difference[1]==-1){
			if(snake[0][i]==snake[0][i+1]){
				if(difference[1]==1) snake[1][i+1]=snake[1][i]-1;
				else if(difference[1]==-1) snake[1][i+1]=snake[1][i]+1;
				difference[1]=snake[1][i]-snake[1][i+1];
				difference[0]=0;
			}
			else{
				difference[0]=snake[0][i]-snake[0][i+1];
				snake[0][i+1]=snake[0][i];
				difference[1]=0;
			}
		}
	}
	
	if(difference[0]!=0)
	return -difference[0];
	else if(difference[0]==0 && difference[1]==1)
	return -2;
	else if(difference[0]==0 && difference[1]==-1)
	return 2;
}

void AddBody(char snake[2][3100], char for_add_body){
	int i=0;
	while(snake[0][i]!=0){
		i++;
	}
	//printf("i=%d\n", i);
	
	if((for_add_body==1) || (for_add_body==-1)){
		snake[0][i]=snake[0][i-1]+for_add_body;
		snake[1][i]=snake[1][i-1];
	}
	else if(for_add_body==-2){
		snake[0][i]=snake[0][i-1];
		snake[1][i]=snake[1][i-1]-1;
	}
	else if(for_add_body==2){
		snake[0][i]=snake[0][i-1];
		snake[1][i]=snake[1][i-1]+1;
	}
}

void EraseSnakeAndFood(char snake[2][3100], char food_coordinate[2]){
	
	int i;
	
	for(i=0; snake[0][i]!=0; i++){
		GotoXy(snake[0][i], snake[1][i]);
		printf(" ");
	}
	GotoXy(food_coordinate[0], food_coordinate[1]);
	printf(" ");
}

void IsEatFoodCheck(char snake[2][3100], char food_coordinate[2], char for_add_body){
	if((food_coordinate[0]==snake[0][0]) && (food_coordinate[1]==snake[1][0]))
		{
			//printf("hithit!");
			EraseSnakeAndFood(snake, food_coordinate);
			AddBody(snake, for_add_body);
			GenerateFood(snake, food_coordinate);
			DrawSnakeAndFood(snake, food_coordinate);
			//Need add body function
		}
}

int DeathCheck(char snake[2][3100]){
	int i;
	for(i=1; snake[0][i]!=0; i++){
		if((snake[0][0]==snake[0][i]) && (snake[1][0]==snake[1][i]))
		return 1;
	}
	
	if( (snake[0][0]<2) || (snake[0][0]>97) ) return 1;
	else if( (snake[1][0]<1) || (snake[1][0]>28) ) return 1;
	
	return 0;
	
}
