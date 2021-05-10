#include "common.h"

int game_start_menu()
{
	int key, x = 67;
	int y = 17;

	gotoxy(54, 15);
	printf("1. 게임 시작");
	gotoxy(55, 17);
	printf("- 초등학교");
	gotoxy(55, 19);
	printf("- 중학교");
	gotoxy(55, 21);
	printf("- 고등학교");
	gotoxy(54, 23);
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
				if (y > 17)
					y -= 2;
				break;
			case DOWN:
				if (y < 23)
					y += 2;
				break;
			}
		}
		else if (key == Enter)
			break;
	}
	return y;
}
void move_stage(int stage)
{
	switch (stage)
	{
	case 17:
		elementary();
		break;
	case 19:
		// middle();
		break;
	case 21:
		// high();
		break;
	case 23:
		how_to_play();
		break;
	}
}

