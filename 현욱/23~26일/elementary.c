//############ ���� - ���� ���� ��������ϴ�.
#include "common.h"


///���������� ���� �����ص� ���� �ֽ��ϴ�*******5/26 ����
int O_X[MAX_Q] = { 0 }; //############ ���� - �ϴ� ���⼭ ���̱淡 �����ߴµ�, ���������� �����ص� �� �� ����.
int E_num_Q;//�ʵ��б� Ǭ ������ ���
int E_O;	//�ʵ��б� ���� ������(��������)

void elementary(int n) // elementary(0): ó������, elementary(1): ó���ƴ�.
{
	resetOX(); //���� �ٽ� ������ ��츦 ����� ����ǥ �ʱ�ȭ, ��� ��������� ���� �ϳ� �޺� ������ Ȥ�ø� ���� ����****5/26 ����
	

	extern int life, changeword, addtime;
	extern int time_left;
	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;
	extern int total_score,e_total_score, e_correct_score, e_time_bonus, e_combo_bonus, eboss_total_score;	////���� ȣ��****5/26����
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
			//����Ȯ�ο�///*******5/26 ����
			gotoxy(32, 24);
			printf("total: %d, e_time: %d", total_score, e_time_bonus);
			extern int m_combo_bonus;
			gotoxy(32, 25);
			printf("e_correct: %d, e_combo: %d m_combo: %d", e_correct_score, e_combo_bonus, m_combo_bonus);
			//////////////

			E_num_Q++;/////////���� �� ���****5/26����
			
			// ���̾ƿ�
			drawline();
			draws("�ʵ�", grade, num);//////draws �μ� ����
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
			//******* 5/24(����) - ���ѽð� ��� �߰�, ���̾ƿ� �߾ǰ� ����
			gotoxy(32, 15);
			printf("���� : %d �� / ���ѽð�: %d ��", score, Etime(grade));

			// �������߱�
			gotoxy(32, 19);
			printf("������ ���� ġ����: ");
			cursor(1);
			timelimit = Etime(grade);	// �ʵ��б� ���ѽð� ��ȯ
			result = game(grade, timelimit, input, word,E_num_Q);// �ܾ� �Է� �ޱ� & ���� �ð��� ������ �Ѿ��//////************5/26���� - game() �Լ� �μ� ����

			// result 0: ����, 1: ����, 2: �޴������� 
			while (1)
			{
				if (result == 1) //����-�����ݿ���� ����************5/26 ����
				{	
					time_bonus(ELEMENTARY, TimeBonus(time_left));
					correct_score(ELEMENTARY, score);
					if (O_X[E_num_Q - 2] == 1)
					{	
						//test//
						/*extern int e_combo_bonus, e_total_score, total_score;
						e_combo_bonus += BonusPerCombo;
						e_total_score += BonusPerCombo;
						total_score += BonusPerCombo;*/
						combo_bonus(ELEMENTARY);
					}
					
					E_O++;//���� ������ ���

					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					drawline();
					draws("�ʵ�", grade, num);////////****draws() �Լ� �μ� ����*****5/26����
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("���� : %s", word);
					gotoxy(70, 17);
					printf("���� : %d ��", score);

					gotoxy(32, 19);
					printf("������ ���� ġ����: ");
					timelimit = Etime(grade);
					result = game(grade, timelimit, input, word, E_num_Q);/////////*****game()�Լ��μ�����******5/26����
				}
				else
					break;
			}

			
			// ����ǥ ���(0: ����, 1: ����/ ����(result==2)��� �ݺ������� �� ����)
			O_X[E_num_Q - 1] = result;
			
			
			
		}

	}

	// ����� ���� ���, �ʵ��б� ����!
	if (life > 0)
		e_boss();
	/*************5/26���� - ���� ��� ������ ��� ó��
	// �޺� ���ʽ� ���
	combo_bonus = ComboBonus(Combo_num(--num_Q));

	// �ð� ���ʽ� ���
	time_bonus = TimeBonus(time_left);*/

	// ����ǥ ���******�μ� ����(5/26����)
	go = Scorecard(ELEMENTARY);

	// ���� �ܰ��
	if (go)
		middle(1);
}