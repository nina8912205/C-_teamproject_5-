#include "common.h"

int O_X[MAX_Q] = { 0 }; 
char sch[SCHSIZE][SIZE] = { "�ʵ�","��","���" };

void elementary(int n)
{
	extern int item[3], gobackstart, end_game;
	extern int time_left, scorearray[SCHSIZE][ASIZE], TotalScore;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;

	gobackstart = 0;
	time_left = 0;
	resetScore(E);
	resetOX();
	
	if (!n) {
		get_name();       
		system("cls");
	}
	
	welcome(E);
	
	drawline(21, 8, 75, 25);
	
	item_random(3);    
	
	for (grade = 1; grade <= 6; grade++) 
	{
		score = grade * 1000;

		for (int num = 1; num <= 2; num++) 
		{

			if ((item[LIFE]) == 0)
				break;

			/*gotoxy(32, 24);	printf("total: %d, e_time: %d", TotalScore, scorearray[E][TIME]);
			gotoxy(32, 25);	printf("e_correct: %d, e_combo: %d", scorearray[E][CORRECT], scorearray[E][COMBO]);*/
			scorearray[E][Q_SOLVED]++;

			// ���̾ƿ�						
			layout(E, grade, num, score);
			
			// �������
			gotoxy(61 - grade, 19);
			
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
			
			// �������߱�
			timelimit = Etime(grade);	// �ʵ��б� ���ѽð� ��ȯ
			result = game(61 - grade, timelimit, input, word, scorearray[E][Q_SOLVED], E, 0, score);

			// �ܾ� �ٲٱ� ����
			if (result == 5)
			{
				num--;
				continue;
			}

			while (1)
			{
				if (result == 1)
				{
					timescore(E, TimeBonus(time_left));
					correct(E, score);
					if (O_X[scorearray[E][Q_SOLVED] - 2] == 1)
						combo(E);
					scorearray[E][Q_CORRECT]++;//���� ������ ���
					break;
				}
				else if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					layout(E, grade, num, score);
					gotoxy(61 - grade, 19);	printf("%s", word);
					timelimit = Etime(grade);
					result = game(61 - grade, timelimit, input, word, scorearray[E][Q_SOLVED], E, 0, score);
				}
				else if (result == 4)
				{
					gobackstart = 1;
					break;
				}
				else
					break;
			}
			if (gobackstart)
				break;

			// ����ǥ ���
			O_X[scorearray[E][Q_SOLVED] - 1] = result;
			
			
		}
		if (gobackstart)
			break;

		if (item[LIFE] && grade < 6)
			gradeup();
	}

	if (!gobackstart) {
		// ����� ���� ���, �ʵ��б� ����!
		if (item[LIFE])
			test(E);

		end_game = Scorecard(E);

		// ���� �ܰ��
		if (item[LIFE] && end_game)
			middle(1);
	}	
}