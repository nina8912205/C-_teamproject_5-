/* get_name : �̸� �Է� */
#include "common.h"

char name[100]; //############ ���� - ��������&&�����Ҵ� -> ��������

void get_name()
{
	gotoxy(47, 21);
	printf("�� �̸��� ����? \n");
	gotoxy(63, 21);
	cursor(1);
	gets_s(name, 100);
	cursor(0);
	gotoxy(47, 23);
	printf("%s ! ���� �̸��̴�!", name);
	Sleep(1000);
}