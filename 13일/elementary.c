#include "common.h"

void elementary()
{
	char word[SIZE];
	char input[SIZE];
	int score;
	int k;             // ���ڿ� ���� ���� ����

	system("cls");
	drawline();
	get_name();
	item_random();
	system("cls");

	// item_board(); // ������ ���� ��Ȳ �����


	// ���̵� ����
	// �г⺰�� �ܾ����, 


	for (int i = 1; i <= 6; i++)  // 1�г� ~ 6�г�
	{
		for (int j = 1; j <= 3; j++)  // �г�� ���� ���� : 3�� 
		{
			drawline();
			drawitem();
			drawmenu();
			gotoxy(32, 15);

			printf("[%d �г� - ���� %d ��]\n", i, j);

			// ���� ���ڿ�
			for (k = 0; k <= i-1; k++) // �ش� �г⸸ŭ ������ �������ڿ�
			{
				word[k] = 'a' + (rand() % 26);
			}
			word[k] = '\0';

			// ���� �ο�
			score = i * 1000;

			// ���� ���
			gotoxy(32, 17);
			printf("���� : ");
			printf("%s\n", word);
			gotoxy(52, 17);
			printf("           ���� : %d ��\n\n", score);

			// ���� ���߱� 
			gotoxy(32, 19);
			printf("������ ���� ġ���� : ");
			gets_s(input, SIZE);

			if (!strcmp(input, word))
			{
				gotoxy(32, 21);
				printf("���� ! ���� ���� : %d", elementary_score_add(score));
	
				//if (lefttime > 0)
				//{
				//	elemetary_score += score;
				//}
			}
			else
			{
				decrease_life();
			}

			Sleep(2000);
			system("cls");
		}
	
	}


	// boss();

	///* == 1 �г� == */
	///*for (int i = 1; i <= 5; i++)
	//{*/
	//// ���� ���ڿ� 
	//word[0] = 'a' + (rand() % 26);
	//word[1] = '\0';

	//// ���� �ο�
	//score = 1000;

	//// ���� ���
	//printf("���� : ");
	//printf("%s\n", word);
	//printf("                                                    ���� : %d ��\n", score);

	//// ���� ���߱� 
	//printf("������ ���� ġ���� : ");
	//gets_s(input, SIZE);

	//if (!strcmp(input, word))
	//{
	//	printf("%d", elementary_score_add(score));
	//	//if (lefttime > 0)
	//	//{
	//	//	elemetary_score += score;
	//	//}
	//}
	//else
	//{
	//	decrease_life();
	//}
	//

	///* == 2 �г� == */
	//for (int i = 1; i <= 5; i++)
	//{
	//	// ���� ���
	//	// ���� ���߱� 
	//	if (// �����ð� > 0 && ���� ����)
	//		{
	//			// elem_total_score += score;
	//		}
	//	else
	//	{
	//		// life--;
	//	}
	//}
	///* == 3 �г� == */
	///* == 4 �г� == */
	///* == 5 �г� == */
	///* == 6 �г� == */

	///* === ���� === */
	//for (i = 1; i <= 5; i++)
	//{
	//	// ���� Ǯ��, 

	//	if (// �����ð� > 0 && ���� ���߸�)
	//		{
	//			correct_number += 1; // ���� ���� ���� ����
	//			if (// �����ð� > 5��)
	//			{
	//					// elem_total_score += boss_score
	//				}
	//				else // 0< �����ð� <= 5��
	//				{
	//				// elem_total_score += boss_score * (1- �����ð� * 0.1)
	//			}
	//				}

	//}


	//if (// correct_number >= ��ü ������ k��)
	//	{
	//		printf("���� ������ �̰���ϴ� !\n"); // ����� �¸� ! 
	//		printf("�����մϴ� ! �ʵ��б��� �����߽��ϴ� !\n");
	//		printf("����ǥ ���\n");  // ����ǥ ���
	//		printf("���б��� �����Ͻðڽ��ϱ�? \n( �� : \'y\' / �������� : press any button ) (5�� �̳� ���� ������ �ڵ� ���޵˴ϴ�)");

	//	}
	//else
	//{
	//	// �����ܰ� ���� �Ф�
	//	printf("�絵�� �Ͻðڽ��ϱ�? (�� : press 'y' / �������� : press any button)");


	//}
}