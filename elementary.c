#include "common.h"

void elementary()
{
	system("cls");
	
	/* == 1 학년 == */
	for (int i = 1; i <= 5; i++)
	{
		// 문제 출력
		// 문제 맞추기 
		if (// 남은시간 > 0 && 정답 맞춤)
		{
			// elem_total_score += score;
		}
		else
		{
			// life--;
		}
	}

	/* == 2 학년 == */
	for (int i = 1; i <= 5; i++)
	{
		// 문제 출력
		// 문제 맞추기 
		if (// 남은시간 > 0 && 정답 맞춤)
			{
				// elem_total_score += score;
			}
		else
		{
			// life--;
		}
	}
	/* == 3 학년 == */
	/* == 4 학년 == */
	/* == 5 학년 == */
	/* == 6 학년 == */

	/* === 보스 === */
	for (i = 1; i <= 5; i++)
	{
		// 문제 풀고, 

		if(// 남은시간 > 0 && 문제 맞추면)
		{
			correct_number += 1; // 맞힌 문제 개수 누적
			if(// 남은시간 > 5초)
			{
				// elem_total_score += boss_score
			}
			else // 0< 남은시간 <= 5초
			{
				// elem_total_score += boss_score * (1- 남은시간 * 0.1)
			}
		}
		
	}


	if(// correct_number >= 전체 문제중 k개)
	{
		printf("교장 보스를 이겼습니다 !\n"); // 사용자 승리 ! 
		printf("축하합니다 ! 초등학교를 졸업했습니다 !\n"); 
		printf("성적표 출력\n");  // 성적표 출력
		printf("중학교로 진급하시겠습니까? \n( 네 : \'y\' / 게임종료 : press any button ) (5초 이내 응답 없으면 자동 진급됩니다)");
		
	}
	else
	{
		// 보스단계 실패 ㅠㅠ
		printf("재도전 하시겠습니까? (네 : press 'y' / 게임종료 : press any button)");


	}
}
