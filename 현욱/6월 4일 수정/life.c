/* ��� ���� */
#include "common.h"

int die = 0;//�׾����� ���

/* ��� ���� - ���� ���� �� */
void decrease_life(int* item)
{
	// life: ��� ���� ���� ����
	extern int die;

	item[LIFE]--;

	if (item[LIFE] == 0)
	{
		gotoxy(30, 7); printf("   ");
		gotoxy(32, 26);	printf("����� �����ϴ�. ��Ÿ���Ե� ���ӿ� �����ϼ̽��ϴ�.");
		gotoxy(32, 28);	printf("������ �����մϴ�.");
		Sleep(2000);
		die = 1;
	}
}