#include "common.h"

int h_total_score = 0;

void high(int n) // high(0): 처음시작, high(1): 처음아님.
{
	extern int O_X[];
	extern int life, changeword, addtime;
	extern int time_left;

	time_left = 0;  // 남은시간 초기화

	char word[SIZE], input[SIZE];
	int grade, score = 0, num_Q = 1;
	int timelimit, result;
	int O = 0;
	int h_score = 0, time_bonus = 0;
	int combo_bonus = 0, boss_score = 0;
	int go;

	if (!n)
	{
		drawline();
		get_name();
		system("cls");
	}

	drawline();       // 레이아웃 그리기

	item_random(2);    // 아이템 뽑기
	system("cls");


	for (grade = 1; grade <= 3; grade++)
	{
		score = grade * 3000; // 학년 당 배점

		// 목숨 검사
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++)
		{
			// 레이아웃
			drawline();
			draws("고등", grade, num, h_score);
			drawitem();
			drawmenu();

			// 문제출력
			gotoxy(30, 17);
			printf("문제 : ");

			switch (grade) // 학년별 문제 출력
			{
			case 1:                    // 1학년: 랜덤 문자열(10글자)
				random_word(10, word);
				break;
			case 2:                    // 2학년: 짧은 글
				word_short(word);
				break;
			case 3:                    // 3학년: 짧은 글보다는 조금 더 긴 글
				word_short_h(word);
				break;
			}
			gotoxy(70, 15);
			printf("배점 : %d 점", score);

			// 문제맞추기
			gotoxy(30, 19);
			printf("문제를 따라 치세요: ");
			cursor(1);
			timelimit = Htime(grade);
			result = game(7, timelimit, input, word);

			// result 0: 오답, 1: 정답, 2: 메뉴열었음
			while (1)
			{
				if (result == 1)
				{
					h_score += score;
					O++;
					break;
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					drawline();
					draws("고등", grade, num, h_score);
					drawitem();
					drawmenu();
					gotoxy(30, 17);

					printf("문제 : %s", word);
					gotoxy(70, 17);
					printf("배점 : %d 점", score);

					gotoxy(30, 19);
					printf("문제를 따라 치세요: ");
					timelimit = Htime(grade);
					result = game(7, timelimit, input, word);
				}
				else
					break;
			}

			// 정오표 기록
			O_X[num_Q - 1] = result;
			num_Q++;
		}
	}

	// 목숨이 있을 경우, 고등학교 보스!
	/*if (life > 0)
		boss_score = h_boss();*/

		// 콤보 보너스 계산
	combo_bonus = ComboBonus(Combo_num(--num_Q));

	// 시간 보너스 계산
	time_bonus = TimeBonus(time_left);

	// 성적표 출력
	go = Scorecard(HIGH, h_score, time_bonus, combo_bonus, boss_score, num_Q, O);

	//메뉴 이동
}
