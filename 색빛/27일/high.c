#include "common.h"

int H_num_Q;
int H_O;

void high(int n) // high(0): ó������, high(1): ó���ƴ�.
{

	extern int O_X[], h_score[], TotalScore;
	extern int life, changeword, addtime;
	extern int time_left;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result, size;
	int go;

	time_left = 0;  // �����ð� �ʱ�ȭ
	resetOX();

	if (!n)
	{
		get_name(MIDDLE);
		system("cls");
	}

	drawline(21, 8, 75, 25);       // ���̾ƿ� �׸���

	item_random(2);    // ������ �̱�
	system("cls");

	for (grade = 1; grade <= 3; grade++)
	{
		score = grade * 3000; // �г� �� ����

		// ��� �˻�
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++)
		{
			gotoxy(32, 24);
			printf("total: %d, e_time: %d", TotalScore, h_score[TIME]);
			gotoxy(32, 25);
			printf("m_correct: %d, m_combo: %d", h_score[CORRECT], h_score[COMBO]);
			H_num_Q++;
			// ���̾ƿ�
			drawline(21, 8, 75, 25);
			draws("���", grade, num);
			drawitem();
			drawmenu();

			// �������
			gotoxy(32, 17);
			printf("���� : ");

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
			gotoxy(70, 17);
			printf("���� : %d ��", score);

			// �������߱�
			gotoxy(32, 19);
			printf("������ ���� ġ����: ");
			cursor(1);
			size = strlen(word);
			timelimit = Htime(grade);
			result = game(size, timelimit, input, word, H_num_Q);

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
					timescore(HIGH, TimeBonus(time_left));
					correct(HIGH, score);
					if (O_X[H_num_Q - 2] == 1)
						combo(HIGH);
					H_O++;
					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					drawline(21, 8, 75, 25);
					draws("���", grade, num);
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("���� : %s", word);
					gotoxy(70, 17);
					printf("���� : %d ��", score);

					gotoxy(32, 19);
					printf("������ ���� ġ����: ");
					timelimit = Htime(grade);
					result = game(size, timelimit, input, word, H_num_Q);
				}
				else
					break;
			}

			// ����ǥ ���
			O_X[H_num_Q - 1] = result;
			
		}
	}

	// ����� ���� ���, ����!
	/*if (life > 0)
		 h_boss();*/

		// ����ǥ ���
	go = Scorecard(MIDDLE);

	// ���� �ܰ�
	/*if (go)
		high(1);
	else
		game_title();*/

}