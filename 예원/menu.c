//############ ���� - �� �� ���� �ʿ�
#include "common.h"

int menu()
{
	char menu[2];
	int result;

	while (1)
	{
		gotoxy(38, 17);
		for (int i = 1; i < 10; i++)
			printf("  ");
		gotoxy(23, 33);
		printf("�� � ����� �����Ͻðڽ��ϱ�? ");
		gets_s(menu, 2);

		if (!strcmp(menu, "P"))
		{
			gotoxy(40, 21);
			system("pause");
			system("cls");
			result = 2;
			break;
		}
		else if (!strcmp(menu, "R"))
		{
			system("cls");
			game_rules();
			system("cls");
			result = 2;
			break;
		}
		else if (!strcmp(menu, "L"))
		{
			system("cls");
			game_start_menu();            // @@@@@@@@@@@@@@@@@@@ ���� : L ������ �ٽ� �޴�����
			system("cls");
			result = 3;
			break;
		}
		else if (!strcmp(menu, "S"))
		{
			system("cls");
			result = 4;                // @@@@@@@@@@@@@@@@@@@@@@2 ������ : result = 4
			break;
		}
		else if (!strcmp(menu, "Q"))
		{
			system("cls");
			exit(0);
			break;
		}
		else
			continue;
	}
	return result;
}