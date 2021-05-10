#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define Enter 13

/* 게임 시작 함수 */
void game_title(); // 게임 타이틀 출력
int game_start_menu(); // 게임 시작 메뉴 출력, 난이도 선택


/* 게임 진행 함수 */
int elementary(); //초등학교


/* 아이템 함수 */
void item_random(void);   // 아이템 랜덤 지급 함수
void item_board(void);       // 아이템 보유 현황 함수

/* 콘솔창 편집 함수 */
void gotoxy(int x, int y); // 커서 이동 함수

