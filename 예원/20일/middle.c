#include "common.h"

void middle()
{
	char word[SIZE];
	char input[SIZE];
	int score;
	int k;             // ���ڿ� ���� ���� ����

	system("cls");
	drawline();
	item_random();     // ������ �̱�
	system("cls");

	// item_board(); // ������ ���� ��Ȳ �����


	// ���̵� ����
	// �г⺰�� �ܾ����, 


	for (int i = 1; i <= 3; i++)  // 1�г� ~ 6�г�
	{
		for (int j = 1; j <= 5; j++)  // �г�� ���� ���� : 3�� 
		{
			drawline();
			drawitem();
			drawmenu();
			gotoxy(32, 15);

			printf("[%d �г� - ���� %d ��]\n", i, j);

			// ���� ���ڿ�
			for (k = 0; k <= i - 1; k++) // �ش� �г⸸ŭ ������ �������ڿ�
			{
				word[k] = 'a' + (rand() % 26);
			}
			word[k] = '\0';

			// ���� �ο�
			score = i * 1000;

			// ���� ���
			gotoxy(32, 17);
			printf("���� : ");
			printf("%s\n", word);
			gotoxy(52, 17);
			printf("           ���� : %d ��\n\n", score);

			// ���� ���߱� 
			gotoxy(32, 19);
			printf("������ ���� ġ���� : ");
			gets_s(input, SIZE);

			if (!strcmp(input, word))
			{
				gotoxy(32, 21);
				printf("���� ! ���� ȹ�� ! ���� ���� : %d", middle_score_add(score));

				//if (lefttime > 0)
				//{
				//	elemetary_score += score;
				//}
			}
			else
			{
				gotoxy(32, 21);
				printf("���� �Ф� ������� ... ���� ���� : %d", middle_score_add(score));
				decrease_life();
			}

			Sleep(2000);
			system("cls");
		}

	}
}