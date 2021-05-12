#include "common.h"

void game_start_menu()
{
	int key, x = 67;
	int y = ELEMENTARY;
	
	drawline();

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
				if (y < GAMERULES)
					y += 2;
				break;
			}
		}
		else if (key == Enter)
			break;
	}
	move_stage(y);
}
void move_stage(int stage)
{
	switch (stage)
	{
	case ELEMENTARY:
		elementary();
		break;
	case MIDDLE:
		middle();
		break;
	case HIGH:
		high();
		break;
	case GAMERULES:
		game_rules();
		game_start_menu();
		break;
	}
}

