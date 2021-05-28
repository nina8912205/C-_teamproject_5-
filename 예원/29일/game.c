//game.c : 게임 진행
/* (5/26)
  단어바꾸기 적용(예원님)
  - spacebar -> tab키
  - 새로운 변수 선언 삭제
  - 초등학교에서는 정상적으로 실행하지만 중학교에선 실행 안 되는 문제 해결
  SPACE 입력 추가
*/
#include "common.h"

int time_left = 0; // 남은 시간 저장 변수

// 단어 입력 && 시간 제한 -> 결과 반환(0: 오답, 1: 정답, 2: 메뉴 선택, 5: 단어 바꾸기)
int game(int size, int timelimit, char* input, char* word, int num_Q)
{
	extern int changeword;
	char ch;
	int j = 0, start, end, result;

	input[0] = '\0';    // @@@@@@@@@@@@@@@@@@@@@@@@@ 예원 : input 초기화. 올바르게 입력했는데 틀렸다고 하는 경우가 있어서 game 이 재호출 될 때 input 을 초기화 해 잔여 값을 없앱니다. 

	start = time(0);   // 시작 시간

	while (1)
	{
		if (time(0) == start + timelimit)   // 학년별 제한 시간을 지켰는가?
		{
			result = 0;
			cursor(0);
			gotoxy(32, 21);
			printf("TIME OVER!");
			gotoxy(32, 22);
			printf("목숨이 하나 차감됩니다");

			decrease_life();

			Sleep(1500);
			system("cls");
			break;
		}

		if (_kbhit()) // 사용자가 키를 눌렀는가?
		{
			ch = _getch();
			if (ch == ESC) // ESC누르면 메뉴로 
			{
				result = menu();
				break;
			}
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == SPACE)
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			if (ch == BACKSPACE && j > 0)
			{
				printf("\b \b"); // 입력한거 지우기
				j--;
				input[j] = '\0';             //@@@@@@@@@@@@@@@@ 예원 : input 배열 안의 문자도 지워야  정답 비교가 정상적으로 되더라구요

			}
			if (ch == TAB && changeword > 0)
			{
				changeword--; // changeword 감소
				result = 5;
				return result;
			}
			if (ch == 13)     // @@@@@@@@@@@@@@@@@@@@@ 예원 : enter 누르면 정/오 판별 (common.h 에 기호상수 ENTER 추가 필요)
			{
				input[j] = NULL;     // @@@@@@@@@@@@@@@@@@@@@ 예원 : game 인자를 size 대신 30 으로 했으므로, 배열에 입력한 자리 까지만 \0 으로 함
				if (!strcmp(word, input)) // 정답
				{
					result = 1;
					cursor(0);
					gotoxy(32, 21);
					printf("PERFECT!\n");
					gotoxy(32, 22);
					end = time(0);
					time_left += TimeLeft(timelimit, start, end); // 남아있는 시간 기록
					gotoxy(76, 12);
					printf("+ 시간 보너스( %d 초)", TimeLeft(timelimit, start, end));
					gotoxy(76, 13);
					if (combo_print(num_Q) != 0)
						printf("%d COMBO", combo_print(num_Q));
				}
				else // 오답
				{
					result = 0;
					cursor(0);
					gotoxy(32, 21);
					printf("땡!\n");
					gotoxy(32, 22);
					printf("목숨이 하나 차감됩니다.");
					decrease_life();
				}
				Sleep(1000);
				system("cls");
				break;
			
			}
		}				
	}

	
	
	return result;
}
