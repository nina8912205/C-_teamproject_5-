/* item : ������ �̱� */
#include "common.h"

int item[3] = { 0 };

void item_random(int n)
{
	extern char name[100];
	int i, p;
	
	item[LIFE] = DEFAULT, item[CHANGEWORD] = 0; item[ADDTIME] = 0;

	cursor(0);
	system("cls"); 
	drawline(21, 8, 75, 25);
	gotoxy(44, 14);	printf("%s�Բ� ���м����� �����߽��ϴ�!\n", name);
	Sleep(1500);
	gotoxy(48, 16);	printf("\"������ ���� �̱� (%dȸ)\"", n);
	Sleep(1000);
	gotoxy(44, 18);	printf("< �ƹ�Ű�� ������ ������ ��÷ >");
	cursor(1);
	_getch();
	drawline(43, 19, 30, 7);

	for (i = 1; i <= n; i++) 
	{
		p = rand() % 4;
		switch (p)
		{
		case LIFE:
			item[LIFE]++;
			gotoxy(55, (22 - n) + i * 2);
			printf("\'�������\'");
			break;
		case CHANGEWORD:
			item[CHANGEWORD]++;
			gotoxy(54, (22 - n) + i * 2);
			printf("\'�ܾ�ٲٱ�\'");
			break;
		case ADDTIME:
			item[ADDTIME]++;
			gotoxy(55, (22 - n) + i * 2);
			printf("\'�ð�����\'");
			break;
		case BOMB:
			gotoxy(58, (22 - n) + i * 2);
			printf("\'��\'\n\n");
			break;
		}
	}
	drawitem();
	drawmenu();
	gotoxy(36, 28);	printf("�������: %d��, �ܾ�ٲٱ�: %d��, �ð�����: %d�� ȹ��!\n", item[LIFE] - DEFAULT, item[CHANGEWORD], item[ADDTIME]);
	gotoxy(32, 31);	printf("[TIP] �ܾ� �ٲٱ� �������� TABŰ�� ������ ����� �� �־�!\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t     ���� ���� >");
	_getch();
	system("cls");
}