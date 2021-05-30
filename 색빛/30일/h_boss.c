#include "common.h"
#define H_Bscore 12000
int H_Boss_time = 15;

void h_boss()
{
	extern int life, addtime;
	extern int time_left, scorearray[SCHSIZE][ASIZE], TotalScore, O_X[];

	char word[SIZE], input[SIZE], item;
	int use = 0, i;
	int start, end, result;
	int combo[5] = { 0 };

	resetOX();

	// ���̾ƿ�
	drawline(21, 8, 75, 25);
	drawitem();
	drawmenu();

	// ���� ���丮
	gotoxy(32, 15);	printf("�����մϴ�");
	Sleep(1000);
	gotoxy(32, 17);	printf("����б� ���������� ������ ���ƽ��ϴ�");
	Sleep(1000);
	gotoxy(32, 19);	printf("����б� ���� �������� �̱⼼��");
	Sleep(2000);
	system("cls");

	if (addtime >= 1) {
		drawline(21, 8, 75, 25);
		drawitem();
		drawmenu();
		gotoxy(32, 15);	printf("�ð� �߰� �������� �ֽ��ϴ�.");
		Sleep(1000);
		gotoxy(32, 17);	printf("����Ͻðڽ��ϱ�? [y/n]");

		item = _getch();
		if (item == 'y') {
			gotoxy(32, 19);	printf("�������� �� �� ����Ͻðڽ��ϱ�? ");
			Sleep(1000);
			scanf("%d", &use);
			getchar();
			gotoxy(32, 21);	printf("�������� ����մϴ�.");
			Sleep(1000);
			gotoxy(32, 23); printf("���ѽð��� %d�� �þ�ϴ�.", use);
			Sleep(2000);
			for (i = 0; i < use; i++) {
				addtime--;
				H_Boss_time++;
			}
		}
		else if (item == 'n') {
			gotoxy(32, 19);	printf("�������� ������� �ʽ��ϴ�.");
			Sleep(1000);
		}
		system("cls");
	}

	// ���� ����
	for (int i = 1; i <= 1; i++)
	{
		// ��� �˻�
		if (life == 0)
			break;

		drawline(21, 8, 75, 25);
		drawitem();
		drawmenu();
		scorearray[H][B_Q_SOLVED]++;
		drawtopbar();
		gotoxy(76, 10);	printf("�� SCORE�� %010d", TotalScore);
		gotoxy(25, 10);	printf(" ����б� ���� ���� - ���� %d ��\n", i);

		// ���� ����
		gotoxy(32, 18);	printf("���� : ");
		word_short_h(word);
		gotoxy(70, 17);	printf("���� : %d ��", H_Bscore);
		start = time(0);

		// ���� ���߱� & ���
		gotoxy(32, 19);	printf("������ ���� ġ���� : ");
		result = game(H_Boss_time, input, word, scorearray[H][B_Q_SOLVED]);
		end = time(0);

		if (result) {
			boss_correct(H, H_Bscore);
			boss_time(H, TimeBonus(time_left));

			if (O_X[scorearray[H][B_Q_SOLVED] - 2] == 1)
				boss_combo(H);

			combo[i - 1] = 1;
			O_X[scorearray[H][B_Q_SOLVED] - 1] = 1;
			scorearray[H][B_Q_CORRECT]++;
		}
		else {
			combo[i - 1] = 0;
			O_X[scorearray[H][B_Q_SOLVED] - 1] = 0;
		}
	}
}

