//string.c : ���ڿ� ��°� ���õ� �Լ�
//########### ���� - �ܾ� ���� �迭�� �ʹ� ������� �������� ���� ���� �س����ϴ�. 
#include "common.h"

// �ܾ� ���(����)
void random_word(int size, char* w)
{
	int i;
	for (i = 0; i < size; i++) // ���ϴ� ���̸�ŭ ���� ���ڿ� ����
	{
		if (rand() % 2 == 0)  // �빮��, �ҹ��� ���� ����
			w[i] = 'a' + rand() % 26;
		else
			w[i] = 'A' + rand() % 26;
	}
	w[i] = NULL; // word[size]�� 0�� �����ϸ鼭 �ϳ��� ���ڿ� �ϼ�

	printf("%s\n", w); // ���� ���ڿ� ��� 
}

// �ܾ� ���(�ǹ�)
void word_3(char* w)  // 3���� �ܾ�
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

void word_4(char* w)  // 4���� �ܾ�
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

void word_5(char* w) // 5���� �ܾ�
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

void word_6(char* w) // 6���� �ܾ�
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

void word_7(char* w) // 7���� �ܾ�
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