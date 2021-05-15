#include "common.h"
#define BONUS_PER_SEC 50
int level;
//elementary() 등에 int start,end; 선언
//문제의 printf 직후에 start=clock();, gets_S 직후에 end=clock(); 작성
//TimeLimit = 각 학년별 제한시간
//기호상수로 학년별 제한시간 정의 필요
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


//몇 학년 문제를 푸는 중인지 기록해야 될 필요가 있을 것 같습니다.
//전역변수로 int level을 정의하여, level 1~6: 초1~초6, level 7~9: 중1,2,3, level 10~12: 고1,2,3으로 간주해 보았습니다.

//제한 시간내에 문제를 해결했을 경우, 남은 시간을 초 단위로 반환
//사용시 TimeLeft(level,start,end)
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



//남은 시간에 대한 보너스 점수 반환
//기호 상수로 #define BONUS_PER_SEC 50 (추후 조정) 정의 필요
//사용시 TimeBonus(start,end,TimeLimit(level))
int TimeBonus(clock_t start, clock_t end,int TimeLimit)
{
	return TimeLeft(start, end,TimeLimit) * BONUS_PER_SEC;
}

//혹시 몰라 각 단계별 제한시간을 초단위로 반환하는 함수도 만들어 두었습니다.
//사용시 TimeLimit(level);
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