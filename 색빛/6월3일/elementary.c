#include "common.h"

int O_X[MAX_Q] = { 0 }; 
char sch[SCHSIZE][SIZE] = { "초등","중","고등" };

void elementary(int n)
{
	extern int item[3], end_game;
	extern int SCORE[SCHSIZE][ASIZE];

	char word[SIZE], input[SIZE];
	int grade;
	int result;

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
		for (int num = 1; num <= 2; num++) 
		{
			if (item[LIFE] == 0)
				break;
		
			// 레이아웃						
			layout(E, grade, num);
			
			// 문제출력
			gotoxy(61 - grade, 19);
			
			switch (grade) // 학년별 문제 출력
			{
			case 1:
			case 2:
				random_word(grade, word); // 1~2학년: 랜덤 문자열
				break;
			case 3:
				if (rand() % 2)
					word_3(word);
				else
					random_word(grade, word); // 3학년: 3글자 단어 or 랜덤 문자열
				break;
			case 4:
				if (rand() % 2)
					word_4(word);
				else
					random_word(grade, word); // 4학년: 4글자 단어 or 랜덤 문자열
				break;
			case 5:
				if (rand() % 2)
					word_5(word);
				else
					random_word(grade, word); // 5학년: 5글자 단어 or 랜덤 문자열
				break;
			case 6:
				if (rand() % 2)
					word_6(word);
				else
					random_word(grade, word); // 6학년: 6글자 단어 or 랜덤 문자열
				break;
			}
			
			// 문제맞추기
			result = game(61 - grade, input, word, E, grade, 0);

			// 단어 바꾸기 실행
			if (result == WORDITEM)
			{
				num--;
				continue;
			}

			while (1)
			{
				if (result == HOWTOPLAY) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					layout(E, grade, num);
					gotoxy(61 - grade, 19);	printf("%s", word);
					result = game(61 - grade, input, word, E, grade, 0);
				}
				if (result == STARTMENU || result == CHANGE_LEVEL)
					return;
				else
					break;
			}

			// 정오표 기록
			O_X[SCORE[E][Q_SOLVED] - 1] = result;
		}

		if (item[LIFE] && grade < 6)
			gradeup();
	}
	
	// 목숨이 있을 경우, 초등학교 보스!
	if (item[LIFE])
		test(E);

	end_game = Scorecard(E);

	// 다음 단계로
	if (item[LIFE] && end_game)
		middle(1);
		
}