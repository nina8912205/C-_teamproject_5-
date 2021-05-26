#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/* Ű���� �Է� */         //############ ���� - ����Ű �ܿ��� �� ���� �Է� ���� �߰��ؼ� (����Ű -> Ű���� �Է�)
#define UP 72             // ��
#define DOWN 80           // ��
#define LEFT 75           // ��
#define RIGHT 77          // ��
#define Enter 13          // Enter: ����
#define BACKSPACE 8       //############ ���� - ���� �߰��� (BackSpace: �����)
#define ESC 27            //############ ���� - ���� �߰��� (ESCŰ)

/* ���� ���� */            //############ ���� - ���̾ƿ��� ���� ��ȣ ��� �� ����
#define GAMESTART 16
#define ELEMENTARY 18      // ���� ���۸޴� - �ʵ��б� ���� ��ǥ
#define MIDDLE 20          // ���� ���۸޴� - ���б� ���� ��ǥ
#define HIGH 22            // ���� ���۸޴� - ����б� ���� ��ǥ
#define GAMERULES 24       
#define GAME_END 26        


/* ������ */
#define ADDLIFE 0          // ��� + 1 �߰�
#define CHANGEWORD 1       // �ܾ� �ٲٱ�
#define ADDTIME 2          // �ð� �߰�
#define BOMB 3             // ��

/* ������� */
#define SIZE 50

/* ��� */
#define LIFE 3


/* ���� ��� */
#define BonusPerCombo 50    // �޺�����
#define MAX_Q 30           // ����ǥ ����� ���� �ִ� ���� ����


#define total_score 0
#define correct_score 1
#define time_bonus 2
#define combo_bonus 3
#define boss_total_score 4
#define boss_correct_score 5
#define boss_time_bonus 6
#define boss_combo_bonus 7


/*====================================== �Լ� ========================================*/

//############ ���� - �Լ��� ��� ���ǵǾ� �ִ� �� ã�� ������� �ڵ� ���� ���� ���� �߽��ϴ�

//main.c
void gotoxy(int, int);        // Ŀ�� �̵� �Լ�
void cursor(int);             // Ŀ�� ���̱�/�����

//game_title.c
void game_title();            // ���� Ÿ��Ʋ ���

//game_start.c
void game_start_menu();       // ���� ���� �޴� ���, ���� ����
void move_stage(int);         // ������ ������ �̵�

//game_rules.c
void game_rules();            // ���� ��Ģ
void rule_title();            // ��Ģ ��ܹ�
void PAGE1();
void PAGE2();
void PAGE3();
void PAGE4();
void PAGE5();
void clear();                 // ���θ� �����

//get_name.c
void get_name();              // �̸� �Է�

//item.c
void item_random(int);           // ������ �̱�

//edit.c
void drawline();              // ȭ�� �׵θ� �׸���
void drawmenu();              // �޴� 
void drawitem();              // ������, ��� ���
void draws(char*, int, int);  // ��� �� ����
void drawtopbar();                 // ��� �� �׵θ�

void draws_boss(char* sch, int num, int score);


//game.c
int game(int, int, char*, char*, int);


//elementary.c
void elementary(int);

//e_boss.c
void e_boss();

//middle.c
void middle(int);

//scorecard.c
void Final_Scorecard(int, int, int);
int Scorecard(int);
void sadKU();
void happyKU();

//combo.c
int Combo_num(int);   // ���� ���� ���� ��ȯ �Լ�

int combo_print(int); //**** 5/24(����) �޺� �ǽð� ǥ�� �߰�

//reset.c
void reset_OX();               // ����ǥ �ʱ�ȭ

//life.c
int decrease_life();

//timescore.c
int Etime(int);
int Mtime(int);
int Htime(int);
int TimeLeft(int, int, int);
int TimeBonus(int);

//menu.c
int menu();

//string.c
void random_word(int, char*);
void word_3(char*);
void word_4(char*);
void word_5(char*);
void word_6(char*);
void word_7(char*);

//score.c
void correct(int, int); //���� ���� �ݿ�
void combo(int);//�޺� ���ʽ� �ݿ�
void timescore(int,int);

void boss_correct(int , int ); //���� ���� �ݿ�

void boss_combo(int ); //�޺� ���ʽ� �ݿ�

void boss_time(int , int );

void score_reset();
void resetOX();//����ǥ �ʱ�ȭ

