#include "common.h"

// �׵θ� ���[(x, y): ������ġ, w: �ʺ�, h: ����]
void drawline(int x, int y, int w, int h) 
{
	int i;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < w; i++)
		printf("��");
	printf("��");
	for (i = y + 1; i <= h + y; i++)
	{
		gotoxy(x, i); printf("��");
		gotoxy(x + w + 1, i); printf("��\n");
	}
	gotoxy(x, y + h + 1);
	printf("��");
	for (i = 0; i < w; i++)
		printf("��");
	printf("��");
}

// �޴� ���
void drawmenu()
{
	gotoxy(27, 35);	printf("[ ESC ���Ӹ޴� ] R ���ӹ���� L ���̵����榢 S ����ȭ�馢 Q �������� ");
}

// ������, ��� ���
void drawitem()
{
	extern int item[3];

	// ��� 
	gotoxy(21, 7);	printf("��  LIFE �� ");
	for (int i = 0; i < item[LIFE]; i++) 
		printf("�� ");

	// ������ ������
	gotoxy(55, 7);
	printf("��  ITEM ��  �ܾ�ٲٱ�[TAB]: %d  �ð�����: %d ", item[CHANGEWORD], item[ADDTIME]);
}

// �⺻ ���̾ƿ�[level: �б�, grade: �г�, num: ���� ��ȣ, score: ����]
void layout(int level, int grade, int num)
{
	extern int TotalScore;
	extern char sch[SCHSIZE][SIZE];
	int score = scoreboard(level, grade);

	system("cls");

	// �ٱ� �׵θ�, ������, �޴�
	drawline(21, 8, 75, 25);
	drawitem();
	drawmenu();

	// ���� ���â
	drawline(28, 15, 61, 6);
	gotoxy(55, 16); printf("��  ���� �� ");

	// �Է�â
	drawline(28, 23, 61, 6);
	gotoxy(55, 24); printf("��  �Է� ��");

	// ����
	gotoxy(76, 14); printf("�� ������ %d ��", score);

	// ��ܹ�[�б�, �г�, ���� ��ȣ, �� ����] ���
	drawline(23, 9, 71, 1);
	gotoxy(25, 10);
	printf("�� SCHOOL�� %s�б�", sch[level]);
	printf("\t�� GRADE�� %d�г�", grade);
	printf("\t�� NO�� %d ", num);
	gotoxy(76, 10); printf("�� SCORE�� %010d", TotalScore);
}

// �������� ���̾ƿ�[level: �б�, num: ���� ��ȣ, score: ����]
void test_layout(int level, int num)
{
	extern char sch[SCHSIZE][SIZE];
	extern int TotalScore;
	int score = scoreboard(T, level);

	system("cls");

	drawline(21, 8, 75, 25);
	drawitem();
	drawmenu();

	drawline(28, 15, 61, 6);
	gotoxy(55, 16); printf("��  ���� �� ");

	drawline(28, 23, 61, 6);
	gotoxy(55, 24); printf("��  �Է� ��");

	gotoxy(76, 14); printf("�� ������ %d ��", score);

	drawline(23, 9, 71, 1);
	gotoxy(25, 10);
	printf("%s�б� �������� - %d��", sch[level], num);
	gotoxy(76, 10);
	printf("�� SCORE�� %010d", TotalScore);
}

// ���� ����[(x, y): ������ġ, w: �ʺ�, h: ����]
void clear(int x, int y, int w, int h) // ���븸 �����
{
	for (int i = 0; i < h; i++)
	{
		gotoxy(x, y + i);
		for (int j = 0; j < w; j++)
			printf("  ");
		printf("\n");
	}
}

// Ŀ�� �̵�(x, y)
void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// Ŀ�� ���� [(n) 0: Ŀ��X, 1: Ŀ��O] 
void cursor(int n)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

// ���ڻ� �ٲٱ� [n: ��] 
void textcolor(int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}

void KU(int type)
{
	cursor(0);
	gotoxy(0, 9);
	printf("\t\t\t\t            ���                      ���\n");
	printf("\t\t\t\t            ��  ��    ������    ��  ��\n");
	printf("\t\t\t\t            ��    ���          ���    ��\n");
	printf("\t\t\t\t            ��  ���              ���  ��\n");
	printf("\t\t\t\t        �����        ��    ��      �����\n");
	printf("\t\t\t\t    ���  ��            ��    ��          ��  ���\n");
	printf("\t\t\t\t  ��      ��      ��      ��  ��  ��      ��      ��\n");
	printf("\t\t\t\t��      ��      ��          ��      ��      ��      ��\n");
	printf("\t\t\t\t��      ��                                  ��      ��\n");
	switch (type)
	{
	case 0:
		printf("\t\t\t\t  ����                                      ����\n");
		printf("\t\t\t\t      ��      ������      ������      ��\n");
		printf("\t\t\t\t      ��        ��  ��          ��  ��        ��\n");
		break;
	case 1:
		printf("\t\t\t\t  ����          ��              ��          ����\n");
		printf("\t\t\t\t      ��        ��  ��          ��  ��        ��\n");
		printf("\t\t\t\t      ��                                      ��\n");
		break;
	case 2:
		printf("\t\t\t\t  ����            ��            ��          ����\n");
		printf("\t\t\t\t      ��          ���          ���          ��\n");
		printf("\t\t\t\t      ��          ���          ���          ��\n");
		break;
	case 3:
		printf("\t\t\t\t  ����          ��              ��          ����\n");
		printf("\t\t\t\t      ��            ��          ��            ��\n");
		printf("\t\t\t\t      ��          ��              ��          ��\n");
		break;
	case 4:
		printf("\t\t\t\t  ����            ��            ��          ����\n");
		printf("\t\t\t\t      ��      ��  ���  ����  ���  ��      ��\n");
		printf("\t\t\t\t      ��        �����      �����        ��\n");
		break;
	}

	printf("\t\t\t\t    ��                  ��  ��                  ��\n");
	printf("\t\t\t\t    ��            ����������            ��\n");
	printf("\t\t\t\t    ��        ����              ����        ��\n");
	switch (type)
	{
	case 0:
		printf("\t\t\t\t    ��    ���          ����          ���    ��\n");
		printf("\t\t\t\t    ��  ��            ��      ��            ��  ��\n");
		break;
	case 1:
	case 2:
	case 3:
	case 4:
		printf("\t\t\t\t    ��    ���        ��      ��        ���    ��\n");
		printf("\t\t\t\t    ��  ��              ����              ��  ��\n");
		break;
	}
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t      ��                                      ��\n");
	printf("\t\t\t\t        ��                                  ��\n");
	printf("\t\t\t\t        ���                              ���\n");
	printf("\t\t\t\t            ���                      ���\n");
	printf("\t\t\t\t              ���                  ���\n");
	printf("\t\t\t\t                  ����������\n");
	Sleep(700);
	system("cls");
}
