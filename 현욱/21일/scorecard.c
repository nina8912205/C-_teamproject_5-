//변수 리스트
//name: 이름	elementary_score: 초등학교 총점		middle_score: 중학교 총점	high_score: 고등학교 총점
//grade: 등급
//level: 게임을 플레이한 레벨 ex)초/중/고 => e/m/h ***게임 진행시 고정 필요
//time_bonus, combo_bonus
#include "common.h"

///******** 5/21 (현욱)추가
int next_step = 0;//다음 단계로 넘어갈 지 물어볼때 사용, 1 기록시 중학교, 2 기록시 고등학교로 이동, 3 기록시 ESC


//최종 종료시 성적표
void Final_Scorecard(char name[], int elementary_score, int middle_score, int high_score)
{
	int grade;
	int scoresum = elementary_score + middle_score + high_score;

	//등급 산정-추후 조정하기
	if (scoresum < 10000)
		grade = 9;
	else if (10000 <= scoresum && scoresum < 20000)
		grade = 8;
	else if (20000 <= scoresum && scoresum < 30000)
		grade = 7;
	else if (30000 <= scoresum && scoresum < 40000)
		grade = 6;
	else if (40000 <= scoresum && scoresum < 50000)
		grade = 5;
	else if (50000 <= scoresum && scoresum < 60000)
		grade = 4;
	else if (60000 <= scoresum && scoresum < 70000)
		grade = 3;
	else if (70000 <= scoresum && scoresum < 80000)
		grade = 2;
	else
		grade = 1;

	printf("                     성적표                     \n");
	printf("                                    이름:	%s  \n", name);//이름 출력
	printf("                                                \n");
	printf("             초등학교:  %d점\n\n", elementary_score);
	printf("             중학교  :  %d점\n\n", middle_score);
	printf("             고등학교:  %d점\n\n", high_score);
	printf("             총점    :  %d점\n\n", elementary_score + middle_score + high_score);
	printf("             최종 등급: %d등급", grade);

}

///****** 5/21(현욱) - 콤보 개수도 같이 출력, 성적표 출력 레이아웃 수정
////void scorecard(이름 배열, 초-e/중-m/고-h, 정답 맞춰서 얻은 점수, 시간보너스, 콤보보너스, 콤보 개수, 푼 문제 수, 정답 수)
int Scorecard(char name[], char level, int score, int time_bonus, int combo_bonus, int combo_question, int Q_solved, int Q_correct) //level: e-elementary  m-middle  h-high
{
	char ch; //입력 받기위한 임시변수
	extern int next_step;
	extern int life;
	drawline();

	drawitem();
	drawmenu();
	gotoxy(52, 12);
	switch (level)
	{
	case 'e':
		printf("초등학교 성적표 \n\n");
		break;
	case 'm':
		printf("중학교 성적표\n\n");
		break;
	case 'h':
		printf("고등학교 성적표\n\n");
		break;
	}

	gotoxy(45, 14);
	if (life != 0)
	{
		switch (level)
		{
		case 'e':
			printf("! 초등학교 졸업을 축하합니다 ! \n\n");
			break;
		case 'm':
			printf("! 중학교 졸업을 축하합니다 !\n\n");
			break;
		case 'h':
			printf("! 고등학교 졸업을 축하합니다 !\n\n");
			break;
		}

	}
	else
		printf(" --  조금 더 연습해보아요!  --");

	gotoxy(75, 16);
	printf("이름: %s\n", name);//이름 출력
	gotoxy(48, 19);
	printf("%d 문제중 %d 문제 정답", Q_solved, Q_correct);
	gotoxy(48, 21);
	printf("획득한 점수  :  %d 점", score);
	gotoxy(48, 24);
	printf("시간추가 점수:  %d 점", time_bonus);
	gotoxy(48, 27);
	printf("콤보점수     :  %d 점 (%d COMBO)", combo_bonus, combo_question);
	gotoxy(36, 28);
	printf("----------------------------------------------------");
	gotoxy(48, 30);
	printf("총점         :  %d 점", score + time_bonus + combo_bonus);
	gotoxy(48, 32);
	switch (level)
	{
		case 'e':
		{
			printf("중학교로 진행하려면 m을 눌러주세요.");
			gotoxy(48, 33);
			printf("메인 메뉴로 돌아가시려면 ESC키를 눌러주세요.");
	
			while (1)
			{
				ch = _getch();
				if (ch == 27) //ESC
				{
					next_step = 3;
					score_reset();
					break;
				}
				if (ch == 'm')
				{
					next_step = 1;
					break;
				}
			}
			break;
		}

		case 'm':
		{
			printf("고등학교로 진행하려면 h를 눌러주세요.");
			gotoxy(57, 33);
			printf("메인 메뉴로 돌아가시려면 ESC키를 눌러주세요.");

			while (1)
			{
				ch = _getch();
				if (ch == 27) //ESC
				{
					next_step = 3;
					score_reset();
					break;
				}
				if (ch == 'h')
				{
					next_step = 2;
					break;
				}
			}
			break;
		}
	}
	system("cls");
}
