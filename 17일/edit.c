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

void drawmenu()  // �޴� ���
{
	gotoxy(22, 35);
	printf("�� M ���Ӹ޴��� P �Ͻ������� R ���ӹ���� L ���̵����榢 S ����ȭ�馢 Q �������ᦢ ");
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


void draws(char school,int grade, int score)
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
	/* �۾� */
	gotoxy(25, 10);
	printf("�� SCHOOL�� %c�б�   �� GRADE�� %d�г�", school, grade); // ������ �ٲٱ�(�б�, �г�)
	gotoxy(76, 10);
	printf("�� SCORE�� %010d",score);                            // ������ �ٲٱ�(����)
}