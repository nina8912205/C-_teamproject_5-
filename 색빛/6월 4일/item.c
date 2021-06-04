/* item : 아이템 뽑기 */
#include "common.h"

int item[3] = { 0 };

void item_random(int n)
{
	extern char name[100];
	int i, p;
	
	item[LIFE] = DEFAULT, item[CHANGEWORD] = 0; item[ADDTIME] = 0;

	cursor(0);
	system("cls"); 
	drawline(21, 8, 75, 25);
	gotoxy(44, 14);	printf("%s님께 입학선물이 도착했습니다!\n", name);
	Sleep(1500);
	gotoxy(48, 16);	printf("\"아이템 랜덤 뽑기 (%d회)\"", n);
	Sleep(1000);
	gotoxy(44, 18);	printf("< 아무키나 누르면 아이템 추첨 >");
	cursor(1);
	_getch();
	drawline(43, 19, 30, 7);

	for (i = 1; i <= n; i++) 
	{
		p = rand() % 4;
		switch (p)
		{
		case LIFE:
			item[LIFE]++;
			gotoxy(55, (22 - n) + i * 2);
			printf("\'목숨증가\'");
			break;
		case CHANGEWORD:
			item[CHANGEWORD]++;
			gotoxy(54, (22 - n) + i * 2);
			printf("\'단어바꾸기\'");
			break;
		case ADDTIME:
			item[ADDTIME]++;
			gotoxy(55, (22 - n) + i * 2);
			printf("\'시간증가\'");
			break;
		case BOMB:
			gotoxy(58, (22 - n) + i * 2);
			printf("\'꽝\'\n\n");
			break;
		}
	}
	drawitem();
	drawmenu();
	gotoxy(36, 28);	printf("목숨증가: %d개, 단어바꾸기: %d개, 시간증가: %d개 획득!\n", item[LIFE] - DEFAULT, item[CHANGEWORD], item[ADDTIME]);
	gotoxy(32, 31);	printf("[TIP] 단어 바꾸기 아이템은 TAB키를 누르면 사용할 수 있어!\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t     게임 시작 >");
	_getch();
	system("cls");
}