// game.c : 게임 진행과 관련된 함수
#include "common.h"

int time_left = 0; // 남은 시간 저장 변수

// 단어 입력 받기 & 제한 시간이 지나면 넘어가기 -> 결과 반환(0: 오답, 1: 정답, 2: 메뉴 선택)
int game(int size, int timelimit, char* input, char* word)
{
	char ch;
	int j = 0, start, end, result;
	extern void random_word(int size, char* w);   // @@@@@@@@@@@@@@@@@@@@@@@  예원 : 단어바꾸기 함수 link
	extern int changeword;                        // @@@@@@@@@@@@@@@@@@@@@@@ 예원 : 외부에서 선언된 changeword 참조. 

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
				gotoxy(53 + j, 19);    // @@@@@@@@@@@@@@@@@@ 예원 : 밑에 if 문 단어바꾸기 때문에 커서위치가 달라져 gotoxy를 넣었습니다. 입력과 동시에 덧써지지 않도록 +j 했습니다.
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
			if (ch == ' ') // @@@@@@@@@@@@@@@@@@@ 예원 : 스페이스바 누르면 단어바꾸기 (계속 시도해봤는데 ctrl (17) 을 누르면 컴퓨터가 인식을 못하더라구요
			{
				if (changeword > 0)   // @@@@@@@@@@@@@@@@@@ 예원 : changeword 가 0보다 클때만 아래 실행 가능. 
				{
					int size_random;
					char* word_random;
					size_random = size;
					word_random = word;

					gotoxy(39, 17);   // @@@@@@@@@@@@@@@@@@@@@ 예원 : 덧써져서 출력되게 원래 단어 있던 위치로 이동시켜 print
					random_word(size_random, word_random);  // @@@@@@@@@@@@@@@@@@@@@@@@@ 예원 -> ctrl 키 누르면 단어바꾸기

					changeword--;    // changeword 감소 
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
