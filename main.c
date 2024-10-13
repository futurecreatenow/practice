/***********************************************************************
状況：単語の頻度をアルファベット順と頻度順に並べ替える

課題：それぞれの関数を別のcファイルに移植する
　　　⇒ヘッダーファイルにも記載していくこと
***********************************************************************/
/***********************************************************************
INCLUDE
***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "char_table.h"
#include "in.h"
#include "out.h"

/***********************************************************************
ENUM
***********************************************************************/
typedef enum {BY_CHAR,BY_FREG} sort_key;



int main(void){
    //頻度表全体の構造体の宣言
    FREGTABLE fregtable;

    //頻度かアルファベット順かの選択
    sort_key skey;
    printf("%s",PROMPT);
    if(getchar() == 'c') skey = BY_CHAR;else skey = BY_FREG;

    //単語一覧ファイルの読み込み
    GETKeydata(&fregtable);

    //単語一覧ファイルの出力
    OUTKey(&fregtable);

    //入力ファイルの読み込み
    GETInputdata(&fregtable);

    //入力データの出力
    OUTInput(&fregtable);

    //文字列が同じか否かの判定
    CTPut(&fregtable);

    //単語の頻度出力（単語の頻度が０回であるものも出力する）
    OUTKeyFreg(&fregtable);

    //頻度が1以上の単語を新たな構造体に格納する
    CREATENEWCT(&fregtable);

    //頻度かアルファベット順に並び替え
    if (skey == BY_CHAR) SORTChar(&fregtable);
    else SORTFreg(&fregtable);

    //頻度順もしくはアルファベット順に並び替え後の構造体の出力
    OUTPrint(&fregtable);

}