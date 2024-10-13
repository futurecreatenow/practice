#include "char_table.h"
#include <string.h>

/***********************************************************************
ENUM
***********************************************************************/
typedef enum {JUDGEYES} wordjudge;

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
関数名：CreateNewCT
概要：頻度が1以上の単語を新たな構造体に格納する
戻り値：なし
**********************************************************************/
void CreateNewCT(FREGTABLE *fregtable){
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
