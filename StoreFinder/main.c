#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//#include "storeinfo.h"

#define TRUE 1
#define FALSE 0
#define ARROWKEY 224
#define UP 72
#define DOWN 80
#define LEFT 77
#define RIGHT 75

//Node store[1000];
int graph[100][100];

//functions
void gotoxy(int x, int y);
int keyReturn();
int mainPage();

int main()
{
	mainPage();
	/*while (TRUE) {
		gotoxy(x, y);
		printf("#");
		if (kbhit()) {
			nSelect = getch();
			if (nSelect == ARROWKEY) {
				nSelect = getch();
				switch (nSelect)
				{
				case LEFT:
					y--;
					break;
				case RIGHT:
					y++;
					break;
				case UP:
					x--;
					break;
				case DOWN:
					x++;
					break;
				default:
					break;
				}
			}
			system("cls");
		}
	}*/

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
		return command;
	}
}

int mainPage() {
	int x = 13, y = 8, com;

	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                    ����� ������ ���� ã�� �����                  ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��   ã�� ���� ���� ������ �������ּ���                                                            ��\n");
	printf("��                                                               ��\n");
	printf("��   *����Ű�� ���ͷ� ������ �� �ֽ��ϴ�                                                           ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��           > �Ĵ�                ��\n");
	printf("��             �౹              ��\n");
	printf("��             ������&��Ʈ              ��\n");
	printf("��             ī��              ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������\n");

	while (TRUE) {
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

		default:
			break;
		}
	}
}
