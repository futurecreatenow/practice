#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define STR_LENGTH 10
#define INIT_NUM -1

enum num{
    ZERO,
    ONE,
    TWO,
};
enum re{
    FINISH,
    RETRY,
};
typedef enum{
    ROCK,
    SCISSORS,
    PAPER,
}HAND;
typedef enum{
    DRAW,
    WIN,
    LOSE,
}RESULT;
typedef struct DATA{
    RESULT result;
    HAND hand;
    int retry;
}DATA;

char hand_char[STR_LENGTH];//出し手の表示
char result_char[STR_LENGTH];//結果の表示

//プロトタイプ宣言
void set_hand(DATA *me,DATA *you);//出す手をそれぞれ決定する
char *num_to_hand(int num);//数字(0から2)を出し手(ROCK,SCISSORS,PAPER)に変換する
void judge(DATA *me,DATA *you);//勝敗の判定
char *printout(DATA *me);//勝敗の結果出力
int re(DATA *me);//続けるか終了するか

//数字(0から2)を出し手(ROCK,SCISSORS,PAPER)に変換する
char *num_to_hand(int num){
    if (num == ZERO)
    {
        strcpy(hand_char,"ROCK");
    }
    else if (num == ONE)
    {
        strcpy(hand_char,"SCISSORS");
    }
    else{
        strcpy(hand_char,"PAPER");
    }
    return hand_char;
}

//勝敗の結果出力
char *printout(DATA *me){
    printf("########result#########\n");
    if (me->result == DRAW)strcpy(result_char,"DRAW");
    else if (me->result == WIN)strcpy(result_char,"WIN");
    else strcpy(result_char,"LOSE");
    return result_char;
}

//出す手をそれぞれ決定する
void set_hand(DATA *me,DATA *you){
    me->hand = INIT_NUM;
    you->hand = INIT_NUM;

    //自分の手を決定する
    while ((me->hand < ZERO) || (me->hand > TWO))
    {
        printf("########select########\n");
        printf("select your hand\n");
        printf("%d>>>ROCK\n",ROCK);
        printf("%d>>>SCISSORS\n",SCISSORS);
        printf("%d>>>PAPER\n",PAPER);
        scanf("%d",&me->hand);
    }

    //相手の手を決定する
    //time関数を使った乱数の種の設定
    srand((unsigned int)time(NULL));
    you->hand = rand() % 3;
    return;
}
//勝敗の判定
void judge(DATA *me,DATA *you){
    if (me->hand == you->hand)
    {
        me->result = DRAW;
    }
    else{
        if (me->hand == ROCK)
        {
            switch(you->hand){
                case SCISSORS:me->result = WIN;break;
                case PAPER:me->result = LOSE;break;
                default:break;
            }
        }
        if (me->hand == SCISSORS)
        {
            switch(you->hand){
                case PAPER:me->result = WIN;break;
                case ROCK:me->result = LOSE;break;
                default:break;
            }
        }
        if (me->hand == PAPER)
        {
            switch(you->hand){
                case ROCK:me->result = WIN;break;
                case SCISSORS:me->result = LOSE;break;
                default:break;
            }
        }
    }
    return;
}

//続けるか終了するか
int re(DATA *me){
    bool reflag = false;
    while (reflag == false)
    {
        printf("########continue??#########\n");
        printf("retry or finish??\n");
        printf("finish>>>:%d\n",FINISH);
        printf("retry>>>:%d\n",RETRY);
        scanf("%d",&me->retry);
        reflag =  (me->retry < FINISH || me->retry > RETRY) ? false:true;
    }
    
}

int main(void){
    DATA me,you;
    me.retry = RETRY;
    while (me.retry == RETRY)
    {
        set_hand(&me,&you);
        printf("########set#########\n");
        printf("me>>>%s\n",num_to_hand(me.hand));
        printf("you>>>%s\n",num_to_hand(you.hand));
        judge(&me,&you);
        printf("RESULT>>>%s\n",printout(&me));
        re(&me);
    }
    return 0;
}