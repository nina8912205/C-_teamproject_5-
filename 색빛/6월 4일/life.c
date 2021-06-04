/* 목숨 증감 */
#include "common.h"

/* 목숨 감소 - 문제 실패 시 */
void decrease_life(int* item)
{
	item[LIFE]--;

	if (item[LIFE] == 0)
	{
		gotoxy(30, 7); printf("   ");
		gameover();
		clear(29, 24, 30, 6);
		gotoxy(52, 25);	printf("목숨이 없습니다.");
		gotoxy(51, 27);	printf("게임을 종료합니다.");
		Sleep(2000);
	}
}
void gameover()
{
	cursor(0);
	clear(29, 16, 30, 6);
	gotoxy(32, 16); printf("  ■■    ■   ■  ■  ■■    ■    ■  ■  ■■  ■■\n");
	gotoxy(32, 17); printf("■      ■  ■ ■■■  ■    ■  ■  ■  ■  ■    ■  ■\n");
	gotoxy(32, 18); printf("■  ■  ■■■ ■  ■  ■■  ■  ■  ■  ■  ■■  ■■ \n");
	gotoxy(32, 19); printf("■  ■  ■  ■ ■  ■  ■    ■  ■  ■  ■  ■    ■  ■\n");
	gotoxy(32, 20); printf("■■    ■  ■ ■  ■  ■■    ■      ■    ■■  ■  ■\n");
}
