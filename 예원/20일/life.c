/* ��� ���� */
#include "common.h"

//////5/19 �߰�(����)
int die = 0;//�׾����� ���

/* ��� ���� - ���� ���� �� */
int decrease_life()
{
    extern int life;  // life: ��� ���� ���� ����
	extern int die;

    life--;

	if (life == 0)
	{
		gotoxy(32, 23);
		printf("����� �����ϴ�. ��Ÿ���Ե� ���ӿ� �����ϼ̽��ϴ�.");
		gotoxy(32, 25);
		printf("������ �����մϴ�.");
		Sleep(2000);
		
		die = 1;  //// 5/19 �߰�(����) ���� �Լ����� Ÿ��Ʋ�� ���ư� �� �ֵ��� �׾����� ���.
	}

    return life;
}

/* ��� ���� - ���� ������ ȹ�� �� */
int increase_life() 
{
    extern int life;

    life++;
    return life;

}