/* get_name : 이름 입력 */
#include "common.h"

char name[100];

void get_name(int level)
{
	char sch[10];
	/*if (strlen(sch))
	{
		for (int i = 0; i < strlen(sch); i++)
			sch[i] = 0;
	}*/
	drawline(21, 8, 75, 25);
	gotoxy(37, 18);
	printf("게임을 시작하기 전에, 당신의 이름을 알려주세요!\n");
	drawline(47, 20, 22, 1);
	gotoxy(50, 21);
	cursor(1);
	gets_s(name, 100);
	cursor(0);
	Sleep(700);
	system("cls");
	KU(2);
	drawline(21, 8, 75, 25);
	drawline(21, 19, 75, 3);
	gotoxy(45, 21);
	cursor(0);
	switch(level)
	{
	case ELEMENTARY:
		strcpy(sch, "초등");
		break;
	case MIDDLE:
		strcpy(sch, "중");
		break;
	case HIGH:
		strcpy(sch, "고등");
		break;
	}
	printf("%s, %s학교 입학을 축하한다KU!", name, sch);
	Sleep(1200);

	gotoxy(37, 29);
	printf("[TIP] 메뉴 기능을 사용하고 싶을 땐 ESC키를 눌러줘!");
	gotoxy(95, 33);
	printf(">");
	cursor(1);
	_getch();
}