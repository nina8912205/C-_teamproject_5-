/* get_name : �̸� �Է� */
#include "common.h"

char name[100];

void get_name(int level)
{
	char sch[10];
	/*if (strlen(sch))
	{
		for (int i = 0; i < strlen(sch); i++)
			sch[i] = 0;
	}*/
	drawline(21, 8, 75, 25);
	gotoxy(37, 18);
	printf("������ �����ϱ� ����, ����� �̸��� �˷��ּ���!\n");
	drawline(47, 20, 22, 1);
	gotoxy(50, 21);
	cursor(1);
	gets_s(name, 100);
	cursor(0);
	Sleep(700);
	system("cls");
	KU(2);
	drawline(21, 8, 75, 25);
	drawline(21, 19, 75, 3);
	gotoxy(45, 21);
	cursor(0);
	switch(level)
	{
	case ELEMENTARY:
		strcpy(sch, "�ʵ�");
		break;
	case MIDDLE:
		strcpy(sch, "��");
		break;
	case HIGH:
		strcpy(sch, "���");
		break;
	}
	printf("%s, %s�б� ������ �����Ѵ�KU!", name, sch);
	Sleep(1200);

	gotoxy(37, 29);
	printf("[TIP] �޴� ����� ����ϰ� ���� �� ESCŰ�� ������!");
	gotoxy(95, 33);
	printf(">");
	cursor(1);
	_getch();
}