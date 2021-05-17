/* 목숨 증감 */
#include "common.h"

/* 목숨 감소 - 문제 실패 시 */
int decrease_life()
{
    extern int life;  // life: 목숨 개수 저장 변수

    life--;

	if (life == 0)
	{
		gotoxy(32, 23);
		printf("목숨이 없습니다. 안타깝게도 게임에 실패하셨습니다.");
		gotoxy(32, 25);
		printf("게임을 종료합니다.");
		Sleep(2000);
		game_title();
	}

    return life;
}

/* 목숨 증가 - 물약 아이템 획득 시 */
int increase_life() 
{
    extern int life;

    life++;
    return life;

}