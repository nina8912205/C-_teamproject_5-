/* get_name : 이름 입력 */
#include "common.h"

char name[100]; //############ 색빛 - 지역변수&&정적할당 -> 전역변수

void get_name()
{
	gotoxy(47, 21);
	printf("네 이름이 뭐니? \n");
	gotoxy(63, 21);
	cursor(1);
	gets_s(name, 100);
	cursor(0);
	gotoxy(47, 23);
	printf("%s ! 멋진 이름이다!", name);
	Sleep(1000);
}