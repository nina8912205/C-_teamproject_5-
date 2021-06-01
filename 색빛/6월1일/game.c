#include "common.h"

int time_left = 0; // ���� �ð� ���� ����

// �ܾ� �Է� && �ð� ���� -> ��� ��ȯ(0: ����, 1: ����, 2: �޴� ����, 5: �ܾ� �ٲٱ�)
int game(int n, int timelimit, char* input, char* word, int num_Q, int level, int boss, int score)
{
	extern int item[3], scorearray[SCHSIZE][ASIZE], TotalScore, O_X[];
	char ch;
	int j = 0, start, end, result, sec = 1;
	int k = 0, i;

	input[0] = '\0';

	cursor(0);
	gotoxy(28, 14); printf("�� TIME�� ");
	for (int i = 0; i < timelimit; i++)
		printf("��");
	
	start = time(0);   // ���� �ð�

	while (1)
	{	
		if (time(0) == start + sec)
		{
			cursor(0);
			gotoxy(28, 14); printf("�� TIME�� ");
			for (i = 0; i < timelimit - sec; i++)
				printf("��");
			for (i = timelimit - sec; i < timelimit; i++)
				printf("��");
			printf("\n");
			sec++;

			if (sec > timelimit)   // �г⺰ ���� �ð��� ���״°�?
			{
				result = 0;
				timeover();
				decrease_life(item);
				Sleep(1500);
				system("cls");
				break;
			}
		}

		if (_kbhit()) // ����ڰ� Ű�� �����°�?
		{
			cursor(1);
			gotoxy(n + k, 27); 
			ch = _getch();
			if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9') || ch == QUOTATION || ch == COMMA || ch == SPACE || ch == APOSTROPHE || ch == PERIOD)
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
				k++;
			}
			else if (ch == ESC) // ESC������ �޴��� 
			{
				result = menu();
				break;
			}
			
			else if (ch == BACKSPACE && j > 0)
			{
				printf("\b \b"); // �Է��Ѱ� �����
				j--;
				k--;
				input[j] = '\0';
			}

			else if (ch == TAB && item[CHANGEWORD] > 0)
			{
				item[CHANGEWORD]--; // changeword ����
				result = 5;
				return result;
			}
			else if (ch == ENTER)
			{
				input[j] = NULL;
				if (!strcmp(word, input)) { //����
					result = 1;					
					end = time(0);
					time_left += TimeLeft(timelimit, start, end); // �����ִ� �ð� ���
					switch (level)
					{
					case E:
						if (boss)
						{
							boss_correct(E, score);
							boss_time(E, TimeBonus(time_left));
							if (O_X[scorearray[E][B_Q_SOLVED] - 2] == 1)//////�̰� ������???
								boss_combo(E);
						}
						else
						{
							timescore(E, TimeBonus(time_left));
							correct(E, score);
							if (O_X[scorearray[E][Q_SOLVED] - 2] == 1)
								combo(E);
							scorearray[E][Q_CORRECT]++;
						}
						break;
					case M:
						if (boss)
						{
							boss_correct(M, score);
							boss_time(M, TimeBonus(time_left));
							if (O_X[scorearray[M][B_Q_SOLVED] - 2] == 1)//////�̰� ������???
								boss_combo(M);

						}
						else
						{
							timescore(M, TimeBonus(time_left));
							correct(M, score);
							if (O_X[scorearray[M][Q_SOLVED] - 2] == 1)
								combo(M);
							scorearray[M][Q_CORRECT]++;
						}
						break;
					case H:
						if (boss)
						{
							boss_correct(H, score);
							boss_time(H, TimeBonus(time_left));
							if (O_X[scorearray[H][B_Q_SOLVED] - 2] == 1)//////�̰� ������???
								boss_combo(H);

						}
						else
						{
							timescore(H, TimeBonus(time_left));
							correct(H, score);
							if (O_X[scorearray[H][Q_SOLVED] - 2] == 1)
								combo(H);
							scorearray[H][Q_CORRECT]++;
						}
						break;
					}
					gotoxy(76, 10);	printf("�� SCORE�� %010d", TotalScore);
					gotoxy(76, 12);	printf("+ �ð� ���ʽ�( %d ��)", TimeLeft(timelimit, start, end));
					gotoxy(76, 13);
					if (combo_print(num_Q) != 0)
						printf("%d COMBO", combo_print(num_Q));
					perfect();
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