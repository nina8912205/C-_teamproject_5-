#include "common.h"

int menu()
{
	char key;
	int result = 0;

	while (1)
	{                
		clear(29, 17, 30, 5);
		gotoxy(33, 35); printf("  ���  ");       
		gotoxy(23, 33);	printf("�� � ����� �����Ͻðڽ��ϱ�? ");    
		
		key = _getch();
		switch (key)
		{
		case ESC:
			result = 2;
			break;
		case 'R':
			printf("%c", key);
			system("cls");
			game_rules(1);
			result = HOWTOPLAY;
			break;
		case 'L':
			printf("%c", key);
			system("cls");
			game_start_menu();
			system("cls");
			result = CHANGE_LEVEL;
			break;
		case 'S':
			printf("%c", key);
			system("cls");
			result = STARTMENU;
			break;
		case 'Q':
			printf("%c", key);
			system("cls");
			exit(0);
			break;
		default:
			gotoxy(50, 33); printf("  ");
			continue;
		}
		break;
	}
	return result;
}