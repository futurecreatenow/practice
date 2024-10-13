#include "in.h"
#include <string.h>
#define INIT_FRE 0

/**********************************************************************
関数名：removeNewline
概要：ファイルから読み込んだデータの行末の改行コードを削除する
戻り値：なし
**********************************************************************/
void removeNewline(char *str) {
    char *newline;
    if ((newline = strchr(str, '\n')) != NULL) {
        *newline = '\0';
    }
}
/**********************************************************************
関数名：GETKeydata
概要：単語一覧ファイルの読み込み
戻り値：なし
**********************************************************************/
void GETKeydata(FREGTABLE *fregtable){
    FILE *fkey;
    char key_fname[] = "keyword.txt";
    char keystr[N];
    fkey = fopen(key_fname,"r");
    if(fkey == NULL) {
        printf("%s file not open!\n", key_fname);
    }
    fregtable->keynext = 0;
    while(fgets(keystr, N, fkey) != NULL) {
        removeNewline(keystr);
        strcpy(fregtable->keytable[fregtable->keynext].keywords,keystr);
        fregtable->keytable[fregtable->keynext].frest = INIT_FRE;
        fregtable->keynext++;
    }
    fclose(fkey);
}
/**********************************************************************
関数名：GETInputdata
概要：入力ファイルの読み込み
戻り値：なし
**********************************************************************/
void GETInputdata(FREGTABLE *fregtable){
    FILE *fp;
    char input_fname[] = "wordinput.txt";
    char str[N];
    fp = fopen(input_fname,"r");

    if(fp == NULL) {
        printf("%s file not open!\n", input_fname);
    }
    fregtable->wordnext = 0;
    while(fgets(str, N, fp) != NULL) {
        removeNewline(str);
        strcpy(fregtable->table[fregtable->wordnext].wordst,str);
        fregtable->wordnext++;
    }
    fclose(fp);
}