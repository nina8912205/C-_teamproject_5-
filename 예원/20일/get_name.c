/* get_name : 이름 입력 */
#include "common.h"

void get_name()
{
	static char name[100];

	gotoxy(47, 21);
	printf("네 이름이 뭐니? \n");
	gotoxy(63, 21);
	gets_s(name, 100);                     // 원래 scanf("%s", name) 이었는데 입력버퍼에 enter 가 남아 뒤에 elementary의 첫문제 입력에 영향줘서 수정. 
	gotoxy(47, 23);
	printf("%s ! 멋진 이름이다!", name);
	Sleep(1000);
}