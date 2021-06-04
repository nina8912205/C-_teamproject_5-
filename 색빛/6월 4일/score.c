// score.c : 점수 계산
#include "common.h"

int TotalScore;
int SCORE[SCHSIZE][ASIZE] = { 0 };


/*==========점수 누적==========*/

// 점수 누적[level: 학교, type: 점수 종류, score: 배점]
void addscore(int level, int type, int score)
{
	SCORE[level][type] += score;
	SCORE[level][TOTAL] += score;
	TotalScore += score;
}

void add_test_score(int level, int type, int score)
{
	SCORE[level][type] += score;
	SCORE[level][TEST] += score;
	TotalScore += score;
}


/*==========시간 보너스==========*/

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


/*==========콤보 보너스==========*/


int combo_print(int num_q)
{
	extern int O_X[];
	int i = num_q, count = 0;
	if (num_q >= 2)
	{
		while (i > 0)
		{
			if (O_X[i - 1])
				count++;
			else
				break;
			i--;
		}
	}
	return count;
}
