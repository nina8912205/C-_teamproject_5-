/*콤보점수 계산*/
#include "common.h"


//문제 개수를 저장할 변수를 question 등으로 저장할 필요가 있을 것 같습니다.
//연속으로 맞춘 문제 개수 반환하는 함수
//사용시 Combo(O_X, question) 호출
int Combo_num(int question)   //question: 문제 개수  
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

//콤보 점수 반환하는 함수
//#define BonusPerCombo 50 필요
//사용시 ComboBonus(Combo(O_X, question)) 호출
int ComboBonus(int combo)
{
	return combo * BonusPerCombo;
}

//정오 기록 함수
//int O_X[MAX_Q] = { 0 };			//0: 미입력, 1: 정답, 2: 오답, **메인함수에 정의 필요

//요 밑에 두개는 elementary.c 등에서 문제랑 답 비교할 때
//맞으면 OX_Corrext(O_X,k);, 틀리면 OX_Wrong(O_X,k); 호출
void OX_Correct(int num_Q)	//k=문제 번호(몇번째 문제인지?)                       // @@@@@@@@@@@@@@@@@@@ int O_X[] 지움. 필요없는 매개변수 같아서 ...  / k -> num_Q 
									//몇 번째 문제인지 알 수 있도록 elementary()등의 함수에서int k=0 정의 후 
{
	extern int O_X[];								//OX_Correct 혹은 OX_Wrong 호출 직후에 k++; 해주기.
	O_X[num_Q - 1] = 1;
}

void OX_Wrong(int num_Q)	//k=문제 번호(몇번째 문제인지?)
{
	extern int O_X[];
	O_X[num_Q - 1] = 2;
}

//정오 기록 초기화 하기위한 함수. 사용 위해서는 reset_OX(O_X); 호출.
void reset_OX()
{
	extern int O_X[];
	int i;
	for (i = 0; i < MAX_Q; i++)
		O_X[i] = 0;
}
