/* �޺����� ��� */
#include "common.h"


// �޺� ����
int Combo_num(int question)
{
	extern int O_X[];
	int combo = 0;

	for (int i = 0; i < question; i++) //############ ���� - for�� �ȿ����� i�� ���ǹǷ� for������ ������.
	{
		if (O_X[i] == 1)
			if (O_X[i + 1] == 1)
				combo++;
	}
	return combo;
}

// �޺� ���� 
int ComboBonus(int combo)
{
	return combo * BonusPerCombo;
}

//############ ���� - �Լ� �� ���� �迭�� ����� �� �־ �Լ� OX_Wrong, OX_Correct ����
//############ ���� - �г��� ����Ǹ鼭 �ٽ� O_X[0]���� �Է��� �ϱ� ������ ����ǥ ���� �ʿ� X -> �Լ� reset_OX ����