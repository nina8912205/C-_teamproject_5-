#include "common.h"

void drawline() // �׵θ� ���
{
	int i;

	gotoxy(21, 8);
	printf("��");
	for (i = 0; i < 75; i++)
		printf("��");
	printf("��");
	for (i = 9; i < 34; i++)
	{
		gotoxy(21, i); printf("��");
		gotoxy(97, i); printf("��\n");
	}
	gotoxy(21, 34);
	printf("��");
	for (i = 0; i < 75; i++)
		printf("��");
	printf("��");
}

void drawmenu()  //############ ���� - ���� �޴�â ����
{
	gotoxy(21, 35);
	printf("[ ESC ���Ӹ޴� ] P �Ͻ������� R ���ӹ���� L ���̵����榢 S ����ȭ�馢 Q �������� "); 	
}

void drawitem() // ������, ��� ���
{
	int i;
	extern int life, addtime, changeword;
	gotoxy(21, 7);
	printf("��  LIFE �� ");
	for (i = 0; i < life; i++)
		printf("�� ");
	gotoxy(60, 7);
	printf("��  ITEM ��  �ܾ�ٲٱ�: %d  �ð�����: %d ", changeword, addtime);
}

//############ ���� - �Լ� �μ� ����, ���� ����
void draws(char* sch, int grade, int num, int score)
{
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
	printf("�� SCORE�� %010d", score);                              
}

void drawtopbar() //############ ���� - �������� ������ ��ܹ� �׵θ� �Լ��� �и�
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