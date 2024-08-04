#include <stdio.h>
#define STRING_LENGTH 256
#define CHAR_START_S 'a'
#define CHAR_START_L 'A'
#define CHAR_END_S 'z'
#define CHAR_END_L 'Z'
#define NUM_CHAR_START '0'
#define NUM_CHAR_END '9'

// // プロトタイプ宣言
// void practice(void);// 練習用関数
// void init(void);//文字列配列の初期化
// void get_moji(void);//一文字だけ標準入力で文字を格納する
// void get_string(void);//標準入力で文字列を格納する
// void count_string(void);//文字のカウント

//構造体宣言
typedef struct MOJI{
    int array[STRING_LENGTH];
    char ch;
	int moji_kind;
    int moji_num;
}STMOJI;

// 練習用関数
void practice(void){
	printf("START>>%d\n",NUM_CHAR_START);
	printf("END>>%d\n",NUM_CHAR_END);
}

//文字列配列の初期化
void init(STMOJI st){
	int i = 0;
	for(i = 0;i<STRING_LENGTH;i++){
		st.array[i] = 0;
	}
}
//一文字だけ標準入力で文字を格納する
void get_moji(void){
	char moji;
	moji = getchar();
	printf("get moji>>%c\n",moji);

}

//標準入力で文字列を格納する
void get_string(STMOJI st){
	while((st.ch = getchar()) != EOF){
		if ((CHAR_START_S <= st.ch) && (st.ch <= CHAR_END_S) ||
			(CHAR_START_L <= st.ch) && (st.ch <= CHAR_END_L) ||
			(NUM_CHAR_START <= st.ch) && (st.ch <= NUM_CHAR_END))
		{
			st.array[st.ch]++; 
		}
		else{
			continue;
		}
		
	}
}

void count_string(STMOJI st){
	int i = 0;
	for(i = 0;i < STRING_LENGTH;i++){
		if(st.array[i] != 0){
			printf("%c>>>%d\n",i,st.array[i]);
			st.moji_kind++;
			st.moji_num += st.array[i];
		}
	}
	printf("moji_kind>>>%d\n",st.moji_kind);
	printf("moji_num>>>%d\n",st.moji_num);
}
int main(void){
    STMOJI mojifre;

	init(mojifre);
	get_string(mojifre);
	// get_moji();
	//practice();
	count_string(mojifre);
	return 0;
}