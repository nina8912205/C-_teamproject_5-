#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/* 키보드 입력 */         //############ 색빛 - 방향키 외에도 더 많은 입력 값을 추가해서 (방향키 -> 키보드 입력)
#define UP 72             // 상
#define DOWN 80           // 하
#define LEFT 75           // 좌
#define RIGHT 77          // 우
#define Enter 13          // Enter: 선택
#define BACKSPACE 8       //############ 색빛 - 새로 추가함 (BackSpace: 지우기)
#define ESC 27            //############ 색빛 - 새로 추가함 (ESC키)

/* 게임 시작 */            //############ 색빛 - 레이아웃을 위해 기호 상수 값 변경
#define GAMESTART 16
#define ELEMENTARY 18      // 게임 시작메뉴 - 초등학교 선택 좌표
#define MIDDLE 20          // 게임 시작메뉴 - 중학교 선택 좌표
#define HIGH 22            // 게임 시작메뉴 - 고등학교 선택 좌표
#define GAMERULES 24       
#define GAME_END 26        


/* 아이템 */
#define ADDLIFE 0          // 목숨 + 1 추가
#define CHANGEWORD 1       // 단어 바꾸기
#define ADDTIME 2          // 시간 추가
#define BOMB 3             // 꽝

/* 문제출력 */
#define SIZE 50

/* 목숨 */
#define LIFE 3


/* 점수 계산 */
#define BonusPerCombo 50    // 콤보점수
#define MAX_Q 30           // 정오표 기록을 위한 최대 문제 개수

/*점수 배열 인덱스값*/
#define total_score 0
#define correct_score 1
#define time_bonus 2
#define combo_bonus 3
#define boss_total_score 4
#define boss_correct_score 5
#define boss_time_bonus 6
#define boss_combo_bonus 7


/*====================================== 함수 ========================================*/

//############ 색빛 - 함수가 어디에 정의되어 있는 지 찾기 어려워서 코드 파일 별로 정리 했습니다

//main.c
void gotoxy(int, int);        // 커서 이동 함수
void cursor(int);             // 커서 보이기/숨기기

//game_title.c
void game_title();            // 게임 타이틀 출력

//game_start.c
void game_start_menu();       // 게임 시작 메뉴 출력, 레벨 선택
void move_stage(int);         // 선택한 레벨로 이동

//game_rules.c
void game_rules();            // 게임 규칙
void rule_title();            // 규칙 상단바
void PAGE1();
void PAGE2();
void PAGE3();
void PAGE4();
void PAGE5();
void clear();                 // 내부만 지우기

//get_name.c
void get_name();              // 이름 입력

//item.c
void item_random(int);           // 아이템 뽑기

//edit.c
void drawline();              // 화면 테두리 그리기
void drawmenu();              // 메뉴 
void drawitem();              // 아이템, 목숨 출력
void draws(char*, int, int);  // 상단 바 내용
void drawtopbar();                 // 상단 바 테두리

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
int Combo_num(int);   // 연속 정답 개수 반환 함수

int combo_print(int); //**** 5/24(현욱) 콤보 실시간 표시 추가

//reset.c
void reset_OX();               // 정오표 초기화

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
void correct(int, int); //정답 점수 반영
void combo(int);//콤보 보너스 반영
void timescore(int,int);

void boss_correct(int , int ); //정답 점수 반영

void boss_combo(int ); //콤보 보너스 반영

void boss_time(int , int );

void score_reset();
void resetOX();//정오표 초기화

