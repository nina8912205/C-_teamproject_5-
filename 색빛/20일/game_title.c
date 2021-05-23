/* game_title : 게임 시작화면 출력함수*/
#include "common.h"

void game_title()
{
	//############ 색빛 - 사용되지 않은 변수(ch)가 선언되어 있어 삭제
	int key;                               

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

	if (key = _getch())           //############ 색빛 - 더 간단하게 코드 작성
		system("cls");            // 키 입력 -> 화면 지우기
}
