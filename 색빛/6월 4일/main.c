#include "common.h"

int main(void)
{
	extern int end_game;
	extern int die;

	system("mode con: cols=120 lines=43"); // �ܼ�â ũŰ ����
	srand((unsigned)time(NULL));

	while (1)
	{
		game_title();                 // ���� Ÿ��Ʋ

		while (1)
		{	
			resetScore();
			game_start_menu();        // ���� ���� �� ����

			if (end_game == 2)        //���� ���� ���� - ���� �޴����� ���� ���� ���ý� ���� ���α׷� ����//
				break;
		}
		if (end_game) //���� ���� �޴����� 3. �������� ���ý�, ���� ���α׷� ������ 
			break;
	}

	return 0;
}

