#include "common.h"

int time_left = 0; // 남은 시간 저장 변수

// 단어 입력 && 시간 제한 -> 결과 반환(0: 오답, 1: 정답, 2: 메뉴 선택, 5: 단어 바꾸기)
int game(int timelimit, char* input, char* word, int num_Q)
{
	extern int changeword;
	char ch;
	int j = 0, start, end, result, sec = 1;
	int k = 0, i;

	input[0] = '\0';

	cursor(0);
	gotoxy(30, 15); printf("[제한 시간] ");
	for (int i = 0; i < timelimit; i++)
		printf("■");
	
	start = time(0);   // 시작 시간

	while (1)
	{	
		if (time(0) == start + sec)
		{
			cursor(0);
			gotoxy(30, 15); printf("[제한 시간] ");
			for (i = 0; i < timelimit - sec; i++)
				printf("■");
			for (i = timelimit - sec; i < timelimit; i++)
				printf("□");
			printf("\n");
			sec++;

			if (sec > timelimit)   // 학년별 제한 시간을 지켰는가?
			{
				result = 0;
				cursor(0);
				gotoxy(32, 21);	printf("TIME OVER!");
				gotoxy(32, 22);	printf("목숨이 하나 차감됩니다");

				decrease_life();

				Sleep(1500);
				system("cls");
				break;
			}
		}

		if (_kbhit()) // 사용자가 키를 눌렀는가?
		{
			cursor(1);
			gotoxy(52 + k, 19); 
			ch = _getch();
			if (ch != ESC && ch != BACKSPACE && ch != TAB && ch != ENTER)
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
				k++;
			}
			if (ch == ESC) // ESC누르면 메뉴로 
			{
				result = menu();
				break;
			}
			
			if (ch == BACKSPACE && j > 0)
			{
				printf("\b \b"); // 입력한거 지우기
				j--;
				k--;
				input[j] = '\0';
			}

			if (ch == TAB && changeword > 0)
			{
				changeword--; // changeword 감소
				result = 5;
				return result;
			}
			if (ch == ENTER)
			{
				input[j] = NULL;
				if (!strcmp(word, input)) { //정답
					result = 1;
					cursor(0);
					gotoxy(32, 21);	printf("PERFECT!\n");
					end = time(0);
					time_left += TimeLeft(timelimit, start, end); // 남아있는 시간 기록
					gotoxy(76, 12);	printf("+ 시간 보너스( %d 초)", TimeLeft(timelimit, start, end));
					gotoxy(76, 13);
					if (combo_print(num_Q) != 0)
						printf("%d COMBO", combo_print(num_Q));
				}
				else {  //오답
					result = 0;
					cursor(0);
					gotoxy(32, 21);	printf("땡!\n");
					gotoxy(32, 22);	printf("목숨이 하나 차감됩니다.");
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