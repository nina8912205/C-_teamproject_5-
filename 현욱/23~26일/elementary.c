//############ 색빛 - 거의 새로 만들었습니다.
#include "common.h"


///전역변수로 새로 선언해둔 변수 있습니다*******5/26 현욱
int O_X[MAX_Q] = { 0 }; //############ 색빛 - 일단 여기서 쓰이길래 선언했는데, 지역변수로 선언해도 될 거 같음.
int E_num_Q;//초등학교 푼 문제수 기록
int E_O;	//초등학교 맞은 문제수(보스제외)

void elementary(int n) // elementary(0): 처음시작, elementary(1): 처음아님.
{
	resetOX(); //게임 다시 진행할 경우를 대비해 정오표 초기화, 없어도 상관없을것 같긴 하나 콤보 계산시의 혹시모를 오류 방지****5/26 현욱
	

	extern int life, changeword, addtime;
	extern int time_left;
	char word[SIZE], input[SIZE];
	int grade, score = 0;
	int timelimit, result;
	extern int total_score,e_total_score, e_correct_score, e_time_bonus, e_combo_bonus, eboss_total_score;	////변수 호출****5/26현욱
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
			//오류확인용///*******5/26 현욱
			gotoxy(32, 24);
			printf("total: %d, e_time: %d", total_score, e_time_bonus);
			extern int m_combo_bonus;
			gotoxy(32, 25);
			printf("e_correct: %d, e_combo: %d m_combo: %d", e_correct_score, e_combo_bonus, m_combo_bonus);
			//////////////

			E_num_Q++;/////////문제 수 기록****5/26현욱
			
			// 레이아웃
			drawline();
			draws("초등", grade, num);//////draws 인수 수정
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
			//******* 5/24(현욱) - 제한시간 출력 추가, 레이아웃 야악간 수정
			gotoxy(32, 15);
			printf("배점 : %d 점 / 제한시간: %d 초", score, Etime(grade));

			// 문제맞추기
			gotoxy(32, 19);
			printf("문제를 따라 치세요: ");
			cursor(1);
			timelimit = Etime(grade);	// 초등학교 제한시간 반환
			result = game(grade, timelimit, input, word,E_num_Q);// 단어 입력 받기 & 제한 시간이 지나면 넘어가기//////************5/26현욱 - game() 함수 인수 수정

			// result 0: 오답, 1: 정답, 2: 메뉴열었음 
			while (1)
			{
				if (result == 1) //정답-점수반영방법 수정************5/26 현욱
				{	
					time_bonus(ELEMENTARY, TimeBonus(time_left));
					correct_score(ELEMENTARY, score);
					if (O_X[E_num_Q - 2] == 1)
					{	
						//test//
						/*extern int e_combo_bonus, e_total_score, total_score;
						e_combo_bonus += BonusPerCombo;
						e_total_score += BonusPerCombo;
						total_score += BonusPerCombo;*/
						combo_bonus(ELEMENTARY);
					}
					
					E_O++;//맞은 문제수 기록

					break;
				}
				else if (result == 2) // 메뉴에서 돌아왔을때
				{
					// 문제 다시 출력
					drawline();
					draws("초등", grade, num);////////****draws() 함수 인수 수정*****5/26현욱
					drawitem();
					drawmenu();
					gotoxy(32, 17);

					printf("문제 : %s", word);
					gotoxy(70, 17);
					printf("배점 : %d 점", score);

					gotoxy(32, 19);
					printf("문제를 따라 치세요: ");
					timelimit = Etime(grade);
					result = game(grade, timelimit, input, word, E_num_Q);/////////*****game()함수인수수정******5/26현욱
				}
				else
					break;
			}

			
			// 정오표 기록(0: 오답, 1: 정답/ 만약(result==2)라면 반복문에서 못 나옴)
			O_X[E_num_Q - 1] = result;
			
			
			
		}

	}

	// 목숨이 있을 경우, 초등학교 보스!
	if (life > 0)
		e_boss();
	/*************5/26현욱 - 점수 계산 위에서 모두 처리
	// 콤보 보너스 계산
	combo_bonus = ComboBonus(Combo_num(--num_Q));

	// 시간 보너스 계산
	time_bonus = TimeBonus(time_left);*/

	// 성적표 출력******인수 수정(5/26현욱)
	go = Scorecard(ELEMENTARY);

	// 다음 단계로
	if (go)
		middle(1);
}