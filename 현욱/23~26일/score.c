/*점수 계산*/
#include "common.h"

///****** 5/21(현욱) - 변수 수정 - 총 점수, 배점 누적 점수, 시간보너스, 콤보보너스 저장 변수 추가
///****** 5/24(현욱) - 성적표 출력에 필요한 점수들 전역변수로 선언, 점수 처리 알고리즘 일관성있게 수정
//점수 누적/상단 표시 위한 변수
int total_score;

//초등학교
int e_total_score; // 총 점수
int e_correct_score;// 문제 맞아서 배점 누적된 점수
int e_time_bonus;	//시간 보너스
int e_combo_bonus;	//콤보 보너스
int eboss_total_score;
int eboss_correct_score;
int eboss_time_bonus;
int eboss_combo_bonus;
//중학교
int m_total_score; // 총 점수
int m_correct_score;// 문제 맞아서 배점 누적된 점수
int m_time_bonus;	//시간 보너스
int m_combo_bonus;	//콤보 보너스
int mboss_total_score;
int mboss_correct_score;
int mboss_time_bonus;
int mboss_combo_bonus;

////////중학교 보스에 선언해주기!
int M_num_Q_boss;
int M_O_BOSS;

//고등학교
int h_total_score; // 총 점수
int h_correct_score;// 문제 맞아서 배점 누적된 점수
int h_time_bonus;	//시간 보너스
int h_combo_bonus;	//콤보 보너스
int hboss_total_score;
int hboss_correct_score;
int hboss_time_bonus;
int hboss_combo_bonus;

////////고등학교 보스에 선언해주기!
int H_num_Q_boss;
int H_O_BOSS;


///*** 5/21 (현욱)- 초기 화면 이동시 점수 초기화위해 만든 함수
////5/25(현욱) 초등 점수 관련 모두 초기화-추후 사용 할수도....?
void e_score_reset(void)
{
	extern int e_total_score; // 총 점수
	extern int e_correct_score;// 문제 맞아서 배점 누적된 점수
	extern int e_time_bonus;	//시간 보너스
	extern int e_combo_bonus;	//콤보 보너스
	extern int eboss_total_score; // 총 점수
	extern int eboss_correct_score;// 문제 맞아서 배점 누적된 점수
	extern int eboss_time_bonus;	//시간 보너스
	extern int eboss_combo_bonus;	//콤보 보너스

	e_total_score=0; 
	e_correct_score=0;
	e_time_bonus=0;	
	e_combo_bonus=0;	
	eboss_total_score=0; 
	eboss_correct_score=0;
	eboss_time_bonus=0;	
	eboss_combo_bonus=0;	

}

//정답 맞출시 점수 추가
void correct_score(int level, int score)
{
	extern int e_total_score, m_total_score, h_total_score;
	extern int e_correct_score, m_correct_score, h_correct_score;
	extern int total_score;
	switch (level)
	{
	case ELEMENTARY:
	{
		total_score = total_score+score;
		e_correct_score = e_correct_score+score;
		e_total_score = e_total_score+score;
		break;
	}
	case MIDDLE:
	{
		m_correct_score = m_correct_score+score;
		m_total_score = m_total_score+ score;
		total_score = total_score+ score;
		break;
	}
	case HIGH:
	{
		h_correct_score = h_correct_score+score;
		h_total_score = h_total_score + score;
		total_score = total_score +score;
		break;
	}

	}
}
void combo_bonus(int level)
{
	extern int e_total_score, m_total_score, h_total_score;
	extern int e_combo_bonus, m_combo_bonus, h_combo_bonus;
	extern int total_score;
	
	switch (level)
	{
	case ELEMENTARY:
	{
		e_combo_bonus = e_combo_bonus + BonusPerCombo;
		e_total_score = e_total_score + BonusPerCombo;
		total_score = total_score + BonusPerCombo - 100;
		break;
	}
	case MIDDLE:
	{
		m_combo_bonus = m_combo_bonus + BonusPerCombo;
		m_total_score = m_total_score + BonusPerCombo;
		total_score = total_score + BonusPerCombo-100;
		break;
	}
	case HIGH:
	{
		h_combo_bonus = h_combo_bonus + BonusPerCombo;
		h_total_score = h_total_score + BonusPerCombo;
		total_score = total_score + BonusPerCombo-100;
		break;
	}
	}
	
}
void time_bonus(int level, int score)
{
	extern int e_total_score, m_total_score, h_total_score;
	extern int e_time_bonus, m_time_bonus, h_time_bonus;
	extern int total_score;
	extern int time_left;
	switch (level)
	{
	case ELEMENTARY:
	{
		e_time_bonus =e_time_bonus+ score;
		e_total_score = e_total_score+score;
		total_score =total_score+score;
		break;
	}
	case MIDDLE:
	{
		m_time_bonus = m_time_bonus + TimeBonus(time_left);
		m_total_score = m_total_score + TimeBonus(time_left);
		total_score = total_score + TimeBonus(time_left);
		break;
	}
	case HIGH:
	{
		h_time_bonus = h_time_bonus + TimeBonus(time_left);
		h_total_score = h_total_score + TimeBonus(time_left);
		total_score = total_score + TimeBonus(time_left);
		break;
	}

	}
}
void boss_correct_score(int level, int score)
{
	extern int eboss_total_score, mboss_total_score, hboss_total_score;
	extern int eboss_correct_score, mboss_correct_score, hboss_correct_score;
	extern int total_score;
	switch (level)
	{
	case ELEMENTARY:
	{
		eboss_correct_score = eboss_correct_score + score;
		eboss_total_score = eboss_total_score + score;
		total_score = total_score + score;
		break;
	}
	case MIDDLE:
	{
		mboss_correct_score = mboss_correct_score + score;
		mboss_total_score = mboss_total_score + score;
		total_score = total_score + score;
		break;

	}
	case HIGH:
	{
		hboss_correct_score = hboss_correct_score + score;
		hboss_total_score = hboss_total_score + score;
		total_score = total_score + score;
		break;

	}

	}
}
void boss_combo_bonus(int level)
{
	extern int eboss_total_score, mboss_total_score, hboss_total_score;
	extern int eboss_combo_bonus, mboss_combo_bonus, hboss_combo_bonus;
	extern int total_score;
	switch (level)
	{
	case ELEMENTARY:
	{
		eboss_combo_bonus = eboss_combo_bonus + BonusPerCombo;
		eboss_total_score = eboss_total_score + BonusPerCombo;
		total_score = total_score + BonusPerCombo;
		break;

	}
	case MIDDLE:
	{
		mboss_combo_bonus = mboss_combo_bonus + BonusPerCombo;
		mboss_total_score = mboss_total_score + BonusPerCombo;
		total_score = total_score + BonusPerCombo;
		break;

	}
	case HIGH:
	{
		hboss_combo_bonus = hboss_combo_bonus + BonusPerCombo;
		hboss_total_score = hboss_total_score + BonusPerCombo;
		total_score = total_score + BonusPerCombo;
		break;

	}

	}
}
void boss_time_bonus (int level, int score)
{
	//extern char O_X[MAX_Q];
	extern int eboss_total_score, mboss_total_score, hboss_total_score;
	extern int eboss_time_bonus, mboss_time_bonus, hboss_time_bonus;
	extern int total_score;
	extern int time_left;
	
	switch (level)
	{
	case ELEMENTARY:
	{
		eboss_time_bonus = eboss_time_bonus + TimeBonus(time_left);
		eboss_total_score = eboss_total_score + TimeBonus(time_left);
		total_score = total_score + TimeBonus(time_left);
		break;

	}
	case MIDDLE:
	{
		mboss_time_bonus = mboss_time_bonus + TimeBonus(time_left);
		mboss_total_score = mboss_total_score + TimeBonus(time_left);
		total_score = total_score + TimeBonus(time_left);
		break;

	}
	case HIGH:
	{
		hboss_time_bonus = hboss_time_bonus + TimeBonus(time_left);
		hboss_total_score = hboss_total_score + TimeBonus(time_left);
		total_score = total_score + TimeBonus(time_left);
		break;

	}

	}
}
//정오표 리셋
void resetOX()
{
	extern O_X[MAX_Q];
	for (int i = 0; i < MAX_Q; i++)
	{
		O_X[i] = 0;
	}
}
//점수 리셋
void score_reset()
{
	extern int e_total_score, e_correct_score, e_time_bonus, e_combo_bonus;
	extern int eboss_total_score, eboss_correct_score, eboss_time_bonus, eboss_combo_bonus;
	extern int E_O, E_num_Q, E_O_BOSS, E_num_Q_boss;

	extern int m_total_score, m_correct_score, m_time_bonus, m_combo_bonus;
	extern int mboss_total_score, mboss_correct_score, mboss_time_bonus, mboss_combo_bonus;
	extern int M_O, M_num_Q, M_O_BOSS, M_num_Q_boss;
	
	extern int h_total_score, h_correct_score, h_time_bonus, h_combo_bonus;
	extern int hboss_total_score, hboss_correct_score, hboss_time_bonus, hboss_combo_bonus;
	extern int H_O, H_num_Q, H_O_BOSS, H_num_Q_boss;
	extern int total_score;

	e_total_score=0, e_correct_score = 0, e_time_bonus = 0, e_combo_bonus = 0;
	eboss_total_score = 0, eboss_correct_score = 0, eboss_time_bonus = 0, eboss_combo_bonus = 0;
	E_O = 0, E_num_Q = 0, E_O_BOSS = 0, E_num_Q_boss = 0;
	m_total_score = 0, m_correct_score = 0, m_time_bonus = 0, m_combo_bonus = 0;
	mboss_total_score = 0, mboss_correct_score = 0, mboss_time_bonus = 0, mboss_combo_bonus = 0;
	M_O = 0, M_num_Q = 0, M_O_BOSS = 0, M_num_Q_boss = 0;
	h_total_score = 0, h_correct_score = 0, h_time_bonus = 0, h_combo_bonus = 0;
	hboss_total_score = 0, hboss_correct_score = 0, hboss_time_bonus = 0, hboss_combo_bonus = 0;
	H_O = 0, H_num_Q = 0, H_O_BOSS = 0, H_num_Q_boss = 0;
	//total_score = 0;
	

}