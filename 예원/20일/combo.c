/*�޺����� ���*/
#include "common.h"


//���� ������ ������ ������ question ������ ������ �ʿ䰡 ���� �� �����ϴ�.
//�������� ���� ���� ���� ��ȯ�ϴ� �Լ�
//���� Combo(O_X, question) ȣ��
int Combo_num(int question)   //question: ���� ����  
{
	extern int O_X[];
	int i;
	int combo = 0;

	for (i = 0; i < question; i++)
	{
		if (O_X[i] == 1)
			if (O_X[i + 1] == 1)
				combo++;
	}
	return combo;
}

//�޺� ���� ��ȯ�ϴ� �Լ�
//#define BonusPerCombo 50 �ʿ�
//���� ComboBonus(Combo(O_X, question)) ȣ��
int ComboBonus(int combo)
{
	return combo * BonusPerCombo;
}

//���� ��� �Լ�
//int O_X[MAX_Q] = { 0 };			//0: ���Է�, 1: ����, 2: ����, **�����Լ��� ���� �ʿ�

//�� �ؿ� �ΰ��� elementary.c ��� ������ �� ���� ��
//������ OX_Corrext(O_X,k);, Ʋ���� OX_Wrong(O_X,k); ȣ��
void OX_Correct(int num_Q)	//k=���� ��ȣ(���° ��������?)                       // @@@@@@@@@@@@@@@@@@@ int O_X[] ����. �ʿ���� �Ű����� ���Ƽ� ...  / k -> num_Q 
									//�� ��° �������� �� �� �ֵ��� elementary()���� �Լ�����int k=0 ���� �� 
{
	extern int O_X[];								//OX_Correct Ȥ�� OX_Wrong ȣ�� ���Ŀ� k++; ���ֱ�.
	O_X[num_Q - 1] = 1;
}

void OX_Wrong(int num_Q)	//k=���� ��ȣ(���° ��������?)
{
	extern int O_X[];
	O_X[num_Q - 1] = 2;
}

//���� ��� �ʱ�ȭ �ϱ����� �Լ�. ��� ���ؼ��� reset_OX(O_X); ȣ��.
void reset_OX()
{
	extern int O_X[];
	int i;
	for (i = 0; i < MAX_Q; i++)
		O_X[i] = 0;
}
