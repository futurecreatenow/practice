勉強会


1）単語のログ表示の前に以下のエラーログが出てくる
Invalid character '5', ignored.
Invalid character '0', ignored.
Invalid character '4', ignored.
Invalid character '0', ignored.
表示：変数cの値である

1_1)変数cはどのように定義されているのか
→input_device/string_input_device.cのSIDGet_Token関数
   c = INDGet_Char(asid->accInputDev);

1_2_1)INDGet_Char(asid->accInputDev);とは
定義場所：input_device/input_device.c
定義：char INDGet_Char(acc_input_device aid) { return getc(aid->inputFile); }
呼び出し元：/app/main.cのwhile ((w = SIDGet_Token(inDev)) != NULLS
引数：asid->accInputDev
typedef struct string_input_device_ {
   acc_input_device accInputDev;
   acc_stm *stms;
   int noSTMs;
} string_input_device, *acc_string_input_device;

1_2_1_1)while ((w = SIDGet_Token(inDev)) != NULLSのinDevの呼び出し元は
呼び出し元：/app/main.cのacc_string_input_device inDev;

1_2_1_1)/app/main.cのacc_string_input_deviceの定義場所は
定義場所：input_device/string_input_device_ds.h





2)プログラムミス
input_device/string_input_device.c
SIDGet_Token関数
誤)wordSt = (asid, c, &skip4w, &wordScanning,wordTok, wordSt, word_STM_No);
正)wordSt = get_Token(asid, c, &skip4w, &wordScanning,wordTok, wordSt, word_STM_No);

