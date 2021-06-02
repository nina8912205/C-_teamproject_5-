/* ??????? ??? */
#include "common.h"


// ??? ????
int Combo_num(int question)
{
	extern int O_X[];
	int combo = 0;

	for (int i = 0; i < question; i++)
	{
		if (O_X[i] == 1)
			if (O_X[i + 1] == 1)
				combo++;
	}
	return combo;
}

int combo_print(int num_q)
{
	extern int O_X[MAX_Q];
	int i = num_q, count = 0;
	if (num_q >= 2)
	{
		while (i > 0)
		{
			if (O_X[i - 2] == 1)
				count++;
			if (O_X[i - 2] == 0)
				break;
			i--;
		}
	}
	return count;
}