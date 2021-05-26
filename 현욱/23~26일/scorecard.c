#include "common.h"

//���� ����� ����ǥ - ���� ������
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


int Scorecard(int level)
{
	extern char name[];
	extern int life;
	extern int total_score;
	extern int e_total_score, e_correct_score, e_time_bonus, e_combo_bonus;
	extern int eboss_total_score, eboss_correct_score, eboss_time_bonus, eboss_combo_bonus;
	extern int E_O, E_num_Q, E_O_BOSS, E_num_Q_boss;

	extern int m_total_score, m_correct_score, m_time_bonus, m_combo_bonus;
	extern int mboss_total_score, mboss_correct_score, mboss_time_bonus, mboss_combo_bonus;
	extern int M_O, M_num_Q, M_O_BOSS, M_num_Q_boss;
	// ����б� �Լ����� ���� �ʿ�
	extern int h_total_score, h_correct_score, h_time_bonus, h_combo_bonus;
	extern int hboss_total_score, hboss_correct_score, hboss_time_bonus, hboss_combo_bonus;
	extern int H_O, H_num_Q, H_O_BOSS, H_num_Q_boss;
	
	char ch, school[10], next[10];
	int go;
	int t1 = 0, t2 = 0;

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


	switch (level)
	{
	case ELEMENTARY:
	{
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
		printf("%7d ��", e_correct_score);
		gotoxy(69, 20);
		printf("%7d ��", eboss_correct_score);

		gotoxy(54, 22);
		printf("%7d ��", e_time_bonus);
		gotoxy(69, 22);
		printf("%7d ��", eboss_time_bonus);

		gotoxy(56, 24);
		printf("%4d ��", e_combo_bonus);
		gotoxy(71, 24);
		printf("%4d ��", eboss_combo_bonus);
		gotoxy(56, 25);
		printf("(%d COMBO)", e_combo_bonus / BonusPerCombo);
		gotoxy(71, 25);
		printf("(%d COMBO)", eboss_combo_bonus / BonusPerCombo);
		gotoxy(27, 26);
		printf("________________________________________________________________");
		gotoxy(37, 28);
		printf("�հ�");
		gotoxy(56, 28);
		printf("%d ��", e_total_score);
		gotoxy(72, 28);
		printf("%d ��", eboss_total_score);
		gotoxy(67, 30);
		printf("����: %7d ��", e_total_score + eboss_total_score);
		gotoxy(67, 32);
		printf("����: %7d ��", total_score);
		break;
	}
	case MIDDLE:
	{
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
		printf("%7d ��", m_correct_score);
		gotoxy(69, 20);
		printf("%7d ��", mboss_correct_score);

		gotoxy(54, 22);
		printf("%7d ��", m_time_bonus);
		gotoxy(69, 22);
		printf("%7d ��", mboss_time_bonus);

		gotoxy(56, 24);
		printf("%4d ��", m_combo_bonus);
		gotoxy(71, 24);
		printf("%4d ��", mboss_combo_bonus);
		gotoxy(56, 25);
		printf("(%d COMBO)", m_combo_bonus / BonusPerCombo);
		gotoxy(71, 25);
		printf("(%d COMBO)", mboss_combo_bonus / BonusPerCombo);
		gotoxy(27, 26);
		printf("________________________________________________________________");
		gotoxy(37, 28);
		printf("�հ�");
		gotoxy(56, 28);
		printf("%d ��", m_total_score);
		gotoxy(72, 28);
		printf("%d ��", mboss_total_score);
		gotoxy(67, 30);
		printf("����: %7d ��", m_total_score + mboss_total_score);
		gotoxy(67, 32);
		printf("����: %7d ��", total_score);
		break;
	}
	case HIGH:
	{
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
		printf("%7d ��", h_correct_score);
		gotoxy(69, 20);
		printf("%7d ��", hboss_correct_score);

		gotoxy(54, 22);
		printf("%7d ��", h_time_bonus);
		gotoxy(69, 22);
		printf("%7d ��", hboss_time_bonus);

		gotoxy(56, 24);
		printf("%4d ��", h_combo_bonus);
		gotoxy(71, 24);
		printf("%4d ��", hboss_combo_bonus);
		gotoxy(56, 25);
		printf("(%d COMBO)", h_combo_bonus / BonusPerCombo);
		gotoxy(71, 25);
		printf("(%d COMBO)", hboss_combo_bonus / BonusPerCombo);
		gotoxy(27, 26);
		printf("________________________________________________________________");
		gotoxy(37, 28);
		printf("�հ�");
		gotoxy(56, 28);
		printf("%d ��", h_total_score);
		gotoxy(72, 28);
		printf("%d ��", hboss_total_score);
		gotoxy(67, 30);
		printf("����: %7d ��", h_total_score + hboss_total_score);
		break;
	}
	}




	/*
	printf("%d ������ %d ���� ����!", Q_solved, Q_correct);
	gotoxy(48, 18);
	printf("ȹ���� ����  :  %5d ��", e_correct_score);
	gotoxy(48, 20);
	printf("�ð��߰� ����:  %5d ��", e_time_bonus);
	gotoxy(48, 22);
	printf("�޺�����     :  %5d �� (%d COMBO)", e_combo_bonus, e_combo_bonus / BonusPerCombo);
	gotoxy(48, 24);
	printf("��������     :  %5d ��", eboss_total_score);
	gotoxy(34, 26);
	printf("----------------------------------------------------");
	gotoxy(48, 28);
	printf("����         :  %5d ��", e_total_score + eboss_total_score);
	*/

	system("pause");/// �ӽ�****

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
		do {	// **********************************5/23 �ο� �ð� 8�� ������ �ڵ� �̵� ��� 
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
			score_reset();
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

//���߿� �ʿ��� ���� ������ ���� �ּ�ó���ϰ� �ϴ��� �ξ����ϴ�.
/*
int Scorecard(int level, int Q_solved, int Q_correct)
{
	extern char name[];
	extern int life;
	extern int e_total_score, e_correct_score, e_time_bonus, e_combo_bonus;
	extern int eboss_total_score, eboss_correct_score, eboss_time_bonus, eboss_combo_bonus;

	char ch, school[10], next[10];
	int go;
	int t1 = 0, t2 = 0;

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
	printf("ȹ���� ����  :  %5d ��", e_correct_score);
	gotoxy(48, 20);
	printf("�ð��߰� ����:  %5d ��", e_time_bonus);
	gotoxy(48, 22);
	printf("�޺�����     :  %5d �� (%d COMBO)",e_combo_bonus , e_combo_bonus / BonusPerCombo);
	gotoxy(48, 24);
	printf("��������     :  %5d ��", eboss_total_score);
	gotoxy(34, 26);
	printf("----------------------------------------------------");
	gotoxy(48, 28);
	printf("����         :  %5d ��", e_total_score+eboss_total_score);


	system("pause");/// �ӽ�****

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
		do {	// **********************************5/23 �ο� �ð� 8�� ������ �ڵ� �̵� ���
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
}*/