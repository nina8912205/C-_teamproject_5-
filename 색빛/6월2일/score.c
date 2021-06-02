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

// 점수 출력함수
int scoreboard(int type, int grade)
{
	switch (type)
	{
	case E:
		switch (grade)
		{
		case 1: return 1000;
		case 2: return 2000;
		case 3: return 3000;
		case 4: return 4000;
		case 5: return 5000;
		case 6: return 6000;
		// 아니면 return (grade * 1000);
		}
	case M:
		switch (grade)
		{
		case 1: return 3000;
		case 2: return 6000;
		case 3: return 9000;
		// 아니면 return (grade * 3000);
		}
	case H:
		switch (grade)
		{
		case 1: return 5000;
		case 2: return 10000;
		case 3: return 15000;
		// 아니면 return (grade * 5000);
		}
	case T:
		switch (grade)
		{
		case E: return 8000;
		case M: return 16000;
		case H: return 24000;
		// 아니면 return (grade * 8000);
		}
	}
}
