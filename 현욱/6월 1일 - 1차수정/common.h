#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/* ????? ??? */
#define UP 72             // ??
#define DOWN 80           // ??
#define LEFT 75           // ??
#define RIGHT 77          // ??
#define ENTER 13          // Enter
#define BACKSPACE 8       // BackSpace
#define ESC 27            // Esc
#define TAB 9             // Tab
#define SPACE 32          // SPACE

#define COMMA 44
#define QUOTATION 34
#define APOSTROPHE 39
#define PERIOD 46

/* ???? ???? */
#define GAMESTART 16
#define ELEMENTARY 18      // ???? ?????? - ????¬Ò? ???? ???
#define MIDDLE 20          // ???? ?????? - ???¬Ò? ???? ???
#define HIGH 22            // ???? ?????? - ?????¬Ò? ???? ???
#define GAMERULES 24       
#define GAME_END 26        


/* ?????? */
#define ADDLIFE 0          // ??? + 1 ???
#define CHANGEWORD 1       // ??? ????
#define ADDTIME 2          // ?©£? ???
#define BOMB 3             // ??

/* ??????? */
#define SIZE 100


/* ??? */
#define LIFE 3

/* ???? ??? */
#define BonusPerCombo 50    // ???????
#define MAX_Q 20            // ????? ????? ???? ??? ???? ????

/* ???? ?ò÷ ?¥å??? */
#define TOTAL 0
#define CORRECT 1
#define TIME 2
#define COMBO 3
#define BOSS 4
#define B_CORRECT 5
#define B_TIME 6
#define B_COMBO 7
#define Q_CORRECT 8
#define Q_SOLVED 9
#define B_Q_CORRECT 10
#define B_Q_SOLVED 11
#define ASIZE 12

#define E 0
#define M 1
#define H 2
#define SCHSIZE 3


//Á¡¼ö
#define E_Bscore 8000
#define M_Bscore 10000
#define H_Bscore 12000


/*====================================== ??? ========================================*/

//game_title.c
void game_title();            // ???? ???? ???

//game_start.c
void game_start_menu();       // ???? ???? ??? ???, ???? ????
void move_stage(int);         // ?????? ?????? ???

//game_rules.c
void game_rules(int);            // ???? ???
void rule_title();            // ??? ????
void PAGE1();
void PAGE2();
void PAGE3();
void PAGE4();
void PAGE5();
void clear();                 // ???¥è? ?????

//get_name.c
void get_name();              // ??? ???
void welcome(int);

//item.c
void item_random(int);           // ?????? ???

//edit.c
void drawline(int, int, int, int);              // ??? ??¥è? ?????
void drawmenu();              // ??? 
void drawitem();              // ??????, ??? ???
void draws(char*, int, int);  // ??? ?? ????
void draws_boss(char*, int, int);
void drawtopbar();                 // ??? ?? ??¥è?
void gotoxy(int, int);        // ¨¨?? ??? ???
void cursor(int);             // ¨¨?? ?????/?????

//game.c
int game(int, char*, char*, int, int, int, int);

//elementary.c
void elementary(int);

//e_boss.c
void e_boss();

//middle.c
void middle(int);

//m_boss.c
void m_boss();

//high.c
void high(int);

//h_boss.c
void h_boss();

//scorecard.c
void Final_Scorecard();
void print_phrase(int);
int Scorecard(int);
void KU(int);

//combo.c
int Combo_num(int);   // ???? ???? ???? ??? ???
int combo_print(int);     // ??????? ??? ???

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
void resetScore(int);
void empty_buffer();

//score.c
void correct(int, int);
void combo(int);
void timescore(int, int);
void boss_correct(int, int);
void boss_combo(int);
void boss_time(int, int); 
