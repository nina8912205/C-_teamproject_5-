// score.c : ���� ���
#include "common.h"

int TotalScore;
int SCORE[SCHSIZE][ASIZE] = { 0 };

// ���� ����[level: �б�, type: ���� ����, score: ����]
void addscore(int level, int type, int score)
{
	SCORE[level][type] += score;
	SCORE[level][TOTAL] += score;
	TotalScore += score;
}

void add_test_score(int level, int type, int score)
{
	SCORE[level][type] += score;
	SCORE[level][BOSS] += score;
	TotalScore += score;
}

// ���� ����Լ�
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
		// �ƴϸ� return (grade * 1000);
		}
	case M:
		switch (grade)
		{
		case 1: return 3000;
		case 2: return 6000;
		case 3: return 9000;
		// �ƴϸ� return (grade * 3000);
		}
	case H:
		switch (grade)
		{
		case 1: return 5000;
		case 2: return 10000;
		case 3: return 15000;
		// �ƴϸ� return (grade * 5000);
		}
	case T:
		switch (grade)
		{
		case E: return 8000;
		case M: return 16000;
		case H: return 24000;
		// �ƴϸ� return (grade * 8000);
		}
	}
}
