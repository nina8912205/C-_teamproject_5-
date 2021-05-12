# include "common.h"

int main(void)
{
	int stage;  // 단계
	system("mode con: cols=120 lines=43"); // 콘솔창 크키 조정
	
	/*====================== 게임 시작 =======================*/
	game_title();                  // 게임 타이틀 출력
	drawline();	
	stage = game_start_menu();     // 단계 선택
	move_stage(stage);	       // 단계로 이동
	if (stage != GAMERULES)            
		get_name();            // 이름 입력 받기
	Sleep(1500);                   // 1.5초 기다리기
	srand((unsigned)time(NULL));  
	item_random();                 // 아이템 뽑기
	
	/*======================= 게임진행 =======================*/
	if (level == 1)
	{
		elementary(); // 초등학교
		ch = getchar();
		if (ch == 'y')  // y누르면 middle로 진급
		{
			middle();
		}
		else
		{
			end_game();  // ekf
		}
		// 시간 지나면 자동 초-> 중 진급 기능 필요. 
	}
	else if (level == 2)
	{
		middle();  // 중학교
		ch = getchar();
		if (ch == 'y')
		{
			high();
		}
		else
		{
			end_game();
		}
	}
	else if (level == 3)
	{
		high();  // 고등학교
	}
	else
	{
		// 다시 레벨 선텍하라고 함. 
	}






}
void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// 아이템 추첨함수 : 물약, 시간추가, 단어바꾸기 에서 3개 랜덤 추출. 게임 시작시 , 진급할 시
// 아이템 저장함수 : 어떤 아이템이 몇개 있는지 현황 표시.
// 단어바꾸기 함수 : 게임 진행 중 다시 단어 랜덤으로 바꾸기.
