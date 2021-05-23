//############ ���� - �г⺰ ���ѽð�(��), ���ѽð� ��ȯ �Լ�, �ð� ���ʽ� (���� ���� �ۼ�)
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
#define M3 6

// ����б� ���ѽð�
#define H1 9
#define H2 9
#define H3 9

// �ʵ��б� ���ѽð� ��ȯ
int Etime(int level) 
{
	switch (level)
	{
	case 1:
		return E1;
		break;
	case 2:
		return E2;
		break;
	case 3:
		return E3;
		break;
	case 4:
		return E4;
		break;
	case 5:
		return E5;
		break;
	case 6:
		return E6;
		break;
	}
}

// ���б� ���ѽð� ��ȯ
int Mtime(int level) 
{
	switch (level)
	{
	case 1:
		return M1;
		break;
	case 2:
		return M2;
		break;
	case 3:
		return M3;
		break;
	}
}

// ����б� ���ѽð� ��ȯ
int Htime(int level)
{
	switch (level)
	{
	case 1:
		return H1;
		break;
	case 2:
		return H2;
		break;
	case 3:
		return H3;
		break;
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