#include "common.h"

int M_num_Q;
int M_O;

void middle(int n) // middle(0): ó������, middle(1): ó���ƴ�.
{
	resetOX();
	extern int O_X[];
	extern int life, changeword, addtime;
	extern int time_left;
	extern int m_score[];
	extern int TotalScore;
	time_left = 0;  // �����ð� �ʱ�ȭ

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;

	int go;

	if (!n)
	{
		drawline();
		get_name();
		system("cls");
	}

	drawline();       // ���̾ƿ� �׸���

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
			printf("total: %d, e_time: %d", TotalScore, m_score[time_bonus]);
			gotoxy(32, 25);
			printf("m_correct: %d, m_combo: %d", m_score[correct_score], m_score[combo_bonus]);
			M_num_Q++;
			// ���̾ƿ�
			drawline();
			draws("��", grade, num);///����???????????
			drawitem();
			drawmenu();

			// �������
			gotoxy(32, 17);
			printf("���� : ");

			switch (grade) // �г⺰ ���� ���
			{
			case 1:                    // 1�г�: 7���� ���ܾ�
				word_7(word);
				break;
			case 2:                    // 2�г�: ���� ���ڿ�(7����)
				random_word(7, word);
				break;
			case 3:                    // 3�г�: ª�� ��
				random_word(7, word);
				break;
			}
			//******* 5/24(����) - ���ѽð� ��� �߰�, ���̾ƿ� �߾ǰ� ����
			gotoxy(32, 15);
			printf("���� : %d �� / ���ѽð�: %d ��", score, Mtime(grade));


			// �������߱�
			gotoxy(32, 19);
			printf("������ ���� ġ����: ");
			cursor(1);
			timelimit = Mtime(grade);
			result = game(7, timelimit, input, word,M_num_Q);

			// result 0: ����, 1: ����, 2: �޴�������
			while (1)
			{
				if (result == 1)
				{
					timescore(MIDDLE, TimeBonus(time_left));
					correct(MIDDLE, score);
					if (O_X[M_num_Q - 2] == 1)
					{
						combo(MIDDLE);
					}
					
					M_O++;
					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					drawline();
					draws("��", grade, num);/////?????����
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("���� : %s", word);
					gotoxy(70, 17);
					printf("���� : %d ��", score);

					gotoxy(32, 19);
					printf("������ ���� ġ����: ");
					timelimit = Mtime(grade);
					result = game(7, timelimit, input, word, M_num_Q);
				}
				else
					break;
			}

			// ����ǥ ���
			O_X[M_num_Q - 1] = result;
			
		}
	}

	// ����� ���� ���, ���б� ����!
	/*if (life > 0)
		boss_score = m_boss();*/
	/*
		// �޺� ���ʽ� ���
	combo_bonus = ComboBonus(Combo_num(--num_Q));

	// �ð� ���ʽ� ���
	time_bonus = TimeBonus(time_left);*/

	// ����ǥ ���
	go = Scorecard(MIDDLE);

	// ���� �ܰ�
	/*if (go)
		high(1);
	else
		game_title();*/

}