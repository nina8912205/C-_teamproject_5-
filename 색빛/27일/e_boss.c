#include "common.h"
#define EBOSS 6
#define Bscore 8000
int Boss_time = 6;

int E_num_Q_boss = 0;//�ʵ��б� �������� Ǭ ���� �� ���
int E_O_BOSS = 0;	//�ʵ��б� �������� ���� ���� �� ���

void e_boss()
{
	extern int life, addtime;
	extern int time_left, e_score[], TotalScore, O_X[];

	char word[SIZE], input[SIZE], item;
	int start, end, result;
	int combo[5] = { 0 };
	
	resetOX();

	// ���̾ƿ�
	drawline(21, 8, 75, 25);
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
		drawline(21, 8, 75, 25);
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
			addtime--;
			Boss_time++;
		}
		else if (item == 'n') {
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

		drawline(21, 8, 75, 25);
		drawitem();
		drawmenu();
		E_num_Q_boss++;
		drawtopbar();
		gotoxy(76, 10);
		printf("�� SCORE�� %010d", TotalScore);
		gotoxy(25, 10);
		printf(" �ʵ��б� ���� ���� - ���� %d ��\n", i);

		// ���� ����
		gotoxy(32, 18);
		printf("���� : ");
		random_word(EBOSS, word);
		gotoxy(70, 17);
		printf("���� : %d ��", Bscore);
		start = time(0);

		// ���� ���߱� & ���
		gotoxy(32, 19);
		printf("������ ���� ġ���� : ");
		result = game(EBOSS, Boss_time, input, word, E_num_Q_boss);
		end = time(0);

		if (result) {
			boss_correct(ELEMENTARY, Bscore);
			boss_time(ELEMENTARY, TimeBonus(time_left));

			if (O_X[E_num_Q_boss - 2] == 1)
				boss_combo(ELEMENTARY);

			combo[i - 1] = 1;
			O_X[E_num_Q_boss - 1] = 1;
			E_O_BOSS++;
		}
		else {
			combo[i - 1] = 0;
			O_X[E_num_Q_boss - 1] = 0;
		}
	}
}