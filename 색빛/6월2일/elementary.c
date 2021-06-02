#include "common.h"

int O_X[MAX_Q] = { 0 }; 
char sch[SCHSIZE][SIZE] = { "�ʵ�","��","���" };

void elementary(int n)
{
	extern int item[3], gobackstart, end_game;
	extern int scorearray[SCHSIZE][ASIZE], TotalScore;

	char word[SIZE], input[SIZE];
	int grade;
	int result;

	gobackstart = 0;
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
		for (int num = 1; num <= 2; num++) 
		{
			if ((item[LIFE]) == 0)
				break;

			/*gotoxy(32, 24);	printf("total: %d, e_time: %d", TotalScore, scorearray[E][TIME]);
			gotoxy(32, 25);	printf("e_correct: %d, e_combo: %d", scorearray[E][CORRECT], scorearray[E][COMBO]);*/
			
			// ���̾ƿ�						
			layout(E, grade, num);
			
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
			result = game(61 - grade, input, word, E, grade, 0);

			// �ܾ� �ٲٱ� ����
			if (result == 5)
			{
				num--;
				continue;
			}

			while (1)
			{
				if (result == 2) // �޴����� ���ƿ�����
				{
					// ���� �ٽ� ���
					layout(E, grade, num);
					gotoxy(61 - grade, 19);	printf("%s", word);
					result = game(61 - grade, input, word, E, grade, 0);
				}
				if (result == 4)
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