/* 목숨 증감 */
#include "common.h"

/* 목숨 감소 - 문제 실패 시 */
int decrease_life()
{
    extern int life;  // life: 목숨 개수 저장 변수

    life--;
    return life;
}

/* 목숨 증가 - 물약 아이템 획득 시 */
int increase_life() 
{
    extern int life;

    life++;
    return life;

}