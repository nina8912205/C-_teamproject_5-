/*game_start : 게임 시작 전 레벨선택, 게임 방법 설명 함수*/
#include "common.h"
int end_game = 0;
void game_start_menu()
{
	int key, x = 67;
	int y = ELEMENTARY;    // 처음 커서 위치. 초등학교 레벨 
	
	drawline();  // 화면 테두리 및 메뉴 출력
	drawmenu();
	// 게임 레벨 출력
	gotoxy(54, GAMESTART);
	printf("1. 게임 시작");
	gotoxy(55, ELEMENTARY);
	printf("- 초등학교");
	gotoxy(55, MIDDLE);
	printf("- 중학교");
	gotoxy(55, HIGH);
	printf("- 고등학교");
	gotoxy(54, GAMERULES);
	printf("2. 게임 방법");
	gotoxy(54, GAME_END);
	printf("3. 게임 종료");

	// 커서 변경
	while (1)
	{
		gotoxy(x, y);
		printf("◀");
		key = _getch();
		if (key == 224)
		{
			gotoxy(x, y);
			printf("  ");
			key = _getch();
			switch (key)
			{
			case UP:
				if (y > ELEMENTARY)
					y -= 2;
				break;
			case DOWN:
				if (y < GAME_END)
					y += 2;
				break;
			}
		}
		else if (key == Enter)
			break;
	}

	move_stage(y);  // 선택한 레벨로 이동
	
}

/* 선택한 레벨로 이동 함수 */
void move_stage(int stage)
{
	extern int end_game;
	system("cls");
	drawline();
	

	switch (stage)
	{
	case ELEMENTARY:
		elementary();  // 초등학교 레벨로 이동
		break;
	case MIDDLE:
		//middle();  // 중학교 레벨로 이동
		break;
	case HIGH:
		//high();  // 고등학교 레벨로 이동
		break;
	case GAMERULES:  // 게임 방법을 보고 싶을 때
		game_rules();          // 게임 방법 출력
		break;
	case GAME_END:	//선택시 게임 종료
		end_game = 1;
		break;

	}
}