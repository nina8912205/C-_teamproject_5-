//############ 색빛 - 파일 이름 바꿨습니다.
#include "common.h"
#define EBOSS 6	//글자 수
#define Bscore 8000  //############ 색빛 - 보스점수 기호 상수로 선언.
int Boss_time = 6;

//5/26 현욱	- 변수 새로 선언******************
int E_num_Q_boss = 0;//초등학교 보스에서 푼 문제 수 기록
int E_O_BOSS = 0;	//초등학교 보스에서 맞은 문제 수 기록

void e_boss() //############ 색빛 - 원래 두 함수였는데 하나로 만듦.
{
	resetOX();
	char word[SIZE], input[SIZE];
	char item;
	///****5/26 현욱 - 점수 관련 모두 수정
	extern int total_score,eboss_total_score, eboss_correct_score, eboss_time_bonus, eboss_combo_bonus;
	extern int O_X[MAX_Q];
	extern int life, e_total_score, time_left;
	extern int addtime;
	int result;
	int start, end, B_combo = 0, time_score = 0;
	int combo[5] = { 0 };//함수를 조금 수정하여 당장은 쓰이지는 않지만, 혹시 몰라 두었습니다. (현욱)
	


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

		drawline();
		drawitem();
		drawmenu();
		/*draws_boss("초등학교 졸업시험", i,e_total_score);*/
		E_num_Q_boss++;//문제 수 기록;
		drawtopbar();
		gotoxy(76, 10);
		printf("│ SCORE│ %010d", total_score);//점수 알고리즘 수정********5/26현욱
		gotoxy(25, 10);
		printf(" 초등학교 졸업 시험 - 문제 %d 번\n", i);

		//변수값 확인용//****5/26현욱
		gotoxy(25, 13);
		printf("total %d / correct %d / time bonus %d %d", eboss_total_score, eboss_correct_score, eboss_time_bonus, eboss_combo_bonus);

		// 문제 출제
		gotoxy(32, 17);
		printf("문제 : ");
		random_word(EBOSS, word);
		gotoxy(32, 15);
		///***** 5/24 (현욱) - 제한시간 나오도록 수정
		printf("배점 : %d 점 / 제한시간: %d 초", Bscore, Boss_time);
		start = time(0);

		// 문제 맞추기 & 결과
		gotoxy(32, 19);
		printf("문제를 따라 치세요 : ");
		result = game(EBOSS, Boss_time, input, word, E_num_Q_boss);
		end = time(0);

		//점수 반영 알고리즘 수정****** score.c 참조해주세요 -5/26현욱
		if (result) {
			boss_correct_score(ELEMENTARY, Bscore);
			boss_time_bonus(ELEMENTARY, TimeBonus(time_left));

			if (O_X[E_num_Q_boss - 2] == 1)
			{
				boss_combo_bonus(ELEMENTARY);
			}
			combo[i - 1] = 1;
			//**** 5/24(현욱)콤보 실시간출력에 사용
			O_X[E_num_Q_boss - 1] = 1;
			E_O_BOSS++;

		}
		else {
			combo[i - 1] = 0;
			O_X[E_num_Q_boss - 1] = 0;
			//**** 5/24(현욱)콤보 실시간출력에 사용

		}

		//e_total_score += eboss_total_score;

		gotoxy(32, 28);

	}
	//요 밑은 함수 수정해서 지워도 될 것 같긴 한데 혹시몰라 두었습니다. *****5/26현욱
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
