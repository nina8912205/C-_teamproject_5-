/*점수 계산*/
#include "common.h"

///****** 5/21(현욱) - 변수 수정 - 총 점수, 배점 누적 점수, 시간보너스, 콤보보너스 저장 변수 추가
int elementary_total_score = 0; // 총 점수
int elementary_correct_score = 0;// 문제 맞아서 배점 누적된 점수
int elementary_time_bonus=0;	//시간 보너스
int elementary_combo_bonus=0;	//콤보 보너스

// 초등학교 획득한 점수 계산
int elementary_score_add(int score)
{
	extern int elementary_correct_score;

	////**** 5/21 (현욱) - 문제 맞으면 점수를 총 점수 및 문제 점수에 각각 기록 (게임 진행중 표시 및 성적표 출력용)
	elementary_correct_score += score;

	elementary_total_score += score;

	return elementary_correct_score;
}


// 초등학교 콤보점수 계산 -	combo.c  참조

// 초등학교 시간 추가 점수 계산
double elementary_score_time(double timebonus)
{
	static int elementary_score_time = 0;

	elementary_score_time += timebonus;
	
	///5/21 (현욱)**** 추후 변수 정리가 조금 필요할 것 같습니다!
	elementary_time_bonus = elementary_score_time; /// 5/21 현욱- 성적표 출력 위한 외부 변수
	elementary_total_score += timebonus;
	return elementary_score_time;
}


// 중학교 획득한 점수 계산
int middle_score_add(score)
{
	static int middle_total_score = 0;

	middle_total_score += score;

	return middle_total_score;
}
// 중학교 콤보점수 계산

// 중학교 시간추가 점수 계산

// 고등학교

///*** 5/21 (현욱)- 초기 화면 이동시 점수 초기화위해 만든 함수
void score_reset(void)
{
	extern int elementary_total_score; // 총 점수
	extern int elementary_correct_score;// 문제 맞아서 배점 누적된 점수
	extern int elementary_time_bonus;	//시간 보너스
	extern int elementary_combo_bonus;	//콤보 보너스

	elementary_total_score = 0;
	elementary_correct_score = 0;
	elementary_time_bonus = 0;
	elementary_combo_bonus = 0;

}
