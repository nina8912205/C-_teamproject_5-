#include "common.h"
#define NUMBER_CHARACTERS 6

void elem_boss()
{
	/*
	�ʵ��б� ~ �ʵ��б� ������ �Ѿ�� �κ�
	��¹� �߰��ؾ���
	ex) ���� ���
	*/
	drawline();
	drawitem();
	drawmenu();
	gotoxy(32, 15);
	printf("�����մϴ�");		//�ӽ�
	Sleep(1000);
	gotoxy(32, 17);
	printf("�ʵ��б� ���������� ������ ���ƽ��ϴ�");	//�ӽ�
	Sleep(1000);
	gotoxy(32, 19);
	printf("�ʵ��б� ���� �������� �̱⼼��");		//�ӽ�
	Sleep(2000);
	system("cls");

	for (int i = 1; i <= 5; i++) {
		drawline();
		drawitem();
		drawmenu();
		gotoxy(32, 15);
		printf("[%�ʵ��б� ���� ���� - ���� %d ��]\n", i);

		elem_boss_word();
		Sleep(2000);
		system("cls");
	}
}

void elem_boss_word()
{
	srand((unsigned int)time(NULL));
	char word[256];   //��� ����
	char user[256];   //�Է� ����
	int t1, t2;
	int x = 0;
	int LIMIT = 7000;	//�ð� ���� 7��
	int Bscore = 8000;

	extern int O_X[MAX_Q];     // ����ǥ
	int num_Q = 1;

	extern int elementary_total_score;   // ȹ���� �� �������� (�ʵ��б�)

	for (int i = 0; i < NUMBER_CHARACTERS; i++) {
		word[i] = 'a' + rand() % 26;
	}
	word[NUMBER_CHARACTERS] = 0;
	gotoxy(32, 17);
	printf("���� : ");
	printf("%s\n", word);
	gotoxy(52, 17);
	printf("           ���� : %d ��\n\n", Bscore);
	gotoxy(32, 19);
	printf("������ ���� ġ���� : ");
	t1 = clock();

	do {
		t2 = clock();
		if (difftime(t2, t1) > LIMIT) {
			x = 1;
			break;
		}
	} while (!_kbhit());

	if (x != 1)
		gets_s(user, SIZE);

	if (LIMIT >= t2 - t1)   // �ð� ���� �Է� �Ϸ��� ���
	{
		if (!strcmp(word, user))   // �ٵ� �¾Ҿ�
		{
			gotoxy(32, 21);
			printf("���� !! %.2f �� ����� ���� �߽��ϴ�! ���� ȹ�� !! \n", TimeLeft(LIMIT, t1, t2));
			elementary_score_add(Bscore);

			//if (lefttime > 0)
			//{
			//	elemetary_score += score;
			//}

			// ���� ������ �ش��ϴ� ���ʽ� ���� �߰�
			printf("%.2f", elementary_score_time(TimeBonus(t1, t2, LIMIT)));

			// ===== ����ǥ ��� ===
			OX_Correct(num_Q);	// num_Q ��° ���� �� �����̸� ����ǥ�� 1 ���
			num_Q++;

		}
		else    // �ٵ� Ʋ�Ⱦ�
		{
			gotoxy(32, 21);
			printf("�� ! Ʋ�Ƚ��ϴ�. ��� ���� �Ф�\n");
			decrease_life();

			// ===== ����ǥ ��� ===
			OX_Wrong(num_Q);	// num_Q ��° ���� �� �����̸� ����ǥ�� 2 ���
			num_Q++;
		}
	}
	else    // �ð� ���� �Է� ���߾�
	{
		gotoxy(32, 21);
		printf("�ð��ʰ� ! ��� ���� �Ф�");
		decrease_life();

		// ===== ����ǥ ��� ===
		OX_Wrong(num_Q);	// num_Q ��° ���� �� �����̸� ����ǥ�� 2 ���
		num_Q++;
	}
}