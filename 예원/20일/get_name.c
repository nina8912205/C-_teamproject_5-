/* get_name : �̸� �Է� */
#include "common.h"

void get_name()
{
	static char name[100];

	gotoxy(47, 21);
	printf("�� �̸��� ����? \n");
	gotoxy(63, 21);
	gets_s(name, 100);                     // ���� scanf("%s", name) �̾��µ� �Է¹��ۿ� enter �� ���� �ڿ� elementary�� ù���� �Է¿� �����༭ ����. 
	gotoxy(47, 23);
	printf("%s ! ���� �̸��̴�!", name);
	Sleep(1000);
}