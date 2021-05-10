/* 아이템 보유현황 함수 */
#include "common.h"

void item_board()
{
	static int medicine = 0, changeword = 0, addtime = 0, bomb = 0;
	int i = 0;
	extern item;

	for (i = 0; i <= 3; i++)
	{
		switch (item[i])
		{
		case 0:
			medicine = medicine + 1;
			break;
		case 1:
			changeword = changeword + 1;
			break;
		case 2:
			addtime = addtime + 1;
			break;
		case 3:
			bomb = bomb + 1;
			break;
		}
	}

	printf("물약 : %d개, 단어바꾸기 : %d개, 시간추가 : %d개, 꽝 : %d개", medicine, changeword, addtime, bomb);
}
