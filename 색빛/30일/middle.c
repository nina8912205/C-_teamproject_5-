#include "common.h"
#define MSIZE 7

void middle(int n) // middle(0): ó������, middle(1): ó���ƴ�.
{
	extern int O_X[], scorearray[SCHSIZE][ASIZE], TotalScore;
	extern int life, changeword, addtime;
	extern int time_left, gobackstart, end_game;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;

	// ����
	gobackstart = 0;
	time_left = 0;
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
	system("cls");

	for (grade = 1; grade <= 1; grade++)
	{
		score = grade * 3000; // �г� �� ����

		// ��� �˻�
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++)
		{
			gotoxy(32, 24); printf("total: %d, e_time: %d", TotalScore, scorearray[M][TIME]);
			gotoxy(32, 25); printf("m_correct: %d, m_combo: %d", scorearray[M][CORRECT], scorearray[M][COMBO]);
			scorearray[M][Q_SOLVED]++;

			// ���̾ƿ�
			drawline(21, 8, 75, 25);
			draws("��", grade, num);
			drawitem();
			drawmenu();

			// �������
			gotoxy(32, 17); printf("���� : ");

			switch (grade) // �г⺰ ���� ���
			{
			case 1:                    // 1�г�: 7���� ���ܾ�
				word_7(word);
				break;
			case 2:                    // 2�г�: ���� ���ڿ�(7����)
				random_word(MSIZE, word);
				break;
			case 3:                    // 3�г�: ª�� ��
				word_short(word);
				break;
			}
			gotoxy(70, 17);	printf("���� : %d ��", score);

			// �������߱�
			gotoxy(32, 19);	printf("������ ���� ġ����: ");
			cursor(1);
			timelimit = Mtime(grade);
			result = game(timelimit, input, word, scorearray[M][Q_SOLVED]);

			// �ܾ� �ٲٱ� ����
			if (result == 5)
			{
				num--;
				gotoxy(36, 17); printf("                                   ");
				continue;
			}

			// result 0: ����, 1: ����, 2: �޴�������, 3: ���۸޴� 4:���� �缱�� 5:�ܾ�ٲٱ�
			while (1)
			{
				if (result == 1)
				{
					timescore(M, TimeBonus(time_left));
					correct(M, score);
					if (O_X[scorearray[M][Q_SOLVED] - 2] == 1)
						combo(M);
					scorearray[M][Q_CORRECT]++;
					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					drawline(21, 8, 75, 25);
					draws("��", grade, num);
					drawitem();
					drawmenu();

					gotoxy(32, 17);	printf("���� : %s", word);
					gotoxy(70, 17);	printf("���� : %d ��", score);
					gotoxy(32, 19);	printf("������ ���� ġ����: ");
					timelimit = Mtime(grade);
					result = game(timelimit, input, word, scorearray[M][Q_SOLVED]);
				}
				else if (result == 4) {
					gobackstart = 1;  
					break;
				}
				else
					break;
			}
			if (gobackstart)
				break;
			// ����ǥ ���
			O_X[scorearray[M][Q_SOLVED] - 1] = result;			
		}
		if (gobackstart)
			break;
	}

	if (!gobackstart)
	{
		// ����� ���� ���, ���б� ����!
		if (life > 0) 
			m_boss();

		// ����ǥ ���
		end_game = Scorecard(M);

		if (life && end_game)
			high(1);
	}
	

}