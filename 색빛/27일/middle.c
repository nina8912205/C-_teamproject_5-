/* (5/26)
   - word 속 문자열의 크기를 인식하고, 그만큼 입력받도록 수정
*/
#include "common.h"
#define MSIZE 7

int M_num_Q;
int M_O;

void middle(int n) // middle(0): 처음시작, middle(1): 처음아님.
{
	
	extern int O_X[], m_score[], TotalScore;
	extern int life, changeword, addtime;
	extern int time_left;

	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result, size;
	int go;

	time_left = 0;  // 남은시간 초기화
	resetOX();

	if (!n)
	{
		get_name(MIDDLE);
		system("cls");
	}

	drawline(21, 8, 75, 25);       // 레이아웃 그리기

	item_random(2);    // 아이템 뽑기
	system("cls");

	for (grade = 1; grade <= 3; grade++)
	{
		score = grade * 3000; // 학년 당 배점

		// 목숨 검사
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++)
		{
			gotoxy(32, 24);
			printf("total: %d, e_time: %d", TotalScore, m_score[TIME]);
			gotoxy(32, 25);
			printf("m_correct: %d, m_combo: %d", m_score[CORRECT], m_score[COMBO]);
			M_num_Q++;
			// 레이아웃
			drawline(21, 8, 75, 25);
			draws("중", grade, num);
			drawitem();
			drawmenu();

			// 문제출력
			gotoxy(32, 17);
			printf("문제 : ");

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
			gotoxy(70, 17);
			printf("배점 : %d 점", score);

			// 문제맞추기
			gotoxy(32, 19);
			printf("문제를 따라 치세요: ");
			cursor(1);
			size = strlen(word);
			timelimit = Mtime(grade);
			result = game(size, timelimit, input, word, M_num_Q);

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
					timescore(MIDDLE, TimeBonus(time_left));
					correct(MIDDLE, score);
					if (O_X[M_num_Q - 2] == 1)
						combo(MIDDLE);
					M_O++;
					break;
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					drawline(21, 8, 75, 25);
					draws("중", grade, num);
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("문제 : %s", word);
					gotoxy(70, 17);
					printf("배점 : %d 점", score);

					gotoxy(32, 19);
					printf("문제를 따라 치세요: ");
					timelimit = Mtime(grade);
					result = game(size, timelimit, input, word, M_num_Q);
				}
				else
					break;
			}

			// 정오표 기록
			O_X[M_num_Q - 1] = result;
			
		}
	}

	// 목숨이 있을 경우, 중학교 보스!
	/*if (life > 0)
		m_boss();*/

	// 성적표 출력
	go = Scorecard(HIGH);

}