#include "common.h"

//정오표 리셋
void resetOX()
{
	extern char O_X[];
	for (int i = 0; i < MAX_Q; i++)
	{
		O_X[i] = 0;
	}
}

//초등점수 리셋
void e_score_reset(void)
{
	extern int e_score[];
	for (int i = TOTAL; i < SSIZE; i++)
		e_score[i] = 0;
}

//점수 리셋
//void score_reset()
//{
//	extern int e_score[], m_score[], h_score[] ,TotalScore;
//	extern int E_O, E_num_Q, E_O_BOSS, E_num_Q_boss;
//	extern int M_O, M_num_Q, M_O_BOSS, M_num_Q_boss;
//	extern int H_O, H_num_Q, H_O_BOSS, H_num_Q_boss;
//
//	e_total_score = 0, e_correct_score = 0, e_time_bonus = 0, e_combo_bonus = 0;
//	eboss_total_score = 0, eboss_correct_score = 0, eboss_time_bonus = 0, eboss_combo_bonus = 0;
//	E_O = 0, E_num_Q = 0, E_O_BOSS = 0, E_num_Q_boss = 0;
//	m_total_score = 0, m_correct_score = 0, m_time_bonus = 0, m_combo_bonus = 0;
//	mboss_total_score = 0, mboss_correct_score = 0, mboss_time_bonus = 0, mboss_combo_bonus = 0;
//	M_O = 0, M_num_Q = 0, M_O_BOSS = 0, M_num_Q_boss = 0;
//	h_total_score = 0, h_correct_score = 0, h_time_bonus = 0, h_combo_bonus = 0;
//	hboss_total_score = 0, hboss_correct_score = 0, hboss_time_bonus = 0, hboss_combo_bonus = 0;
//	H_O = 0, H_num_Q = 0, H_O_BOSS = 0, H_num_Q_boss = 0;
//	//TotalScore = 0;
//}