/* get_name : �̸� �Է� */
#include "common.h"

void get_name()
{
	static char name[100];

	gotoxy(47, 21);
	printf("�� �̸��� ����? \n");
	gotoxy(63, 21);
	scanf("%s", &name);
	gotoxy(47, 23);
	printf("%s ! ���� �̸��̴�!", name);
}