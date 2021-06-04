#include "common.h"

void high(int n) // high(0): 처음시작, high(1): 처음아님.
{
	extern int O_X[], SCORE[SCHSIZE][ASIZE], TotalScore;
	extern int item[3];
	extern int end_game;

	char word[SIZE], input[SIZE];
	int grade, x;
	int result;

	resetOX();
	SCORE[H][Q_SOLVED] = 1;

	if (!n)
	{
		get_name();
		system("cls");
	}

	welcome(H);

	drawline(21, 8, 75, 25);       // 레이아웃 그리기

	item_random(2);    // 아이템 뽑기

	for (grade = 1; grade <= 3; grade++)
	{
		if (item[LIFE] == 0)
			break;

		for (int num = 1; num <= 3; num++)
		{
			// 레이아웃
			layout(H, grade, num);

			// 문제출력
			gotoxy(40, 19);
			SCORE[H][Q_SOLVED]++;

			switch (grade) // 학년별 문제 출력
			{
			case 1: // 1학년: 10글자 영단어				
				x = 55;
				gotoxy(x, 19);
				random_word(10, word);
				break;
			case 2: // 2학년: 짧은 글
				x = 50;
				gotoxy(x, 19);
				word_short(word);
				break;
			case 3: // 3학년: 덜 짧은 글
				x = 33;
				gotoxy(x, 19);
				word_short_h(word);
				break;
			}

			// 문제맞추기
			result = game(x, input, word,  H, grade, 0);

			// 단어 바꾸기 실행
			if (result == WORDITEM)
			{
				num--;
				continue;
			}

			// result 0: 오답, 1: 정답, 2: 메뉴열었음
			while (1)
			{
				if (result == HOWTOPLAY) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					layout(H, grade, num);
					gotoxy(x, 19);	printf("%s", word);
					result = game(x, input, word, H, grade, 0);
				}
				if (result == STARTMENU || result == CHANGE_LEVEL)
					return;
				else
					break;
			}

			// 정오표 기록
			O_X[SCORE[H][Q_SOLVED]] = result;
		}

		if (item[LIFE] && grade < 3)
			gradeup();
	}
	// 목숨이 있을 경우, 중학교 보스!
	if (item[LIFE])
		test(H);

	// 성적표 출력
	end_game = Scorecard(H);

	if (SCORE[E][T_Q_SOLVED]+ SCORE[M][T_Q_SOLVED] + SCORE[H][T_Q_SOLVED] == 15)
	{
		Final_Scorecard();
		Sleep(10000);
	}		
}