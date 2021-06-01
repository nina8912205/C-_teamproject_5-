﻿#include "common.h"
#define EBOSS 6

int E_Boss_time = 6;

void e_boss()
{
	extern int life, addtime;
	extern int time_left, scorearray[SCHSIZE][ASIZE], TotalScore, O_X[];

	char word[SIZE], input[SIZE], item;
	int use = 0, i;
	int start, end, result;
	int combo[5] = { 0 };

	resetOX();

	// 레이아웃
	drawline(21, 8, 75, 25);
	drawitem();
	drawmenu();

	// 게임 스토리
	gotoxy(32, 15);	printf("축하합니다");
	Sleep(1000);
	gotoxy(32, 17);	printf("초등학교 교육과정을 무사히 마쳤습니다");
	Sleep(1000);
	gotoxy(32, 19);	printf("초등학교 교장 선생님을 이기세요");
	Sleep(2000);
	system("cls");

	if (addtime >= 1) {
		drawline(21, 8, 75, 25);
		drawitem();
		drawmenu();
		gotoxy(32, 15);	printf("시간 추가 아이템이 있습니다.");
		Sleep(1000);
		gotoxy(32, 17);	printf("사용하시겠습니까? [y/n]");

		item = _getch();
		if (item == 'y') {
			gotoxy(32, 19);	printf("아이템을 몇 개 사용하시겠습니까? ");
			Sleep(1000);
			scanf("%d", &use);
			getchar();
			gotoxy(32, 21);	printf("아이템을 사용합니다.");
			Sleep(1000);
			gotoxy(32, 23); printf("제한시간이 %d초 늘어납니다.", use);
			Sleep(2000);
			for (i = 0; i < use; i++) {
				addtime--;
				E_Boss_time++;
			}
		}
		else if (item == 'n') {
			gotoxy(32, 19);	printf("아이템을 사용하지 않습니다.");
			Sleep(1000);
		}
		system("cls");
	}

	// 게임 진행
	for (int i = 1; i <= 1; i++)
	{
		// 목숨 검사
		if (life == 0)
			break;

		drawline(21, 8, 75, 25);
		drawitem();
		drawmenu();
		scorearray[E][B_Q_SOLVED]++;
		drawtopbar();
		gotoxy(76, 10);	printf("│ SCORE│ %010d", TotalScore);
		gotoxy(25, 10);	printf(" 초등학교 졸업 시험 - 문제 %d 번\n", i);

		// 문제 출제
		gotoxy(32, 18);	printf("문제 : ");
		random_word(EBOSS, word);
		gotoxy(70, 17);	printf("배점 : %d 점", E_Bscore);
		start = time(0);

		// 문제 맞추기 & 결과
		gotoxy(32, 19);	printf("문제를 따라 치세요 : ");
		result = game(E_Boss_time, input, word, scorearray[E][B_Q_SOLVED],E,1,E_Bscore);
		end = time(0);

		if (result) {
			/*
			boss_correct(E, E_Bscore);
			boss_time(E, TimeBonus(time_left));

			if (O_X[scorearray[E][B_Q_SOLVED] - 2] == 1)
				boss_combo(E);*/

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