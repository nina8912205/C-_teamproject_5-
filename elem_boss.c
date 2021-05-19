#include "common.h"
#define NUMBER_CHARACTERS 6

void elem_boss() {
	/*
	초등학교 ~ 초등학교 보스로 넘어가는 부분
	출력물 추가해야함
	ex) 보스 대사
	*/
	drawline();
	drawitem();
	drawmenu();
	gotoxy(32, 15);
	printf("축하합니다");		//임시
	Sleep(1000);
	gotoxy(32, 17);
	printf("초등학교 교육과정을 무사히 마쳤습니다");	//임시
	Sleep(1000);
	gotoxy(32, 19);
	printf("초등학교 교장 선생님을 이기세요");		//임시
	Sleep(2000);
	system("cls");

	for (int i = 1; i <= 5; i++) {
		drawline();
		drawitem();
		drawmenu();
		gotoxy(32, 15);
		printf("[%초등학교 졸업 시험 - 문제 %d 번]\n", i);

		elem_boss_word();
		Sleep(2000);
		system("cls");
	}
}

void elem_boss_word() {
	srand((unsigned int)time(NULL));
	char word[256];   //출력 글자
	char user[256];   //입력 글자
	int t1, t2;
	int x = 0;
	int LIMIT = 7000;	//시간 제한 7초
	int Bscore = 8000;

	extern int O_X[MAX_Q];     // 정오표
	int num_Q = 1;

	extern int elementary_total_score;   // 획득한 총 누적점수 (초등학교)

	for (int i = 0; i < NUMBER_CHARACTERS; i++) {
		word[i] = 'a' + rand() % 26;
	}
	word[NUMBER_CHARACTERS] = 0;
	gotoxy(32, 17);
	printf("문제 : ");
	printf("%s\n", word);
	gotoxy(52, 17);
	printf("           배점 : %d 점\n\n", Bscore);
	gotoxy(32, 19);
	printf("문제를 따라 치세요 : ");
	t1 = clock();

	do {
		t2 = clock();
		if (difftime(t2, t1) > LIMIT) {
			x = 1;
			break;
		}
	} while (!_kbhit());

	if (x != 1)
		gets_s(user, SIZE);

	if (LIMIT >= t2 - t1)   // 시간 내에 입력 완료한 경우
	{
		if (!strcmp(word, user))   // 근데 맞았어
		{
			gotoxy(32, 21);
			printf("정답 !! %.2f 초 남기고 성공 했습니다! 배점 획득 !! \n", TimeLeft(LIMIT, t1, t2));
			elementary_score_add(Bscore);

			//if (lefttime > 0)
			//{
			//	elemetary_score += score;
			//}

			// 남긴 점수에 해당하는 보너스 점수 추가
			printf("%.2f", elementary_score_time(TimeBonus(t1, t2, LIMIT)));

			// ===== 정오표 기록 ===
			OX_Correct(num_Q);	// num_Q 번째 문제 가 정답이면 정오표에 1 기록
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
}
