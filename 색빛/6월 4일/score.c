// score.c : ���� ���
#include "common.h"

int TotalScore;
int SCORE[SCHSIZE][ASIZE] = { 0 };


/*==========���� ����==========*/

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
	SCORE[level][TEST] += score;
	TotalScore += score;
}


/*==========�ð� ���ʽ�==========*/

// ���� �ð�
int TimeLeft(int timelimit, int start, int end)
{
	return (timelimit - (end - start));
}

// �ð� ���ʽ�
int TimeBonus(int left)
{
	return (left * BOUNS_PER_SEC);
}


/*==========�޺� ���ʽ�==========*/


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
