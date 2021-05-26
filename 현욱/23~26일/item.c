/* item : 아이템 뽑기 */
#include "common.h"

int life = LIFE, changeword = 0, addtime = 0; //############ 색빛 - 기호 상수 사용

void item_random(int n) //############ 색빛 - 몇 번 뽑을 지 인수 추가

{
	life = LIFE, changeword = 0, addtime = 0; //**** 5/24(현욱) - 게임 재진행/다음 학교로 넘어갈 때 목숨 아이템 음수값 나오는거 방지위해 life=LIFE 추가

	int i, p;
	system("cls");
	drawline();
	gotoxy(52, 15);
	printf("아이템을 뽑아보자\n\n");

	Sleep(1500);
	for (i = 1; i <= n; i++)  //############ 색빛 - 인수 사용
	{
		p = rand() % 4;
		switch (p)
		{
		case ADDLIFE:
			life++;
			gotoxy(56, 16 + i * 2);
			printf("\'목숨증가\'");
			break;
		case CHANGEWORD:
			changeword++;
			gotoxy(55, 16 + i * 2);
			printf("\'단어바꾸기\'");
			break;
		case ADDTIME:
			addtime++;
			gotoxy(56, 16 + i * 2);
			printf("\'시간증가\'");
			break;
		case BOMB:
			gotoxy(58, 16 + i * 2);
			printf("\'꽝!\'\n\n");
			break;
		}
	}
	drawitem();
	drawmenu();
	gotoxy(36, 26);
	printf("목숨증가: %d개, 단어바꾸기: %d개, 시간증가: %d개 획득!\n", life - LIFE, changeword, addtime); //############ 색빛 - 기호 상수 사용
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                         아무키나 누르면 게임 시작! >");
	_getch();
}