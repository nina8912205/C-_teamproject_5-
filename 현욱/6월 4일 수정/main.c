#include "common.h"

int main(void)
{
	extern int end_game;
	extern int die;

	system("mode con: cols=120 lines=43"); // �ܼ�â ũŰ ����
	srand((unsigned)time(NULL));

	while (1)
	{
		system("cls");
		game_title();                 // ���� Ÿ��Ʋ

		while (1)
		{
			resetScore();
			game_start_menu();        // ���� ���� �� ����
			if (die == 1)             //��� 0 �Ǿ� �׾��� ��� - Ÿ��Ʋ ������� ���ư�.
			{
				die = 0;
				end_game = 0;
				break;
			}
			if (end_game)        //���� ���� ���� - ���� �޴����� ���� ���� ���ý� ���� ���α׷� ����//
				break;
		
		}
		if (end_game == 1) //���� ���� �޴����� 3. �������� ���ý�, ���� ���α׷� ������ 
			break;
	}

	return 0;
}