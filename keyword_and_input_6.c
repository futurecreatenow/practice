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
/***********************************************************************
DEFINE
***********************************************************************/
#define data_wordlength 10
#define input_wordlength 10
#define INIT_FRE 0
#define N 256
#define PROMPT "Which key,c for character,frequency otherwise?"
/***********************************************************************
ENUM
***********************************************************************/
typedef enum {JUDGEYES} wordjudge;
typedef enum {NO, YES} boolean;
typedef enum {BY_CHAR,BY_FREG} sort_key;
/***********************************************************************
STRUCTER
***********************************************************************/
//入力された文字と頻度を格納する構造体
typedef struct KEYWORD{
    char keywords[data_wordlength];
    int frest;
    struct KEYWORD *nest;
}KEYWORD;

//単語の一覧を格納する構造体
typedef struct FREG{
    char wordst[input_wordlength];
}FREG;

//単語表（全ての情報）
typedef struct FREGTABLE{
    FREG table[N];
    KEYWORD keytable[N];
    KEYWORD newtable[N];
    int wordnext;
    int keynext;
    int newnext;
}FREGTABLE;

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
/**********************************************************************
関数名：OUTKey
概要：単語一覧ファイルの出力
戻り値：なし
**********************************************************************/
void OUTKey(FREGTABLE *fregtable){
    int m;
    printf("\n");
    printf("### keyword data ###\n");
    for(m = 0;m < fregtable->keynext;m++){
        printf("(%s)\n",fregtable->keytable[m].keywords);
    }
}

/**********************************************************************
関数名：OUTInput
概要：入力データの出力
戻り値：なし
**********************************************************************/
void OUTInput(FREGTABLE *fregtable){
    int k;
    printf("\n");
    printf("### input data ###\n");
    for(k = 0;k < fregtable->wordnext;k++){
        printf("(%s)\n",fregtable->table[k].wordst);
    }
}

/**********************************************************************
関数名：CTPut
概要：文字列が同じか否かの判定
戻り値：なし
**********************************************************************/
void CTPut(FREGTABLE *fregtable){
    printf("\n");
    printf("********************\n");
    printf("*** Now JUDGEING ***\n");
    printf("********************\n");
    int key_i;
    int input_i;
    for(input_i = 0;input_i < fregtable->wordnext;input_i++){
        for(key_i = 0;key_i<fregtable->keynext;key_i++){
            if (strcmp(fregtable->keytable[key_i].keywords,fregtable->table[input_i].wordst) == JUDGEYES)
            {
                fregtable->keytable[key_i].frest++;
            }
            else{
                continue;
            }
        }
    }
}
/**********************************************************************
関数名：OUTKeyFreg
概要：単語の頻度出力（単語の頻度が０回であるものも出力する）
戻り値：なし
**********************************************************************/
void OUTKeyFreg(FREGTABLE *fregtable){
    int i;
    printf("\n");
    printf("### keyword ###\n");
    printf("(keyword:frequency)\n");
    for(i = 0;i < fregtable->keynext;i++){
        printf("(%s:%d)\n",fregtable->keytable[i].keywords,fregtable->keytable[i].frest);
    }
}

/**********************************************************************
関数名：CREATENEWCT
概要：頻度が1以上の単語を新たな構造体に格納する
戻り値：なし
**********************************************************************/
void CREATENEWCT(FREGTABLE *fregtable){
    int i;
    fregtable->newnext = 0;
    printf("\n");
    printf("### keyword exist ... so create new structer ###\n");
    for (i = 0; i < fregtable->keynext; i++)
    {
        if (fregtable->keytable[i].frest >= 1)
        {
            printf("(%s:%d)\n",fregtable->keytable[i].keywords,fregtable->keytable[i].frest);
            strcpy(fregtable->newtable[fregtable->newnext].keywords,fregtable->keytable[i].keywords);
            fregtable->newtable[fregtable->newnext].frest = fregtable->keytable[i].frest;
            fregtable->newnext++;
        }
        
    }
    printf("\n");
}

/**********************************************************************
関数名：SORTChar
概要：アルファベット順に並び替え
戻り値：なし
**********************************************************************/
void SORTChar(FREGTABLE *fregtable){
    int i,j;
    for (int i = 0; i < fregtable->newnext - 1; i++)
    {
        for(j = i + 1;j < fregtable->newnext;j++){
            if (strcmp(fregtable->newtable[i].keywords,fregtable->newtable[j].keywords)> 0)
            {
                KEYWORD swap;
                swap = fregtable->newtable[i];
                fregtable->newtable[i] = fregtable->newtable[j];
                fregtable->newtable[j] = swap;
            }
            
        }
    }
}

/**********************************************************************
関数名：SORTFreg
概要：頻度順に並び替え
戻り値：なし
**********************************************************************/
void SORTFreg(FREGTABLE *fregtable){
    int ii;
    int iii;
    printf("\n");
    for (ii = 0; ii < fregtable->newnext - 1; ii++)
    {
        for(iii = ii + 1;iii < fregtable->newnext;iii++){
            if (fregtable->newtable[ii].frest > fregtable->newtable[iii].frest)
            {
                KEYWORD swap;
                swap = fregtable->newtable[ii];
                fregtable->newtable[ii] = fregtable->newtable[iii];
                fregtable->newtable[iii] = swap;
            }
        }
    }
}

/**********************************************************************
関数名：OUTPrint
概要：頻度順もしくはアルファベット順に並び替え後の構造体の出力
戻り値：なし
**********************************************************************/
void OUTPrint(FREGTABLE *fregtable){
    int i = 0;
    printf("\n");
    printf("### swap new structer ###\n");
    for (i = 0; i < fregtable->newnext; i++)
    {
        printf("(%s:%d)\n",fregtable->newtable[i].keywords,fregtable->newtable[i].frest);
    }
    printf("\n");
}


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