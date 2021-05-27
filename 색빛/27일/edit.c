#include "common.h"

void drawline(int x, int y, int w, int h) // 테두리 출력
{
	int i;

	gotoxy(x, y);
	printf("┌");
	for (i = 0; i < w; i++)
		printf("─");
	printf("┐");
	for (i = y + 1; i <= h + y; i++)
	{
		gotoxy(x, i); printf("│");
		gotoxy(x + w + 1, i); printf("│\n");
	}
	gotoxy(x, y + h + 1);
	printf("└");
	for (i = 0; i < w; i++)
		printf("─");
	printf("┘");
}


void drawmenu()
{
	gotoxy(21, 35);
	printf("[ ESC 게임메뉴 ] P 일시정지│ R 게임방법│ L 난이도변경│ S 시작화면│ Q 게임종료 ");
}

void draws_boss(char* sch, int num, int score)
{
	drawtopbar();

	/* 글씨 */
	gotoxy(25, 10);
	printf(" %s - 문제 %d 번", sch, num);
	gotoxy(76, 10);
	printf("│ SCORE│ %010d", score);
}

void drawitem() // 아이템, 목숨 출력
{
	int i;
	extern int life, addtime, changeword;
	gotoxy(21, 7);
	printf("│  LIFE │ ");
	for (i = 0; i < life; i++)
		printf("♥ ");
	gotoxy(55, 7);
	printf("│  ITEM │  단어바꾸기[TAB]: %d  시간증가: %d ", changeword, addtime);
}

void draws(char* sch, int grade, int num)
{
	extern int TotalScore;
	char school[10];

	drawtopbar();

	/* 내용 */
	strcpy(school, sch);

	/* 글씨 */
	gotoxy(25, 10);
	printf("│ SCHOOL│ %s학교", school);
	printf("\t│ GRADE│ %d학년", grade);
	printf("\t│ NO│ %d ", num);
	gotoxy(76, 10);
	printf("│ SCORE│ %010d", TotalScore);
}

void drawtopbar()
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
}

void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void cursor(int n)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}