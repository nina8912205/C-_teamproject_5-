/*���� ���*/
#include "common.h"

int elementary_total_score = 0; // ���������� ȣ�� ���ϹǷ� ��������

// �ʵ��б� ȹ���� ���� ���
int elementary_score_add(int score)
{
	extern int elementary_total_score;

	elementary_total_score += score;

	return elementary_total_score;
}


// �ʵ��б� �޺����� ���

// �ʵ��б� �ð� �߰� ���� ���
double elementary_score_time(double timebonus)
{
	static int elementary_score_time = 0;

	elementary_score_time += timebonus;

	return elementary_score_time;
}


// ���б� ȹ���� ���� ���
int middle_score_add(score)
{
	static int middle_total_score = 0;

	middle_total_score += score;

	return middle_total_score;
}
// ���б� �޺����� ���

// ���б� �ð��߰� ���� ���

// ����б�