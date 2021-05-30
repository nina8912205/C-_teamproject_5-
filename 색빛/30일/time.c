#include "common.h"
#define BOUNS_PER_SEC 50

// �ʵ��б� ���ѽð�
#define E1 10
#define E2 9
#define E3 8
#define E4 7
#define E5 6
#define E6 5

// ���б� ���ѽð�
#define M1 8
#define M2 6
#define M3 15

// ����б� ���ѽð�
#define H1 9
#define H2 9
#define H3 9

// �ʵ��б� ���ѽð� ��ȯ
int Etime(int level)
{
	switch (level)
	{
	case 1:	return E1;
	case 2:	return E2;
	case 3:	return E3;
	case 4:	return E4;
	case 5:	return E5;
	case 6:	return E6;
	}
}

// ���б� ���ѽð� ��ȯ
int Mtime(int level)
{
	switch (level)
	{
	case 1:	return M1;
	case 2:	return M2;
	case 3: return M3;
	}
}

// ����б� ���ѽð� ��ȯ
int Htime(int level)
{
	switch (level)
	{
	case 1:	return H1;
	case 2: return H2;
	case 3: return H3;
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