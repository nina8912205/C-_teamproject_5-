#include "common.h"


// ����[x: �Է� ���� ��ġ, level: �б�/���� ����, grade: �г�, i: �����ۻ��(����)]
int game(int x, char* input, char* word, int level, int grade, int u)
{
	extern int item[3], SCORE[SCHSIZE][ASIZE], TotalScore, O_X[];
	char ch;
	int j = 0, start, end, result, sec = 1;
	int k = 0, i;
	int timelimit, score;

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
		SCORE[level][B_Q_SOLVED]++;
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
				result = Wrong;
				timeover();
				decrease_life(item);
				Sleep(1500);
				system("cls");
				break;
			}
		}

		if (_kbhit()) // Ű �Է� ����
		{
			cursor(1);
			gotoxy(x + k, 27);
			ch = _getch();
			if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9') || ch == QUOTATION || ch == COMMA || ch == SPACE || ch == APOSTROPHE || ch == PERIOD)
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
					result = Right;
					end = time(0);

					if (level == T)
					{
						switch (grade)
						{
						case E: 
							level = E;
							break;
						case M: 
							level = M;
							break;
						case H: 
							level = H;
							break;
						}
						boss_correct(level, score);
						boss_time(level, TimeBonus(TimeLeft(timelimit, start, end)));
						if (O_X[SCORE[level][B_Q_SOLVED] - 2] == 1)
							boss_combo(level);
						SCORE[level][B_Q_CORRECT]++;
						gotoxy(76, 13);
						if (combo_print(SCORE[level][B_Q_SOLVED]) != 0)
							printf("%d COMBO", combo_print(SCORE[level][B_Q_SOLVED]));
					}
					else
					{
						correct(level, score);
						timescore(level, TimeBonus(TimeLeft(timelimit, start, end)));
						if (O_X[SCORE[level][Q_SOLVED] - 2] == 1)
							combo(level);
						SCORE[level][Q_CORRECT]++;
						gotoxy(76, 13);
						if (combo_print(SCORE[level][Q_SOLVED]) != 0)
							printf("%d COMBO", combo_print(SCORE[level][Q_SOLVED]));
					}

					// ��� ��� �� ���� ����
					gotoxy(76, 10);	printf("�� SCORE�� %010d", TotalScore);
					gotoxy(76, 12);	printf("+ �ð� ���ʽ�( %d ��)", TimeLeft(timelimit, start, end));
					gotoxy(76, 13);
					perfect();
				}
				else {  //����
					result = Wrong;
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
	Sleep(1000);
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