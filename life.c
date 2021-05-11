#include "common.h"
//life: 목숨 개수 저장 변수, 메인 함수에 int life=LIFE 선언
//#define LIFE 5
int decrease_life(int life)
{
    life--;
    return life;
    //목숨을 깎을 떄 life = decrease_life(life); 이용
}

int increase_life(int life) //물약 등
{
    life++;
    return life;
    //목숨 추가할때 (ex) 물약: life=increase_life(life) 이용
}