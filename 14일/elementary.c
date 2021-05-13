#include "common.h"

void elementary()
{
	char word[SIZE];
	char input[SIZE];
	int score;
	int k;             // 문자열 길이 조절 변수


	system("cls");
	drawline();
	item_random();    // 아이템 뽑기
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
				printf("성공 ! 배점 획득 !! 누적 총점 : %d", elementary_score_add(score));
	
				//if (lefttime > 0)
				//{
				//	elemetary_score += score;
				//}
			}
			else
			{
				gotoxy(32, 21);
				printf("실패 ㅠㅠ 목숨차감 ... 누적 총점 : %d", elementary_score_add(0));
				decrease_life();
			}

		

			Sleep(2000);
			system("cls");
		}
	
	}
