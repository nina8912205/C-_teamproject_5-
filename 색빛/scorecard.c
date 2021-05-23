//############ 색빛 - 현욱님(21일)이 올리신거 좀 수정했습니다.
#include "common.h"

//최종 종료시 성적표
////############ 색빛 - 이름을 전역변수로 바꿔서 인수 필요X, 인수 이름 너무 길어서 수정
void Final_Scorecard(int elementary, int middle, int high)
{
	extern char name[]; //############ 색빛 - 이름(전역변수)
	int grade;
	int scoresum = elementary + middle + high; ////############ 색빛 - scoresum보단 total_score가 더 좋을거같습니다.

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
	printf("             초등학교:  %d점\n\n", elementary);
	printf("             중학교  :  %d점\n\n", middle);
	printf("             고등학교:  %d점\n\n", high);
	printf("             총점    :  %d점\n\n", elementary + middle + high);
	printf("             최종 등급: %d등급", grade);

}

/*############ 색빛
 - 이름은 전역변수로 선언했기 때문에 뺐음.
 - 콤보 점수를 통해서 콤보 개수를 알 수 있기 때문에 콤보 개수를 인수에서 뺌.
 - char level -> int level (이미 기호상수로 선언된게 있어서 그거 쓰려고 바꿈)
 - 보스 점수 추가
 - 다음 단계로 넘어가는 알고리즘이 충돌한 것 같음.(제가 현욱님 game_start.c를 주석 달때봐서..)
 - 좀 더 간단하게 코드 수정. && 성적표 레이아웃 수정
 - 쿠 얼굴 추가
*/
int Scorecard(int level, int score, int time, int combo, int boss, int Q_solved, int Q_correct)
{
	extern char name[];
	extern int life;
	char ch, school[10], next[10];
	int go;

	drawline();
	drawitem();
	drawmenu();

	switch (level)
	{
	case ELEMENTARY:
		strcpy(school, "초등");
		strcpy(next, "중");
		break;
	case MIDDLE:
		strcpy(school, "중");
		strcpy(next, "고등");
		break;
	case HIGH:
		strcpy(school, "고등");
		break;
	}

	if (life)
	{
		happyKU();
		drawline();
		gotoxy(45, 12);
		printf("! %s학교 졸업을 축하합니다 ! \n\n", school);
	}
	else 
	{
		sadKU();
		drawline();
		gotoxy(45, 12);
		printf(" --  조금 더 연습해보아요!  --");
	}
		

	gotoxy(75, 14);
	printf("이름: %s\n", name);//이름 출력
	gotoxy(48, 16);
	printf("%d 문제중 %d 문제 정답!", Q_solved, Q_correct);
	gotoxy(48, 18);
	printf("획득한 점수  :  %5d 점", score);
	gotoxy(48, 20);
	printf("시간추가 점수:  %5d 점", time);
	gotoxy(48, 22);
	printf("콤보점수     :  %5d 점 (%d COMBO)", combo, combo/BonusPerCombo);
	gotoxy(48, 24);
	printf("보스점수     :  %5d 점", boss);
	gotoxy(34, 26);
	printf("----------------------------------------------------");
	gotoxy(48, 28);
	printf("총점         :  %5d 점", score + time + combo + boss);
	
	gotoxy(25, 31);
	if (level != HIGH && life != 0)
		printf("[ %s학교로 진행하려면 g, 메인 메뉴로 돌아가시려면 ESC키를 눌러주세요.]", next);
	else
		printf("[ 메인 메뉴로 돌아가시려면 ESC키를 눌러주세요.]");
	
	while (1)
	{
		ch = _getch();
		if (ch == ESC)
		{
			go = 0;
			//score_reset();
			break;
		}
		if (ch == 'g')
		{
			go = 1;
			break;
		}
	}
	system("cls");
	return go;
}

void sadKU()
{
	system("cls");
	gotoxy(0, 9);
	printf("\t\t\t\t            ■■                      ■■\n");
	printf("\t\t\t\t            ■  ■    ■■■■■    ■  ■\n");
	printf("\t\t\t\t            ■    ■■          ■■    ■\n");
	printf("\t\t\t\t            ■  ■■              ■■  ■\n");
	printf("\t\t\t\t        ■■■■        ■    ■      ■■■■\n");
	printf("\t\t\t\t    ■■  ■            ■    ■          ■  ■■\n");
	printf("\t\t\t\t  ■      ■      ■      ■  ■  ■      ■      ■\n");
	printf("\t\t\t\t■      ■      ■          ■      ■      ■      ■\n");
	printf("\t\t\t\t■      ■                                  ■      ■\n");
	printf("\t\t\t\t  ■■■                                      ■■■\n");
	printf("\t\t\t\t      ■      ■■■■■      ■■■■■      ■\n");
	printf("\t\t\t\t      ■        ■  ■          ■  ■        ■\n");
	printf("\t\t\t\t    ■                  ■  ■                  ■\n");
	printf("\t\t\t\t    ■            ■■■■■■■■■            ■\n");
	printf("\t\t\t\t    ■        ■■■              ■■■        ■\n");
	printf("\t\t\t\t    ■    ■■          ■■■          ■■    ■\n");
	printf("\t\t\t\t    ■  ■            ■      ■            ■  ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t        ■                                  ■\n");
	printf("\t\t\t\t        ■■                              ■■\n");
	printf("\t\t\t\t            ■■                      ■■\n");                                
	printf("\t\t\t\t              ■■                  ■■\n");
	printf("\t\t\t\t                  ■■■■■■■■■\n");
	Sleep(2000);
	system("cls");
}

void happyKU()
{
	system("cls");
	gotoxy(0, 9);
	printf("\t\t\t\t            ■■                      ■■\n");
	printf("\t\t\t\t            ■  ■    ■■■■■    ■  ■\n");
	printf("\t\t\t\t            ■    ■■          ■■    ■\n");
	printf("\t\t\t\t            ■  ■■              ■■  ■\n");
	printf("\t\t\t\t        ■■■■        ■    ■      ■■■■\n");
	printf("\t\t\t\t    ■■  ■            ■    ■          ■  ■■\n");
	printf("\t\t\t\t  ■      ■      ■      ■  ■  ■      ■      ■\n");
	printf("\t\t\t\t■      ■      ■          ■      ■      ■      ■\n");
	printf("\t\t\t\t■      ■                                  ■      ■\n");
	printf("\t\t\t\t  ■■■          ■              ■            ■■■\n");
	printf("\t\t\t\t      ■        ■  ■          ■  ■        ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t    ■                  ■  ■                  ■\n");
	printf("\t\t\t\t    ■            ■■■■■■■■■            ■\n");
	printf("\t\t\t\t    ■        ■■■              ■■■        ■\n");
	printf("\t\t\t\t    ■    ■■        ■      ■        ■■    ■\n");
	printf("\t\t\t\t    ■  ■              ■■■              ■  ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t      ■                                      ■\n");
	printf("\t\t\t\t        ■                                  ■\n");
	printf("\t\t\t\t        ■■                              ■■\n");
	printf("\t\t\t\t            ■■                      ■■\n");
	printf("\t\t\t\t              ■■                  ■■\n");
	printf("\t\t\t\t                  ■■■■■■■■■\n");
	Sleep(2000);
	system("cls");
}