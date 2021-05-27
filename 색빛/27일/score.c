/*점수 계산*/
#include "common.h"

//점수 누적/상단 표시 위한 변수
int TotalScore;

int e_score[SSIZE] = { 0 };
int m_score[SSIZE] = { 0 };
int h_score[SSIZE] = { 0 };

////////중학교 보스에 선언해주기!
int M_num_Q_boss;
int M_O_BOSS;

////////고등학교 보스에 선언해주기!
int H_num_Q_boss;
int H_O_BOSS;


//정답 맞출시 점수 추가
void correct(int level, int score)
{
	extern int e_score[], m_score[], h_score[], TotalScore;
	int i;

	switch (level)
	{
	case ELEMENTARY:
		for (i = TOTAL; i <= CORRECT; i++)
			e_score[i] += score;
		break;
	case MIDDLE:
		for (i = TOTAL; i <= CORRECT; i++)
			m_score[i] += score;
		break;
	case HIGH:
		for (i = TOTAL; i <= CORRECT; i++)
			h_score[i] += score;
		break;
	}
	TotalScore += score;
}

void combo(int level)
{
	extern int e_score[], m_score[], h_score[], TotalScore;

	switch (level)
	{
	case ELEMENTARY:
		e_score[COMBO] += BonusPerCombo;
		e_score[TOTAL] += BonusPerCombo;		
		break;
	case MIDDLE:
		m_score[COMBO] += BonusPerCombo;
		m_score[TOTAL] += BonusPerCombo;
		break;
	case HIGH:
		h_score[COMBO] += BonusPerCombo;
		h_score[TOTAL] += BonusPerCombo;
		break;
	}
	TotalScore += BonusPerCombo;
}

void timescore(int level, int score)
{
	extern int e_score[], m_score[], h_score[], TotalScore;

	switch (level)
	{
	case ELEMENTARY:
		e_score[TIME] += score;
		e_score[TOTAL] += score;
		break;
	case MIDDLE:
		m_score[TIME] += score;
		m_score[TOTAL] += score;
		break;
	case HIGH:
		h_score[TIME] += score;
		h_score[TOTAL] += score;
		break;
	}
	TotalScore += score;
}

void boss_correct(int level, int score)
{
	extern int e_score[], m_score[], h_score[], TotalScore;
	int i;

	switch (level)
	{
	case ELEMENTARY:
		for (i = BOSS; i <= B_CORRECT; i++)
			e_score[i] += score;
		break;
	case MIDDLE:
		for (i = BOSS; i <= B_CORRECT; i++)
			m_score[i] += score;
		break;
	case HIGH:
		for (i = BOSS; i <= B_CORRECT; i++)
			h_score[i] += score;
		break;
	}
	TotalScore += score;
}
void boss_combo(int level)
{
	extern int e_score[], m_score[], h_score[], TotalScore;

	switch (level)
	{
	case ELEMENTARY:
		e_score[B_COMBO] += BonusPerCombo;
		e_score[BOSS] += BonusPerCombo;		
		break;
	case MIDDLE:
		m_score[B_COMBO] += BonusPerCombo;
		m_score[BOSS] += BonusPerCombo;
		break;
	case HIGH:
		h_score[B_COMBO] += BonusPerCombo;
		h_score[BOSS] += BonusPerCombo;
		break;	
	}
	TotalScore += BonusPerCombo;
}

void boss_time(int level, int score)
{
	extern int e_score[], m_score[], h_score[], TotalScore;

	switch (level)
	{
	case ELEMENTARY:
		e_score[B_TIME] += score;
		e_score[BOSS] += score;
		break;
	case MIDDLE:
		m_score[B_TIME] += score;
		m_score[BOSS] += score;
		break;
	case HIGH:
		h_score[B_TIME] += score;
		h_score[BOSS] += score;
		break;
	}
	TotalScore += score;
}

