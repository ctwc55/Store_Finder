#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <stack>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include "storeinfo.h"

using namespace std;

//define boolean
#define TRUE 1
#define FALSE 0

//define keys
#define ARROWKEY 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77 

#define SPACE 32

//define selection
#define RESTAURANT 7
#define DRUGSTORE 8
#define CVS 9
#define CAFE 10

#define EXIT 11

//define algorithm related const
#define INFINITE 100000000
#define NIL -1

typedef struct { //½ºÅÃ ±¸Á¶Ã¼
	int head;
	int stack[250];
} STACK;

Node store[250]; //°¢ Á¤Á¡ÀÇ Á¤º¸¸¦ ´ã´Â ±¸Á¶Ã¼ ¹è¿­
//STACK print_route; 
//STACK possible_stores; 
stack<int> print_route; //°æ·Î Ãâ·Â¿¡ »ç¿ëµÇ´Â ½ºÅÃ
stack<int> possible_stores; //°¡´ÉÇÑ °¡°ÔµéÀ» ÀúÀåÇÏ´Â ½ºÅÃ
int graph[250][250]; //°¢ Á¤Á¡ °£ °Å¸®¸¦ ÀúÀåÇÏ´Â ÀÌÂ÷¿ø ¹è¿­
int route[250][250]; // a¿¡¼­ b·Î °¥ ¶§ b¿¡ µµÂøÇÏ±â Á÷Àü Á¤Á¡À» ÀúÀåÇÏ´Â ÀÌÂ÷¿ø ¹è¿­ (°æ·Î Ãâ·Â ½Ã ÀÌ¿ë)

// display functions
void gotoxy(int x, int y);
int keyReturn();
int mainPage();
void endPage();
int restaurantPage();
int drugstorePage();
int cvsPage();
int cafePage();

// algorithm functions
void initGraph(); //Á¤Á¡ °£ ¸ðµç °Å¸®¸¦ ¹«ÇÑ´ë·Î ¼³Á¤ÇÕ´Ï´Ù + routeµµ NIL·Î ÃÊ±âÈ­
void setEdgeDist(); //Á¤Á¡ °£ °Å¸®¸¦ ÀÚµ¿À¸·Î ÀÔ·ÂÇÕ´Ï´Ù
void floydWarshallAlgorithm(); //ÇÃ·ÎÀÌµå-¿ö¼È ¾Ë°í¸®ÁòÀ» »ç¿ëÇÏ¿© °¢ Á¤Á¡ °£ ÃÖ´Ü°æ·Î¸¦ °è»êÇÕ´Ï´Ù
void filteringStore(int store_type);

int main()
{
	int run = TRUE, select_mode;

	setStoreInfo(store);
	initGraph();
	setEdgeDist();
	floydWarshallAlgorithm();
	//print_route.head = -1;

	while (run) {
		select_mode = mainPage();
		if (select_mode == RESTAURANT) {
			restaurantPage();
		}
		else if (select_mode == DRUGSTORE) {
			drugstorePage();
		}
		else if (select_mode == CVS) {
			cvsPage();
		}
		else if (select_mode == CAFE) {
			cafePage();
		}
		else if (select_mode == EXIT) {
			run = FALSE;
		}
	}

	endPage();

	system("pause");
	return 0;
}

void gotoxy(int x, int y)//³»°¡ ¿øÇÏ´Â À§Ä¡·Î Ä¿¼­ ÀÌµ¿
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);// WIN32API ÇÔ¼öÀÔ´Ï´Ù
}

int keyReturn() {
	int nSelect;
	int command = 0;
	if (kbhit()) {
		nSelect = getch();
		if (nSelect == ARROWKEY) {
			nSelect = getch();
			switch (nSelect)
			{
			case LEFT:
				command = LEFT;
				break;
			case RIGHT:
				command = RIGHT;
				break;
			case UP:
				command = UP;
				break;
			case DOWN:
				command = DOWN;
				break;
			default:
				break;
			}
		}
		else if (nSelect == SPACE) command = SPACE;
		return command;
	}
}

int mainPage() {
	int x = 12, y = 7, com, run = TRUE;

	system("cls");
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢             ¸í·ûµ¿ À¯»ýÀÇ °¡°Ô Ã£±â µµ¿ì¹Ì                   ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢   Ã£°í ½ÍÀº °¡°Ô Á¾·ù¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä                         ¦¢\n");
	printf("¦¢                                                              ¦¢\n");
	printf("¦¢   *¹æÇâÅ°¿Í ½ºÆäÀÌ½º¹Ù·Î Á¶ÀÛÇÒ ¼ö ÀÖ½À´Ï´Ù                  ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢           > ½Ä´ç                                             ¦¢\n");
	printf("¦¢             ¾à±¹                                             ¦¢\n");
	printf("¦¢             ÆíÀÇÁ¡&¸¶Æ®                                      ¦¢\n");
	printf("¦¢             Ä«Æä                                             ¦¢\n");
	printf("¦¢             Á¾·á                                             ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");

	while (run) {
		com = keyReturn();
		switch (com)
		{
		case UP:
			if (y > 7) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, --y);
				printf(">");
			}
			break;

		case DOWN:
			if (y < 11) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, ++y);
				printf(">");
			}
			break;

		case SPACE:
			run = FALSE;
			break;

		default:
			break;
		}
	}

	return y;
}

void endPage() {
	system("cls");
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢             ¸í·ûµ¿ À¯»ýÀÇ °¡°Ô Ã£±â µµ¿ì¹Ì                   ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢                                                              ¦¢\n");
	printf("¦¢                   ÇÁ·Î±×·¥À» Á¾·áÇÕ´Ï´Ù                      ¦¢\n");
	printf("¦¢                                                              ¦¢\n");
	printf("¦¢                                                              ¦¢\n");
	printf("¦¢                                                              ¦¢\n");
	printf("¦¢                  ÀÌ¿ëÇØÁÖ¼Å¼­ °í¸¿½À´Ï´Ù!                    ¦¢\n");
	printf("¦¢                                                              ¦¢\n");
	printf("¦¢                    COMEDU X HANEDU PROJ                      ¦¢\n");
	printf("¦¢                                                              ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	return;
}

int restaurantPage() {
	int x = 3, y = 8, com, run = TRUE;

	system("cls");
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢             ¸í·ûµ¿ À¯»ýÀÇ °¡°Ô Ã£±â µµ¿ì¹Ì                      ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢   ½Ä´çÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù                                         ¦¢\n");
	printf("¦¢   ÇöÀç À§Ä¡¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä                                      ¦¢\n");
	printf("¦¢                                                                 ¦¢\n");
	printf("¦¢   *¹æÇâÅ°¿Í ½ºÆäÀÌ½º¹Ù·Î Á¶ÀÛÇÒ ¼ö ÀÖ½À´Ï´Ù                     ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢  > È£¾Ï°ü      ±¹Á¦°ü             ¿Ã·¹»ç°Å¸®        ÇÐ±³Á¤¹®    ¦¢\n");
	printf("¦¢    °æ¿µ°ü      ¼ö¼±°ü             ÇýÈ­¿ª1¹øÃâ±¸     ´ë¸í°Å¸®    ¦¢\n");
	printf("¦¢    °æÁ¦°ü      ÂÊ¹®¿¤¸®º£ÀÌÅÍ     ÇýÈ­¿ª4¹øÃâ±¸     Áß¾Óµµ¼­°ü  ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");

	while (run) {
		com = keyReturn();
		switch (com)
		{
		case UP:
			if (y > 8) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, --y);
				printf(">");
			}
			break;

		case DOWN:
			if (y < 11) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, ++y);
				printf(">");
			}
			break;

		case RIGHT:
			if (x < 53) {
				if (x == 3) {
					gotoxy(x, y);
					printf(" ");
					x += 12;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 15) {
					gotoxy(x, y);
					printf(" ");
					x += 19;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 34) {
					gotoxy(x, y);
					printf(" ");
					x += 18;
					gotoxy(x, y);
					printf(">");
				}
			}
			break;

		case LEFT:
			if (x > 3) {
				if (x == 15) {
					gotoxy(x, y);
					printf(" ");
					x -= 12;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 34) {
					gotoxy(x, y);
					printf(" ");
					x -= 19;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 52) {
					gotoxy(x, y);
					printf(" ");
					x -= 18;
					gotoxy(x, y);
					printf(">");
				}

			}
			break;

		case SPACE:
			run = FALSE;
			break;

		default:
			break;
		}
	}



	return x * 100 + y;
}

int drugstorePage() {
	int x = 3, y = 8, com, run = TRUE;

	system("cls");
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢             ¸í·ûµ¿ À¯»ýÀÇ °¡°Ô Ã£±â µµ¿ì¹Ì                   ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢   ¾à±¹À» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù                                      ¦¢\n");
	printf("¦¢   ÇöÀç À§Ä¡¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä                                   ¦¢\n");
	printf("¦¢                                                              ¦¢\n");
	printf("¦¢   *¹æÇâÅ°¿Í ½ºÆäÀÌ½º¹Ù·Î Á¶ÀÛÇÒ ¼ö ÀÖ½À´Ï´Ù                  ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢  > È£¾Ï°ü      ±¹Á¦°ü             ¿Ã·¹»ç°Å¸®        ÂÊ¹®     ¦¢\n");
	printf("¦¢    °æ¿µ°ü      Áß¾Óµµ¼­°ü         ÇýÈ­¿ª1¹øÃâ±¸     ´ë¸í°Å¸® ¦¢\n");
	printf("¦¢    °æÁ¦°ü      ÂÊ¹®¿¤¸®º£ÀÌÅÍ     ÇýÈ­¿ª4¹øÃâ±¸     ¼Ò³ª¹«±æ ¦¢\n");
	printf("¦¢    ¼ö¼±°ü      ÇÐ±³Á¤¹®           ´ëÇÐ·Î                     ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");

	while (run) {
		com = keyReturn();
		switch (com)
		{
		case UP:
			if (y > 8) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, --y);
				printf(">");
			}
			break;

		case DOWN:
			if (y < 11) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, ++y);
				printf(">");
			}
			break;

		case RIGHT:
			if (x < 53) {
				if (x == 3) {
					gotoxy(x, y);
					printf(" ");
					x += 12;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 15) {
					gotoxy(x, y);
					printf(" ");
					x += 19;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 34) {
					gotoxy(x, y);
					printf(" ");
					x += 18;
					gotoxy(x, y);
					printf(">");
				}
			}
			break;

		case LEFT:
			if (x > 3) {
				if (x == 15) {
					gotoxy(x, y);
					printf(" ");
					x -= 12;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 34) {
					gotoxy(x, y);
					printf(" ");
					x -= 19;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 52) {
					gotoxy(x, y);
					printf(" ");
					x -= 18;
					gotoxy(x, y);
					printf(">");
				}

			}
			break;

		case SPACE:
			run = FALSE;
			break;

		default:
			break;
		}
	}

	return x * 100 + y;
}

int cvsPage() {
	int x = 3, y = 8, com, run = TRUE;

	system("cls");
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢             ¸í·ûµ¿ À¯»ýÀÇ °¡°Ô Ã£±â µµ¿ì¹Ì                   ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢   ÆíÀÇÁ¡&¸¶Æ®¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù                               ¦¢\n");
	printf("¦¢   ÇöÀç À§Ä¡¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä                                   ¦¢\n");
	printf("¦¢                                                              ¦¢\n");
	printf("¦¢   *¹æÇâÅ°¿Í ½ºÆäÀÌ½º¹Ù·Î Á¶ÀÛÇÒ ¼ö ÀÖ½À´Ï´Ù                  ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢  > È£¾Ï°ü      ±¹Á¦°ü             ¿Ã·¹»ç°Å¸®        ÂÊ¹®     ¦¢\n");
	printf("¦¢    °æ¿µ°ü      Áß¾Óµµ¼­°ü         ÇýÈ­¿ª1¹øÃâ±¸     ´ë¸í°Å¸® ¦¢\n");
	printf("¦¢    °æÁ¦°ü      ÂÊ¹®¿¤¸®º£ÀÌÅÍ     ÇýÈ­¿ª4¹øÃâ±¸     ¼Ò³ª¹«±æ ¦¢\n");
	printf("¦¢    ¼ö¼±°ü      ÇÐ±³Á¤¹®           ´ëÇÐ·Î                     ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");

	while (run) {
		com = keyReturn();
		switch (com)
		{
		case UP:
			if (y > 8) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, --y);
				printf(">");
			}
			break;

		case DOWN:
			if (y < 11) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, ++y);
				printf(">");
			}
			break;

		case RIGHT:
			if (x < 53) {
				if (x == 3) {
					gotoxy(x, y);
					printf(" ");
					x += 12;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 15) {
					gotoxy(x, y);
					printf(" ");
					x += 19;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 34) {
					gotoxy(x, y);
					printf(" ");
					x += 18;
					gotoxy(x, y);
					printf(">");
				}
			}
			break;

		case LEFT:
			if (x > 3) {
				if (x == 15) {
					gotoxy(x, y);
					printf(" ");
					x -= 12;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 34) {
					gotoxy(x, y);
					printf(" ");
					x -= 19;
					gotoxy(x, y);
					printf(">");
				}
				else if (x == 52) {
					gotoxy(x, y);
					printf(" ");
					x -= 18;
					gotoxy(x, y);
					printf(">");
				}

			}
			break;

		case SPACE:
			run = FALSE;
			break;

		default:
			break;
		}
	}

	return x * 100 + y;
}

int cafePage() {
	int x = 0, y = 0;

	system("cls");
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢             ¸í·ûµ¿ À¯»ýÀÇ °¡°Ô Ã£±â µµ¿ì¹Ì                   ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢   Ä«Æä¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù                                      ¦¢\n");
	printf("¦¢   ÇöÀç À§Ä¡¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä                                   ¦¢\n");
	printf("¦¢                                                              ¦¢\n");
	printf("¦¢   *¹æÇâÅ°¿Í ½ºÆäÀÌ½º¹Ù·Î Á¶ÀÛÇÒ ¼ö ÀÖ½À´Ï´Ù                  ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢   > È£¾Ï°ü      ±¹Á¦°ü             ¿Ã·¹»ç°Å¸®        ÂÊ¹®    ¦¢\n");
	printf("¦¢     °æ¿µ°ü      Áß¾Óµµ¼­°ü         ÇýÈ­¿ª1¹øÃâ±¸     ´ë¸í°Å¸®¦¢\n");
	printf("¦¢     °æÁ¦°ü      ÂÊ¹®¿¤¸®º£ÀÌÅÍ     ÇýÈ­¿ª4¹øÃâ±¸     ¼Ò³ª¹«±æ¦¢\n");
	printf("¦¢     ¼ö¼±°ü      ÇÐ±³Á¤¹®           ´ëÇÐ·Î                    ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");

	return x * 100 + y;
}


void initGraph() {
	for (int i = 0; i < 250; i++) {
		for (int j = 0; j < 250; j++) {
			if (i == j) graph[i][j] = 0; //ÀÚ±â ÀÚ½ÅÀ¸·Î °¡´Â °Å¸®´Â 0
			else graph[i][j] = INFINITE; //¾Æ´Ï¸é ÀÏ´Ü °¥ ¼ö ¾øÀ½ (°Å¸® ¹«ÇÑ´ë)
			route[i][j] = NIL; // Á÷Àü Á¤Á¡Àº ¿ì¼± NIL·Î ÃÊ±âÈ­
		}
	}
	return;
}

void setEdgeDist() { //¹è¿­¿¡ ºóÄ­ Ã³¸® ÇÊ¿ä
	for (int i = 0; i < 250; i++) {
		if (i < 120) { // °¡°Ô¸é
			graph[i][store[i].position] = store[i].store_to_pos_dist; //°¡°Ô -> Ã¹¹øÂ° °¡±î¿î Á¤Á¡ °Å¸®
			graph[store[i].position][i] = store[i].store_to_pos_dist; //Ã¹¹øÂ° °¡±î¿î Á¤Á¡ -> °¡°Ô °Å¸®

			graph[i][store[i].second_near] = store[i].store_to_sec_dist; //°¡°Ô -> µÎ¹øÂ° °¡±î¿î Á¤Á¡ °Å¸®
			graph[store[i].second_near][i] = store[i].store_to_sec_dist; //µÎ¹øÂ° °¡±î¿î Á¤Á¡ -> °¡°Ô °Å¸®
		}
	}
	return;
}

void floydWarshallAlgorithm() {
	for (int k = 0; k < 250; k++) {
		for (int i = 0; i < 250; i++) {
			for (int j = 0; j < 250; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) { //i¿¡¼­ j·Î °¥ ¶§ ±âÁ¸ º¸´Ù k¸¦ ´õ °ÅÃÄ °¡´Â°Ô ´õ °¡±î¿ï ¶§
					graph[i][j] = graph[i][k] + graph[k][j]; // ÃÖ´Ü °Å¸® °»½Å
					route[i][j] = route[k][j]; // i¿¡¼­ j µµÂø Á÷Àü Á¤Á¡À» k¿¡¼­ j µµÂø Á÷Àü Á¤Á¡À¸·Î °»½Å
				}
			}
		}
	}
	return;
}

void filteringStore(int store_type) {
	if (store_type == RESTAURANT) {

	}
	else if (store_type == DRUGSTORE) {

	}
	else if (store_type == CVS) {

	}
	else if (store_type == CAFE) {

	}
	return;
}

/*
void push(int data) {
	print_route.stack[++(print_route.head)] = data;
	return;
}

void pop(int data) {
	print_route.stack[print_route.head] = 0;
	(print_route.head)--;
	return;
}

int top(int data) {
	return print_route.stack[print_route.head];
}

int isEmpty() {
	if (print_route.head == -1) return TRUE;
	return FALSE;
}*/