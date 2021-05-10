#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define Enter 13
#define GAMESTART 15
#define ELEMENTARY 17
#define MIDDLE 19
#define HIGH 21
#define GAMERULES 23


/* 게임 시작 함수 */
void game_title();          // 게임 타이틀 출력
int game_start_menu();      // 게임 시작 메뉴 출력, 난이도 선택
void move_stage(int stage); // 선택한 난이도로 이동
void get_name();            // 이름 입력
void game_rules();          // 게임 방법 출력

/* 게임 진행 함수 */
int elementary(); // 초등학교
// 초등학교 보스
int middle();  //중학교
// 중학교 보스
int high();  //고등학교
// 수능

/* 아이템 함수 */
void item_random(void);   // 아이템 랜덤 지급 함수
void item_board(void);       // 아이템 보유 현황 함수

/* 콘솔창 편집 함수 */
void gotoxy(int x, int y); // 커서 이동 함수

