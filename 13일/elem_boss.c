#include "common.h"
#define NUMBER_CHARACTERS 6

void elem_boss() {
	srand((unsigned int)time(NULL));
	char word[SIZE];
	char user[SIZE];
	time_t t1, t2;
	int x = 0;
	int LIMIT = 7000;	//시간 제한 7초
	int correct_number = 0;	//맞춘 문제 수
	int Bscore = 8000;

	for (int i = 0; i < NUMBER_CHARACTERS; i++) {
		word[i] = 'a' + rand() % 26;
	}
	word[NUMBER_CHARACTERS] = 0;
	gotoxy(32, 17);
	printf("문제 : ");
	printf("%s\n", word);
	gotoxy(52, 17);
	printf("           배점 : %d 점\n\n", Bscore);
	gotoxy(32, 21);
	printf("제한 시간: %d초", LIMIT / 1000);
	gotoxy(32, 23);
	printf("맞춘 문제 수: ");
	printf("%d", correct_number);
	gotoxy(32, 19);
	printf("문제를 따라 치세요 : ");
	t1 = clock();

	do {
		t2 = clock();
		if (difftime(t2, t1) > LIMIT) {
			x = 1;
			break;
		}
	} while (!_kbhit());
	if (x != 1) 
		scanf("%s[^\n]", &user);
	
	int ret = strcmp(word, user);
	gotoxy(32, 21);
	if (ret == 0) {
		printf("성공 ! 누적 총점 : %d", elementary_score_add(Bscore));
		correct_number += 1;
	}
	else {
		printf("시간 초과가 되었거나 틀렸습니다.");
		decrease_life();
	}
}
