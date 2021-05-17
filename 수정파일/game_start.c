/*game_start : ���� ���� �� ��������, ���� ��� ���� �Լ�*/
#include "common.h"
int end_game = 0;
void game_start_menu()
{
	int key, x = 67;
	int y = ELEMENTARY;    // ó�� Ŀ�� ��ġ. �ʵ��б� ���� 
	
	drawline();  // ȭ�� �׵θ� �� �޴� ���
	drawmenu();
	// ���� ���� ���
	gotoxy(54, GAMESTART);
	printf("1. ���� ����");
	gotoxy(55, ELEMENTARY);
	printf("- �ʵ��б�");
	gotoxy(55, MIDDLE);
	printf("- ���б�");
	gotoxy(55, HIGH);
	printf("- ����б�");
	gotoxy(54, GAMERULES);
	printf("2. ���� ���");
	gotoxy(54, GAME_END);
	printf("3. ���� ����");

	// Ŀ�� ����
	while (1)
	{
		gotoxy(x, y);
		printf("��");
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

	move_stage(y);  // ������ ������ �̵�
	
}

/* ������ ������ �̵� �Լ� */
void move_stage(int stage)
{
	extern int end_game;
	system("cls");
	drawline();
	

	switch (stage)
	{
	case ELEMENTARY:
		elementary();  // �ʵ��б� ������ �̵�
		break;
	case MIDDLE:
		//middle();  // ���б� ������ �̵�
		break;
	case HIGH:
		//high();  // ����б� ������ �̵�
		break;
	case GAMERULES:  // ���� ����� ���� ���� ��
		game_rules();          // ���� ��� ���
		break;
	case GAME_END:	//���ý� ���� ����
		end_game = 1;
		break;

	}
}