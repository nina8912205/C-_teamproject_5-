#include "common.h"

int O_X[MAX_Q] = { 0 }; 
int E_num_Q;
int E_O;

void elementary(int n) // elementary(0): ó������, elementary(1): ó���ƴ�.
{
	extern int life, changeword, addtime;
	extern int time_left, e_score[], TotalScore;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;
	int go = 0; // ���� �ܰ��

	if (!n)
	{
		get_name(ELEMENTARY);       // �̸� �ޱ�
		system("cls");
	}

	drawline(21, 8, 75, 25);     // ���̾ƿ� �׸���

	item_random(3);    // ������ �̱�
	system("cls");

	for (grade = 1; grade <= 6; grade++) 
	{
		score = grade * 1000; // �г� �� ����

		// ��� �˻�
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++) 
		{
			gotoxy(32, 24);
			printf("total: %d, e_time: %d", TotalScore, e_score[TIME]);
			gotoxy(32, 25);
			printf("e_correct: %d, e_combo: %d", e_score[CORRECT], e_score[COMBO]);
			E_num_Q++;

			// ���̾ƿ�
			drawline(21, 8, 75, 25);
			draws("�ʵ�", grade, num);
			drawitem();
			drawmenu();

			// �������
			gotoxy(32, 17);
			printf("���� : ");

			switch (grade) // �г⺰ ���� ���
			{
			case 1:
			case 2:
				random_word(grade, word); // 1~2�г�: ���� ���ڿ�
				break;
			case 3:
				if (rand() % 2 == 0)
					word_3(word);
				else
					random_word(grade, word); // 3�г�: 3���� �ܾ� or ���� ���ڿ�
				break;
			case 4:
				if (rand() % 2 == 0)
					word_4(word);
				else
					random_word(grade, word); // 4�г�: 4���� �ܾ� or ���� ���ڿ�
				break;
			case 5:
				if (rand() % 2 == 0)
					word_5(word);
				else
					random_word(grade, word); // 5�г�: 5���� �ܾ� or ���� ���ڿ�
				break;
			case 6:
				if (rand() % 2 == 0)
					word_6(word);
				else
					random_word(grade, word); // 6�г�: 6���� �ܾ� or ���� ���ڿ�
				break;
			}
			gotoxy(32, 15);
			printf("���� : %d �� / ���ѽð�: %d ��", score, Etime(grade));

			// �������߱�
			gotoxy(32, 19);
			printf("������ ���� ġ����: ");
			cursor(1);
			timelimit = Etime(grade);	// �ʵ��б� ���ѽð� ��ȯ
			result = game(grade, timelimit, input, word, E_num_Q);// �ܾ� �Է� �ޱ� & ���� �ð��� ������ �Ѿ��

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
					timescore(ELEMENTARY, TimeBonus(time_left));
					correct(ELEMENTARY, score);
					if (O_X[E_num_Q - 2] == 1)
					{
						combo(ELEMENTARY);
					}
					E_O++;//���� ������ ���

					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					drawline(21, 8, 75, 25);
					draws("�ʵ�", grade, num);
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("���� : %s", word);
					gotoxy(70, 17);
					printf("���� : %d ��", score);

					gotoxy(32, 19);
					printf("������ ���� ġ����: ");
					timelimit = Etime(grade);
					result = game(grade, timelimit, input, word, E_num_Q);
				}
				else
					break;
				draws("�ʵ�", grade, num);
			}

			// ����ǥ ���(0: ����, 1: ����/ ����(result==2)��� �ݺ������� �� ����)
			O_X[E_num_Q - 1] = result;
			
		}
	}

	// ����� ���� ���, �ʵ��б� ����!
	if (life > 0)
		e_boss();

	go = Scorecard(ELEMENTARY);
	

	// ���� �ܰ��
	if (go)
		middle(1);
}