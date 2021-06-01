
#include "common.h"

int time_left = 0; // ���� �ð� ���� ����

// �ܾ� �Է� && �ð� ���� -> ��� ��ȯ(0: ����, 1: ����, 2: �޴� ����, 5: �ܾ� �ٲٱ�)
int game(int timelimit, char* input, char* word, int num_Q, int level, int boss,int score) //boss=0�̸� ����X, boss=1�̸� ����
{
	extern int changeword;
	extern int scorearray[SCHSIZE][ASIZE], TotalScore;
	extern int O_X[];
	char ch;
	int j = 0, start, end, result, sec = 1;
	int k = 0, i;

	input[0] = '\0';

	cursor(0);
	
	gotoxy(30, 15); printf("[���� �ð�] ");
	for (int i = 0; i < timelimit; i++)
		printf("��");
	
	start = time(0);   // ���� �ð�

	while (1)
	{	
		if (time(0) == start + sec)
		{
			cursor(0);
			gotoxy(30, 15); printf("[���� �ð�] ");
			for (i = 0; i < timelimit - sec; i++)
				printf("��");
			for (i = timelimit - sec; i < timelimit; i++)
				printf("��");
			printf("\n");
			sec++;

			if (sec > timelimit)   // �г⺰ ���� �ð��� ���״°�?
			{
				result = 0;
				cursor(0);
				gotoxy(32, 21);	printf("TIME OVER!");
				gotoxy(32, 22);	printf("����� �ϳ� �����˴ϴ�");

				decrease_life();

				Sleep(1500);
				system("cls");
				break;
			}
		}

		if (_kbhit()) // ����ڰ� Ű�� �����°�?
		{
			cursor(1);
			gotoxy(52 + k, 19); 
			ch = _getch();
			/*if (ch != ESC && ch != BACKSPACE && ch != TAB && ch != ENTER)*/
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

			else if (ch == TAB && changeword > 0)
			{
				changeword--; // changeword ����
				result = 5;
				return result;
			}
			else if (ch == ENTER)
			{
				input[j] = NULL;
				if (!strcmp(word, input)) { //����
					result = 1;
					cursor(0);
					gotoxy(32, 21);	printf("PERFECT!\n");
					end = time(0);
					time_left += TimeLeft(timelimit, start, end); // �����ִ� �ð� ���
					switch (level)
					{
					case E:
					{
						if (boss)
						{
							boss_correct(E, E_Bscore);
							boss_time(E, TimeBonus(time_left));
							if (O_X[scorearray[E][B_Q_SOLVED] - 2] == 1)//////�̰� ������???
								boss_combo(E);
							
						}
						else if(!boss)
						{
							timescore(E, TimeBonus(time_left));
							correct(E, score);
							if (O_X[scorearray[E][Q_SOLVED] - 2] == 1)
								combo(E);
							scorearray[E][Q_CORRECT]++;	
						}
						break;
					}
					case M:
					{
						if (boss)
						{
							boss_correct(M, M_Bscore);
							boss_time(M, TimeBonus(time_left));
							if (O_X[scorearray[M][B_Q_SOLVED] - 2] == 1)//////�̰� ������???
								boss_combo(M);

						}
						else if(!boss)
						{
							timescore(M, TimeBonus(time_left));
							correct(M, score);
							if (O_X[scorearray[M][Q_SOLVED] - 2] == 1)
								combo(M);
							scorearray[M][Q_CORRECT]++;
						}
						break;
					}
					case H:
					{
						if (boss)
						{
							boss_correct(H, H_Bscore);
							boss_time(H, TimeBonus(time_left));
							if (O_X[scorearray[H][B_Q_SOLVED] - 2] == 1)//////�̰� ������???
								boss_combo(H);

						}
						else if(!boss)
						{
							timescore(H, TimeBonus(time_left));
							correct(H, score);
							if (O_X[scorearray[H][Q_SOLVED] - 2] == 1)
								combo(H);
							scorearray[H][Q_CORRECT]++;
						}
						break;
					}

					}
					gotoxy(76, 10);	printf("�� SCORE�� %010d", TotalScore);
					gotoxy(76, 12);	printf("+ �ð� ���ʽ�( %d ��)", TimeLeft(timelimit, start, end));
					gotoxy(76, 13);
					if (combo_print(num_Q) != 0)
						printf("%d COMBO", combo_print(num_Q));
				}
				else {  //����
					result = 0;
					cursor(0);
					gotoxy(32, 21);	printf("��!\n");
					gotoxy(32, 22);	printf("����� �ϳ� �����˴ϴ�.");
					decrease_life();
				}
				Sleep(3000);
				system("cls");
				break;
			}	
			else
			{
				cursor(0);
				gotoxy(27, 13); printf("[�Է��� ���� �ʴ´ٸ� ��/�� Ű�� ����������!");
			}
		}
	}
	return result;
}