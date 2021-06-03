#include "common.h"

int O_X[MAX_Q] = { 0 };
char sch[SCHSIZE][SIZE] = { "초등","중","고등" };
int changelevel = 0;            // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  => 메뉴에서 난이도 변경시 수행중인 함수 탈출 위한 변수

void elementary(int n)
{
	extern int item[3], gobackstart, end_game;
	extern int time_left, scorearray[SCHSIZE][ASIZE], TotalScore;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;

	gobackstart = 0;
	time_left = 0;
	resetScore(E);
	resetOX();

	if (!n) {
		get_name();
		system("cls");
	}

	welcome(E);

	drawline(21, 8, 75, 25);

	item_random(3);

	for (grade = 1; grade <= 6; grade++)
	{
		score = grade * 1000;

		for (int num = 1; num <= 2; num++)
		{

			if ((item[LIFE]) == 0)
				break;

			/*gotoxy(32, 24);	printf("total: %d, e_time: %d", TotalScore, scorearray[E][TIME]);
			gotoxy(32, 25);	printf("e_correct: %d, e_combo: %d", scorearray[E][CORRECT], scorearray[E][COMBO]);*/
			scorearray[E][Q_SOLVED]++;

			// 레이아웃						
			layout(E, grade, num, score);

			// 문제출력
			gotoxy(61 - grade, 19);

			switch (grade) // 학년별 문제 출력
			{
			case 1:
			case 2:
				random_word(grade, word); // 1~2학년: 랜덤 문자열
				break;
			case 3:
				if (rand() % 2 == 0)
					word_3(word);
				else
					random_word(grade, word); // 3학년: 3글자 단어 or 랜덤 문자열
				break;
			case 4:
				if (rand() % 2 == 0)
					word_4(word);
				else
					random_word(grade, word); // 4학년: 4글자 단어 or 랜덤 문자열
				break;
			case 5:
				if (rand() % 2 == 0)
					word_5(word);
				else
					random_word(grade, word); // 5학년: 5글자 단어 or 랜덤 문자열
				break;
			case 6:
				if (rand() % 2 == 0)
					word_6(word);
				else
					random_word(grade, word); // 6학년: 6글자 단어 or 랜덤 문자열
				break;
			}

			// 문제맞추기
			timelimit = Etime(grade);	// 초등학교 제한시간 반환
			result = game(61 - grade, timelimit, input, word, scorearray[E][Q_SOLVED], E, 0, score);

			// 단어 바꾸기 실행
			if (result == 5)
			{
				num--;
				continue;
			}

			while (1)
			{
				if (result == 1)
				{
					break;  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	지움
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					layout(E, grade, num, score);
					gotoxy(61 - grade, 19);	printf("%s", word);
					timelimit = Etime(grade);
					result = game(61 - grade, timelimit, input, word, scorearray[E][Q_SOLVED], E, 0, score);
				}
				else if (result == 4)
				{
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
			O_X[scorearray[E][Q_SOLVED] - 1] = result;


		}
		if (gobackstart)
			break;
		if (changelevel == 1)  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
			break;

		if (item[LIFE] && grade < 6)
			gradeup();
	}

	if (changelevel == 1)  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		return;

	if (!gobackstart) {
		// 목숨이 있을 경우, 초등학교 보스!
		if (item[LIFE])
			test(E);

		end_game = Scorecard(E);

		// 다음 단계로
		if (item[LIFE] && end_game)
			middle(1);
	}
}
