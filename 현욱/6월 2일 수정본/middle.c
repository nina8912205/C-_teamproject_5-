#include "common.h"
#define MSIZE 7

void middle(int n) // middle(0): ó������, middle(1): ó���ƴ�.
{
	extern int O_X[], SCORE[SCHSIZE][ASIZE], TotalScore;
	extern int item[3];
	extern int gobackstart, end_game;

	char word[SIZE], input[SIZE];
	int grade, x = 0;
	int result;

	// ����
	gobackstart = 0;
	resetScore(M);
	resetOX();

	if (!n)
	{
		get_name();
		system("cls");
	}

	welcome(M);

	drawline(21, 8, 75, 25);       // ���̾ƿ� �׸���

	item_random(2);                // ������ �̱�

	for (grade = 1; grade <= 3; grade++)
	{
		for (int num = 1; num <= 3; num++)
		{
			if ((item[LIFE]) == 0)
				break;

			/*gotoxy(32, 24); printf("total: %d, e_time: %d", TotalScore, SCORE[M][TIME]);
			gotoxy(32, 25); printf("m_correct: %d, m_combo: %d", SCORE[M][CORRECT], SCORE[M][COMBO]);*/

			// ���̾ƿ�
			layout(M, grade, num);

			// �������
			switch (grade) // �г⺰ ���� ���
			{
			case 1:
				gotoxy(56, 19);// 1�г�: 7���� ���ܾ�				
				x = 56;
				word_7(word);
				break;
			case 2:
				gotoxy(56, 19);// 2�г�: ���� ���ڿ�(7����)
				x = 56;
				random_word(MSIZE, word);
				break;
			case 3:
				gotoxy(40, 19);// 3�г�: ª�� ��
				x = 40;
				word_short(word);
				break;
			}

			// �������߱�			
			result = game(x, input, word, M, grade, 0);


			// �ܾ� �ٲٱ� ����
			if (result == WORDITEM)
			{
				num--;
				gotoxy(36, 17); printf("                                   ");
				continue;
			}

			// result 0: ����, 1: ����, 2: �޴�������, 3: ���۸޴� 4:���� �缱�� 5:�ܾ�ٲٱ�
			while (1)
			{
				if (result == HOWTOPLAY) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					layout(M, grade, num);
					gotoxy(x, 19);	printf("���� : %s", word);
					result = game(x, input, word, M, grade, 0);
				}
				if (result == STARTMENU)
				{
					gobackstart = 1;
					break;
				}
				else
					break;
			}
			if (gobackstart)
				break;
			// ����ǥ ���
			O_X[SCORE[M][Q_SOLVED] - 1] = result;
		}
		if (gobackstart)
			break;

		if (item[LIFE] && grade < 3)
			gradeup();
	}

	if (!gobackstart)
	{
		// ����� ���� ���, ���б� ����!
		if (item[LIFE])
			test(M);

		// ����ǥ ���
		end_game = Scorecard(M);

		if (item[LIFE] && end_game)
			high(1);
	}

}