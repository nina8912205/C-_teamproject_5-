//############ ���� - ���� �̸� �ٲ���ϴ�.
#include "common.h"
#define EBOSS 6	//���� ��
#define Bscore 8000  //############ ���� - �������� ��ȣ ����� ����.
int Boss_time = 6;

//5/26 ����	- ���� ���� ����******************
int E_num_Q_boss = 0;//�ʵ��б� �������� Ǭ ���� �� ���
int E_O_BOSS = 0;	//�ʵ��б� �������� ���� ���� �� ���

void e_boss() //############ ���� - ���� �� �Լ����µ� �ϳ��� ����.
{
	resetOX();
	char word[SIZE], input[SIZE];
	char item;
	///****5/26 ���� - ���� ���� ��� ����
	extern int total_score,eboss_total_score, eboss_correct_score, eboss_time_bonus, eboss_combo_bonus;
	extern int O_X[MAX_Q];
	extern int life, e_total_score, time_left;
	extern int addtime;
	int result;
	int start, end, B_combo = 0, time_score = 0;
	int combo[5] = { 0 };//�Լ��� ���� �����Ͽ� ������ �������� ������, Ȥ�� ���� �ξ����ϴ�. (����)
	


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

		drawline();
		drawitem();
		drawmenu();
		/*draws_boss("�ʵ��б� ��������", i,e_total_score);*/
		E_num_Q_boss++;//���� �� ���;
		drawtopbar();
		gotoxy(76, 10);
		printf("�� SCORE�� %010d", total_score);//���� �˰��� ����********5/26����
		gotoxy(25, 10);
		printf(" �ʵ��б� ���� ���� - ���� %d ��\n", i);

		//������ Ȯ�ο�//****5/26����
		gotoxy(25, 13);
		printf("total %d / correct %d / time bonus %d %d", eboss_total_score, eboss_correct_score, eboss_time_bonus, eboss_combo_bonus);

		// ���� ����
		gotoxy(32, 17);
		printf("���� : ");
		random_word(EBOSS, word);
		gotoxy(32, 15);
		///***** 5/24 (����) - ���ѽð� �������� ����
		printf("���� : %d �� / ���ѽð�: %d ��", Bscore, Boss_time);
		start = time(0);

		// ���� ���߱� & ���
		gotoxy(32, 19);
		printf("������ ���� ġ���� : ");
		result = game(EBOSS, Boss_time, input, word, E_num_Q_boss);
		end = time(0);

		//���� �ݿ� �˰��� ����****** score.c �������ּ��� -5/26����
		if (result) {
			boss_correct_score(ELEMENTARY, Bscore);
			boss_time_bonus(ELEMENTARY, TimeBonus(time_left));

			if (O_X[E_num_Q_boss - 2] == 1)
			{
				boss_combo_bonus(ELEMENTARY);
			}
			combo[i - 1] = 1;
			//**** 5/24(����)�޺� �ǽð���¿� ���
			O_X[E_num_Q_boss - 1] = 1;
			E_O_BOSS++;

		}
		else {
			combo[i - 1] = 0;
			O_X[E_num_Q_boss - 1] = 0;
			//**** 5/24(����)�޺� �ǽð���¿� ���

		}

		//e_total_score += eboss_total_score;

		gotoxy(32, 28);

	}
	//�� ���� �Լ� �����ؼ� ������ �� �� ���� �ѵ� Ȥ�ø��� �ξ����ϴ�. *****5/26����
	/*
	for (int i = 1; i <= 5; i++)
	{
		if (combo[i] == 1)
			if (combo[i + 1] == 1)
				B_combo++;
	}
	eboss_combo_bonus = B_combo * 100;
	*/
}
