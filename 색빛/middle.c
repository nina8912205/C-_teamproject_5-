#include "common.h"

int m_total_score = 0; 

void middle(int n) // middle(0): ó������, middle(1): ó���ƴ�.
{
	extern int O_X[];
	extern int life, changeword, addtime;
	extern int time_left;

	time_left = 0;  // �����ð� �ʱ�ȭ

	char word[SIZE], input[SIZE];
	int grade, score = 0, num_Q = 1;
	int timelimit, result;
	int O = 0;      
	int m_score = 0, time_bonus = 0; 
	int combo_bonus = 0, boss_score = 0; 
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
			// ���̾ƿ�
			drawline();
			draws("��", grade, num, m_score);
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
			gotoxy(70, 17);
			printf("���� : %d ��", score);

			// �������߱�
			gotoxy(32, 19);
			printf("������ ���� ġ����: ");
			cursor(1);
			timelimit = Mtime(grade);
			result = game(7, timelimit, input, word);

			// result 0: ����, 1: ����, 2: �޴�������
			while (1)
			{
				if (result == 1)
				{
					m_score += score;
					O++;
					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					drawline();
					draws("��", grade, num, m_score);
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("���� : %s", word);
					gotoxy(70, 17);
					printf("���� : %d ��", score);

					gotoxy(32, 19);
					printf("������ ���� ġ����: ");
					timelimit = Mtime(grade);
					result = game(7, timelimit, input, word);
				}
				else
					break;
			}

			// ����ǥ ���
			O_X[num_Q - 1] = result;
			num_Q++;
		}
	}

	// ����� ���� ���, ���б� ����!
	/*if (life > 0)
		boss_score = m_boss();*/

	// �޺� ���ʽ� ���
	combo_bonus = ComboBonus(Combo_num(--num_Q));

	// �ð� ���ʽ� ���
	time_bonus = TimeBonus(time_left);

	// ����ǥ ���
	go = Scorecard(MIDDLE, m_score, time_bonus, combo_bonus, boss_score, num_Q, O);

	// ���� �ܰ�
	/*if (go)
		high(1);
	else
		game_title();*/

}