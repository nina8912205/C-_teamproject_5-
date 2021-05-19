# include "common.h"

int main(void)
{

	system("mode con: cols=120 lines=43"); // 콘솔창 크키 조정
	
	srand((unsigned)time(NULL));

	game_title();          // 게임 타이틀
		
	return 0;
}
void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
