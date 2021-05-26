#include "common.h"

int M_num_Q;
int M_O;

void middle(int n) // middle(0): 처음시작, middle(1): 처음아님.
{
	resetOX();
	extern int O_X[];
	extern int life, changeword, addtime;
	extern int time_left;
	extern int m_score[];
	extern int TotalScore;
	time_left = 0;  // 남은시간 초기화

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;

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
			gotoxy(32, 24);
			printf("total: %d, e_time: %d", TotalScore, m_score[time_bonus]);
			gotoxy(32, 25);
			printf("m_correct: %d, m_combo: %d", m_score[correct_score], m_score[combo_bonus]);
			M_num_Q++;
			// 레이아웃
			drawline();
			draws("중", grade, num);///수정???????????
			drawitem();
			drawmenu();

			// 문제출력
			gotoxy(32, 17);
			printf("문제 : ");

			switch (grade) // 학년별 문제 출력
			{
			case 1:                    // 1학년: 7글자 영단어
				word_7(word);
				break;
			case 2:                    // 2학년: 랜덤 문자열(7글자)
				random_word(7, word);
				break;
			case 3:                    // 3학년: 짧은 글
				random_word(7, word);
				break;
			}
			//******* 5/24(현욱) - 제한시간 출력 추가, 레이아웃 야악간 수정
			gotoxy(32, 15);
			printf("배점 : %d 점 / 제한시간: %d 초", score, Mtime(grade));


			// 문제맞추기
			gotoxy(32, 19);
			printf("문제를 따라 치세요: ");
			cursor(1);
			timelimit = Mtime(grade);
			result = game(7, timelimit, input, word,M_num_Q);

			// result 0: 오답, 1: 정답, 2: 메뉴열었음
			while (1)
			{
				if (result == 1)
				{
					timescore(MIDDLE, TimeBonus(time_left));
					correct(MIDDLE, score);
					if (O_X[M_num_Q - 2] == 1)
					{
						combo(MIDDLE);
					}
					
					M_O++;
					break;
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					drawline();
					draws("중", grade, num);/////?????수정
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("문제 : %s", word);
					gotoxy(70, 17);
					printf("배점 : %d 점", score);

					gotoxy(32, 19);
					printf("문제를 따라 치세요: ");
					timelimit = Mtime(grade);
					result = game(7, timelimit, input, word, M_num_Q);
				}
				else
					break;
			}

			// 정오표 기록
			O_X[M_num_Q - 1] = result;
			
		}
	}

	// 목숨이 있을 경우, 중학교 보스!
	/*if (life > 0)
		boss_score = m_boss();*/
	/*
		// 콤보 보너스 계산
	combo_bonus = ComboBonus(Combo_num(--num_Q));

	// 시간 보너스 계산
	time_bonus = TimeBonus(time_left);*/

	// 성적표 출력
	go = Scorecard(MIDDLE);

	// 다음 단계
	/*if (go)
		high(1);
	else
		game_title();*/

}