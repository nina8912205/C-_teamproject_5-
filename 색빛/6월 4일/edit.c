#include "common.h"

// 테두리 출력[(x, y): 시작위치, w: 너비, h: 높이]
void drawline(int x, int y, int w, int h) 
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

// 메뉴 출력
void drawmenu()
{
	gotoxy(27, 35);	printf("[ ESC 게임메뉴 ] R 게임방법│ L 난이도변경│ S 시작화면│ Q 게임종료 ");
}

// 아이템, 목숨 출력
void drawitem()
{
	extern int item[3];

	// 목숨 
	gotoxy(21, 7);	printf("│  LIFE │ ");
	for (int i = 0; i < item[LIFE]; i++) 
		printf("♥ ");

	// 아이템 보유량
	gotoxy(55, 7);
	printf("│  ITEM │  단어바꾸기[TAB]: %d  시간증가: %d ", item[CHANGEWORD], item[ADDTIME]);
}

// 기본 레이아웃[level: 학교, grade: 학년, num: 문제 번호, score: 배점]
void layout(int level, int grade, int num)
{
	extern int TotalScore;
	extern char sch[SCHSIZE][SIZE];
	int score = scoreboard(level, grade);

	system("cls");

	// 바깥 테두리, 아이템, 메뉴
	drawline(21, 8, 75, 25);
	drawitem();
	drawmenu();

	// 문제 출력창
	drawline(28, 15, 61, 6);
	gotoxy(55, 16); printf("│  문제 │ ");

	// 입력창
	drawline(28, 23, 61, 6);
	gotoxy(55, 24); printf("│  입력 │");

	// 배점
	gotoxy(76, 14); printf("│ 배점│ %d 점", score);

	// 상단바[학교, 학년, 문제 번호, 총 점수] 출력
	drawline(23, 9, 71, 1);
	gotoxy(25, 10);
	printf("│ SCHOOL│ %s학교", sch[level]);
	printf("\t│ GRADE│ %d학년", grade);
	printf("\t│ NO│ %d ", num);
	gotoxy(76, 10); printf("│ SCORE│ %010d", TotalScore);
}

// 졸업시험 레이아웃[level: 학교, num: 문제 번호, score: 배점]
void test_layout(int level, int num)
{
	extern char sch[SCHSIZE][SIZE];
	extern int TotalScore;
	int score = scoreboard(T, level);

	system("cls");

	drawline(21, 8, 75, 25);
	drawitem();
	drawmenu();

	drawline(28, 15, 61, 6);
	gotoxy(55, 16); printf("│  문제 │ ");

	drawline(28, 23, 61, 6);
	gotoxy(55, 24); printf("│  입력 │");

	gotoxy(76, 14); printf("│ 배점│ %d 점", score);

	drawline(23, 9, 71, 1);
	gotoxy(25, 10);
	printf("%s학교 졸업시험 - %d번", sch[level], num);
	gotoxy(76, 10);
	printf("│ SCORE│ %010d", TotalScore);
}

// 내용 삭제[(x, y): 시작위치, w: 너비, h: 높이]
void clear(int x, int y, int w, int h) // 내용만 지우기
{
	for (int i = 0; i < h; i++)
	{
		gotoxy(x, y + i);
		for (int j = 0; j < w; j++)
			printf("  ");
		printf("\n");
	}
}

// 커서 이동(x, y)
void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// 커서 유무 [(n) 0: 커서X, 1: 커서O] 
void cursor(int n)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

// 글자색 바꾸기 [n: 색] 
void textcolor(int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
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
