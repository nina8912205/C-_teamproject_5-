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
