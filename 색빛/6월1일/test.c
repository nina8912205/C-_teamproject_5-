#include "common.h"

#define ETEST 7

void test(int level)
{
	extern int item[3], scorearray[SCHSIZE][ASIZE], gobackstart;
	extern int time_left, TotalScore, O_X[MAX_Q];
	extern char sch[SCHSIZE][SIZE];

	char word[SIZE], input[SIZE];
	int use, num, score;
	int result, timelimit;

	// 리셋
	
	resetOX();
	timelimit = Ttime(level);
	
	// 레이아웃
	system("cls");
	drawline(21, 8, 75, 25);

	// 게임 스토리
	gotoxy(32, 15);	printf("축하합니다");
	Sleep(1000);
	gotoxy(32, 17);	printf("%s학교 교육과정을 무사히 마쳤습니다", sch[level]);
	Sleep(1000);
	gotoxy(32, 19);	printf("%s학교 교장 선생님을 이기세요", sch[level]);
	Sleep(2000);
	system("cls");

	if (item[ADDTIME]) {
		drawline(21, 8, 75, 25);
		drawitem();
		gotoxy(32, 15);	printf("시간 추가 아이템이 있습니다.");
		Sleep(1000);
		gotoxy(32, 17);	printf("사용하시겠습니까? [y/n]");
		use = _getch();
		switch (use)
		{
		case 'y':
			gotoxy(32, 19); printf("아이템을 사용합니다.");
			Sleep(1000);
			gotoxy(32, 21); printf("제한시간이 %d초 늘어납니다.", item[ADDTIME]);
			Sleep(1000);
			while (item[ADDTIME])
			{
				item[ADDTIME]--;
				timelimit++;
			}
			break;
		case 'n':
			gotoxy(32, 19);	printf("아이템을 사용하지 않습니다.");
			Sleep(1000);
			break;				
		}
	}
		// 게임 진행
	for (num = 1; num <= 5; num++)
	{
		// 목숨 검사
		if ((item[LIFE]) == 0)
			break;

		score = level * 8000;
		boss_layout(level, num, score);
		scorearray[level][B_Q_SOLVED]++;		

		// 문제 출제
			
		switch (level)
		{
		case E:
			gotoxy(50, 19);
			random_word(ETEST, word);
			break;
		case M:
			gotoxy(40, 19);
			word_short(word);
			break;
		case H:
			gotoxy(40, 19);
			word_short_h(word);
			break;
		}
		
		// 문제 맞추기 & 결과
			
		result = game(50, timelimit, input, word, scorearray[level][B_Q_SOLVED], level, 1, score);

		if (result == 5)
		{
			num--;
			continue;
		}
		while (1)
		{
			if (result == 1)
			{
				boss_correct(level, score);
				boss_time(level, TimeBonus(time_left));
				if (O_X[scorearray[level][B_Q_SOLVED] - 2] == 1)
					combo(level);
				scorearray[level][B_Q_CORRECT]++;//맞은 문제수 기록
				break;
			}
			else if (result == 2) // 메뉴에서 돌아왔을때
			{
				// 문제 다시 출력
				boss_layout(level, num, score);
				gotoxy(40, 19);	printf("%s", word);
				timelimit = Ttime(level);
				result = game(40, timelimit, input, word, scorearray[level][B_Q_SOLVED], level, 1, score);
			}
			else if (result == 4)
			{
				gobackstart = 1;
				break;
			}
			else
				break;
		}
		if (gobackstart)
			break;

		// 정오표기록
		O_X[scorearray[level][B_Q_SOLVED] - 1] = result;
		system("cls");
	}
}
