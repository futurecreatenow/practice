#include <stdio.h>
#define STRING_LENGTH 256
#define CHAR_START_S 'a'
#define CHAR_START_L 'A'
#define CHAR_END_S 'z'
#define CHAR_END_L 'Z'
#define NUM_CHAR_START '0'
#define NUM_CHAR_END '9'

//グローバル変数宣言
int array[STRING_LENGTH];
char ch;
int moji_kind = 0;
int moji_num = 0;

// プロトタイプ宣言
void practice(void);// 練習用関数
void init(void);//文字列配列の初期化
void get_string(void);//標準入力で文字列を格納する
void count_string(void);//入力した文字の頻度計算

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

//入力した文字の頻度計算
void count_string(void){
	int i = 0;
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
	count_string();
	return 0;
}