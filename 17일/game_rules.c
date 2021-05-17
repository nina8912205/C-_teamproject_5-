/* game_rules : 게임 방법 출력 */
#include "common.h"

void game_rules()
{
	int ch;
	system("cls");
	drawline();
	rule_title();   // 게임방법 제목란 출력

	/* 게임방법 - 1단계 */
	do {
		printf("\t\t\t    1. 난이도를 선택하자!\n\n");
		printf("\t\t\t     - 초등학교(1~6학년) → 중학교 → 고등학교\n\n");
		printf("\t\t\t     - 중학교(1~3학년) → 고등학교\n\n");
		printf("\t\t\t     - 고등학교(1~3학년)\n\n\n");
		printf("\t\t\t    ★ 게임 중간에 난이도 변경 가능 (단, 점수 초기화)\n\n ");
		printf("\t\t\t    ★ 난이도 변경 시 특정 학년(ex. 중학교 2학년)으로 이동 불가\n\n");
		printf("\t\t\t    ★ 상급 학년, 학교에 진학할수록 난이도 상승\n\n");
		gotoxy(71, 33);
		printf("아무키나 누르면 다음으로 >");
		ch = _getch();
	} while (!ch);

	system("cls");
	drawline();
	rule_title();

	/* 게임방법 - 2단계 */
	do {
		printf("\t\t\t    2. 즐거운 학교 생활을 하자!\n\n");
		printf("\t\t\t     - 제시된 단어/랜덤 문자열을 빠르고 정확하게 입력하자!\n\n");
		printf("\t\t\t     - 틀리거나 시간 내에 입력하지 않으면 목숨이 한 개 줄어든다\n\n");
		printf("\t\t\t     - 정/오답에 상관없이 일정 횟수를 넘기면 다음 학년으로 진학한다\n\n\n");
		printf("\t\t\t    ★ 연속으로 단어를 맞추면 BONUS 점수 획득!\n\n ");
		printf("\t\t\t    ★ 빠르고 정확하게 입력할수록 높은 점수 획득!\n\n");
		printf("\t\t\t    ★ 높은 성적(점수)을 받아 마지막에 좋은 등급을 받자!\n\n");

		gotoxy(71, 33);
		printf("아무키나 누르면 다음으로 >");
		ch = _getch();
	} while (!ch);

	system("cls");
	drawline();
	rule_title();

	/* 게임방법 - 3단계 */
	do {
		printf("\t\t\t    3. 학교를 졸업하자!\n\n");
		printf("\t\t\t     - 초6, 중3을 마치면 졸업을 위해 교장선생님의 승인이 필요하다\n\n");
		printf("\t\t\t     - 졸업장을 얻기 위해 교장선생님이 제시하는 문자열을 입력하자!\n\n");
		printf("\t\t\t     - 성공 시 성적표를 받고, 다음학교로 진학할 수 있다\n\n");
		printf("\t\t\t     - 실패 시 일정 점수를 깎고 재도전이 가능하다\n\n\n");
		printf("\t\t\t    ★ 빠르게 입력하지 않으면, 점수가 계속 깎이니 주의하자!\n\n ");
		printf("\t\t\t    ★ 고등학교 3학년을 마치면 수능이 기다린다!\n\n ");
		printf("\t\t\t    ★ 새 학교에 진학하면, 목숨과 아이템이 초기화된다!\n\n");
		gotoxy(71, 33);
		printf("아무키나 누르면 다음으로 >");
		ch = _getch();
	} while (!ch);

	system("cls");
	drawline();
	rule_title();

	/* 게임방법 - 4단계 */
	do {
		printf("\t\t\t    4. 아이템을 사용하자!\n\n");
		printf("\t\t\t     - 아이템은 새 학교에 입학할 때 랜덤으로 얻을 수 있다!\n\n");
		printf("\t\t\t       ( 초등학교: 3개 / 중학교: 2개 / 고등학교: 2개 )\n\n\n");
		printf("\t\t\t    │ 아이템 종류│ \n\n");
		printf("\t\t\t     - 목숨 증가: 목숨이 1개 증가한다 (자동 사용) \n\n");
		printf("\t\t\t     - 단어 바꾸기: 다른 단어로 바뀐다 (보스 게임에서 사용 불가)\n\n");
		printf("\t\t\t     - 시간 증가: 전체 시간이 2초 증가한다 (보스 게임에서만 사용 가능)\n\n\n\n");
		gotoxy(71, 33);
		printf("아무키나 누르면 다음으로 >");
		ch = _getch();
	} while (!ch);

	system("cls");
	drawline();
	rule_title();

	/* 게임방법 - 5단계 */
	printf("\t\t\t    5. 메뉴를 불러오자!\n\n");
	printf("\t\t\t      │ 메뉴 이용│ : M 입력 → 원하는 실행 키 입력 \n\n");
	printf("\t\t\t       -  M : 게임 메뉴 기능을 실행한다\n\n");
	printf("\t\t\t       -  P : 게임을 일시정지한다 \n\n");
	printf("\t\t\t       -  R : 게임 방법을 불러온다\n\n");
	printf("\t\t\t       -  L : 게임 난이도를 변경한다\n\n");
	printf("\t\t\t       -  S : 시작 화면으로 돌아간다\n\n");
	printf("\t\t\t       -  Q : 게임을 종료한다\n\n");
	gotoxy(78, 33);
	printf("게임 방법 나가기 >");
	ch = _getch();
	if (ch)
		system("cls");
}

/* 게임방법 제목란 출력 */
void rule_title()
{
	gotoxy(54, 10);
	printf("< 게 임 방 법 >\n\n");
	gotoxy(28, 13);
	printf("[ MISSION: 빠르고 정확하게 타자를 쳐서 모든 학교를 졸업하라 KU! ]\n\n\n");
}