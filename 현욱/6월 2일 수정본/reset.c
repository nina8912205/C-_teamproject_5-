#include "common.h"

//?����??? �����?
void resetOX()
{
	extern char O_X[];
	for (int i = 0; i < MAX_Q; i++)
	{
		O_X[i] = 0;
	}
}

//?����? �����?
void resetScore(int level)
{
	extern int SCORE[SCHSIZE][ASIZE];

	for (int i = TOTAL; i < ASIZE; i++)
		SCORE[level][i] = 0;
}

