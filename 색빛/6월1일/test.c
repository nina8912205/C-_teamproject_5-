#include "common.h"

#define ETEST 7

void test(int level)
{
	extern int item[3], scorearray[SCHSIZE][ASIZE], gobackstart;
	extern int time_left, TotalScore, O_X[MAX_Q];
	extern char sch[SCHSIZE][SIZE];

	char word[SIZE], input[SIZE];
	int use, num, score;
	int result, timelimit;

	// ����
	
	resetOX();
	timelimit = Ttime(level);
	
	// ���̾ƿ�
	system("cls");
	drawline(21, 8, 75, 25);

	// ���� ���丮
	gotoxy(32, 15);	printf("�����մϴ�");
	Sleep(1000);
	gotoxy(32, 17);	printf("%s�б� ���������� ������ ���ƽ��ϴ�", sch[level]);
	Sleep(1000);
	gotoxy(32, 19);	printf("%s�б� ���� �������� �̱⼼��", sch[level]);
	Sleep(2000);
	system("cls");

	if (item[ADDTIME]) {
		drawline(21, 8, 75, 25);
		drawitem();
		gotoxy(32, 15);	printf("�ð� �߰� �������� �ֽ��ϴ�.");
		Sleep(1000);
		gotoxy(32, 17);	printf("����Ͻðڽ��ϱ�? [y/n]");
		use = _getch();
		switch (use)
		{
		case 'y':
			gotoxy(32, 19); printf("�������� ����մϴ�.");
			Sleep(1000);
			gotoxy(32, 21); printf("���ѽð��� %d�� �þ�ϴ�.", item[ADDTIME]);
			Sleep(1000);
			while (item[ADDTIME])
			{
				item[ADDTIME]--;
				timelimit++;
			}
			break;
		case 'n':
			gotoxy(32, 19);	printf("�������� ������� �ʽ��ϴ�.");
			Sleep(1000);
			break;				
		}
	}
		// ���� ����
	for (num = 1; num <= 5; num++)
	{
		// ��� �˻�
		if ((item[LIFE]) == 0)
			break;

		score = level * 8000;
		boss_layout(level, num, score);
		scorearray[level][B_Q_SOLVED]++;		

		// ���� ����
			
		switch (level)
		{
		case E:
			gotoxy(50, 19);
			random_word(ETEST, word);
			break;
		case M:
			gotoxy(40, 19);
			word_short(word);
			break;
		case H:
			gotoxy(40, 19);
			word_short_h(word);
			break;
		}
		
		// ���� ���߱� & ���
			
		result = game(50, timelimit, input, word, scorearray[level][B_Q_SOLVED], level, 1, score);

		if (result == 5)
		{
			num--;
			continue;
		}
		while (1)
		{
			if (result == 1)
			{
				boss_correct(level, score);
				boss_time(level, TimeBonus(time_left));
				if (O_X[scorearray[level][B_Q_SOLVED] - 2] == 1)
					combo(level);
				scorearray[level][B_Q_CORRECT]++;//���� ������ ���
				break;
			}
			else if (result == 2) // �޴����� ���ƿ�����
			{
				// ���� �ٽ� ���
				boss_layout(level, num, score);
				gotoxy(40, 19);	printf("%s", word);
				timelimit = Ttime(level);
				result = game(40, timelimit, input, word, scorearray[level][B_Q_SOLVED]);
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

		// ����ǥ���
		O_X[scorearray[level][B_Q_SOLVED] - 1] = result;
		system("cls");
	}
}