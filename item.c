#include "common.h"

int life=3, changeword, addtime;

void item_random()
{
	int i, p;
	system("cls");
	drawline();
	gotoxy(52, 15);
	printf("아이템을 뽑아보자\n\n");
	Sleep(1500);
	for (i = 1; i < 4; i++)
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
	printf("목숨증가: %d개, 단어바꾸기: %d개, 시간증가: %d개 획득!\n", life-3, changeword, addtime);
	printf("\n\n\n\n\n\n\n\n\n\n");
}
