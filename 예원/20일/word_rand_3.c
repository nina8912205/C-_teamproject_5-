#include "common.h"
//3���� ���ܾ� ��� �� �Է� �ް� ������ Ȯ��(�ð� ���� ���o)

void word_rand_3() 
{
    srand((unsigned)time(NULL));
    char word[25][4] = { "red", "cat", "bad", "ant", "dry", "egg", "fog", "gym", "hat", "ice", "job", "kid", "low", "mom", "new", "odd", "pen", "qua", "spy", "tie", "use", "van", "woe", "yew", "zap" };
    char s1[20];    //�Է¹��� ���ڿ�
    time_t t1, t2;  //���ѽð� ������ t1, t2����
    int LIMIT = 7000;	//�ð� ���� 7��
    int correct_number = 0;	//���� ���� ��
    int x = rand() % 25;

    printf("%s\n", word[x]);
    t1 = clock();
    do
    {                                    //���� t2 - t1�� LIMIT�� 7�ʰ� �Ѿ�� �ڵ����� �Ѿ�� �ϱ� ���� �ݺ���
        t2 = clock();
        if (difftime(t2, t1) > LIMIT) 
        {
            x = 1;
            break;
        }
    } while (!_kbhit());

    if (x != 1)
        scanf("%s", s1);

    int ret = strcmp(s1, word[x]);    // �Էµ� ���ڿ� ��(�� ���ڿ��� ������ 0���)
    if (ret == 0) {
        printf("O");
    }
    else {
        printf("X");
    }
}