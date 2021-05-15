#include "common.h"
#define BONUS_PER_SEC 50
int level;
//elementary() � int start,end; ����
//������ printf ���Ŀ� start=clock();, gets_S ���Ŀ� end=clock(); �ۼ�
//TimeLimit = �� �г⺰ ���ѽð�
//��ȣ����� �г⺰ ���ѽð� ���� �ʿ�
// #define E1_LIMIT	10000
// #define E2_LIMIT	9000
// #define E3_LIMIT 8000
// #define E4_LIMIT 7000
// #define E5_LIMIT 6000
// #define E6_LIMIT 5000
// #define M1_LIMIT 8000
// #define M2_LIMIT 6000
// #define M3_LIMIT 6000
// #define H1_LIMIT 9000
// #define H2_LIMIT 9000
// #define H3_LIMIT 9000


//�� �г� ������ Ǫ�� ������ ����ؾ� �� �ʿ䰡 ���� �� �����ϴ�.
//���������� int level�� �����Ͽ�, level 1~6: ��1~��6, level 7~9: ��1,2,3, level 10~12: ��1,2,3���� ������ ���ҽ��ϴ�.

//���� �ð����� ������ �ذ����� ���, ���� �ð��� �� ������ ��ȯ
//���� TimeLeft(level,start,end)
float TimeLeft(int level,clock_t start, clock_t end)
{
	float TimeLimit, TimeLeft;

	float TimeSpent = end - start;
	if (level == 1)
		TimeLimit = E1_LIMIT;
	if (level == 2)
		TimeLimit = E2_LIMIT;
	if (level == 3)
		TimeLimit = E3_LIMIT;
	if (level == 4)
		TimeLimit = E4_LIMIT;
	if (level == 5)
		TimeLimit = E5_LIMIT;
	if (level == 6)
		TimeLimit = E6_LIMIT;
	if (level == 7)
		TimeLimit = M1_LIMIT;
	if (level == 8)
		TimeLimit = M2_LIMIT;
	if (level == 9)
		TimeLimit = M3_LIMIT;
	if (level == 10)
		TimeLimit = H1_LIMIT;
	if (level == 11)
		TimeLimit = H2_LIMIT;
	if (level == 12)
		TimeLimit = H3_LIMIT;
	return (TimeLimit - TimeSpent) / 1000;

}



//���� �ð��� ���� ���ʽ� ���� ��ȯ
//��ȣ ����� #define BONUS_PER_SEC 50 (���� ����) ���� �ʿ�
//���� TimeBonus(start,end,TimeLimit(level))
int TimeBonus(clock_t start, clock_t end,int TimeLimit)
{
	return TimeLeft(start, end,TimeLimit) * BONUS_PER_SEC;
}

//Ȥ�� ���� �� �ܰ躰 ���ѽð��� �ʴ����� ��ȯ�ϴ� �Լ��� ����� �ξ����ϴ�.
//���� TimeLimit(level);
int TimeLimit(int level)
{
	int TimeLimit;
	if (level == 1)
		TimeLimit = E1_LIMIT / 1000;
	if (level == 2)
		TimeLimit = E2_LIMIT / 1000;
	if (level == 3)
		TimeLimit = E3_LIMIT / 1000;
	if (level == 4)
		TimeLimit = E4_LIMIT / 1000;
	if (level == 5)
		TimeLimit = E5_LIMIT / 1000;
	if (level == 6)
		TimeLimit = E6_LIMIT / 1000;
	if (level == 7)
		TimeLimit = M1_LIMIT / 1000;
	if (level == 8)
		TimeLimit = M2_LIMIT / 1000;
	if (level == 9)
		TimeLimit = M3_LIMIT / 1000;
	if (level == 10)
		TimeLimit = H1_LIMIT / 1000;
	if (level == 11)
		TimeLimit = H2_LIMIT / 1000;
	if (level == 12)
		TimeLimit = H3_LIMIT / 1000;
	return TimeLimit;
}