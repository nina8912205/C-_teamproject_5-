#include "common.h"

//���� ����� ����ǥ
void Final_Scorecard(int elementary, int middle, int high)
{
	extern char name[];
	int grade;
	int scoresum = elementary + middle + high;

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

// �г⺰ ����ǥ
int Scorecard(int level)
{
	extern char name[];
	extern int life, TotalScore, e_score[], m_score[], h_score[];
	extern int E_O, E_num_Q, E_O_BOSS, E_num_Q_boss;
	extern int M_O, M_num_Q, M_O_BOSS, M_num_Q_boss;
	extern int H_O, H_num_Q, H_O_BOSS, H_num_Q_boss;

	char ch, school[10], next[10];
	int go;
	int t1 = 0, t2 = 0;

	drawline(21, 8, 75, 25);
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
		system("cls");
		KU(1);
		drawline(21, 8, 75, 25);
		gotoxy(45, 12);
		printf("! %s�б� ������ �����մϴ� ! \n\n", school);
	}
	else
	{
		system("cls");
		KU(0);
		drawline(21, 8, 75, 25);
		gotoxy(45, 12);
		printf(" --  ���� �� �����غ��ƿ�!  --");
	}

	switch (level)
	{
	case ELEMENTARY:
		gotoxy(75, 14);
		printf("�̸�: %s\n", name);//�̸� ���
		gotoxy(58, 16);
		printf("�б�");
		gotoxy(73, 16);
		printf("����");
		gotoxy(28, 18);
		printf("���� ������ / Ǭ ������");
		gotoxy(35, 20);
		printf("ȹ�� ����");
		gotoxy(33, 22);
		printf("�ð� �߰� ����");
		gotoxy(35, 24);
		printf("�޺� ����");
		gotoxy(57, 18);
		printf("%d / %d", E_O, E_num_Q);
		gotoxy(72, 18);
		printf("%d / %d", E_O_BOSS, E_num_Q_boss);
		gotoxy(54, 20);
		printf("%7d ��", e_score[CORRECT]);
		gotoxy(69, 20);
		printf("%7d ��", e_score[B_CORRECT]);
		gotoxy(54, 22);
		printf("%7d ��", e_score[TIME]);
		gotoxy(69, 22);
		printf("%7d ��", e_score[B_TIME]);
		gotoxy(56, 24);
		printf("%4d ��", e_score[COMBO]);
		gotoxy(71, 24);
		printf("%4d ��", e_score[B_COMBO]);
		gotoxy(56, 25);
		printf("(%d COMBO)", e_score[COMBO] / BonusPerCombo);
		gotoxy(71, 25);
		printf("(%d COMBO)", e_score[B_COMBO] / BonusPerCombo);
		gotoxy(27, 26);
		printf("________________________________________________________________");
		gotoxy(37, 28);
		printf("�հ�");
		gotoxy(56, 28);
		printf("%d ��", e_score[TOTAL]);
		gotoxy(72, 28);
		printf("%d ��", e_score[BOSS]);
		gotoxy(67, 30);
		printf("����: %7d ��", e_score[TOTAL] + e_score[BOSS]);
		gotoxy(67, 32);
		printf("����: %7d ��", TotalScore);
		break;
	case MIDDLE:
		gotoxy(75, 14);
		printf("�̸�: %s\n", name);//�̸� ���
		gotoxy(58, 16);
		printf("�б�");
		gotoxy(73, 16);
		printf("����");
		gotoxy(28, 18);
		printf("���� ������ / Ǭ ������");
		gotoxy(35, 20);
		printf("ȹ�� ����");
		gotoxy(33, 22);
		printf("�ð� �߰� ����");
		gotoxy(35, 24);
		printf("�޺� ����");
		gotoxy(57, 18);
		printf("%d / %d", M_O, M_num_Q);
		gotoxy(72, 18);
		printf("%d / %d", M_O_BOSS, M_num_Q_boss);
		gotoxy(54, 20);
		printf("%7d ��", m_score[CORRECT]);
		gotoxy(69, 20);
		printf("%7d ��", m_score[B_CORRECT]);
		gotoxy(54, 22);
		printf("%7d ��", m_score[TIME]);
		gotoxy(69, 22);
		printf("%7d ��", m_score[B_TIME]);
		gotoxy(56, 24);
		printf("%4d ��", m_score[COMBO]);
		gotoxy(71, 24);
		printf("%4d ��", m_score[B_COMBO]);
		gotoxy(56, 25);
		printf("(%d COMBO)", m_score[COMBO] / BonusPerCombo);
		gotoxy(71, 25);
		printf("(%d COMBO)", m_score[B_COMBO] / BonusPerCombo);
		gotoxy(27, 26);
		printf("________________________________________________________________");
		gotoxy(37, 28);
		printf("�հ�");
		gotoxy(56, 28);
		printf("%d ��", m_score[TOTAL]);
		gotoxy(72, 28);
		printf("%d ��", m_score[BOSS]);
		gotoxy(67, 30);
		printf("����: %7d ��", m_score[TOTAL] + m_score[BOSS]);
		gotoxy(67, 32);
		printf("����: %7d ��", TotalScore);
		break;
	case HIGH:
		gotoxy(75, 14);
		printf("�̸�: %s\n", name);//�̸� ���
		gotoxy(58, 16);
		printf("�б�");
		gotoxy(73, 16);
		printf("����");
		gotoxy(28, 18);
		printf("���� ������ / Ǭ ������");
		gotoxy(35, 20);
		printf("ȹ�� ����");
		gotoxy(33, 22);
		printf("�ð� �߰� ����");
		gotoxy(35, 24);
		printf("�޺� ����");
		gotoxy(57, 18);
		printf("%d / %d", H_O, H_num_Q);
		gotoxy(72, 18);
		printf("%d / %d", H_O_BOSS, H_num_Q_boss);
		gotoxy(54, 20);
		printf("%7d ��", h_score[CORRECT]);
		gotoxy(69, 20);
		printf("%7d ��", h_score[B_CORRECT]);
		gotoxy(54, 22);
		printf("%7d ��", h_score[TIME]);
		gotoxy(69, 22);
		printf("%7d ��", h_score[B_TIME]);
		gotoxy(56, 24);
		printf("%4d ��", h_score[COMBO]);
		gotoxy(71, 24);
		printf("%4d ��", h_score[B_COMBO]);
		gotoxy(56, 25);
		printf("(%d COMBO)", h_score[COMBO] / BonusPerCombo);
		gotoxy(71, 25);
		printf("(%d COMBO)", h_score[B_COMBO] / BonusPerCombo);
		gotoxy(27, 26);
		printf("________________________________________________________________");
		gotoxy(37, 28);
		printf("�հ�");
		gotoxy(56, 28);
		printf("%d ��", h_score[TOTAL]);
		gotoxy(72, 28);
		printf("%d ��", h_score[BOSS]);
		gotoxy(67, 30);
		printf("����: %7d ��", h_score[TOTAL] + h_score[BOSS]);
		gotoxy(67, 32);
		printf("����: %7d ��", TotalScore);
		break;
	}


	gotoxy(25, 31);
	if (level != HIGH && life != 0) {
		printf("[ %s�б��� �����Ϸ��� g, ���� �޴��� ���ư��÷��� ESCŰ�� �����ּ���.]", next);
		gotoxy(25, 32);
		printf(" �ƹ�Ű�� ������ ������ �ڵ����� %s�б��� �����մϴ�. [8��]", next);
		t1 = clock(0);
	}
	else
		printf("[ ���� �޴��� ���ư��÷��� ESCŰ�� �����ּ���.]");
		

	while (1)
	{
		do {
			t2 = clock(0);
			if (difftime(t2, t1) > 8000) {
				return 1;
				break;
			}
		} while (!_kbhit());
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

void KU(int type)
{
	cursor(0);
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
	switch (type)
	{
	case 0:
		printf("\t\t\t\t  ����                                      ����\n");
		printf("\t\t\t\t      ��      ������      ������      ��\n");
		printf("\t\t\t\t      ��        ��  ��          ��  ��        ��\n");
		break;
	case 1:
		printf("\t\t\t\t  ����          ��              ��          ����\n");
		printf("\t\t\t\t      ��        ��  ��          ��  ��        ��\n");
		printf("\t\t\t\t      ��                                      ��\n");
		break;
	case 2:
		printf("\t\t\t\t  ����            ��            ��          ����\n");
		printf("\t\t\t\t      ��          ���          ���          ��\n");
		printf("\t\t\t\t      ��          ���          ���          ��\n");
		break;
	}
	
	printf("\t\t\t\t    ��                  ��  ��                  ��\n");
	printf("\t\t\t\t    ��            ����������            ��\n");
	printf("\t\t\t\t    ��        ����              ����        ��\n");
	switch (type)
	{
	case 0:
		printf("\t\t\t\t    ��    ���          ����          ���    ��\n");
		printf("\t\t\t\t    ��  ��            ��      ��            ��  ��\n");
		break;
	case 1:
	case 2:
		printf("\t\t\t\t    ��    ���        ��      ��        ���    ��\n");
		printf("\t\t\t\t    ��  ��              ����              ��  ��\n");
		break;
	}
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t        ��                                  ��\n");
	printf("\t\t\t\t        ���                              ���\n");
	printf("\t\t\t\t            ���                      ���\n");
	printf("\t\t\t\t              ���                  ���\n");
	printf("\t\t\t\t                  ����������\n");
	Sleep(700);
	system("cls");
}
