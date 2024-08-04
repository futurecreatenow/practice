#include <stdio.h>
#define STRING_LENGTH 256
#define CHAR_START_S 'a'
#define CHAR_START_L 'A'
#define CHAR_END_S 'z'
#define CHAR_END_L 'Z'
#define NUM_CHAR_START '0'
#define NUM_CHAR_END '9'

//全角数字と文字に対応していない。例えば全角の１２３がそれぞれPQRと認識されてしまう


//構造体宣言
typedef struct MOJI{
    int array[STRING_LENGTH];
    char ch;
	int moji_kind;
    int moji_num;
}STMOJI;

// プロトタイプ宣言
void practice(void);// 練習用関数
void set_moji(STMOJI *st);//頻度表配列情報の初期化
void get_string(STMOJI *st);//標準入力で文字列を格納する
void count_string(STMOJI *st);//入力した文字の頻度計算


// 練習用関数
void practice(void){
	printf("START>>%d\n",NUM_CHAR_START);
	printf("END>>%d\n",NUM_CHAR_END);
}

//頻度表配列情報の初期化
void set_moji(STMOJI *st){
    st->moji_num = 0;
    st->moji_kind = 0;
	int i = 0;
	for(i = 0;i<STRING_LENGTH;i++){
		st->array[i] = 0;
	}
}

//標準入力で文字列を格納する
void get_string(STMOJI *st){
	while((st->ch = getchar()) != EOF){
        if ((CHAR_START_S <= st->ch) && (st->ch <= CHAR_END_S) ||
			(CHAR_START_L <= st->ch) && (st->ch <= CHAR_END_L) ||
			(NUM_CHAR_START <= st->ch) && (st->ch <= NUM_CHAR_END))
		{
			st->array[st->ch]++; 
		}
		else{
			continue;
		}
		
	}
}

//入力した文字の頻度計算
void count_string(STMOJI *st){
	int i = 0;
	for(i = 0;i < STRING_LENGTH;i++){
		if(st->array[i] != 0){
			printf("%c>>>%d\n",i,st->array[i]);
			st->moji_kind++;
			st->moji_num += st->array[i];
		}
	}
	printf("moji_kind>>>%d\n",st->moji_kind);
	printf("moji_num>>>%d\n",st->moji_num);
}

int main(void){
    STMOJI mojifre;
    // practice();
	set_moji(&mojifre);
	get_string(&mojifre);
	count_string(&mojifre);
	return 0;
}