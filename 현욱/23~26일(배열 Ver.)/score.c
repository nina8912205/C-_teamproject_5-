/*점수 계산*/
#include "common.h"

///****** 5/21(현욱) - 변수 수정 - 총 점수, 배점 누적 점수, 시간보너스, 콤보보너스 저장 변수 추가
///****** 5/24(현욱) - 성적표 출력에 필요한 점수들 전역변수로 선언, 점수 처리 알고리즘 일관성있게 수정
//점수 누적/상단 표시 위한 변수
int TotalScore;

//초등학교

int e_score[8] = { 0 };
int m_score[8] = { 0 };
int h_score[8] = { 0 };



////////중학교 보스에 선언해주기!
int M_num_Q_boss;
int M_O_BOSS;

////////고등학교 보스에 선언해주기!
int H_num_Q_boss;
int H_O_BOSS;


///*** 5/21 (현욱)- 초기 화면 이동시 점수 초기화위해 만든 함수
////5/25(현욱) 초등 점수 관련 모두 초기화-추후 사용 할수도....?////배열로 다시 만들어 두겠습니다 :-)
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
void correct(int level, int score)
{
	
	extern int e_score[];
	extern int m_score[];
	extern int h_score[];
	extern int TotalScore;
	switch (level)
	{
	case ELEMENTARY:
	{
		e_score[total_score] = e_score[total_score] + score;
		e_score[correct_score] = e_score[correct_score] + score;
		TotalScore = TotalScore + score;
		break;
	}
	case MIDDLE:
	{
		m_score[total_score] = m_score[total_score] + score;
		m_score[correct_score] = m_score[correct_score] + score;
		TotalScore = TotalScore + score;
		break;
	}
	case HIGH:
	{
		m_score[total_score] = m_score[total_score] + score;
		m_score[correct_score] = m_score[correct_score] + score;
		TotalScore = TotalScore + score;
		break;
	}

	}
	
}

void combo(int level)
{
	extern int e_score[];
	extern int m_score[];
	extern int h_score[];
	extern int TotalScore;
	switch (level)
	{
	case ELEMENTARY:
	{
		e_score[combo_bonus] = e_score[combo_bonus] + BonusPerCombo;
		e_score[total_score] = e_score[total_score] + BonusPerCombo;
		TotalScore = TotalScore + BonusPerCombo ;
		break;
	}
	case MIDDLE:
	{
		m_score[combo_bonus] = m_score[combo_bonus] + BonusPerCombo;
		m_score[total_score] = m_score[total_score] + BonusPerCombo;
		TotalScore = TotalScore + BonusPerCombo ;
		break;
	}
	case HIGH:
	{
		h_score[combo_bonus] = h_score[combo_bonus] + BonusPerCombo;
		h_score[total_score] = h_score[total_score] + BonusPerCombo;
		TotalScore = TotalScore + BonusPerCombo ;
		break;
	}
	}
	
}
void timescore(int level, int score)
{
	extern int e_score[];
	extern int m_score[];
	extern int h_score[];
	extern int TotalScore;
	switch (level)
	{
	case ELEMENTARY:
	{
		e_score[time_bonus] = e_score[time_bonus] + score;
		e_score[total_score] = e_score[total_score] + score;
		TotalScore =TotalScore+score;
		break;
	}
	case MIDDLE:
	{
		m_score[time_bonus] = m_score[time_bonus] + score;
		m_score[total_score] = m_score[total_score] + score;
		TotalScore = TotalScore + score;
		break;
	}
	case HIGH:
	{
		h_score[time_bonus] = h_score[time_bonus] + score;
		h_score[total_score] = h_score[total_score] + score;
		TotalScore = TotalScore + score;
		break;
	}

	}
}
void boss_correct(int level, int score)
{
	extern int e_score[];
	extern int m_score[];
	extern int h_score[];
	extern int TotalScore;
	switch (level)
	{
	case ELEMENTARY:
	{
		e_score[boss_correct_score] = e_score[boss_correct_score] + score;
		e_score[boss_total_score] = e_score[boss_total_score] + score;
		TotalScore = TotalScore + score;
		break;
	}
	case MIDDLE:
	{
		m_score[boss_correct_score] = m_score[boss_correct_score] + score;
		m_score[boss_total_score] = m_score[boss_total_score] + score;
		TotalScore = TotalScore + score;
		break;

	}
	case HIGH:
	{
		h_score[boss_correct_score] = h_score[boss_correct_score] + score;
		h_score[boss_total_score] = h_score[boss_total_score] + score;
		TotalScore = TotalScore + score;
		break;

	}

	}
}
void boss_combo(int level)
{
	extern int e_score[];
	extern int m_score[];
	extern int h_score[];
	extern int TotalScore;
	switch (level)
	{
	case ELEMENTARY:
	{

		e_score[boss_combo_bonus] = e_score[boss_combo_bonus] + BonusPerCombo;
		e_score[boss_total_score] = e_score[boss_total_score] + BonusPerCombo;
		TotalScore = TotalScore + BonusPerCombo;
		break;


	}
	case MIDDLE:
	{
		m_score[boss_combo_bonus] = m_score[boss_combo_bonus] + BonusPerCombo;
		m_score[boss_total_score] = m_score[boss_total_score] + BonusPerCombo;
		TotalScore = TotalScore + BonusPerCombo;
		break;

	}
	case HIGH:
	{
		h_score[boss_combo_bonus] = h_score[boss_combo_bonus] + BonusPerCombo;
		h_score[boss_total_score] = h_score[boss_total_score] + BonusPerCombo;
		TotalScore = TotalScore + BonusPerCombo;
		break;
	}

	}
}
void boss_time (int level, int score)
{
	//extern char O_X[MAX_Q];
	extern int e_score[];
	extern int m_score[];
	extern int h_score[];
	extern int TotalScore;
	switch (level)
	{
	case ELEMENTARY:
	{
		e_score[boss_time_bonus] = e_score[boss_time_bonus] + score;
		e_score[boss_total_score] = e_score[boss_total_score] + score;
		TotalScore = TotalScore + score;
		break;
	}
	case MIDDLE:
	{
		m_score[boss_time_bonus] = m_score[boss_time_bonus] + score;
		m_score[boss_total_score] = m_score[boss_total_score] + score;
		TotalScore = TotalScore + score;
		break;

	}
	case HIGH:
	{
		h_score[boss_time_bonus] = h_score[boss_time_bonus] + score;
		h_score[boss_total_score] = h_score[boss_total_score] + score;
		TotalScore = TotalScore + score;
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
//점수 리셋-배열로 다시 만들어두겠습니다!
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
	extern int TotalScore;

	e_total_score=0, e_correct_score = 0, e_time_bonus = 0, e_combo_bonus = 0;
	eboss_total_score = 0, eboss_correct_score = 0, eboss_time_bonus = 0, eboss_combo_bonus = 0;
	E_O = 0, E_num_Q = 0, E_O_BOSS = 0, E_num_Q_boss = 0;
	m_total_score = 0, m_correct_score = 0, m_time_bonus = 0, m_combo_bonus = 0;
	mboss_total_score = 0, mboss_correct_score = 0, mboss_time_bonus = 0, mboss_combo_bonus = 0;
	M_O = 0, M_num_Q = 0, M_O_BOSS = 0, M_num_Q_boss = 0;
	h_total_score = 0, h_correct_score = 0, h_time_bonus = 0, h_combo_bonus = 0;
	hboss_total_score = 0, hboss_correct_score = 0, hboss_time_bonus = 0, hboss_combo_bonus = 0;
	H_O = 0, H_num_Q = 0, H_O_BOSS = 0, H_num_Q_boss = 0;
	//TotalScore = 0;
	

}
