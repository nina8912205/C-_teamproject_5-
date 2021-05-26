// game.c : ���� ����� ���õ� �Լ�
#include "common.h"

int time_left; // ���� �ð� ���� ����

// �ܾ� �Է� �ޱ� & ���� �ð��� ������ �Ѿ�� -> ��� ��ȯ(0: ����, 1: ����, 2: �޴� ����)
int game(int size, int timelimit, char* input, char* word, int num_Q) //**** 5/24(����)-�ǽð� �޺� ǥ������ �μ� �߰�
{
	char ch;
	int j = 0, start, end, result;

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
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			if (ch == BACKSPACE)
			{
				printf("\b \b"); // �Է��Ѱ� �����
				if (j > 0)
				{
					input[j] = NULL;
					j--;
				}
			}
		}

		if (j >= size) // ���ڿ��� ���� ������	
		{
			input[size] = NULL;
			if (!strcmp(word, input)) // ����
			{
				result = 1;
				cursor(0);
				gotoxy(32, 21);
				printf("PERFECT!\n");
				gotoxy(32, 22);
				end = time(0);
				time_left = TimeLeft(timelimit, start, end); // �����ִ� �ð� ���
				gotoxy(76, 12);
				printf("+ �ð� ���ʽ�( %d ��)", TimeLeft(timelimit, start, end)); //############ ���� - ���� �������� �ð� ��°� int���̶� ������� ������ �߽��ϴ�.
				//////*****5/26����-combo�ǽð���� �߰�
				gotoxy(76, 13);
				if (combo_print(num_Q)!=0)
				{
					printf("%d COMBO", combo_print(num_Q));
				}

				Sleep(1500);
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
			//**** 5/24(����) - �޺� ���� ��� ���� Sleep(1500), System("cls") �̵�
			Sleep(1500);
			system("cls");
			break;
		}
	}
	return result;
}