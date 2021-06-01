#include "common.h"
#define MSIZE 7

void middle(int n) // middle(0): ó������, middle(1): ó���ƴ�.
{
	extern int O_X[], scorearray[SCHSIZE][ASIZE], TotalScore;
	extern int item[3];
	extern int time_left, gobackstart, end_game;

	char word[SIZE], input[SIZE];
	int grade, score = 0, x = 0;
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

	for (grade = 1; grade <= 3; grade++)
	{
		score = grade * 3000; // �г� �� ����

		for (int num = 1; num <= 3; num++)
		{
			if ((item[LIFE]) == 0)
				break;

			/*gotoxy(32, 24); printf("total: %d, e_time: %d", TotalScore, scorearray[M][TIME]);
			gotoxy(32, 25); printf("m_correct: %d, m_combo: %d", scorearray[M][CORRECT], scorearray[M][COMBO]);*/
			scorearray[M][Q_SOLVED]++;

			// ���̾ƿ�
			layout(M, grade, num, score);

			// �������
			timelimit = Mtime(grade);

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
			
			result = game(x, timelimit, input, word, scorearray[M][Q_SOLVED], M, 0, score);
			

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
					layout(M, grade, num, score);
					gotoxy(40, 19);	printf("���� : %s", word);
					timelimit = Mtime(grade);
					result = game(40, timelimit, input, word, scorearray[M][Q_SOLVED], M, 0, score);
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