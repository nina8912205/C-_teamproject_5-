#include "common.h"

#define ETEST 7

void test(int level)
{
	extern int item[3], scorearray[SCHSIZE][ASIZE], gobackstart;
	extern int TotalScore, O_X[MAX_Q];
	extern char sch[SCHSIZE][SIZE];

	char word[SIZE], input[SIZE];
	int key, addtime = 0, num;
	int result, x;

	// ����
	
	resetOX();
	
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
		key = _getch();
		switch (key)
		{
		case 'y':
			gotoxy(32, 19); printf("�������� ����մϴ�.");
			Sleep(1000);
			gotoxy(32, 21); printf("���ѽð��� %d�� �þ�ϴ�.", item[ADDTIME]);
			Sleep(1000);
			while (item[ADDTIME])
			{
				item[ADDTIME]--;
				addtime++;
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

		test_layout(level, num);	

		// ���� ����
			
		switch (level)
		{
		case E:
			x = 53;
			gotoxy(x, 19);
			random_word(ETEST, word);
			break;
		case M:
			x = 47;
			gotoxy(x, 19);
			word_short(word);
			break;
		case H:
			x = 40;
			gotoxy(x, 19);
			word_short_h(word);
			break;
		}
		
		// ���� ���߱� & ���
			
		result = game(x, input, word, T, level, addtime);

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
				test_layout(level, num);
				gotoxy(x, 19);	printf("%s", word);
				result = game(x, input, word, T, level, addtime);
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

		// ����ǥ���
		O_X[scorearray[level][B_Q_SOLVED] - 1] = result;
		system("cls");
	}
}