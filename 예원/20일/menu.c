#include "common.h"

void menu()
{
	char menu[2];
	while (1) {
		gotoxy(23, 33);
		printf("�� � ����� �����Ͻðڽ��ϱ�? ");
		gets_s(menu, 2);

		if (!strcmp(menu, "P"))
		{
			//����!
			break;
		}
		else if (!strcmp(menu, "R"))
		{
			system("cls");
			game_rules();
			break;
		}
		else if (!strcmp(menu, "L"))
		{
			// ���� �����
			break;
		}
		else if (!strcmp(menu, "S"))
		{
			system("cls");
			game_title();
			break;
		}
		else if (!strcmp(menu, "Q"))
			exit(0);
		else
			continue;
	}


}