#include "common.h"
#define MSIZE 7

void middle(int n) // middle(0): 처음시작, middle(1): 처음아님.
{
	extern int O_X[], scorearray[SCHSIZE][ASIZE], TotalScore;
	extern int item[3];
	extern int time_left, gobackstart, end_game, changelevel;

	char word[SIZE], input[SIZE];
	int grade, score = 0, x = 0;
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

	for (grade = 1; grade <= 3; grade++)
	{
		score = grade * 3000; // 학년 당 배점

		for (int num = 1; num <= 3; num++)
		{
			if ((item[LIFE]) == 0)
				break;

			/*gotoxy(32, 24); printf("total: %d, e_time: %d", TotalScore, scorearray[M][TIME]);
			gotoxy(32, 25); printf("m_correct: %d, m_combo: %d", scorearray[M][CORRECT], scorearray[M][COMBO]);*/
			scorearray[M][Q_SOLVED]++;

			// 레이아웃
			layout(M, grade, num, score);

			// 문제출력
			timelimit = Mtime(grade);

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

			result = game(x, timelimit, input, word, scorearray[M][Q_SOLVED], M, 0, score);


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
					break;  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	지움
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					layout(M, grade, num, score);
					gotoxy(40, 19);	printf("문제 : %s", word);
					timelimit = Mtime(grade);
					result = game(40, timelimit, input, word, scorearray[M][Q_SOLVED], M, 0, score);
				}
				else if (result == 4) {
					gobackstart = 1;
					break;
				}
				else if (result == 3)   // %%%%%%%%%%%%%%%%%%%%%%%%%%%5
				{
					changelevel = 1;
					break;
				}
				else
					break;
			}
			if (gobackstart)
				break;
			if (changelevel == 1)   // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				break;


			// 정오표 기록
			O_X[scorearray[M][Q_SOLVED] - 1] = result;
		}
		if (gobackstart)
			break;
		if (changelevel == 1)  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
			break;

		gradeup();
	}

	if (changelevel == 1)  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		return;

	if (!gobackstart)
	{
		// 목숨이 있을 경우, 중학교 보스!
		if (item[LIFE])
			test(M);

		// 성적표 출력
		end_game = Scorecard(M);

		if (item[LIFE] && end_game)
			high(1);
	}


}
