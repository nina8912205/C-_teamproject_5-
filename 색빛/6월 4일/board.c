#include "common.h"

// 배점
int scoreboard(int type, int grade)
{
	switch (type)
	{
	case E:	return (grade * 1000);
	case M: return (grade * 3000);
	case H: return (grade * 5000);
	case T: return (++grade * 8000);
	}
}

// 제한 시간
int timeboard(int type, int grade)
{
	switch (type)
	{
	case E:
		switch (grade)
		{
		case 1: return 5;
		case 2: return 5;
		case 3: return 6;
		case 4: return 6;
		case 5: return 8;
		case 6: return 8;
		}
	case M:
		switch (grade)
		{
		case 1: return 10;
		case 2: return 10;
		case 3: return 12;
		}
	case H:
		switch (grade)
		{
		case 1: return 12;
		case 2: return 15;
		case 3: return 15;
		}
	case T:
		switch (grade)
		{
		case E: return 8;
		case M: return 12;
		case H: return 18;
		}
	}
}
