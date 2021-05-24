//############ 색빛 - 학년별 제한시간(초), 제한시간 반환 함수, 시간 보너스 (거의 새로 작성)
#include "common.h"
#define BOUNS_PER_SEC 50

// 초등학교 제한시간
#define E1 10
#define E2 9
#define E3 8
#define E4 7
#define E5 6
#define E6 5

// 중학교 제한시간
#define M1 8
#define M2 6
#define M3 6

// 고등학교 제한시간
#define H1 9
#define H2 9
#define H3 9

// 초등학교 제한시간 반환
int Etime(int level)
{
	switch (level)
	{
	case 1:
		return E1;
		break;
	case 2:
		return E2;
		break;
	case 3:
		return E3;
		break;
	case 4:
		return E4;
		break;
	case 5:
		return E5;
		break;
	case 6:
		return E6;
		break;
	}
}

// 중학교 제한시간 반환
int Mtime(int level)
{
	switch (level)
	{
	case 1:
		return M1;
		break;
	case 2:
		return M2;
		break;
	case 3:
		return M3;
		break;
	}
}

// 고등학교 제한시간 반환
int Htime(int level)
{
	switch (level)
	{
	case 1:
		return H1;
		break;
	case 2:
		return H2;
		break;
	case 3:
		return H3;
		break;
	}
}

// 남은 시간
int TimeLeft(int timelimit, int start, int end)
{
	return (timelimit - (end - start));
}

// 시간 보너스
int TimeBonus(int left)
{
	return (left * BOUNS_PER_SEC);
}
