#include "common.h"

//����ǥ ����
void resetOX()
{
	extern char O_X[];
	for (int i = 0; i < MAX_Q; i++)
	{
		O_X[i] = 0;
	}
}

//���� ����
void resetScore()
{
	extern int SCORE[][ASIZE], TotalScore;
	int* sp, * ep;
	sp = &SCORE;
	ep = &SCORE[SCHSIZE - 1][ASIZE - 1];

	while (sp < ep)
		*sp++ = 0;
	TotalScore = 0;
}
