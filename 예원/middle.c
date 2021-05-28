/* (5/26)
   - word �� ���ڿ��� ũ�⸦ �ν��ϰ�, �׸�ŭ �Է¹޵��� ����
*/
#include "common.h"
#define MSIZE 7

int M_num_Q;
int M_O;

void middle(int n) // middle(0): ó������, middle(1): ó���ƴ�.
{

	extern int O_X[], m_score[], TotalScore;
	extern int life, changeword, addtime;
	extern int time_left;
	extern int gobackstart;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result, size;
	int go;

	gobackstart = 0; //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ���� : �������� �ʱ�ȭ. �޴����� ����ȭ������ ���ư��� ������ flag = 1 -> for �� break

	time_left = 0;  // �����ð� �ʱ�ȭ
	resetOX();

	if (!n)
	{
		get_name(MIDDLE);
		system("cls");
	}

	drawline(21, 8, 75, 25);       // ���̾ƿ� �׸���

	item_random(5);    // ������ �̱�
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
			printf("total: %d, e_time: %d", TotalScore, m_score[TIME]);
			gotoxy(32, 25);
			printf("m_correct: %d, m_combo: %d", m_score[CORRECT], m_score[COMBO]);
			M_num_Q++;
			// ���̾ƿ�
			drawline(21, 8, 75, 25);
			draws("��", grade, num);
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
				random_word(MSIZE, word);
				break;
			case 3:                    // 3�г�: ª�� ��
				word_short(word);
				break;
			}
			gotoxy(70, 17);
			printf("���� : %d ��", score);

			// �������߱�
			gotoxy(32, 19);
			printf("������ ���� ġ����: ");
			cursor(1);
			size = strlen(word);
			timelimit = Mtime(grade);
			result = game(30, timelimit, input, word, M_num_Q);    

			// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ���� �߰����� �߰�
			//  game�� size ��� 
			// (ª���� �� ���� �� ���� ���� ~ input�� ũ��) �� �ش��ϴ� �� [ex) 30] �� �־�� 
			//  ex) germanyhaha => �̷������� �Է��ϸ� �������� ó���� �˴ϴ�.
			// input �� �ʰ��ϴ� �� [ex) 50] �� ������ debug error.
			//  size�� �μ��� ������
			//  ex) germanyhaha �� size �� �ʰ��Ͽ� �Է��� ���� haha�� input�� ������ �ȵż� �ᱹ�� germany ������ �Է°����� �����ϰ� �˴ϴ�. 
			//  �ᱹ �������� �����ǰ� ��.
			//  ���ս� ȥ���� ����� �ϴ��� 30 �־�����, ���ս� �ٸ� ������ ��ȣ����� �����ø� �˴ϴ�.

			// �ܾ� �ٲٱ� ����
			if (result == 5)
			{
				num--;
				gotoxy(36, 17);                                // @@@@@@@@@@@@@@@@@@ ���� : ��ǥ�̵�
				printf("                                   "); // @@@@@@@@@@@@@@@@@@ ���� :  �ܾ� �ٲٱ� �� ���� ���� �����( high������ ����б����� ���� �� ���ڿ��� �ش��ϴ� ���̸�ŭ space ����ϸ� �˴ϴ�.)
				continue;
			}

			// result 0: ����, 1: ����, 2: �޴�������
			while (1)
			{
				if (result == 1)
				{
					timescore(MIDDLE, TimeBonus(time_left));
					correct(MIDDLE, score);
					if (O_X[M_num_Q - 2] == 1)
						combo(MIDDLE);
					M_O++;
					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					drawline(21, 8, 75, 25);
					draws("��", grade, num);
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("���� : %s", word);
					gotoxy(70, 17);
					printf("���� : %d ��", score);

					gotoxy(32, 19);
					printf("������ ���� ġ����: ");
					timelimit = Mtime(grade);
					result = game(size, timelimit, input, word, M_num_Q);
				}
				else if (result == 4)  // @@@@@@@@@@@@@@@@@@@ ���� : �޴����� ����ȭ�� ����
				{
					gobackstart = 1;   // @@@@@@@@@@@@@@@@@@@ ���� : gobackstart = 1�Ҵ��� ��ø�ݺ��� break
					break;
				}
				else
					break;
			}

			if (gobackstart == 1)  // @@@@@@@@@@@@@@@@@@@ ���� 
				break;

			// ����ǥ ���
			O_X[M_num_Q - 1] = result;

		}
		if (gobackstart == 1)  // @@@@@@@@@@@@@@@@@@@ ���� 
			break;
	}

	if (gobackstart == 1)
		;  // @@@@@@@@@@@@@@@@@@@@@@@@@@@@ ���� :  �ƹ��͵� ���� �ʰ� middle �Լ� ����. -> middle ���� �� main���� �� �ѹ� break;
	else
	{
		// ����� ���� ���, ���б� ����!
			/*if (life > 0)
				m_boss();*/

				// ����ǥ ���
			go = Scorecard(HIGH);
	}
		

}
