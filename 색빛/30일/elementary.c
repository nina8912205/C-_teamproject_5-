#include "common.h"

int O_X[MAX_Q] = { 0 }; 

void elementary(int n) // elementary(0): ó������, elementary(1): ó���ƴ�.
{
	extern int life, changeword, addtime, gobackstart, end_game;
	extern int time_left, scorearray[SCHSIZE][ASIZE], TotalScore;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;

	gobackstart = 0;
	time_left = 0;
	resetScore(E);
	resetOX();
	
	if (!n) {
		get_name();       // �̸� �ޱ�
		system("cls");
	}
	
	welcome(E);

	drawline(21, 8, 75, 25);     // ���̾ƿ� �׸���

	item_random(3);    // ������ �̱�
	system("cls");

	for (grade = 1; grade <= 1; grade++) 
	{
		score = grade * 1000; // �г� �� ����

		// ��� �˻�
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++) 
		{
			gotoxy(32, 24);	printf("total: %d, e_time: %d", TotalScore, scorearray[E][TIME]);
			gotoxy(32, 25);	printf("e_correct: %d, e_combo: %d", scorearray[E][CORRECT], scorearray[E][COMBO]);
			scorearray[E][Q_SOLVED]++;

			// ���̾ƿ�
			drawline(21, 8, 75, 25);
			draws("�ʵ�", grade, num);
			drawitem();
			drawmenu();

			// �������
			gotoxy(32, 17);	printf("���� : ");

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
			gotoxy(70, 15);
			printf("[����] %d ��", score);

			// �������߱�
			gotoxy(32, 19);
			printf("������ ���� ġ����: ");
			cursor(1);
			timelimit = Etime(grade);	// �ʵ��б� ���ѽð� ��ȯ
			result = game(timelimit, input, word, scorearray[E][Q_SOLVED]);// �ܾ� �Է� �ޱ� & ���� �ð��� ������ �Ѿ��

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
					timescore(E, TimeBonus(time_left));
					correct(E, score);
					if (O_X[scorearray[E][Q_SOLVED] - 2] == 1)
					{
						combo(E);
					}
					scorearray[E][Q_CORRECT]++;//���� ������ ���
					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					drawline(21, 8, 75, 25);
					draws("�ʵ�", grade, num);
					drawitem();
					drawmenu();
					gotoxy(32, 17);	printf("���� : %s", word);
					gotoxy(70, 17);	printf("���� : %d ��", score);
					gotoxy(32, 19);	printf("������ ���� ġ����: ");
					timelimit = Etime(grade);
					result = game(timelimit, input, word, scorearray[E][Q_SOLVED]);
				}
				else if (result == 4)
				{
					gobackstart = 1;
					break;
				}
				else
					break;
				draws("�ʵ�", grade, num);
			}
			if (gobackstart)
				break;

			// ����ǥ ���(0: ����, 1: ����/ ����(result==2)��� �ݺ������� �� ����)
			O_X[scorearray[E][Q_SOLVED] - 1] = result;
			
		}
		if (gobackstart)
			break;
	}

	if (!gobackstart) {
		// ����� ���� ���, �ʵ��б� ����!
		if (life > 0)
			e_boss();

		end_game = Scorecard(E);

		// ���� �ܰ��
		if (life && end_game)
			middle(1);
	}	
}