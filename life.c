#include "common.h"
//life: ��� ���� ���� ����, ���� �Լ��� int life=LIFE ����
//#define LIFE 5
int decrease_life(int life)
{
    life--;
    return life;
    //����� ���� �� life = decrease_life(life); �̿�
}

int increase_life(int life) //���� ��
{
    life++;
    return life;
    //��� �߰��Ҷ� (ex) ����: life=increase_life(life) �̿�
}