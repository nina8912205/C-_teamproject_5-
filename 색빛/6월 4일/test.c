#include "common.h"

#define ETEST 7

void test(int level)
{
	extern int item[], SCORE[SCHSIZE][ASIZE];
	extern int TotalScore, O_X[];
	extern char sch[SCHSIZE][SIZE], name[];

	char word[SIZE], input[SIZE];
	int key, addtime = 0, num;
	int result, x = 0;

	// 리셋
	
	resetOX();
	
	// 레이아웃
	system("cls");
	KU(2);
	KU(4);
	system("cls");
	drawline(21, 8, 75, 25);

	// 게임 스토리
	
	gotoxy(50, 19);	printf("%s! 축하한다KU!", name);
	Sleep(1500);
	gotoxy(43, 21);	printf("%s학교 교육과정을 무사히 마쳤어!", sch[level]);
	Sleep(1500);
	gotoxy(35, 23);	printf("이제 %s학교 졸업시험을 통과하면 졸업할 수 있어!", sch[level]);
	Sleep(1500);
	system("cls");

	if (item[ADDTIME]) {
		drawline(21, 8, 75, 25);
		drawitem();
		gotoxy(43, 17);	printf("[알림] 시간 증가 아이템이 있습니다.");
		Sleep(1000);
		gotoxy(50, 19);	printf("사용하시겠습니까? [y/n]");
		key = _getch();
		switch (key)
		{
		case 'y':
			gotoxy(50, 21); printf("아이템을 사용합니다.");
			Sleep(1000);
			gotoxy(48, 23); printf("제한시간이 %d초 늘어납니다.", item[ADDTIME]);
			Sleep(1000);
			while (item[ADDTIME])
			{
				item[ADDTIME]--;
				addtime++;
			}
			break;
		case 'n':
			gotoxy(48, 21);	printf("아이템을 사용하지 않습니다.");
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
		SCORE[level][T_Q_SOLVED]++;
		switch (level)
		{
		case E:
			x = 56;
			gotoxy(x, 19);
			random_word(ETEST, word);
			break;
		case M:
			x = 47;
			gotoxy(x, 19);
			word_short(word);
			break;
		case H:
			x = 31;
			gotoxy(x, 19);
			word_short_h(word);
			break;
		}
		
		// 문제 맞추기 & 결과
			
		result = game(x, input, word, T, level, addtime);

		if (result == WORDITEM)
		{
			num--;
			continue;
		}
		do {
			switch (result)
			{
			case HOWTOPLAY:
				test_layout(level, num);
				gotoxy(x, 19);	printf("%s", word);
				result = game(x, input, word, T, level, addtime);
				break;
			case CHANGE_LEVEL:
				return;
			case STARTMENU:
				game_title();
				return;
			default:
				break;
			}
		} while (result == HOWTOPLAY);

		// 정오표기록
		O_X[SCORE[level][T_Q_SOLVED]] = result;
		system("cls");
	}
}
