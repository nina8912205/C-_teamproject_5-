#include "common.h"
//5글자 영단어 출력

void output_rand_5() {
    srand((unsigned)time(NULL));
    char word[25][6] = { "above", "babel", "catch", "daily", "enter", "feint", "ghost", "haven", "ideal", "jolly", "knees", "labor", "marry", "never", "ocean", "party", "quake", "radio", "scary", "table", "urban", "vocal", "waive", "young", "zombi" };
    char s1[20];    //입력받을 문자열
    time_t t1, t2;  //제한시간 때문에 t1, t2설정
    int LIMIT = 7000;	//시간 제한 7초
    int correct_number = 0;	//맞춘 문제 수
    int x = rand() % 25;

    printf("%s\n", word[x]);
    t1 = clock();
    do {    //만약 t2 - t1이 LIMIT인 7초가 넘어가면 자동으로 넘어가게 하기 위한 반복문
        t2 = clock();
        if (difftime(t2, t1) > LIMIT) {
            x = 1;
            break;
        }
    } while (!_kbhit());
    if (x != 1)
        scanf("%s", s1);

    int ret = strcmp(s1, word[x]);    // 입력된 문자열 비교(두 문자열이 같으면 0출력)
    if (ret == 0) {
        printf("O");
    }
    else {
        printf("X");
    }
}
