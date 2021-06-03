#include "common.h"

void Final_Scorecard()
{
	extern char name[];
	extern int life, TotalScore, SCORE[SCHSIZE][ASIZE];
	int grade;

	drawline(21, 8, 75, 25);
	drawitem();
	drawmenu();

	if (TotalScore < 10000)
		grade = 9;
	else if (10000 <= TotalScore && TotalScore < 20000)
		grade = 8;
	else if (20000 <= TotalScore && TotalScore < 30000)
		grade = 7;
	else if (30000 <= TotalScore && TotalScore < 40000)
		grade = 6;
	else if (40000 <= TotalScore && TotalScore < 50000)
		grade = 5;
	else if (50000 <= TotalScore && TotalScore < 60000)
		grade = 4;
	else if (60000 <= TotalScore && TotalScore < 70000)
		grade = 3;
	else if (70000 <= TotalScore && TotalScore < 80000)
		grade = 2;
	else
		grade = 1;

	gotoxy(55, 10);	printf("! 축하합니다 !");
	gotoxy(45, 11);	printf("! 교육 과정을 모두 이수하셨습니다 !");
	gotoxy(75, 13);	printf("이름: %s\n", name);

	gotoxy(28, 15);	printf("|초등학교| - ");
	print_phrase(E);	
	gotoxy(28, 17);	printf("맞은 문제수 / 푼 문제수: ");
	gotoxy(53, 17);	printf("%d  /  %d", SCORE[E][Q_CORRECT] + SCORE[E][B_Q_CORRECT], SCORE[E][Q_SOLVED] + SCORE[E][B_Q_SOLVED]);
	gotoxy(65, 17);	printf("획득 점수: %6d 점", SCORE[E][TOTAL] + SCORE[E][BOSS]);

	gotoxy(28, 20);	printf("| 중학교 | - ");
	print_phrase(M);
	gotoxy(28, 22);	printf("맞은 문제수 / 푼 문제수: ");
	gotoxy(53, 22);	printf("%d  /  %d", SCORE[M][Q_CORRECT] + SCORE[M][B_Q_CORRECT], SCORE[M][Q_SOLVED] + SCORE[M][B_Q_SOLVED]);
	gotoxy(65, 22); printf("획득 점수: %6d 점", SCORE[M][TOTAL] + SCORE[M][BOSS]);

	gotoxy(28, 25);	printf("|고등학교| - ");
	print_phrase(H);
	gotoxy(28, 27);	printf("맞은 문제수 / 푼 문제수: ");
	gotoxy(53, 27);	printf("%d  /  %d", SCORE[H][Q_CORRECT] + SCORE[H][B_Q_CORRECT], SCORE[H][Q_SOLVED] + SCORE[H][B_Q_SOLVED]);
	gotoxy(65, 27);	printf("획득 점수: %6d 점", SCORE[H][TOTAL] + SCORE[H][BOSS]);

	gotoxy(27, 29);	printf("-------------------------------------------------------------");
	gotoxy(28, 30);	printf("총 획득 점수: %d 점 / %d 등급\n", TotalScore, grade);
}

void print_phrase(int level)
{
	extern int SCORE[SCHSIZE][ASIZE];
	int score = SCORE[level][TOTAL] + SCORE[level][BOSS];
	
	switch (level)
	{
	case E:
		if (score < 60000)
			printf("조금 더 연습해보아요!");
		else
			printf("잘했습니다!");
		break;
	case M:
		if (score < 45000)
			printf("조금 더 연습해보아요!");
		else
			printf("잘했습니다!");
		break;
	case H:
	{
		if (score < 45000)
			printf("조금 더 연습해보아요!");
		else
			printf("잘했습니다!");
		break;
	}
	}
}

// 학년별 성적표
int Scorecard(int level)
{
	extern char name[100], sch[SCHSIZE][SIZE];
	extern int TotalScore, item[3];
	extern int SCORE[SCHSIZE][ASIZE];

	char ch;
	int go;
	int t1 = 0, sec = 1;

	drawline(21, 8, 75, 25);

	if (item[LIFE])
	{
		system("cls");
		KU(1);
		drawline(21, 8, 75, 25);
		gotoxy(45, 12);	printf("! %s학교 졸업을 축하합니다 ! \n\n", sch[level]);
	}
	else
	{
		system("cls");
		KU(0);
		drawline(21, 8, 75, 25);
		gotoxy(45, 12);	printf(" --  조금 더 연습해보아요!  --");
	}

	gotoxy(75, 14); printf("이름: %s\n", name);
	gotoxy(58, 16); printf("학교");
	gotoxy(73, 16); printf("교장");
	gotoxy(28, 18); printf("맞은 문제수 / 푼 문제수");
	gotoxy(35, 20); printf("획득 점수");
	gotoxy(33, 22); printf("시간 추가 점수");
	gotoxy(35, 24);	printf("콤보 점수");
	gotoxy(57, 18);	printf("%d / %d", SCORE[level][Q_CORRECT], SCORE[level][Q_SOLVED]);
	gotoxy(72, 18); printf("%d / %d", SCORE[level][B_Q_CORRECT], SCORE[level][B_Q_SOLVED]);
	gotoxy(54, 20); printf("%7d 점", SCORE[level][CORRECT]);
	gotoxy(69, 20);	printf("%7d 점", SCORE[level][B_CORRECT]);
	gotoxy(54, 22); printf("%7d 점", SCORE[level][TIME]);
	gotoxy(69, 22); printf("%7d 점", SCORE[level][B_TIME]);
	gotoxy(56, 24); printf("%4d 점", SCORE[level][COMBO]);
	gotoxy(71, 24); printf("%4d 점", SCORE[level][B_COMBO]);
	gotoxy(56, 25); printf("(%d COMBO)", SCORE[level][COMBO] / BonusPerCombo);
	gotoxy(71, 25); printf("(%d COMBO)", SCORE[level][B_COMBO] / BonusPerCombo);
	gotoxy(27, 26); printf("________________________________________________________________");
	gotoxy(37, 28); printf("합계");
	gotoxy(56, 28); printf("%d 점", SCORE[level][TOTAL]);
	gotoxy(72, 28); printf("%d 점", SCORE[level][BOSS]);
	gotoxy(67, 30); printf("총점: %7d 점", SCORE[level][TOTAL] + SCORE[level][BOSS]);
	gotoxy(67, 32); printf("누적: %7d 점", TotalScore);

	gotoxy(25, 31);
	if (item[LIFE] == 0)
		printf("아무키나 누르면 메인메뉴로 돌아갑니다.\n");
	else if (level == H)
		printf("최종성적표가 도착했습니다.");
	else
		printf("아무키나 누르면 다음학교로 진학합니다. 메인 메뉴로 돌아가시려면 ESC키를 눌러주세요\n");
			
	t1 = time(0);
	gotoxy(67, 33);  printf("5");
	
	while (1)
	{
		if (time(0) == t1 + sec)
		{
			cursor(0);
			gotoxy(67, 33); printf("\b %d", 5 - sec);
			sec++;

			if (sec > 5) return 1;
		}		
		if (_kbhit())
		{
			ch = _getch();
			if (ch == ESC)
				go = 0;
			else
				go = 1;
			break;
		}		
	}
	system("cls");
	return go;
}

void KU(int type)
{
	cursor(0);
	gotoxy(0, 9);
	printf("\t\t\t\t            ■■                      ■■\n");
	printf("\t\t\t\t            ■  ■    ■■■■■    ■  ■\n");
	printf("\t\t\t\t            ■    ■■          ■■    ■\n");
	printf("\t\t\t\t            ■  ■■              ■■  ■\n");
	printf("\t\t\t\t        ■■■■        ■    ■      ■■■■\n");
	printf("\t\t\t\t    ■■  ■            ■    ■          ■  ■■\n");
	printf("\t\t\t\t  ■      ■      ■      ■  ■  ■      ■      ■\n");
	printf("\t\t\t\t■      ■      ■          ■      ■      ■      ■\n");
	printf("\t\t\t\t■      ■                                  ■      ■\n");
	switch (type)
	{
	case 0:
		printf("\t\t\t\t  ■■■                                      ■■■\n");
		printf("\t\t\t\t      ■      ■■■■■      ■■■■■      ■\n");
		printf("\t\t\t\t      ■        ■  ■          ■  ■        ■\n");
		break;
	case 1:
		printf("\t\t\t\t  ■■■          ■              ■          ■■■\n");
		printf("\t\t\t\t      ■        ■  ■          ■  ■        ■\n");
		printf("\t\t\t\t      ■                                      ■\n");
		break;
	case 2:
		printf("\t\t\t\t  ■■■            ■            ■          ■■■\n");
		printf("\t\t\t\t      ■          ■■          ■■          ■\n");
		printf("\t\t\t\t      ■          ■■          ■■          ■\n");
		break;
	case 3:
		printf("\t\t\t\t  ■■■          ■              ■          ■■■\n");
		printf("\t\t\t\t      ■            ■          ■            ■\n");
		printf("\t\t\t\t      ■          ■              ■          ■\n");
		break;
	case 4:
		printf("\t\t\t\t  ■■■            ■            ■          ■■■\n");
		printf("\t\t\t\t      ■      ■  ■■  ■■■  ■■  ■      ■\n");
		printf("\t\t\t\t      ■        ■■■■      ■■■■        ■\n");
		break;
	}
	
	printf("\t\t\t\t    ■                  ■  ■                  ■\n");
	printf("\t\t\t\t    ■            ■■■■■■■■■            ■\n");
	printf("\t\t\t\t    ■        ■■■              ■■■        ■\n");
	switch (type)
	{
	case 0:
		printf("\t\t\t\t    ■    ■■          ■■■          ■■    ■\n");
		printf("\t\t\t\t    ■  ■            ■      ■            ■  ■\n");
		break;
	case 1:
	case 2:
	case 3:
	case 4:
		printf("\t\t\t\t    ■    ■■        ■      ■        ■■    ■\n");
		printf("\t\t\t\t    ■  ■              ■■■              ■  ■\n");
		break;
	}
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t        ■                                  ■\n");
	printf("\t\t\t\t        ■■                              ■■\n");
	printf("\t\t\t\t            ■■                      ■■\n");
	printf("\t\t\t\t              ■■                  ■■\n");
	printf("\t\t\t\t                  ■■■■■■■■■\n");
	Sleep(700);
	system("cls");
}
