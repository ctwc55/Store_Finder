#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <vector>
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
#define STORENUM 131

//global variables
Node store[STORENUM]; //각 정점의 정보를 담는 구조체 배열
vector<int> print_route; //경로 출력에 사용되는 스택
vector<Node> possible_stores; //가능한 가게들을 저장하는 스택
int graph[STORENUM][STORENUM]; //각 정점 간 거리를 저장하는 이차원 배열
int route[STORENUM][STORENUM]; // a에서 b로 갈 때 b에 도착하기 직전 정점을 저장하는 이차원 배열 (경로 출력 시 이용)
int user_position;

//display functions
void gotoxy(int x, int y);
int keyReturn();
int mainPage();
void endPage();
int restaurantPage();
int restaurant_restaurantPosition();
int restaurant_userPosition();
int restaurant_restaurantType();
int restaurant_priceRange();
int restaurant_sortType();
int drugstorePage();
int cvsPage();
int cafePage();
void printPossibleListPage(int store_type, int print_type);
void printRoute(int store_position);

//algorithm functions
void initGraph(); //정점 간 모든 거리를 무한대로 설정합니다 + route도 NIL로 초기화
void setEdgeDist(); //정점 간 거리를 자동으로 입력합니다
void setAddEdgeDist(); //자동 입력이 안되는 거리 중 필요한 거리를 코드 내에서 수동으로 입력합니다
void floydWarshallAlgorithm(); //플로이드-워셜 알고리즘을 사용하여 각 정점 간 최단경로를 계산합니다
void filteringStore(int store_type, int restaurant_type, int area, int price); //각 가게 종류와 사용자 입력 값에 따라 가게들을 선별합니다
void sortingStore(int store_type, int sort_type); //식당은 사용자 입력대로, 나머지는 현재위치기준 거리순으로 가게들을 정렬합니다 (0 : 거리 가까운 순  1 : 가격 오름차순  2 : 가격 내림차순)
bool cmpDistance(Node a, Node b); //가까운 거리 순 정렬을 위한 sort함수 인자
bool cmpPriceAscending(Node a, Node b); //가격 오름차순 정렬을 위한 sort함수 인자 
bool cmpPriceDescending(Node a, Node b); //가격 내림차순 정렬을 위한 sort함수 인자

int main()
{
	int run = TRUE, select_mode;

	setStoreInfo(store);
	initGraph();
	setEdgeDist();
	setAddEdgeDist();
	floydWarshallAlgorithm();
	//system("explorer http://naver.com");

	while (run) {
		select_mode = mainPage();
		if (select_mode == RESTAURANT) {
			run = restaurantPage();
		}
		else if (select_mode == DRUGSTORE) {
			run = drugstorePage();
		}
		else if (select_mode == CVS) {
			run = cvsPage();
		}
		else if (select_mode == CAFE) {
			run = cafePage();
		}
		else if (select_mode == EXIT) {
			run = FALSE;
		}

		while (!possible_stores.empty()) possible_stores.pop_back();
	}

	endPage();

	system("pause");
	return 0;
}

void gotoxy(int x, int y)//내가 원하는 위치로 커서 이동
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);// WIN32API 함수입니다
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
	printf("┌──────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                   │\n");
	printf("├──────────────────────────────────────────────────────────────┤\n");
	printf("│   찾고 싶은 가게 종류를 선택해주세요                         │\n");
	printf("│                                                              │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                  │\n");
	printf("├──────────────────────────────────────────────────────────────┤\n");
	printf("│           > 식당                                             │\n");
	printf("│             약국                                             │\n");
	printf("│             편의점&마트                                      │\n");
	printf("│             카페                                             │\n");
	printf("│             종료                                             │\n");
	printf("└──────────────────────────────────────────────────────────────┘\n");

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
	printf("┌──────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                   │\n");
	printf("├──────────────────────────────────────────────────────────────┤\n");
	printf("│                                                              │\n");
	printf("│                   프로그램을 종료합니다                      │\n");
	printf("│                                                              │\n");
	printf("│                                                              │\n");
	printf("│                                                              │\n");
	printf("│                  이용해주셔서 고맙습니다!                    │\n");
	printf("│                                                              │\n");
	printf("│                    COMEDU X HANEDU PROJ                      │\n");
	printf("│                                                              │\n");
	printf("└──────────────────────────────────────────────────────────────┘\n");
	return;
}

int restaurantPage() {
	int x = 3, y = 8, com, run = TRUE;
	int restaurant_position, restaurant_type, price_range, restaurant_sort_type, print_type;

	user_position = restaurant_userPosition(); //사용자 위치
	if (user_position == 99) return TRUE;
	restaurant_position = restaurant_restaurantPosition(); //식당 위치
	if (restaurant_position == 99) return TRUE;
	restaurant_type = restaurant_restaurantType(); //음식 종류
	if (restaurant_type == 99) return TRUE;
	price_range = restaurant_priceRange(); //음식 가격대
	if (price_range == 99) return TRUE;

	filteringStore(RESTAURANT, restaurant_type, restaurant_position, price_range);
	if (possible_stores.empty()) {
		system("cls");
		printf("┌────────────────────────────────────────────────────────────────┐\n");
		printf("│             명륜동 유생의 가게 찾기 도우미                     │\n");
		printf("├────────────────────────────────────────────────────────────────┤\n");
		printf("│   죄송합니다 조건에 맞는 식당이 없습니다!                      │\n");
		printf("│                                                                │\n");
		printf("│   *방향키와 스페이스바로 조작할 수 있습니다                    │\n");
		printf("├────────────────────────────────────────────────────────────────┤\n");
		printf("│                                                                │\n");
		printf("│   > 처음으로                                                   │\n");
		printf("│                                                                │\n");
		printf("└────────────────────────────────────────────────────────────────┘\n");

		while (run) {
			com = keyReturn();
			switch (com)
			{
			case SPACE:
				return TRUE;
				break;

			default:
				break;
			}
		}
	}

	restaurant_sort_type = restaurant_sortType(); //정렬 기준
	sortingStore(RESTAURANT, restaurant_sort_type);

	// TOP 5 or 전체 출력 선택
	system("cls");
	printf("┌────────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                     │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│   탐색이 완료되었습니다! 어떻게 보여드릴까요?                  │\n");
	printf("│                                                                │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                    │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│                                                                │\n");
	printf("│  > TOP 5                                                       │\n");
	printf("│    전체                                                        │\n");
	printf("│                                                                │\n");
	printf("└────────────────────────────────────────────────────────────────┘\n");

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
			if (y < 9) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, ++y);
				printf(">");
			}
			break;

		case SPACE:
			print_type = y;
			run = FALSE;
			break;

		default:
			break;
		}
	}

	//출력 및 url 연결
	if (print_type == 8) printPossibleListPage(RESTAURANT, 0); //TOP 5
	else if (print_type == 9) printPossibleListPage(RESTAURANT, 1); //전체

	system("pause");
	return TRUE;
}

int restaurant_userPosition() { //사용자 현재위치 선택
	int x = 3, y = 8, com, run = TRUE;

	system("cls");
	printf("┌────────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                     │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│   식당을 선택하셨습니다                                        │\n");
	printf("│   현재 위치를 선택해주세요                                     │\n");
	printf("│                                                                │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                    │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│  > 호암관      국제관             올레사거리        학교정문   │\n");
	printf("│    경영관      수선관             혜화역1번출구     중앙도서관 │\n");
	printf("│    경제관      쪽문엘리베이터     혜화역4번출구     처음으로   │\n");
	printf("└────────────────────────────────────────────────────────────────┘\n");

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
			if (y < 10) {
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
			if (y == 8) {
				if (x == 3) return 121;//호암관
				else if (x == 15) return 124;//국제관
				else if (x == 34) return 128;//올레사거리
				else if (x == 52) return 127;//학교정문
			}
			else if (y == 9) {
				if (x == 3) return 122;//경영관
				else if (x == 15) return 119;//수선관
				else if (x == 34) return 130;//혜화역1번출구
				else if (x == 52) return 123;//중앙도서관
			}
			else if (y == 10) {
				if (x == 3) return 120;//경제관 
				else if (x == 15) return 126;//쪽문
				else if (x == 34) return 129;//혜화역4번출구
				else if (x == 52) return 99;//처응으로
			}
			run = FALSE;
			break;

		default:
			break;
		}
	}
}

int restaurant_restaurantPosition() {
	int x = 3, y = 7, com, run = TRUE;

	system("cls");
	printf("┌────────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                     │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│   원하는 식당 위치를 선택해주세요                              │\n");
	printf("│                                                                │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                    │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│  > 교내           쪽문           대명거리       정문           │\n");
	printf("│    소나무길       대학로         다좋아!        처음으로       │\n");
	printf("└────────────────────────────────────────────────────────────────┘\n");
	//6개이긴 한데 뒤로가기 같은거나 다른거 있을 수도 있어서 3*2 말고 4*2로 만들었어
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
			if (y < 8) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, ++y);
				printf(">");
			}
			break;

		case RIGHT:
			if (x < 48) {
				gotoxy(x, y);
				printf(" ");
				x += 15;
				gotoxy(x, y);
				printf(">");
			}
			break;

		case LEFT:
			if (x > 3) {
				gotoxy(x, y);
				printf(" ");
				x -= 15;
				gotoxy(x, y);
				printf(">");
			}
			break;

		case SPACE:
			if (y == 7) {
				if (x == 3) return 0;//교내
				else if (x == 18) return 1;//쪽문
				else if (x == 33) return 2;//대명거리
				else if (x == 48) return 3;//정문
			}
			else if (y == 8) {
				if (x == 3) return 4;//소나무길
				else if (x == 18) return 5;//대학로
				else if (x == 33) return 6;//다좋아!
				else if (x == 48) return 99;//처음으로
			}
			run = FALSE;
			break;

		default:
			break;
		}
	}
}

int restaurant_restaurantType() {//음식종류 선택
	int x = 3, y = 7, com, run = TRUE;

	system("cls");
	printf("┌────────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                     │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│   원하는 음식 종류를 선택해주세요                              │\n");
	printf("│                                                                │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                    │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│  > 한식         일식         중식         양식                 │\n");
	printf("│    고기         닭           기타         다좋아!              │\n");
	printf("│    처음으로                                                    │\n");
	printf("└────────────────────────────────────────────────────────────────┘\n");

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
			if (y < 8 || (x == 3 && y < 9)) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, ++y);
				printf(">");
			}
			break;

		case RIGHT:
			if (x < 42 && y != 9) {
				gotoxy(x, y);
				printf(" ");
				x += 13;
				gotoxy(x, y);
				printf(">");
			}
			break;

		case LEFT:
			if (x > 3) {
				gotoxy(x, y);
				printf(" ");
				x -= 13;
				gotoxy(x, y);
				printf(">");
			}
			break;

		case SPACE:
			if (y == 7) {
				if (x == 3) return 1; //한식
				else if (x == 16) return 2; //일식
				else if (x == 29) return 3; //중식
				else if (x == 42) return 4; //양식
			}
			else if (y == 8) {
				if (x == 3) return 5; //고기
				else if (x == 16) return 6; //닭
				else if (x == 29) return 7; //기타
				else if (x == 42) return 8; //다좋아!
			}
			else return 99; //처음으로
			run = FALSE;
			break;

		default:
			break;
		}
	}
}

int restaurant_priceRange() {//가격대 선택
	int x = 12, y = 7, com, run = TRUE;

	system("cls");
	printf("┌──────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                   │\n");
	printf("├──────────────────────────────────────────────────────────────┤\n");
	printf("│   원하는 음식 가격대를 선택해주세요                          │\n");
	printf("│                                                              │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                  │\n");
	printf("├──────────────────────────────────────────────────────────────┤\n");
	printf("│           > 하 (5000원 이하)                                 │\n");
	printf("│             중 (5000원 초과 10000원 미만)                    │\n");
	printf("│             중상 (10000원 이상 15000원 미만)                 │\n");
	printf("│             상 (15000원 이상)                                │\n");
	printf("│             다좋아!                                          │\n");
	printf("│             처음으로                                         │\n");
	printf("└──────────────────────────────────────────────────────────────┘\n");

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
			if (y < 12) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, ++y);
				printf(">");
			}
			break;

		case SPACE:
			if (y == 7) return 0; //하
			else if (y == 8) return 1; //중
			else if (y == 9) return 2; //중상
			else if (y == 10) return 3; //상
			else if (y == 11) return 4; //다좋아!
			else if (y == 12) return 99; //처음으로
			run = FALSE;
			break;

		default:
			break;
		}
	}

}

int restaurant_sortType() {
	int x = 12, y = 7, com, run = TRUE;

	system("cls");
	printf("┌──────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                   │\n");
	printf("├──────────────────────────────────────────────────────────────┤\n");
	printf("│   원하는 정렬 기준을 선택해주세요                            │\n");
	printf("│                                                              │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                  │\n");
	printf("├──────────────────────────────────────────────────────────────┤\n");
	printf("│           > 현재 위치 기준 가까운 거리 순                    │\n");
	printf("│             가격 오름차순                                    │\n");
	printf("│             가격 내림차순                                    │\n");
	printf("│             처음으로                                         │\n");
	printf("└──────────────────────────────────────────────────────────────┘\n");

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
			if (y == 7) return 0; //현재 위치 기준 가까운 거리 순
			else if (y == 8) return 1; //가격 오름차순
			else if (y == 9) return 2; //가격 내림차순
			else if (y == 10) return 99; //처음으로
			run = FALSE;
			break;

		default:
			break;
		}
	}
}

int drugstorePage() { //사용자 현재위치 선택
	int x = 3, y = 8, com, run = TRUE;

	system("cls");
	printf("┌────────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                     │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│   약국을 선택하셨습니다                                        │\n");
	printf("│   현재 위치를 선택해주세요                                     │\n");
	printf("│                                                                │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                    │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│  > 호암관      국제관             올레사거리        학교정문   │\n");
	printf("│    경영관      수선관             혜화역1번출구     중앙도서관 │\n");
	printf("│    경제관      쪽문엘리베이터     혜화역4번출구     처음으로   │\n");
	printf("└────────────────────────────────────────────────────────────────┘\n");

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
			if (y < 10) {
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
			if (y == 8) {
				if (x == 3) user_position = 121;//호암관
				else if (x == 15) user_position = 124;//국제관
				else if (x == 34) user_position = 128;//올레사거리
				else if (x == 52) user_position = 127;//학교정문
			}
			else if (y == 9) {
				if (x == 3) user_position = 122;//경영관
				else if (x == 15) user_position = 119;//수선관
				else if (x == 34) user_position = 130;//혜화역1번출구
				else if (x == 52) user_position = 123;//중앙도서관
			}
			else if (y == 10) {
				if (x == 3) user_position = 120;//경제관 
				else if (x == 15) user_position = 126;//쪽문
				else if (x == 34) user_position = 129;//혜화역4번출구
				else if (x == 52) return TRUE;//처음으로
			}
			run = FALSE;
			break;

		default:
			break;
		}
	}

	filteringStore(DRUGSTORE, 0, 0, 0);
	sortingStore(DRUGSTORE, 0);
	printPossibleListPage(DRUGSTORE, 1);

	system("pause");
	return TRUE;
}

int cvsPage() { //사용자 현재위치 선택
	int x = 3, y = 8, com, run = TRUE;

	system("cls");
	printf("┌────────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                     │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│   편의점&마트를 선택하셨습니다                                 │\n");
	printf("│   현재 위치를 선택해주세요                                     │\n");
	printf("│                                                                │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                    │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│  > 호암관      국제관             올레사거리        학교정문   │\n");
	printf("│    경영관      수선관             혜화역1번출구     중앙도서관 │\n");
	printf("│    경제관      쪽문엘리베이터     혜화역4번출구     처음으로   │\n");
	printf("└────────────────────────────────────────────────────────────────┘\n");

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
			if (y < 10) {
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
			if (y == 8) {
				if (x == 3) user_position = 121;//호암관
				else if (x == 15) user_position = 124;//국제관
				else if (x == 34) user_position = 128;//올레사거리
				else if (x == 52) user_position = 127;//학교정문
			}
			else if (y == 9) {
				if (x == 3) user_position = 122;//경영관
				else if (x == 15) user_position = 119;//수선관
				else if (x == 34) user_position = 130;//혜화역1번출구
				else if (x == 52) user_position = 123;//중앙도서관
			}
			else if (y == 10) {
				if (x == 3) user_position = 120;//경제관 
				else if (x == 15) user_position = 126;//쪽문
				else if (x == 34) user_position = 129;//혜화역4번출구
				else if (x == 52) return TRUE;//처음으로
			}
			run = FALSE;
			break;

		default:
			break;
		}
	}

	filteringStore(CVS, 0, 0, 0);
	sortingStore(CVS, 0);
	printPossibleListPage(CVS, 1);

	system("pause");
	return TRUE;
}

int cafePage() { //사용자 현재위치 선택
	int x = 3, y = 8, com, run = TRUE;

	system("cls");
	printf("┌────────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                     │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│   카페를 선택하셨습니다                                        │\n");
	printf("│   현재 위치를 선택해주세요                                     │\n");
	printf("│                                                                │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                    │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│  > 호암관      국제관             올레사거리        학교정문   │\n");
	printf("│    경영관      수선관             혜화역1번출구     중앙도서관 │\n");
	printf("│    경제관      쪽문엘리베이터     혜화역4번출구     처음으로   │\n");
	printf("└────────────────────────────────────────────────────────────────┘\n");

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
			if (y < 10) {
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
			if (y == 8) {
				if (x == 3) user_position = 121;//호암관
				else if (x == 15) user_position = 124;//국제관
				else if (x == 34) user_position = 128;//올레사거리
				else if (x == 52) user_position = 127;//학교정문
			}
			else if (y == 9) {
				if (x == 3) user_position = 122;//경영관
				else if (x == 15) user_position = 119;//수선관
				else if (x == 34) user_position = 130;//혜화역1번출구
				else if (x == 52) user_position = 123;//중앙도서관
			}
			else if (y == 10) {
				if (x == 3) user_position = 120;//경제관 
				else if (x == 15) user_position = 126;//쪽문
				else if (x == 34) user_position = 129;//혜화역4번출구
				else if (x == 52) return TRUE;//처음으로
			}
			run = FALSE;
			break;

		default:
			break;
		}
	}

	filteringStore(CAFE, 0, 0, 0);
	sortingStore(CAFE, 0);
	printPossibleListPage(CAFE, 1);

	system("pause");
	return TRUE;
}

void printPossibleListPage(int store_type, int print_type) {
	system("cls");
	printf("┌────────────────────────────────────────────────────────────────┐\n");
	printf("│             명륜동 유생의 가게 찾기 도우미                     │\n");
	printf("├────────────────────────────────────────────────────────────────┤\n");
	printf("│   가능한 가게들의 목록입니다!                                  │\n");
	printf("│   가게를 하나 선택해주시면 메뉴 확인이 가능한 사이트가 있는지  │\n");
	printf("│   알아보겠습니다!                                              │\n");
	printf("│                                                                │\n");
	printf("│   *방향키와 스페이스바로 조작할 수 있습니다                    │\n");
	printf("└────────────────────────────────────────────────────────────────┘\n");

	if (print_type == 0) {
		for (int i = 0; i < 5 && i < possible_stores.size(); i++) {
			printf("\n");
			printf("TOP %d. %s\n", i + 1, possible_stores[i].name);
			printf("       거리 : 약 %dm(약 %d분)", graph[user_position][possible_stores[i].key], graph[user_position][possible_stores[i].key] / 70); //1분에 약 70m를 걷는다고 가정
			if (store_type == RESTAURANT) printf("   가격 : 약 %d원\n", possible_stores[i].price);
			else printf("\n");
			printRoute(possible_stores[i].key);
		}

	}
	else if (print_type == 1) {
		for (int i = 0; i < possible_stores.size(); i++) {
			printf("\n");
			printf("%d. %s\n", i + 1, possible_stores[i].name);
			printf("   거리 : 약 %dm(약 %d분)", graph[user_position][possible_stores[i].key], graph[user_position][possible_stores[i].key] / 70); //1분에 약 70m를 걷는다고 가정
			if (store_type == RESTAURANT) printf("   가격 : 약 %d원\n", possible_stores[i].price);
			else printf("\n");
			printRoute(possible_stores[i].key);
		}
	}
	return;
}

void printRoute(int store_position) {
	int route_tmp = route[user_position][store_position];
	printf("경로 : %s -> ", store[user_position].name);
	
	while (route_tmp != user_position) {
		print_route.push_back(route_tmp);
		route_tmp = route[user_position][route_tmp];
	}
	
	while (!print_route.empty()) {
		printf("%s -> ", store[print_route[print_route.size()-1]].name);
		print_route.pop_back();
	}
	printf("%s\n", store[store_position].name);
	return;
}


void initGraph() {
	for (int i = 0; i < STORENUM; i++) {
		for (int j = 0; j < STORENUM; j++) {
			if (i == j) graph[i][j] = 0; //자기 자신으로 가는 거리는 0
			else graph[i][j] = INFINITE; //아니면 일단 갈 수 없음 (거리 무한대)
			route[i][j] = NIL; // 직전 정점은 우선 NIL로 초기화
		}
	}
	return;
}

void setEdgeDist() { //배열에 빈칸 처리 필요
	for (int i = 0; i < STORENUM; i++) {
		store[i].key = i; // 가게 키값 초기화
		graph[i][store[i].position] = store[i].store_to_pos_dist; //가게 -> 첫번째 가까운 정점 거리
		graph[store[i].position][i] = store[i].store_to_pos_dist; //첫번째 가까운 정점 -> 가게 거리
		route[i][store[i].position] = i;
		route[store[i].position][i] = store[i].position;

		graph[i][store[i].second_near] = store[i].store_to_sec_dist; //가게 -> 두번째 가까운 정점 거리
		graph[store[i].second_near][i] = store[i].store_to_sec_dist; //두번째 가까운 정점 -> 가게 거리
		route[i][store[i].second_near] = i;
		route[store[i].second_near][i] = store[i].second_near;
	}
	return;
}

void setAddEdgeDist() {
	graph[121][122] = 60; //호암관 -> 경영관
	graph[122][121] = 60; //경영관 -> 호암관
	route[121][122] = 121;
	route[122][121] = 122;

	graph[123][125] = 140; //중앙도서관 -> 600주년기념관
	graph[125][123] = 140; //600주년기념관 -> 중앙도서관
	route[123][125] = 123;
	route[125][123] = 125;

	graph[124][127] = 350; //국제관 -> 정문
	graph[127][124] = 350; //정문 -> 국제관
	route[124][127] = 124;
	route[127][124] = 127;

	graph[125][127] = 450; //600주년기념관 -> 정문
	graph[127][125] = 450; //정문 -> 600주년기념관
	route[125][127] = 125;
	route[127][125] = 127;

	graph[123][127] = 580; //중앙도서관 -> 정문
	graph[127][123] = 580; //정문 -> 중앙도서관
	route[123][127] = 123;
	route[127][123] = 127;

	graph[122][127] = 630; //경영관 -> 정문
	graph[127][122] = 630; //정문 -> 경영관
	route[122][127] = 122;
	route[127][122] = 127;

	graph[128][129] = 240; //올레사거리 -> 혜화역4번출구
	graph[129][128] = 240; //혜화역4번출구 -> 올레사거리
	route[128][129] = 128;
	route[129][128] = 129;
}

void floydWarshallAlgorithm() {
	for (int k = 0; k < STORENUM; k++) {
		for (int i = 0; i < STORENUM; i++) {
			for (int j = 0; j < STORENUM; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) { //i에서 j로 갈 때 기존 보다 k를 더 거쳐 가는게 더 가까울 때
					graph[i][j] = graph[i][k] + graph[k][j]; // 최단 거리 갱신
					route[i][j] = route[k][j]; // i에서 j 도착 직전 정점을 k에서 j 도착 직전 정점으로 갱신
				}
			}
		}
	}
	return;
}

void filteringStore(int store_type, int restaurant_type, int area, int price) {
	//음식 종류 : 한식 = 1, 일식 = 2, 중식 = 3, 양식 = 4, 고기 = 5, 닭 = 6, 기타 = 7 (다좋아! = 8)
	//가게 위치 : 교내 = 0, 쪽문 = 1, 대명거리 = 2, 정문 = 3, 소나무길 = 4, 대학로 = 5 (다좋아! = 6)
	
	//정점
	//119 수선관  120 경제관  121 호암관  122 경영관  123 중앙도서관  124 국제관
	//125 600주년기념관  126 쪽문엘리베이터  127 학교정문  128 올레사거리  129 혜화역4번출구  130 혜화역1번출구

	//Position
	//교내store(0~6) 소나무길store(7~39) 대명거리store(40~54, 108~118)
	//쪽문store(55 - 72)  정문store(73 - 88, 103 - 107)  대학로store(89 - 102)

	for (int i = 0; i < STORENUM; i++) {
		if (store_type == RESTAURANT) {
			if (store[i].type + 7 == RESTAURANT && (store[i].type_eat == restaurant_type || restaurant_type == 8)) {
				if (area == 0 && (i >= 0 && i <= 6)) {
					if (price == 0 && (store[i].price >= 0 && store[i].price <= 5000)) possible_stores.push_back(store[i]);
					else if (price == 1 && (store[i].price > 5000 && store[i].price < 10000)) possible_stores.push_back(store[i]);
					else if (price == 2 && (store[i].price >= 10000 && store[i].price < 15000)) possible_stores.push_back(store[i]);
					else if (price == 3 && (store[i].price >= 15000 && store[i].price <= 25000)) possible_stores.push_back(store[i]);
					else possible_stores.push_back(store[i]);
				}
				else if (area == 1 && (i >= 55 && i <= 72)) {
					if (price == 0 && (store[i].price >= 0 && store[i].price <= 5000)) possible_stores.push_back(store[i]);
					else if (price == 1 && (store[i].price > 5000 && store[i].price < 10000)) possible_stores.push_back(store[i]);
					else if (price == 2 && (store[i].price >= 10000 && store[i].price < 15000)) possible_stores.push_back(store[i]);
					else if (price == 3 && (store[i].price >= 15000 && store[i].price <= 25000)) possible_stores.push_back(store[i]);
					else possible_stores.push_back(store[i]);
				}
				else if (area == 2 && ((i >= 40 && i <= 54) || (i >= 108 && i <= 118))) {
					if (price == 0 && (store[i].price >= 0 && store[i].price <= 5000)) possible_stores.push_back(store[i]);
					else if (price == 1 && (store[i].price > 5000 && store[i].price < 10000)) possible_stores.push_back(store[i]);
					else if (price == 2 && (store[i].price >= 10000 && store[i].price < 15000)) possible_stores.push_back(store[i]);
					else if (price == 3 && (store[i].price >= 15000 && store[i].price <= 25000)) possible_stores.push_back(store[i]);
					else possible_stores.push_back(store[i]);
				}
				else if (area == 3 && ((i >= 73 && i <= 88) || (i >= 103 && i <= 107))) {
					if (price == 0 && (store[i].price >= 0 && store[i].price <= 5000)) possible_stores.push_back(store[i]);
					else if (price == 1 && (store[i].price > 5000 && store[i].price < 10000)) possible_stores.push_back(store[i]);
					else if (price == 2 && (store[i].price >= 10000 && store[i].price < 15000)) possible_stores.push_back(store[i]);
					else if (price == 3 && (store[i].price >= 15000 && store[i].price <= 25000)) possible_stores.push_back(store[i]);
					else possible_stores.push_back(store[i]);
				}
				else if (area == 4 && (i >= 7 && i <= 39)) {
					if (price == 0 && (store[i].price >= 0 && store[i].price <= 5000)) possible_stores.push_back(store[i]);
					else if (price == 1 && (store[i].price > 5000 && store[i].price < 10000)) possible_stores.push_back(store[i]);
					else if (price == 2 && (store[i].price >= 10000 && store[i].price < 15000)) possible_stores.push_back(store[i]);
					else if (price == 3 && (store[i].price >= 15000 && store[i].price <= 25000)) possible_stores.push_back(store[i]);
					else possible_stores.push_back(store[i]);
				}
				else if (area == 5 && (i >= 89 && i <= 102)) {
					if (price == 0 && (store[i].price >= 0 && store[i].price <= 5000)) possible_stores.push_back(store[i]);
					else if (price == 1 && (store[i].price > 5000 && store[i].price < 10000)) possible_stores.push_back(store[i]);
					else if (price == 2 && (store[i].price >= 10000 && store[i].price < 15000)) possible_stores.push_back(store[i]);
					else if (price == 3 && (store[i].price >= 15000 && store[i].price <= 25000)) possible_stores.push_back(store[i]);
					else possible_stores.push_back(store[i]);
				}
				else {
					if (price == 0 && (store[i].price >= 0 && store[i].price <= 5000)) possible_stores.push_back(store[i]);
					else if (price == 1 && (store[i].price > 5000 && store[i].price < 10000)) possible_stores.push_back(store[i]);
					else if (price == 2 && (store[i].price >= 10000 && store[i].price < 15000)) possible_stores.push_back(store[i]);
					else if (price == 3 && (store[i].price >= 15000 && store[i].price <= 25000)) possible_stores.push_back(store[i]);
					else possible_stores.push_back(store[i]);
				}
			}
		}
		else if (store_type == DRUGSTORE) {
			if (store[i].type + 7 == DRUGSTORE) possible_stores.push_back(store[i]);
		}
		else if (store_type == CVS) {
			if (store[i].type + 7 == CVS) possible_stores.push_back(store[i]);
		}
		else if (store_type == CAFE) {
			if (store[i].type + 7 == CAFE) possible_stores.push_back(store[i]);
		}
	}
	return;
}

void sortingStore(int store_type, int sort_type) {
	if (store_type == RESTAURANT) {
		if (sort_type == 0) sort(possible_stores.begin(), possible_stores.end(), cmpDistance);
		else if (sort_type == 1) sort(possible_stores.begin(), possible_stores.end(), cmpPriceAscending);
		else if (sort_type == 2) sort(possible_stores.begin(), possible_stores.end(), cmpPriceDescending);
	}
	else sort(possible_stores.begin(), possible_stores.end(), cmpDistance);
	return;
}

bool cmpDistance(Node a, Node b) {
	if (graph[user_position][a.key] < graph[user_position][b.key]) return true;
	else return false;
}

bool cmpPriceAscending(Node a, Node b) {
	if (a.price < b.price) return true;
	else return false;
}

bool cmpPriceDescending(Node a, Node b) {
	if (a.price > b.price) return true;
	else return false;
}
