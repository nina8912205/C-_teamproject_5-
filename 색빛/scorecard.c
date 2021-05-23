//############ ���� - �����(21��)�� �ø��Ű� �� �����߽��ϴ�.
#include "common.h"

//���� ����� ����ǥ
////############ ���� - �̸��� ���������� �ٲ㼭 �μ� �ʿ�X, �μ� �̸� �ʹ� �� ����
void Final_Scorecard(int elementary, int middle, int high)
{
	extern char name[]; //############ ���� - �̸�(��������)
	int grade;
	int scoresum = elementary + middle + high; ////############ ���� - scoresum���� total_score�� �� �����Ű����ϴ�.

	//��� ����-���� �����ϱ�
	if (scoresum < 10000)
		grade = 9;
	else if (10000 <= scoresum && scoresum < 20000)
		grade = 8;
	else if (20000 <= scoresum && scoresum < 30000)
		grade = 7;
	else if (30000 <= scoresum && scoresum < 40000)
		grade = 6;
	else if (40000 <= scoresum && scoresum < 50000)
		grade = 5;
	else if (50000 <= scoresum && scoresum < 60000)
		grade = 4;
	else if (60000 <= scoresum && scoresum < 70000)
		grade = 3;
	else if (70000 <= scoresum && scoresum < 80000)
		grade = 2;
	else
		grade = 1;

	printf("                     ����ǥ                     \n");
	printf("                                    �̸�:	%s  \n", name);//�̸� ���
	printf("                                                \n");
	printf("             �ʵ��б�:  %d��\n\n", elementary);
	printf("             ���б�  :  %d��\n\n", middle);
	printf("             ����б�:  %d��\n\n", high);
	printf("             ����    :  %d��\n\n", elementary + middle + high);
	printf("             ���� ���: %d���", grade);

}

/*############ ����
 - �̸��� ���������� �����߱� ������ ����.
 - �޺� ������ ���ؼ� �޺� ������ �� �� �ֱ� ������ �޺� ������ �μ����� ��.
 - char level -> int level (�̹� ��ȣ����� ����Ȱ� �־ �װ� ������ �ٲ�)
 - ���� ���� �߰�
 - ���� �ܰ�� �Ѿ�� �˰����� �浹�� �� ����.(���� ����� game_start.c�� �ּ� �޶�����..)
 - �� �� �����ϰ� �ڵ� ����. && ����ǥ ���̾ƿ� ����
 - �� �� �߰�
*/
int Scorecard(int level, int score, int time, int combo, int boss, int Q_solved, int Q_correct)
{
	extern char name[];
	extern int life;
	char ch, school[10], next[10];
	int go;

	drawline();
	drawitem();
	drawmenu();

	switch (level)
	{
	case ELEMENTARY:
		strcpy(school, "�ʵ�");
		strcpy(next, "��");
		break;
	case MIDDLE:
		strcpy(school, "��");
		strcpy(next, "���");
		break;
	case HIGH:
		strcpy(school, "���");
		break;
	}

	if (life)
	{
		happyKU();
		drawline();
		gotoxy(45, 12);
		printf("! %s�б� ������ �����մϴ� ! \n\n", school);
	}
	else 
	{
		sadKU();
		drawline();
		gotoxy(45, 12);
		printf(" --  ���� �� �����غ��ƿ�!  --");
	}
		

	gotoxy(75, 14);
	printf("�̸�: %s\n", name);//�̸� ���
	gotoxy(48, 16);
	printf("%d ������ %d ���� ����!", Q_solved, Q_correct);
	gotoxy(48, 18);
	printf("ȹ���� ����  :  %5d ��", score);
	gotoxy(48, 20);
	printf("�ð��߰� ����:  %5d ��", time);
	gotoxy(48, 22);
	printf("�޺�����     :  %5d �� (%d COMBO)", combo, combo/BonusPerCombo);
	gotoxy(48, 24);
	printf("��������     :  %5d ��", boss);
	gotoxy(34, 26);
	printf("----------------------------------------------------");
	gotoxy(48, 28);
	printf("����         :  %5d ��", score + time + combo + boss);
	
	gotoxy(25, 31);
	if (level != HIGH && life != 0)
		printf("[ %s�б��� �����Ϸ��� g, ���� �޴��� ���ư��÷��� ESCŰ�� �����ּ���.]", next);
	else
		printf("[ ���� �޴��� ���ư��÷��� ESCŰ�� �����ּ���.]");
	
	while (1)
	{
		ch = _getch();
		if (ch == ESC)
		{
			go = 0;
			//score_reset();
			break;
		}
		if (ch == 'g')
		{
			go = 1;
			break;
		}
	}
	system("cls");
	return go;
}

void sadKU()
{
	system("cls");
	gotoxy(0, 9);
	printf("\t\t\t\t            ���                      ���\n");
	printf("\t\t\t\t            ��  ��    ������    ��  ��\n");
	printf("\t\t\t\t            ��    ���          ���    ��\n");
	printf("\t\t\t\t            ��  ���              ���  ��\n");
	printf("\t\t\t\t        �����        ��    ��      �����\n");
	printf("\t\t\t\t    ���  ��            ��    ��          ��  ���\n");
	printf("\t\t\t\t  ��      ��      ��      ��  ��  ��      ��      ��\n");
	printf("\t\t\t\t��      ��      ��          ��      ��      ��      ��\n");
	printf("\t\t\t\t��      ��                                  ��      ��\n");
	printf("\t\t\t\t  ����                                      ����\n");
	printf("\t\t\t\t      ��      ������      ������      ��\n");
	printf("\t\t\t\t      ��        ��  ��          ��  ��        ��\n");
	printf("\t\t\t\t    ��                  ��  ��                  ��\n");
	printf("\t\t\t\t    ��            ����������            ��\n");
	printf("\t\t\t\t    ��        ����              ����        ��\n");
	printf("\t\t\t\t    ��    ���          ����          ���    ��\n");
	printf("\t\t\t\t    ��  ��            ��      ��            ��  ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t        ��                                  ��\n");
	printf("\t\t\t\t        ���                              ���\n");
	printf("\t\t\t\t            ���                      ���\n");                                
	printf("\t\t\t\t              ���                  ���\n");
	printf("\t\t\t\t                  ����������\n");
	Sleep(2000);
	system("cls");
}

void happyKU()
{
	system("cls");
	gotoxy(0, 9);
	printf("\t\t\t\t            ���                      ���\n");
	printf("\t\t\t\t            ��  ��    ������    ��  ��\n");
	printf("\t\t\t\t            ��    ���          ���    ��\n");
	printf("\t\t\t\t            ��  ���              ���  ��\n");
	printf("\t\t\t\t        �����        ��    ��      �����\n");
	printf("\t\t\t\t    ���  ��            ��    ��          ��  ���\n");
	printf("\t\t\t\t  ��      ��      ��      ��  ��  ��      ��      ��\n");
	printf("\t\t\t\t��      ��      ��          ��      ��      ��      ��\n");
	printf("\t\t\t\t��      ��                                  ��      ��\n");
	printf("\t\t\t\t  ����          ��              ��            ����\n");
	printf("\t\t\t\t      ��        ��  ��          ��  ��        ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t    ��                  ��  ��                  ��\n");
	printf("\t\t\t\t    ��            ����������            ��\n");
	printf("\t\t\t\t    ��        ����              ����        ��\n");
	printf("\t\t\t\t    ��    ���        ��      ��        ���    ��\n");
	printf("\t\t\t\t    ��  ��              ����              ��  ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t        ��                                  ��\n");
	printf("\t\t\t\t        ���                              ���\n");
	printf("\t\t\t\t            ���                      ���\n");
	printf("\t\t\t\t              ���                  ���\n");
	printf("\t\t\t\t                  ����������\n");
	Sleep(2000);
	system("cls");
}