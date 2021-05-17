#include "common.h"
#define BONUS_PER_SEC 50  
int level;


//elementary() � int start,end; ����
//������ printf ���Ŀ� start=clock();, gets_S ���Ŀ� end=clock(); �ۼ�
//TimeLimit = �� �г⺰ ���ѽð�
//��ȣ����� �г⺰ ���ѽð� ���� �ʿ�
// 

//@@@@@@@@@@@@@@@@
/* level �� ���ѽð� */
/* level 1 ~ 6 : �ʵ��б� �г� �� ���ѽð� */
#define E1_LIMIT 10000
#define E2_LIMIT 9000
#define E3_LIMIT 8000
#define E4_LIMIT 7000
#define E5_LIMIT 6000
#define E6_LIMIT 5000

/* level 7 ~ 9 : ���б� �г� �� ���ѽð� */
#define M1_LIMIT 8000
#define M2_LIMIT 6000
#define M3_LIMIT 6000

/* level 10 ~ 12 : ����б� �г� �� ���ѽð� */
#define H1_LIMIT 9000
#define H2_LIMIT 9000
#define H3_LIMIT 9000


//�� �г� ������ Ǫ�� ������ ����ؾ� �� �ʿ䰡 ���� �� �����ϴ�.
//���������� int level�� �����Ͽ�, level 1~6: ��1~��6, level 7~9: ��1,2,3, level 10~12: ��1,2,3���� ������ ���ҽ��ϴ�.

//���� �ð����� ������ �ذ����� ���, ���� �ð��� �� ������ ��ȯ
//���� TimeLeft(level,start,end)


/* level �� ���ѽð� ��ȯ �Լ� */
int TimeLimit(int level)
{

	switch (level)    //@@@@@@@@@@@@@@@ if �� switch�� ���� 
	{
	case 1:
		return E1_LIMIT;
		break;
	case 2:
		return E2_LIMIT;
		break;
	case 3:
		return E3_LIMIT;
		break;
	case 4:
		return E4_LIMIT;
		break;
	case 5:
		return E5_LIMIT;
		break;
	case 6:
		return  E6_LIMIT;
		break;
	case 7:
		return  M1_LIMIT;
		break;
	case 8:
		return  M2_LIMIT;
		break;
	case 9:
		return  M3_LIMIT;
		break;
	case 10:
		return  H1_LIMIT;
		break;
	case 11:
		return  H2_LIMIT;
		break;
	case 12:
		return  H3_LIMIT;
		break;
	}


}

/*���� �ð����� ������ �ذ����� ���, ���� �ð��� �� ������ ��ȯ*/
double TimeLeft(double timelimit, clock_t start, clock_t end)
{
	double TimeSpent = end - start;

	return (timelimit - TimeSpent) / 1000;
}



//���� �ð��� ���� ���ʽ� ���� ��ȯ
//��ȣ ����� #define BONUS_PER_SEC 50 (���� ����) ���� �ʿ�
//���� TimeBonus(start,end,TimeLimit(level))
double TimeBonus(clock_t start, clock_t end, int timelimit)   // @@@@@@@@@@@@@@@@@@@ ��ȯ�� double �̹Ƿ� int -> double �� ��ħ
{
	return TimeLeft(timelimit,start,end) * BONUS_PER_SEC;
}

//Ȥ�� ���� �� �ܰ躰 ���ѽð��� �ʴ����� ��ȯ�ϴ� �Լ��� ����� �ξ����ϴ�.
//���� TimeLimit(level);
//int TimeLimit(int level)
//{
//	int TimeLimit;
//	if (level == 1)
//		TimeLimit = E1_LIMIT / 1000;  // 10��
//	if (level == 2)
//		TimeLimit = E2_LIMIT / 1000;
//	if (level == 3)
//		TimeLimit = E3_LIMIT / 1000;
//	if (level == 4)
//		TimeLimit = E4_LIMIT / 1000;
//	if (level == 5)
//		TimeLimit = E5_LIMIT / 1000;
//	if (level == 6)
//		TimeLimit = E6_LIMIT / 1000;
//	if (level == 7)
//		TimeLimit = M1_LIMIT / 1000;
//	if (level == 8)
//		TimeLimit = M2_LIMIT / 1000;
//	if (level == 9)
//		TimeLimit = M3_LIMIT / 1000;
//	if (level == 10)
//		TimeLimit = H1_LIMIT / 1000;
//	if (level == 11)
//		TimeLimit = H2_LIMIT / 1000;
//	if (level == 12)
//		TimeLimit = H3_LIMIT / 1000;
//	return TimeLimit;
//}