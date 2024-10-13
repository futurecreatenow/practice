#include "out.h"

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