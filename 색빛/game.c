// game.c : 게임 진행과 관련된 함수
#include "common.h"

int time_left = 0; // 남은 시간 저장 변수

// 단어 입력 받기 & 제한 시간이 지나면 넘어가기 -> 결과 반환(0: 오답, 1: 정답, 2: 메뉴 선택)
int game(int size, int timelimit, char* input, char* word)
{
	char ch;
	int j = 0, start, end, result;

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
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			if (ch == BACKSPACE)
			{
				printf("\b \b"); // 입력한거 지우기
				if (j > 0)
				{
					input[j] = NULL;
					j--;
				}
			}
		}

		if (j >= size) // 문자열의 길이 넘으면	
		{
			input[size] = NULL;
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
				printf("+ 시간 보너스( %d 초)", TimeLeft(timelimit, start, end)); //############ 색빛 - 강의 내용으로 시간 재는게 int형이라 초출력을 정수로 했습니다.
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
			Sleep(1500);
			system("cls");
			break;
		}
	}
	return result;
}