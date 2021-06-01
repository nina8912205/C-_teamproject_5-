#include "common.h"

void high(int n) // high(0): ó������, high(1): ó���ƴ�.
{
	extern int O_X[], scorearray[SCHSIZE][ASIZE], TotalScore;
	extern int item[3];
	extern int time_left, end_game, gobackstart;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;

	gobackstart = 0;
	time_left = 0;  // �����ð� �ʱ�ȭ
	resetScore(H);
	resetOX();

	if (!n)
	{
		get_name();
		system("cls");
	}

	welcome(H);

	drawline(21, 8, 75, 25);       // ���̾ƿ� �׸���

	item_random(2);    // ������ �̱�

	for (grade = 1; grade <= 3; grade++)
	{
		score = grade * 5000; // �г� �� ����

		for (int num = 1; num <= 3; num++)
		{
			if (item[LIFE] == 0)
				break;

			scorearray[H][Q_SOLVED]++;

			// ���̾ƿ�
			layout(H, grade, num, score);

			// �������
			gotoxy(40, 19);

			switch (grade) // �г⺰ ���� ���
			{
			case 1:                    // 1�г�: 7���� ���ܾ�
				random_word(10, word);
				break;
			case 2:                    // 2�г�: ���� ���ڿ�(7����)
				word_short(word);
				break;
			case 3:                    // 3�г�: ª�� ��
				word_short_h(word);
				break;
			}

			// �������߱�
			timelimit = Htime(grade);
			result = game(40, timelimit, input, word, scorearray[H][Q_SOLVED], H, 0, score);

			// �ܾ� �ٲٱ� ����
			if (result == 5)
			{
				num--;
				continue;
			}

			// result 0: ����, 1: ����, 2: �޴�������
			while (1)
			{
				if (result == 1)
				{
					timescore(H, TimeBonus(time_left));
					correct(H, score);
					if (O_X[scorearray[H][Q_SOLVED] - 2] == 1)
						combo(H);
					scorearray[H][Q_CORRECT]++;
					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					layout(E, grade, num, score);
					gotoxy(40, 19);	printf("%s", word);
					timelimit = Htime(grade);
					result = game(40, timelimit, input, word, scorearray[H][Q_SOLVED], H, 0, score, , H, 0, score);
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
			O_X[scorearray[H][Q_SOLVED] - 1] = result;			
		}
		if (gobackstart)
			break;
	}
	if (!gobackstart)
	{
		// ����� ���� ���, ���б� ����!
		if (item[LIFE])
			test(H);

		// ����ǥ ���
		end_game = Scorecard(H);

		system("cls");
		Final_Scorecard();
		Sleep(5000);
	}
		
}