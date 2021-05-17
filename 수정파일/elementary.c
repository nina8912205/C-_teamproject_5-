#include "common.h"

int O_X[MAX_Q] = { 0 };                // OX_Correct 함수 및 다른 함수에서도 호출해야 하므로 전역변수로 지정.
extern int Combo_num(int question);
int ComboBonus(int combo);

void elementary()
{
	char word[SIZE] = { '\0' };         // 지역변수는 초기 선언에 쓰레기 값 있으므로 '\0' 이나 0으로 초기화 시켜줌
	char input[SIZE] = { '\0' };
	int score = 0;
	int k;                      // 문자열 길이 조절 변수
	int start, end;             // 시작시각, 종료시각 . 지역변수이므로 elementary 함수 호출할 때 마다 초기화. 
	double timelimit;              // level 별(학년별) 제한시간

	extern int O_X[MAX_Q];     // 정오표
	int num_Q = 1;              // 정오표 기록을 위한 문제 번째수  ex) 초등학교 총 18문제 => 1번 ~ 18번 문제 

	extern int elementary_total_score;   // 획득한 총 누적점수 (초등학교)
	extern int life, changeword, addtime;

	get_name();       // 이름 입력받기
	system("cls");

	drawline();      // 레이아웃 그리기

	item_random();    // 아이템 뽑기
	system("cls");

	// item_board(); // 아이템 보유 현황 띄워줌


	// 난이도 조절
	// 학년별로 단어길이, 


	for (int i = 1; i <= 6; i++)  // 1학년 ~ 6학년
	{
		//목숨 검사
		if (life == 0)
		{
			life = 3, changeword = 0, addtime = 0;
			elementary_total_score = 0;
			break;
		}
		
		timelimit = (double)TimeLimit(i);   // 학년 별 제한시간 

		for (int j = 1; j <= 3; j++)  // 학년당 문제 개수 : 3개 
		{
			//목숨검사
			if (life == 0)
				break;
			drawline();
			draws('초등', i, elementary_total_score);
			drawitem();
			drawmenu();
			gotoxy(32, 15);

			// 배점 부여
			score = i * 1000;

			printf("[%d 학년 - 문제 %d 번]\n", i, j);

			// 랜덤 문자열
			for (k = 0; k <= i - 1; k++)             // 해당 학년만큼 길이의 랜덤문자열
			{
				word[k] = 'a' + (rand() % 26);
			}

			// 문제 출력
			gotoxy(32, 17);
			printf("문제 : ");
			printf("%s\n", word);
			gotoxy(52, 17);
			printf("           배점 : %d 점\n\n", score);

			// 문제 맞추기 
			gotoxy(32, 19);
			printf("문제를 따라 치세요 : ");
			start = clock();  // 시작 시각 기록
			gets_s(input, SIZE);


			// ================================================= 시간 ===================================== // 
			// 05/17 : 제한시간 내 정답 에 따른 보너스 점수 추가 / 제한시간 내 오답에 따른 목숨 차감 / 제한시간 초과에 따른 목숨 차감
			end = clock();  // 종료시각 기록



			if (timelimit >= end - start)   // 시간 내에 입력 완료한 경우
			{
				if (!strcmp(input, word))   // 근데 맞았어
				{
					gotoxy(32, 21);
					printf("정답 !! %.2f 초 남기고 성공 했습니다! 배점 획득 !! \n", TimeLeft(timelimit, start, end));
					elementary_score_add(score);

					//if (lefttime > 0)
					//{
					//	elemetary_score += score;
					//}
					// ===== 정오표 기록 ===
					OX_Correct(num_Q);	// num_Q 번째 문제 가 정답이면 정오표에 1 기록
					// 남긴 점수에 해당하는 보너스 점수 추가
					printf("%.2f\n", elementary_score_time(TimeBonus(start, end, timelimit)));
					
					

					
					num_Q++;

				}
				else    // 근데 틀렸어
				{
					gotoxy(32, 21);
					printf("땡 ! 틀렸습니다. 목숨 차감 ㅠㅠ\n");
					decrease_life();
					
					// ===== 정오표 기록 ===
					OX_Wrong(num_Q);	// num_Q 번째 문제 가 오답이면 정오표에 2 기록
					num_Q++;
					
				}
			}
			else    // 시간 내에 입력 못했어
			{
				gotoxy(32, 21);
				printf("시간초과 ! 목숨 차감 ㅠㅠ");
				decrease_life();

				// ===== 정오표 기록 ===
				OX_Wrong(num_Q);	// num_Q 번째 문제 가 오답이면 정오표에 2 기록
				num_Q++;
			
				
			}


			Sleep(2000);
			system("cls");
		}

	}

	

	// 콤보점수 계산
	gotoxy(32, 23);
	printf("콤보점수 : %d 점", ComboBonus(Combo_num(18)));

	// 정오표 초기화
	reset_OX();
	// 나중에 ComboBonus 함수를 살짝 바꿔서 특정 변수에 콤보 점수 저장해두면 life 0 으로 인해 게임 종료돼도 어딘가 콤보 저장되어
	life = 3; //목숨 초기화
}
