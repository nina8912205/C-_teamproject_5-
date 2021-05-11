//���� ����Ʈ
//name: �̸�	elementary_score: �ʵ��б� ����		middle_score: ���б� ����	high_score: ����б� ����
//grade: ���
//level: ������ �÷����� ���� ex)��/��/�� => e/m/h ***���� ����� ���� �ʿ�
//time_bonus, combo_bonus
#include "common.h"

//���� ����� ����ǥ
void Final_Scorecard(char name[],int elementary_score, int middle_score, int high_score)
{
	int grade;
	int scoresum = elementary_score + middle_score + high_score;
	
	//��� ����-���� �����ϱ�
	if (scoresum < 10000)
		grade = 9;
	else if (10000 <= scoresum && scoresum < 20000)
		grade = 8;
	else if (20000 <= scoresum && scoresum < 30000)
		grade = 7;
	else if (30000 <= scoresum && scoresum < 40000)
		grade = 6;
	else if (40000 <= scoresum && scoresum < 50000)
		grade = 5;
	else if (50000 <= scoresum && scoresum < 60000)
		grade = 4;
	else if (60000 <= scoresum && scoresum < 70000)
		grade = 3;
	else if (70000 <= scoresum && scoresum < 80000)
		grade = 2;
	else
		grade = 1;

	printf("                     ����ǥ                     \n");
	printf("                                    �̸�:	%s  \n",name);//�̸� ���
	printf("                                                \n");
	printf("             �ʵ��б�:  %d��\n\n",elementary_score);
	printf("             ���б�  :  %d��\n\n",middle_score);
	printf("             ����б�:  %d��\n\n", high_score);
	printf("             ����    :  %d��\n\n", elementary_score + middle_score + high_score);
	printf("             ���� ���: %d���", grade);

}

void Scorecard(char name[], char level, int score, int time_bonus, int combo_bonus) //level: e-elementary  m-middle  h-high
{
	if (level == 'e')
	{
		printf("                  �ʵ��б� ����ǥ          \n\n");
		printf("          ! �ʵ��б� ������ �����մϴ� !  \n\n");
	}
		
	if(level=='m')
	{
		printf("                  ���б� ����ǥ          \n\n");
		printf("          ! ���б� ������ �����մϴ� !  \n\n");
	}
	if(level=='h')
	{
		printf("                  ����б� ����ǥ          \n\n");
		printf("          ! ����б� ������ �����մϴ� !  \n\n");
	}
	
	printf("                                         �̸�:    %s	\n",name);//�̸� ���
	printf("                                                \n");
	printf("             ȹ���� ����  :  %d��\n\n", score);
	printf("             �ð��߰� ����:  %d��\n\n", time_bonus);
	printf("             �޺�����     :  %d��\n\n", combo_bonus);
	printf("             ����         :  %d��\n\n", score+time_bonus+combo_bonus);
	
	
}