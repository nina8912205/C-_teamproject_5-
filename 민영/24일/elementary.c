//############ 색빛 - 거의 새로 만들었습니다.
#include "common.h"

int e_total_score = 0; //############ 색빛 -  너무 길어서 변수 이름 바꿈 && score에서 옮겨왔음.

int O_X[MAX_Q] = { 0 }; //############ 색빛 - 일단 여기서 쓰이길래 선언했는데, 지역변수로 선언해도 될 거 같음.

void elementary(int n) // elementary(0): 처음시작, elementary(1): 처음아님.
{
	extern int life, changeword, addtime;
	extern int time_left;

	char word[SIZE], input[SIZE];
	int grade, score = 0, num_Q = 1;
	int timelimit, result;
	int O = 0;      //############ 색빛 - 현욱님(5/22)거 보고 변수 이름만 수정했습니다.
	int e_score = 0, time_bonus = 0;  // e_score: 기본 점수
	int combo_bonus = 0, boss_score = 0; // 성적표에 기록
	int go; // 다음 단계로

	if (!n)
	{
		drawline();
		get_name();       // 이름 받기
		system("cls");
	}


	drawline();       // 레이아웃 그리기

	item_random(3);    // 아이템 뽑기
	system("cls");


	for (grade = 1; grade <= 6; grade++) //############ 색빛 - 학년 변수 수정 (i -> grade)
	{
		score = grade * 1000; // 학년 당 배점

		// 목숨 검사
		if (life == 0)
			break;

		for (int num = 1; num <= 1; num++) //############ 색빛 - 문제 번호 변수 수정 (j -> num)
		{
			// 레이아웃
			drawline();
			draws("초등", grade, num, e_total_score);
			drawitem();
			drawmenu();

			// 문제출력
			gotoxy(32, 17);
			printf("문제 : ");

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
			gotoxy(70, 17);
			printf("배점 : %d 점", score);

			// 문제맞추기
			gotoxy(32, 19);
			printf("문제를 따라 치세요: ");
			cursor(1);
			timelimit = Etime(grade);	// 초등학교 제한시간 반환
			result = game(grade, timelimit, input, word);// 단어 입력 받기 & 제한 시간이 지나면 넘어가기

			// result 0: 오답, 1: 정답, 2: 메뉴열었음 
			while (1)
			{
				if (result == 1)
				{
					e_score += score;
					O++;
					break;
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					drawline();
					draws("초등", grade, num, e_score);
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("문제 : %s", word);
					gotoxy(70, 17);
					printf("배점 : %d 점", score);

					gotoxy(32, 19);
					printf("문제를 따라 치세요: ");
					timelimit = Etime(grade);
					result = game(grade, timelimit, input, word);
				}
				else
					break;
			}

			// 정오표 기록(0: 오답, 1: 정답/ 만약(result==2)라면 반복문에서 못 나옴)
			O_X[num_Q - 1] = result;
			num_Q++;

			// 시간 보너스 계산
			time_bonus = TimeBonus(time_left);

			e_total_score = time_bonus + e_score; //############ 색빛 - 상단바 점수를 위해 계산
		}

	}

	// 목숨이 있을 경우, 초등학교 보스!
	if (life > 0)
		boss_score = e_boss(e_score);

	// 콤보 보너스 계산
	combo_bonus = ComboBonus(Combo_num(--num_Q));

	// 시간 보너스 계산
	time_bonus = TimeBonus(time_left);

	// 성적표 출력
	go = Scorecard(ELEMENTARY, e_score, time_bonus, combo_bonus, boss_score, num_Q, O);
	e_total_score = e_score + combo_bonus + time_bonus + boss_score; //############ 색빛 - 최종 성적표를 위해 계산

	// 다음 단계로
	if (go)
		middle(1);
}