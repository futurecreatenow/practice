#include <stdio.h>
#define STRING_LENGTH 256
#define CHAR_START_S 'a'
#define CHAR_START_L 'A'
#define CHAR_END_S 'z'
#define CHAR_END_L 'Z'
#define NUM_CHAR_START '0'
#define NUM_CHAR_END '9'

// プロトタイプ宣言
void practice(void);// 練習用関数
void init(void);//文字列配列の初期化
void get_moji(void);//一文字だけ標準入力で文字を格納する
void get_string(void);//標準入力で文字列を格納する
void count_string(void);//文字のカウント

//グローバル変数宣言
int array[STRING_LENGTH];
char ch;

// 練習用関数
void practice(void){
	printf("START>>%d\n",NUM_CHAR_START);
	printf("END>>%d\n",NUM_CHAR_END);
}

//文字列配列の初期化
void init(void){
	int i = 0;
	for(i = 0;i<STRING_LENGTH;i++){
		array[i] = 0;
	}
}
//一文字だけ標準入力で文字を格納する
void get_moji(void){
	char moji;
	moji = getchar();
	printf("get moji>>%c\n",moji);

}

//標準入力で文字列を格納する
void get_string(void){
	while((ch = getchar()) != EOF){
		if ((CHAR_START_S <= ch) && (ch <= CHAR_END_S) ||
			(CHAR_START_L <= ch) && (ch <= CHAR_END_L) ||
			(NUM_CHAR_START <= ch) && (ch <= NUM_CHAR_END))
		{
			array[ch]++; 
		}
		else{
			continue;
		}
		
	}
}

void count_string(void){
	int i = 0;
	int moji_kind ,moji_num = 0;
	for(i = 0;i < STRING_LENGTH;i++){
		if(array[i] != 0){
			printf("%c>>>%d\n",i,array[i]);
			moji_kind++;
			moji_num += array[i];
		}
	}
	printf("moji_kind>>>%d\n",moji_kind);
	printf("moji_num>>>%d\n",moji_num);
}
int main(void){
	init();
	get_string();
	// get_moji();
	//practice();
	count_string();
	return 0;
}
