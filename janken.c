#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef enum _hand {
    HAND_ROCK = 0,
    HAND_SCISSORS,
    HAND_PAPER,
    HAND_NUM
} HAND;

typedef enum _result {
    RESULT_DRAW,
    RESULT_YOU_WIN,
    RESULT_YOU_LOSE,
    RESULT_NUM
} RESULT;

static RESULT result_table[HAND_NUM][HAND_NUM];
static char *hand_strs[HAND_NUM];
static char *result_strs[RESULT_NUM];


void init(void) {
    // 乱数の初期化
    srand((unsigned int)time(NULL));

    // result_table[player_hand][com_hand]にプレイヤーの結果を格納
    result_table[HAND_ROCK][HAND_ROCK] = RESULT_DRAW;
    result_table[HAND_ROCK][HAND_SCISSORS] = RESULT_YOU_WIN;
    result_table[HAND_ROCK][HAND_PAPER] = RESULT_YOU_LOSE;
    result_table[HAND_SCISSORS][HAND_ROCK] = RESULT_YOU_LOSE;
    result_table[HAND_SCISSORS][HAND_SCISSORS] = RESULT_DRAW;
    result_table[HAND_SCISSORS][HAND_PAPER] = RESULT_YOU_WIN;
    result_table[HAND_PAPER][HAND_ROCK] = RESULT_YOU_WIN;
    result_table[HAND_PAPER][HAND_SCISSORS] = RESULT_YOU_LOSE;
    result_table[HAND_PAPER][HAND_PAPER] = RESULT_DRAW;

    hand_strs[HAND_ROCK] = "ROCK";
    hand_strs[HAND_SCISSORS] = "SCISSORS";
    hand_strs[HAND_PAPER] = "PAPER";

    result_strs[RESULT_DRAW] = "DRAW";
    result_strs[RESULT_YOU_WIN] = "WIN";
    result_strs[RESULT_YOU_LOSE] = "LOSE";
}

HAND getComHand(void) {
    return rand() % HAND_NUM;
}

HAND getPlayerHand(void) {

    HAND player_hand;

    while (1) {
        printf("HOW INPUT??0:ROCK,1:SCISSORS,2:PAPER");
        scanf("%d", &player_hand);

        if (player_hand >= HAND_NUM || player_hand < 0) {
            printf("AGEIN INPUT NUM\n\n");
        } else {
            break;
        }
    }
    printf("\n");

    return player_hand;
}

RESULT getResult(HAND player_hand, HAND com_hand) {
    return result_table[player_hand][com_hand];
}

void printHand(HAND hand) {
    printf("%s\n", hand_strs[hand]);
}

void printResult(RESULT result) {

    printf("RESULT>>>");
    printf("%s\n", result_strs[result]);
}


int main(void) {

    HAND player_hand;
    HAND com_hand;
    RESULT result;

    init();

    do {
        // コンピューターが出す手を決定する
        com_hand = getComHand();

        // プレイヤーが出す手の入力を受け付ける
        player_hand = getPlayerHand();
        
        // プレイヤーとコンピューターが出した手を表示する
        printf("YOUR HAND:");
        printHand(player_hand);

        printf("PC HAND:");
        printHand(com_hand);

        printf("\n");

        // じゃんけんの結果を判断する
        result = getResult(player_hand, com_hand);

        // じゃんけんの結果を表示する
        printResult(result);
        printf("\n");

    } while (result == RESULT_DRAW);

}

