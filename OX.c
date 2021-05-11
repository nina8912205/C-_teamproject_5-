//정오기록함수
//int O_X[MAX_Q] = { 0 };			//0: 미입력, 1: 정답, 2: 오답, **메인함수에 정의 필요
// 각 학년이 진행되는 동안에는 실행 중이어야 함.
//elementary.c 등에서 각 학년의 for 구문 안에서 OX(O_X, i, (각 학년별 문제수-기호상수)); 사용해주면 됨.
/*각 학년별 문제수 예시-common.h
#define E1Q 10
#define E2Q	10
#define E3Q	8
#define E4Q	8
#define E5Q	5
#define E6Q	5
#define M1Q	5
#define M2Q	5
#define M3Q	5
#define H1Q	5
#define H2Q	5
#define H3Q	5
*/
#include "common.h"
int OX(int O_X[],int question_num int question) //question: 문제 수(지역변수), question_num: 몇 번째 문제인지 기록 (각 학년에서 n개 문제중 k번째 문제)
{	
	//배열 크기: 최대 문제수 MAX_Q
	
		if (/*정답일치*/)
			O_X[i-1] = 1;
		else 
			O_X[i-1] = 2;
}

