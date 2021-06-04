#include "common.h"

#define ETEST 7

void test(int level)
{
	extern int item[], SCORE[SCHSIZE][ASIZE];
	extern int TotalScore, O_X[];
	extern char sch[SCHSIZE][SIZE], name[];

	char word[SIZE], input[SIZE];
	int key, addtime = 0, num;
	int result, x = 0;

	// ����
	
	resetOX();
	
	// ���̾ƿ�
	system("cls");
	KU(2);
	KU(4);
	system("cls");
	drawline(21, 8, 75, 25);

	// ���� ���丮
	
	gotoxy(50, 19);	printf("%s! �����Ѵ�KU!", name);
	Sleep(1500);
	gotoxy(43, 21);	printf("%s�б� ���������� ������ ���ƾ�!", sch[level]);
	Sleep(1500);
	gotoxy(35, 23);	printf("���� %s�б� ���������� ����ϸ� ������ �� �־�!", sch[level]);
	Sleep(1500);
	system("cls");

	if (item[ADDTIME]) {
		drawline(21, 8, 75, 25);
		drawitem();
		gotoxy(43, 17);	printf("[�˸�] �ð� ���� �������� �ֽ��ϴ�.");
		Sleep(1000);
		gotoxy(50, 19);	printf("����Ͻðڽ��ϱ�? [y/n]");
		key = _getch();
		switch (key)
		{
		case 'y':
			gotoxy(50, 21); printf("�������� ����մϴ�.");
			Sleep(1000);
			gotoxy(48, 23); printf("���ѽð��� %d�� �þ�ϴ�.", item[ADDTIME]);
			Sleep(1000);
			while (item[ADDTIME])
			{
				item[ADDTIME]--;
				addtime++;
			}
			break;
		case 'n':
			gotoxy(48, 21);	printf("�������� ������� �ʽ��ϴ�.");
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

		test_layout(level, num);	

		// ���� ����
		SCORE[level][T_Q_SOLVED]++;
		switch (level)
		{
		case E:
			x = 56;
			gotoxy(x, 19);
			random_word(ETEST, word);
			break;
		case M:
			x = 47;
			gotoxy(x, 19);
			word_short(word);
			break;
		case H:
			x = 31;
			gotoxy(x, 19);
			word_short_h(word);
			break;
		}
		
		// ���� ���߱� & ���
			
		result = game(x, input, word, T, level, addtime);

		if (result == WORDITEM)
		{
			num--;
			continue;
		}
		while (1)
		{
			if (result == HOWTOPLAY) // �޴����� ���ƿ�����
			{
				// ���� �ٽ� ���
				test_layout(level, num);
				gotoxy(x, 19);	printf("%s", word);
				result = game(x, input, word, T, level, addtime);
			}
			if (result == STARTMENU || result == CHANGE_LEVEL)
				return;
			else
				break;
		}

		// ����ǥ���
		O_X[SCORE[level][T_Q_SOLVED]] = result;
		system("cls");
	}
}