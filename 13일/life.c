/* ��� ���� */
#include "common.h"

/* ��� ���� - ���� ���� �� */
int decrease_life()
{
    extern int life;  // life: ��� ���� ���� ����

    life--;
    return life;
}

/* ��� ���� - ���� ������ ȹ�� �� */
int increase_life() 
{
    extern int life;

    life++;
    return life;

}