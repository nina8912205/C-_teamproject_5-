#include "common.h"
#define EBOSS 6
#define Bscore 8000
int Boss_time = 6;

int E_O_BOSS = 0;	//초등학교 보스에서 맞은 문제 수 기록

void e_boss()
{
	extern int life, addtime;
	extern int time_left, scorearray[GRADESIZE][SSIZE], TotalScore, O_X[];

	char word[SIZE], input[SIZE], item;
	int start, end, result;
	int combo[5] = { 0 };

	resetOX();

	// 레이아웃
	drawline(21, 8, 75, 25);
	drawitem();
	drawmenu();

	// 게임 스토리
	gotoxy(32, 15);
	printf("축하합니다");
	Sleep(1000);
	gotoxy(32, 17);
	printf("초등학교 교육과정을 무사히 마쳤습니다");
	Sleep(1000);
	gotoxy(32, 19);
	printf("초등학교 교장 선생님을 이기세요");
	Sleep(2000);
	system("cls");
	if (addtime >= 1) {
		drawline(21, 8, 75, 25);
		drawitem();
		drawmenu();
		gotoxy(32, 15);
		printf("시간 추가 아이템이 있습니다.");
		Sleep(1000);
		gotoxy(32, 17);
		printf("사용하시겠습니까? [y/n]");
		item = _getch();
		if (item == 'y') {
			gotoxy(32, 19);
			printf("아이템을 사용합니다.");
			Sleep(1000);
			gotoxy(32, 21);
			printf("제한 시간이 1초 늘어납니다.");
			Sleep(1000);
			addtime--;
			Boss_time++;
		}
		else if (item == 'n') {
			gotoxy(32, 19);
			printf("아이템을 사용하지 않습니다.");
			Sleep(1000);
		}
		system("cls");
	}

	// 게임 진행
	for (int i = 1; i <= 5; i++)
	{
		// 목숨 검사
		if (life == 0)
			break;

		drawline(21, 8, 75, 25);
		drawitem();
		drawmenu();
		scorearray[E][B_Q_SOLVED]++;
		drawtopbar();
		gotoxy(76, 10);
		printf("│ SCORE│ %010d", TotalScore);
		gotoxy(25, 10);
		printf(" 초등학교 졸업 시험 - 문제 %d 번\n", i);

		// 문제 출제
		gotoxy(32, 18);
		printf("문제 : ");
		random_word(EBOSS, word);
		gotoxy(70, 17);
		printf("배점 : %d 점", Bscore);
		start = time(0);

		// 문제 맞추기 & 결과
		gotoxy(32, 19);
		printf("문제를 따라 치세요 : ");
		result = game(EBOSS, Boss_time, input, word, scorearray[E][B_Q_SOLVED]);
		end = time(0);

		if (result) {
			boss_correct(ELEMENTARY, Bscore);
			boss_time(ELEMENTARY, TimeBonus(time_left));

			if (O_X[scorearray[E][B_Q_SOLVED] - 2] == 1)
				boss_combo(ELEMENTARY);

			combo[i - 1] = 1;
			O_X[scorearray[E][B_Q_SOLVED] - 1] = 1;
			scorearray[E][B_Q_CORRECT]++;
		}
		else {
			combo[i - 1] = 0;
			O_X[scorearray[E][B_Q_SOLVED] - 1] = 0;
		}
	}
}