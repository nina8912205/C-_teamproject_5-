#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/* 키보드 입력 */        
#define UP 72             // 상
#define DOWN 80           // 하
#define LEFT 75           // 좌
#define RIGHT 77          // 우
#define ENTER 13          // Enter
#define BACKSPACE 8       // BackSpace
#define ESC 27            // Esc
#define TAB 9             // Tab
#define SPACE 32          // SPACE
#define COMMA 44          // ,
#define QUOTATION 34      // "
#define APOSTROPHE 39     // '
#define PERIOD 46         // .

/* 게임 시작 */            
#define GAMESTART 16
#define ELEMENTARY 18      // 게임 시작메뉴 - 초등학교 선택 좌표
#define MIDDLE 20          // 게임 시작메뉴 - 중학교 선택 좌표
#define HIGH 22            // 게임 시작메뉴 - 고등학교 선택 좌표
#define GAMERULES 24       
#define GAME_END 26        


/* 아이템 배열 */
#define LIFE 0             // 목숨
#define CHANGEWORD 1       // 단어 바꾸기
#define ADDTIME 2          // 시간 추가
#define BOMB 3             // 꽝

/* 문제출력 */
#define SIZE 100

/* 목숨 */
#define DEFAULT 3

/* 점수 계산 */
#define BonusPerCombo 50    // 콤보점수
#define MAX_Q 20            // 정오표 기록을 위한 최대 문제 개수

/* 점수 배열 인덱스 */
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
#define T 3

/* game() 반환 result 값 기호상수화*/
#define Wrong 0	//RIGHT가 이미 선언되어 있어 Wrong,Right 소문자로 선언했습니다.
#define Right 1
#define HOWTOPLAY 2
#define CHANGE_LEVEL 3
#define STARTMENU 4
#define WORDITEM 5




/*====================================== 함수 ========================================*/

//game_title.c
void game_title();            // 게임 타이틀 출력

//game_start.c
void game_start_menu();       // 게임 시작 메뉴 출력, 레벨 선택
void move_stage(int);         // 선택한 레벨로 이동

//game_rules.c
void game_rules(int);            // 게임 규칙
void rule_title();            // 규칙 상단바
void PAGE1();
void PAGE2();
void PAGE3();
void PAGE4();
void PAGE5();


//get_name.c
void get_name();              
void welcome(int);

//item.c
void item_random(int);          

//edit.c
void drawline(int, int, int, int);            
void drawmenu();              
void drawitem();              
void layout(int, int, int);
void test_layout(int, int);
void clear(int, int, int, int);
void gotoxy(int, int);       
void cursor(int);             
void textcolor(int);

//game.c
int game(int, char*, char*, int, int, int);
void perfect();
void timeover();
void wrong();
void gradeup();

//elementary.c
void elementary(int);

//middle.c
void middle(int);

//high.c
void high(int);

//test.c
void test(int);

//scorecard.c
void Final_Scorecard();
void print_phrase(int);
int Scorecard(int);
void KU(int);

//combo.c
int Combo_num(int);   // 연속 정답 개수 반환 함수
int combo_print(int);     // 콤보점수 반환 함수

//life.c
void decrease_life(int*);

//time.c
int timeboard(int, int);
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
void resetScore();

//score.c
int scoreboard(int, int);
void addscore(int, int, int);
void add_test_score(int, int, int);
