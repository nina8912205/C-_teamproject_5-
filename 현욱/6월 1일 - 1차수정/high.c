#include "common.h"

void high(int n) // high(0): ó������, high(1): ó���ƴ�.
{
	extern int O_X[], scorearray[SCHSIZE][ASIZE], TotalScore;
	extern int life, changeword, addtime;
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
	system("cls");

	for (grade = 1; grade <= 1; grade++)
	{
		score = grade * 5000; // �г� �� ����

		// ��� �˻�
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++)
		{
			gotoxy(32, 24);	printf("total: %d, e_time: %d", TotalScore, scorearray[H][TIME]);
			gotoxy(32, 25);
			printf("m_correct: %d, m_combo: %d", scorearray[H][CORRECT], scorearray[H][COMBO]);
			scorearray[H][Q_SOLVED]++;

			// ���̾ƿ�
			drawline(21, 8, 75, 25);
			draws("���", grade, num);
			drawitem();
			drawmenu();

			// �������
			gotoxy(32, 17);	printf("���� : ");

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
			gotoxy(70, 18);	printf("���� : %d ��", score);

			// �������߱�
			gotoxy(32, 19);	printf("������ ���� ġ����: ");
			cursor(1);
			timelimit = Htime(grade);
			result = game(timelimit, input, word, scorearray[H][Q_SOLVED],H,0,score);

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
					/*
					timescore(H, TimeBonus(time_left));
					correct(H, score);
					if (O_X[scorearray[H][Q_SOLVED] - 2] == 1)
						combo(H);
					scorearray[H][Q_CORRECT]++;*/
					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					drawline(21, 8, 75, 25);
					draws("���", grade, num);
					drawitem();
					drawmenu();
					gotoxy(32, 17);	printf("���� : %s", word);
					gotoxy(70, 17);	printf("���� : %d ��", score);
					gotoxy(32, 19);	printf("������ ���� ġ����: ");
					timelimit = Htime(grade);
					result = game(timelimit, input, word, scorearray[H][Q_SOLVED],H,0,score);
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
		if (life > 0)
			h_boss();

		end_game = Scorecard(H);
		system("pause");

		/*system("cls");
		Final_Scorecard();
		Sleep(5000);*/
	}

}