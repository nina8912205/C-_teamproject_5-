#include "common.h"




void high(int n) // high(0): 처음시작, high(1): 처음아님.
{

	extern int O_X[], scorearray[GRADESIZE][SSIZE], TotalScore;
	extern int life, changeword, addtime;
	extern int time_left;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result, size;
	int go;

	time_left = 0;  // 남은시간 초기화
	resetOX();

	if (!n)
	{
		get_name(MIDDLE);
		system("cls");
	}

	drawline(21, 8, 75, 25);       // 레이아웃 그리기

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
			printf("total: %d, e_time: %d", TotalScore, scorearray[H][TIME]);
			gotoxy(32, 25);
			printf("m_correct: %d, m_combo: %d", scorearray[H][CORRECT], scorearray[H][COMBO]);
			scorearray[H][Q_SOLVED]++;
			// 레이아웃
			drawline(21, 8, 75, 25);
			draws("고등", grade, num);
			drawitem();
			drawmenu();

			// 문제출력
			gotoxy(32, 17);
			printf("문제 : ");

			switch (grade) // 학년별 문제 출력
			{
			case 1:                    // 1학년: 7글자 영단어
				random_word(10, word);
				break;
			case 2:                    // 2학년: 랜덤 문자열(7글자)
				word_short(word);
				break;
			case 3:                    // 3학년: 짧은 글
				word_short_h(word);
				break;
			}
			gotoxy(70, 17);
			printf("배점 : %d 점", score);

			// 문제맞추기
			gotoxy(32, 19);
			printf("문제를 따라 치세요: ");
			cursor(1);
			size = strlen(word);
			timelimit = Htime(grade);
			result = game(size, timelimit, input, word, scorearray[H][Q_SOLVED]);

			// 단어 바꾸기 실행
			if (result == 5)
			{
				num--;
				continue;
			}

			// result 0: 오답, 1: 정답, 2: 메뉴열었음
			while (1)
			{
				if (result == 1)
				{
					timescore(HIGH, TimeBonus(time_left));
					correct(HIGH, score);
					if (O_X[scorearray[H][Q_SOLVED] - 2] == 1)
						combo(HIGH);
					scorearray[H][Q_CORRECT]++;
					break;
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					drawline(21, 8, 75, 25);
					draws("고등", grade, num);
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("문제 : %s", word);
					gotoxy(70, 17);
					printf("배점 : %d 점", score);

					gotoxy(32, 19);
					printf("문제를 따라 치세요: ");
					timelimit = Htime(grade);
					result = game(size, timelimit, input, word, scorearray[H][Q_SOLVED]);
				}
				else
					break;
			}

			// 정오표 기록
			O_X[scorearray[H][Q_SOLVED] - 1] = result;

		}
	}

	// 목숨이 있을 경우, 수능!
	/*if (life > 0)
		 h_boss();*/

		 // 성적표 출력
	go = Scorecard(MIDDLE);

	// 다음 단계
	/*if (go)
		high(1);
	else
		game_title();*/

}