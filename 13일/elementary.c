#include "common.h"

void elementary()
{
	char word[SIZE];
	char input[SIZE];
	int score;
	int k;             // 문자열 길이 조절 변수

	system("cls");
	drawline();
	get_name();
	item_random();
	system("cls");

	// item_board(); // 아이템 보유 현황 띄워줌


	// 난이도 조절
	// 학년별로 단어길이, 


	for (int i = 1; i <= 6; i++)  // 1학년 ~ 6학년
	{
		for (int j = 1; j <= 3; j++)  // 학년당 문제 개수 : 3개 
		{
			drawline();
			drawitem();
			drawmenu();
			gotoxy(32, 15);

			printf("[%d 학년 - 문제 %d 번]\n", i, j);

			// 랜덤 문자열
			for (k = 0; k <= i-1; k++) // 해당 학년만큼 길이의 랜덤문자열
			{
				word[k] = 'a' + (rand() % 26);
			}
			word[k] = '\0';

			// 배점 부여
			score = i * 1000;

			// 문제 출력
			gotoxy(32, 17);
			printf("문제 : ");
			printf("%s\n", word);
			gotoxy(52, 17);
			printf("           배점 : %d 점\n\n", score);

			// 문제 맞추기 
			gotoxy(32, 19);
			printf("문제를 따라 치세요 : ");
			gets_s(input, SIZE);

			if (!strcmp(input, word))
			{
				gotoxy(32, 21);
				printf("성공 ! 누적 총점 : %d", elementary_score_add(score));
	
				//if (lefttime > 0)
				//{
				//	elemetary_score += score;
				//}
			}
			else
			{
				decrease_life();
			}

			Sleep(2000);
			system("cls");
		}
	
	}
	drawline();
	drawitem();
	drawmenu();
	gotoxy(32, 15);
	printf("교장 선생님 두두둥장\n");
	Sleep(1000);
	gotoxy(32, 17);
	printf("선생님을 이겨보세요~");
	Sleep(2000);
	system("cls");
	for (int i = 1; i <= 5; i++) {
		drawline();
		drawitem();
		drawmenu();
		gotoxy(32, 15);
		printf("[보스 - 문제 %d 번]\n", i);

		elem_boss();
		Sleep(2000);
		system("cls");
	}

	///* == 1 학년 == */
	///*for (int i = 1; i <= 5; i++)
	//{*/
	//// 랜덤 문자열 
	//word[0] = 'a' + (rand() % 26);
	//word[1] = '\0';

	//// 배점 부여
	//score = 1000;

	//// 문제 출력
	//printf("문제 : ");
	//printf("%s\n", word);
	//printf("                                                    배점 : %d 점\n", score);

	//// 문제 맞추기 
	//printf("문제를 따라 치세요 : ");
	//gets_s(input, SIZE);

	//if (!strcmp(input, word))
	//{
	//	printf("%d", elementary_score_add(score));
	//	//if (lefttime > 0)
	//	//{
	//	//	elemetary_score += score;
	//	//}
	//}
	//else
	//{
	//	decrease_life();
	//}
	//

	///* == 2 학년 == */
	//for (int i = 1; i <= 5; i++)
	//{
	//	// 문제 출력
	//	// 문제 맞추기 
	//	if (// 남은시간 > 0 && 정답 맞춤)
	//		{
	//			// elem_total_score += score;
	//		}
	//	else
	//	{
	//		// life--;
	//	}
	//}
	///* == 3 학년 == */
	///* == 4 학년 == */
	///* == 5 학년 == */
	///* == 6 학년 == */

	///* === 보스 === */
	//for (i = 1; i <= 5; i++)
	//{
	//	// 문제 풀고, 

	//	if (// 남은시간 > 0 && 문제 맞추면)
	//		{
	//			correct_number += 1; // 맞힌 문제 개수 누적
	//			if (// 남은시간 > 5초)
	//			{
	//					// elem_total_score += boss_score
	//				}
	//				else // 0< 남은시간 <= 5초
	//				{
	//				// elem_total_score += boss_score * (1- 남은시간 * 0.1)
	//			}
	//				}

	//}


	//if (// correct_number >= 전체 문제중 k개)
	//	{
	//		printf("교장 보스를 이겼습니다 !\n"); // 사용자 승리 ! 
	//		printf("축하합니다 ! 초등학교를 졸업했습니다 !\n");
	//		printf("성적표 출력\n");  // 성적표 출력
	//		printf("중학교로 진급하시겠습니까? \n( 네 : \'y\' / 게임종료 : press any button ) (5초 이내 응답 없으면 자동 진급됩니다)");

	//	}
	//else
	//{
	//	// 보스단계 실패 ㅠㅠ
	//	printf("재도전 하시겠습니까? (네 : press 'y' / 게임종료 : press any button)");


	//}
}
