#include "common.h"


// ����[x: �Է� ���� ��ġ, level: �б�, grade: �г�, i: �����ۻ��(����)]
int game(int x, char* input, char* word, int level, int grade, int u)
{
	extern int item[3], SCORE[SCHSIZE][ASIZE], TotalScore, O_X[];
	char ch;
	int j = 0, start, end, result, sec = 1;
	int k = 0, i;
	int timelimit, score, timeleft = 0;

	input[0] = '\0';

	// ����, ���ѽð� ���
	timelimit = timeboard(level, grade);
	score = scoreboard(level, grade);

	if (level == T)
		timelimit += u;
	// ���ѽð� ���
	cursor(0);
	gotoxy(28, 14); printf("�� TIME�� ");
	for (int i = 0; i < timelimit; i++)
		printf("��");
	start = time(0);   // ���� �ð�

	if (level == T)
		SCORE[grade][B_Q_SOLVED]++;
	else
		SCORE[level][Q_SOLVED]++;

	while (1)
	{
		if (time(0) == start + sec)
		{
			// 1�ʸ��� ���� �ð� ǥ�� (�� �� ��)
			cursor(0);
			gotoxy(28, 14); printf("�� TIME�� ");
			for (i = 0; i < timelimit - sec; i++)
				printf("��");
			for (i = timelimit - sec; i < timelimit; i++)
				printf("��");
			printf("\n");
			sec++;

			// ���ѽð� �ʰ�
			if (sec > timelimit)
			{
				result = 0;
				timeover();
				decrease_life(item);
				Sleep(1500);
				break;
			}
		}

		if (_kbhit()) // Ű �Է� ����
		{
			cursor(1);
			gotoxy(x + k, 27);
			ch = _getch();
			if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9') || ch == QUOTATION || ch == COMMA || ch == SPACE || ch == APOSTROPHE || ch == PERIOD || ch == QUESTION)
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
				k++;
			}
			else if (ch == ESC) // ESC: �޴� ���
			{
				result = menu();
				break;
			}
			else if (ch == BACKSPACE && j > 0) // BACKSPACE: �����
			{
				printf("\b \b");
				j--;
				k--;
				input[j] = '\0';
			}
			else if (ch == TAB && item[CHANGEWORD] > 0) // TAB: �ܾ� �ٲٱ�
			{
				item[CHANGEWORD]--;
				result = WORDITEM;
				return result;
			}
			else if (ch == ENTER) // ENTER: �Է� ��� ����
			{
				input[j] = NULL;
				if (!strcmp(word, input)) { // ����
					result = 1;
					end = time(0);
					timeleft = TimeLeft(timelimit, start, end);

					if (level == T)
					{
						add_test_score(grade, B_CORRECT, score);
						add_test_score(grade, B_TIME, TimeBonus(timeleft));
						if (O_X[SCORE[grade][B_Q_SOLVED] - 2] == 1)
							add_test_score(grade, B_COMBO, BonusPerCombo);
						SCORE[grade][B_Q_CORRECT]++;
					}
					else
					{
						addscore(level, CORRECT, score);
						addscore(level, TIME, TimeBonus(timeleft));
						if (O_X[SCORE[level][Q_SOLVED] - 2] == 1)
							addscore(level, COMBO, BonusPerCombo);
						SCORE[level][Q_CORRECT]++;
					}

					// ��� ��� �� ���� ����
					perfect();
					gotoxy(76, 10);	printf("�� SCORE�� %010d", TotalScore);
					textcolor(2);
					gotoxy(81, 12);	printf("+TIMEBONUS(%d��)", timeleft);
					textcolor(6);
					gotoxy(56, 21);
					if (level == T)
					{
						if (combo_print(SCORE[grade][B_Q_SOLVED]) != 0)
							printf("%d COMBO", combo_print(SCORE[grade][B_Q_SOLVED]));
					}
					else
					{
						if (combo_print(SCORE[level][Q_SOLVED]) != 0)
							printf("%d COMBO", combo_print(SCORE[level][Q_SOLVED]));
					}
					textcolor(15);
					Sleep(1000);
				}
				else {  //����
					result = 0;
					wrong();
					decrease_life(item);
				}
				break;
			}
			else
			{
				cursor(0);
				gotoxy(40, 31); printf("[�Է��� ���� �ʴ´ٸ� ��/�� Ű�� ����������!");
			}
		}
	}
	return result;
}
void perfect()
{
	cursor(0);
	//textcolor(2);
	clear(29, 16, 30, 6);
	gotoxy(35, 16); printf("���    ���  ���    ���  ���  ���  ����  ��\n");
	gotoxy(35, 17); printf("��  ��  ��    ��  ��  ��    ��    ��      ��    ��\n");
	gotoxy(35, 18); printf("���    ���  ���    ���  ���  ��      ��    ��\n");
	gotoxy(35, 19); printf("��      ��    ��  ��  ��    ��    ��      ��\n");
	gotoxy(35, 20); printf("��      ���  ��  ��  ��    ���  ���    ��    ��\n");
}

void timeover()
{
	cursor(0);
	//textcolor(2);
	clear(29, 16, 30, 6);
	gotoxy(32, 16); printf("����  ��  ��  ��  ���      ��    ��  ��  ���  ���\n");
	gotoxy(32, 17); printf("  ��    ��  ����  ��      ��  ��  ��  ��  ��    ��  ��\n");
	gotoxy(32, 18); printf("  ��    ��  ��  ��  ���    ��  ��  ��  ��  ���  ���\n");
	gotoxy(32, 19); printf("  ��    ��  ��  ��  ��      ��  ��  ��  ��  ��    ��  ��\n");
	gotoxy(32, 20); printf("  ��    ��  ��  ��  ���      ��      ��    ���  ��  ��\n");
	Sleep(1000);
}

void wrong()
{
	cursor(0);
	//textcolor(2);
	clear(29, 16, 30, 6);
	gotoxy(49, 16); printf("���      ��    ���\n");
	gotoxy(49, 17); printf("��  ��  ��  ��  ��  ��\n");
	gotoxy(49, 18); printf("���    ����  ��  ��\n");
	gotoxy(49, 19); printf("��  ��  ��  ��  ��  ��\n");
	gotoxy(49, 20); printf("���    ��  ��  ���\n");
	Sleep(1000);
}

void gradeup()
{
	cursor(0);
	//textcolor(2);
	clear(29, 16, 30, 6);
	gotoxy(34, 16); printf("  ���  ���     ��    ���    ���    ��  ��  ���\n");
	gotoxy(34, 17); printf("��      ��  �� ��  ��  ��  ��  ��      ��  ��  ��  ��\n");
	gotoxy(34, 18); printf("��  ��  ���   ����  ��  ��  ���    ��  ��  ��� \n");
	gotoxy(34, 19); printf("��  ��  ��  �� ��  ��  ��  ��  ��      ��  ��  ��\n");
	gotoxy(34, 20); printf("���    ��  �� ��  ��  ���    ���    ����  ��\n");
	Sleep(1000);
}