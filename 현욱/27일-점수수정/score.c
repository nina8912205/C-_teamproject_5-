/*점수 계산*/
#include "common.h"

//점수 누적/상단 표시 위한 변수
int TotalScore;

int scorearray[GRADESIZE][SSIZE] = { 0 };



//정답 맞출시 점수 추가
void correct(int level, int score)
{
	extern int scorearray[GRADESIZE][SSIZE];
	int i;

	switch (level)
	{
	case ELEMENTARY:
		for (i = TOTAL; i <= CORRECT; i++)
			scorearray[E][i] += score;
		break;
	case MIDDLE:
		for (i = TOTAL; i <= CORRECT; i++)
			scorearray[M][i] += score;
		break;
	case HIGH:
		for (i = TOTAL; i <= CORRECT; i++)
			scorearray[H][i] += score;
		break;
	}
	TotalScore += score;
}

void combo(int level)
{
	extern int scorearray[GRADESIZE][SSIZE], TotalScore;

	switch (level)
	{
	case ELEMENTARY:
		scorearray[E][COMBO] += BonusPerCombo;
		scorearray[E][TOTAL] += BonusPerCombo;
		break;
	case MIDDLE:
		scorearray[M][COMBO] += BonusPerCombo;
		scorearray[M][TOTAL] += BonusPerCombo;
		break;
	case HIGH:
		scorearray[H][COMBO] += BonusPerCombo;
		scorearray[H][TOTAL] += BonusPerCombo;
		break;
	}
	TotalScore += BonusPerCombo;
}

void timescore(int level, int score)
{
	extern int scorearray[GRADESIZE][SSIZE], TotalScore;

	switch (level)
	{
	case ELEMENTARY:
		scorearray[E][TIME] += score;
		scorearray[E][TOTAL] += score;
		break;
	case MIDDLE:
		scorearray[M][TIME] += score;
		scorearray[M][TOTAL] += score;
		break;
	case HIGH:
		scorearray[H][TIME] += score;
		scorearray[H][TOTAL] += score;
		break;
	}
	TotalScore += score;
}

void boss_correct(int level, int score)
{
	extern int scorearray[GRADESIZE][SSIZE], TotalScore;
	int i;

	switch (level)
	{
	case ELEMENTARY:
		for (i = BOSS; i <= B_CORRECT; i++)
			scorearray[E][i] += score;
		break;
	case MIDDLE:
		for (i = BOSS; i <= B_CORRECT; i++)
			scorearray[M][i] += score;
		break;
	case HIGH:
		for (i = BOSS; i <= B_CORRECT; i++)
			scorearray[H][i] += score;
		break;
	}
	TotalScore += score;
}
void boss_combo(int level)
{
	extern int scorearray[GRADESIZE][SSIZE], TotalScore;

	switch (level)
	{
	case ELEMENTARY:
		scorearray[E][B_COMBO] += BonusPerCombo;
		scorearray[E][BOSS] += BonusPerCombo;
		break;
	case MIDDLE:
		scorearray[M][B_COMBO] += BonusPerCombo;
		scorearray[M][BOSS] += BonusPerCombo;
		break;
	case HIGH:
		scorearray[H][B_COMBO] += BonusPerCombo;
		scorearray[H][BOSS] += BonusPerCombo;
		break;
	}
	TotalScore += BonusPerCombo;
}

void boss_time(int level, int score)
{
	extern int scorearray[GRADESIZE][SSIZE], TotalScore;

	switch (level)
	{
	case ELEMENTARY:
		scorearray[E][B_TIME] += score;
		scorearray[E][BOSS] += score;
		break;
	case MIDDLE:
		scorearray[M][B_TIME] += score;
		scorearray[M][BOSS] += score;
		break;
	case HIGH:
		scorearray[H][B_TIME] += score;
		scorearray[H][BOSS] += score;
		break;
	}
	TotalScore += score;
}
