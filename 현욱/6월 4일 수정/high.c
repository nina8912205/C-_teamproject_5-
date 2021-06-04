#include "common.h"

void high(int n) // high(0): ó������, high(1): ó���ƴ�.
{
	extern int O_X[], SCORE[SCHSIZE][ASIZE], TotalScore;
	extern int item[3];
	extern int end_game;

	char word[SIZE], input[SIZE];
	int grade, x;
	int result;

	resetOX();

	if (!n)
	{
		get_name();
		system("cls");
	}

	welcome(H);

	drawline(21, 8, 75, 25);       // ���̾ƿ� �׸���

	item_random(2);    // ������ �̱�

	for (grade = 1; grade <= 1; grade++)
	{
		for (int num = 1; num <= 1; num++)
		{
			if (item[LIFE] == 0)
				break;
			
			
			// ���̾ƿ�
			layout(H, grade, num);

			// �������
			gotoxy(40, 19);

			switch (grade) // �г⺰ ���� ���
			{
			case 1: // 1�г�: 10���� ���ܾ�				
				x = 55;
				gotoxy(x, 19);
				random_word(10, word);
				break;
			case 2: // 2�г�: ª�� ��
				x = 50;
				gotoxy(x, 19);
				word_short(word);
				break;
			case 3: // 3�г�: �� ª�� ��
				x = 33;
				gotoxy(x, 19);
				word_short_h(word);
				break;
			}

			// �������߱�
			result = game(x, input, word, H, grade, 0);

			// �ܾ� �ٲٱ� ����
			if (result == 5)
			{
				num--;
				continue;
			}

			// result 0: ����, 1: ����, 2: �޴�������
			while (1)
			{
				if (result == HOWTOPLAY) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					layout(H, grade, num);
					gotoxy(x, 19);	printf("%s", word);
					result = game(x, input, word, H, grade, 0);
				}
				if (result == STARTMENU || result == CHANGE_LEVEL)
					return;
				else
					break;
			}

			// ����ǥ ���
			O_X[SCORE[H][Q_SOLVED] - 1] = result;
		}

		if (item[LIFE] && grade < 3)
			gradeup();
	}
	// ����� ���� ���, ���б� ����!
	if (item[LIFE])
		test(H);

	// ����ǥ ���
	end_game = Scorecard(H);
	
	end_game = 0;
	if (SCORE[E][B_Q_SOLVED] == 5 && SCORE[M][B_Q_SOLVED] == 5 && SCORE[H][B_Q_SOLVED] == 5)
	{
		Final_Scorecard();
		gotoxy(27, 32);
		system("pause");
	}
	system("cls");
	//��⼭ ����!
}