/* game_title : 게임 시작화면 출력함수*/
#include "common.h"

void game_title()
{
	int ch;
	int key;                               // 게임 시작 버튼

	gotoxy(0, 3);
	printf("\t\t            ■■                      ■■\n");
	printf("\t\t            ■  ■    ■■■■■    ■  ■                 ■■■■■    ■    ■\n");
	printf("\t\t            ■    ■■          ■■    ■                     ■      ■  ■  ■\n");
	printf("\t\t            ■  ■■              ■■  ■                 ■■  ■■  ■  ■■■\n");
	printf("\t\t        ■■■■        ■    ■      ■■■■                 ■      ■  ■  ■\n");
	printf("\t\t    ■■  ■            ■    ■          ■  ■■         ■■■■■    ■    ■\n");
	printf("\t\t  ■      ■      ■      ■  ■  ■      ■      ■                   ■      ■ \n");
	printf("\t\t■      ■      ■          ■      ■      ■      ■     ■■■■■  ■      ■\n");
	printf("\t\t■      ■                                  ■      ■             ■  ■■■■■\n");
	printf("\t\t  ■■■            ■            ■          ■■■       ■■■■■  ■      ■\n");
	printf("\t\t      ■          ■■          ■■          ■           ■          ■      ■\n");
	printf("\t\t      ■          ■■          ■■          ■           ■■■■■  ■■■■■\n");
	printf("\t\t    ■                  ■  ■                  ■           \n");
	printf("\t\t    ■            ■■■■■■■■■            ■           ■    ■  ■■■  ■\n");
	printf("\t\t    ■        ■■■              ■■■        ■         ■■■  ■      ■  ■\n");
	printf("\t\t    ■    ■■        ■      ■        ■■    ■                 ■      ■  ■\n");
	printf("\t\t    ■    ■            ■■■            ■    ■           ■    ■      ■  ■\n");
	printf("\t\t      ■■                                  ■■           ■  ■  ■  ■■■  ■\n");
	printf("\t\t      ■                                      ■           ■  ■  ■■■      ■■\n");
	printf("\t\t      ■                                      ■           ■  ■  ■  ■      ■\n");
	printf("\t\t        ■                                  ■■■■       ■  ■  ■  ■      ■\n");
	printf("\t\t        ■                                  ■      ■     ■  ■  ■  ■      ■\n");
	printf("\t\t        ■■                              ■        ■       ■    ■  ■■■  ■\n");
	printf("\t\t          ■■                          ■          ■\n");
	printf("\t\t              ■■                  ■■          ■       ■      ■  ■      ■\n");
	printf("\t\t              ■■■■■■■■■■■■          ■         ■      ■  ■      ■\n");
	printf("\t\t            ■  ■                  ■        ■           ■    ■    ■      ■\n");
	printf("\t\t          ■    ■       K  U       ■      ■             ■  ■      ■      ■\n");
	printf("\t\t        ■    ■  ■■          ■■  ■  ■               ■■        ■      ■\n");
	printf("\t\t      ■      ■      ■      ■      ■■                 ■  ■      ■      ■\n");
	printf("\t\t    ■      ■          ■  ■          ■                 ■    ■    ■      ■\n");
	printf("\t\t  ■        ■            ■            ■                 ■      ■  ■      ■\n");
	printf("\t\t  ■        ■                          ■                 ■      ■  ■■■■■\n");
	printf("\t\t  ■      ■■                          ■\n");
	printf("\t\t    ■■■  ■                          ■               < PRESS ANY KEY TO START >\n");
	printf("\n\n");
	printf("\t\t\t\t\t(0451 5팀) 김현욱 노민영 오색빛 정예원\n\n");

	key = _getch();

	if (key)
		system("cls");            // 키 입력 -> 화면 지우기
}