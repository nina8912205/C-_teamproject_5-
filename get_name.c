#include "common.h"

void get_name()
{
	static char name[100];

	gotoxy(47, 21);
	printf("네 이름이 뭐니? \n");
	gotoxy(63, 21);
	scanf("%s", &name);
	gotoxy(47, 23);
	printf("%s ! 멋진 이름이다!", name);
}
