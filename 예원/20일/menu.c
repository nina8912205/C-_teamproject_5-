#include "common.h"

void menu()
{
	char menu[2];
	while (1) {
		gotoxy(23, 33);
		printf("※ 어떤 기능을 실행하시겠습니까? ");
		gets_s(menu, 2);

		if (!strcmp(menu, "P"))
		{
			//멈춰!
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
			// 레벨 물어보기
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