//변수 리스트
//name: 이름	elementary_score: 초등학교 총점		middle_score: 중학교 총점	high_score: 고등학교 총점
//grade: 등급
//level: 게임을 플레이한 레벨 ex)초/중/고 => e/m/h ***게임 진행시 고정 필요
//time_bonus, combo_bonus
#include "common.h"

//최종 종료시 성적표
void Final_Scorecard(char name[],int elementary_score, int middle_score, int high_score)
{
	int grade;
	int scoresum = elementary_score + middle_score + high_score;
	
	//등급 산정-추후 조정하기
	if (scoresum < 10000)
		grade = 9;
	else if (10000 <= scoresum && scoresum < 20000)
		grade = 8;
	else if (20000 <= scoresum && scoresum < 30000)
		grade = 7;
	else if (30000 <= scoresum && scoresum < 40000)
		grade = 6;
	else if (40000 <= scoresum && scoresum < 50000)
		grade = 5;
	else if (50000 <= scoresum && scoresum < 60000)
		grade = 4;
	else if (60000 <= scoresum && scoresum < 70000)
		grade = 3;
	else if (70000 <= scoresum && scoresum < 80000)
		grade = 2;
	else
		grade = 1;

	printf("                     성적표                     \n");
	printf("                                    이름:	%s  \n",name);//이름 출력
	printf("                                                \n");
	printf("             초등학교:  %d점\n\n",elementary_score);
	printf("             중학교  :  %d점\n\n",middle_score);
	printf("             고등학교:  %d점\n\n", high_score);
	printf("             총점    :  %d점\n\n", elementary_score + middle_score + high_score);
	printf("             최종 등급: %d등급", grade);

}

void Scorecard(char name[], char level, int score, int time_bonus, int combo_bonus) //level: e-elementary  m-middle  h-high
{
	if (level == 'e')
	{
		printf("                  초등학교 성적표          \n\n");
		printf("          ! 초등학교 졸업을 축하합니다 !  \n\n");
	}
		
	if(level=='m')
	{
		printf("                  중학교 성적표          \n\n");
		printf("          ! 중학교 졸업을 축하합니다 !  \n\n");
	}
	if(level=='h')
	{
		printf("                  고등학교 성적표          \n\n");
		printf("          ! 고등학교 졸업을 축하합니다 !  \n\n");
	}
	
	printf("                                         이름:    %s	\n",name);//이름 출력
	printf("                                                \n");
	printf("             획득한 점수  :  %d점\n\n", score);
	printf("             시간추가 점수:  %d점\n\n", time_bonus);
	printf("             콤보점수     :  %d점\n\n", combo_bonus);
	printf("             총점         :  %d점\n\n", score+time_bonus+combo_bonus);
	
	
}