/*점수 계산*/
#include "common.h"

int elementary_total_score = 0; // 여러곳에서 호출 당하므로 전역변수

// 초등학교 획득한 점수 계산
int elementary_score_add(int score)
{
	extern int elementary_total_score;

	elementary_total_score += score;

	return elementary_total_score;
}


// 초등학교 콤보점수 계산

// 초등학교 시간 추가 점수 계산
double elementary_score_time(double timebonus)
{
	static int elementary_score_time = 0;

	elementary_score_time += timebonus;

	return elementary_score_time;
}


// 중학교 획득한 점수 계산
int middle_score_add(score)
{
	static int middle_total_score = 0;

	middle_total_score += score;

	return middle_total_score;
}
// 중학교 콤보점수 계산

// 중학교 시간추가 점수 계산

// 고등학교