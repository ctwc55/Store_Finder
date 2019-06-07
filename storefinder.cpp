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

typedef struct { //蝶鷗 掘褻羹
	int head;
	int stack[250];
} STACK;

Node store[250]; //陝 薑薄曖 薑爾蒂 氬朝 掘褻羹 寡翮
//STACK print_route; 
//STACK possible_stores; 
stack<int> print_route; //唳煎 轎溘縑 餌辨腎朝 蝶鷗
stack<int> possible_stores; //陛棟и 陛啪菟擊 盪濰ж朝 蝶鷗
int graph[250][250]; //陝 薑薄 除 剪葬蒂 盪濰ж朝 檜離錳 寡翮
int route[250][250]; // a縑憮 b煎 陞 陽 b縑 紫雜ж晦 霜瞪 薑薄擊 盪濰ж朝 檜離錳 寡翮 (唳煎 轎溘 衛 檜辨)

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
void initGraph(); //薑薄 除 賅萇 剪葬蒂 鼠и渠煎 撲薑м棲棻 + route紫 NIL煎 蟾晦��
void setEdgeDist(); //薑薄 除 剪葬蒂 濠翕戲煎 殮溘м棲棻
void floydWarshallAlgorithm(); //Ы煎檜萄-錶暫 憲堅葬闈擊 餌辨ж罹 陝 薑薄 除 譆欽唳煎蒂 啗骯м棲棻
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

void gotoxy(int x, int y)//頂陛 錳ж朝 嬪纂煎 醴憮 檜翕
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);// WIN32API л熱殮棲棻
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
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛             貲睫翕 嶸儅曖 陛啪 瓊晦 紫辦嘐                   弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛   瓊堅 談擎 陛啪 謙盟蒂 摹鷗п輿撮蹂                         弛\n");
	printf("弛                                                              弛\n");
	printf("弛   *寞щ酈諦 蝶む檜蝶夥煎 褻濛й 熱 氈蝗棲棻                  弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛           > 衝渡                                             弛\n");
	printf("弛             擒措                                             弛\n");
	printf("弛             ら曖薄&葆お                                      弛\n");
	printf("弛             蘋む                                             弛\n");
	printf("弛             謙猿                                             弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

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
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛             貲睫翕 嶸儅曖 陛啪 瓊晦 紫辦嘐                   弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛                                                              弛\n");
	printf("弛                   Щ煎斜極擊 謙猿м棲棻                      弛\n");
	printf("弛                                                              弛\n");
	printf("弛                                                              弛\n");
	printf("弛                                                              弛\n");
	printf("弛                  檜辨п輿敷憮 堅蛾蝗棲棻!                    弛\n");
	printf("弛                                                              弛\n");
	printf("弛                    COMEDU X HANEDU PROJ                      弛\n");
	printf("弛                                                              弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	return;
}

int restaurantPage() {
	int x = 3, y = 8, com, run = TRUE;

	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛             貲睫翕 嶸儅曖 陛啪 瓊晦 紫辦嘐                      弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛   衝渡擊 摹鷗ж樟蝗棲棻                                         弛\n");
	printf("弛   ⑷營 嬪纂蒂 摹鷗п輿撮蹂                                      弛\n");
	printf("弛                                                                 弛\n");
	printf("弛   *寞щ酈諦 蝶む檜蝶夥煎 褻濛й 熱 氈蝗棲棻                     弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛  > �ˇ炾�      措薯婦             螢溯餌剪葬        з掖薑僥    弛\n");
	printf("弛    唳艙婦      熱摹婦             ���倍�1廓轎掘     渠貲剪葬    弛\n");
	printf("弛    唳薯婦      薹僥縣葬漆檜攪     ���倍�4廓轎掘     醞懈紫憮婦  弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

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
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛             貲睫翕 嶸儅曖 陛啪 瓊晦 紫辦嘐                   弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛   擒措擊 摹鷗ж樟蝗棲棻                                      弛\n");
	printf("弛   ⑷營 嬪纂蒂 摹鷗п輿撮蹂                                   弛\n");
	printf("弛                                                              弛\n");
	printf("弛   *寞щ酈諦 蝶む檜蝶夥煎 褻濛й 熱 氈蝗棲棻                  弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛  > �ˇ炾�      措薯婦             螢溯餌剪葬        薹僥     弛\n");
	printf("弛    唳艙婦      醞懈紫憮婦         ���倍�1廓轎掘     渠貲剪葬 弛\n");
	printf("弛    唳薯婦      薹僥縣葬漆檜攪     ���倍�4廓轎掘     模釭鼠望 弛\n");
	printf("弛    熱摹婦      з掖薑僥           渠з煎                     弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

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
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛             貲睫翕 嶸儅曖 陛啪 瓊晦 紫辦嘐                   弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛   ら曖薄&葆お蒂 摹鷗ж樟蝗棲棻                               弛\n");
	printf("弛   ⑷營 嬪纂蒂 摹鷗п輿撮蹂                                   弛\n");
	printf("弛                                                              弛\n");
	printf("弛   *寞щ酈諦 蝶む檜蝶夥煎 褻濛й 熱 氈蝗棲棻                  弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛  > �ˇ炾�      措薯婦             螢溯餌剪葬        薹僥     弛\n");
	printf("弛    唳艙婦      醞懈紫憮婦         ���倍�1廓轎掘     渠貲剪葬 弛\n");
	printf("弛    唳薯婦      薹僥縣葬漆檜攪     ���倍�4廓轎掘     模釭鼠望 弛\n");
	printf("弛    熱摹婦      з掖薑僥           渠з煎                     弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

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
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛             貲睫翕 嶸儅曖 陛啪 瓊晦 紫辦嘐                   弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛   蘋む蒂 摹鷗ж樟蝗棲棻                                      弛\n");
	printf("弛   ⑷營 嬪纂蒂 摹鷗п輿撮蹂                                   弛\n");
	printf("弛                                                              弛\n");
	printf("弛   *寞щ酈諦 蝶む檜蝶夥煎 褻濛й 熱 氈蝗棲棻                  弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛   > �ˇ炾�      措薯婦             螢溯餌剪葬        薹僥    弛\n");
	printf("弛     唳艙婦      醞懈紫憮婦         ���倍�1廓轎掘     渠貲剪葬弛\n");
	printf("弛     唳薯婦      薹僥縣葬漆檜攪     ���倍�4廓轎掘     模釭鼠望弛\n");
	printf("弛     熱摹婦      з掖薑僥           渠з煎                    弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	return x * 100 + y;
}


void initGraph() {
	for (int i = 0; i < 250; i++) {
		for (int j = 0; j < 250; j++) {
			if (i == j) graph[i][j] = 0; //濠晦 濠褐戲煎 陛朝 剪葬朝 0
			else graph[i][j] = INFINITE; //嬴棲賊 橾欽 陞 熱 橈擠 (剪葬 鼠и渠)
			route[i][j] = NIL; // 霜瞪 薑薄擎 辦摹 NIL煎 蟾晦��
		}
	}
	return;
}

void setEdgeDist() { //寡翮縑 綴蘊 籀葬 в蹂
	for (int i = 0; i < 250; i++) {
		if (i < 120) { // 陛啪賊
			graph[i][store[i].position] = store[i].store_to_pos_dist; //陛啪 -> 羅廓簞 陛梱遴 薑薄 剪葬
			graph[store[i].position][i] = store[i].store_to_pos_dist; //羅廓簞 陛梱遴 薑薄 -> 陛啪 剪葬

			graph[i][store[i].second_near] = store[i].store_to_sec_dist; //陛啪 -> 舒廓簞 陛梱遴 薑薄 剪葬
			graph[store[i].second_near][i] = store[i].store_to_sec_dist; //舒廓簞 陛梱遴 薑薄 -> 陛啪 剪葬
		}
	}
	return;
}

void floydWarshallAlgorithm() {
	for (int k = 0; k < 250; k++) {
		for (int i = 0; i < 250; i++) {
			for (int j = 0; j < 250; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) { //i縑憮 j煎 陞 陽 晦襄 爾棻 k蒂 渦 剪藥 陛朝啪 渦 陛梱選 陽
					graph[i][j] = graph[i][k] + graph[k][j]; // 譆欽 剪葬 偵褐
					route[i][j] = route[k][j]; // i縑憮 j 紫雜 霜瞪 薑薄擊 k縑憮 j 紫雜 霜瞪 薑薄戲煎 偵褐
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