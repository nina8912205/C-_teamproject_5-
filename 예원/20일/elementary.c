#include "common.h"

int O_X[MAX_Q] = { 0 };                // OX_Correct �Լ� �� �ٸ� �Լ������� ȣ���ؾ� �ϹǷ� ���������� ����.
extern int Combo_num(int question);
int ComboBonus(int combo);

void elementary()
{
	char word[SIZE] = { '\0' };         // ���������� �ʱ� ���� ������ �� �����Ƿ� '\0' �̳� 0���� �ʱ�ȭ ������
	char input[SIZE] = { '\0' };
	int score = 0;
	int k;                      // ���ڿ� ���� ���� ����
	int start, end;             // ���۽ð�, ����ð� . ���������̹Ƿ� elementary �Լ� ȣ���� �� ���� �ʱ�ȭ. 
	double timelimit;              // level ��(�г⺰) ���ѽð�

	extern int O_X[MAX_Q];     // ����ǥ
	int num_Q = 1;              // ����ǥ ����� ���� ���� ��°��  ex) �ʵ��б� �� 18���� => 1�� ~ 18�� ���� 

	extern int elementary_total_score;   // ȹ���� �� �������� (�ʵ��б�)


	//////// 5/19 �߰�(����) - �б� ����/��� 0 �ǰ��� �� ���� ������ ������ �� �������� �ʱ�ȭ�� �ȵǾ� ����� ���� �������� �߰�///////
	extern int life, changeword, addtime;

	get_name();       // �̸� �Է¹ޱ�
	system("cls");

	drawline();      // ���̾ƿ� �׸���

	item_random();    // ������ �̱�
	system("cls");

	// item_board(); // ������ ���� ��Ȳ �����


	// ���̵� ����
	// �г⺰�� �ܾ����, 


	for (int i = 1; i <= 6; i++)  // 1�г� ~ 6�г�
	{
		timelimit = (double)TimeLimit(i);   // �г� �� ���ѽð� 

		//��� �˻�
		if (life == 0) ////////5/19 ����(����) - ���� �׾��ٸ�, for�� ���� ���� ������/��� ���� �Լ� �ʱ�ȭ
		{
			//life = 3, changeword = 0, addtime = 0;
			//elementary_total_score = 0;	//��� 0�Ǿ� �������̹Ƿ� �ʵ��б� ������ �ʱ�ȭ �صξ����ϴ�. �ʿ��ϸ� �������ּ���! :-)
			break;
		}

		for (int j = 1; j <= 1; j++)  // �г�� ���� ���� : 3�� 
		{
			/////// 5/19 �߰�(����) - ����˻�, 0�̸� �ٷ� break
			if (life == 0)
				break;

			drawline();
			draws("�ʵ�", i, j, elementary_total_score);
			drawitem();
			drawmenu();

			// ���� �ο�
			score = i * 1000;

			printf("[%d �г� - ���� %d ��]\n", i, j);

			// ���� ���ڿ�
			for (k = 0; k <= i - 1; k++)             // �ش� �г⸸ŭ ������ �������ڿ�
			{
				word[k] = 'a' + (rand() % 26);
			}

			// ���� ���
			gotoxy(32, 17);
			printf("���� : ");
			printf("%s\n", word);
			gotoxy(52, 17);
			printf("           ���� : %d ��\n\n", score);

			// ���� ���߱� 
			gotoxy(32, 19);
			printf("������ ���� ġ���� : ");
			start = clock();  // ���� �ð� ���
			gets_s(input, SIZE);


			// ================================================= �ð� ===================================== // 
			// 05/17 : ���ѽð� �� ���� �� ���� ���ʽ� ���� �߰� / ���ѽð� �� ���信 ���� ��� ���� / ���ѽð� �ʰ��� ���� ��� ����
			end = clock();  // ����ð� ���



			// �޴� �Է�
			if (!strcmp(input, "M"))
			{
				menu();
				system("cls");
				j--;
			}
			else
			{
				if (timelimit >= end - start)   // �ð� ���� �Է� �Ϸ��� ���
				{
					if (!strcmp(input, word))    // �ٵ� �¾Ҿ�
					{
						gotoxy(32, 21);
						printf("���� !! %.2f �� ����� ���� �߽��ϴ�! ���� ȹ�� !! \n", TimeLeft(timelimit, start, end));
						elementary_score_add(score);

						//if (lefttime > 0)
						//{
						//	elemetary_score += score;
						//}



						// ===== ����ǥ ��� ===
						OX_Correct(num_Q);	// num_Q ��° ���� �� �����̸� ����ǥ�� 1 ���

						// ���� ������ �ش��ϴ� ���ʽ� ���� �߰�
						printf("%.2f", elementary_score_time(TimeBonus(start, end, timelimit)));

						num_Q++;

					}
					else if (strcmp(input, word))   // �ٵ� Ʋ�Ⱦ�
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
				Sleep(2000);
				system("cls");
			}

		}

	}

	if (life != 0)
		elem_boss();   // ���� 
		

	/////// 5/19 ���� (����) - �޺����� ��� �Ǳ����� ����ǥ�� �ʱ�ȭ�Ǿ� �ֱ淡 ���� �ٲپ� �־����ϴ�!
		// �޺����� ���
	gotoxy(32, 23);
	printf("�޺����� : %d ��", ComboBonus(Combo_num(18)));
	Sleep(2000);

	// ����ǥ �ʱ�ȭ
	reset_OX();
	// ���߿� ComboBonus �Լ��� ��¦ �ٲ㼭 Ư�� ������ �޺� ���� �����صθ� life 0 ���� ���� ���� ����ŵ� ��� �޺� ����Ǿ�


	life = 3; //��� �ʱ�ȭ
}