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

typedef struct { //���� ����ü
	int head;
	int stack[250];
} STACK;

Node store[250]; //�� ������ ������ ��� ����ü �迭
//STACK print_route; 
//STACK possible_stores; 
stack<int> print_route; //��� ��¿� ���Ǵ� ����
stack<int> possible_stores; //������ ���Ե��� �����ϴ� ����
int graph[250][250]; //�� ���� �� �Ÿ��� �����ϴ� ������ �迭
int route[250][250]; // a���� b�� �� �� b�� �����ϱ� ���� ������ �����ϴ� ������ �迭 (��� ��� �� �̿�)

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
void initGraph(); //���� �� ��� �Ÿ��� ���Ѵ�� �����մϴ� + route�� NIL�� �ʱ�ȭ
void setEdgeDist(); //���� �� �Ÿ��� �ڵ����� �Է��մϴ�
void floydWarshallAlgorithm(); //�÷��̵�-���� �˰����� ����Ͽ� �� ���� �� �ִܰ�θ� ����մϴ�
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

void gotoxy(int x, int y)//���� ���ϴ� ��ġ�� Ŀ�� �̵�
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);// WIN32API �Լ��Դϴ�
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
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��             ����� ������ ���� ã�� �����                   ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��   ã�� ���� ���� ������ �������ּ���                         ��\n");
	printf("��                                                              ��\n");
	printf("��   *����Ű�� �����̽��ٷ� ������ �� �ֽ��ϴ�                  ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��           > �Ĵ�                                             ��\n");
	printf("��             �౹                                             ��\n");
	printf("��             ������&��Ʈ                                      ��\n");
	printf("��             ī��                                             ��\n");
	printf("��             ����                                             ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");

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
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��             ����� ������ ���� ã�� �����                   ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                              ��\n");
	printf("��                   ���α׷��� �����մϴ�                      ��\n");
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("��                                                              ��\n");
	printf("��                  �̿����ּż� �����ϴ�!                    ��\n");
	printf("��                                                              ��\n");
	printf("��                    COMEDU X HANEDU PROJ                      ��\n");
	printf("��                                                              ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	return;
}

int restaurantPage() {
	int x = 3, y = 8, com, run = TRUE;

	system("cls");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��             ����� ������ ���� ã�� �����                      ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��   �Ĵ��� �����ϼ̽��ϴ�                                         ��\n");
	printf("��   ���� ��ġ�� �������ּ���                                      ��\n");
	printf("��                                                                 ��\n");
	printf("��   *����Ű�� �����̽��ٷ� ������ �� �ֽ��ϴ�                     ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��  > ȣ�ϰ�      ������             �÷���Ÿ�        �б�����    ��\n");
	printf("��    �濵��      ������             ��ȭ��1���ⱸ     ���Ÿ�    ��\n");
	printf("��    ������      �ʹ�����������     ��ȭ��4���ⱸ     �߾ӵ�����  ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");

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
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��             ����� ������ ���� ã�� �����                   ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��   �౹�� �����ϼ̽��ϴ�                                      ��\n");
	printf("��   ���� ��ġ�� �������ּ���                                   ��\n");
	printf("��                                                              ��\n");
	printf("��   *����Ű�� �����̽��ٷ� ������ �� �ֽ��ϴ�                  ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��  > ȣ�ϰ�      ������             �÷���Ÿ�        �ʹ�     ��\n");
	printf("��    �濵��      �߾ӵ�����         ��ȭ��1���ⱸ     ���Ÿ� ��\n");
	printf("��    ������      �ʹ�����������     ��ȭ��4���ⱸ     �ҳ����� ��\n");
	printf("��    ������      �б�����           ���з�                     ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");

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
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��             ����� ������ ���� ã�� �����                   ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��   ������&��Ʈ�� �����ϼ̽��ϴ�                               ��\n");
	printf("��   ���� ��ġ�� �������ּ���                                   ��\n");
	printf("��                                                              ��\n");
	printf("��   *����Ű�� �����̽��ٷ� ������ �� �ֽ��ϴ�                  ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��  > ȣ�ϰ�      ������             �÷���Ÿ�        �ʹ�     ��\n");
	printf("��    �濵��      �߾ӵ�����         ��ȭ��1���ⱸ     ���Ÿ� ��\n");
	printf("��    ������      �ʹ�����������     ��ȭ��4���ⱸ     �ҳ����� ��\n");
	printf("��    ������      �б�����           ���з�                     ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");

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
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��             ����� ������ ���� ã�� �����                   ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��   ī�並 �����ϼ̽��ϴ�                                      ��\n");
	printf("��   ���� ��ġ�� �������ּ���                                   ��\n");
	printf("��                                                              ��\n");
	printf("��   *����Ű�� �����̽��ٷ� ������ �� �ֽ��ϴ�                  ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��   > ȣ�ϰ�      ������             �÷���Ÿ�        �ʹ�    ��\n");
	printf("��     �濵��      �߾ӵ�����         ��ȭ��1���ⱸ     ���Ÿ���\n");
	printf("��     ������      �ʹ�����������     ��ȭ��4���ⱸ     �ҳ����榢\n");
	printf("��     ������      �б�����           ���з�                    ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");

	return x * 100 + y;
}


void initGraph() {
	for (int i = 0; i < 250; i++) {
		for (int j = 0; j < 250; j++) {
			if (i == j) graph[i][j] = 0; //�ڱ� �ڽ����� ���� �Ÿ��� 0
			else graph[i][j] = INFINITE; //�ƴϸ� �ϴ� �� �� ���� (�Ÿ� ���Ѵ�)
			route[i][j] = NIL; // ���� ������ �켱 NIL�� �ʱ�ȭ
		}
	}
	return;
}

void setEdgeDist() { //�迭�� ��ĭ ó�� �ʿ�
	for (int i = 0; i < 250; i++) {
		if (i < 120) { // ���Ը�
			graph[i][store[i].position] = store[i].store_to_pos_dist; //���� -> ù��° ����� ���� �Ÿ�
			graph[store[i].position][i] = store[i].store_to_pos_dist; //ù��° ����� ���� -> ���� �Ÿ�

			graph[i][store[i].second_near] = store[i].store_to_sec_dist; //���� -> �ι�° ����� ���� �Ÿ�
			graph[store[i].second_near][i] = store[i].store_to_sec_dist; //�ι�° ����� ���� -> ���� �Ÿ�
		}
	}
	return;
}

void floydWarshallAlgorithm() {
	for (int k = 0; k < 250; k++) {
		for (int i = 0; i < 250; i++) {
			for (int j = 0; j < 250; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) { //i���� j�� �� �� ���� ���� k�� �� ���� ���°� �� ����� ��
					graph[i][j] = graph[i][k] + graph[k][j]; // �ִ� �Ÿ� ����
					route[i][j] = route[k][j]; // i���� j ���� ���� ������ k���� j ���� ���� �������� ����
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