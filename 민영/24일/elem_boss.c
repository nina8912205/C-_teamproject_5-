//############ ���� - ���� �̸� �ٲ���ϴ�.
#include "common.h"
#define EBOSS 6	//���� ��
#define Bscore 8000  //############ ���� - �������� ��ȣ ����� ����.
int Boss_time = 6;

int e_boss(int e_score) //############ ���� - ���� �� �Լ����µ� �ϳ��� ����.
{
	char word[SIZE], input[SIZE];
	char item;
	int boss_score = 0, result;
	int time_bonus = 0;
	int start, end, B_combo = 0, time_score = 0;
	int combo[5] = {0, 0, 0, 0, 0};
	extern int life, e_total_score, time_left;
	extern int addtime;

	// ���̾ƿ�
	drawline();
	drawitem();
	drawmenu();

	// ���� ���丮
	gotoxy(32, 15);
	printf("�����մϴ�");
	Sleep(1000);
	gotoxy(32, 17);
	printf("�ʵ��б� ���������� ������ ���ƽ��ϴ�");
	Sleep(1000);
	gotoxy(32, 19);
	printf("�ʵ��б� ���� �������� �̱⼼��");
	Sleep(2000);
	system("cls");
	if (addtime >= 1) {
		drawline();
		drawitem();
		drawmenu();
		gotoxy(32, 15);
		printf("�ð� �߰� �������� �ֽ��ϴ�.");
		Sleep(1000);
		gotoxy(32, 17);
		printf("����Ͻðڽ��ϱ�? [y/n]");
		item = _getch();
		if (item == 'y') {
			gotoxy(32, 19);
			printf("�������� ����մϴ�.");
			Sleep(1000);
			gotoxy(32, 21);
			printf("���� �ð��� 1�� �þ�ϴ�.");
			Sleep(1000);
			addtime -= 1;
			Boss_time += 1;
		}
		else if(item == 'n'){
			gotoxy(32, 19);
			printf("�������� ������� �ʽ��ϴ�.");
			Sleep(1000);
		}
		system("cls");
	}

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
		start = time(0);

		// ���� ���߱� & ���
		gotoxy(32, 19);
		printf("������ ���� ġ���� : ");
		result = game(EBOSS, Boss_time, input, word);
		end = time(0);

		if (result) {
			boss_score += Bscore ;
			time_score += (7 - (end - start)) * 500;
			combo[i - 1] = 1;
		}
		else {
			combo[i - 1] = 0;
		}
		printf("%d", time_score);
	}
	for (int i = 1; i <= 5; i++) {
		if (combo[i] == 1)
			if (combo[i + 1] == 1)
				B_combo++;
	}
	boss_score += B_combo * 100;
	boss_score += time_score;
	e_total_score = e_score + TimeBonus(time_left) + boss_score;
	return boss_score;
}