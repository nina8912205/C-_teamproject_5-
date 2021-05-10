/*게임 시작 시 아이템 랜덤 추출함수*/

# include "common.h"

// main 함수에서 srand((unsigned)time(NULL)) 명명 필요. 
// 0 : 물약, 1: 단어바꾸기, 2: 시간추가, 3: 꽝

void item_random(void)
{
	int i;
	int item[4] = {0,0,0,0};

	for (i = 0; i < sizeof(item) / sizeof(int); i++)
	{
		item[i] = rand() % 4; // 0123  item[4] = {2,3,0 ,0}  => 
		printf("%d", item[i]);
	}
	//  0,1,2,3중 하나 랜덤 추출하여 item_random 에 저장됨.  
}
