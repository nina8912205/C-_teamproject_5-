//############ ���� - ���� �̸� �ٲ���ϴ�.
#include "common.h"
#define EBOSS 6
#define Bscore 8000  //############ ���� - �������� ��ȣ ����� ����.
 
int e_boss(int e_score) //############ ���� - ���� �� �Լ����µ� �ϳ��� ����.
{
	char word[SIZE], input[SIZE];
	int boss_score = 0, result;
	extern int life, e_total_score, time_left;

	// ���̾ƿ�
	drawline();
	drawitem();
	drawmenu();

	// ���� ���丮
	/*
	�ʵ��б� ~ �ʵ��б� ������ �Ѿ�� �κ�
	��¹� �߰��ؾ���
	ex) ���� ���
	*/
	gotoxy(32, 15);
	printf("�����մϴ�");		//�ӽ�
	Sleep(1000);
	gotoxy(32, 17);
	printf("�ʵ��б� ���������� ������ ���ƽ��ϴ�");	//�ӽ�
	Sleep(1000);
	gotoxy(32, 19);
	printf("�ʵ��б� ���� �������� �̱⼼��");		//�ӽ�
	Sleep(2000);
	system("cls");

	// ���� ����
	for (int i = 1; i <= 5; i++) 
	{
		// ��� �˻�
		if (life == 0)
			break;

		drawline();
		drawitem();
		drawmenu();
		drawtopbar();
		gotoxy(76, 10);
		printf("�� SCORE�� %010d", e_total_score);
		gotoxy(25, 10);
		printf(" �ʵ��б� ���� ���� - ���� %d ��\n", i);
		
		// ���� ����
		gotoxy(32, 17);
		printf("���� : ");
		random_word(EBOSS, word);
		gotoxy(70, 17);
		printf("���� : %d ��", Bscore);

		// ���� ���߱� & ���
		gotoxy(32, 19);
		printf("������ ���� ġ���� : ");
		result = game(EBOSS, EBOSS, input, word);

		if (result)
			boss_score += Bscore;
		
		e_total_score = e_score + TimeBonus(time_left) + boss_score;
	}
	return boss_score;
}