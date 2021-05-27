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


void drawmenu()
{
	gotoxy(21, 35);
	printf("[ ESC ���Ӹ޴� ] P �Ͻ������� R ���ӹ���� L ���̵����榢 S ����ȭ�馢 Q �������� ");
}

void draws_boss(char* sch, int num, int score)
{
	drawtopbar();

	/* �۾� */
	gotoxy(25, 10);
	printf(" %s - ���� %d ��", sch, num);
	gotoxy(76, 10);
	printf("�� SCORE�� %010d", score);
}

void drawitem() // ������, ��� ���
{
	int i;
	extern int life, addtime, changeword;
	gotoxy(21, 7);
	printf("��  LIFE �� ");
	for (i = 0; i < life; i++)
		printf("�� ");
	gotoxy(55, 7);
	printf("��  ITEM ��  �ܾ�ٲٱ�[TAB]: %d  �ð�����: %d ", changeword, addtime);
}

void draws(char* sch, int grade, int num)
{
	extern int TotalScore;
	char school[10];

	drawtopbar();

	/* ���� */
	strcpy(school, sch);

	/* �۾� */
	gotoxy(25, 10);
	printf("�� SCHOOL�� %s�б�", school);
	printf("\t�� GRADE�� %d�г�", grade);
	printf("\t�� NO�� %d ", num);
	gotoxy(76, 10);
	printf("�� SCORE�� %010d", TotalScore);
}

void drawtopbar()
{
	/* ��ܹ� �׵θ� */
	int i;
	gotoxy(23, 9);
	printf("��");
	for (i = 0; i < 71; i++)
		printf("��");
	printf("��");
	gotoxy(23, 10); printf("��");
	gotoxy(95, 10); printf("��\n");
	gotoxy(23, 11);
	printf("��");
	for (i = 0; i < 71; i++)
		printf("��");
	printf("��");
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