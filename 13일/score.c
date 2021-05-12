/*점수 계산*/
#include "common.h"

// 초등학교 획득한 점수 계산
int elementary_score_add(score)
{
	static int elementary_total_score = 0;

	elementary_total_score += score;
	
	return elementary_total_score;
}

// 초등학교 콤보점수 계산

// 초등학교 시간 추가 점수 계산

// 중학교

// 고등학교