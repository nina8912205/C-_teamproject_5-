//game.c : ���� ����
/* (5/26)
  �ܾ�ٲٱ� ����(������)
  - spacebar -> tabŰ
  - ���ο� ���� ���� ����
  - �ʵ��б������� ���������� ���������� ���б����� ���� �� �Ǵ� ���� �ذ�
  SPACE �Է� �߰�
*/
#include "common.h"

int time_left = 0; // ���� �ð� ���� ����

// �ܾ� �Է� && �ð� ���� -> ��� ��ȯ(0: ����, 1: ����, 2: �޴� ����, 5: �ܾ� �ٲٱ�)
int game(int size, int timelimit, char* input, char* word, int num_Q)
{
	extern int changeword;
	char ch;
	int j = 0, start, end, result;

	input[0] = '\0';    // @@@@@@@@@@@@@@@@@@@@@@@@@ ���� : input �ʱ�ȭ. �ùٸ��� �Է��ߴµ� Ʋ�ȴٰ� �ϴ� ��찡 �־ game �� ��ȣ�� �� �� input �� �ʱ�ȭ �� �ܿ� ���� ���۴ϴ�. 

	start = time(0);   // ���� �ð�

	while (1)
	{
		if (time(0) == start + timelimit)   // �г⺰ ���� �ð��� ���״°�?
		{
			result = 0;
			cursor(0);
			gotoxy(32, 21);
			printf("TIME OVER!");
			gotoxy(32, 22);
			printf("����� �ϳ� �����˴ϴ�");

			decrease_life();

			Sleep(1500);
			system("cls");
			break;
		}

		if (_kbhit()) // ����ڰ� Ű�� �����°�?
		{
			ch = _getch();
			if (ch == ESC) // ESC������ �޴��� 
			{
				result = menu();
				break;
			}
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == SPACE)
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			if (ch == BACKSPACE && j > 0)
			{
				printf("\b \b"); // �Է��Ѱ� �����
				j--;
				input[j] = '\0';             //@@@@@@@@@@@@@@@@ ���� : input �迭 ���� ���ڵ� ������  ���� �񱳰� ���������� �Ǵ��󱸿�

			}
			if (ch == TAB && changeword > 0)
			{
				changeword--; // changeword ����
				result = 5;
				return result;
			}
			if (ch == 13)     // @@@@@@@@@@@@@@@@@@@@@ ���� : enter ������ ��/�� �Ǻ� (common.h �� ��ȣ��� ENTER �߰� �ʿ�)
			{
				input[j] = NULL;     // @@@@@@@@@@@@@@@@@@@@@ ���� : game ���ڸ� size ��� 30 ���� �����Ƿ�, �迭�� �Է��� �ڸ� ������ \0 ���� ��
				if (!strcmp(word, input)) // ����
				{
					result = 1;
					cursor(0);
					gotoxy(32, 21);
					printf("PERFECT!\n");
					gotoxy(32, 22);
					end = time(0);
					time_left += TimeLeft(timelimit, start, end); // �����ִ� �ð� ���
					gotoxy(76, 12);
					printf("+ �ð� ���ʽ�( %d ��)", TimeLeft(timelimit, start, end));
					gotoxy(76, 13);
					if (combo_print(num_Q) != 0)
						printf("%d COMBO", combo_print(num_Q));
				}
				else // ����
				{
					result = 0;
					cursor(0);
					gotoxy(32, 21);
					printf("��!\n");
					gotoxy(32, 22);
					printf("����� �ϳ� �����˴ϴ�.");
					decrease_life();
				}
				Sleep(1000);
				system("cls");
				break;
			
			}
		}				
	}

	
	
	return result;
}