//############ 색빛 - 좀 더 수정 필요
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
		printf("※ 어떤 기능을 실행하시겠습니까? ");
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
			game_start_menu();            // @@@@@@@@@@@@@@@@@@@ 예원 : L 누르면 다시 메뉴선택
			system("cls");
			result = 3;
			break;
		}
		else if (!strcmp(menu, "S"))
		{
			system("cls");
			result = 4;                // @@@@@@@@@@@@@@@@@@@@@@2 ㅇ예원 : result = 4
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