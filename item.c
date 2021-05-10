#include "common.h"

int addlife, changeword, addtime;

void item_random()
{
	int i, p;
	system("cls");

	printf("아이템을 뽑아보자.\n\n");
	Sleep(1500);
	for (i = 1; i < 4; i++)
	{
		p = rand() % 4;

		switch (p)
		{
		case ADDLIFE:
			addlife++;
			printf("\'목숨증가\' 아이템을 획득했다.\n ");
			break;
		case CHANGEWORD:
			changeword++;
			printf("\'단어바꾸기\' 아이템을 획득했다.\n");
			break;
		case ADDTIME:
			addtime++;
			printf("\'시간증가\' 아이템을 획득했다.\n");
			break;
		case BOMB:
			printf("\'꽝!\'\n");
			break;
		}
	}	
	printf(" \n총 목숨증가: %d개, 단어바꾸기: %d개, 시간증가: %d개를 획득했다.\n", addlife, changeword, addtime);
}
void item_board()
{
	char ch;
	printf("아이템 보유 현황을 보고 싶으면 i를 입력하세요: ");
	while ((ch = getchar()) == '\n');
	if (ch == 'i')
	{
		printf("+ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ+\n");
		printf("l        MY ITEM       l\n");
		printf("l                      l\n");
		printf("l    목숨증가: %d개     l\n", addlife);
		printf("l                      l\n");
		printf("l  단어바꾸기: %d개     l\n", changeword);
		printf("l                      l\n");
		printf("l    시간증가: %d개     l\n", addtime);
		printf("l                      l\n");
		printf("+ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ+\n");
	}	
}
