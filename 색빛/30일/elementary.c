#include "common.h"

int O_X[MAX_Q] = { 0 }; 

void elementary(int n) // elementary(0): 처음시작, elementary(1): 처음아님.
{
	extern int life, changeword, addtime, gobackstart, end_game;
	extern int time_left, scorearray[SCHSIZE][ASIZE], TotalScore;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;

	gobackstart = 0;
	time_left = 0;
	resetScore(E);
	resetOX();
	
	if (!n) {
		get_name();       // 이름 받기
		system("cls");
	}
	
	welcome(E);

	drawline(21, 8, 75, 25);     // 레이아웃 그리기

	item_random(3);    // 아이템 뽑기
	system("cls");

	for (grade = 1; grade <= 1; grade++) 
	{
		score = grade * 1000; // 학년 당 배점

		// 목숨 검사
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++) 
		{
			gotoxy(32, 24);	printf("total: %d, e_time: %d", TotalScore, scorearray[E][TIME]);
			gotoxy(32, 25);	printf("e_correct: %d, e_combo: %d", scorearray[E][CORRECT], scorearray[E][COMBO]);
			scorearray[E][Q_SOLVED]++;

			// 레이아웃
			drawline(21, 8, 75, 25);
			draws("초등", grade, num);
			drawitem();
			drawmenu();

			// 문제출력
			gotoxy(32, 17);	printf("문제 : ");

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
			gotoxy(70, 15);
			printf("[배점] %d 점", score);

			// 문제맞추기
			gotoxy(32, 19);
			printf("문제를 따라 치세요: ");
			cursor(1);
			timelimit = Etime(grade);	// 초등학교 제한시간 반환
			result = game(timelimit, input, word, scorearray[E][Q_SOLVED]);// 단어 입력 받기 & 제한 시간이 지나면 넘어가기

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
					timescore(E, TimeBonus(time_left));
					correct(E, score);
					if (O_X[scorearray[E][Q_SOLVED] - 2] == 1)
					{
						combo(E);
					}
					scorearray[E][Q_CORRECT]++;//맞은 문제수 기록
					break;
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					drawline(21, 8, 75, 25);
					draws("초등", grade, num);
					drawitem();
					drawmenu();
					gotoxy(32, 17);	printf("문제 : %s", word);
					gotoxy(70, 17);	printf("배점 : %d 점", score);
					gotoxy(32, 19);	printf("문제를 따라 치세요: ");
					timelimit = Etime(grade);
					result = game(timelimit, input, word, scorearray[E][Q_SOLVED]);
				}
				else if (result == 4)
				{
					gobackstart = 1;
					break;
				}
				else
					break;
				draws("초등", grade, num);
			}
			if (gobackstart)
				break;

			// 정오표 기록(0: 오답, 1: 정답/ 만약(result==2)라면 반복문에서 못 나옴)
			O_X[scorearray[E][Q_SOLVED] - 1] = result;
			
		}
		if (gobackstart)
			break;
	}

	if (!gobackstart) {
		// 목숨이 있을 경우, 초등학교 보스!
		if (life > 0)
			e_boss();

		end_game = Scorecard(E);

		// 다음 단계로
		if (life && end_game)
			middle(1);
	}	
}