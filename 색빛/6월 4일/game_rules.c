/* game_rules : ���� ��� ��� */
#include "common.h"

void game_rules(int i) //i=0�̸� ���� ������, i=1�̸� ���� ����
{
	int page = 1, key;
	cursor(0);
	system("cls");
	drawline(21, 8, 75, 25);
	rule_title();

	while (1 <= page && page <= 5)
	{
		clear(23, 16, 37, 18);
		switch (page)
		{
		case 1:	PAGE1(); break;
		case 2:	PAGE2(); break;
		case 3:	PAGE3(); break;
		case 4:	PAGE4(); break;
		case 5:	PAGE5(); break;
		}

		if (page > 1)
		{
			gotoxy(23, 33);
			printf("< %d", page - 1);
		}
		else
		{
			gotoxy(23, 33);
			if(i)
				printf("< ��������");
			else
				printf("< ���� ���� �޴�");			
		}

		if (page < 5)
		{
			gotoxy(94, 33);
			printf("%d >", page + 1);
		}
		else
		{
			if (i)
			{
				gotoxy(85, 33); 
				printf(" ��������  >");
			}				
			else
			{
				gotoxy(80, 33); 
				printf(" ���� ���� �޴� >");
			}
				
		}

		key = _getch();
		if (key == 224)
		{
			key = _getch();
			switch (key)
			{
			case LEFT:
				page--;
				break;
			case RIGHT:
				page++;
				break;
			}
		}
	}
}

void rule_title()
{
	gotoxy(54, 10);
	printf("< �� �� �� �� >\n\n");
	gotoxy(28, 13);
	printf("[ MISSION: ������ ��Ȯ�ϰ� Ÿ�ڸ� �ļ� ��� �б��� �����϶� KU! ]");
}

void PAGE1()
{
	gotoxy(0, 16);
	printf("\t\t\t    1. ���̵��� ��������!\n\n");
	printf("\t\t\t     - �ʵ��б�(1~6�г�) �� ���б� �� ����б�\n\n");
	printf("\t\t\t     - ���б�(1~3�г�) �� ����б�\n\n");
	printf("\t\t\t     - ����б�(1~3�г�)\n\n\n");
	printf("\t\t\t    �� ���� �߰��� ���̵� ���� ���� (��, ���� �ʱ�ȭ)\n\n ");
	printf("\t\t\t    �� ���̵� ���� �� Ư�� �г�(ex. ���б� 2�г�)���� �̵� �Ұ�\n\n");
	printf("\t\t\t    �� ��� �г�, �б��� �����Ҽ��� ���̵� ���\n\n");
}

void PAGE2()
{
	gotoxy(0, 16);
	printf("\t\t\t    2. ��ſ� �б� ��Ȱ�� ����!\n\n");
	printf("\t\t\t     - ���õ� �ܾ�/���� ���ڿ��� ������ ��Ȯ�ϰ� �Է�����!\n\n");
	printf("\t\t\t     - Ʋ���ų� �ð� ���� �Է����� ������ ����� �� �� �پ���\n\n");
	printf("\t\t\t     - ��/���信 ������� ���� Ƚ���� �ѱ�� ���� �г����� �����Ѵ�\n\n\n");
	printf("\t\t\t    �� �������� �ܾ ���߸� BONUS ���� ȹ��!\n\n ");
	printf("\t\t\t    �� ������ ��Ȯ�ϰ� �Է��Ҽ��� ���� ���� ȹ��!\n\n");
	printf("\t\t\t    �� ���� ����(����)�� �޾� �������� ���� ����� ����!\n\n");
}

void PAGE3()
{
	gotoxy(0, 16);
	printf("\t\t\t    3. �б��� ��������!\n\n");
	printf("\t\t\t     - �� �б��� �ְ� �г��� ��ġ�� ���������� ġ���� �Ѵ�\n\n");
	printf("\t\t\t     - ���������� 5������ �����Ǿ� �ִ�\n\n");
	printf("\t\t\t     - ���� �� ����ǥ�� �ް�, �����б��� ������ �� �ִ�\n\n\n");
	printf("\t\t\t    �� �� �б��� �����ϸ�, ����� �������� �ʱ�ȭ�ȴ�!\n\n ");
}

void PAGE4()
{
	gotoxy(0, 16);
	printf("\t\t\t    4. �������� �������!\n\n");
	printf("\t\t\t     - �������� �� �б��� ������ �� �������� ���� �� �ִ�!\n\n");
	printf("\t\t\t       ( �ʵ��б�: 3�� / ���б�: 2�� / ����б�: 2�� )\n\n\n");
	printf("\t\t\t    �� ������ ������ \n\n");
	printf("\t\t\t     - ��� ����: ����� 1�� �����Ѵ� (�ڵ� ���) \n\n");
	printf("\t\t\t     - �ܾ� �ٲٱ�: �ٸ� �ܾ�� �ٲ��\n\n");
	printf("\t\t\t     - �ð� ����: ���� �ð��� 1�� �����Ѵ� (���� ���ӿ����� ��� ����)\n\n\n\n");
}

void PAGE5()
{
	gotoxy(0, 16);
	printf("\t\t\t    5. �޴��� �ҷ�����!\n\n");
	printf("\t\t\t      �� �޴� �̿릢 : ESCŰ ������ �� ��� ���� Ű �Է�\n\n\n");
	printf("\t\t\t       -  ESCŰ : ���� �޴� ����� �����Ѵ�\n\n");
	printf("\t\t\t       -      R : ���� ����� �ҷ��´�\n\n");
	printf("\t\t\t       -      L : ���� ���̵��� �����Ѵ�\n\n");
	printf("\t\t\t       -      S : ���� ȭ������ ���ư���\n\n");
	printf("\t\t\t       -      Q : ������ �����Ѵ�\n\n");
}

