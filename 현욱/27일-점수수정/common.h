#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/* Ű���� �Է� */
#define UP 72             // ��
#define DOWN 80           // ��
#define LEFT 75           // ��
#define RIGHT 77          // ��
#define Enter 13          // Enter
#define BACKSPACE 8       // BackSpace
#define ESC 27            // Esc
#define TAB 9             // Tab
#define SPACE 32          // SPACE 

/* ���� ���� */
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
#define MAX_Q 20            // ����ǥ ����� ���� �ִ� ���� ����

/* ���� �迭 �ε��� */
//1����-�б� �ܰ�
#define E 0
#define M 1
#define H 2
//2����
#define TOTAL 0
#define CORRECT 1
#define TIME 2
#define COMBO 3
#define BOSS 4
#define B_CORRECT 5
#define B_TIME 6
#define B_COMBO 7
#define Q_CORRECT 8	//���� ������
#define Q_SOLVED 9	//Ǭ ������
#define B_Q_CORRECT 10
#define B_Q_SOLVED 11

#define GRADESIZE 3
#define SSIZE 12


/*====================================== �Լ� ========================================*/

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
void get_name(int);              // �̸� �Է�

//item.c
void item_random(int);           // ������ �̱�

//edit.c
void drawline(int, int, int, int);              // ȭ�� �׵θ� �׸���
void drawmenu();              // �޴� 
void drawitem();              // ������, ��� ���
void draws(char*, int, int);  // ��� �� ����
void draws_boss(char*, int, int);
void drawtopbar();                 // ��� �� �׵θ�
void gotoxy(int, int);        // Ŀ�� �̵� �Լ�
void cursor(int);             // Ŀ�� ���̱�/�����

//game.c
int game(int, int, char*, char*, int);

//elementary.c
void elementary(int);

//e_boss.c
void e_boss();

//middle.c
void middle(int);

//high.c
void high(int);

//scorecard.c
void Final_Scorecard(int, int, int);
int Scorecard(int);
void KU(int);

//combo.c
int Combo_num(int);   // ���� ���� ���� ��ȯ �Լ�
int combo_print(int);     // �޺����� ��ȯ �Լ�

//life.c
int decrease_life();

//time.c
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
void word_short(char*);
void word_short_h(char*);

//reset.c
void resetOX();
void e_score_reset(void);

//score.c
void correct(int, int);
void combo(int);
void timescore(int, int);
void boss_correct(int, int);
void boss_combo(int);
void boss_time(int, int);