#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/*커서 이동*/
#define UP 72
#define DOWN 80
#define Enter 13

/*게임 시작*/
#define GAMESTART 15
#define ELEMENTARY 17      // 게임 시작메뉴 - 초등학교 선택 좌표
#define MIDDLE 19          // 게임 시작메뉴 - 중학교 선택 좌표
#define HIGH 21            // 게임 시작메뉴 - 고등학교 선택 좌표
#define GAMERULES 23

/*아이템*/
#define ADDLIFE 0          // 아이템 - 목숨 + 1 추가
#define CHANGEWORD 1       // 단어 바꾸기
#define ADDTIME 2          // 시간 추가
#define BOMB 3             // 꽝

/*문제출력*/
#define SIZE 50

/*목숨*/
#define LIFE 5
 


/*====================================== 함수 ========================================*/
/* 게임 시작 함수 */
void game_title();            // 게임 타이틀 출력
void game_start_menu();       // 게임 시작 메뉴 출력, 레벨 선택
void move_stage(int stage);  // 선택한 레벨로 이동
void get_name();            // 이름 입력
void rule_title();          // 게임 방법 타이틀 출력
void game_rules();          // 게임 방법 출력


/* 게임 진행 함수 */
void elementary(); // 초등학교
//// 초등학교 보스
//int middle();  //중학교
//// 중학교 보스
//int high();  //고등학교
//// 수능


/* 아이템 함수 */
void item_random();         // 아이템 뽑기
//

/* 콘솔창 편집 함수 */
void gotoxy(int x, int y);  // 커서 이동 함수
void drawline();            // 화면 테두리 그리기
void drawmenu();            // 메뉴 
void drawitem();            // 아이템, 목숨 출력
void draws();               // 상단바(단계, 점수) 출력


/*목숨 증감 함수*/
int decrease_life();
int increase_life();

/*점수 계산*/
int elementary_score_add(int score);
