/* item : ������ �̱� */
#include "common.h"

int life = LIFE, changeword = 0, addtime = 0; //############ ���� - ��ȣ ��� ���

void item_random(int n) //############ ���� - �� �� ���� �� �μ� �߰�

{
	life = LIFE, changeword = 0, addtime = 0; //**** 5/24(����) - ���� ������/���� �б��� �Ѿ �� ��� ������ ������ �����°� �������� life=LIFE �߰�

	int i, p;
	system("cls");
	drawline();
	gotoxy(52, 15);
	printf("�������� �̾ƺ���\n\n");

	Sleep(1500);
	for (i = 1; i <= n; i++)  //############ ���� - �μ� ���
	{
		p = rand() % 4;
		switch (p)
		{
		case ADDLIFE:
			life++;
			gotoxy(56, 16 + i * 2);
			printf("\'�������\'");
			break;
		case CHANGEWORD:
			changeword++;
			gotoxy(55, 16 + i * 2);
			printf("\'�ܾ�ٲٱ�\'");
			break;
		case ADDTIME:
			addtime++;
			gotoxy(56, 16 + i * 2);
			printf("\'�ð�����\'");
			break;
		case BOMB:
			gotoxy(58, 16 + i * 2);
			printf("\'��!\'\n\n");
			break;
		}
	}
	drawitem();
	drawmenu();
	gotoxy(36, 26);
	printf("�������: %d��, �ܾ�ٲٱ�: %d��, �ð�����: %d�� ȹ��!\n", life - LIFE, changeword, addtime); //############ ���� - ��ȣ ��� ���
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                         �ƹ�Ű�� ������ ���� ����! >");
	_getch();
}