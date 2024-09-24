#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define data_wordlength 10
#define input_wordlength 10
#define INIT_FRE 0
#define N 256
enum wordjudge {YES};

//単語の一覧を格納する構造体
typedef struct KEYWORD{
    char keywords[data_wordlength];
}KEYWORD;

//入力された文字と頻度を格納する構造体
typedef struct FREG{
    char wordst[input_wordlength];
    int frest;
}FREG;

//単語表（全ての情報）
typedef struct FREGTABLE{
    FREG table[N];
    KEYWORD keytable[N];
    int wordnext;
    int keynext;
}FREGTABLE;

//ファイルから読み込んだデータの行末の改行コードを削除する
void removeNewline(char *str) {
    char *newline;
    if ((newline = strchr(str, '\n')) != NULL) {
        *newline = '\0';
    }
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
        fregtable.keynext++;
	}
	fclose(fkey);

    //出力データの出力
    int key_i;
    printf("\n");
    printf("### keyword ###\n");
    printf("(No.:keyword)\n");
    for(key_i = 0;key_i < fregtable.keynext;key_i++){
        printf("(%d:%s)\n",key_i + 1,fregtable.keytable[key_i].keywords);
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
        fregtable.table[fregtable.wordnext].frest = INIT_FRE;
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
    printf("JUDGE\n");
    int keyjudge_i;
    int inputjudge_i;
    for (keyjudge_i = 0; keyjudge_i < fregtable.keynext; keyjudge_i++)
    {
        for(inputjudge_i = 0;inputjudge_i < fregtable.wordnext;inputjudge_i++){
            if (strcmp(fregtable.keytable[keyjudge_i].keywords,fregtable.table[inputjudge_i].wordst) == YES)
            {
                fregtable.table[inputjudge_i].frest++;
            }
            else{
                continue;
            }
        }       
    }

    //頻度出力
    int judge_i;
    printf("\n");
    printf("### input data ###\n");
    printf("(input word:frequency)\n");
    for(judge_i = 0;judge_i < fregtable.wordnext;judge_i++){
        printf("(%s,%d)\n",fregtable.table[judge_i].wordst,fregtable.table[judge_i].frest);
    }

    return 0;
}