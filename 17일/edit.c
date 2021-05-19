#include "common.h"

void drawline() // 테두리 출력
{
	int i;

	gotoxy(21, 8);
	printf("┌");
	for (i = 0; i < 75; i++)
		printf("─");
	printf("┐");
	for (i = 9; i < 34; i++)
	{
		gotoxy(21, i); printf("│");
		gotoxy(97, i); printf("│\n");
	}
	gotoxy(21, 34);
	printf("└");
	for (i = 0; i < 75; i++)
		printf("─");
	printf("┘");
}

void drawmenu()  // 메뉴 출력
{
	gotoxy(22, 35);
	printf("│ M 게임메뉴│ P 일시정지│ R 게임방법│ L 난이도변경│ S 시작화면│ Q 게임종료│ ");
}

void drawitem() // 아이템, 목숨 출력
{
	int i;
	extern int life, addtime, changeword;
	gotoxy(21, 7);
	printf("│  LIFE │ ");
	for (i = 0; i < life; i++)
		printf("♥ ");
	gotoxy(60, 7);
	printf("│  ITEM │  단어바꾸기: %d  시간증가: %d ", changeword, addtime);
}


void draws(char sch[10], int grade, int num, int score)
{
	/* 상단바 테두리 */
	int i;
	gotoxy(23, 9);
	printf("┌");
	for (i = 0; i < 71; i++)
		printf("─");
	printf("┐");
	gotoxy(23, 10); printf("│");
	gotoxy(95, 10); printf("│\n");
	gotoxy(23, 11);
	printf("└");
	for (i = 0; i < 71; i++)
		printf("─");
	printf("┘");
	
	/* 내용 */
	strcpy(school, sch);

	/* 글씨 */
	gotoxy(25, 10);
	printf("│ SCHOOL│ %s학교", school);
	printf("\t│ GRADE│ %d학년", grade);
	printf("\t│ NO│ %d ", num);
	gotoxy(76, 10);
	printf("│ SCORE│ %010d", score);    
}
