#include "common.h"
#define MSIZE 7

void middle(int n) // middle(0): 처음시작, middle(1): 처음아님.
{
	extern int O_X[], SCORE[SCHSIZE][ASIZE], TotalScore;
	extern int item[3];
	extern int end_game;

	char word[SIZE], input[SIZE];
	int grade, x = 0;
	int result;

	// 리셋
	resetOX();

	if (!n)
	{
		get_name();
		system("cls");
	}

	welcome(M);

	drawline(21, 8, 75, 25);       // 레이아웃 그리기

	item_random(2);                // 아이템 뽑기

	for (grade = 1; grade <= 3; grade++)
	{
		if (item[LIFE] == 0)
			break;

		for (int num = 1; num <= 3; num++)
		{

			// 레이아웃
			layout(M, grade, num);
			SCORE[M][Q_SOLVED]++;

			// 문제출력
			switch (grade) // 학년별 문제 출력
			{
			case 1:
				gotoxy(56, 19);// 1학년: 7글자 영단어				
				x = 56;
				word_7(word);
				break;
			case 2:
				gotoxy(56, 19);// 2학년: 랜덤 문자열(7글자)
				x = 56;
				random_word(MSIZE, word);
				break;
			case 3:
				gotoxy(40, 19);// 3학년: 짧은 글
				x = 40;
				word_short(word);
				break;
			}

			// 문제맞추기			
			result = game(x, input, word, M, grade, 0);
			

			// 단어 바꾸기 실행
			if (result == WORDITEM)
			{
				num--;
				gotoxy(x, 17);
				for (int i = 0; i < strlen(word); i++)
					printf(" ");
				continue;
			}

			while (1)
			{
				if (result == HOWTOPLAY) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					layout(M, grade, num);
					gotoxy(x, 19);	printf("%s", word);
					result = game(x, input, word, M, grade, 0);
				}
				if (result == STARTMENU || result == CHANGE_LEVEL)
					return;
				else
					break;
			}

			// 정오표 기록
			O_X[SCORE[M][Q_SOLVED]] = result;
		}

		if (item[LIFE] && grade < 3)
			gradeup();
	}

	// 목숨이 있을 경우, 중학교 보스!
	if (item[LIFE])
		test(M);

	// 성적표 출력
	end_game = Scorecard(M);

	if (item[LIFE] && end_game == 0)
		high(1);

}