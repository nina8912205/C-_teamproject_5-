//############ ���� - ���� ���� ��������ϴ�.
#include "common.h"

int e_total_score = 0; //############ ���� -  �ʹ� �� ���� �̸� �ٲ� && score���� �Űܿ���.

int O_X[MAX_Q] = { 0 }; //############ ���� - �ϴ� ���⼭ ���̱淡 �����ߴµ�, ���������� �����ص� �� �� ����.

void elementary(int n) // elementary(0): ó������, elementary(1): ó���ƴ�.
{
	extern int life, changeword, addtime;
	extern int time_left;

	char word[SIZE], input[SIZE];
	int grade, score = 0, num_Q = 1;
	int timelimit, result;
	int O = 0;      //############ ���� - �����(5/22)�� ���� ���� �̸��� �����߽��ϴ�.
	int e_score = 0, time_bonus = 0;  // e_score: �⺻ ����
	int combo_bonus = 0, boss_score = 0; // ����ǥ�� ���
	int go; // ���� �ܰ��

	if (!n)
	{
		drawline();
		get_name();       // �̸� �ޱ�
		system("cls");
	}


	drawline();       // ���̾ƿ� �׸���

	item_random(3);    // ������ �̱�
	system("cls");


	for (grade = 1; grade <= 6; grade++) //############ ���� - �г� ���� ���� (i -> grade)
	{
		score = grade * 1000; // �г� �� ����

		// ��� �˻�
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++) //############ ���� - ���� ��ȣ ���� ���� (j -> num)
		{
			// ���̾ƿ�
			drawline();
			draws("�ʵ�", grade, num, e_total_score);
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
			gotoxy(70, 17);
			printf("���� : %d ��", score);

			// �������߱�
			gotoxy(32, 19);
			printf("������ ���� ġ����: ");
			cursor(1);
			timelimit = Etime(grade);	// �ʵ��б� ���ѽð� ��ȯ
			result = game(grade, timelimit, input, word);// �ܾ� �Է� �ޱ� & ���� �ð��� ������ �Ѿ��

			// result 0: ����, 1: ����, 2: �޴������� 
			while (1)
			{
				if (result == 1)
				{
					e_score += score;
					O++;
					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					drawline();
					draws("�ʵ�", grade, num, e_score);
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("���� : %s", word);
					gotoxy(70, 17);
					printf("���� : %d ��", score);

					gotoxy(32, 19);
					printf("������ ���� ġ����: ");
					timelimit = Etime(grade);
					result = game(grade, timelimit, input, word);
				}
				else
					break;
			}

			// ����ǥ ���(0: ����, 1: ����/ ����(result==2)��� �ݺ������� �� ����)
			O_X[num_Q - 1] = result;
			num_Q++;

			// �ð� ���ʽ� ���
			time_bonus = TimeBonus(time_left);

			e_total_score = time_bonus + e_score; //############ ���� - ��ܹ� ������ ���� ���
		}

	}

	// ����� ���� ���, �ʵ��б� ����!
	if (life > 0)
		boss_score = e_boss(e_score);

	// �޺� ���ʽ� ���
	combo_bonus = ComboBonus(Combo_num(--num_Q));

	// �ð� ���ʽ� ���
	time_bonus = TimeBonus(time_left);

	// ����ǥ ���
	go = Scorecard(ELEMENTARY, e_score, time_bonus, combo_bonus, boss_score, num_Q, O);
	e_total_score = e_score + combo_bonus + time_bonus + boss_score; //############ ���� - ���� ����ǥ�� ���� ���

	// ���� �ܰ��
	if (go)
		middle(1);
}