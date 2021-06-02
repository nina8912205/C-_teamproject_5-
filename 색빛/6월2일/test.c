#include "common.h"

#define ETEST 7

void test(int level)
{
	extern int item[3], scorearray[SCHSIZE][ASIZE], gobackstart;
	extern int TotalScore, O_X[MAX_Q];
	extern char sch[SCHSIZE][SIZE];

	char word[SIZE], input[SIZE];
	int key, addtime = 0, num;
	int result, x;

	// 리셋
	
	resetOX();
	
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
		key = _getch();
		switch (key)
		{
		case 'y':
			gotoxy(32, 19); printf("아이템을 사용합니다.");
			Sleep(1000);
			gotoxy(32, 21); printf("제한시간이 %d초 늘어납니다.", item[ADDTIME]);
			Sleep(1000);
			while (item[ADDTIME])
			{
				item[ADDTIME]--;
				addtime++;
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

		test_layout(level, num);	

		// 문제 출제
			
		switch (level)
		{
		case E:
			x = 53;
			gotoxy(x, 19);
			random_word(ETEST, word);
			break;
		case M:
			x = 47;
			gotoxy(x, 19);
			word_short(word);
			break;
		case H:
			x = 40;
			gotoxy(x, 19);
			word_short_h(word);
			break;
		}
		
		// 문제 맞추기 & 결과
			
		result = game(x, input, word, T, level, addtime);

		if (result == 5)
		{
			num--;
			continue;
		}
		while (1)
		{
			if (result == 2) // 메뉴에서 돌아왔을때
			{
				// 문제 다시 출력
				test_layout(level, num);
				gotoxy(x, 19);	printf("%s", word);
				result = game(x, input, word, T, level, addtime);
			}
			if (result == 4)
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