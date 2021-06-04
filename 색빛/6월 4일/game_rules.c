/* game_rules : 게임 방법 출력 */
#include "common.h"

void game_rules(int i) //i=0이면 게임 시작전, i=1이면 게임 도중
{
	int page = 1, key;
	cursor(0);
	system("cls");
	drawline(21, 8, 75, 25);
	rule_title();

	while (1 <= page && page <= 5)
	{
		clear(23, 16, 37, 18);
		switch (page)
		{
		case 1:	PAGE1(); break;
		case 2:	PAGE2(); break;
		case 3:	PAGE3(); break;
		case 4:	PAGE4(); break;
		case 5:	PAGE5(); break;
		}

		if (page > 1)
		{
			gotoxy(23, 33);
			printf("< %d", page - 1);
		}
		else
		{
			gotoxy(23, 33);
			if(i)
				printf("< 게임으로");
			else
				printf("< 게임 시작 메뉴");			
		}

		if (page < 5)
		{
			gotoxy(94, 33);
			printf("%d >", page + 1);
		}
		else
		{
			if (i)
			{
				gotoxy(85, 33); 
				printf(" 게임으로  >");
			}				
			else
			{
				gotoxy(80, 33); 
				printf(" 게임 시작 메뉴 >");
			}
				
		}

		key = _getch();
		if (key == 224)
		{
			key = _getch();
			switch (key)
			{
			case LEFT:
				page--;
				break;
			case RIGHT:
				page++;
				break;
			}
		}
	}
}

void rule_title()
{
	gotoxy(54, 10);
	printf("< 게 임 방 법 >\n\n");
	gotoxy(28, 13);
	printf("[ MISSION: 빠르고 정확하게 타자를 쳐서 모든 학교를 졸업하라 KU! ]");
}

void PAGE1()
{
	gotoxy(0, 16);
	printf("\t\t\t    1. 난이도를 선택하자!\n\n");
	printf("\t\t\t     - 초등학교(1~6학년) → 중학교 → 고등학교\n\n");
	printf("\t\t\t     - 중학교(1~3학년) → 고등학교\n\n");
	printf("\t\t\t     - 고등학교(1~3학년)\n\n\n");
	printf("\t\t\t    ★ 게임 중간에 난이도 변경 가능 (단, 점수 초기화)\n\n ");
	printf("\t\t\t    ★ 난이도 변경 시 특정 학년(ex. 중학교 2학년)으로 이동 불가\n\n");
	printf("\t\t\t    ★ 상급 학년, 학교에 진학할수록 난이도 상승\n\n");
}

void PAGE2()
{
	gotoxy(0, 16);
	printf("\t\t\t    2. 즐거운 학교 생활을 하자!\n\n");
	printf("\t\t\t     - 제시된 단어/랜덤 문자열을 빠르고 정확하게 입력하자!\n\n");
	printf("\t\t\t     - 틀리거나 시간 내에 입력하지 않으면 목숨이 한 개 줄어든다\n\n");
	printf("\t\t\t     - 정/오답에 상관없이 일정 횟수를 넘기면 다음 학년으로 진학한다\n\n\n");
	printf("\t\t\t    ★ 연속으로 단어를 맞추면 BONUS 점수 획득!\n\n ");
	printf("\t\t\t    ★ 빠르고 정확하게 입력할수록 높은 점수 획득!\n\n");
	printf("\t\t\t    ★ 높은 성적(점수)을 받아 마지막에 좋은 등급을 받자!\n\n");
}

void PAGE3()
{
	gotoxy(0, 16);
	printf("\t\t\t    3. 학교를 졸업하자!\n\n");
	printf("\t\t\t     - 각 학교의 최고 학년을 마치면 졸업시험을 치러야 한다\n\n");
	printf("\t\t\t     - 졸업시험은 5문제로 구성되어 있다\n\n");
	printf("\t\t\t     - 성공 시 성적표를 받고, 다음학교로 진학할 수 있다\n\n\n");
	printf("\t\t\t    ★ 새 학교에 진학하면, 목숨과 아이템이 초기화된다!\n\n ");
}

void PAGE4()
{
	gotoxy(0, 16);
	printf("\t\t\t    4. 아이템을 사용하자!\n\n");
	printf("\t\t\t     - 아이템은 새 학교에 입학할 때 랜덤으로 얻을 수 있다!\n\n");
	printf("\t\t\t       ( 초등학교: 3개 / 중학교: 2개 / 고등학교: 2개 )\n\n\n");
	printf("\t\t\t    │ 아이템 종류│ \n\n");
	printf("\t\t\t     - 목숨 증가: 목숨이 1개 증가한다 (자동 사용) \n\n");
	printf("\t\t\t     - 단어 바꾸기: 다른 단어로 바뀐다\n\n");
	printf("\t\t\t     - 시간 증가: 제한 시간이 1초 증가한다 (보스 게임에서만 사용 가능)\n\n\n\n");
}

void PAGE5()
{
	gotoxy(0, 16);
	printf("\t\t\t    5. 메뉴를 불러오자!\n\n");
	printf("\t\t\t      │ 메뉴 이용│ : ESC키 누르기 → 기능 실행 키 입력\n\n\n");
	printf("\t\t\t       -  ESC키 : 게임 메뉴 기능을 실행한다\n\n");
	printf("\t\t\t       -      R : 게임 방법을 불러온다\n\n");
	printf("\t\t\t       -      L : 게임 난이도를 변경한다\n\n");
	printf("\t\t\t       -      S : 시작 화면으로 돌아간다\n\n");
	printf("\t\t\t       -      Q : 게임을 종료한다\n\n");
}

