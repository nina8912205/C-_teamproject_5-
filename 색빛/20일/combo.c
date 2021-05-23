/* 콤보점수 계산 */
#include "common.h"


// 콤보 개수
int Combo_num(int question)
{
	extern int O_X[];
	int combo = 0;

	for (int i = 0; i < question; i++) //############ 색빛 - for문 안에서만 i가 사용되므로 for문에서 선언함.
	{
		if (O_X[i] == 1)
			if (O_X[i + 1] == 1)
				combo++;
	}
	return combo;
}

// 콤보 점수 
int ComboBonus(int combo)
{
	return combo * BonusPerCombo;
}

//############ 색빛 - 함수 안 쓰고도 배열에 기록할 수 있어서 함수 OX_Wrong, OX_Correct 삭제
//############ 색빛 - 학년이 변경되면서 다시 O_X[0]부터 입력을 하기 때문에 정오표 리셋 필요 X -> 함수 reset_OX 삭제
