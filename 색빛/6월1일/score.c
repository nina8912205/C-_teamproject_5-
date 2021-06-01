// score.c : 점수 계산
#include "common.h"

int TotalScore;
int scorearray[SCHSIZE][ASIZE] = { 0 };

//정답 맞출시 점수 추가
void correct(int level, int score)
{
	for (int i = TOTAL; i <= CORRECT; i++)
		scorearray[level][i] += score;
	TotalScore += score;
}

void combo(int level)
{
	scorearray[level][COMBO] += BonusPerCombo;
	scorearray[level][TOTAL] += BonusPerCombo;
	TotalScore += BonusPerCombo;
}

void timescore(int level, int score)
{
	scorearray[level][TIME] += score;
	scorearray[level][TOTAL] += score;
	TotalScore += score;
}

void boss_correct(int level, int score)
{
	for (int i = BOSS; i <= B_CORRECT; i++)
		scorearray[level][i] += score;
	TotalScore += score;
}

void boss_combo(int level)
{
	scorearray[level][B_COMBO] += BonusPerCombo;
	scorearray[level][BOSS] += BonusPerCombo;
	TotalScore += BonusPerCombo;
}

void boss_time(int level, int score)
{
	scorearray[level][B_TIME] += score;
	scorearray[level][BOSS] += score;
	TotalScore += score;
}

