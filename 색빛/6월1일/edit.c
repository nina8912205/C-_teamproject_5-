#include "common.h"

void drawline(int x, int y, int w, int h) // �׵θ� ���
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

void drawmenu() //#################����(5/31)
{
	gotoxy(27, 35);
	printf("[ ESC ���Ӹ޴� ] R ���ӹ���� L ���̵����榢 S ����ȭ�馢 Q �������� ");
}

void drawitem() // ������, ��� ���
{
	int i;
	extern int item[3];
	gotoxy(21, 7);
	printf("��  LIFE �� ");
	for (i = 0; i < item[LIFE]; i++)
		printf("�� ");
	gotoxy(55, 7);
	printf("��  ITEM ��  �ܾ�ٲٱ�[TAB]: %d  �ð�����: %d ", item[CHANGEWORD], item[ADDTIME]);
}

void layout(int level, int grade, int num, int score)
{
	extern int TotalScore;
	extern char sch[SCHSIZE][SIZE];

	system("cls");

	drawline(21, 8, 75, 25);

	drawline(28, 15, 61, 6);
	gotoxy(55, 16); printf("��  ���� �� ");

	drawline(28, 23, 61, 6);
	gotoxy(55, 24); printf("��  �Է� ��");

	gotoxy(76, 14); printf("�� ������ %d ��", score);

	drawitem();
	drawmenu();

	drawline(23, 9, 71, 1);
	gotoxy(25, 10);
	printf("�� SCHOOL�� %s�б�", sch[level]);
	printf("\t�� GRADE�� %d�г�", grade);
	printf("\t�� NO�� %d ", num);
	gotoxy(76, 10); printf("�� SCORE�� %010d", TotalScore);
}

void boss_layout(int level, int num, int score)
{
	extern char sch[SCHSIZE][SIZE];
	extern int TotalScore;
	
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
	printf("%s�б� ��������", sch[level]);
	gotoxy(76, 10);
	printf("�� SCORE�� %010d", TotalScore);
}

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

void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void cursor(int n)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}


void textcolor(int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}