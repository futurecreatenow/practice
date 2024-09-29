/*
状況：最低限のやりたいことは達成されている。
　　　単語一覧ファイルの単語が、
　　　入力ファイルにどれぐらい含まれているかを判定する
　　　⇒リスト構造をうまく作ることができず。。。中断
　　　⇒単語の頻度をアルファベット順と頻度順に並べ替えるプログラムを作成する。
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define data_wordlength 10
#define input_wordlength 10
#define INIT_FRE 0
#define N 256
enum wordjudge {JUDGEYES};
typedef enum {NO, YES} boolean;

//単語の一覧を格納する構造体
typedef struct KEYWORD{
    char keywords[data_wordlength];
    int frest;
    struct KEYWORD *nest;
}KEYWORD;

//入力された文字と頻度を格納する構造体
typedef struct FREG{
    char wordst[input_wordlength];
}FREG;

//単語表（全ての情報）
typedef struct FREGTABLE{
    FREG table[N];
    KEYWORD keytable[N];
    int wordnext;
    int keynext;
}FREGTABLE;

/*
概要：ファイルから読み込んだデータの行末の改行コードを削除する
戻り値：なし
*/
void removeNewline(char *str) {
    char *newline;
    if ((newline = strchr(str, '\n')) != NULL) {
        *newline = '\0';
    }
}

/*
概要：リスト構造を作ることができるか否かを判定する関数
戻り値：入力ファイルの単語が２つ以上単語一覧ファイルに存在したときにYESを返す。
*/
boolean Listinit(FREGTABLE *fre){
    int count= 0;
    for(int i = 0;i < fre->keynext;i++){
        if(fre->keytable[i].frest > INIT_FRE){
            count++;
        }
    }
    if(count >= 2)return YES;else return NO;
}



void Listcreate(FREGTABLE *fre){
    printf("\n");
    printf("#################\n");
    printf("can list structer\n");
}


int main(void){
    FREGTABLE fregtable;

    //単語一覧ファイルの読み込み
    FILE *fkey;
    char key_fname[] = "keyword.txt";
    char keystr[N];
    fkey = fopen(key_fname,"r");
    if(fkey == NULL) {
		printf("%s file not open!\n", key_fname);
		return -1;
	}
    fregtable.keynext = 0;
    while(fgets(keystr, N, fkey) != NULL) {
        removeNewline(keystr);
        strcpy(fregtable.keytable[fregtable.keynext].keywords,keystr);
        fregtable.keytable[fregtable.keynext].frest = INIT_FRE;
        fregtable.keynext++;
	}
	fclose(fkey);

    //単語一覧ファイルの出力
    int key_i;
    printf("\n");
    printf("### keyword ###\n");
    printf("(No.:keyword:frequency)\n");
    for(key_i = 0;key_i < fregtable.keynext;key_i++){
        printf("(%d:%s:%d)\n",key_i + 1,fregtable.keytable[key_i].keywords,fregtable.keytable[key_i].frest);
    }


    //入力ファイルの読み込み
    FILE *fp;
    char input_fname[] = "wordinput.txt";
    char str[N];
    fp = fopen(input_fname,"r");

    if(fp == NULL) {
		printf("%s file not open!\n", input_fname);
		return -1;
	}
    fregtable.wordnext = 0;
    while(fgets(str, N, fp) != NULL) {
        removeNewline(str);
        strcpy(fregtable.table[fregtable.wordnext].wordst,str);
        fregtable.wordnext++;
	}
	fclose(fp);

    //入力データの出力
    int input_i;
    printf("\n");
    printf("### input data ###\n");
    printf("(No.:inputword)\n");
    for(input_i = 0;input_i < fregtable.wordnext;input_i++){
        printf("(%d,%s)\n",input_i + 1,fregtable.table[input_i].wordst);
    }


    //文字列が同じか否かの判定
    printf("\n");
    printf("*** Now JUDGEING ***\n");
    printf("\n");
    int keyjudge_i;
    int inputjudge_i;
    for(inputjudge_i = 0;inputjudge_i < fregtable.wordnext;inputjudge_i++){
        for(keyjudge_i = 0;keyjudge_i<fregtable.keynext;keyjudge_i++){
            if (strcmp(fregtable.keytable[keyjudge_i].keywords,fregtable.table[inputjudge_i].wordst) == JUDGEYES)
            {
                fregtable.keytable[keyjudge_i].frest++;
            }
            else{
                continue;
            }
        }
    }


    //単語一覧ファイルの出力（単語の頻度が０回であるものも出力する）
    int key_ii;
    printf("\n");
    printf("### keyword ###\n");
    printf("(No.:keyword:frequency)\n");
    for(key_ii = 0;key_ii < fregtable.keynext;key_ii++){
        printf("(%d:%s:%d)\n",key_ii + 1,fregtable.keytable[key_ii].keywords,fregtable.keytable[key_ii].frest);
    }


    //以下はリスト構造するための処理であるが、できていない（やり方が思いつかない）
    if (Listinit(&fregtable) == YES){
        Listcreate(&fregtable);
    }
    else printf("can not list structer\n");
    return 0;
}