# コンパイラの指定
CC=gcc

# コンパイル時のオプション
CFLAGS=-I. -Wall

# 最終的な実行ファイル名
TARGET=test.exe

# 最終ターゲット
$(TARGET): main.o in.o out.o char_table.o
	$(CC) -o $(TARGET) main.o in.o out.o char_table.o

# main.cからmain.oを生成
main.o: main.c
	$(CC) -c main.c $(CFLAGS)

in.o: in.c
	$(CC) -c in.c $(CFLAGS)

out.o: out.c
	$(CC) -c out.c $(CFLAGS)

char_table.o: char_table.c
	$(CC) -c char_table.c $(CFLAGS)

# 'make clean' を実行した時に実行ファイルとオブジェクトファイルを削除
clean:
	del *.o
cleanall:
	del *.o $(TARGET)
