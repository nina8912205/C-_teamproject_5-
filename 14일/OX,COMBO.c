
#include "common.h"

//�������� ���� ���� ���� ��ȯ�ϴ� �Լ�
int Combo(int O_X[],int question)//question: ���� ����
{
	int i;
	int combo = 0;
	for (i = 0; i < question; i++)
	{
		if (O_X[i] == 1)
			if (O_X[i+1] == 1)
				combo++;
	}
	return combo;
}

//���� ��� �Լ�
//int O_X[MAX_Q] = { 0 };			//0: ���Է�, 1: ����, 2: ����, **�����Լ��� ���� �ʿ�

//�� �ؿ� �ΰ��� elementary.c ��� ������ �� ���� ��
//������ OX_Corrext(O_X,k);, Ʋ���� OX_Wrong(O_X,k); ȣ��
void OX_Correct(int O_X[], int n)	//k=���� ��ȣ(���° ��������?)
									//�� ��° �������� �� �� �ֵ��� elementary()���� �Լ�����int k=0 ���� �� 
{									//OX_Correct Ȥ�� OX_Wrong ȣ�� ���Ŀ� k++; ���ֱ�.
	O_X[k - 1] = 1;
}

void OX_Wrong(int O_X[], int k)	//k=���� ��ȣ(���° ��������?)
{
	O_X[k - 1] = 2;
}
//���� ��� �ʱ�ȭ �ϱ����� �Լ�. ��� ���ؼ��� reset_OX(O_X); ȣ��.
void reset_OX(int O_X[])
{
	int i;
	for (i = 0; i < MAX_Q; i++)
		O_X[i] = 0;
}