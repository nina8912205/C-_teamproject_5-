#include "common.h"
#define MSIZE 7

void middle(int n) // middle(0): 처음시작, middle(1): 처음아님.
{
	extern int O_X[], scorearray[SCHSIZE][ASIZE], TotalScore;
	extern int life, changeword, addtime;
	extern int time_left, gobackstart, end_game;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;

	// 리셋
	gobackstart = 0;
	time_left = 0;
	resetScore(M);
	resetOX();

	if (!n)
	{
		get_name();
		system("cls");
	}

	welcome(M);

	drawline(21, 8, 75, 25);       // 레이아웃 그리기

	item_random(2);                // 아이템 뽑기
	system("cls");

	for (grade = 1; grade <= 1; grade++)
	{
		score = grade * 3000; // 학년 당 배점

		// 목숨 검사
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++)
		{
			gotoxy(32, 24); printf("total: %d, e_time: %d", TotalScore, scorearray[M][TIME]);
			gotoxy(32, 25); printf("m_correct: %d, m_combo: %d", scorearray[M][CORRECT], scorearray[M][COMBO]);
			scorearray[M][Q_SOLVED]++;

			// 레이아웃
			drawline(21, 8, 75, 25);
			draws("중", grade, num);
			drawitem();
			drawmenu();

			// 문제출력
			gotoxy(32, 17); printf("문제 : ");

			switch (grade) // 학년별 문제 출력
			{
			case 1:                    // 1학년: 7글자 영단어
				word_7(word);
				break;
			case 2:                    // 2학년: 랜덤 문자열(7글자)
				random_word(MSIZE, word);
				break;
			case 3:                    // 3학년: 짧은 글
				word_short(word);
				break;
			}
			gotoxy(70, 17);	printf("배점 : %d 점", score);

			// 문제맞추기
			gotoxy(32, 19);	printf("문제를 따라 치세요: ");
			cursor(1);
			timelimit = Mtime(grade);
			result = game(timelimit, input, word, scorearray[M][Q_SOLVED]);

			// 단어 바꾸기 실행
			if (result == 5)
			{
				num--;
				gotoxy(36, 17); printf("                                   ");
				continue;
			}

			// result 0: 오답, 1: 정답, 2: 메뉴열었음, 3: 시작메뉴 4:레벨 재선택 5:단어바꾸기
			while (1)
			{
				if (result == 1)
				{
					timescore(M, TimeBonus(time_left));
					correct(M, score);
					if (O_X[scorearray[M][Q_SOLVED] - 2] == 1)
						combo(M);
					scorearray[M][Q_CORRECT]++;
					break;
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					drawline(21, 8, 75, 25);
					draws("중", grade, num);
					drawitem();
					drawmenu();

					gotoxy(32, 17);	printf("문제 : %s", word);
					gotoxy(70, 17);	printf("배점 : %d 점", score);
					gotoxy(32, 19);	printf("문제를 따라 치세요: ");
					timelimit = Mtime(grade);
					result = game(timelimit, input, word, scorearray[M][Q_SOLVED]);
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
			O_X[scorearray[M][Q_SOLVED] - 1] = result;			
		}
		if (gobackstart)
			break;
	}

	if (!gobackstart)
	{
		// 목숨이 있을 경우, 중학교 보스!
		if (life > 0) 
			m_boss();

		// 성적표 출력
		end_game = Scorecard(M);

		if (life && end_game)
			high(1);
	}
	

}