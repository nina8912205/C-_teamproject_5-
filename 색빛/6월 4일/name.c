/* get_name : �̸� �Է� */
#include "common.h"

char name[SIZE];

void get_name()
{	
	drawline(21, 8, 75, 25);
	gotoxy(37, 18);	printf("������ �����ϱ� ����, ����� �̸��� �˷��ּ���!\n");
	drawline(47, 20, 22, 1);
	gotoxy(50, 21);
	cursor(1);
	gets_s(name, SIZE);
	cursor(0);
	Sleep(700);
}

void welcome(int level)
{
	extern char sch[SCHSIZE][SIZE];

	system("cls");
	KU(2);
	if (rand() % 2)	KU(1);
	else KU(3);

	drawline(21, 8, 75, 25);
	drawline(21, 19, 75, 3);
	gotoxy(45, 21);
	cursor(0);

	printf("%s, %s�б� ������ �����Ѵ�KU!", name, sch[level]);
	Sleep(1200);

	gotoxy(37, 29);
	printf("[TIP] �޴� ����� ����ϰ� ���� �� ESCŰ�� ������!");
	gotoxy(95, 33);
	printf(">");
	cursor(1);
	_getch();
}