//############ 색빛 - 좀 더 수정 필요
#include "common.h"

int menu()
{
	char menu[2];
	int result;

	while (1)
	{
		gotoxy(38, 17);                   //############ 색빛 - 메뉴를 실행하면 출력글자 지우기
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
			// 레벨 다시 선택
			// result = 3;
			break;
		}
		else if (!strcmp(menu, "S"))
		{
			system("cls");
			// result = 4;
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

