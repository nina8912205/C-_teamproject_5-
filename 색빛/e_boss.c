//############ 색빛 - 파일 이름 바꿨습니다.
#include "common.h"
#define EBOSS 6
#define Bscore 8000  //############ 색빛 - 보스점수 기호 상수로 선언.
 
int e_boss(int e_score) //############ 색빛 - 원래 두 함수였는데 하나로 만듦.
{
	char word[SIZE], input[SIZE];
	int boss_score = 0, result;
	extern int life, e_total_score, time_left;

	// 레이아웃
	drawline();
	drawitem();
	drawmenu();

	// 게임 스토리
	/*
	초등학교 ~ 초등학교 보스로 넘어가는 부분
	출력물 추가해야함
	ex) 보스 대사
	*/
	gotoxy(32, 15);
	printf("축하합니다");		//임시
	Sleep(1000);
	gotoxy(32, 17);
	printf("초등학교 교육과정을 무사히 마쳤습니다");	//임시
	Sleep(1000);
	gotoxy(32, 19);
	printf("초등학교 교장 선생님을 이기세요");		//임시
	Sleep(2000);
	system("cls");

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

		// 문제 맞추기 & 결과
		gotoxy(32, 19);
		printf("문제를 따라 치세요 : ");
		result = game(EBOSS, EBOSS, input, word);

		if (result)
			boss_score += Bscore;
		
		e_total_score = e_score + TimeBonus(time_left) + boss_score;
	}
	return boss_score;
}