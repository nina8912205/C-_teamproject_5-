//string.c : 문자열 출력과 관련된 함수
#include "common.h"

// 단어 출력(랜덤)
void random_word(int size, char* w)
{
	int i;
	for (i = 0; i < size; i++) // 원하는 길이만큼 랜덤 문자열 생성
	{
		if (rand() % 2)
		{
			w[i] = 'a' + rand() % 26;
			printf("%c", w[i]);
			if (w[i] == 'l')
				printf("(엘)");
		}
		else
		{
			w[i] = 'A' + rand() % 26;
			printf("%c", w[i]);
			if (w[i] == 'I')
				printf("(아이)");
		}
			
	}
	w[i] = NULL; // word[size]에 0을 저장하면서 하나의 문자열 완성
}

// 단어 출력(의미)
void word_3(char* w)  // 3글자 단어
{
	int i, x;
	char word[25][4] = { "red", "cat", "bad", "ant", "dry", "egg", "fog", "gym", "hat", "ice",
		"job", "kid", "low", "mom", "new", "odd", "pen", "qua", "spy", "tie", "use", "van", "woe", "yew", "zap" };

	x = rand() % 25;
	for (i = 0; i < 4; i++)
	{
		w[i] = word[x][i];
	}
	printf("%s\n", w);
}

void word_4(char* w)  // 4글자 단어
{
	int i, x;
	char word[25][5] = { "asia", "babe", "chef", "data", "easy", "fake", "game", "hand", "icon", "joke", "mass", "king",
		"leaf", "note", "only", "peak", "quit", "road", "seed", "time", "ugly", "vain", "want", "year", "zoom" };

	x = rand() % 25;
	for (i = 0; i < 5; i++)
	{
		w[i] = word[x][i];
	}
	printf("%s\n", w);
}

void word_5(char* w) // 5글자 단어
{
	int i, x;
	char word[25][6] = { "above", "babel", "catch", "daily", "enter", "feint", "ghost", "haven", "ideal",
		"jolly", "knees", "labor", "marry", "never", "ocean", "party", "quake", "radio", "scary", "table",
		"urban", "vocal", "waive", "young", "zombi" };

	x = rand() % 25;
	for (i = 0; i < 6; i++)
	{
		w[i] = word[x][i];
	}
	printf("%s\n", w);
}

void word_6(char* w) // 6글자 단어
{
	int i, x;
	char word[25][7] = { "action", "ballet", "cannon", "degree", "effort", "fervor", "garlic", "happen",
		"impact", "jungle", "kimchi", "laptop", "magnet", "nobody", "omelet", "packet", "quaint", "racial",
		"safety", "talent", "update", "vendor", "waiter", "yellow", "zigzag" };

	x = rand() % 25;
	for (i = 0; i < 7; i++)
	{
		w[i] = word[x][i];
	}
	printf("%s\n", w);
}

void word_7(char* w) // 7글자 단어
{
	int i, x;
	char word[25][8] = { "ability", "baggage", "caution", "dynasty", "eyebrow", "foreign", "germany", "hostile",
		"inspire", "january", "kingdom", "laundry", "machine", "novelty", "observe", "popular", "quality", "railway",
		"scarify", "textile", "upstart", "vehicle", "warrior", "yawning", "zealous" };

	x = rand() % 25;
	for (i = 0; i < 8; i++)
	{
		w[i] = word[x][i];
	}
	printf("%s\n", w);
}

// 문장 출력
void word_short(char* w)	
{
	int i, x, y;
	char word[25][31] = { "A piece of cake", "Better than nothing", "Catch you later", "Do not miss the boat", 
		"Either will do", "First think and speak", "Good luck to you", "He is history to me", "It is out of style", 
		"Just do it", "Keep it to yourself", "Love will find a way", "No sweat, no sweet", "No pain no gain", 
		"Office changes manners", "Pride will have a fall", "Appearances are deceptive", "Reach for the stars",
		"Success doesn't come overnight", "This too, shall pass", "Union is strength", "Asking costs nothing", 
		"Will is power", "You let me down", "Habit is second nature" };

	x = rand() % 25;
	y = sizeof(word[x]) / sizeof(char);
	for (i = 0; i < y; i++)
	{
		w[i] = word[x][i];
	}
	printf("%s\n", w);
}

void word_short_h(char* w)
{
	int i, x, y;
	char word[25][100] = { "They can get married. They are old enough", "No, he won't. I only invited a few people", 
		"Good. I don't really like parties with a lot of people", "Sometimes that can be a good thing", 
		"We all felt sad to see our soccer team play so poorly", "Shut the door so that the cats don't run outside", 
		"Leave early so that you won't miss the bus", "I bet you'd hate to miss your first class even more",
		"It costs so much to get some clothes cleaned", "Do you know where I can get a watch fixed?", 
		"Five men have been killed in a car accident", "Are you sure we're going in the right direction", 
		"Yes, Her chocolate chip cookies are my favorite", "It is believed that 400 people were hurt in the latest earthquake", 
		"Jack is very old. It is said that he is 108 years old", "Don't worry. I'll run to the store for you", 
		"The truth is that my SAT is below what	they want", "The problem is that he doesn't know his own strength",
		"I wish I were rich. I need more money to pay my bills", "It's okay. I wasn't there for that long", 
		"Whether he may be young or old, I will employ him", "Do you want to go to the pool with me?", 
		"Thanks. That bus should get me to the meeting on time", "The people who live next to me have three cars", 
		"Though everyone may desert you, I will not" };

	x = rand() % 25;
	y = sizeof(word[x]) / sizeof(char);
	for (i = 0; i < y; i++)
	{
		w[i] = word[x][i];
	}
	printf("%s\n", w);
}