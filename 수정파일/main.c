# include "common.h"

int main(void)
{
	/* 변수 지정 및 사전 작업 */
	int key;                               // 게임 시작 버튼
	extern int end_game, die;
	system("mode con: cols=120 lines=43"); // 콘솔창 크키 조정
	srand((unsigned)time(NULL));
	/*===================================== 게임 시작 단계 ===================================*/
	while (1)
	{
		game_title();          // 게임 타이틀
		key = _getch();
		
			if (key)
				system("cls"); // 키 입력 -> 화면 지우기
			while (1)
			{
				game_start_menu(); // 게임 시작 및 진행
				
				if (end_game == 1)//게임 종료 관련 - 메인 메뉴에서 게임 종료 선택시 게임 종료//
					break;
				if (die ==1) //목숨 0 되어 죽었을 경우
				{
					die = 0;
					break;
				}
			}
		
	if (end_game == 1)
		break;
	}     


	return 0;
	/*======================= 게임진행 =======================*/
	//if (level == 1)
	//{
	//	elementary(); // 초등학교
	//	ch = getchar();
	//	if (ch == 'y')  // y누르면 middle로 진급
	//	{
	//		middle();
	//	}
	//	else
	//	{
	//		end_game();  // ekf
	//	}
	//	// 시간 지나면 자동 초-> 중 진급 기능 필요. 
	//}
	//else if (level == 2)
	//{
	//	middle();  // 중학교
	//	ch = getchar();
	//	if (ch == 'y')
	//	{
	//		high();
	//	}
	//	else
	//	{
	//		end_game();
	//	}
	//}
	//else if (level == 3)
	//{
	//	high();  // 고등학교
	//}
	//else
	//{
	//	// 다시 레벨 선텍하라고 함. 
	//}






}
void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// 아이템 추첨함수 : 물약, 시간추가, 단어바꾸기 에서 3개 랜덤 추출. 게임 시작시 , 진급할 시
// 아이템 저장함수 : 어떤 아이템이 몇개 있는지 현황 표시.
// 단어바꾸기 함수 : 게임 진행 중 다시 단어 랜덤으로 바꾸기.




	/* ======================= 아이템 ========================*/

//	srand((unsigned)time(NULL));
//	item_random();
//
//}

// 아이템 추첨함수 : 물약, 시간추가, 단어바꾸기 에서 3개 랜덤 추출. 게임 시작시 , 진급할 시. 
// 아이템 저장함수 : 어떤 아이템이 몇개 있는지 현황 표시.
// 단어바꾸기 함수 : 게임 진행 중 다시 단어 랜덤으로 바꾸기.