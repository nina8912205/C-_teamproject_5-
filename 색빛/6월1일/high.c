#include "common.h"

void high(int n) // high(0): 처음시작, high(1): 처음아님.
{
	extern int O_X[], scorearray[SCHSIZE][ASIZE], TotalScore;
	extern int item[3];
	extern int time_left, end_game, gobackstart;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;

	gobackstart = 0;
	time_left = 0;  // 남은시간 초기화
	resetScore(H);
	resetOX();

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
		score = grade * 5000; // 학년 당 배점

		for (int num = 1; num <= 3; num++)
		{
			if (item[LIFE] == 0)
				break;

			scorearray[H][Q_SOLVED]++;

			// 레이아웃
			layout(H, grade, num, score);

			// 문제출력
			gotoxy(40, 19);

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

			// 문제맞추기
			timelimit = Htime(grade);
			result = game(40, timelimit, input, word, scorearray[H][Q_SOLVED], H, 0, score);

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
					timescore(H, TimeBonus(time_left));
					correct(H, score);
					if (O_X[scorearray[H][Q_SOLVED] - 2] == 1)
						combo(H);
					scorearray[H][Q_CORRECT]++;
					break;
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					layout(E, grade, num, score);
					gotoxy(40, 19);	printf("%s", word);
					timelimit = Htime(grade);
					result = game(40, timelimit, input, word, scorearray[H][Q_SOLVED], H, 0, score);
				}
				else if (result == 4) {
					gobackstart = 1;
					break;
				}
				else
					break;
			}
			if (gobackstart)
				break;

			// 정오표 기록
			O_X[scorearray[H][Q_SOLVED] - 1] = result;			
		}
		if (gobackstart)
			break;
	}
	if (!gobackstart)
	{
		// 목숨이 있을 경우, 중학교 보스!
		if (item[LIFE])
			test(H);

		// 성적표 출력
		end_game = Scorecard(H);

		system("cls");
		Final_Scorecard();
		Sleep(5000);
	}
		
}
