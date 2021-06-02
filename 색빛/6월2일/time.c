#include "common.h"
#define BOUNS_PER_SEC 50

// ���� �ð� ��ȯ
int timeboard(int type, int grade)
{
	switch (type)
	{
	case E:
		switch (grade)
		{
		case 1: return 5;
		case 2: return 5;
		case 3: return 6;
		case 4: return 6;
		case 5: return 6;
		case 6: return 6;
		}
	case M:
		switch (grade)
		{
		case 1: return 8;
		case 2: return 8;
		case 3: return 10;
		}
	case H:
		switch (grade)
		{
		case 1: return 10;
		case 2: return 15;
		case 3: return 15;
		}
	case T:
		switch (grade)
		{
		case E: return 7;
		case M: return 10;
		case H: return 15;
		}
	}
}

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