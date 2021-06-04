#include "common.h"

void Final_Scorecard()
{
	extern char name[], sch[][SIZE];
	extern int life, TotalScore, SCORE[][ASIZE];
	int grade;

	system("cls");
	drawline(21, 8, 75, 25);
	drawitem();
	drawmenu();

	if (TotalScore < 10000)
		grade = 9;
	else if (10000 <= TotalScore && TotalScore < 20000)
		grade = 8;
	else if (20000 <= TotalScore && TotalScore < 30000)
		grade = 7;
	else if (30000 <= TotalScore && TotalScore < 40000)
		grade = 6;
	else if (40000 <= TotalScore && TotalScore < 50000)
		grade = 5;
	else if (50000 <= TotalScore && TotalScore < 60000)
		grade = 4;
	else if (60000 <= TotalScore && TotalScore < 70000)
		grade = 3;
	else if (70000 <= TotalScore && TotalScore < 80000)
		grade = 2;
	else
		grade = 1;

	gotoxy(54, 11);	printf("�� �����մϴ� ��");
	gotoxy(43, 12);	printf("�� ���� ������ ��� �̼��ϼ̽��ϴ� ��");
	gotoxy(75, 14);	printf("�̸�: %s\n", name);

	for (int i = E, j = 15; i < SCHSIZE; i++, j += 5)
	{
		gotoxy(30, j);	printf("|%s�б�| - ", sch[i]);
		print_phrase(i);
		gotoxy(30, j + 2);	printf("���� ������ / Ǭ ������: ");
		gotoxy(55, j + 2);	printf("%d  /  %d", SCORE[i][Q_CORRECT] + SCORE[i][T_Q_CORRECT], SCORE[i][Q_SOLVED] + SCORE[i][T_Q_SOLVED]);
		gotoxy(67, j + 2);	printf("ȹ�� ����: %6d ��", SCORE[i][TOTAL] + SCORE[i][TEST]);
		Sleep(1000);
	}

	gotoxy(29, 29);	printf("-------------------------------------------------------------");
	gotoxy(35, 30);	printf("�� ȹ�� ����: %d �� / %d ���\n", TotalScore, grade);
}

void print_phrase(int level)
{
	extern int SCORE[][ASIZE];
	int score = SCORE[level][TOTAL] + SCORE[level][TEST];
	
	switch (level)
	{
	case E:
		if (score < 60000)
			printf("���� �� �����غ��ƿ�!");
		else
			printf("���߽��ϴ�!");
		break;
	case M:
		if (score < 45000)
			printf("���� �� �����غ��ƿ�!");
		else
			printf("���߽��ϴ�!");
		break;
	case H:
		if (score < 45000)
			printf("���� �� �����غ��ƿ�!");
		else
			printf("���߽��ϴ�!");
		break;
	}
}

// �г⺰ ����ǥ
int Scorecard(int level)
{
	extern char name[], sch[][SIZE];
	extern int TotalScore, item[];
	extern int SCORE[][ASIZE];

	char ch;
	int go;
	int t1 = 0, sec = 1;

	drawline(21, 8, 75, 25);

	if (item[LIFE])
	{
		system("cls");
		KU(1);
		drawline(21, 8, 75, 25);
		gotoxy(45, 11);	printf("�� %s�б� ������ �����մϴ� ��\n\n", sch[level]);
	}
	else
	{
		system("cls");
		KU(0);
		drawline(21, 8, 75, 25);
		gotoxy(45, 11);	printf(" --  ���� �� �����غ��ƿ�!  --");
	}

	gotoxy(75, 13); printf("�̸�: %s\n", name);
	gotoxy(61, 15); printf("�б�");
	gotoxy(75, 15); printf("��������");
	gotoxy(31, 17); printf("���� ������ / Ǭ ������");
	gotoxy(38, 19); printf("ȹ�� ����");
	gotoxy(36, 21); printf("�ð� �߰� ����");
	gotoxy(38, 23);	printf("�޺� ����");
	gotoxy(62, 17);	printf("%d / %d", SCORE[level][Q_CORRECT], SCORE[level][Q_SOLVED]);
	gotoxy(77, 17); printf("%d / %d", SCORE[level][T_Q_CORRECT], SCORE[level][T_Q_SOLVED]);
	gotoxy(57, 19); printf("%7d ��", SCORE[level][CORRECT]);
	gotoxy(72, 19);	printf("%7d ��", SCORE[level][T_CORRECT]);
	gotoxy(57, 21); printf("%7d ��", SCORE[level][TIME]);
	gotoxy(72, 21); printf("%7d ��", SCORE[level][T_TIME]);
	gotoxy(57, 23); printf("%7d ��", SCORE[level][COMBO]);
	gotoxy(72, 23); printf("%7d ��", SCORE[level][T_COMBO]);
	gotoxy(59, 24); printf("(%d COMBO)", SCORE[level][COMBO] / BonusPerCombo);
	gotoxy(76, 24); printf("(%d COMBO)", SCORE[level][T_COMBO] / BonusPerCombo);
	gotoxy(28, 25); printf("________________________________________________________________");
	gotoxy(40, 27); printf("�հ�");
	gotoxy(57, 27); printf("%7d ��", SCORE[level][TOTAL]);
	gotoxy(72, 27); printf("%7d ��", SCORE[level][TEST]);
	gotoxy(73, 29); printf("����: %7d ��", SCORE[level][TOTAL] + SCORE[level][TEST]);
	gotoxy(73, 31); printf("����: %7d ��", TotalScore);

	Sleep(1000);
	
	textcolor(2);
	if (item[LIFE] == 0)
	{
		gotoxy(25, 31); printf("�ƹ�Ű�� ������ ���θ޴��� ���ư��ϴ�.");
	}		
	else if (SCORE[E][T_Q_SOLVED] + SCORE[M][T_Q_SOLVED] + SCORE[H][T_Q_SOLVED] == 15)
	{
		gotoxy(28, 31); printf("[�˸�] ��������ǥ�� �����߽��ϴ�.");
	}
	else if (level == H)
	{
		gotoxy(25, 31); printf("�ƹ�Ű�� ������ ���θ޴��� ���ư��ϴ�.");
	}
	else
	{		
		gotoxy(25, 30); printf("�ƹ�Ű�� ������ �����б��� �����մϴ�.");
		gotoxy(25, 31); printf("���� �޴��� ���ư��÷��� ESCŰ�� �����ּ���");		
	}

	t1 = time(0);
	printf(" 10");
	
	while (1)
	{
		if (time(0) == t1 + sec)
		{
			cursor(0);
			printf("\b\b %d", 10 - sec);
			sec++;

			if (sec > 10)
			{
				go = 0;
				break;
			}				
		}		
		if (_kbhit())
		{
			ch = _getch();
			if (ch == ESC)
				go = 1;
			else
				go = 0;
			break;
		}		
	}
	textcolor(15);
	system("cls");
	return go;
}

