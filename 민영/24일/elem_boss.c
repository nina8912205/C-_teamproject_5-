//############ 색빛 - 파일 이름 바꿨습니다.
#include "common.h"
#define EBOSS 6	//글자 수
#define Bscore 8000  //############ 색빛 - 보스점수 기호 상수로 선언.
int Boss_time = 6;

int e_boss(int e_score) //############ 색빛 - 원래 두 함수였는데 하나로 만듦.
{
	char word[SIZE], input[SIZE];
	char item;
	int boss_score = 0, result;
	int time_bonus = 0;
	int start, end, B_combo = 0, time_score = 0;
	int combo[5] = {0, 0, 0, 0, 0};
	extern int life, e_total_score, time_left;
	extern int addtime;

	// 레이아웃
	drawline();
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
		drawline();
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
			addtime -= 1;
			Boss_time += 1;
		}
		else if(item == 'n'){
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

		drawline();
		drawitem();
		drawmenu();
		drawtopbar();
		gotoxy(76, 10);
		printf("│ SCORE│ %010d", e_total_score);
		gotoxy(25, 10);
		printf(" 초등학교 졸업 시험 - 문제 %d 번\n", i);

		// 문제 출제
		gotoxy(32, 17);
		printf("문제 : ");
		random_word(EBOSS, word);
		gotoxy(70, 17);
		printf("배점 : %d 점", Bscore);
		start = time(0);

		// 문제 맞추기 & 결과
		gotoxy(32, 19);
		printf("문제를 따라 치세요 : ");
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