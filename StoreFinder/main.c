#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "storeinfo.h"

#define TRUE 1
#define FALSE 0

typedef struct {
	char url[100];	 
	char name[100];  
	int price;	     
	int type;        
	int type_eat;
	//----------------
	int position;
	int store_to_pos_dist;
	int second_near;
	int store_to_sec_dist;
} Node;

Node store[1000];
int graph[100][100];

//functions
void gotoxy(int x, int y);
void mainPage();

int main()
{
	int nSelect = 0, x = 0, y = 0;
	while (TRUE) {
		gotoxy(x, y);
		printf("#");
		if (kbhit()) {
			nSelect = getch();
			if (nSelect == 224) {
				nSelect = getch();
				switch (nSelect)
				{
				case 72:
					y--;
					break;
				case 80:
					y++;
					break;
				case 75:
					x--;
					break;
				case 77:
					x++;
					break;
				default:
					break;
				}
			}
		}
		system("cls");
	}

	system("pause");
	return 0;
}

void gotoxy(int x, int y)//내가 원하는 위치로 커서 이동
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);// WIN32API 함수입니다
}

void mainPage() {

}
