#include "common.h"

int main(void)
{
	extern int end_game;
	extern int die;

	system("mode con: cols=120 lines=43"); // �ܼ�â ũŰ ����
	srand((unsigned)time(NULL));
	
	while (1)
	{
		cursor(0);
		game_title();                 // ���� Ÿ��Ʋ

		while (1)
		{
			game_start_menu();        // ���� ���� �� ����

			if (end_game == 1)        //���� ���� ���� - ���� �޴����� ���� ���� ���ý� ���� ���α׷� ����//
				break;
			if (die == 1)             //��� 0 �Ǿ� �׾��� ��� - Ÿ��Ʋ ������� ���ư�.
			{
				die = 0;
				break;
			}
		}

		if (end_game == 1) //���� ���� �޴����� 3. �������� ���ý�, ���� ���α׷� ������ 
			break;
	}

	return 0;
}

void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void cursor(int n) //############ ���� - Ŀ�� ���̱�cursor(1) & �����cosor(0)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

